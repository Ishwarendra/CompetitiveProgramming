#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    for (int i = 0; i < n - 1; i++)
        std::cout << i + 1 << " " << i + 2 << "\n";

    int prev = n - 1;
    std::array<int, 2> last {n, n - 1};
    while (q--)  
    {
        int d;
        std::cin >> d;

        if (d == prev)
        {
            std::cout << "-1 -1 -1\n";
            continue;
        }

        std::cout << last[0] << " " << last[1] << " " << d << "\n";
        last[1] = d;
        prev = d;
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