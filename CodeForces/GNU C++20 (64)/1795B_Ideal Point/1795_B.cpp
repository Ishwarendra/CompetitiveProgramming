#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool contains(int l, int r, int x)
{
    return l <= x and x <= r;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::multiset<std::pair<int, int>> s;
    std::map<int, int> m;
    for (int i = 0; i < n; i++)  
    {
        int l, r;
        std::cin >> l >> r;
        for (int i = l; i <= r; i++)
            m[i]++;

        s.emplace(l, r);
    }

    std::vector<std::pair<int, int>> del;
    for (auto [num, f] : m)
    {
        if (m[num] >= m[k] and k != num)
            del.emplace_back(f, num);
    }

    std::sort(std::rbegin(del), std::rend(del));

    for (auto [_, x] : del)
    {
        int need = m[x] - m[k] + 1;
        int have = 0;

        std::vector<std::pair<int, int>> remove;
        for (auto [l, r] : s)
        {
            if (contains(l, r, x) and !contains(l, r, k))
            {
                remove.emplace_back(l, r);
                have++;
            }
        }

        if (have < need)
        {
            std::cout << "NO\n";
            return;
        }

        for (auto [l, r] : remove)
        {
            s.erase(s.find({l, r}));
            for (int i = l; i <= r; i++)
                m[i]--;
        }
    }

    std::cout << "YES\n";
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