#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * ddown[i] => farthest infected node in subtree of i
 * ddown[i] => Base Case => If no infected node below me then 0 if I am infected else -inf
 * dp[root] => ddown[root]
 * dp[i] = max(ddown[i], second max path of parent not m ancestor or descendent + 1)
 */

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, d;
    std::cin >> n >> m >> d;
    
    std::vector<int> isInfected(n);    
    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        isInfected[x - 1] = 1;   
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
    
    std::vector<int> ddown(n, -inf);
    auto dfs1 = [&](auto &&self, int u, int p) -> void
    {
        if (isInfected[u])
            ddown[u] = 0;
            
        for (int v : adj[u])        
        {
            if (v == p)
                continue;
            
            self(self, v, u);
            if (ddown[v] != -inf)
                ddown[u] = std::max(ddown[u], ddown[v] + 1);    
        }
    }; dfs1(dfs1, 0, 0);
    
    std::vector<int> dup(n, -inf);
    if (isInfected[0])
        dup[0] = 0;
    
    auto dfs2 = [&](auto &&self, int u, int p) -> void
    {
        int max = -inf, smax = -inf;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            
            if (max <= ddown[v])
                smax = max, max = ddown[v];
            else if (smax < ddown[v])
                smax = ddown[v];
        }
        
        if (p != u and dup[p] != -inf)
            dup[u] = std::max(dup[u], dup[p] + 1);

        for (int v : adj[u])
        {
            if (v == p)
                continue;
            
            if (max == ddown[v])
            {
                if (smax != -inf)
                    dup[v] = std::max(dup[v], smax + 2);
            }
            else
            {
                if (max != -inf)
                    dup[v] = std::max(dup[v], max + 2);
            }
            
            self(self, v, u);
        }
        
    }; dfs2(dfs2, 0, 0);
    
    int ans = 0;
    print(dup)
    print(ddown)
    for (int i = 0; i < n; i++)
    {
        int dist = std::max(ddown[i], dup[i]);
        if (dist != -inf and dist <= d)
            ans++;
    }
    
    std::cout << ans;
    
    return 0;
}