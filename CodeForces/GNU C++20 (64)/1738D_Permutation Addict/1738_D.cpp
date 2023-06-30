#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<int> prefMin(n), suffMax(n + 1);
    prefMin[0] = b[0];
    for (int i = 1; i < n; i++)
        prefMin[i] = std::min(prefMin[i - 1], b[i]);

    suffMax[n] = 0;
    suffMax[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffMax[i] = std::max(suffMax[i + 1], b[i]);

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (prefMin[i] > i + 1 and suffMax[i + 1] <= i + 1)
            k = i + 1;
    }

    std::cout << k << "\n";
    std::vector<std::vector<int>> adj(n + 2);

    for (int i = 0; i < n; i++)
        adj[b[i]].emplace_back(i + 1);

    std::vector<int> ans;
    for (int i = 0; i < n + 2; i++)
    {
        std::sort(std::begin(adj[i]), std::end(adj[i]), [&](int x, int y)
        {
            return std::size(adj[x]) < std::size(adj[y]);
        });
    }

    auto add = [&](int u)
    {
        for (int v : adj[u])
            ans.emplace_back(v);
    };

    add(0);
    add(n + 1);
    while (std::size(ans) < n)
        add(ans.back());

    assert(std::size(ans) == n);
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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