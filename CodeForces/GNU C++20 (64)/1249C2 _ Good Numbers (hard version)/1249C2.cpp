#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n;
    std::cin >> n;

    auto get = [&](i64 n)
    {
        std::vector<int> digits(60);
        for (int i = 0; i < 60; i++)
        {
            digits[i] = n % 3;
            n /= 3;
        }

        return digits;
    };

    auto digits = get(n);

    i64 ans = 0;
    int last_two = 60;

    for (int i = 59; i >= 0; i--)
    {
        if (digits[i] == 2)
        {
            digits[i] = 0;
            last_two = i;
            break;
        }
    }

    for (int i = last_two + 1; i < 60; i++)
    {
        if (digits[i] == 0)
        {
            digits[i] = 1;
            last_two = i;
            break;
        }
    }

    if (last_two == 60)
        last_two = -1;
    auto debug = [&]()
    {
        for (int i = 5; i >= 0; i--)
            std::cerr << digits[i] << " \n"[i == 0];
    };

    for (int i = last_two - 1; i >= 0; i--)
        digits[i] = 0;

    for (int i = 59; i >= 0; i--)
        ans = ans * 3 + digits[i];

    std::cout << ans << "\n";
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