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
    
    i64 a, b;
    std::cin >> a >> b;

    auto primeFactor = [&](i64 x)
    {
        std::map<i64, int> m;
        for (int i = 2; 1LL * i * i <= x; i++)
        {
            while (x % i == 0)
                x /= i, m[i]++;
        }

        if (x > 1)
            m[x]++;

        return m;
    };

    i64 len = b - a + 1;

    i64 num = a + b;
    if (len % 2)
        num = (a + b) / 2;

    auto pf = primeFactor(num);
    for (const auto &[num, f] : primeFactor(len % 2 ? len : len / 2))
        pf[num] += f;

    i64 ans = 1;
    for (auto &[num, f] : pf)
        ans *= (f + 1LL);

    std::cout << ans << "\n";
    
    return 0;
}