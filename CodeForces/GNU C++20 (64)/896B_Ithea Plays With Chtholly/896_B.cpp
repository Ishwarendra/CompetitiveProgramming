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
    
    int n, m, c;
    std::cin >> n >> m >> c;

    std::vector<int> a(n, c + 1);

    auto end = [&](int x)
    {
        for (int i = n - 1; i >= 0; i--)    
        {
            if (a[i] < x or a[i] == c + 1)
            {
                std::cout << i + 1 << std::endl;
                a[i] = x;
                break;
            }
        }
    };

    auto begin = [&](int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > x or a[i] == c + 1)
            {
                std::cout << i + 1 << std::endl;
                a[i] = x;
                break;
            }
        }
    };

    auto query = [&]()
    {
        int x;
        std::cin >> x;
        m--;

        if (x > c / 2)
            end(x);
        else
            begin(x);
    }; 

    auto ok = [&]()
    {
        return std::is_sorted(std::begin(a), std::end(a)) and 
            !std::count(std::begin(a), std::end(a), c + 1);
    };

    while (!ok() and m >= 0)
        query();

    return 0;
}