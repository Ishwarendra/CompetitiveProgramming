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
    
    int n, m;
    std::cin >> n >> m;

    DSU dsu(2 * n);
    int cc = 2 * n;
    for (int i = 0; i < n; i++)
        cc -= dsu.unite(i, i + n);

    int failed = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        char a, b;
        std::cin >> u >> a >> v >> b;
        u--, v--;

        if (a == 'R') u += n;
        else v += n;

        if (dsu.unite(u, v))
            cc--;
        else
            failed++;
    }

    std::cout << failed << " " << cc - failed;
    
    return 0;
}