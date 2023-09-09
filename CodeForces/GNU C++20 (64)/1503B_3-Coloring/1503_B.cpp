#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

const std::vector<std::pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector a(n, std::vector<int>(n));
    auto safe = [&](int x, int y)
    {
        return std::min(x, y) >= 0 and std::max(x, y) < n;
    };

    auto validate = [&]()
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                for (auto [dx, dy] : dirs)
                {
                    if (!safe(x + dx, y + dy) or a[x + dx][y + dy] == 0)
                        continue;
                    assert(a[x + dx][y + dy] != a[x][y]);
                }
            }
        }
    };

    auto good = [&](int x, int y, int c)
    {
        if (!safe(x, y))
            return 0;

        int ok = 1;
        for (auto &[dx1, dy1] : dirs)
        {
            if (!safe(x + dx1, y + dy1))
                continue;

            ok &= a[x + dx1][y + dy1] != c || a[x + dx1][y + dy1] == 0;

            for (auto &[dx2, dy2] : dirs)
            {
                int dx = dx1 + dx2;
                int dy = dy1 + dy2;

                if (!safe(x + dx, y + dy) or a[x + dx1][y + dy1] != 0)
                    continue;

                ok &= a[x + dx][y + dy] == c || a[x + dx][y + dy] == 0;
            }
        }

        return ok;
    };

    for (int _ = 0; _ < n * n; _++)
    {
        int x;
        std::cin >> x;

        int done = 0;
        for (auto c : {1, 2, 3})
        {
            if (c == x or done)
                continue;

            assert(c != x);
            for (int i = 0; i < n and !done; i++)
            {
                for (int j = 0; j < n and !done; j++)
                {
                    if (a[i][j])
                        continue;
                    if (good(i, j, c))
                    {
                        std::cout << c << " " << i + 1 << " " << j + 1 << std::endl;
                        a[i][j] = c, done = 1;
                    }
                }
            }
        }
        // validate();
        assert(done);
    }

    return 0;
}