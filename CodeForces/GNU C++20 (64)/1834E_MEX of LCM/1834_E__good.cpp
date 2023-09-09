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

    const i64 LIMIT = 1LL * n * n + 1;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::set<i64> s;
    for (int i = 0; i < n; i++)
    {
        s.emplace(a[i]);
        i64 last = a[i];
        for (int j = i - 1; j >= 0; j--)
        {
            last = std::lcm<i64>(last, a[j]);
            if (last > LIMIT)
                break;
            s.emplace(last);
        }
    }

    i64 mex = 1;
    while (s.count(mex))
        mex++;  

    // print(s)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         i64 lcm = 1;
    //         for (int k = i; k <= j; k++)
    //             lcm = std::lcm(lcm, a[k]);

    //         print(i, j, lcm)
    //     }
    // }

    std::cout << mex << "\n";
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