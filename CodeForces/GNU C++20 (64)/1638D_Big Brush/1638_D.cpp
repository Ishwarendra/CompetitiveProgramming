#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    auto safe = [&](int i, int j)
    {
        return i >= 0 and i < n and j >= 0 and j < m; 
    };

    std::vector<std::tuple<int, int, int>> ans;
    std::queue<std::tuple<int, int, int>> q;
    std::vector b(n, std::vector(m, 0));

    auto get = [&](int i, int j)
    {
        std::set<int> s;
        if (!safe(i + 1, j + 1) or !safe(i, j))
            return -1;

        for (auto [dx, dy] : dirs)
        {
            if (b[i + dx][j + dy] == 0)
                s.emplace(a[i + dx][j + dy]);
        }

        return std::size(s) == 1 ? *std::begin(s) : -1;
    };

    auto apply = [&](int x, int y, int c)
    {
        ans.emplace_back(x, y, c);
        for (auto [dx, dy] : dirs)
        {
            if (b[x + dx][y + dy] == 0)
                b[x + dx][y + dy] = c;
        }
    };

    std::vector vis(n, std::vector<int>(m));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {   
            auto c = get(i, j);
            if (c != -1)
            {
                q.emplace(i, j, c);
                vis[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y, c] = q.front();
        q.pop();
        apply(x, y, c);

        for (int dx = -1; dx <= 2; dx++)
        {
            for (int dy = -1; dy <= 2; dy++)
            {
                if (!safe(x + dx, y + dy) or vis[x + dx][y + dy])
                    continue;

                auto col = get(x + dx, y + dy);
                if (col != -1)
                {
                    q.emplace(x + dx, y + dy, col);
                    vis[x + dx][y + dy] = 1;
                }
            }
        }
    }

    if (b == a)
    {
        std::reverse(std::begin(ans), std::end(ans));
        std::cout << std::size(ans) << "\n";
        for (auto &[x, y, c] : ans)
            std::cout << x + 1 << " " << y + 1 << " " << c << "\n";
    }
    else
        std::cout << -1;
    
    return 0;
}