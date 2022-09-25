#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
using i64 = long long;
 
void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;
 
    std::vector<int> x(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i];
 
    i64 tot = std::accumulate(x.begin(), x.end(), 0LL);
    i64 cur = 0;
    i64 ans = 1LL * tot * b;
 
    for (int i = 1; i < n; i++)
    {
        cur += x[i];
        i64 cur_cost = a * 1LL * abs(x[i] - x[0]);
        cur_cost += b * 1LL * abs(x[i] - x[0]);
 
        cur_cost += b * 1LL * (tot - cur - 1LL * (n - i) * x[i]);
 
        ans = std::min(ans, cur_cost);
    }
 
    std::cout << ans << "\n";   
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