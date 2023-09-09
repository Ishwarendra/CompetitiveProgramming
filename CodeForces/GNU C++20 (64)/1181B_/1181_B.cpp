#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string add(std::string s, std::string t)
{
    std::reverse(std::begin(s), std::end(s));
    while (std::size(s) < std::size(t))
        s += '0';
    std::reverse(std::begin(s), std::end(s));

    std::reverse(std::begin(t), std::end(t));
    while (std::size(t) < std::size(s))
        t += '0';
    std::reverse(std::begin(t), std::end(t));

    int carry = 0;
    std::string ans;

    int n = std::size(s);
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = s[i] + t[i] - 2 * '0' + carry;
        carry = sum / 10;
        sum %= 10;
        ans += std::to_string(sum);
    }

    if (carry)
        ans += std::to_string(carry);

    std::reverse(std::begin(ans), std::end(ans));

    return ans;
}

auto custom_min(std::string s, std::string t)
{
    if (std::size(s) == std::size(t))
        return std::min(s, t);
    else if (std::size(s) < std::size(t))
        return s;

    return t;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n;
    std::string s;
    std::cin >> n >> s;

    std::string a, b;
    i64 i = n / 2;
    for (; i >= 0; i--)
    {
        if (s[i] != '0')
        {
            a = s.substr(0, i);
            b = s.substr(i);
            break;
        }
    }

    auto ans = add(a, b);
    print(ans, a, b)
    i = n / 2 + 1;
    for (; i < n; i++)
    {
        if (s[i] != '0')
        {
            a = s.substr(0, i);
            b = s.substr(i);
            break;
        }
    }   

    ans = custom_min(ans, add(a, b));
    std::cout << ans;
    
    return 0;
}