#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    i64 k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<std::set<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace(v);
    }

    if (k == 1)
    {
        std::cout << *std::min_element(std::begin(a), std::end(a)) << "\n";
        return 0;      
    }

    auto good = [&](int mid)
    {
        std::vector<i64> dp(n);
        std::vector<int> vis(n);

        std::function<void(int)> dfs = [&](int u)
        {
            vis[u] = 1;

            for (int v : adj[u])
            {
                if (a[v] > mid || a[u] > mid)
                    continue;

                if (vis[v] == 1 or dp[v] == inf)
                    dp[u] = inf;
                else
                {
                    if (!vis[v])
                        dfs(v);
                    dp[u] = std::max(dp[u], 1 + dp[v]);
                }
            }

            vis[u] = 2;
        }; 

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i);

            if (dp[i] >= k - 1)    
                return true;
        }

        return false;
    };  

    int left = 1, right = 1e9;
    int ans = -1;
    while (left <= right)
    {
        auto mid = (left + right) >> 1;
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans;
    
    return 0;
}