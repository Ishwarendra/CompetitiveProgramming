#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, d, w;
    std::cin >> n >> k >> d >> w;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++)  
        std::cin >> t[i];

    int vaccine = 0;
    for (int i = 0; i < n;)
    {
        int j = i;
        vaccine++;
        while (j < n and t[j] <= t[i] + w + d and j - i + 1 <= k)
            j++;

        i = j;
    }

    std::cout << vaccine << "\n";
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