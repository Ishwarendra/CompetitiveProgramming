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
    
    int n, a, b;
    std::string s;
    std::cin >> n >> a >> b >> s;

    s += s;
    i64 ans = 1e18;

    for (int i = 0; i < n; i++)
    {
        int j = i + n - 1;
        int l = i, r = i + n - 1;

        i64 cur = 1LL * i * a;
        while (l < r)
            cur += (s[l++] != s[r--]) * b;

        ans = std::min(ans, cur);
        if (cur == 9)
            print(s.substr(i, n));
    }

    std::cout << ans;
    
    return 0;
}