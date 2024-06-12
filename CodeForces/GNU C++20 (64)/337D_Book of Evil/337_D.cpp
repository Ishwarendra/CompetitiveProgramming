#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Multi source BFS (but instead of shortest path we want longest)
 * Farthest marked node for a vertex v:
 *     Either below it.
 *     Any one among it's ancestors (depth difference) 
 */

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, d;
    std::cin >> n >> m >> d;
    
    std::vector<int> infected(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> infected[i];
        infected[i]--;
    }
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    auto bfs = [&](int src)
    {
        std::queue<int> q;
        q.emplace(src);
        
        std::vector<int> d(n, inf);
        d[src] = 0;
        
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
    
    std::sort(std::begin(infected), std::end(infected));
    auto ds = bfs(infected[0]);
    int t = -1;
    for (int i : infected)
    {
        if (t == -1 or ds[t] < ds[i])
            t = i;
    }
    
    auto dt = bfs(t);
    t = -1;
    for (int i : infected)
    {
        if (t == -1 or dt[t] < dt[i])
            t = i;
    }
    ds = bfs(t);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (std::max(ds[i], dt[i]) <= d)
            ans++;
    }
    
    std::cout << ans;
    
    return 0;
}