#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Since 2 * l <= r so there is atleast one power of two between l and r
 * It will have maximum prime factors
 */

void solve()
{
    int l, r;
    std::cin >> l >> r;
    
    std::cout << std::__lg(r) << "\n";
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