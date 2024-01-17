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

    std::vector<int> a(n);
    std::multiset<std::tuple<int, int, int>> m;

    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int b;
        std::cin >> b;
        m.emplace(-(a[i] + b - 1), a[i], b);
    }

    i64 ans = 0;
    int turn = 0;
    while (!m.empty())
    {
        turn ^= 1;

        auto [d, ai, bi] = *std::begin(m);
        m.erase(std::begin(m));
        ans += turn ? ai - 1 : 1 - bi;
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