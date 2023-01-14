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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> leaf(n);
    std::vector<i64> score(n), sum(n);

    std::function<void(int)> dfs;
    dfs = [&](int u)
    {
        i64 max = 0, d = 0;
        sum[u] = a[u];

        for (int v : adj[u])
        {
            dfs(v);
            leaf[u] += leaf[v];
            sum[u] += sum[v];
            max = std::max<i64>(max, score[v]);
            // d += score[v];
        }

        if (adj[u].empty())
            score[u] = a[u], leaf[u] = 1;
        else
        {
            int sz = leaf[u];
            score[u] = std::max<i64>(max, (sum[u] + sz - 1) / sz);
            // int sz = std::ssize(adj[u]);
            // d = std::max(0LL, 1LL * sz * max - d);

            // if (a[u] <= d)
            //     score[u] = max;
            // else
            //     score[u] = max + (a[u] - d + sz - 1) / sz;
        }
    }; dfs(0);

    std::cout << score[0];
    
    return 0;
}