#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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
    
    int n, a, b;
    std::cin >> n >> a >> b;

    std::map<int, int> id;
    std::vector<int> p(n), options(n), can(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        id[p[i]] = i;
    }

    DSU dsu(n);

    for (int i = 0; auto x : p)
    {
        can[i] = 3;
        if (id.contains(a - x))
        {
            options[i] |= 2;
            dsu.unite(i, id[a - x]);
        }

        if (id.contains(b - x))
        {
            options[i] |= 1;
            dsu.unite(i, id[b - x]);
        }
        i++;
    }

    std::vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        can[dsu.get(id[p[i]])] &= options[i];    
        if (can[dsu.get(id[p[i]])] == 0)
        {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; i++)
        std::cout << (can[dsu.get(i)] % 2) << " \n"[i == n - 1];
    
    return 0;
}