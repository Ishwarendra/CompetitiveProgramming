#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 f(i64 x)
{
    if (x == 0)
        return 0;

    int left = 1, right = 1e9;
    int ans = 0;
    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (1LL * mid * mid <= x)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    i64 cnt = 3LL * (ans - 1);
    i64 cur = 1LL * ans * ans;

    while (cur <= x)
        cur += ans, cnt++;

    return cnt;
}

void solve()
{
    i64 l, r;
    std::cin >> l >> r;  
    std::cout << f(r) - f(l - 1) << "\n";
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