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

    if (k % 3 or n < k)
        std::cout << (n % 3 == 0 ? "Bob\n" : "Alice\n");
    else if (n == k)
        std::cout << "Alice\n";
    else
    {
        // 1 2 3 4 5 _ 7 8 9 ... 15 _ 17 18 ... 25 _ (k = 9)
        int rem = n % (k + 1);
        int special = (n - k) % (k + 1);

        std::cout << (rem % 3 == 0 and special ? "Bob\n" : "Alice\n");
    }
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