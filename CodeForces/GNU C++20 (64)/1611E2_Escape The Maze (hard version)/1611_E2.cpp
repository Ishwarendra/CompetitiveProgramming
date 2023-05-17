#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> a[i];
        a[i]--;
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
        std::queue<int> q;
        std::vector<int> d(n, inf);

        for (int x : src)
            q.emplace(x), d[x] = 0;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] == inf)
                {
                    d[v] = d[u] + 1;
                    q.emplace(v);
                }
            }
        }

        return d;
    };

    auto d1 = bfs({0});
    auto d2 = bfs(a);
    std::vector<int> leaf;
    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        int childless = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            childless = 0;
            dfs(v, u);
        }

        if (childless)
            leaf.emplace_back(u);
    }; dfs(0, 0);

    for (int u : leaf)
    {
        if (d1[u] < d2[u])
        {
            std::cout << "-1\n";
            return;
        }
    }

    std::queue<int> q({0});
    std::vector<int> vis(n);
    vis[0] = 1;

    int ans = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                if (d1[v] < d2[v])
                    q.emplace(v);
                else
                    ans++;
            }
        }
    }

    std::cout << ans << "\n";
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