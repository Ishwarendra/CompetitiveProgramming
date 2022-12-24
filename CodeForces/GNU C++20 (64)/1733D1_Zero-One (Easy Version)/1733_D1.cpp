#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x, y;
    std::cin >> n >> x >> y;

    std::string a, b;
    std::cin >> a >> b;

    std::vector<int> c(n);
    for (int i = 0; i < std::size(a); i++)  
        c[i] = ((a[i] - '0') ^ (b[i] - '0'));

    int have = std::accumulate(std::begin(c), std::end(c), 0);
    if (have % 2)
        std::cout << "-1\n";
    else
    {
        if (have == 2)
        {
            int consec = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (c[i] == c[i + 1] and c[i] == 1)
                    consec = 1;
            }
            std::cout << (consec ? std::min(2 * y, x) : y) << "\n";
        }
        else
            std::cout << 1LL * y * (have / 2) << "\n";
    }
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