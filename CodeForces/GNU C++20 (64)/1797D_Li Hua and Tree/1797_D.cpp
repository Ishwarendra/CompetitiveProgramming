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
    
    int n, q;
    std::cin >> n >> q;

    std::vector<std::set<int>> adj(n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace(v);
        adj[v].emplace(u);
    }

    std::vector<i64> sum(std::begin(a), std::end(a));
    std::vector<int> cnt(n, 1), par(n, -1);
    std::vector<std::multiset<std::pair<int, int>>> heavy(n);

    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        par[u] = p;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            sum[u] += sum[v];
            cnt[u] += cnt[v];
            heavy[u].emplace(-cnt[v], v);
        }
    }; dfs(0, 0);

    auto erase = [&](auto &m, auto x)
    {
        assert(m.find(x) != std::end(m));
        m.erase(m.find(x));
    };

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int x;
            std::cin >> x;

            std::cout << sum[x - 1] << "\n";
        }
        else
        {
            int x;
            std::cin >> x;
            x--;

            int f = par[x];
            if (heavy[x].empty() or heavy[f].empty())
                continue;

            int s = std::begin(heavy[x])->second;

            erase(heavy[x], std::pair{-cnt[s], s});
            erase(heavy[f], std::pair{-cnt[x], x});

            sum[x] -= sum[s];
            sum[s] += sum[x];

            cnt[x] -= cnt[s];
            cnt[s] += cnt[x];

            par[x] = s;
            par[s] = f;

            heavy[s].emplace(-cnt[x], x);
            heavy[f].emplace(-cnt[s], s);
        }
    }
    
    return 0;
}