#include <bits/stdc++.h>

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
    i64 k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    std::multiset<i64> m;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        if (a[i])
            m.emplace(a[i]);
    }

    i64 d = 0, temp = k;
    while (temp > 0)
    {
        i64 min = *std::begin(m);
        min -= d;

        if (min * std::size(m) < temp)
        {
            temp -= min * std::size(m);
            d += min;
            m.erase(std::begin(m));
        }
        else
        {
            i64 x = temp / std::size(m);
            d += x;
            temp -= x;
            break;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (m.find(a[i]) == std::end(m))
            k -= a[i], a[i] = 0;
        else
            a[i] -= d, k -= d;
    } 
    
    for (int i = 0; k > 0; (i += 1) % n)
    {
        if (a[i])
            a[i]--, k--;
    }
    
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];

    return 0;
}