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

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int ans = 0;
    for (int j = 0; j < 7; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += (a[i][j] - '0');

        ans = std::max(ans, sum);
    }

    std::cout << ans;
    
    return 0;
}