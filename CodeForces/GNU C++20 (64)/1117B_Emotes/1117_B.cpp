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
    
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    i64 ans = m / (k + 1LL) * (1LL * k * a[n - 1] + a[n - 2]);
    ans += 1LL * a[n - 1] * (m % (k + 1));

    std::cout << ans;
    
    return 0;
}