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

    auto good = [&](int x)
    {
        std::array<int, 3> a{};
        for (int i = 0; i < 3; i++)
            a[i] = x % 10, x /= 10;

        return a[2] * a[1] == a[0];
    };

    while (!good(n))
        n++;

    std::cout << n;
    
    return 0;
}