#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    constexpr int M = 22;
    std::vector dp(1 << M, -1);

    for (int i = 0; i < n; i++)
        dp[a[i]] = a[i];

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    auto inv = [&](int x) { return ((1 << M) - 1) ^ x; };

    for (int mask = 1; mask < (1 << M); mask++)
    {
        for (int i = 0; i < M; i++)
        {
            if (getBit(mask, i))
                dp[mask] = std::max(dp[mask], dp[mask ^ (1 << i)]);
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << dp[inv(a[i])] << " \n"[i == n - 1];
    
    return 0;
}