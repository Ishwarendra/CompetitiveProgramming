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

    std::vector<std::array<int, 2>> a[2];
    std::vector<int> b(n);
    i64 base = 0;

    for (int i = 0; i < n; i++)  
        std::cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        base += std::abs(b[i] - c);
        a[b[i] > c].push_back({std::min(b[i], c), std::max(c, b[i])});
    }

    for (int i = 0; i < 2; i++)
        std::sort(std::begin(a[i]), std::end(a[i]));

    if (a[0].empty() or a[1].empty())
    {
        std::cout << base;
        return 0;
    }

    i64 ans = base;
    std::vector<int> skip(std::size(a[1]));

    for (int w = 0; w < 2; w++)
    {
        auto &p = a[w];
        auto &q = a[w ^ 1];

        int sz = std::size(p);

        for (int i = 0; i < sz; i++)
        {
            if (w and skip[i])
                continue;

            int j = std::lower_bound(std::begin(q), std::end(q), std::array {p[i][0], 0}) - std::begin(q);
            while (j < std::size(q) and q[j][0] < p[i][1])
            {
                if (q[j][1] >= p[i][1])
                {
                    ans = std::min(ans, base - 2 * (p[i][1] - q[j][0]));
                    break;
                }
                else
                {
                    ans = std::min(ans, base - 2 * (q[j][1] - q[j][0]));
                    if (w == 0)
                        skip[j] = 1;
                    j++;
                }
            }
        }
    }

    std::cout << ans;
    
    return 0;
}