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

    std::vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int d;
        std::cin >> d;

        for (int j = 1; j <= d; j++)
            a.emplace_back(j);
    }

    a.insert(std::end(a), std::begin(a), std::end(a));

    int ans = 0;
    for (int i = 0; i < std::size(a) / 2; i++)
    {
        int sum = 0;
        for (int j = i; j < i + x; j++)
            sum += a[j];

        ans = std::max(ans, sum);
        if (sum == 53)
            print(i, std::vector(std::begin(a) + i, std::begin(a) + i + x));
    }

    std::cout << ans;
    
    return 0;
}