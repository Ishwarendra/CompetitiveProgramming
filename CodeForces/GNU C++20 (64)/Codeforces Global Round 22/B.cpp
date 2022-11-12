#include <bits/stdc++.h>

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

    std::vector<int> s(k);
    for (int i = 0; i < k; i++)  
        std::cin >> s[i];

    if (k == 1)
    {
        std::cout << "Yes\n";
        return;
    }

    std::vector<int> a(n);
    int st = n - k + 1;

    for (int i = 0; i < k - 1; i++)
    {
        a[st + i] = s[i + 1] - s[i]; 
        if (i and a[st + i] < a[st + i - 1])
        {
            std::cout << "No\n";
            return;
        }
    }

    if (1LL * (n - k + 1) * a[n - k + 1] >= s[0])
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
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