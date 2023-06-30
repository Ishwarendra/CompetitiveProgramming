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

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int p;
        std::cin >> p;
        adj[p - 1].emplace_back(i + 1);
    }

    std::vector<int> cnt(n), leaf(n, 1);
    std::function<void(int)> dfs = [&](int u)
    {
        leaf[u] = std::size(adj[u]) == 0;

        for (int v : adj[u])
        {
            dfs(v);
            cnt[u] += leaf[v];
        }
    }; dfs(0);

    for (int i = 0; i < n; i++)
    {
        if (!leaf[i] and cnt[i] < 3)
        {
            std::cout << "No";
            return 0;
        }
    }

    std::cout << "Yes";

    return 0;
}