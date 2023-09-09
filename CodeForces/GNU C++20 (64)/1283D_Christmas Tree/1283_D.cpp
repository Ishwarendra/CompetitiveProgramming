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

    std::set<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a.emplace(x);
    }

    i64 sum = 0;
    std::set<int> pos, ignore(a);
    for (int i = 0, cur = 1; i < m; cur++)
    {
        std::vector<int> rem;
        for (auto x : a)
        {
            if ((pos.count(x - cur) or ignore.count(x - cur)) and (pos.count(x + cur) or ignore.count(x + cur)))
            {
                rem.emplace_back(x);
                continue;
            }

            if (i < m and !pos.count(x - cur) and !ignore.count(x - cur))
                pos.emplace(x - cur), sum += cur, i++;
            if (i < m and !pos.count(x + cur) and !ignore.count(x + cur))
                pos.emplace(x + cur), sum += cur, i++;
        }

        for (auto d : rem)
            a.erase(d);
    }

    std::cout << sum << "\n";
    for (auto x : pos)
        std::cout << x << " ";
    
    return 0;
}