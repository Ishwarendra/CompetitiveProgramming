#include <bits/stdc++.h>

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
    
    i64 n;
    std::cin >> n;

    std::vector<int> set_bits;
    for (int i = 0; i < 61; ++i)
    {
        if ((n >> i) & 1LL)
            set_bits.emplace_back(i);
    }

    std::vector<i64> subset, ans;
    std::function<void(int)> f = [&](int i)
    {
        if (i == std::size(set_bits))
        {
            i64 x = 0;
            for (auto bit : subset)
                x |= (1LL << bit);

            ans.emplace_back(x);
            return;
        }

        subset.emplace_back(set_bits[i]);
        f(i + 1);
        subset.pop_back();
        f(i + 1);
    };

    f(0);
    std::sort(std::begin(ans), std::end(ans));
    for (auto x : ans)
        std::cout << x << "\n";

    return 0;
}