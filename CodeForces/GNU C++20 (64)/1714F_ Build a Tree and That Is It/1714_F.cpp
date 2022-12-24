#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x, y, z;
    std::cin >> n >> x >> y >> z;

    int sum = x + y + z;
    if (sum % 2 == 1)
    {
        std::cout << "NO\n";
        return;
    }

    std::array<int, 4> a {sum / 2 - y, sum / 2 - z, sum / 2 - x, 0};
    
    int min_id = std::min_element(std::begin(a), std::end(a)) - std::begin(a);
    if (a[min_id] < 0 or a[1] + a[2] + a[0] >= n)
    {
        std::cout << "NO\n";
        return;
    }

    int root;
    if (a[min_id] == 0)
        root = min_id + 1;

    std::set<int> s {1, 2, 3};
    s.erase(root);

    // path from root to all elements of `s`, distance a[s_i - 1]
    std::vector<std::pair<int, int>> edges;

    int u = root;
    auto it = std::begin(s);
    int cur = 4 + (root == 4);

    for (int i = 0; i < 3 and it != std::end(s); i++)
    {
        if (a[i] == 0)
            continue;

        int v = *it;
        // u to v using cur
        for (int j = 0; j < a[i] - 1; j++)
        {
            edges.emplace_back(u, cur);
            u = cur;
            cur++;
        }

        edges.emplace_back(u, v);
        u = root;
        it = std::next(it);
    }

    while (cur <= n)
    {
        edges.emplace_back(root, cur);
        cur++;
    }

    std::cout << "YES\n";
    for (auto [u, v] : edges)
        std::cout << u << " " << v << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}