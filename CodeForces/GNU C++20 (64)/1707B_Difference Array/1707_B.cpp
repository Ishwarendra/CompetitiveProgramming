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

    std::vector<int> a;
    int zeroes = 0;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;

        if (x)
            a.emplace_back(x);
        else
            zeroes++;
    }

    for (int cnt = 0; cnt < n - 1; cnt++)
    {
        if (std::empty(a))
        {
            std::cout << "0\n";
            return;
        }

        std::vector<int> b;
        if (zeroes > 0 and a.size() > 0)
            b.emplace_back(a[0]);

        zeroes = std::max(0, zeroes - 1);

        for (int i = 0; i < std::ssize(a) - 1; i++)
        {
            if (a[i] == a[i + 1])
                zeroes++;
            else
                b.emplace_back(a[i + 1] - a[i]);
        }

        std:sort(std::begin(b), std::end(b));
        std::swap(a, b);
    }

    std::cout << (std::empty(a) ? 0 : a.front()) << "\n";
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