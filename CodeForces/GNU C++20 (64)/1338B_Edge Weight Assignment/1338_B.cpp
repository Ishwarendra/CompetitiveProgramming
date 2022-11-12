#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> adj[n], deg(n);
    int root = -1;
    for (int i = 0; i < n - 1; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
            root = i;
    }

    std::vector<int> dep(n, -1), par(n, -1);
    std::function<void(int, int)> get_depth = [&](int u, int p)
    {
        par[u] = p;
        dep[u] = dep[p] + 1;
        for (int v : adj[u])
        {
            if (v != p)
                get_depth(v, u);
        }
    }; get_depth(root, root);

    int max_root = std::max_element(std::begin(dep), std::end(dep)) - std::begin(dep);
    int min_root = std::min_element(std::begin(dep), std::end(dep)) - std::begin(dep);

    std::fill(std::begin(dep), std::end(dep), -1);
    std::fill(std::begin(par), std::end(par), -1);
    get_depth(max_root, max_root);
    int max = n - 1;
    std::set<int> parents;

    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
        {
            parents.emplace(adj[i][0]);
            max--;
        }
    }
    
    max += std::ssize(parents);

    int min = 1;

    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1 and dep[i] % 2)
            min = 3;
    }
    std::cout << min << " " << max << "\n";
    
    return 0;
}