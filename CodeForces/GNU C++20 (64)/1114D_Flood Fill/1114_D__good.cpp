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
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        m[a[i]] = 1;
    }

    int index = 0;
    for (auto &[num, f] : m)
        f = index++;

    if (std::ssize(m) == 1)
    {
        std::cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
        a[i] = m[a[i]];

    constexpr int inf = 1e9;
    std::vector dp(n, std::vector(n, std::vector(index, inf)));

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < index; k++)
        {
            dp[i][i][k] = (a[i] != k);
            if (i + 1 < n)
                dp[i][i + 1][k] = (a[i] != a[i + 1]) + (a[i] != k);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int gap = 3; i + gap - 1 < n; gap++)
        {
            int j = i + gap - 1;

            for (int c = 0; c < index; c++)
            {
                for (int k = i + 1; k <= j - 1; k++)
                    dp[i][j][c] = std::min(dp[i][j][c], dp[i][k - 1][c] + dp[k][k][c] + dp[k + 1][j][c]);
            }
        }
    }

    std::cout << *std::min_element(std::begin(dp[0][n - 1]), std::end(dp[0][n - 1]));

    return 0;
}