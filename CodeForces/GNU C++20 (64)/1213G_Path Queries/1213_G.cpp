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
    i64 ans = 0;

    i64 f(int x) { return 1LL * x * (x - 1) / 2; }
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
            
            ans -= f(rnk[p1]);
            ans -= f(rnk[p2]);
            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;                
            ans += f(rnk[p1]);

            return true;
        }
    }
    bool same(int x, int y) { return get(x) == get(y); }
    int size(int x) { return rnk[get(x)]; }
    i64 get() { return ans; }
}; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    DSU dsu(n);
    std::vector<std::array<int, 3>> edges(n - 1);
    for (auto &[w, u, v] : edges)
    {
        std::cin >> u >> v >> w;
        u--, v--;
    }

    std::vector<std::pair<int, int>> q(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> q[i].first;
        q[i].second = i;
    }

    std::sort(std::begin(edges), std::end(edges));
    std::sort(std::begin(q), std::end(q));
    int pos = 0;
    std::vector<i64> ans(m);

    for (auto &[max, id] : q)
    {
        while (pos < std::size(edges) and edges[pos][0] <= max)
        {
            auto [w, u, v] = edges[pos];
            dsu.unite(u, v);
            pos++;
        }

        ans[id] = dsu.get();
    }

    for (int i = 0; i < m; i++)
        std::cout << ans[i] << " \n"[i == m - 1];

    return 0;
}