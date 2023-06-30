#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using l64 = long double;
using i128 = __int128;
using u128 = __uint128_t;

std::ostream &operator<<(std::ostream &os, i128 n) 
{
    std::string s;
    while (n) 
    {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

std::istream& operator >>(std::istream &is, i128 &T) 
{
    static char buffer[64];
    is >> buffer; 
    size_t len = strlen(buffer), index = 0; 
    T = 0; 
    int mul = 1;

    if (buffer[index] == '-') 
        ++index, mul *= -1; 
    for (; index < len; ++index) 
        T = T * 10 + static_cast<int>(buffer[index] - '0'); 
    T *= mul; 

    return is;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i128 k, d, t;
    std::cin >> k >> d >> t;

    i128 x = (k + d - 1) / d;
    if (x != 0)
        d *= x;

    i128 ans = 2 * t / (k + d);
    auto rem = 2 * t - ans * (k + d);
    int odd = 0;
    
    ans *= d;
    if (rem <= 2 * k)
        ans += rem / 2, odd = rem % 2;
    else
    {
        rem -= 2 * k;
        ans += rem + k;
    }

    std::cout << ans;
    if (odd)
        std::cout << ".5";
    else
        std::cout << ".0";
        
    return 0;
}