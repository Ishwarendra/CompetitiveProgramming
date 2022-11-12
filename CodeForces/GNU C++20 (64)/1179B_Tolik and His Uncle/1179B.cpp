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

    std::array<int, 2> point {1, 1};
    std::vector mat(n, std::vector<int>(m));
    int x = 1, neg = 0;

    auto show = [&]()
    {
        mat[point[0] - 1][point[1] - 1] = 1;
        std::cout << point[0] << ' ' << point[1] << "\n";
    };

    show();
    while (n - x > 0)
    {
        int dy = m - 1;
        for (int i = 0; i < 2 * m - 1; i++, neg ^= 1)
        {
            point[0] += (neg ? -1 : 1) * (n - x);
            point[1] += (neg ? -1 : 1) * (dy--);

            show();
        }

        x++;

        if (n != x)
        {
            point[0] -= n - x;
            show();
        }
        x++;
        neg = 0;
    }

    if (n - x == 0 and m > 1)
    {
        int dy = m - 1;
        while (dy)
        {
            point[1] += (neg ? -1 : 1) * (dy--);
            neg ^= 1;
            show();
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            assert(mat[i][j] != 0);

    return 0;
}