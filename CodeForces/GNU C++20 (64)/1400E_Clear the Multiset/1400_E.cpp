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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::function<i64(int, int, std::vector<int>)> f;
    f = [&](int l, int r, std::vector<int> b) -> i64
    {
        if (l > r)
            return 0;

        int min = *std::min_element(std::begin(b) + l, std::begin(b) + r + 1);
        int split = -1;
        for (int i = l; i <= r; i++)
        {
            b[i] -= min;
            if (b[i] == 0)
                split = i;
        }

        return std::min(f(l, split - 1, b) + f(split + 1, r, b) + min, r - l + 1LL);
    };

    std::cout << f(0, n - 1, a);
    
    return 0;
}