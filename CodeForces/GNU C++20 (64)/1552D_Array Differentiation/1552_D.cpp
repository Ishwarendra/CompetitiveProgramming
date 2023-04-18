#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T, class G>
T power(T a, G b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
} 

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto getBit = [&](auto x, auto pos) { return (x >> pos) & 1; };

    for (int mask_num = 1; mask_num < power(3, n); mask_num++)
    {
        i64 sum = 0;
        int mask = mask_num;

        for (int pos = 0; pos < n; pos++)
        {
            int rem = mask % 3;
            sum += a[pos] * (rem == 0 ? 0 : rem == 1 ? 1 : -1);

            mask /= 3;
        }

        if (sum == 0)
        {
            std::cout << "YES\n";
            return;
        }
    }

    std::cout << "NO\n";
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