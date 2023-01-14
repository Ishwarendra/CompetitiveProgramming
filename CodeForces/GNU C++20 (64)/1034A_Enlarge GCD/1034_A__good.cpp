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

    std::vector<int> a(n);
    int gcd = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        gcd = std::gcd(gcd, a[i]);
    }

    // print(clock() / CLOCKS_PER_SEC)
    
    return 0;
}