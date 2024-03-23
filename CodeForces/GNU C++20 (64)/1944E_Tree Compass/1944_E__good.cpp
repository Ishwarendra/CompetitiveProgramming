#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> par(n, -1);
    auto bfs = [&](int src)
    {
        std::fill(std::begin(par), std::end(par), -1);
        std::vector d(n, inf);
        std::queue<int> q;
        q.emplace(src);
        d[src] = 0;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (d[v] != inf)
                    continue;

                par[v] = u;
                d[v] = d[u] + 1;
                q.emplace(v);
            }
        }

        return d;
    };

    auto ds = bfs(0);
    int t = std::max_element(std::begin(ds), std::end(ds)) - std::begin(ds);
    auto dt = bfs(t);

    int dia = *std::max_element(std::begin(dt), std::end(dt));
    t = std::max_element(std::begin(dt), std::end(dt)) - std::begin(dt);

    std::vector<int> nodes;
    while (t != -1)
    {
        nodes.emplace_back(t);
        t = par[t];
    }

    std::vector<int> col(n);
    if ((dia + 1) % 4 == 0)
    {
        std::cout << (dia + 1) / 2 << "\n";
        int sz = std::size(nodes);
        int distance = 0;
        for (int i = 0; i < (dia + 1) / 2; i++)
        {
            int mid = nodes[sz / 2];
            if (i % 2)
                mid = nodes[sz / 2 - 1];
            else
            {
                if (i == 0)
                    distance++;
                else
                    distance += 2;
            }

            std::cout << mid + 1 << " " << distance << "\n";
            auto dist = bfs(mid);
            for (int i = 0; i < n; i++)
            {
                if (dist[i] == distance)
                    col[i] = 1;
            }
        }

        // assert(std::count(std::begin(col), std::end(col), 0) == 0);
        return;
    }

    std::cout << (dia + 3) / 2 << "\n";
    for (int i = 0; i < (dia + 3) / 2; i++)
        std::cout << nodes[std::size(nodes) / 2] + 1 << " " << i << "\n";
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