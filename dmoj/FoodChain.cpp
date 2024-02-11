#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par, child, ances;
public:
    DSU() {}
    DSU(int n)
    {
        rnk.assign(3 * n, 1);
        par.resize(3 * n);
        std::iota(par.begin(), par.end(), 0);
        child.resize(n);
        ances.resize(n);

        for (int i = 0; i < n; i++)
        {
            child[i] = (i + n);
            ances[i] = (i + 2 * n);
        }
    }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    void unite(int p1, int p2)
    {
        if (p1 == p2)
            return;

        if (rnk[p2] > rnk[p1])
            std::swap(p1, p2);

        rnk[p1] += rnk[p2], par[p2] = p1;
    }
    bool mergeEat(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        
        int chx_p = get(child[x]);
        int chy_p = get(child[y]);
        int anx_p = get(ances[x]);
        int any_p = get(ances[y]);

        if (chy_p == p1)
            return false;
        if (chy_p == chx_p)
            return false;
        if (chx_p == any_p)
            return false;
        if (anx_p == p2)
            return false;
        if (anx_p == p1)
            return false;

        unite(anx_p, chy_p);
        unite(any_p, p1);
        unite(chx_p, p2);
        return true;
    }
    bool mergeSame(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return true;

        int chx_p = get(child[x]);
        int chy_p = get(child[y]);
        int anx_p = get(ances[x]);
        int any_p = get(ances[y]);

        if (chx_p == p2)
            return false;
        if (chy_p == p1)
            return false;
        if (anx_p == p2)
            return false;
        if (any_p == p1)
            return false;

        unite(p1, p2);
        unite(chx_p, chy_p);
        unite(anx_p, any_p);
        return true;
    }
    bool same(int x, int y) { return get(x) == get(y); }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    int ans = 0;
    DSU dsu(n);
    while (q--)
    {
        int t, x, y;
        std::cin >> t >> x >> y;
        x--, y--;

        if (x >= n or y >= n)
            ans++;
        else if (t == 1)
            ans += !dsu.mergeSame(x, y);
        else
            ans += !dsu.mergeEat(x, y);
    }

    std::cout << ans;

    return 0;
}