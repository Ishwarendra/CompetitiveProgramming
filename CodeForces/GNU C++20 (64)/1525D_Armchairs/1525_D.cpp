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

    std::vector<int> a(n), one, zero;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        (a[i] ? one : zero).emplace_back(i);

    constexpr int inf = 1e9;

    int m = std::size(zero);
    n = std::size(one);
    std::vector dp(n + 1, std::vector<int>(m + 1, inf));

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int from = one[i - 1];
            int to = zero[j - 1];
            dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j - 1] + std::abs(from - to));
        }
    }
            
    std::cout << dp.back().back();

    return 0;
}