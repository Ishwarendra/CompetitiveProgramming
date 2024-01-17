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
    std::string s;
    std::cin >> n >> s;

    int cnt = std::count(std::begin(s), std::end(s), '1');
    if (cnt % 2 or cnt == 0)
    {
        std::cout << "NO\n";
        return;
    }

    int id = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' and s[(i + 1) % n] == '0')
            id = (i + 1) % n;
    }
    std::cout << "YES\n";

    int u = id;
    bool new_start = true;

    for (int i = (id + 1) % n; i != id; i = (i + 1) % n)
    {
        if (new_start)
            std::cout << 1 + id << " " << 1 + i << "\n";
        else
        {
            std::cout << 1 + u << " " << 1 + i << "\n";
            new_start = true;
        }

        u = i;
        if (s[i] == '0')
            new_start = false;
    }
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