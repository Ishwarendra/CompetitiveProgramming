#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    auto query = [&](int last, int cur)
    {
        if (last == -1)
            last = 0;

        std::cout << (last ^ cur) << std::endl;
        int r;
        std::cin >> r;
        return r;
    };

    for (int i = 0; i < n; i++)
    {
        int r = query(i - 1, i);
        if (r)
            return;
    }

    assert(false);
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