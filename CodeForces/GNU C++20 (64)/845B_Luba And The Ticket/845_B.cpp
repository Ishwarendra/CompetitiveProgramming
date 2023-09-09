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
    
    std::string s;
    std::cin >> s;

    auto get = [&](std::string t)
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += (i < 3 ? t[i] : -t[i]);

        if (sum != 0)
            return 7;

        int cnt = 0;
        for (int i = 0; i < 6; i++)
            cnt += s[i] != t[i];

        return cnt;
    };

    int ans = 6;
    std::string a;
    std::function<void(int)> f = [&](int id)
    {
        if (id == 6)
        {
            ans = std::min(ans, get(a));
            return;
        }

        for (char ch = '0'; ch <= '9'; ch++)
        {
            a += ch;
            f(id + 1);
            a.pop_back();
        }
    }; f(0);

    std::cout << ans << "\n";
    
    return 0;
}