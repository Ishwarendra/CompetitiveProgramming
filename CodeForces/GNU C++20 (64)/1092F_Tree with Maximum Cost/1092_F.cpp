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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (n == 1)
    {
        std::cout << "0\n";
        return 0;
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

    std::vector<i64> dp(n), sum(n);

    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        sum[u] = a[u];
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            sum[u] += sum[v];
            dp[u] += dp[v] + sum[v];
        }
    }; dfs(0, 0);

    auto move = [&](int u, int p)
    {
        sum[p] -= sum[u];
        dp[p] -= dp[u] + sum[u];

        sum[u] += sum[p];
        dp[u] += dp[p] + sum[p];
    };

    i64 ans = 0;
    dfs = [&](int u, int p)
    {
        ans = std::max(ans, dp[u]);
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            auto dp_u = dp[u], dp_v = dp[v];
            auto sum_u = sum[u], sum_v = sum[v];

            move(v, u);
            dfs(v, u);

            dp[u] = dp_u, dp[v] = dp_v;
            sum[u] = sum_u, sum[v] = sum_v;
        }
    }; dfs(0, 0);

    std::cout << ans;

    return 0;
}