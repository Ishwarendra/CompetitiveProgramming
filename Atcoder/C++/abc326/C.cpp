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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int id = std::lower_bound(std::begin(a), std::end(a), a[i] + m) - std::begin(a);
        ans = std::max(ans, id - i); 
    }

    std::cout << ans;
    
    return 0;
}