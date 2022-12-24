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

    auto query = [&](int l, int r)
    {
        if (l == r)
            return -1;

        std::cout << "? " << l << " " << r << std::endl;

        int x;
        std::cin >> x;

        return x;
    };

    int left = 1, right = n;

    while (right - left + 1 >= 2)
    {
        int mid = std::midpoint(left, right);
        int smax_pos = query(left, right);

        if (smax_pos <= mid)
        {
            if (query(left, mid) == smax_pos)
                right = mid;
            else
                left = mid + 1;
        }
        else
        {
            if (query(mid + 1, right) == smax_pos)
                left = mid + 1;
            else
                right = mid;
        }
    }

    std::cout << "! " << right << std::endl;
    
    return 0;
}