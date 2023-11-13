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

const int N = 2e5+2;
const int INF=numeric_limits<int>::max();
void aaakloo(){
    ios_base::sync_with_stdio(0);                       
    cin.tie(0);
}

vi min_seg_tree(N*4);
vi a(N);

void build_min_seg_Tree(int i, int l, int r){
    int m=(l+r)/2;
    if(l==r){
        min_seg_tree[i]=a[l];
    }else{
        build_min_seg_Tree(2*i, l, m);
        build_min_seg_Tree(2*i+1, m+1, r);
        min_seg_tree[i]=min(min_seg_tree[2*i],min_seg_tree[2*i+1]);
    }
}

void update_min_seg_tree(int i, int l, int r, int pos, int x){
    int m=(l+r)/2;
    if(l==r){
        min_seg_tree[i]=x;
    }else{
        if(pos<=m){
            update_min_seg_tree(2*i, l, m, pos, x);
        }else{
            update_min_seg_tree(2*i+1, m+1, r, pos, x);
        }
        min_seg_tree[i]=min(min_seg_tree[2*i], min_seg_tree[2*i+1]);
    }
}

int min_query(int i, int tl, int tr, int ql, int qr){
    if(ql>qr){
        return INF;
    }
    if(ql==tl && qr==tr){
        return min_seg_tree[i];
    }
    int m=(tl+tr)/2;
    return min(min_query(2*i, tl, m, ql, min(m, qr)), min_query(2*i+1, m+1, tr, max(ql, m+1), qr));
}

void solve(){
    int n, q, cmd, x, y;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    a.resize(n+2);
    min_seg_tree.resize(4*n+8);

    build_min_seg_Tree(1, 1, n);
    while(q--){
        cin>>cmd>>x>>y;
        if(cmd==2){
            cout<<min_query(1, 1, n, x, y)<<nl;
        }else{
            update_min_seg_tree(1, 1, n, x, y);
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
