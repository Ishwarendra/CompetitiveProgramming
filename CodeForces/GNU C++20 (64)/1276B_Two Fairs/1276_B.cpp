#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    x--, y--;

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> vis(n);
    std::function<void(int, int)> dfs = [&](int u, int skip) -> void
    {
        vis[u] = 1;
        for (int v : adj[u])
        {
            if (v == skip)
                continue;

            if (!vis[v])
                dfs(v, skip);
        }
    };

    dfs(x, y);
    auto visa = vis;
    std::fill(std::begin(vis), std::end(vis), 0);
    dfs(y, x);
    auto visb = vis;

    std::array<int, 3> cnt{};
    for (int i = 0; i < n; i++)
    {
        if (i == x || i == y)
            continue;

        if (visa[i] == 0 and visb[i])
            cnt[1]++;
        else if (visb[i] == 0 and visa[i])
            cnt[0]++;
        else
            cnt[2]++;
    }   

    i64 ans = 1LL * cnt[0] * cnt[1];
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}