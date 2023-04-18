#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::string> a(2 * n - 2);
    for (int i = 0; i < 2 * n - 2; i++)
        std::cin >> a[i];

    auto isPalin = [&](std::string a)
    {
        int i = 0, j = std::ssize(a) - 1;
        while (i < j)
        {
            if (a[i++] != a[j--])
                return false;
        }
        return true;
    };

    std::sort(std::begin(a), std::end(a));
    std::string s1, s2;

    for (int i = 0; i < 2 * n - 2; i++)
    {
        if (std::ssize(a[i]) == n - 1)
        {
            if (s1.empty())
                s1 = a[i];
            else
                s2 = a[i];
        }
    }

    auto get = [](std::string a)
    {
        std::vector<std::string> ans;
        int n = std::size(a);
        for (int i = 0; i < n - 1; i++)
            ans.emplace_back(a.substr(0, i + 1));
        for (int i = n - 1; i > 0; i--)
            ans.emplace_back(a.substr(i));

        std::sort(std::begin(ans), std::end(ans));
        return ans;
    };

    if (get(s1 + s2.back()) == a and isPalin(s1 + s2.back()))
        std::cout << "YES\n";
    else if (get(s2 + s1.back()) == a and isPalin(s2 + s1.back()))
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