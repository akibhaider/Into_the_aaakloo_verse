#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

namespace std {
template <class T>constexpr T byteswap(T value) noexcept;
template<class T>constexpr T bit_ceil(T x);
template<class T>constexpr T bit_floor(T x) noexcept;
template<class T>constexpr int bit_width(T x) noexcept;
template<class T>constexpr T rotl(T x, int s) noexcept;
template<class T>constexpr T rotr(T x, int s) noexcept;
}

using namespace std;
using namespace __gnu_pbds; 
#define ll long long
#define F first
#define S second
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed

template <class T>
using ordered_set =  __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T, typename U>
T& amax(T& x, U y) {if(y > x) x = y; return x;}
template<typename T, typename U>
T& amin(T& x, U y) {if(y < x) x = y; return x;}

const ll inf = 1e9;
const long double ep = 0.0000001;
const long double pi = acos(-1.0);
const ll MOD = 1000000007;
const int mod = 998244353;
const int TWO_MOD_INV = 500000004;

long long get(int x) {
    return x * 1ll * (x + 1) / 2;
}

pair<ll, ll> findOverlap(ll x1, ll y1, ll x2, ll y2) {
    ll l = max(x1, x2), r = min(y1, y2);
 
    if(l <= r) return {l,r};
    else return {-inf, -inf};
}


int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    cout<<findOverlap(2, 4, 3, 9).first << " " << findOverlap(2, 4, 3, 9).second <<" ";    
    return 0;
}

