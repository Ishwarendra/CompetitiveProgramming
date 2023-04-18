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

    std::vector<int> a(n);
    std::multiset<std::pair<int, int>> m;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        m.emplace(a[i], i);
    }

    std::vector<std::array<int, 2>> ans;
    auto [min, min_id] = *std::begin(m);
    auto [max, max_id] = *(--std::end(m));

    if (min == max)
    {
        std::cout << "0\n";
        return;
    }

    if (min == 1)
    {
        std::cout << "-1\n";
        return;
    }

    while (!m.empty() and max != min and min != 1)
    {
        if (min == 1)
        {
            m.erase(std::begin(m));
            if (!m.empty())
                std::tie(min, min_id) = *std::begin(m);
            continue;
        }

        ans.push_back({max_id, min_id});
        max = (max + min - 1) / min;
        m.erase(--std::end(m));
        m.emplace(max, max_id);

        std::tie(min, min_id) = *std::begin(m);
        std::tie(max, max_id) = *(--std::end(m));
    }

    std::cout << std::size(ans) << "\n";
    for (auto [x, y] : ans)
    {
        a[x] = (a[x] + a[y] - 1) / a[y];
        std::cout << x + 1 << " " << y + 1 << "\n";
    }

    assert(std::size(std::set(std::begin(a), std::end(a))) == 1);
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