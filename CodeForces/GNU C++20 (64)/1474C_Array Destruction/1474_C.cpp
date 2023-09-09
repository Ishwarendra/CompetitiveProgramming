#include "bits/stdc++.h"

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

    n *= 2;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<std::pair<int, int>> ans;
    auto get = [&](int x)
    {
        ans.clear();
        std::multiset<std::pair<int, int>> m;
        for (int i = 0; i < n; i++)
            m.emplace(a[i], i);

        while (!m.empty())
        {
            auto [max, id1] = *std::prev(std::end(m));
            m.erase(std::prev(std::end(m)));

            auto it = m.lower_bound({x - max, -1});
            if (it == std::end(m) or it->first != x - max)
                return false;

            int id2 = it->second;
            m.erase(it);

            ans.emplace_back(id1 + 1, id2 + 1);
            x = max;
        }

        return true;
    };

    int max_id = std::max_element(std::begin(a), std::end(a)) - std::begin(a);
    for (int i = 0; i < n; i++)
    {
        if (i == max_id)
            continue;

        int x = a[i] + a[max_id];
        if (get(x))
        {
            std::cout << "YES\n";
            std::cout << x << "\n";

            for (auto &[id1, id2] : ans)
                std::cout << a[id1 - 1] << " " << a[id2 - 1] << "\n";
            return;
        }
    }

    std::cout << "NO\n";
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