#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::array<int, 2> a[n][n] {};
    std::array<int, 2> zero{-1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            std::cin >> x;

            if (x == 0)
                a[i][j] = {inf, inf}, zero = {i, j};
            else
            {
                while (x > 0 and x % 2 == 0)
                    x /= 2, a[i][j][0]++;
                while (x > 0 and x % 5 == 0)
                    x /= 5, a[i][j][1]++;
            }
        }
    }

    std::array<int, 2> dp[n][n] {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j][0] = dp[i][j][1] = inf;
    }

    dp[0][0] = a[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int p = 0; p < 2; p++)
            {
                if (i - 1 >= 0 and dp[i][j][p] > dp[i - 1][j][p] + a[i][j][p])
                    dp[i][j][p] = dp[i - 1][j][p] + a[i][j][p];

                if (j - 1 >= 0 and dp[i][j][p] > dp[i][j - 1][p] + a[i][j][p])
                    dp[i][j][p] = dp[i][j - 1][p] + a[i][j][p];
            }
        }
    }

    int p = 0;
    if (dp[n - 1][n - 1][1] < dp[n - 1][n - 1][0])
        p = 1;

    if (dp[n - 1][n - 1][p] > 1 and zero[0] != -1)
    {
        std::cout << "1\n";
        std::cout << std::string(zero[1], 'R') + std::string(zero[0], 'D') + std::string(n - zero[1] - 1, 'R') + std::string(n - zero[0] - 1, 'D');
        return 0;
    }

    int i = n - 1, j = n - 1;
    std::string ans;
    while (i != 0 or j != 0)
    {
        if (i - 1 < 0)
            ans += 'R', j--;
        else if (j - 1 < 0)
            ans += 'D', i--;
        else
        {
            if (dp[i - 1][j][p] < dp[i][j - 1][p])
                ans += 'D', i--;
            else
                ans += 'R', j--;
        }
    }

    std::cout << dp[n - 1][n - 1][p] << "\n";
    std::cout << std::string(std::rbegin(ans), std::rend(ans));

    return 0;
}