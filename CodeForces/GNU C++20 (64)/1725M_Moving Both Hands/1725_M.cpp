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

    std::vector<std::vector<std::array<int, 3>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        adj[--u].push_back({--v, w, 0});
        adj[v].push_back({u, w, 1});
    }

    auto dijkstra = [&](int src)
    {
        std::set<std::tuple<i64, int, int>> s;
        std::vector d(n, std::array<i64, 2>{inf, inf});

        s.emplace(0, src, 0);
        d[src][0] = 0;

        while (!s.empty())
        {
            auto [dist, u, rev] = *std::begin(s);
            s.erase(std::begin(s));

            for (auto [v, w, r] : adj[u])
            {
                if (rev)
                {
                    if (r == 0)
                        continue;

                    if (dist + w < d[v][r])
                    {
                        s.erase({d[v][r], v, r});
                        d[v][r] = dist + w;
                        s.insert({d[v][r], v, r});
                    }
                }
                else
                {
                    if (dist + w < d[v][r])
                    {
                        s.erase({d[v][r], v, r});
                        d[v][r] = dist + w;
                        s.insert({d[v][r], v, r});
                    }
                }
            }
        }

        return d;
    };

    auto d = dijkstra(0);
    for (int i = 1; i < n; i++)
    {
        if (d[i][0] == inf and d[i][1] == inf)
            std::cout << -1 << " \n"[i == n - 1];
        else
            std::cout << std::min(d[i][0], d[i][1]) << " \n"[i == n - 1];
    }
    
    return 0;
}