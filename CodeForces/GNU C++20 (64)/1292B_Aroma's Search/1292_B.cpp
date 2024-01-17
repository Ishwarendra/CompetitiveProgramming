#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;

const i64 LIMIT = 1e17;

i64 d(std::array<i64, 2> a, std::array<i64, 2> b)
{
    return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<i64, 2> st, a, b;
    std::cin >> st[0] >> st[1] >> a[0] >> a[1] >> b[0] >> b[1];

    i64 xs, ys, t;
    std::cin >> xs >> ys >> t;

    std::vector<std::array<i64, 2>> points;
    points.emplace_back(st);
    while (true)
    {
        if (i128(a[0]) * points.back()[0] + b[0] > LIMIT)
            break;
        if (i128(a[1]) * points.back()[1] + b[1] > LIMIT)
            break;

        i64 x = a[0] * points.back()[0] + b[0];
        i64 y = a[1] * points.back()[1] + b[1];
        points.push_back({x, y});
    }

    auto get = [&](int id)
    {
        if (id < 0 or id >= std::size(points))
            return 0;

        int n = std::size(points);

        i64 need = d(std::array {xs, ys}, points[id]);
        int ans = need <= t;

        for (int i = id + 1; i >= 0; i--)
        {
            i64 base = d(std::array {xs, ys}, points[id]) + d(points[id], points[i]);
            need = base;
            if (need > t)
                continue;

            ans = std::max(ans, id - i + 1);
            for (int j = id + 1; j < n; j++)
            {
                need += d(points[id], points[j]) * 2;
                if (need <= t)
                    ans = std::max(ans, j - i + 1);
            }
        }

        for (int j = id + 1; j < n; j++)
        {
            i64 base = d(std::array {xs, ys}, points[id]) + d(points[id], points[j]);
            need = base;
            if (need > t)
                continue;

            ans = std::max(ans, j - id);
            for (int i = id + 1; i >= 0; i--)
            {
                need = base + d(points[id], points[i]) * 2;
                if (need <= t)
                    ans = std::max(ans, j - i + 1);
            }
        }

        return ans;
    };
    
    int ans = 0;
    for (int i = 0; i < std::size(points); i++)
        ans = std::max(ans, get(i));

    std::cout << ans;

    return 0;
}