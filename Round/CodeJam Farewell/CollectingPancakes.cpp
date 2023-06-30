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
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int la, ra, lb, rb;
    std::cin >> la >> ra >> lb >> rb;
    la--, lb--, ra--, rb--;

    std::vector<i64> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];

    auto sum = [&](int i, int j)
    {
        if (i == 0)
            return pref[j];
        return pref[j] - pref[i - 1];
    };

    auto between = [&](int x, int l, int r)
    {
        return l <= x and x <= r;
    };

    auto get = [&](int alice, int bob)
    {
        if (alice > bob)
            return sum((alice + bob + 1) / 2, n - 1);
        else
            return sum(0, (alice + bob) / 2);
    };

    i64 ans = 0;
    constexpr i64 inf = 1e18;
    for (int i = la; i <= ra; i++)
    {
        i64 cur_ans = inf;
        if (lb > i)
            cur_ans = std::min(cur_ans, get(i, lb));
        if (rb < i)
            cur_ans = std::min(cur_ans, get(i, rb));

        if (between(i - 1, lb, rb))
            cur_ans = std::min(cur_ans, get(i, i - 1));
        if (between(i + 1, lb, rb))
            cur_ans = std::min(cur_ans, get(i, i + 1));

        if (cur_ans < inf)
            ans = std::max(ans, cur_ans);
    }

    std::cout << ans << "\n";
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