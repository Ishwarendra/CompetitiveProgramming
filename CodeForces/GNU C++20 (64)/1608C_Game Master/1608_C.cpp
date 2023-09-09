#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector val(n, std::array<int, 2>());
    int cur = 0;

    auto read = [&](auto &a)
    {
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i][0];
            a[i][1] = i;
            val[i][cur] = a[i][0];
        }

        std::sort(std::begin(a), std::end(a));
        cur++;
    };

    std::vector<std::array<int, 2>> a(n), b(n);
    read(a);
    read(b);

    int can = 1;
    std::string ans(n, '0');
    ans[a.back()[1]] = '1';

    std::array<int, 2> min{inf, inf};

    while (can)
    {
        can = 0;
        while (!a.empty() and ans[a.back()[1]] == '1')
        {
            min[0] = std::min(min[0], val[a.back()[1]][0]);
            min[1] = std::min(min[1], val[a.back()[1]][1]);
            a.pop_back();
        }

        while (!b.empty() and ans[b.back()[1]] == '1')
        {
            min[0] = std::min(min[0], val[b.back()[1]][0]);
            min[1] = std::min(min[1], val[b.back()[1]][1]);
            b.pop_back();
        }

        if (!a.empty() and a.back()[0] > min[0])
            ans[a.back()[1]] = '1', can = 1;
        if (!b.empty() and b.back()[0] > min[1])
            ans[b.back()[1]] = '1', can = 1;
    }

    std::cout << ans << "\n";
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