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

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::vector<i64> dp(n);
    i64 ans = *std::max_element(std::begin(a), std::end(a));

    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        i64 max = 0, smax = 0;
        for (auto [v, w] : adj[u])
        {
            if (v == p)
                continue;

            self(self, v, u);
            auto nval = dp[v] - w;

            if (nval >= max)
                smax = max, max = nval;
            else if (nval > smax)
                smax = nval;
        }

        ans = std::max(ans, max + smax + a[u]);
        dp[u] = max + a[u];

    }; dfs(dfs, 0, 0);
    
    std::cout << ans;

    return 0;
}