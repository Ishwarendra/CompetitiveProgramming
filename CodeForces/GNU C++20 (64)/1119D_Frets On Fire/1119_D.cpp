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
    
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    a.erase(std::unique(std::begin(a), std::end(a)), std::end(a));

    n = std::size(a);
    std::vector<i64> diff(n);
    diff[n - 1] = 6e18;

    for (int i = 0; i < n - 1; i++)
        diff[i] = a[i + 1] - a[i];
    std::sort(std::begin(diff), std::end(diff));

    auto pref = diff;
    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1];

    int q;
    std::cin >> q;
    
    while (q--)
    {
        i64 l, r;
        std::cin >> l >> r;

        i64 len = r - l + 1;
        auto id = std::upper_bound(std::begin(diff), std::end(diff), len) - std::begin(diff);
        i64 sub = pref[n - 1] - (id ? pref[id - 1] : 0LL);

        i64 ans = pref[n - 1] - sub;
        ans += 1LL * len * (n - id);

        std::cout << ans << " \n"[q == 0];
    }

    return 0;
}