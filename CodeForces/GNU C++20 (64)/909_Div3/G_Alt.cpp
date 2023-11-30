#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> pinv(n);
    for (int i = 0; i < n; i++)
    {
        int p;
        std::cin >> p;
        p--;
        
        pinv[p] = i;
    }

    std::map<int, std::vector<std::array<int, 3>>> m;
    for (int i = 0; i < q; i++)
    {
        int l, r, x;
        std::cin >> l >> r >> x;
        l--, r--, x--;

        m[pinv[x]].push_back({l, r, i});
    }

    std::vector<std::set<int>> s(n);
    std::vector<bool> ans(q);
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        s[pinv[u]].emplace(pinv[u]);
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            self(self, v, u);
            if (std::size(s[pinv[u]]) < std::size(s[pinv[v]]))
                std::swap(s[pinv[u]], s[pinv[v]]);

            for (auto &x : s[pinv[v]])
                s[pinv[u]].emplace(x);
        }

        for (auto [l, r, id] : m[pinv[u]])
        {
            int x = pinv[u];
            auto it = s[x].lower_bound(l);
            if (it == std::end(s[x]) || *it > r)
                ans[id] = false;
            else
                ans[id] = true;
        }
        
    }; dfs(dfs, 0, 0);

    for (int i = 0; i < q; i++)
        std::cout << (ans[i] ? "YES\n" : "NO\n");
    std::cout << "\n";
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