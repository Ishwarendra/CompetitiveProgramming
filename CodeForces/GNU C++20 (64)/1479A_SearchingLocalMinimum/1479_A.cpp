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

    std::vector a(n + 2, -1);
    a[0] = a.back() = n + 1;

    auto query = [&](int i)
    {
        if (a[i] != -1)
            return a[i];

        std::cout << "? " << i << std::endl;
        std::cin >> a[i];
        return a[i];
    };

    int left = 1, right = n;
    int ans = -1;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (query(mid) > query(mid + 1))
            left = mid + 1;
        else if (query(mid) > query(mid - 1))
            right = mid - 1;
        else
        {
            ans = mid;
            break;
        }
    }

    std::cout << "! " << ans << std::endl;

    return 0;
}