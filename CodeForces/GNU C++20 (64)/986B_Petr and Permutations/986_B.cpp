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

    std::vector<int> need(n);
    for (int i = 0; i < n; i++)
        std::cin >> need[i];

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        adj[i].emplace_back(need[i] - 1);

    std::vector<int> vis(n);
    std::function<void(int)> dfs = [&](int u)
    {   
        vis[u] = 1;
        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v);
        }
    };

    int par = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            par ^= 1;
        }
    }

    std::cout << (par ? "Um_nik" : "Petr");

    return 0;
}