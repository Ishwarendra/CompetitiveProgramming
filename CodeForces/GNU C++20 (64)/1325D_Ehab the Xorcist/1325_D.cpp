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
    
    i64 u, v;
    std::cin >> u >> v;

    if (((u & 1) != (v & 1)) or v < u)
    {
        std::cout << "-1\n";
        return 0;
    }

    if (u == v)
    {
        if (u == 0)
            std::cout << 0 << "\n";
        else
            std::cout << "1\n" << u << "\n";
        return 0;
    }

    std::vector<i64> ans(3);
    i64 d = v - u;
    ans[0] = u, ans[1] = d / 2, ans[2] = d / 2;

    for (auto f : {u, d / 2})
    {
        i64 first = f;
        i64 second = v - f;

        if ((first ^ second) == u)
            ans = {first, second};
    }

    std::cout << std::size(ans) << "\n";
    for (auto x : ans)
        std::cout << x << " ";
    
    return 0;
}