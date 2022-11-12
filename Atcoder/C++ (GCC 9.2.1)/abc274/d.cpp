#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e3 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<int> a, b(1);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        (i % 2 ? b : a).emplace_back(x);
    }

    std::set<int> dpx, dpy;
    dpx.emplace(a[0]);
    dpy.emplace(0);

    auto f = [](auto & dp, auto &v)
    {
        for (int i = 1; i < std::size(v); i++)
        {
            std::set<int> ndp;
            for (auto &x : dp)
                ndp.emplace(x - v[i]), ndp.emplace(x + v[i]);

            std::swap(dp, ndp);
        }
    }; f(dpx, a); f(dpy, b);
    
    if (dpx.count(x) and dpy.count(y))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    return 0;
}