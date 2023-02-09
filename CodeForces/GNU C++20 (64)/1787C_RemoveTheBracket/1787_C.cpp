#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void solve()
{
    int n, s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<std::array<int, 2>> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= s)
            b.push_back({s, a[i] - s});
        else
            b.push_back({0, a[i]});
    }

    std::vector dp(n, std::array {inf, inf});

    for (int i = 0; i < 2; i++)
        dp[0][i] = 1LL * a[0] * b[1][i];

    for (int i = 1; i < n - 2; i++)
    {
        auto [x1, y1] = b[i];
        auto [x2, y2] = b[i + 1];

        dp[i][0] = std::min(dp[i - 1][0] + 1LL * y1 * x2, dp[i - 1][1] + 1LL * x1 * x2);
        dp[i][1] = std::min(dp[i - 1][0] + 1LL * y1 * y2, dp[i - 1][1] + 1LL * x1 * y2);
    }

    // for (int i = 0; i < n - 2; i++)
    //     print(dp[i])

    auto [x, y] = b[n - 2];
    i64 ans = std::min(dp[n - 3][0] + 1LL * y * a.back(), dp[n - 3][1] + 1LL * x * a.back());
    std::cout << ans << "\n";
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