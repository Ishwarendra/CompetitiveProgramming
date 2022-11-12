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

    int q = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'Q')
            q++;
        else
        {
            if (q)
                q--;
        }
    }

    std::cout << (q ? "No\n" : "Yes\n");
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