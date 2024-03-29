#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    int left = 1, right = n;
    std::vector<int> a(n, 0);

    int pos = 0;
    while (pos < n)
    {
        for (int i = 0; i < k - 1 and pos < n; i++)
            a[pos++] = right--;

        if (pos < n)
            a[pos++] = left++;
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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