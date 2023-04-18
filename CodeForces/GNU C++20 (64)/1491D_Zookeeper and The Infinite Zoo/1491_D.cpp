#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int u, v;
    std::cin >> u >> v;

    if (u > v)
    {
        std::cout << "NO\n";
        return;
    }

    int remove = 0;

    auto getBit = [&](int x, int pos) { return (x >> pos) & 1; };

    for (int pos = 0; pos < 30; pos++)
    {
        if (getBit(u, pos) and getBit(v, pos))
            continue;

        if (getBit(u, pos) and !getBit(v, pos))
            remove++;
        else if (!getBit(u, pos) and getBit(v, pos))
        {
            if (remove > 0)
                remove--;
            else
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
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