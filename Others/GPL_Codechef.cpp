#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::array<int, 2> c{};
    c[0] = std::count(std::begin(s), std::end(s), '0');
    c[1] = n - c[0];

    int d = std::abs(c[0] - c[1]);
    if ((c[0] + c[1]) % 2 == 0)
        std::cout << (d >= 2 ? "Alice\n" : "Bob\n");  
    else
        std::cout << (d >= 2 or n == 1 ? "Bob\n" : "Alice\n");
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