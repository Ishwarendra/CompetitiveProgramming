#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;
    int ans = 0;

    if (x == 0 and n % 2 == 1)
    {
        std::cout << "-1\n";
        return;
    }

    auto getBit = [&](auto x, auto pos) { return (x >> pos) & 1; };
    for (int bit = 30; bit >= 0 and n > x; bit--)
    {
        if (bit & 1)
        {
            if (getBit(n, bit))
                ans++, n ^= (1 << bit);
        }
        else
        {
            if (getBit(n, bit))
            {
                ans++;
                n -= (1 << (bit - 1));
                if (n > x)
                    ans++, n -= (1 << (bit - 1));
            }
        }
    }

    std::cout << ans + (n != 0) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}