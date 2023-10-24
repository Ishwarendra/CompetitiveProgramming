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

    auto sum = [&](auto &p)
    {
        return std::accumulate(std::begin(p), std::end(p), 0LL);
    };

    auto min = [&](auto &p) -> i64
    {
        return *std::min_element(std::begin(p), std::end(p));
    };

    std::cout << std::min(sum(a) + n * min(b), sum(b) + n * min(a)) << "\n";
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