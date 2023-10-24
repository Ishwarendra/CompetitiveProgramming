#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void chmin(i64 &a, i64 b)
{
    if (a > b)
        a = b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x, y, z;
    std::cin >> x >> y >> z;

    std::string s;
    std::cin >> s;

    int n = std::size(s);

    std::vector dp(n + 1, std::array {inf, inf});
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        char ch = s[i - 1];
        if (ch == 'a')
        {
            // caps on, shift + A
            chmin(dp[i][1], dp[i - 1][1] + y);
            chmin(dp[i][1], dp[i - 1][0] + z + std::min(x, y));

            // caps off, a
            chmin(dp[i][0], dp[i - 1][0] + x);
            chmin(dp[i][0], dp[i - 1][1] + z + std::min(x, y));
        }
        else
        {
            // caps on, A
            chmin(dp[i][1], dp[i - 1][1] + x);
            chmin(dp[i][1], dp[i - 1][0] + z + std::min(x, y));

            // caps off, shift + a
            chmin(dp[i][0], dp[i - 1][0] + y);
            chmin(dp[i][0], dp[i - 1][1] + std::min(x, y) + z);
        }
    }

    std::cout << std::min(dp[n][0], dp[n][1]);
    
    return 0;
}