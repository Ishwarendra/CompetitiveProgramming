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

    int prev = 0, next;
    int count = 0;

    for (int i = 0; i < n; i++)  
    {
        std::cin >> next;
        count += (next - prev) / 120;

        prev = next;
    }

    next = 1440;
    count += (next - prev) / 120;

    std::cout << (count >= 2 ? "YES\n" : "NO\n");
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