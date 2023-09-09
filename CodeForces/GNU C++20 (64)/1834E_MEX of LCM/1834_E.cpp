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
    s.emplace(a[0]);
    std::vector<i64> prev { a[0] };

    for (int i = 1; i < n; i++)
    {
        std::vector<i64> cur { a[i] } ;
        for (auto x : prev)
        {
            if (std::lcm(x, a[i]) > LIMIT)
                continue;

            cur.emplace_back(std::lcm(x, a[i]));
        }

        s.insert(std::begin(cur), std::end(cur));

        std::sort(std::begin(cur), std::end(cur));
        cur.erase(std::unique(std::begin(cur), std::end(cur)), std::end(cur));

        print(cur)
        std::swap(cur, prev);
    }   

    int mex = 1;
    while (s.count(mex)) 
        mex++;

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