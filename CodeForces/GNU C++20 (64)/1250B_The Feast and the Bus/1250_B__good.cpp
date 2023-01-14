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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[x - 1]++;
    }

    auto m = std::multiset(std::begin(a), std::end(a));

    auto good = [&](i64 mid) -> std::pair<bool, int>
    {
        auto x = m;
        int count = 0;
        while (!x.empty())
        {
            count++;
            auto cur = *(--std::end(x));
            if (cur > mid)
                return {false, 1e9};

            x.erase(--std::end(x));
            if (x.empty())
                return {true , count};
            auto it = x.upper_bound(mid - cur);

            if (it == std::begin(x))
                continue;

            --it;
            x.erase(it);
        }

        return {true, count};
    };

    i64 ans = 1e18;
    i64 left = 1, right = 1e18;

    for (int mid = n; mid >= 0; mid--)
    {
        auto [g, count] = good(mid);
        if (g)
        {
            if (count * mid == 36)
                print(count);
            ans = std::min(ans, 1LL * count * mid);
        }
        else
            break;
    }

    std::cout << ans;
    
    return 0;
}