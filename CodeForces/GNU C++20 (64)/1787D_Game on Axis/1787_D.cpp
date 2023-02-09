#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)  
    {
        int a;
        std::cin >> a;

        if (0 <= i + a and i + a < n and a != 0)
            adj[i + a].emplace_back(i);
        else
            adj[n].emplace_back(i);
    }

    std::vector<int> can(n + 1), par(n);

    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        par[u] = p;
        can[u] = 1; 
        for (int v : adj[u])
            dfs(v, u);
    }; dfs(n, n);

    int total = std::accumulate(std::begin(can), std::end(can), 0);

    if (can[0])
    {
        // std::vector<int> down(n, -1);
        // int par = 0, u = 0;
        // while (u != n)
        // {
        //     for (auto v : adj[u])
        //     {
        //         if (v == par)
        //             continue;

        //         print(par, u, v)
        //         par = u;
        //         u = v;
        //         down[u] = down[par] + 1;
        //     }
        // }

        // print(down)
    }
    else
    {

    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}