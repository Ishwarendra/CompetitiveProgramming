#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> x(k);
    for (int i = 0; i < k; i++)  
    {
        std::cin >> x[i];
        x[i]--;
    }

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto bfs = [&](std::vector<int> src)
    {
        constexpr int inf = 1e9;
        std::vector<int> d(n, inf);

        std::queue<int> q;
        for (auto u : src)
        {
            q.emplace(u);
            d[u] = 0;
        }

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] != inf)
                    continue;
                d[v] = d[u] + 1;
                q.emplace(v);
            }
        }

        return d;
    };

    auto d1 = bfs({0});
    auto d2 = bfs(x);

    std::vector<int> vis(n);
    int can = 0;
    std::function<void(int)> dfs = [&](int u)
    {
        bool leaf = true;
        vis[u] = 1;

        for (int v : adj[u])
        {
            if (!vis[v])
                leaf = false;
            if (!vis[v] and d1[v] < d2[v])
                dfs(v);
        }

        if (leaf)
            can = 1;
    }; dfs(0);

    std::cout << (can ? "YES\n" : "NO\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}