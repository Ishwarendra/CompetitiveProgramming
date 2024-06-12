#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n * 2);
    for (int i = 0; i < n * 2; i++)
        std::cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (a[i] == a[i + 1])
            continue;
        
        int j = i + 1;
        while (j < 2 * n and a[j] != a[i])
            j++;
        
        ans += j - i - 1;                
        while (j > i)
        {
            std::swap(a[j], a[j - 1]);
            j--;
        }

    }
    
    std::cout << ans;
    
    return 0;
}