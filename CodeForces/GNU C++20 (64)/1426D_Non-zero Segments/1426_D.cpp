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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::set<i64> seen {0};
    i64 pref = 0;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        pref += a[i];
        if (seen.count(pref))
            ans++, seen.clear(), seen.emplace(0), pref = a[i];

        seen.emplace(pref);
    }

    std::cout << ans;

    return 0;
}