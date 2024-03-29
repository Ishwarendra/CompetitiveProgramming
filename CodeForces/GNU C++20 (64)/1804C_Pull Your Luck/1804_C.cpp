#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x, p;
    std::cin >> n >> x >> p;

    for (int i = 1; i < std::min(2 * n + 1, p + 1); i++)  
    {
        i64 f = 1LL * i * (i + 1) / 2;
        f %= n;

        if (f == (n - x) % n)
        {
            std::cout << "Yes\n";
            return;
        }
    }

    std::cout << "No\n";
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