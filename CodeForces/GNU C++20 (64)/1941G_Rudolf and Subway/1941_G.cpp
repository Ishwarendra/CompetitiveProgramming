#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> edges(m);
    std::map<int, int> id;
    for (auto &[u, v, c] : edges)
    {
        std::cin >> u >> v >> c;
        u--, v--;
        id[c] = 0;
    }

    int index = 0;
    for (auto &[num, f] : id)
        f = index++;

    int sz = std::size(id);
    std::vector<std::vector<int>> adj(n + sz);

    for (auto &[u, v, c] : edges)
    {
        int col = id[c];
        adj[u].emplace_back(n + col);
        adj[n + col].emplace_back(u);
        adj[n + col].emplace_back(v);
        adj[v].emplace_back(n + col);
    }

    int st, en;
    std::cin >> st >> en;
    st--, en--;

    std::vector<int> d(n + sz, inf);
    d[st] = 0;

    std::queue<int> q;
    q.emplace(st);

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (d[v] != inf)
                continue;

            d[v] = d[u] + 1;
            q.emplace(v);
        }
    }
    
    std::cout << d[en] / 2 << '\n';
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