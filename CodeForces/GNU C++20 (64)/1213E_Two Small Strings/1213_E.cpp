#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    auto check = [&](std::string ans)
    {
        int ok = 1;
        for (int i = 1; i < 3 * n; i++)
        {
            for (auto &p : {s, t})
            {
                if (p[0] == ans[i - 1] and p[1] == ans[i])
                    ok = 0;
            }
        }

        return ok;
    };

    std::string a = "abc";
    do
    {
        std::string ans;
        for (int i = 0; i < n; i++)
            ans += a;

        if (check(ans))
        {
            std::cout << "YES\n" << ans;
            return 0;
        }

        ans.clear();
        for (char ch : a)
            ans += std::string(n, ch);

        if (check(ans))
        {
            std::cout << "YES\n" << ans;
            return 0;
        }

    } while (std::next_permutation(std::begin(a), std::end(a)));

    std::cout << "NO";
    
    return 0;
}