#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;
using u128 = __uint128_t;

std::ostream &operator<<(std::ostream &os, i128 x) 
{
    std::string s;
    bool neg = false;
    if (x < 0)
        neg = true, x = -x;
    if (x == 0)
        s = "0";
    
    while (x)
    {
        s += '0' + x % 10;
        x /= 10;
    }

    if (neg)
        s += '-';
    s = std::string(std::rbegin(s), std::rend(s));
    return os << s;
}

i128 sum(i128 a, i128 n, i128 d)
{
    if (n <= 0)
        return 0;
    
    i128 res = a * n;
    res += n * (n + 1) * d / 2;
    res -= d * n;
    
    i128 add = n * (2 * n + 1) * (n + 1) / 6;
    add -= 3 * n * (n + 1) / 2;
    add += 2 * n;
    add /= 2;
    res += add;
    
    return res;
}

i128 ai(i128 a, i128 n, i128 d)
{
    i128 res = a + (n - 1) * d;
    res += (n - 1) * (n - 2) / 2;
    return res;
}

void solve()
{
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    
    int dh = x2 - x1 + 1;
    int dv = y2 - y1 + 1; 

    i128 min = sum(1, dh, 1) + sum(ai(1, dh, 1) + dh + 1, dv - 1, dh + 2); 
    i128 max = sum(1, dv, 2) + sum(ai(1, dv, 2) + dv, dh - 1, dv + 1);
    std::cout << std::max<i128>(0, max - min + 1) << "\n";
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