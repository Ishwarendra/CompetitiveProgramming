#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector adj(n, std::vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a - 1].emplace_back(b - 1);
    }

    auto dist = [&](int x, int y) { return (y - x + n) % n; };

    for (int i = 0; i < n; i++)
    {
        std::sort(std::begin(adj[i]), std::end(adj[i]), [&](int x, int y)
        {
            return dist(i, x) < dist(i, y);
        });
    }

    auto get = [&](int st)
    {
        auto backup = adj;
        std::map<int, int> s;
        int i = st, rem = m;
        int ans = 0;

        while (rem)
        {
            if (s.contains(i))
            {
                rem -= s[i];
                s.erase(i);
            }

            if (!adj[i].empty())
            {
                s[adj[i].back()]++;
                adj[i].pop_back();
            }

            i = (i + 1) % n;
            ans += rem > 0;
        }

        adj = backup;
        return ans;
    };

    for (int i = 0; i < n; i++)
        std::cout << get(i) << " \n"[i == n - 1];

    return 0;
}