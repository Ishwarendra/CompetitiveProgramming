#include "bits/stdc++.h"

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
    
    int n, m;;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::vector<int> ans(m);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];

        for (int j = 0; j < m; j++)
            ans[j] += a[i][j] == '#';
    }

    for (int i = 0; i < m; i++)
        std::cout << ans[i] << " \n"[i == m - 1];
    
    return 0;
}