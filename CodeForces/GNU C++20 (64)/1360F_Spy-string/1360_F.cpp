#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::set<std::string> a;
    for (int i = 0; i < n; i++)  
    {
        std::string s;
        std::cin >> s;
        a.emplace(s);
    }

    auto check = [&](const std::string &s)
    {
        if (std::size(s) != m)
            return false;

        for (auto x : a)
        {
            int cnt = 0;
            for (int i = 0; i < m; i++)
                cnt += x[i] != s[i];

            if (cnt > 1)
                return false;
        }

        return true;
    };

    std::string s, ans;

    std::function<void(int, int)> f = [&](int id, int done)
    {
        if (id == m)
        {
            if (check(s))
                ans = s;
            return;
        }

        std::set<char> alphabets;
        for (const auto &x : a)
            alphabets.emplace(x[id]);

        done += (std::size(alphabets) > 3);
        if (done > 2)
            return;

        for (auto ch : alphabets)
        {
            s += ch;
            f(id + 1, done);
            s.pop_back();
        }
    }; f(0, 0);

    if (check(ans))
        std::cout << ans << '\n';
    else
        std::cout << "-1\n";
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