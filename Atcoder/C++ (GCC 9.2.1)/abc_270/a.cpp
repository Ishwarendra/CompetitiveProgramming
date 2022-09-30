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
    
    int a, b;
    std::cin >> a >> b;

    int ans = 0;
    auto getBit = [&](int x, int pos)
    {
        return (x >> pos) & 1;
    };

    for (int i = 0; i < 3; i++)
    {
        if (getBit(a, i) or getBit(b, i))
            ans |= (1 << i);
    }

    std::cout << ans;
    
    return 0;
}