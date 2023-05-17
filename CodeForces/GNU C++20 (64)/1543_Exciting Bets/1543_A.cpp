#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 a, b;
    std::cin >> a >> b;

    if (a < b)
        std::swap(a, b);

    i64 d = a - b;
    if (d == 0)
        std::cout << "0 0\n";
    else
        std::cout << d << " " << std::min(b % d, d - b % d) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}