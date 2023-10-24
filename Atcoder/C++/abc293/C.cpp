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

    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    auto getBit = [&](int x, int pos) { return (x >> pos) & 1; };

    int ans = 0;
    for (int mask = 0; mask < (1 << (n + m - 2)); mask++)
    {
        if (__builtin_popcount(mask) != m - 1)
            continue;

        std::set<int> path {a[0][0]};
        int x = 0, y = 0;
        for (int i = 0; i < n + m - 2; i++)
        {
            if (getBit(mask, i))
                y++;
            else
                x++;

            path.emplace(a[x][y]);
        }

        ans += std::size(path) == n + m - 1;
    }

    std::cout << ans;
    
    return 0;
}