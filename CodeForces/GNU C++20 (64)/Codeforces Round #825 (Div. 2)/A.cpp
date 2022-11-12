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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<int> diff_a, diff_b;
    int zero = 0, one = 0;

    for (int i = 0; i < n; i++)
    {
        zero += (a[i] == 0) - (b[i] == 0);
        one += (a[i] == 1) - (b[i] == 1);
        if (a[i] == b[i])
            continue;
        diff_a.emplace_back(a[i]);
        diff_b.emplace_back(b[i]);
    }

    int ans = std::size(diff_a);
    ans = std::min(ans, std::max(zero, one) + 1);

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