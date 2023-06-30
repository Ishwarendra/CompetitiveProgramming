#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::map<int, int> pref, suff;
    auto b = a;
    std::sort(std::begin(b), std::end(b));
    std::multiset<int> m(std::begin(a), std::end(a));
    for (int i = n - 1; i >= 0; i--)
    {
        int sz = 1;

        i64 st = 1;
        auto it = m.lower_bound(b[i] + st * k);
            
        if (it != std::end(m))
            sz += suff[*it];

        suff[b[i]] = sz;
    }

    for (int i = 0; i < n; i++)
    {
        auto get = [&](i64 x)
        {
            if (m.empty())
                return std::end(m);

            auto itr = m.upper_bound(x);
            if (itr == std::begin(m))
                return std::end(m);

            return --itr;
        };

        auto it = get(b[i] - 1LL * k);
        int sz = 1;

        if (it != std::end(m))
            sz += pref[*it];

        pref[b[i]] = sz;
    }
    
    for (int i = 0; i < n; i++)
        std::cout << pref[a[i]] + suff[a[i]] - 1 << " \n"[i == n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}