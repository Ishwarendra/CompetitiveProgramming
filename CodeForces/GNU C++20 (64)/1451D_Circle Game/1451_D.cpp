#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int k, d;
    std::cin >> d >> k;

    auto check = [&](int x, int y) 
    {
        return 1LL * x * x + 1LL * y * y <= 1LL * d * d;
    };

    int left = 1, right = d;
    int ans = -1;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (check(k * mid, k * mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }
    
    if (!check(k * ans, k * (ans + 1)))
        std::cout << "Utkarsh\n";
    else
        std::cout << "Ashish\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}