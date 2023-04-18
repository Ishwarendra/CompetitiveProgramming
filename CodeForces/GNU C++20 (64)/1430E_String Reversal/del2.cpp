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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto horizontal = [&](int x1, int x2, char ch)
    {
        if (x1 > x2)
            return false;

        for (int i = x1; i <= x2; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != ch)
                    return false;
            }
        }

        return true;
    };

    auto vertical = [&](int y1, int y2, char ch)
    {
        if (y1 > y1)
            return false;

        for (int i = 0; i < n; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                if (a[i][j] != ch)
                    return false;
            }
        }

        return true;
    };

    std::string s = "BGR";

    do
    {
        if (n % 3 == 0)
        {
            int k = n / 3;
            if (horizontal(0, k - 1, s[0]) and horizontal(k, 2 * k - 1, s[1])
                    and horizontal(2 * k, 3 * k - 1, s[2]))
            {
                std::cout << "YES\n";
                return 0;
            }
        }

        if (m % 3 == 0)
        {
            int k = m / 3;
            if (vertical(0, k - 1, s[0]) and vertical(k, 2 * k - 1, s[1])
                    and vertical(2 * k, 3 * k - 1, s[2]))
            {
                std::cout << "YES\n";
                return 0;
            }
        }
    } while (std::next_permutation(std::begin(s), std::end(s)));

    std::cout << "NO\n";

    return 0;
}