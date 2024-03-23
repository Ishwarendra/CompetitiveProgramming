#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct DSU
{
    std::vector<int> rnk, par;
    std::vector<std::pair<int, int>> max;
    DSU() {}
    DSU(int n) : rnk(n, 1), par(n), max(n, {0, 0}) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    void simpleUnite(int x, int p, int maxh = 0, int smaxh = 0)
    {
        par[x] = p;
        max[p] = std::pair {maxh, smaxh};
        rnk[p] = maxh;
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
                
            par[p2] = p1;
            rnk[p1] += rnk[p1] == rnk[p2];

            std::array<int, 4> cand{};
            cand[0] = max[p1].first, cand[1] = max[p1].second;
            cand[2] = max[p2].first + 1, cand[3] = max[p2].second;
            cand[3] += cand[3] > 0;
            std::sort(std::begin(cand), std::end(cand), std::greater<int>());

            max[p1] = {cand[0], cand[1]};

            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int longestPath(int x)
    {
        int p = get(x);
        return max[p].first + max[p].second;
    }
}; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, q;
    std::cin >> n >> m >> q;

    DSU dsu(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> vis(n);
    auto dfs = [&](auto &&self, int u, int p) -> std::pair<int, int>
    {
        vis[u] = 1;
        int maxh = 0, smaxh = 0;
        for (int v : adj[u])
        {
            if (vis[v])
                continue;

            auto [max, smax] = self(self, v, p);
            if (max >= maxh)
                smaxh = maxh, maxh = max;
            else if (max > smaxh)
                smaxh = max;

            if (smax >= maxh)
                smaxh = maxh, maxh = smax;
            else if (smax > smaxh)
                smaxh = smax;
        }

        if (u != p)
        {
            dsu.simpleUnite(u, p, maxh, smaxh);
            maxh++, smaxh += !!smaxh;
        }
        return std::pair {maxh, smaxh};
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(dfs, i, i);
    }

    print(dsu.max)

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int u;
            std::cin >> u;
            u--;
            std::cout << dsu.longestPath(u) << "\n";
        }
        else
        {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            dsu.unite(u, v);
        }
    }
    
    return 0;
}