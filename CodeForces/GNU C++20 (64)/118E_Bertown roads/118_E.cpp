#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> tin(n), low(n, inf);
    int time = 0;
    std::vector<std::pair<int, int>> ans;
    std::map<std::pair<int, int>, bool> check;

    auto add = [&](int u, int v)
    {
        if (check.contains({u, v}))
            return;
        ans.emplace_back(u, v);
        check[{u, v}] = check[{v, u}] = true;
    };

    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        tin[u] = low[u] = ++time;

        for (int v : adj[u])
        {
            if (!tin[v])
            {
                self(self, v, u);
                low[u] = std::min(low[u], low[v]);

                if (low[v] > tin[u])
                {
                    std::cout << 0;
                    std::exit(0);
                }
                
                add(u, v);
            }
            else if (v != p)
            {
                low[u] = std::min(low[u], tin[v]);
                add(u, v);
            }
        }
    }; dfs(dfs, 0, 0);

    for (auto &[u, v] : ans)
        std::cout << u + 1 << " " << v + 1 << "\n";

    return 0;
}