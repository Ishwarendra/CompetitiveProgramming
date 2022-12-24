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

    a.resize(std::unique(std::begin(a), std::end(a)) - std::begin(a));
    n = std::ssize(a);

    constexpr int inf = 1e9;
    std::vector dp(n, std::vector(n, std::array{inf, inf}));

    for (int i = 0; i < n; i++)
        dp[i][i][0] = dp[i][i][1] = 0;

    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + len - 1;
            if (i - 1 >= 0 and j < n)
                dp[i - 1][j][0] = std::min({dp[i - 1][j][0], dp[i][j][0] + (a[i - 1] != a[i]), dp[i][j][1] + (a[i - 1] != a[j])});

            if (j + 1 < n)
                dp[i][j + 1][1] = std::min({dp[i][j + 1][1], dp[i][j][0] + (a[j + 1] != a[i]), dp[i][j][1] + (a[j + 1] != a[j])});
        }
    }

    std::cout << std::min(dp[0][n - 1][0], dp[0][n - 1][1]);

    return 0;
}