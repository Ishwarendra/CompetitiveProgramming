#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, l;
    std::cin >> n >> k >> l;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> d(2 * k + 1);
    for (int i = 0; i <= k; i++)
        d[i] = i;
    for (int i = k + 1; i < 2 * k + 1; i++)
        d[i] = k - (i - k);

    std::vector dp(n + 1, std::vector(2 * k + 1, 0));
    std::fill(std::begin(dp[0]), std::end(dp[0]), 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 2 * k + 1; j++)
        {
            dp[i][j] |= dp[i - 1][j - 1] && (a[i - 1] + d[j] <= l);
            if (j < 2 * k)
                dp[i][j + 1] |= dp[i][j] && (a[i - 1] + d[j + 1] <= l);
            else
                dp[i][0] |= dp[i].back() && (a[i - 1] <= l);
        }

        dp[i][0] = dp[i].back();
    }

    for (int i = 0; i < 2 * k + 1; i++)
    {
        if (dp.back()[i])
        {
            std::cout << "Yes\n";
            return;
        }
    }

    std::cout << "No\n";
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