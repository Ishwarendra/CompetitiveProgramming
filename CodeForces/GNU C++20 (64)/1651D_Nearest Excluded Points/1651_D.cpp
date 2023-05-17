#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::array<int, 2>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2>());
    std::set<std::array<int, 2>> in;

    std::map<std::array<int, 2>, std::array<int, 2>> ans;
    for (auto &[x, y] : a)
    {
        std::cin >> x >> y;
        in.insert({x, y});
    }

    auto mdist = [&](auto x, auto y)
    {
        return std::abs(x[0] - y[0]) + std::abs(x[1] - y[1]);
    };

    std::queue<std::array<int, 2>> q;
    for (int i = 0; i < n; i++)
    {
        for (auto [dx, dy] : dirs)
        {
            if (in.count({a[i][0] + dx, a[i][1] + dy}))
                continue;

            if (mdist(a[i], std::array {a[i][0] + dx, a[i][1] + dy}) == 1)
            {
                q.emplace(a[i]);
                ans[a[i]] = {a[i][0] + dx, a[i][1] + dy};
                break;
            }
        }
    }

    assert(!q.empty());

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs)
        {
            if (!ans.contains({x + dx, y + dy}))
            {
                if (in.count({x + dx, y + dy}))
                    q.push({x + dx, y + dy});
                ans[{x + dx, y + dy}] = ans[{x, y}];
            }
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[a[i]][0] << " " << ans[a[i]][1] << "\n";
}