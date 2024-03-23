#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> indeg(n), a(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
        adj[i].emplace_back(a[i]);
        indeg[a[i]]++;
    }

    std::vector<int> num(n, -1);
    std::set<int> s;

    int ok = 1;
    auto dfs = [&](auto &&self, int u, int x) -> void
    {
        s.emplace(u);
        num[u] = x;
        for (auto v : adj[u])
        {
            if (num[v] == -1)
                self(self, v, x + 1);
            else if (s.count(v))
            {
                int len = std::abs(num[v] - x) + 1;
                ok &= len == k;
            }
        }
        s.erase(u);
    };

    std::vector<int> ord(n);
    std::iota(std::begin(ord), std::end(ord), 0);
    if (k == 1)
    {
        std::cout << (a == ord ? "YES\n" : "NO\n");
        return;
    }

    for (int i : ord)
    {
        if (num[i] == -1)
            dfs(dfs, i, 0);
    }

    std::cout << (ok ? "YES\n" : "NO\n");
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