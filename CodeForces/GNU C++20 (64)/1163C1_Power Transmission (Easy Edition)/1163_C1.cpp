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

    std::vector a(n, std::array<int, 2>{});
    for (auto &[x, y] : a)
        std::cin >> x >> y;

    auto line = [&](int i, int j)
    {
        auto [x1, y1] = a[i];
        auto [x2, y2] = a[j];

        return std::array {y2 - y1, x1 - x2, y1 * x2 - y2 * x1};
    };  

    auto norm = [](std::array<int, 3> x)
    {
        auto [a, b, c] = x;
        int g = std::gcd(a, std::gcd(b, c));

        a /= g, b /= g, c /= g;
        if (c < 0)
            a = -a, b = -b, c = -c;

        return std::array {a, b, c};
    };

    std::vector<std::array<int, 3>> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            l.emplace_back(norm(line(i, j)));
    }

    std::sort(std::begin(l), std::end(l));
    l.erase(std::unique(std::begin(l), std::end(l)), std::end(l));

    auto intersect = [&](auto x, auto y)
    {
        auto [a1, b1, c1] = x;
        auto [a2, b2, c2] = y;

        return 1LL * a1 * b2 != 1LL * a2 * b1;
    };  

    int ans = 0;

    for (int i = 0; i < std::size(l); i++)
    {
        for (int j = i + 1; j < std::size(l); j++)
            ans += intersect(l[i], l[j]);
    }

    std::cout << ans;
    
    return 0;
}