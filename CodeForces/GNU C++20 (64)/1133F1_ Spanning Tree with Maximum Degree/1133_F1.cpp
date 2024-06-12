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
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> deg(n);
    std::vector<std::vector<int>> adj(n);
    
    DSU dsu(n);
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        
        deg[u]++, deg[v]++;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (deg[max] < deg[i])
            max = i;
    }
    
    std::vector<std::pair<int, int>> ans;    
    for (int v : adj[max])
    {
        ans.emplace_back(max + 1, v + 1);
        dsu.unite(max, v);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (dsu.same(max, i))
            continue;
        
        for (auto v : adj[i])
        {
            if (!dsu.same(v, i))    
            {
                dsu.unite(v, i);
                ans.emplace_back(i + 1, v + 1);
            }
        }
    }
    
    for (auto &[v, u] : ans)
        std::cout << v << " " << u << "\n";
    
    return 0;
}