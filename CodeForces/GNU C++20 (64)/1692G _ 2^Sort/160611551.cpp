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
 
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];
 
    int i = 1, st = 0;
    int ans = 0;
 
    while (i < n)
    {
        if (2 * a[i] <= a[i - 1])
            st = i;
        else
        {
            if (i - st == k)
            {
                ans++, st++;
            }
        }
        i++;
    }
 
    std::cout << ans << "\n";
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