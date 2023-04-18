#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool valid(std::string a, std::string b)
{
    auto check = [&](std::string s)
    {
        for (int i = 1; i < std::ssize(s); i++)
        {
            if (s[i] == s[i - 1])
                return false;
        }

        return true;
    };

    if (check(a) and check(b))
        return true;

    while (std::size(b) > 1)
    {
        a.push_back(b.back());
        b.pop_back();

        if (check(a) and check(b))
            return true;
    }

    return false;
}

void solve()
{
    int n, m;
    std::string a, b;
    std::cin >> n >> m >> a >> b;

    if (valid(a, b) or valid(b, a))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}