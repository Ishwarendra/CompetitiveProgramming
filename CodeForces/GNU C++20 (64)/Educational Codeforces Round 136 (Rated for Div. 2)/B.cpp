#include <bits/stdc++.h>

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

    std::vector<int> d(n);
    for (int i = 0; i < n; i++)  
        std::cin >> d[i];

    std::vector<int> a(n);
    a[0] = d[0];
    for (int i = 1; i < n; ++i)
    {
        int first = a[i - 1] - d[i];
        int second = a[i - 1] + d[i];
        if (first != second and first >= 0 and second >= 0)
        {
            std::cout << "-1\n";
            return;
        }

        a[i] = a[i - 1] + d[i];
    }

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " \n"[i == n - 1];
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