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

    std::vector<std::vector<int>> adj(n);

    for (int i = 1; i < n; i++)
    {
        int p;
        std::cin >> p;

        adj[p - 1].emplace_back(i);
    }

    std::vector<int> sz(n);

    auto dfs = [&](auto &&self, int u) -> void
    {
        sz[u] = 1;
        for (auto v : adj[u])
        {
            self(self, v);
            sz[u] += sz[v];
        }
    }; dfs(dfs, 0);

    std::vector dp(n, 0);
    auto work = [&](auto &&self, int u, int done) -> void
    {
        if (sz[u] <= 1)
            return;

        int heavy = -1;
        int tot = 0;
        for (int v : adj[u])
            tot += sz[v];

        for (int v : adj[u])
        {
            if (sz[v] - done > tot - sz[v])
                heavy = v;
        }

        if (heavy == -1)
            dp[u] = (tot - done) / 2;
        else
        {
            int other = tot - sz[heavy];
            self(self, heavy, std::max(0, done + other - 1));
            dp[u] = other + dp[heavy];
        }
    }; work(work, 0, 0);

    std::cout << dp[0] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}