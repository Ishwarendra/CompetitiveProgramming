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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    std::map<int, int> freq;
    i64 ans = 0;
    int b = 0, s = 0;
    for (int i = pos[m - 1]; i < n; i++)
    {
        b += a[i] > (m - 1);
        s += a[i] < (m - 1);
        freq[b - s]++;
    }

    b = 0, s = 0;
    for (int i = pos[m - 1]; i >= 0; i--)
    {   
        b += a[i] > (m - 1);
        s += a[i] < (m - 1);
        int diff = b - s;
        ans += freq[-diff] + freq[1 - diff];
    }

    std::cout << ans;
    
    return 0;
}