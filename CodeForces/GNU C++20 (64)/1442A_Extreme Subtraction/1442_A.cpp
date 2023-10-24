#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    if (n <= 2)
    {
        std::cout << "YES\n";
        return;
    }

    std::vector<int> x(n), y(n);
    x[0] = a[0], x.back() = 0;
    y[0] = 0, y.back() = a.back();

    for (int i = 1; i < n; i++)
    {
        x[i] = std::min(x[i - 1], a[i] - y[i - 1]);
        y[i] = a[i] - x[i];
        if (y[i] < y[i - 1] or x[i] > x[i - 1] or std::min(x[i], y[i]) < 0)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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