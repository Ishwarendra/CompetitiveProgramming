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
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    int ans = 101;
    for (int make = -100; make <= 100; make++)
    {
        for (int d = 0; d <= 100; d++)
        {
            bool can = true;
            for (int i = 0; i < n; i++)
            {
                if (a[i] + d != make and a[i] - d != make and a[i] != make)
                    can = false;
            }

            if (can)
                ans = std::min(ans, d);
        }
    }

    std::cout << (ans == 101 ? -1 : ans);
    
    return 0;
}