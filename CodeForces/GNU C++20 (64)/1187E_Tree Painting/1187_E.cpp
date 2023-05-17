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
    
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<i64> dp(n), size(n);
    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        size[u] = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u);
            size[u] += size[v];
            dp[u] += dp[v];
        }

        dp[u] += size[u];
    }; dfs(0, 0);

    i64 ans = dp[0];

    auto move = [&](int u, int p)
    {
        dp[p] -= size[p];
        size[p] -= size[u];
        dp[p] += size[p];
        dp[p] -= dp[u];

        dp[u] -= size[u];
        size[u] += size[p];
        dp[u] += size[u];
        dp[u] += dp[p];
    };

    dfs = [&](int u, int p)
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            int old_u = dp[u], old_v = dp[v];
            int size_u = size[u], size_v = size[v];

            move(v, u);
            ans = std::max(ans, dp[v]);
            dfs(v, u);

            dp[u] = old_u, dp[v] = old_v;
            size[u] = size_u, size[v] = size_v;
        }
    }; dfs(0, 0);

    std::cout << ans;

    return 0;
}