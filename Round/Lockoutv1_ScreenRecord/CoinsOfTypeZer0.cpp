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
    
    i64 n, x, y;
    std::cin >> n >> x >> y;

    i64 ans = (n / (x + y)) * x;
    ans += std::min(x, n % (x + y));

    std::cout << ans;
    
    return 0;
}