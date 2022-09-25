#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
void solve()
{
    int n, k;
    std::cin >> n >> k;
 
    if (n % 2 == 0)
    {
        if (k % n)
            std::cout << k % n << "\n";
        else
            std::cout << n << "\n";
    }
    else
    {
        int skipped = (k - 1) / (n / 2);
        int ans = (k + skipped);
 
        if (ans % n == 0)
            ans = n;
        else
            ans %= n;
 
        std::cout << ans << "\n";    
    }
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