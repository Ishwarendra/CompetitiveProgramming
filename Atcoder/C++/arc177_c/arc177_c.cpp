#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

std::vector<std::pair<int, int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::vector par(n, std::vector(n, std::pair {-1, -1}));
    auto safe = [&](int i, int j)
    {
        return 0 <= i and i < n and 0 <= j and j < n;
    };
    
    auto bfs = [&](int sx, int sy, char ch)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                par[i][j] = std::pair {-1, -1};
        }
        
        std::vector d(n, std::vector(n, inf));
        std::set<std::tuple<int, int, int>> q;
        d[sx][sy] = a[sx][sy] == ch;
        q.emplace(a[sx][sy] == ch, sx, sy);
        
        while (!q.empty())
        {
            auto [dist, x, y] = *std::begin(q);
            q.erase(std::begin(q));
            
            for (auto &[dx, dy] : dirs)
            {
                if (!safe(x + dx, y + dy))
                    continue;
                
                int w = a[x + dx][y + dy] == ch;
                if (d[x + dx][y + dy] > dist + w)
                {
                    q.erase({d[x + dx][y + dy], x + dx, y + dy});
                    d[x + dx][y + dy] = dist + w;
                    par[x + dx][y + dy] = {x, y};
                    q.emplace(d[x + dx][y + dy], x + dx, y + dy);
                }
            }
        }
        
        return d;
    };
    
    bfs(0, 0, 'B');
    int x = n - 1, y = n - 1;
    
    int ans = 0;
    while (x != -1)
    {
        if (a[x][y] == 'B')
            ans++, a[x][y] = 'P';
        std::tie(x, y) = par[x][y];
    }
    
    auto db = bfs(0, n - 1, 'R');
    ans += db[n - 1][0];
    
    std::cout << ans;
    
    return 0;
}