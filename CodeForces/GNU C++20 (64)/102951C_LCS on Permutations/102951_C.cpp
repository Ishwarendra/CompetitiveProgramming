#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        b[x - 1] = i;
    }

    std::vector<int> c(n);    
    for (int i = 0; i < n; i++)
        c[i] = b[a[i]];

    c = {1, 1, 0, 10, 3};
    n = std::size(c);
    std::vector<int> s;
    for (int i = 0; i < n; i++)
    {
        auto it = std::upper_bound(std::begin(s), std::end(s), c[i]);
        if (it == std::end(s))
            s.emplace_back(c[i]);
        else
            *it = c[i];
    }
    
    std::cout << std::size(s);
    
    return 0;
}