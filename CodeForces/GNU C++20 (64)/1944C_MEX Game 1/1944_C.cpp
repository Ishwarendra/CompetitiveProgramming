#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        m[a]++;
    }

    auto good = [&](int mid)
    {
        std::vector<std::pair<int, int>> a;
        for (auto &[num, f] : m)
        {
            if (num < mid)
                a.emplace_back(f, num);
        }

        std::sort(std::begin(a), std::end(a));
        if (std::size(a) != mid)
            return false;

        for (int i = 1; i < std::size(a); i++)
        {
            if (a[i].first < 2)
                return false;
        }

        return true;
    };

    int left = 0, right = n;
    int ans = 0;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << "\n";
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