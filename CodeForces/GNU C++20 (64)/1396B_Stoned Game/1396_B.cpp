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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    int max = a.back();
    int sum = std::accumulate(std::begin(a), std::end(a), 0);

    if (n == 1)
        std::cout << "T\n";
    else if (n == 2)
        std::cout << (a[0] == a[1] ? "HL\n" : "T\n");
    else if (sum < 2 * max)
        std::cout << "T\n";
    else
        std::cout << (sum % 2 == 0 ? "HL\n" : "T\n");
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