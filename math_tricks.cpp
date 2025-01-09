#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define e exp(1)


/// Log related operations:

double log_a_to_base_b(long long a, long long b)
{
    return log2((double)a) / log2((double)b);
}

long long Pow(long long a, long long b) {
    // a %= md;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            // res = res * a % md;
            res = res * a;
        // a = a * a % md;
        a = a * a;
        b >>= 1;
    }
    return res;
}

/// Stirling's Factorial Approximation:
long long fact(long long n){
    return ( sqrt((2*pi*n))*(double)pow(n, n) )/(double)(pow(e, n));
}