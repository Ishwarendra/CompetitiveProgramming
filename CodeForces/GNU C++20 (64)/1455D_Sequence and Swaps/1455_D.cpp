#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector dp(n, std::vector<std::vector<int>>(501, std::vector<int>(501, inf)));
    dp[0][a[0]][x] = 1;
    dp[0][x][a[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 501; ++j)
        {
            for (int k = 0; k < 501; ++k)
            {
                if (dp[i - 1][j][k] == inf)
                    continue;

                // last element is k and current_x is j
                if (a[i] >= k)
                    dp[i][j][a[i]] = std::min(dp[i][j][a[i]], dp[i - 1][j][k]);
                if (j >= k and a[i] > j)
                    dp[i][a[i]][j] = std::min(dp[i][a[i]][j], dp[i - 1][j][k] + 1);
            }
        }
    }

    int min = inf;
    for (int i = 0; i < 501; ++i)
        for (int j = 0; j < 501; ++j)
            min = std::min(min, dp[n - 1][i][j]);

    std::cout << (min == inf ? -1 : min) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}