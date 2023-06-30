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
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }

    int root = -1;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
            root = i;
    }

    std::multiset<int> m;
    std::function<void(int, int, int)> dfs;
    dfs = [&](int u, int p, int special)
    {
        if (special == 2)
            m.emplace(deg[u]);

        for (int v : adj[u])
        {
            if (v != p and deg[v] > 1)
                dfs(v, u, (special + 1) % 3);
        }
    }; dfs(root, root, 1);

    for (auto x : m)
        std::cout << x << " ";
    
    return 0;
}