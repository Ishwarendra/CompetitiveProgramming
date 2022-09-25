#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif
 
using i64 = long long;
 
void solve()
{
    int n, k, x;
    std::cin >> n >> k >> x;
 
    constexpr int LIMIT = (1 << 10);
 
    std::vector<int> a(LIMIT);
    for (int i = 0; i < n; ++i)  
    {
        int num;
        std::cin >> num;
 
        a[num]++;        
    }
 
    for (int j = 0; j < k; ++j)
    {
        int pos = 0;
        std::vector<int> b = a;
        for (int i = 0; i < (1 << 10); ++i)
        {
            int give = 0;
 
            if (a[i] % 2 == 0)
                give = a[i] / 2;
            else
            {
                if (pos % 2 == 0)
                    give = (a[i] + 1) / 2;
                else
                    give = a[i] / 2;
            }
 
            assert(i < std::size(b) && (i ^ x) < std::size(b));
            b[i] -= give;
            b[i ^ x] += give;
            pos += a[i];
        }
 
        std::swap(a, b);
    }
 
    int max = 0, min = LIMIT;
 
    for (int i = 0; i < LIMIT; i++)
    {
        if (a[i])
        {
            min = std::min(i, min);
            max = std::max(i, max);
        }
    }
 
    std::cout << max << " " << min << "\n";
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    
    while (t--)
        solve();
    
    return 0;
}