#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
void solve()
{
    int n;
    std::cin >> n;
 
    std::vector<int> a(n);
    std::map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        m[a[i]]++;
    }
 
    int even = 0, odd = 0;
    for (auto [p, f] : m)
    {
        odd += f % 2 == 1;
        even += f % 2 == 0;
    }
 
    int ans = (even - (even % 2)) + odd; 
 
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