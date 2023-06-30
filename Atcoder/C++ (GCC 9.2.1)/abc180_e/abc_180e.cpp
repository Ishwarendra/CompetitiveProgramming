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

    std::vector a(n, std::array<int, 3>());
    for (auto &[x, y, z] : a)
        std::cin >> x >> y >> z;

    auto dist = [&](int i, int j)
    {
        auto x = a[i];
        auto y = a[j];
        return std::abs(x[0] - y[0]) + std::abs(x[1] - y[1]) + std::max(0, y[2] - x[2]);
    };

    const int m = 1 << n;
    constexpr int inf = 1e9;
    std::vector dp(n, std::vector(m, inf));

    dp[0][1] = dist(1, 1);
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    for (int mask = 0; mask < m; mask++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (getBit(mask, u) and getBit(mask, v) and u != v)
                    dp[u][mask] = std::min(dp[u][mask], dp[v][mask ^ (1 << u)] + dist(v, u));
            }
        }
    }

    int ans = inf;
    for (int i = 1; i < n; i++)
        ans = std::min(ans, dp[i][m - 1] + dist(i, 0));

    std::cout << ans;

    return 0;
}