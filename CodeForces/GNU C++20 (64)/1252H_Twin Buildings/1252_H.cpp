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

    std::vector<std::pair<int, int>> a(n);
    for (auto &[l, r] : a)
    {
        std::cin >> l >> r;
        if (l > r)
            std::swap(l, r);
    }

    i64 ans = 0;
    for (auto &[l, r] : a)
        ans = std::max(ans, 1LL * l * r);

    std::multiset<int, std::greater<>> m;
    std::sort(std::rbegin(a), std::rend(a));
    m.emplace(a[0].second);

    for (int i = 1; i < n; i++)
    {
        m.emplace(a[i].second);
        auto max1 = *std::begin(m);
        auto max2 = *(++std::begin(m));

        ans = std::max(ans, 2LL * a[i].first * std::min(max1, max2));
    }

    std::cout << ans / 2;
    if (ans % 2)
        std::cout << ".5";
    else
        std::cout << ".0";
    
    return 0;
}