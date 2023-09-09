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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<int> cnt(2 * k + 2), sum(2 * k + 1);
    for (int i = 0; i < n / 2; i++)
    {
        auto [L, R] = std::minmax(a[i], a[n - 1 - i]);
        cnt[L + 1]++;
        cnt[R + k + 1]--;
        sum[L + R]++;
    }

    for (int i = 1; i < std::size(cnt); i++)
        cnt[i] += cnt[i - 1];

    int ans = n;
    for (int s = 2; s <= 2 * k; s++)
    {
        int cur = cnt[s] + (n / 2 - cnt[s]) * 2;
        cur -= sum[s];
        ans = std::min(ans, cur);
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}