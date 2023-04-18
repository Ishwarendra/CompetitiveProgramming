#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> rem;
    std::vector ans(n, -1);
    int end = n - 1;
    for (int i = 0; i < m; i++)  
    {
        int x;
        std::cin >> x;        
        if (!rem.contains(x) and end >= 0)
        {
            rem[x] = 0;
            ans[end--] = i + 1;
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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