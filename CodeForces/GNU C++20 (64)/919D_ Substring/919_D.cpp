#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> indeg(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        indeg[v]++;
    }
    
    std::vector<int> vis(n);
    int cycle = 0;
    auto dfs = [&](auto &&self, int u) -> void
    {
        vis[u] = 1;
        for (int v : adj[u])  
        {
            if (vis[v] == 1)
                cycle = 1;
            else if (!vis[v])
                self(self, v);
        }
        vis[u] = 2;
    };
    
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(dfs, i);
    }
    
    if (cycle)
    {
        std::cout << -1;
        return 0;
    }
    
    auto get = [&](int ch)
    {
        std::queue<int> q;
        std::vector<int> dp(n, -inf);
        auto deg = indeg;
        
        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 0)
            {
                q.emplace(i);
                dp[i] = (s[i] == ch + 'a');
            }
        }
        
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            
            for (int v : adj[u])
            {
                deg[v]--;
                dp[v] = std::max(dp[v], dp[u] + (s[v] == ch + 'a'));
                if (deg[v] == 0)
                    q.emplace(v);
            }
        }
        
        return *std::max_element(std::begin(dp), std::end(dp));
    };
    
    int ans = 0;
    for (int ch = 0; ch < 26; ch++)
        ans = std::max(ans, get(ch));
    
    std::cout << ans;

    return 0;
}