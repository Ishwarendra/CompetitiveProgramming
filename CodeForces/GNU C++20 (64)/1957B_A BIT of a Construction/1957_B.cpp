#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Total sum <= k
 * Max set bits = msb(k)
 */

void solve()
{
    int n, k;
    std::cin >> n >> k;
    
    if (n == 1)
        std::cout << k << "\n";
    else
    {
        int msb = std::__lg(k);
        int f = (1 << msb) - 1;
        int s = k - f;
        std::cout << f << " " << s << " ";
        for (int i = 0; i < n - 2; i++)
            std::cout << "0 ";
        std::cout << "\n";
    }
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