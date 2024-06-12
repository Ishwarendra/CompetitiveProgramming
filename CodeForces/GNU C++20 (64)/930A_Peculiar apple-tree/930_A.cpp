#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
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

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        std::cin >> p;
        p--;

        adj[p].emplace_back(i);
    }

    std::queue<int> q;
    q.emplace(0);

    int ans = 0;

    while (!q.empty())
    {
        int sz = std::size(q);
        for (int i = 0; i < sz; i++)
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
                q.emplace(v);
        }

        ans += sz % 2;
    }

    std::cout << ans;

    return 0;
}