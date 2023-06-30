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

    int k;
    std::string s;
    std::cin >> k >> s;

    int n = std::size(s);
    std::vector a(n, 0), m(n, 0);

    std::iota(std::begin(m), std::end(m), 0);
    std::reverse(std::begin(s), std::end(s));

    for (int i = 1; i < k; i++)
    {
        int st = (1 << i) - 1;
        int en = (1 << (i + 1)) - 1;
        std::reverse(std::begin(s) + st, std::begin(s) + en);
        std::reverse(std::begin(m) + st, std::begin(m) + en);
    }

    std::reverse(std::begin(m), std::end(m));

    auto left = [&](int p)
    {
        if (p >= n / 2)
            return 1;
        return a[p * 2 + 1];
    };

    auto right = [&](int p)
    {
        if (p >= n / 2)
            return 1;
        return a[2 * p + 2];
    };

    auto pull = [&](int p)
    {
        a[p] = 0;
        if (s[p] != '1')
            a[p] += left(p);
        if (s[p] != '0')
            a[p] += right(p);
    };

    for (int i = n - 1; i >= 0; i--)
        pull(i);

    int q;
    std::cin >> q;
    
    while (q--)
    {
        int p;
        char ch;
        std::cin >> p >> ch;
        p = m[p - 1];
        s[p] = ch;

        while (p)
        {
            pull(p);
            p = (p - 1) / 2;
        }

        pull(0);
        std::cout << a[0] << "\n";
    }

    return 0;
}