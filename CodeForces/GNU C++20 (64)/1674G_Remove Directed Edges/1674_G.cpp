#include "bits/stdc++.h"

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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n], indeg(n), outdeg(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        indeg[v]++;
        outdeg[u]++;
    }

    std::vector<int> dp(n, -1);
    std::function<int(int)> dfs = [&](int u)
    {
        if (dp[u] != -1)
            return dp[u];

        dp[u] = 1;
        for (int v : adj[u])
        {
            if (indeg[v] > 1 and outdeg[u] > 1)
                dp[u] = std::max(dp[u], dfs(v) + 1);
        }

        return dp[u];
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = std::max(ans, dfs(i));

    std::cout << ans;
    
    return 0;
}