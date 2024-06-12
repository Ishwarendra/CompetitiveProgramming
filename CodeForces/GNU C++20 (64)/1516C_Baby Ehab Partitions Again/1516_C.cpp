#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * If sum is odd => 0
 * If sum is even and you can divide into two subseq:
 *     If any element is odd then remove it
 *     If all elements are even
 *         is removing one element enough always? NO
 *         Divide all element by 2, since this reduces sum of both subseq so our answer will be unaffected
 */

constexpr int N = 2e5 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto get = [&]()
    {
        std::bitset<N> dp;
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            dp |= dp << a[i];
        return dp;
    };

    int sum = std::accumulate(std::begin(a), std::end(a), 0);
    auto dp = get();
    if (sum % 2 or !dp[sum / 2])
        std::cout << 0;
    else
    {
        int min = 30;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int x = a[i];
            while (x % 2 == 0)
                cnt++, x /= 2;

            min = std::min(min, cnt);
        }
        
        for (int i = 0; i < n; i++)
            a[i] >>= min;

        std::cout << "1\n";
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 1)
            {
                std::cout << i + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}