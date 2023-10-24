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
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 left = 0, right = 1e17;
    i64 ans = 0;

    auto good = [&](i64 mid)
    {
        i64 sum = 0;
        for (int i = 0; i < n; ++i)
            sum += std::min(a[i], mid);
        return sum <= k;
    }; 

    while (left < right)
    {
        i64 mid = (left + right) / 2;
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    for (int i = 0; i < n; ++i)
    {
        k -= std::min(a[i], ans);
        a[i] -= std::min(a[i], ans);
    }

    for(int i = 0; k > 0; i = (i + 1) % n)
    {
        if (a[i])
            a[i]--, k--;
    }

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " \n"[i + 1 == n];
    
    return 0;
}