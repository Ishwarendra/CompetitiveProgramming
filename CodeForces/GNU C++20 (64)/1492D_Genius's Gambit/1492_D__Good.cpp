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
    
    int a, b, k;
    std::cin >> a >> b >> k;

    auto getBit = [&](int mask, int pos) { return mask >> pos & 1; };
    auto valid = [&](int x)
    {
        return getBit(x, a + b - 1);
    };

    int n = a + b;
    std::string ans = "No";
    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (__builtin_popcount(mask) != b)
            continue;
        for (int mask2 = 0; mask2 < (1 << n); mask2++)
        {
            if (mask2 > mask or __builtin_popcount(mask2) != b)
                continue;

            if (!valid(mask) or !valid(mask2))
                continue;

            int K = mask - mask2;
            if (__builtin_popcount(K) == k)
            {
                print(mask, mask2, K)
                return 0;
                ans = "Yes";
            }
        }
    }

    std::cout << ans;
    
    return 0;
}