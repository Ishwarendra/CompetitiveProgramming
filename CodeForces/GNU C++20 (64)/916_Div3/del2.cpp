#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, int b, int mod = 2) 
{
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) 
    {
        if (b % 2) 
            res = (res % mod) * (a % mod) % mod;
    }
    return res;
}

std::string solve(int m, std::vector<std::string> s)
{
    int ans = 0;
    for (auto word : s)
    {
        int even = 0;
        for (auto ch : word)
            even |= (ch % 2 == 0);

        if (!even)
            ans ^= 1;
    }

    return ans ? "ODD" : "EVEN";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int m, n;
    std::cin >> m >> n;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];

    print(solve(m, s));
    
    return 0;
}