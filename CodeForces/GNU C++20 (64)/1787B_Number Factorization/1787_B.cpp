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

    auto primeFactor = [&](int x)
    {
        std::map<int, int> m;
        for (int i = 2; 1LL * i * i <= x; i++)
        {
            int count = 0;
            while (x % i == 0)
                x /= i, count++;

            if (count)
                m[i] = count;
        }

        if (x > 1)
            m[x] = 1;

        return m;
    };  

    i64 prod = 0;
    auto m = primeFactor(n);

    while (!m.empty())
    {
        std::vector<int> del;
        i64 cur = 1;
        for (auto &[num, f] : m)
        {
            if (f == 1)
                del.emplace_back(num);

            f--;
            cur *= num;
        }

        prod += cur;
        for (auto x : del)
            m.erase(x);
    }

    std::cout << prod << "\n";
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