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
    
    int n, t;
    std::cin >> n >> t;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < t; i++)
    {
        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++)
        {
            int u, v;
            std::cin >> u >> v;
            u--, v--;

            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }

    int k;
    std::cin >> k;

    std::vector<int> a(k);
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < k; i++)
    {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]].emplace_back(i + 1);
    }

    std::vector<i64> d(n, inf);
    d[0] = 0;
    std::set<std::pair<i64, int>> s;
    s.emplace(d[0], 0);

    while (!s.empty())
    {
        auto [dist, u] = *std::begin(s);
        s.erase(std::begin(s));

        for (auto &[v, idx] : adj[u])
        {
            auto it = std::upper_bound(std::begin(pos[idx]), std::end(pos[idx]), dist);
            if (it == std::end(pos[idx]))
                continue;

            if (d[v] > *it)
            {
                s.erase({d[v], v});
                d[v] = *it;
                s.emplace(d[v], v);
            }
        }
    }
    
    std::cout << (d[n - 1] == inf ? -1 : d[n - 1]);
    
    return 0;
}