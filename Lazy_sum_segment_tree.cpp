#include<bits/stdc++.h>
 
using namespace std;

#define ll long long
#define rep(i, a, b) for(long long i=a; i<b; i++)
#define spc " "    
#define vi vector<int>
#define vll vector<long long>
#define vip vector<pair<int, int>>
#define vb vector<bool> 
#define Mthis 1e9
#define pb push_back 
#define nl '\n'
#define E 1e-4
#define mp make_pair 

const int maxN=100000;

void aaakloo(){
    ios_base::sync_with_stdio(false);                       
    cin.tie(NULL);
}

vll sum_seg_tree(4*maxN, 0);
vll prop(4*maxN, 0);
vi a(maxN+2, 0);

void build_sum_seg_Tree(ll i, ll tl, ll tr){
    ll tm=(tl+tr)/2;
    if(tl==tr){
        sum_seg_tree[i]=a[tl];
    }else{
        build_sum_seg_Tree(2*i, tl, tm);
        build_sum_seg_Tree(2*i+1, tm+1, tr);
        sum_seg_tree[i]=sum_seg_tree[2*i]+sum_seg_tree[2*i+1];
    }
}

void update_sum_seg_tree(ll i, ll tl, ll tr, ll pos, ll x){
    ll tm=(tl+tr)/2;
    if(tl==tr){
        sum_seg_tree[i]+=x;
    }else{
        if(pos<=tm){
            update_sum_seg_tree(2*i, tl, tm, pos, x);
        }else{
            update_sum_seg_tree(2*i+1, tm+1, tr, pos, x);
        }
        sum_seg_tree[i]=sum_seg_tree[2*i]+sum_seg_tree[2*i+1];
    }
}

void update_lazy_sum_seg_tree(ll i, ll tl , ll tr, ll ul, ll ur, ll x){
    if(ul>tr || ur<tl) // Update range is out of tree bound
        return ;
    if(ul<=tl && ur>=tr) // node's range is in between update range
    {
        sum_seg_tree[i]+=((tr-tl+1)*x);
        prop[i]+=x;
        return ;
    }
    ll tm=(tl+tr)/2;
    update_lazy_sum_seg_tree(2*i, tl, tm, ul, ur, x);
    update_lazy_sum_seg_tree(2*i+1, tm+1, tr, ul, ur, x);
    sum_seg_tree[i]=sum_seg_tree[2*i] + sum_seg_tree[2*i+1] + (tr-tl+1)*prop[i];
}

ll sum_query(ll i, ll tl, ll tr, ll ql, ll qr){
    if(ql>tr || qr<tl)
        return 0;
    if(ql<=tl && qr>=tr)
        return sum_seg_tree[i];

    ll tm=(tl+tr)/2;
    return sum_query(2*i, tl, tm, ql, qr) + sum_query(2*i+1, tm+1, tr, ql, qr);
}

ll lazy_sum_query(ll i, ll tl , ll tr, ll ql , ll qr, ll carry=0){
    if(ql>tr || qr<tl)
        return 0;
    if(ql<=tl && qr>=tr)
        return sum_seg_tree[i] + carry*(tr-tl+1);

    ll tm=(tl+tr)>>1;
    return (lazy_sum_query(2*i, tl, tm, ql, qr, carry+prop[i]) + lazy_sum_query(2*i+1, tm+1, tr, ql, qr, carry+prop[i]));
}

void solve(){
    ll n, q, cmd, x, y, v;
    cin>>n>>q;
    build_sum_seg_Tree(1, 1, n);
    while(q--){
        cin>>cmd>>x>>y;
        if(cmd){
            cout<<lazy_sum_query(1, 1, n, x+1, y+1)<<nl;
        }else{
            cin>>v;
            update_lazy_sum_seg_tree(1, 1, n, x+1, y+1, v);
        }
    }
}

signed main(){
    aaakloo();
    int tc=1;
    cin>>tc;
    rep(i, 1, tc+1){
        cout<<"Case "<<i<<":"<<nl;
        solve();
        memset(&sum_seg_tree[0], 0, sum_seg_tree.size()* sizeof sum_seg_tree[0]);
        memset(&prop[0], 0, prop.size()* sizeof prop[0]);
        memset(&a[0], 0, a.size()* sizeof a[0]);

    }
    return 0;
}
/*
problem: https://lightoj.com/problem/horrible-queries
*/