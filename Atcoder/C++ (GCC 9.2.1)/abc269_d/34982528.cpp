#include <bits/stdc++.h>

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
    
    int n;
    std::cin >> n;

    constexpr int N = 2000;
    std::vector vis(N + 1, std::vector<int>(N + 1));
    std::vector<std::array<int, 2>> dirs {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
    auto a = vis;

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        x += N / 2, y += N / 2;
        a[x][y] = 1;
    }

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i <= N and j <= N;
    };

    std::function<void(int, int)> dfs = [&](int i, int j)
    {
        vis[i][j] = 1;
        for (auto [dx, dy] : dirs)
        {
            if (safe(i + dx, j + dy) and a[i + dx][j + dy] == 1 and !vis[i + dx][j + dy])
                dfs(i + dx, j + dy);
        }
    };

    int ans = 0;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; ++j)
        {
            if (!vis[i][j] and a[i][j] == 1)
            {
                dfs(i, j);
                ans++;
            }
        }
    }

    std::cout << ans;
    
    return 0;
}