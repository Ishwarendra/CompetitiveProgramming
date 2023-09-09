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

    int a, b;
    std::string s;
    std::cin >> a >> b >> s;

    int n = std::size(s);

    auto move = [&](int &x, int &y, char ch)
    {
        if (ch == 'U')
            y++;
        else if (ch == 'D')
            y--;
        else if (ch == 'L')
            x--;
        else
            x++;
    };

    auto get = [&](int end) -> std::array<int, 2>
    {
        int x = 0, y = 0;
        for (int i = 0; i < end; i++)
            move(x, y, s[i]);

        return std::array {x, y};
    };

    auto isDivisible = [&](int a, int b) 
    { 
        if (b == 0)
            return true;
        return a % b == 0; 
    };

    auto check = [&](int x, int a)
    {
        if (a == 0 and x != a)
            return true;
        return false;
    };

    std::array<int, 2> t = get(n);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (check(a - x, t[0]) or check(b - y, t[1]))
        {
            // print(a - x, b - y, t)
            move(x, y, s[i]);
            continue;
        }
        if (1LL * (a - x) * t[1] == 1LL * (b - y) * t[0])
        {
            int p = t[0] == 0 ? 1 : isDivisible(a - x, t[0]) and (a - x) / t[0] >= 0;
            p &= t[1] == 0 ? 1 : isDivisible(b - y, t[1]) and (b - y) / t[1] >= 0;

            if (p)
            {
                std::cout << "Yes";
                return 0;
            }
        }

        move(x, y, s[i]);
    }


    std::cout << "No";

    return 0;
}