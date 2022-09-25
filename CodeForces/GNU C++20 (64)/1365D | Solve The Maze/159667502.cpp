#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
void solve()
{
    int n, m;
    std::cin >> n >> m;
 
    std::vector<std::string> a(n);
 
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];
 
    int cg = 0, cb = 0;
 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cb += a[i][j] == 'B';
            cg += a[i][j] == 'G';
        }
    }
 
    if (!cg)
    {
        std::cout << "Yes\n";
        return;
    }
 
    std::vector<std::pair<int, int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
 
    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };
 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'B')
            {
                for (auto [dx, dy] : dirs)
                {
                    if (safe(i + dx, j + dy))
                    {
                        if (a[i + dx][j + dy] == 'G')
                        {
                            std::cout << "No\n";
                            return;
                        }
 
                        if (a[i + dx][j + dy] == '.')
                            a[i + dx][j + dy] = '#';
                    }
                }       
            }
        }
    }
 
    for (auto i : a)
        print(i)
 
    std::queue<std::pair<int, int>> q;
    q.emplace(n - 1, m - 1);
    std::vector<std::vector<int>> vis(n, std::vector<int>(m));
    vis.back().back() = 1;
 
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
 
        for (auto [dx, dy] : dirs)
        {
            if (safe(i + dx, j + dy) and !vis[i + dx][j + dy] and a[i + dx][j + dy] != '#')
            {
                vis[i + dx][j + dy] = 1;
                q.emplace(i + dx, j + dy);
            }
        }
    }
 
    int cnt = 0;
 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (vis[i][j] and a[i][j] == 'G')
                cnt++;
            if (vis[i][j] and a[i][j] == 'B')
            {
                std::cout << "No\n";
                return;
            }
        }
    }
 
    if (cnt == cg)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}