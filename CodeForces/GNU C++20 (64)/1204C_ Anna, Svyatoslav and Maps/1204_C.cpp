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

    std::vector a(n, std::vector(n, 0));
    std::vector dp(n, std::vector(n, inf));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
        for (int j = 0; j < n; j++)
        {
            char ch;
            std::cin >> ch;
            a[i][j] = ch - '0';

            if (a[i][j])
                dp[i][j] = 1;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (dp[u][v] > dp[u][k] + dp[k][v])
                    dp[u][v] = dp[u][k] + dp[k][v];
            }
        }
    }

    int m;
    std::cin >> m;

    std::vector p(m, 0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> p[i];
        p[i]--;
    }

    std::vector<int> ans(1, p[0] + 1);
    int prev = 0, st = 0;

    for (int i = 1; i < m; i++)
    {
        if (prev + dp[p[i - 1]][p[i]] == dp[p[st]][p[i]])
        {
            prev++;
            continue;
        }

        prev = 0;
        i--;
        st = i;
        ans.emplace_back(p[i] + 1);
    }

    ans.emplace_back(p.back() + 1);

    std::cout << std::size(ans) << "\n";
    for (auto x : ans)
        std::cout << x << " ";

    return 0;
}