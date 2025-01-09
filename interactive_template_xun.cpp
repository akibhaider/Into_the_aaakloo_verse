#include <bits/stdc++.h>
#ifdef LOCAL
 #include "Dbug.h"
#else
 #define dbg(...)
#endif
 
using namespace std;
 
// #warning CHANGE INT-LONG-LONG IN CASE OF ORDERED SET
// #warning CHANGE MAX VALUE
// #warning change endl and FastIO for interactive
typedef long long LL;
typedef long double LD;
#define pi acos(-1)
#define all(x) begin(x), end(x)
// #define endl "\n"
#define TESTS int test; cin>>test; for(int kase = 1 ; kase <= test ; kase++) solve(kase);
#define CASEOUT cout << "Case " << testcase << ": ";
#define int long long
#define pii pair<int,int>
const LL MAX = 100;
const LL MOD = (1e9) + 7;
const LL INF = (1e15) + 5;
 
int n, k;
namespace judge{
    int query(int a, int b)
    {
        int ret;
        cout << "? " << a << " " << b << endl;
        cin >> ret;
        return ret;
    }
 
    void answer(int a)
    {
        int ret;
        cout << "! " << a << endl;
        cin >> ret;
        assert(ret == 1);
        return;
    }
 
    void takeInput()
    {
        cin >> n >> k;
    }
}
 
 
namespace offline{
    vector <int> v;
    int query(int a, int b)
    {
        cout << "? " << a << " " << b << endl;
        int maxV = v[a];
        for(int i = a-1, j = 1 ; i < n ; i++, j++)
        {
            maxV = max(maxV, v[i]);
            if(j * maxV == b) return i+1;
        }
        return n+1;
    }
 
    void answer(int a)
    {
        int ret;
        cout << "! " << a << endl;
        ret = 1;
        assert(ret == 1);
    }
 
    void takeInput()
    {
        cerr << "Taking input..." << endl;
        n = 6;
        k = 3;
        v = {1, 3, 6, 1, 2, 1};
    }
}
 
#ifdef LOCAL
    using namespace offline;
#else
    using namespace judge;
#endif
 
 
 
 
bool check(int val)
{
    int curr = 1;
    for(int i = 0 ; i < k ; i++)
    {
        curr = query(curr, val)+1;
        if(i != k-1 && curr > n) return false;
    }
    return curr == n+1;
}
 
int solve(int testcase)
{
    takeInput();
    int maximum = 1;
    for(int i = n ; i >= 1 ; i--)
    {
        if(query(1, n*i) == n)
        {
            maximum = i;
            break;
        }
    }
    int ans = -1;
    for(int i = n/k ; i >= 1 ; i--)
    {
        if(check(maximum * i)) 
        {
            ans = maximum * i;
            break;
        }
    }
    answer(ans);
    return testcase;
}
 
signed main()
{
    #ifdef LOCAL
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    #endif
 
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int testerrr = 10;
    // cin >> test;
    for(int i = 1 ; i <= testerrr ; i++)
        solve(i);
    // TESTS
    return 0;
}