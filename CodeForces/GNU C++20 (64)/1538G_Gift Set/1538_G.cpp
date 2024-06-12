#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

i64 floor_div(i64 a, i64 b)
{
    if ((a ^ b) < 0)
        return a / b - (a % b != 0);
    a = std::abs(a), b = std::abs(b);
    return a / b;
}
i64 ceil_div(i64 a, i64 b) 
{
    if ((a ^ b) < 0)
        return a / b;
    a = std::abs(a), b = std::abs(b);
    return (a + b - 1) / b;
}

void solve()
{
    int R, B, a, b;
    std::cin >> R >> B >> a >> b;

    if (a == b)
    {
        std::cout << std::min(R / a, B / a) << "\n";
        return;
    }

    auto intersect = [&](int l1, int r1, int l2, int r2)
    {
        return std::max(l1, l2) <= std::min(r1, r2);
    };

    auto good = [&](i64 T, int a, int b)
    {
        i64 min = inf, max = -inf;
        i64 num_r = (R - 1LL * b * T);
        i64 num_b = (B - 1LL * a * T);

        if (a > b)
        {
            max = std::max(max, floor_div(num_r, a - b));
            min = std::min(min, ceil_div(num_b, b - a));
        }
        else
        {
            min = std::min(min, ceil_div(num_r, a - b));
            max = std::max(max, floor_div(num_b, b - a));
        }

        return min <= max and intersect(min, max, 0, T);
    };

    int left = 1, right = (R + B) / (a + b);
    int ans = 0;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid, a, b))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << "\n";
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