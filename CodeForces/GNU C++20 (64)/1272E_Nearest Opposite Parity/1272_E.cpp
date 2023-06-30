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
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::set<std::pair<int, int>> q;
    std::vector<int> d(n, inf);

    auto add = [&](int u, int v)
    {
        if (a[v] % 2 != a[u] % 2)
            q.emplace(1, u), d[u] = 1;
    };

    for (int i = 0; i < n; i++)
    {
        if (i - a[i] >= 0)
        {
            adj[i].emplace_back(i - a[i]);
            add(i, i - a[i]);
        }
        if (i + a[i] < n)
        {
            adj[i].emplace_back(i + a[i]);
            add(i, i + a[i]);
        }
    }

    std::vector<int> radj[n];
    for (int i = 0; i < n; i++)
    {
        for (auto v : adj[i])
            radj[v].emplace_back(i);
    }

    while (!q.empty())
    {
        auto [du, u] = *std::begin(q);
        q.erase(std::begin(q));

        for (int v : radj[u])
        {
            if (a[v] % 2 != a[u] % 2)
                continue;
            if (d[v] > d[u] + 1)
            {
                q.erase({d[v], v});
                d[v] = d[u] + 1;
                q.emplace(d[v], v);
            }
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << (d[i] < inf ? d[i] : -1) << " \n"[i == n - 1];

    return 0;
}