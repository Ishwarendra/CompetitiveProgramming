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
    
    int x, y;
    std::cin >> x >> y;

    if (x > y)
        std::cout << (x - y <= 3 ? "Yes" : "No");
    else
        std::cout << (y - x <= 2 ? "Yes" : "No");
    
    return 0;
}