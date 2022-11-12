#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

// a, b, c -> all distinct 
// a + b + c = n
// gcd(a, b) = c

// 1 <= n <= 10^9

void solve()
{
    int n;
    std::cin >> n;
    
    for (int i = 2; i < n; i++)  
    {
        if (i != n - i - 1 and std::gcd(i, n - 1 - i) == 1)
        {
            std::cout << i << " " << n - i - 1 << " " << 1 << "\n";
            return;
        }
    }

    std::vector<int> a(n), b(m);
    std::vector<int> c;

    std::
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