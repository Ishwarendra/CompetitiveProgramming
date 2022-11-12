#include <bits/stdc++.h>

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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    i64 left = 1, right = a.back();

    auto good = [&](i64 mid)
    {
        std::vector<int> have {1};
        i64 last = a[0];

        for (int i = 1; i < n and have.size() < k; i++)
        {
            if (a[i] - last >= mid)
                last = a[i], have.push_back(i + 1);
        }

        return have;
    };

    std::vector<i64> ans;
    while (left <= right)
    {
        i64 mid = (left + right) >> 1;
        auto id = good(mid);
        if (std::size(id) >= k)
        {
            left = mid + 1;
            ans.clear();

            for (int i : id)
                ans.emplace_back(a[i - 1]);
        }
        else
            right = mid - 1;
    }

    for (auto x : ans)    
        std::cout << x << " ";
    
    return 0;
}