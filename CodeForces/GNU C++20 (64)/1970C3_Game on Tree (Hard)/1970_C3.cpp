#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, t;
    std::cin >> n >> t;

    std::vector adj(n, std::vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    std::vector<int> cnt(n);
    auto dfs1 = [&](auto &&dfs, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            
            dfs(dfs, v, u);
            cnt[u] += cnt[v] == 0;
        }
        
    }; dfs1(dfs1, 0, 0);
    
    std::vector<int> ans(n);
    auto dfs2 = [&](auto &&dfs, int u, int p) -> void
    {
        ans[u] = cnt[u] == 0;
        
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            
            cnt[u] -= (cnt[v] == 0);
            cnt[v] += (cnt[u] == 0);
            dfs(dfs, v, u);
            cnt[v] -= (cnt[u] == 0);
            cnt[u] += (cnt[v] == 0);
        }
    }; dfs2(dfs2, 0, 0);
    
    while (t--)
    {
        int x;
        std::cin >> x;
        std::cout << (ans[x - 1] ? "Hermione\n" : "Ron\n");
    }
    
    return 0;
}