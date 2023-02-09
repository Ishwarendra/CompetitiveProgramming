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
    
    int n, m, k, s;
    std::cin >> n >> m >> k >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    std::vector<i64> ans(n);
    std::vector vis(n, std::vector(k, 0));
    std::vector cnt(n, 0);

    std::queue<std::array<int, 3>> q;
    for (int i = 0; i < n; i++)
        q.push({i, a[i], 0});

    while (!q.empty())
    {
        auto [u, type, c] = q.front();
        q.pop();

        if (cnt[u] >= s or vis[u][type])
            continue;

        ans[u] += c;
        cnt[u]++;
        vis[u][type] = 1;

        for (auto v : adj[u])
            q.push({v, type, c + 1});
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
    
    return 0;
}