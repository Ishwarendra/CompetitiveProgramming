#include "bits/stdc++.h"

#undef LOCAL

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 3e5 + 10;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n), pos(N);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]] = i + 1;
    }

    int s, t;
    std::cin >> s >> t;
    s--, t--;

    if (a[s] == a[t])
    {
        if (a[s] == 1 and s != t)
            std::cout << "-1\n";
        else if (s == t)
            std::cout << "1\n" << s + 1 << "\n";
        else
            std::cout << "2\n" << s + 1 << " " << t + 1 << "\n";

        std::exit(0);
    }

    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> adj;
    for (int i = 0; i < n; i++)
    {
        std::pair<int, int> u { a[i], 0 };
        int x = a[i];
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                std::pair<int, int> v { j, 1 };
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }

            while (x % j == 0)
                x /= j;
        }

        if (x > 1)
        {
            adj[{x, 1}].push_back({a[i], 0});
            adj[{a[i], 0}].push_back({x, 1});
        }
    }

    std::map<std::pair<int, int>, int> d;
    std::queue<std::pair<int, int>> q;
    q.emplace(a[s], 0);
    d[q.front()] = 0;

    std::map<std::pair<int, int>, std::pair<int, int>> par;

    while (!q.empty())
    {
        auto u = q.front();
        auto [val, t1] = u;
        q.pop();

        for (auto v : adj[u])
        {
            if (d.contains(v) or v.second == t1)
                continue;

            auto [val_c, t2] = v;
            d[v] = d[u] + 1;
            par[v] = u;
            q.emplace(v);
        }
    }
    print(d)
    if (!d.contains({a[t], 0}))
    {
        std::cout << "-1\n";
        std:exit(0);
    }

    std::vector<int> path { t + 1 } ;
    std::pair<int, int> node = {a[t], 0};
    node = par[node];
    
    while (node != std::pair{a[s], 0})
    {
        if (node.second == 0)
            path.emplace_back(pos[node.first]);

        node = par[node];
    }

    path.emplace_back(s + 1);
    std::reverse(std::begin(path), std::end(path));

    std::cout << std::size(path) << "\n";

    for (auto x : path)
        std::cout << x << " ";
    
    return 0;
}