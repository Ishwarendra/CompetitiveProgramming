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
    }; 

    int root = -1;
    for (int i = 0; i < n; i++)
    {
        if (std::size(adj[i]) >= 3)
            root = i;
    }

    if (root != -1)
    {
        dfs(root, root);
        std::cout << dp[root] << "\n";
    }
    else
        std::cout << "1\n";
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