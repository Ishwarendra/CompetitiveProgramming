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
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        std::cin >> s[i];

    constexpr i64 inf = 1e18;
    std::vector dp(n, std::vector<std::pair<int, i64>>(n, {n, inf}));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == 'Y')
            {
                if (i == j)
                    dp[i][j] = std::min<std::pair<int, i64>>(dp[i][j], {0, -a[i]});
                else
                    dp[i][j] = std::min<std::pair<int, i64>>(dp[i][j], {1, -a[i] - a[j]});
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][k].second == inf or dp[k][j].second == inf)
                    continue;

                dp[i][j] = std::min<std::pair<int, i64>>(dp[i][j],
                    {dp[i][k].first + dp[k][j].first, dp[i][k].second + dp[k][j].second + a[k]});
            }
        }
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;
        --u, --v;

        auto [d, val] = dp[u][v];
        if (val == inf)
            std::cout << "Impossible\n";
        else
            std::cout << d << ' ' << -val << '\n';
    }

    return 0;
}