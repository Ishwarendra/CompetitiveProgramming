#include "bits/stdc++.h"

void solve()
{
    int n, m, x;
    std::cin >> n >> m >> x;
    x--;

    std::vector<int> dp(n, 0);
    dp[x] = 1;

    for (int i = 0; i < m; i++)
    {
        int r;
        char ch;
        std::cin >> r >> ch;

        std::vector<int> ndp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (dp[j] == 0)
                continue;
            
            if (ch == '0' || ch == '?')
            {
                int next = (j + r) % n;
                ndp[next] = 1;
            }

            if (ch == '1' || ch == '?')
            {
                int next = (j - r + n) % n;
                ndp[next] = 1;
            }
        }

        std::swap(dp, ndp);
    }

    std::cout << std::accumulate(dp.begin(), dp.end(), 0) << '\n';
    for (int i = 0; i < n; i++)
    {
        if (dp[i])
            std::cout << i + 1 << ' ';
    }

    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();
}