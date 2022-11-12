#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e16;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n), rev(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[--u].emplace_back(--v, w);
        rev[v].emplace_back(u, w);
    }

    auto dijkstra = [&](int src, auto & a)
    {
        std::vector<i64> distance(n, inf);
        std::set<std::pair<i64, int>> q;

        distance[src] = 0;
        q.emplace(distance[src], src);

        while (!q.empty())
        {
            auto [d, u] = *std::begin(q);
            q.erase(std::begin(q));

            for (auto [v, wt] : a[u])
            {
                if (distance[v] > distance[u] + wt)
                {
                    q.erase({distance[v], v});
                    distance[v] = distance[u] + wt;
                    q.emplace(distance[v], v);
                }
            }
        }

        return distance;
    };

    auto d1 = dijkstra(0, adj);
    

    for (int i = 1; i < n; ++i)
    {
        auto d2 = dijkstra(i, rev);
        if (d1[i] == inf and d2[i] == inf)
            std::cout << -1 << " \n"[i == n - 1];
        else
        {
            i64 cost = inf;
            for (int j = 0; j < n; j++)
                cost = std::min(cost, d1[j] + d2[j]);
            std::cout << cost << " \n"[i == n - 1];
        }
    }

    return 0;
}