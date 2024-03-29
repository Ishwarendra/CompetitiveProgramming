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

    std::array<int, 26> cnt{};
    for (int i = 0; i < n; i++)
    {
        char ch;
        std::cin >> ch;
        cnt[ch - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans += cnt[i] > i;

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