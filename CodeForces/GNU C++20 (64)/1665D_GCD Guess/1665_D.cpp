#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int query(int a, int b)
{
    std::cout << "? " << a << ' ' << b << std::endl;
    int g;
    std::cin >> g;

    return g;
}

void solve()
{
    int r = 0;
    for (int i = 0; i < 30; i++)
    {
        int g = query((1 << i) - r, (1 << i) - r + (1 << (i + 1)));
        if (g == (1 << i));
        else if (g == (1 << (i + 1)))
            r += (1 << i);
    }

    std::cout << "! " << r << std::endl;
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