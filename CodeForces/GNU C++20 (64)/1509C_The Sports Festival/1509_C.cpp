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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    constexpr i64 inf = 1e18;
    std::vector dp(n, std::vector(n, inf));

    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + a[j] - a[i];
        }
    }

    std::cout << dp[0][n - 1];
    
    return 0;
}