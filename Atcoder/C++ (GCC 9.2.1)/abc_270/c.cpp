#include <bits/stdc++.h>

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
    
    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    std::vector<int> ans, path;
    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        path.push_back(u);
        if (u == y)
            ans = path;
        for (int v : adj[u])
        {
            if (v != p)
                dfs(v, u);
        }
        path.pop_back();
    };
    --y, --x;
    dfs(x, -1);  

    for (int i : ans)  
        std::cout << i + 1 << " ";

    return 0;
}