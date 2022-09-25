#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
void solve()
{
    int n, m;
    std::string s;
 
    std::cin >> n >> m >> s; 
 
    int lx = 0, hx = 0, ly = 0, hy = 0;
    int x = 0, y = 0;
 
    std::vector<int> ans(2);
 
    for (int i = 0; i < s.length(); i++)  
    {
        x += s[i] == 'R';
        x -= s[i] == 'L';
        y += s[i] == 'U';
        y -= s[i] == 'D';
 
        lx = std::min(lx, x);
        ly = std::min(ly, y);
        hx = std::max(hx, x);
        hy = std::max(hy, y);
 
        if (hx - lx < m and hy - ly < n)
            ans = {-ly, -lx};
    }
 
    std::cout << n - ans[0] << " " << ans[1] + 1 << "\n";
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}