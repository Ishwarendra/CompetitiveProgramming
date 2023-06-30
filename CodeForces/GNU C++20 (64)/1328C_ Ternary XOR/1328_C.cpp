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

    std::string a = "1", b = "1";
    bool started = false;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
            a += '0', b += '0';
        else if (s[i] == '1')
        {
            if (started)
                a += '0', b += '1';
            else
                a += '1', b += '0', started = true;
        }
        else
        {
            if (started)
                a += '0', b += '2';
            else
                a += '1', b += '1';
        }
    }

    std::cout << a << "\n" << b << "\n";
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