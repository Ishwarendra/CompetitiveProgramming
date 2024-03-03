#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    auto query = [&](int r, int c)
    {
        std::cout << "? " << r << " " << c << std::endl;
        int d;
        std::cin >> d;
        return d;
    };

    auto d = query(1, 1);
    int down = d + 1, right = d + 1;

    if (d + 1 <= m)
        down = query(1, d + 1);

    if (d + 1 <= n)
        right = query(d + 1, 1);

    if (down == right and down == d)
        std::cout << "! " << d + 1 << " " << d + 1 << std::endl;
    else if (down < d)
        std::cout << "! " << down + 1 << " " << d + 1 << std::endl;
    else
        std::cout << "! " << d + 1 << " " << right + 1 << std::endl;  
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}