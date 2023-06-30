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

    std::vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    std::sort(std::begin(a), std::end(a));

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto bfs = [&](int src)
    {
        std::vector d(n, inf);
        d[src] = 0;
        std::queue<int> q;
        q.emplace(src);

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (auto v : adj[u])
            {
                if (d[v] == inf)
                {
                    d[v] = d[u] + 1;
                    q.emplace(v);
                }
            }
        }

        return d;
    };
    
    auto d1 = bfs(0);
    auto d2 = bfs(n - 1);

    std::multiset<std::pair<int, int>, std::greater<>> dn;
    for (int i = 0; i < n; i++)
    {
        if (std::binary_search(std::begin(a), std::end(a), i))
            dn.emplace(d2[i], i);
    }

    std::vector<int> order(k);
    std::iota(std::begin(order), std::end(order), 0);

    std::sort(std::begin(order), std::end(order), [&](int i, int j)
    {
        int u = a[i], v = a[j];
        return d1[u] - d2[u] < d1[v] - d2[v];
    });

    int ans = d1[n - 1];
    int max = 0;
    
    for (int i : order)
    {
        int u = a[i];
        dn.erase(dn.find({d2[u], u}));
        if (dn.empty())
            break;

        auto [back, v] = *std::begin(dn);
        max = std::max(max, d1[u] + d2[v] + 1);
    }

    std::cout << std::min(ans, max);

    return 0;
}