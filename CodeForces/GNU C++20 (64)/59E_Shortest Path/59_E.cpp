#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::set<std::tuple<int, int, int>> s;
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--, c--;
        s.emplace(a, b, c);
    }

    std::vector dp(n, std::vector(n, inf));
    std::vector par(n, std::vector(n, std::array {-1, -1}));
    dp[0][0] = 0;
    std::queue<std::tuple<int, int, int>> q;
    q.emplace(0, 0, 0);

    while (!q.empty())
    {
        auto [d, u, p] = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (s.count({p, u, v}))
                continue;

            if (dp[v][u] > dp[u][p] + 1)
            {
                dp[v][u] = dp[u][p] + 1;
                par[v][u] = {u, p};
                q.emplace(dp[v][u], v, u);
            }
        }
    }

    int ans = inf;
    std::array<int, 2> end {-1, -1};
    for (int i = 0; i < n; i++)
    {
        if (ans > dp[n - 1][i])
        {
            end = {n - 1, i};
            ans = dp[n - 1][i];
        }
    }

    std::cout << (ans == inf ? -1 : ans) << "\n";
    // if (ans != inf)
    // {
    //     std::vector<int> path(1, n - 1);
    //     while (end[1] != -1)
    //     {
    //         path.emplace_back(end[1]);
    //         end = par[end[0]][end[1]];
    //     }

    //     path.pop_back();
    //     std::reverse(std::begin(path), std::end(path));
    //     for (int i = 0; i < std::size(path); i++)
    //         std::cout << path[i] + 1 << " \n"[i + 1 == std::size(path)];
    // }
    
    return 0;
}