#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;
using l64 = long double;
using Point = std::array<l64, 2>;

l64 edist(auto x1, auto y1, auto x2, auto y2)
{
    auto sq = [&](auto x) { return 1.0L * x * x; };
    return std::sqrt(sq(x1 - x2) + sq(y1 - y2));
}

l64 edist(Point p1, Point p2)
{
    return edist(p1[0], p1[1], p2[0], p2[1]);
}

auto mdist(auto x1, auto y1, auto x2, auto y2)
{
    return 1.0L * std::abs(x1 - x2) + std::abs(y1 - y2);
}

auto mdist(Point p1, Point p2)
{
    return mdist(p1[0], p1[1], p2[0], p2[1]);
}

l64 get(Point one, Point two, Point three, Point four)
{
    return mdist(one, two) + edist(two, three) + mdist(three, four);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    int x1, y1, x2, y2;
    std::cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    
    auto onLineWithX = [&](int x) -> l64 
    { 
        return -(1.0L * a * x + c) / b; 
    };

    auto onLineWithY = [&](int y) -> l64 
    { 
        return -(1.0L * b * y + c) / a; 
    };

    l64 ans = mdist(x1, y1, x2, y2);
    Point st {1. * x1, 1. * y1}, en {1. * x2, 1. * y2};

    std::vector<Point> onL1, onL2;
    if (b != 0)
    {
        onL1.push_back({x1, onLineWithX(x1)});
        onL2.push_back({x2, onLineWithX(x2)});
    }

    if (a != 0)
    {
        onL1.push_back({onLineWithY(y1), y1});
        onL2.push_back({onLineWithY(y2), y2});
    }

    for (auto p1 : onL1)
    {
        for (auto p2 : onL2)
            ans = std::min(ans, get(st, p1, p2, en));
    }

    std::cout << std::fixed << std::setprecision(12) << ans;

    return 0;
}