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
    
    i64 l, r;
    std::cin >> l >> r;

    auto getBit = [&](auto x, auto pos) { return (x >> pos) & 1LL; };
    auto set = [&](auto x, auto pos, int bit)
    {
        if (getBit(x, pos) == bit)
            return x;
        else
            return x ^ (1LL << pos);
    };

    bool done = false;
    i64 a = 0, b = 0;
    for (int pos = 62; pos >= 0; pos--)
    {
        if (done)
        {
            a = set(a, pos, 0);
            b = set(b, pos, 1);
        }
        else
        {
            int bit = getBit(l, pos);
            if (getBit(l, pos) == getBit(r, pos) or bit == 1)
            {
                a = set(a, pos, bit);
                b = set(b, pos, bit);
            }
            else
            {
                a = set(a, pos, 1);
                b = set(b, pos, 0);
                done = true;
            }
        }
    }

    std::cout << (a ^ b);

    return 0;
}