#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 2>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::set<std::pair<i64, int>> pq;

    pq.emplace(0, 0); // {distance, node}
    std::vector<int> par(n);
    std::vector<i64> distance(n, inf);
    distance[0] = 0;

    while (!pq.empty())
    {
        auto [d, u] = *std::begin(pq);
        pq.erase({d, u});

        for (auto [v, wt] : adj[u])
        {
            if (distance[v] > distance[u] + wt)
            {
                pq.erase({distance[v], v});
                distance[v] = distance[u] + wt;
                par[v] = u;
                pq.emplace(distance[v], v);
            }
        }
    }

    if (distance[n - 1] == inf)
        std::cout << "-1\n";
    else
    {
        std::vector<int> ans(1, n - 1);
        while (par[ans.back()] != ans.back())
            ans.emplace_back(par[ans.back()]);

        for (int i = std::ssize(ans) - 1; i >= 0; i--)
            std::cout << ans[i] + 1 << " \n"[i == 0];
    }
}