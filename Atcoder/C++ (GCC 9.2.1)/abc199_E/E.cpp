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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> a[n];
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        a[x].emplace_back(y, z);
    }

    std::vector dp(n + 1, std::vector<i64>(1 << (n + 1), -1));
    std::function<i64(int, int)> f;
    f = [&](int mask, int i) -> i64
    {
        if (i == n)
            return 1LL;

        i64 &ans = dp[i][mask];
        if (ans != -1)
            return ans;

        ans = 0;
        for (auto [y, z] : a[i])
        {

            int cnt = 0;
            if (mask % (1 << y))
                cnt += __builtin_popcount(mask % (1 << y));
            if (cnt > z)
                return 0;
        }

        for (int j = 0; j < n; j++)
        {
            if ((mask >> j) & 1)
                continue;
            ans += f(mask | (1 << j), i + 1);
        }

        return ans;
    };

    std::cout << f(0, 0);
    
    return 0;
}