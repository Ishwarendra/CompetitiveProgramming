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
    
    int n, p, q, r, s;
    std::cin >> n >> p >> q >> r >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = p - 1, j = r - 1; i < q; i++, j++)
        std::swap(a[i], a[j]);

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
    
    return 0;
}