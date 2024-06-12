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

/**
 * Ignore node-1 and connect all components.
 * Add edges from 1 to different components.
 * If you can add more then add arbitrarily 
 * but remove edges accordingly so you don't make cycles
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, d0;
    std::cin >> n >> m >> d0;
    
    std::vector<std::vector<int>> adj(n), g(n);
    std::vector<int> one;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        
        if (u == 0)
            one.emplace_back(v);
        else if (v == 0)
            one.emplace_back(u);
        else
        {
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    
    auto add = [&](int u, int v)
    {
        g[u].emplace_back(v);
        g[v].emplace_back(u);  
    };
    
    DSU dsu(n);
    std::vector<std::pair<int, int>> ans;
    int cc = n - 1;
    for (int i = 1; i < n; i++)
    {
        for (int v : adj[i])
        {
            if (dsu.unite(i, v))
            {
                add(i, v);
                cc--;
            }
        }
    }
    
    if (cc > d0 || std::size(one) < d0)
    {
        std::cout << "NO";
        return 0;
    }
    
    std::set<int> done;
    for (int v : one)
    {
        if (dsu.unite(0, v))
        {
            ans.emplace_back(1, v + 1), d0--;
            done.emplace(v);
        }
    }
    
    for (int v : one)
    {
        if (!done.count(v) and d0)
        {
            d0--;
            ans.emplace_back(1, v + 1);
        }
    }
    
    dsu = DSU(n);
    for (auto &[u, v] : ans)
        dsu.unite(u - 1, v - 1);
    
    for (int i = 1; i < n; i++)
    {
        for (int v : adj[i])
        {
            if (dsu.unite(i, v))
                ans.emplace_back(i + 1, v + 1);
        }
    }
    
    if (std::size(ans) == n - 1)
    {
        std::cout << "YES\n";
        for (auto [u, v] : ans)
            std::cout << u << " " << v << "\n";
    }
    else
        std::cout << "NO";
    
    return 0;
}