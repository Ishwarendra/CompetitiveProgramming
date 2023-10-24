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

    std::multiset<std::pair<int, int>, std::greater<>> start;
    std::multiset<std::pair<int, int>> end;
    while (q--)
    {
        char type;
        int l, r;
        std::cin >> type >> l >> r;

        if (type == '+')
        {
            end.emplace(r, l);
            start.emplace(l, r);
        }
        else
        {
            end.erase(end.find({r, l}));
            start.erase(start.find({l, r}));
        }

        if (std::begin(end)->first < std::begin(start)->first)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    
    return 0;
}