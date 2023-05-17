#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU() {}
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);
                
            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;                
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
}; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector points(n, std::array<int, 2>());
    for (auto &[x, y] : points)
        std::cin >> x >> y;

    std::vector<int> c(n + 1), k(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];
    for (int i = 1; i <= n; i++)
        std::cin >> k[i];

    auto dist = [&](int i, int j) -> i64
    {
        if (i == 0 || j == 0)
            return c[std::max(i, j)];

        auto [x1, y1] = points[i - 1];
        auto [x2, y2] = points[j - 1];
        int d = std::abs(x1 - x2) + std::abs(y1 - y2);

        return 1LL * d * (k[i] + k[j]);
    };  

    std::vector<std::tuple<i64, int, int>> edges;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            edges.emplace_back(dist(i, j), i, j);
    }

    int root = std::min_element(std::begin(c) + 1, std::end(c)) - std::begin(c);
    std::sort(std::begin(edges), std::end(edges));

    DSU dsu(n + 1);
    dsu.unite(root, 0);
    i64 cost = c[root];

    std::vector<std::pair<int, int>> wire;
    std::vector<int> power_station(1, root);
    for (auto &[w, u, v] : edges)
    {
        if (dsu.same(u, v))
            continue;

        dsu.unite(u, v);
        if (u == 0)
            power_station.emplace_back(v);
        else
            wire.emplace_back(u, v);

        cost += w;
    }

    std::cout << cost << "\n";

    std::cout << std::size(power_station) << "\n";
    for (auto x : power_station)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << std::size(wire) << "\n";
    for (auto [u, v] : wire)
        std::cout << u << " " << v << "\n";

    return 0;
}