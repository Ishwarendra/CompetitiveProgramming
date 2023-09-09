#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::multiset<std::pair<int, int>> p;
    for (int i = 1; i <= n; i++)  
        p.emplace(0, i);

    int extra = n % m;
    for (int i = 0; i < k; i++)
    {
        std::multiset<std::pair<int, int>> np;
        for (int j = 0; j < m; j++)
        {
            int cnt = n / m;
            int add = 0;
            if (extra > 0)
                extra--, cnt++, add = 1;

            std::cout << cnt << " ";
            while (cnt--)
            {
                auto [priorty, num] = *std::begin(p);
                p.erase(std::begin(p));
                std::cout << num << " \n"[cnt == 0];
                np.emplace(priorty + add, num);
            }
        }

        extra = n % m;
        std::swap(p, np);
    }

    std::cout << "\n";
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