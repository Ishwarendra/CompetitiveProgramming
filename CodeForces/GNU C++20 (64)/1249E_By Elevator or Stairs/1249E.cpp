#include <bits/stdc++.h>

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
    
    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; i++)
        std::cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        std::cin >> b[i];

    std::vector<std::array<i64, 2>> dp(n, {0, c});
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
        dp[i][1] = std::min(dp[i - 1][0] + c, dp[i - 1][1]) + b[i - 1];
    }

    for (int i = 0; i < n; ++i)
        std::cout << std::min(dp[i][0], dp[i][1]) << " \n"[i == n - 1];
    
    return 0;
}