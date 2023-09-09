#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::array<int, 2>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve()
{
    int b, w;
    std::cin >> b >> w;

    auto [min, max] = std::minmax(b, w);
    if (max > 3 * min + 1)  
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";

        auto get = [&](std::array<int, 2> cur, int id)
        {
            auto [dx, dy] = dirs[id];
            cur[0] += dx;
            cur[1] += dy;
            return cur;
        };

        int cnt = 0;
        auto disp = [&](std::array<int, 2> x)
        {
            cnt++;
            std::cout << x[0] << " " << x[1] << "\n";
        };

        std::array<int, 2> st {2, 2};
        if (b < w)
            st = std::array {2, 3};

        int b = min, w = max;
        std::vector<std::array<int, 2>> getLeft;
        while (b and w)
        {
            disp(st);
            b--;
            getLeft.emplace_back(st);   

            disp(get(st, 2));
            w--;

            st = get(get(st, 2), 2);
        }

        int id = 0;
        if (w)
            disp(get(getLeft[0], 3)), w--;

        while (w)
        {
            st = getLeft[id++];

            disp(get(st, 0));
            w--;
            if (w)
                disp(get(st, 1)), w--;
        }

        assert(cnt == min + max);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}