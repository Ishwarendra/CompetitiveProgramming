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

    std::string s;
    std::cin >> s;

    i64 pos = 0, neg = 0;
    for (auto ch : s)
    {
        pos += ch == '+';
        neg += ch == '-';
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int a, b;
        std::cin >> a >> b;

        i64 num = 1LL * b * (neg - pos);
        i64 den = (a - b);

        if (den != 0 and std::abs(num) % std::abs(den) == 0)
        {
            i64 frac = num / den;
            if (-neg <= frac and frac <= pos)
            {
                std::cout << "YES\n";
                continue;
            }
        }

        if (den == 0)
        {
            if (neg == pos)
            {
                std::cout << "YES\n";
                continue;
            }
        }

        std::cout << "NO\n";
    }
    
    return 0;
}