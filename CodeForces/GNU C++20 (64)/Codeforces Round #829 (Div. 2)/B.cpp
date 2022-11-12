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

    std::vector<int> ans(n);
    
    for (int i = 0, num = 1; i < n;)
    {
        int start = i;
        int x = 0, d = n / 2;
        while (num + d * x <= n)
        {
            ans[i] = num + d * x;
            x++;
            i++;
        }

        num++;
        std::reverse(std::begin(ans) + start, std::begin(ans) + i);
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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