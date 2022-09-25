#include <bits/stdc++.h>
 
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
 
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < 3; ++j)
        {
            int x;
            std::cin >> x;
            cnt += x;
        }
 
        ans += cnt >= 2;
    }
 
    std::cout << ans;
 
    
    return 0;
}