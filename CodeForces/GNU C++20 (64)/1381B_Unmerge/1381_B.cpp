#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> p(n * 2);
    for (int i = 0; i < n * 2; i++)
        std::cin >> p[i];

    std::vector<int> den;
    auto split = [&](auto self, int left, int right)
    {
        if (right < left)
            return;

        int max_id = std::max_element(std::begin(p) + left, std::begin(p) + right + 1) - std::begin(p);
        den.emplace_back(right - max_id + 1);
        self(self, left, max_id - 1);
    };

    split(split, 0, 2 * n - 1);
    std::sort(std::begin(den), std::end(den));

    std::vector dp(2 * n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < std::ssize(den); i++)
    {
        std::vector ndp(2 * n + 1, 0);
        for (int j = 0; j < 2 * n + 1; j++)
        {
            ndp[j] |= dp[j];
            if (j - den[i] >= 0)
                ndp[j] |= dp[j - den[i]];
        }

        std::swap(ndp, dp);
    }

    std::cout << (dp[n] ? "YES\n" : "NO\n");
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