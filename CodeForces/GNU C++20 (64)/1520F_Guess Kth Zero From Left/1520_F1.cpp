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
    
    int n, t;
    std::cin >> n >> t;

    while (t--)
    {
        int k;
        std::cin >> k;

        auto f = [&](int i, int j)
        {
            std::cout << "? " << i + 1 << " " << j + 1 << std::endl;
            int sum;
            std::cin >> sum;

            return sum;
        };

        int left = 0, right = n - 1;
        int ans = -1;

        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            int sum = f(0, mid);
            if (mid + 1 - sum >= k)
                ans = mid + 1, right = mid - 1;
            else
                left = mid + 1;
        }

        std::cout << "! " << ans << std::endl;
    }
    
    return 0;
}