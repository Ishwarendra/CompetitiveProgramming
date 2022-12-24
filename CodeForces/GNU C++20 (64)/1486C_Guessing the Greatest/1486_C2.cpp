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

        auto [min, max] = std::minmax(l, r);
        std::cout << "? " << min << " " << max << std::endl;

        int x;
        std::cin >> x;

        return x;
    };

    auto answer = [&](int x)
    {
        std::cout << "! " << x << std::endl;
    };

    int smax_pos = query(1, n);

    auto find_left = [&](int left, int right)
    {
        int ans = -1;

        if (query(left, smax_pos) != smax_pos)
            return ans;

        while (left <= right)
        {
            int mid = std::midpoint(left, right);

            if (query(mid, smax_pos) == smax_pos)
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    };

    auto find_right = [&](int left, int right)
    {
        int ans = -1;

        if (query(smax_pos, right) != smax_pos)
            return ans;

        while (left <= right)
        {
            int mid = std::midpoint(left, right);

            if (query(smax_pos, mid) == smax_pos)
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    };

    auto left = find_left(1, smax_pos - 1);
    auto right = find_right(smax_pos + 1, n);

    if (left != -1)
        answer(left);
    else
        answer(right);
}