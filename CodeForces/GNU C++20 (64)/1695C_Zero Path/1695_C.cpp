#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 2e3 + 2;
constexpr int offset = 1e3;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    auto safe = [&](int i, int j) 
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    auto shift = [&](auto &x, auto pos)
    {
        if (pos < 0)
            return (x >> -pos);
        else
            return (x << pos);
    };

    std::vector<std::bitset<N>> dp(m);
    dp[0][offset + a[0][0]] = 1;
    int sum = offset + a[0][0];

    for (int i = 1; i < m; i++)
    {
        sum += a[0][i];
        dp[i][sum] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        std::vector<std::bitset<N>> ndp(m);
        for (int j = 0; j < m; j++)
        {
            if (safe(i, j - 1))
                ndp[j] |= shift(ndp[j - 1], a[i][j]);
            
            if (safe(i - 1, j))
                ndp[j] |= shift(dp[j], a[i][j]);
        }

        std::swap(ndp, dp);
    }

    std::cout << (dp[m - 1][offset] ? "YES\n" : "NO\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}