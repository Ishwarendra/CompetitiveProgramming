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
    int l, r;
    std::cin >> l >> r;
 
    auto len = [&](int x)
    {
        int cnt = 0;
        while (x)
            x /= 10, cnt++;
 
        return cnt;
    };
 
    std::vector<long long> p10(11, 1);
    i64 ans = 0;
 
    for (int i = 1; i <= 10; ++i)
        p10[i] *= p10[i - 1] * 10LL;
 
    for (int x = 0; x <= len(r); x++)
        ans += (r / p10[x]) - (l / p10[x]);
 
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