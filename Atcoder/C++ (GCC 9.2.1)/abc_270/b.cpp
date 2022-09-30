#include <bits/stdc++.h>

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
    
    int x, y, z;
    std::cin >> x >> y >> z;

    auto between = [&](int a, int b, int c)
    {
        return std::min(b, c) <= a and a <= std::max(b, c);
    };

    if (between(y, 0, x) and between(y, 0, z))
        std::cout << "-1\n";
    else if (between(y, 0, x))
        std::cout << std::abs(z) + std::abs(z - x);
    else
        std::cout << std::abs(x);
    
    return 0;
}