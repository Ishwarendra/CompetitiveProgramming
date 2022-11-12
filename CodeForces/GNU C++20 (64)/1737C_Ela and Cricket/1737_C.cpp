#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::pair<int, int> cols[3];
    std::map<int, int> row, col;
    for (int i = 0; i < 3; ++i)
    {
        std::cin >> cols[i].first >> cols[i].second;
        row[cols[i].first]++;
        col[cols[i].second]++;
    }
    std::sort(cols, cols + 3);

    int x, y;
    std::cin >> x >> y;

    int parCol = 0, parRow = 0;
    for (auto [num, f] : row)
    {
        if (f == 2)
            parRow = num;
    }

    for (auto [num, f] : col)
    {
        if (f == 2)
            parCol = num;
    }

    std::vector<std::vector<std::vector<int>>>
    cornercase
    {
        {{1, 1}, {1, 2}, {2, 1}},
        {{1, n}, {1, n - 1}, {2, n}},
        {{n - 1, 1}, {n, 1}, {n, 2}},
        {{n, n - 1}, {n - 1, n}, {n, n}}
    };

    for (int i = 0; i < 4; ++i)
        std::sort(std::begin(cornercase[i]), std::end(cornercase[i]));

    auto corner = [&]()
    {
        int yes = 0;
        do
        {
            for (int i = 0; i < 4; ++i)
            {
                int can = 1;
                for (int j = 0; j < 3; ++j)
                {
                    auto [r, c] = cols[j];
                    if (cornercase[i][j][0] != r or cornercase[i][j][1] != c)
                        can = 0;
                }

                yes |= can;
            }

        } while (std::next_permutation(cols, cols + 3));

        return yes;
    };

    print(corner())
    if (corner())
    {
        if (x == parRow or y == parCol)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    else
        std::cout << ((x % 2 == parRow % 2) or (y % 2 == parCol % 2) ? "YES\n" : "NO\n");
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