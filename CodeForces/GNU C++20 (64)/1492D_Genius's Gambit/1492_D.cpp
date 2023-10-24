#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string add(std::string a, std::string b)
{
    std::string c;
    std::reverse(std::begin(a), std::end(a));
    std::reverse(std::begin(b), std::end(b));

    int n = std::size(a);
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = carry + a[i] + b[i] - 2 * '0';
        carry = sum / 2;
        sum &= 1;
        c += char(sum + '0');
    }

    std::reverse(std::begin(c), std::end(c));
    return c;
}

auto checkCount(std::string s, int cnt)
{
    return std::count(std::begin(s), std::end(s), '1') == cnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, k;
    std::cin >> a >> b >> k;
    int n = a + b;

    if (b == 1)
    {
        if (k != 0)
            std::cout << "No";
        else
        {
            std::cout << "Yes\n";
            std::string s(n, '0');
            s[0] = '1';
            std::cout << s << "\n" << s << "\n";
        }
    }
    else if (a == 0)
    {
        if (k != 0)
            std::cout << "No";
        else
            std::cout << "Yes\n" << std::string(n, '1') << "\n" << std::string(n, '1');
    }
    else if (k > a + b - 2)
        std::cout << "No";
    else
    {
        std::string X(n, '0'), Y(n, '0');
        for (int i = 0; i < b; i++)
            X[i] = Y[i] = '1';

        int id = n - 1 - k;
        if (k > a)
            std::swap(Y[id], Y.back());
        else
            std::swap(Y[Y.find('0') + k - 1], Y[b - 1]);

        std::cout << "Yes\n";
        std::cout << X << "\n" << Y;
    }

    return 0;
}