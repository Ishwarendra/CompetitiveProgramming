#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
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

    if (n == 1)
    {
        std::cout << "0\n";
        return;
    }

    std::vector<int> dp(n), rem(n);

    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        int sub = 0;
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u);
            dp[u] += dp[v];
            sub += dp[v] == 0;
        }

        rem[u] = sub;
        dp[u] += std::max(0, rem[u] - 1);
    }; dfs(0, 0);

    auto move = [&](int u, int p)
    {   
        dp[p] -= dp[u];
        dp[p] -= std::max(0, rem[p] - 1);
        rem[p] -= dp[u] == 0;
        dp[p] += std::max(0, rem[p] - 1);

        dp[u] += dp[p];
        dp[u] -= std::max(0, rem[u] - 1);
        rem[u] += dp[p] == 0;
        dp[u] += std::max(0, rem[u] - 1);
    };

    int ans = 1e9;
    dfs = [&](int u, int p)
    {
        ans = std::min(ans, 1 + dp[u]);

        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            int dp_u = dp[u], dp_v = dp[v];
            int rem_u = rem[u], rem_v = rem[v];
            
            move(v, u);
            dfs(v, u);

            dp[u] = dp_u, dp[v] = dp_v;
            rem[u] = rem_u, rem[v] = rem_v;
        }
    }; dfs(0, 0);

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