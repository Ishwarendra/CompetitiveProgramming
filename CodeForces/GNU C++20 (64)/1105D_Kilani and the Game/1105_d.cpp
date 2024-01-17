#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, p;
    std::cin >> n >> m >> p;

    std::vector<int> a(p);
    for (int i = 0; i < p; i++)
        std::cin >> a[i];

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
    std::vector<std::string> g(n);
    std::vector<i64> need(p);

    for (int i = 0; i < n; i++)
        std::cin >> g[i];

    i64 pref = 0;
    std::set<std::tuple<i64, int, int, int>> s;
    for (int id = 0; id < p; id++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] != '.' and g[i][j] != '#' and g[i][j] - '1' == id)
                    s.emplace(pref, -id, i, j);
            }
        }

        pref += a[id];
        need[id] += pref;
    }

    int last = -0;
    auto safe = [&](int i, int j)
    {
        return 0 <= i and i < n and 0 <= j and j < m and g[i][j] == '.';
    };

    std::vector ans(p, 0);
    while (!s.empty())
    {
        auto [d, u, x, y] = *std::begin(s);
        s.erase(std::begin(s));
        ans[-u]++;

        if (u != last)
        {
            need[-last] += sum;
            // print(need)
        }

        for (auto [dx, dy] : dirs)
        {
            if (!safe(x + dx, y + dy))
                continue;

            g[x + dx][y + dy] = char(-u + '1');
            if (d + 1 == need[-u])
                s.emplace(d + 1 + sum - a[-u], u, x + dx, y + dy);
            else
                s.emplace(d + 1, u, x + dx, y + dy);
        }

        last = u;
    }
    
    for (int id = 0; id < p; id++)
        std::cout << ans[id] << " \n"[id == p - 1];

    return 0;
}