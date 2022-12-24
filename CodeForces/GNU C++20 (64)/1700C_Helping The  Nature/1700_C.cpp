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

    std::vector<i64> a(n);
    std::vector<i64> pref(n), suff(n);

    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 ans = 0;

    for (int i = 1; i < n; i++)
    {
        ans += std::abs(a[i] - a[i - 1]);
        if (a[i - 1] > a[i]) 
        {
            pref[0] += a[i - 1] - a[i];
            pref[i] -= a[i - 1] - a[i];
        }
        else
        {
            suff.back() += a[i] - a[i - 1];
            suff[i - 1] -= a[i] - a[i - 1];
        }
    }

    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1];
    for (int i = n - 2; i >= 0; i--)
        suff[i] += suff[i + 1];

    for (int i = 0; i < n; i++)
        a[i] -= pref[i] + suff[i];

    assert(std::size(std::set(std::begin(a), std::end(a))) == 1);
    std::cout << ans + std::abs(a[0]) << "\n";
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