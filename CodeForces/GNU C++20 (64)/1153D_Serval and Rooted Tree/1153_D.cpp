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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        std::cin >> p;
        adj[p - 1].emplace_back(i);
    }

    int k = 0;
    for (int i = 0; i < n; i++)
        k += adj[i].empty();

    int left = 1, right = k;
    int ans = 1;

    std::function<int(int)> dfs = [&](int u)
    {
        int sum = 0;
        int min = k;
        for (int v : adj[u])
        {
            int res = dfs(v);
            sum += res;
            min = std::min(min, res);
        }

        if (adj[u].empty())
            return 1;

        return (a[u] ? min : sum);
    };

    int need = dfs(0);
    std::cout << k - need + 1;

    return 0;
}