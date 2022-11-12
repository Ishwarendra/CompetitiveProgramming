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

    std::vector<int> p(n), adj[n];
    for (int i = 1; i < n; i++)
    {
        std::cin >> p[i];
        adj[--p[i]].emplace_back(i);
    }

    std::vector<int> dp(n);
    std::function<void(int)> depth = [&](int u)
    {
        for (int v : adj[u])
        {
            depth(v);
            dp[u] = std::max(dp[u], dp[v]);
        }

        dp[u]++;
    }; depth(0);

    std::function<int(int)> dfs = [&](int u)
    {
        int sum = 0;
        for (int v : adj[u])
            sum += dfs(v);

        return dp[u] = std::max(dp[u], sum);
    }; dfs(0);

    print(dp)
    std::cout << dp[0];

    return 0;
}