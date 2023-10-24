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

    std::vector<std::array<int, 3>> a, b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;

        (x > y ? a : b).push_back({x, y, i});
    }

    std::sort(std::begin(a), std::end(a));
    std::sort(std::rbegin(b), std::rend(b));

    if (std::size(a) < std::size(b))
        std::swap(a, b);

    std::cout << std::size(a) << "\n";
    for (auto [_, __, id] : a)
        std::cout << id + 1 << " ";
    
    return 0;
}   