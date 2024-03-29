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
    {
        std::cin >> a[i];
        a[i] = a[i] & 1;
    }

    int ans = 0;
    for (int i = 0; i < n; )
    {
        int j = i + 1;
        while (j < n and a[j] % 2 == a[i] % 2)
            j++;

        ans += j - i - 1;
        i = j;
    }

    std::cout << ans << '\n';
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