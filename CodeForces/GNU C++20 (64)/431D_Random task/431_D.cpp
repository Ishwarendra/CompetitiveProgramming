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
    
    i64 m;
    int k;
    std::cin >> m >> k;

    std::function<i64(int, int)> C = [&](int n, int r) -> i64
    {
        if (r == 0)
            return 1;

        return 1LL * n * C(n - 1, r - 1) / r;
    };

    auto getBit = [&](auto x, int pos) { return (x >> pos) & 1LL; };

    auto f = [&](auto n)
    {
        i64 ans = 0;
        for (int cur = 0, i = 62; k - cur >= 0 and i >= 0; i--)
        {
            if (getBit(n, i))
            {
                ans += C(i, k - cur);
                cur++;
            }
        }

        return ans;
    };

    auto good = [&](auto mid)
    {
        return f(2LL * mid) - f(mid) >= m;
    };

    i64 left = 1, right = 1e18;
    i64 ans = -1;

    while (left <= right)
    {
        auto mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans;
    
    return 0;
}