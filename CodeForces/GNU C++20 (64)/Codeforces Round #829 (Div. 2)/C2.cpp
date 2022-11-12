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

    std::vector<int> a(n);
    std::vector<std::pair<int, int>> pos;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] != 0)
            pos.emplace_back(a[i], i);
    }

    if (std::ssize(pos) % 2)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<std::pair<int, int>> ans;

    // 0 0 0 1
    // (0 0) (0 -1)
    // (0 0 0) (1)
    // (1 0 0 0 ... 1) can be treated as (1 0 0 ...) (0 -1) sum = 0
    // (1 0 0 0 ... -1) can be treated as (1 0 0 0 ... 0) (-1) sum = 0
    // (-1 0 0 0 ... -1) = (-1 0 0 0 ... ) (0 1)
    // (-1 0 0 0 ... 1) = (-1 0 0 0 ... 0) (1)

    for (int i = 0; i < std::ssize(pos) - 1; i += 2)
    {
        if (pos[i + 1].second == pos[i].second + 1)
        {
            if (a[pos[i + 1].second] == a[pos[i].second])
                ans.emplace_back(pos[i].second, pos[i + 1].second);
            else
            {
                ans.emplace_back(pos[i].second, pos[i].second);
                ans.emplace_back(pos[i + 1].second, pos[i + 1].second);
            }
        }

        else
        {
            int zeroes = pos[i + 1].second - pos[i].second - 1;
            if (pos[i].first == pos[i + 1].first)
            {
                ans.emplace_back(pos[i].second, pos[i + 1].second - 2);
                ans.emplace_back(pos[i + 1].second - 1, pos[i + 1].second);
            }
            else
            {
                ans.emplace_back(pos[i].second, pos[i + 1].second - 1);
                ans.emplace_back(pos[i + 1].second, pos[i + 1].second);
            }
        }
    }

    for (int i = 2; i < std::size(pos); i += 2)
    {
        for (int j = pos[i].second - 1; j > pos[i - 1].second; j--)
            ans.emplace_back(j, j);
    }
    if (pos.empty())
        ans.emplace_back(0, n - 1);
    else
    {
        if (pos.back().second != n - 1)
            ans.emplace_back(pos.back().second + 1, n - 1);
    // FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF //
        if (pos.front().second != 0)
            ans.emplace_back(0, pos.front().second - 1);
    }

    std::sort(std::begin(ans), std::end(ans));
    std::cout << std::size(ans) << "\n";
    for (int i = 0; i < std::ssize(ans); i++)
        std::cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";

    assert(std::size(ans) == std::size(std::set(std::begin(ans), std::end(ans))));
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