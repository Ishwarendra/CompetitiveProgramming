#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::array<int, 2>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    double p;
    std::cin >> n >> m >> p;

    std::vector a(n, std::vector<int>(m));
for (int i = 0; i < n; ++i)
{
    for (int j = 0; j < m; ++j)
    {
        std::string x;
        std::cin >> x;

        if (std::stod(x) >= p)
            a[i][j] = 1;
    }
}

    std::vector<int> comp(n + m);
    std::function<void(int, int)> dfs;
    dfs = [&](int i, int j)
    {
        a[i][j] = 0;
        comp[i] = 1, comp[j + n] = 1;

        for (auto [dx, dy] : dirs)
        {
            int x = (i + dx + n) % n;
            int y = (j + dy + m) % m;

            if (a[x][y])
                dfs(x, y);
        }
    };

    for (int i = 0; i < m; ++i)
    {
        if (a[0][i])
        {
            std::fill(std::begin(comp), std::end(comp), 0);
            dfs(0, i);

            if (std::accumulate(std::begin(comp), std::end(comp), 0) == n + m)
            {
                std::cout << "YES\n";
                std::exit(0);
            }
        }
    }

    std::cout << "NO\n";
    
    return 0;
}