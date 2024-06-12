#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool p4(int x)
{
    int sq = std::max<int>(1, std::sqrt(x));
    while (sq * sq < x)
        sq++;
    return sq * sq == x;
}

void solve()
{
    int n;
    std::cin >> n;

    if (n % 2 == 0 and p4(n / 2))
        std::cout << "YES\n";
    else if (n % 4 == 0 and p4(n / 4))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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