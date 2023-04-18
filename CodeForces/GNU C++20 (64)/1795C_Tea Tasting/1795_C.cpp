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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<i64> pref(n);
    pref[0] = b[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + b[i];

    std::vector<i64> ans(n + 1);
    std::map<int, i64> to_add;
    i64 sum = 0;

    for (int i = 0; i < n; i++)
    {
        int id = std::lower_bound(std::begin(pref), std::end(pref), a[i] + sum) - std::begin(pref);
        ans[i] += 1;
        ans[id] -= 1;

        if (id - 1 >= 0)
            to_add[id] += (a[i] + sum - pref[id - 1]);
        else
            to_add[id] += a[i];

        sum += b[i];
    }

    for (int i = 1; i <= n; i++)
        ans[i] += ans[i - 1];

    for (int i = 0; i < n; i++)
        std::cout << ans[i] * b[i] + to_add[i] << " \n"[i == n - 1];
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