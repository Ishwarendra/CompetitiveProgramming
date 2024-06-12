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
    
    const int N = 2e5 + 1;
    
    std::array<int, N + 2> f{};
    std::array<int, N + 2> pref{}, cnt{};
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        f[a]++;
        pref[a] = f[a] >= 2;
    }
    
    for (int i = 1; i <= N + 1; i++)
        pref[i] += pref[i - 1];
    for (int i = 1; i <= N + 1; i++)
        cnt[i] = f[i] + cnt[i - 1]; 
        
    int ans = 0, st = -1, en = -1;
    for (int i = 1; i <= N; i++)
    {
        if (f[i])
        {
            int left = i + 1, right = N;
            int j = i;
            
            auto good = [&](int mid)
            {
                return pref[mid] - pref[i] == mid - i;  
            };
            
            while (left <= right)
            {
                int mid = std::midpoint(left, right);
                if (good(mid))
                    j = mid, left = mid + 1;
                else
                    right = mid - 1;
            }
            
            int cur_ans = cnt[j] - cnt[i - 1];
            int cur_en = j;
            if (f[j + 1])
                cur_ans++, j++;
            
            if (cur_ans > ans)
            {
                st = i;
                en = cur_en;
                ans = cur_ans;
            }
        }
    }
    
    int num = st;
    std::cout << ans << "\n";
    while (num <= en)
    {
        f[num]--;
        std::cout << num << " "; 
        num++;
    }
    
    while (num >= st)
    {
        while (f[num] > 0)
        {
            std::cout << num << " ";
            f[num]--;
        }
        
        num--;
    }
    
    return 0;
}