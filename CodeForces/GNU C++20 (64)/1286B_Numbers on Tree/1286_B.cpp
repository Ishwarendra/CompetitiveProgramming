#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace __gnu_pbds;

template<typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C,
      rb_tree_tag, tree_order_statistics_node_update>;

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

    int root = -1;
    std::vector<int> adj[n], c(n);
    for (int i = 0; i < n; i++)
    {
        int p;
        std::cin >> p >> c[i];
        p--;
        if (p == -1)
            root = i;
        else
            adj[p].emplace_back(i);
    }

    std::vector<int> a(n), cnt(n, 1);
    std::function<void(int)> dfs = [&](int u)
    {
        for (int v : adj[u])
        {
            dfs(v);
            cnt[u] += cnt[v];
        }
    }; dfs(root);

    for (int i = 0; i < n; i++)
    {
        if (c[i] > cnt[i] - 1)
        {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::function<void(int, ordered_set<int> &)> get;
    get = [&](int u, ordered_set<int> &pbds)
    {
        pbds.insert(a[u]);
        for (int v : adj[u])
            get(v, pbds);
    };

    dfs = [&](int u)
    {
        for (int v : adj[u])
            dfs(v);

        if (adj[u].empty())
        {
            a[u] = *std::max_element(std::begin(a), std::end(a)) + 1;
            return;
        }

        ordered_set<int> pbds;
        get(u, pbds);
        pbds.erase(a[u]);

        print(pbds, u, cnt[u])
        assert(std::size(pbds) == cnt[u] - 1);
        auto it = pbds.find_by_order(c[u]);
        if (it == std::end(pbds))
            a[u] = *std::max_element(std::begin(a), std::end(a)) + 1;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] >= *it)
                    a[i]++;
            }

            a[u] = *it;
        }
    }; dfs(root);

    std::cout << "YES\n";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];

    return 0;
}