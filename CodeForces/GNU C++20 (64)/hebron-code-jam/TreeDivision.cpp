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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    if (n % k)
    {
        std::cout << "No\n";
        std::exit(0);
    }

    int can = 1;
    std::function<int(int, int)> dfs = [&](int u, int p)
    {
        int cnt = 1;

        for (int v : adj[u])
        {
            if (v == p)
                continue;
            cnt += dfs(v, u);
        }

        if (cnt > n / k)
        {
            can = 0;
            cnt = 0;
        }
        else if (cnt == n / k)
            cnt = 0; 

        return cnt;
    };
    dfs(0, 0);

    std::cout << (can ? "Yes\n" : "No\n");
    
    return 0;
}