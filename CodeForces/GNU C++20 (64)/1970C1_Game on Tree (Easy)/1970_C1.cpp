#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    std::cin >> n >> t;

    std::vector adj(n, std::vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int root;
    std::cin >> root;
    root--;

    std::vector<int> win(n, -1);
    auto dfs = [&](auto && self, int u, int p) -> int
    {
        if (win[u] != -1)
            return win[u];
        
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            
            if (!self(self, v, u))
                return win[u] = 1;
        }

        return win[u] = 0;
    };

    std::cout << (dfs(dfs, root, root) ? "Ron" : "Hermione");

    return 0;
}