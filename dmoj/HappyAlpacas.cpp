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
    
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    if ((n - x) < 0 or (n - x) % 2)
    {
        std::cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
    
    return 0;
}