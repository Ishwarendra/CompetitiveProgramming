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
    i64 l;
    std::cin >> n >> l;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::multiset<i64> m(std::begin(a), std::end(a));
    i64 s = std::accumulate(std::begin(a), std::end(a), 0LL);

    if (s != l)
        m.emplace(l - s);

    i64 cost = 0;
    while (std::size(m) > 1)
    {
        auto min1 = *std::begin(m);
        m.erase(std::begin(m));
        auto min2 = *std::begin(m);
        m.erase(std::begin(m));

        cost += min1 + min2;
        m.emplace(min1 + min2);
    }

    std::cout << cost;
    
    return 0;
}