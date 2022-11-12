#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> freq(x + 3);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        freq[x]++;
    }

    auto f = [&]()
    {
        for (int i = 1; i <= x; i++)
        {
            if (freq[i] % (i + 1) == 0)
            {
                freq[i + 1] += freq[i] / (i + 1);
                freq[i] = 0;
            }
        }
    }; f(); f();

    for (int i = 1; i < x; i++)
    {
        if (freq[i])
        {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;

    while (t--)
        solve();

    return 0;
}