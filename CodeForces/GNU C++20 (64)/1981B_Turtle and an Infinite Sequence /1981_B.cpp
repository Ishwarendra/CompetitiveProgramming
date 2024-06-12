#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * a0, a1, a2, a3, a4, a5, ...
 * m = 1 (first 1 terms increase on right, rest both sides)
 * a[0..1], a[0..2], a[1..3], a[2..4], a[3..5], a[4..6]
 * 
 * m = 2 (first 2 terms increase on right, rest both sides)
 * a[0..2], a[0..3], a[0..4], a[1..5], a[2..6], a[3..7]
 * 
 * a[0..3], a[0..4], a[0..5], a[0..6], a[1..7], a[2..8]
 * 
 * For generic m,
 * First m terms will be
 * a[0..m], a[0..m+1], a[0..2*m], a[0..2*m+1], a[1..2*m+2], a[2..2*m+2]
 * 
 * if x <= m: a[0 .. m+x]
 * else: a[x-m .. m+x]
 * 
 * How to find bitwise or of all numbers between L to R.
 * Observations:
 *     1. No bit that is set once will ever unset.
 *     2. Iterate bit by bit and check if any number in this range can have bit set.
 */

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    
    auto get = [&](i64 L, i64 R)
    {
        i64 res = 0;
        for (int pos = 0; pos < 32; pos++)
        {
            if (getBit(L, pos))
                res |= (1LL << pos);
            else
            {
                i64 mod = (1LL << (pos + 1)) - 1;
                i64 rank = L & mod;
                i64 need = (1LL << pos);
                
                if (need - rank < R - L + 1)
                    res |= (1LL << pos);
            }
        }  
        
        return res;
    };
    
    std::cout << get(std::max(0, n - m), m + n) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}