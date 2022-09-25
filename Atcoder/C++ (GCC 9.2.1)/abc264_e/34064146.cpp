#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick
{
    const int n;
    std::vector<T> a;

    Fenwick(int n) : n(n), a(n) {}
    template<typename G>
    Fenwick(const std::vector<G> in) : Fenwick((int)std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }
    void add(int x, T v)
    {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x)
    {
        T ans = 0;
        x++;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r)
    {
        if (l - 1 < 0)
            return sum(r);

        return sum(r) - sum(l - 1);
    }
};

class DSU
{
    std::vector<int> rnk, par;
public:
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

    int n, m, e;
    std::cin >> n >> m >> e;

    std::vector<std::set<int>> adj(n + m);
    std::vector<std::array<int, 2>> edge(e);

    for (int i = 0; i < e; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        u--, v--;

        adj[u].emplace(v);
        adj[v].emplace(u);
        edge[i] = {u, v};
    }

    int q;
    std::cin >> q;

    std::vector<int> x(q);
    for (int i = 0; i < q; ++i)
    {
        std::cin >> x[i];
        x[i]--;

        auto [u, v] = edge[x[i]];

        adj[u].erase(v);
        adj[v].erase(u);
    }

    DSU dsu(n + m);
    Fenwick<int> ft(n + m);

    std::queue<int> queue;

    for (int i = n; i < n + m; i++)
    {
        queue.emplace(i);
        ft.add(i, 1);
    }

    while (!queue.empty())
    {
        auto cur = queue.front();
        queue.pop();

        for (int v : adj[cur])
        {
            if (ft.rangeSum(v, v))
                continue;
            queue.emplace(v);
            ft.add(v, 1);
        }
    }

    std::vector<int> ans(q);
    ans[q - 1] = ft.rangeSum(0, n - 1);

    for (int i = 0; i < n + m; ++i)
    {
        for (int v : adj[i])
            dsu.unite(i, v);
    }

    for (int i = q - 2; i >= 0; i--)
    {
        ans[i] = ans[i + 1];
        auto [u, v] = edge[x[i + 1]];
        u = dsu.get(u);
        v = dsu.get(v);

        print(u, v, ft.rangeSum(v, v), ft.rangeSum(u, u))
        if (ft.rangeSum(u, u) != ft.rangeSum(v, v))
        {
            if (ft.rangeSum(u, u))
            {
                ft.add(v, 1);
                ans[i] += dsu.size(v);
            }
            else
            {
                ft.add(u, 1);
                ans[i] += dsu.size(u);
            }
        }

        dsu.unite(u, v);
    }

    for (int i = 0; i < q; i++)
        std::cout << ans[i] << "\n";

    return 0;
}