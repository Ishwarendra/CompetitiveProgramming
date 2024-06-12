#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), p(n);
    for (int i = 0; i < n; i++)
    {  
        std::cin >> a[i];
        p[i] = a[i];
        if (i)
            p[i] ^= p[i - 1];
    }
    
    auto get = [&](int l, int r)
    {
        return (p[r] ^ (l ? p[l - 1] : 0));
    };
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                if ((get(i, j) ^ get(j, k)) > get(i, k))
                    ans++;
            }
        }
    }
    
    std::cout << ans << '\n';
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