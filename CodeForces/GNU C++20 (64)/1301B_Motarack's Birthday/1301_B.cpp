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

    int k = 0;

    auto good = [&](int mid)
    {
        int L = 0, R = 1e9;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1] and a[i] == -1)
                continue;

            if (a[i] != -1 and a[i - 1] != -1)
            {
                if (std::abs(a[i - 1] - a[i]) > mid)
                    return false;
            }
            else
            {
                int x = a[i] == -1 ? a[i - 1] : a[i];
                L = std::max(L, x - mid);
                R = std::min(R, x + mid);
            }
        }

        if (L <= R)
            k = L;
        return L <= R;
    };  

    int left = 0, right = 1e9;
    int ans = 0;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans << " " << k << "\n";
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