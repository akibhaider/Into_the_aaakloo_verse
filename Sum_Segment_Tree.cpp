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

void aaakloo(){
    ios_base::sync_with_stdio(false);                       
    cin.tie(NULL);
}

vll sum_seg_tree(2e6);
vll a(5e5+2);

void build_sum_seg_Tree(ll i, ll l, ll r){
    ll m=(l+r)/2;
    if(l==r){
        sum_seg_tree[i]=a[l];
    }else{
        build_sum_seg_Tree(2*i+1, l, m);
        build_sum_seg_Tree(2*i+2, m+1, r);
        sum_seg_tree[i]=sum_seg_tree[2*i+1]+sum_seg_tree[2*i+2];
    }
}

void update_sum_seg_tree(ll i, ll l, ll r, ll pos, ll x){
    ll m=(l+r)/2;
    if(l==r){
        sum_seg_tree[i]=x;
    }else{
        if(pos<=m){
            update_sum_seg_tree(2*i+1, l, m, pos, x);
        }else{
            update_sum_seg_tree(2*i+2, m+1, r, pos, x);
        }
        sum_seg_tree[i]=sum_seg_tree[2*i+1]+sum_seg_tree[2*i+2];
    }
}

ll sum_query(ll i, ll tl, ll tr, ll ql, ll qr){
    if(ql>qr){
        return 0;
    }
    if(ql==tl && qr==tr){
        return sum_seg_tree[i];
    }
    ll m=(tl+tr)/2;
    return sum_query(2*i+1, tl, m, ql, min(m, qr)) + sum_query(2*i+2, m+1, tr, max(ql, m+1), qr);
}

void solve(){
    ll n, q, cmd, x, y;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build_sum_seg_Tree(0, 0, n-1);
    while(q--){
        cin>>cmd>>x>>y;
        if(cmd){
            cout<<sum_query(0, 0, n-1, x, --y)<<nl;
        }else{
            update_sum_seg_tree(0, 0, n-1, x, y);
        }
    }
}

signed main(){
    aaakloo();
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
        if(tc)
            cout<<nl;
    }
    return 0;
}
/*
problem: https://judge.yosupo.jp/problem/point_add_range_sum
*/