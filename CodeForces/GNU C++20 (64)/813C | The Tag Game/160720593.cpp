#include<bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x;
    std::cin >> n >> x;
 
    std::vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    std::vector<int> da(n + 1, -1), db(n + 1, -1);
 
    std::function<void(int, int, std::vector<int> &)> dfs;
    dfs = [&](int u, int p, std::vector<int> &depth)
    {
        depth[u] = depth[p] + 1;
 
        for (int v : adj[u])
        {
            if (v != p)
                dfs(v, u, depth);
        }
    };
    dfs(1, 0, da);
    dfs(x, 0, db);
 
    int ans = 2;
    for (int i = 1; i <= n; ++i)
    {
        if (da[i] > db[i])
        {
            ans = std::max(ans, da[i] * 2);
        }
    }
 
    std::cout << ans << "\n";
 
    return 0;
}