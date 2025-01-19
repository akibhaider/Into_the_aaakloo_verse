#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename DT> 
using ordered_set = tree <DT, null_type, less<DT>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;


#define tcout(i) cout << "Case " << i << ": "
const ll MOD = 1e9+7;
const ll INF = 1e18;
const int MAX = 1e5+5;




void solve(int tc)
{   
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll> (m));
    for(auto &i: g)
    {
        for(auto &j: i) cin >> j;
    }

    vector<vector<ll>> dp(n, vector<ll>(m));
    dp[0][0] = g[0][0];

    for(int i = 1; i < m; i++) dp[0][i] = max(dp[0][i-1] + g[0][i]-1, g[0][i]);
    for(int i = 1; i < n; i++) dp[i][0] = max(dp[i-1][0] + g[i][0]-1, g[i][0]);

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            dp[i][j] = max(g[i][j]-1+max(dp[i-1][j], dp[i][j-1]), g[i][j]);
        }
    }

    ll ans = 0;
    for(auto &i: dp)
    {
        for(auto &j: i)
        {
            ans = max(ans, j);
            // cout << j << ' ';
        }
        // cout << endl;
    }   
    cout << ans;

    



    cout << '\n';
}


signed main()
{
    cin.tie(0)->sync_with_stdio(0);





    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) solve(i);

    return 0;
}