#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    k = n * m / 2 - k;

    if (n % 2 == 1)
        std::swap(n, m), k = n * m / 2 - k;

    std::vector a(n, std::string(m, '.'));
    if (m % 2 == 0)
    {
        char ch = 'a';
        ch = 'e';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j += 2)
            {
                a[i][j] = a[i][j + 1] = ch;
                ch = 'e' + 'f' - ch;
            }
        }
    }
    else if (k >= n / 2)
    {
        k -= n / 2;
        std::cout << (k % 2 ? "NO\n" : "YES\n");
    }
    else
    {
        if (k % (n / 2) == 0 and (k / (n / 2)) % 2 == 1)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
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