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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<i64> closed(n);
    i64 ans = (b.back() + k - 1) / k;
    closed[n - k] = ans;
    i64 sum = ans * k, cnt = ans;

    for (int i = n - 1; i >= 0; i--)
    {
        b[i] -= sum;
        if (b[i] > 0)
        {
            if (i + 1 - k < 0)
                k = i + 1;

            i64 add = (b[i] + k - 1) / k;
            sum += add * k;
            ans += add;

            cnt += add;
            closed[i + 1 - k] += add;
        }

        sum -= cnt;
        cnt -= closed[i];
    }

    std::cout << ans;
    
    return 0;
}