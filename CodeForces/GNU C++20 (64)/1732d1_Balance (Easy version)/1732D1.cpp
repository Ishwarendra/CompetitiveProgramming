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
    
    int q;
    std::cin >> q;

    std::set<i64> s { 0LL };
    std::map<i64, i64> ans;

    while (q--)
    {
        char ch;
        std::cin >> ch;

        if (ch == '+')
        {
            i64 x;
            std::cin >> x;
            s.emplace(x);
        }
        else
        {
            i64 k;
            std::cin >> k;

            while (s.count(ans[k]))
                ans[k] += k;

            std::cout << ans[k] << "\n";
        }
    }
    
    return 0;
}