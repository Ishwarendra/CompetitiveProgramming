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
    
    int n, l;
    std::cin >> n >> l;

    i64 sum = 0;
    i64 ans = 0;

    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++)
        std::cin >> a[i];

    for (int i = 0; i < l; i++)
        sum += a[i];
    ans = sum;

    for (int i = l; i < n - 1; i++)
    {
        sum += a[i];
        sum -= a[i - l];
        ans = std::min(ans, sum);
    }

    std::cout << ans;
    
    return 0;
}