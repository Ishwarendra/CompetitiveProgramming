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

    if (k == 1 || n <= 2)
        std::cout << std::string(n, 'a');
    else
    {
        int sz = n;
        std::string ans;
        int i = 0, j = 0;
        while (n > 0)
        {
            ans += char(j + 'a');
            n--;

            if (j != k - 1)
            {
                n--;
                ans += char(i + 'a');
            }
            
            j++;
            if (j == k)
                i = (i + 1) % k, j = i;
        }

        ans = ans.substr(0, sz);
        std::cout << ans;
    }

    return 0;
}