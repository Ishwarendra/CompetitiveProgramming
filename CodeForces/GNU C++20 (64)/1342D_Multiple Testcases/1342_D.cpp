#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Start from biggest length array and add until you can.
 * c_k => for Length k
 * c_{k-1} - c_k + (extra) => for Length k - 1
 * extra comes form unused length k array
 * and so on...
 * To find which element you put in answer next, use binary search.
 * Rightmost element `r` such that `c[r] - tot_add_till_now > 0` and freq[r] > 0
 */

template <typename T>
struct Fenwick 
{
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) { init(n_); }
    template <class G>
    Fenwick(const std::vector<G> in) : Fenwick(std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }
    
    void init(int n_) 
    {
        n = n_;
        a.assign(n, T{});
    }


    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) 
            a[i - 1] = a[i - 1] + v;
    }
    
    T sum(int x) 
    {
        T ans{};
        for (int i = x + 1; i > 0; i -= i & -i) 
            ans = ans + a[i - 1];
        return ans;
    }
    
    T rangeSum(int l, int r) 
    { 
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1); 
    }
};

struct Ans
{
    std::vector<int> a;
    void emplace_back(int x) { a.emplace_back(x); }
    void disp()
    {
        int n = std::size(a);
        std::cout << n << " ";
        for (int i = 0; i < n; i++)
            std::cout << a[i] << " \n"[i == n - 1];
    }  
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> c(k + 2);
    Fenwick<int> m(k + 1);
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        m.add(a, 1);
    }
    
    for (int i = 1; i <= k; i++)
        std::cin >> c[i];
    
    std::vector<Ans> ans;
    int total = 0, start = k;
    
    while (total < n)
    {
        ans.emplace_back();
        int sub = 0;
        while (start > 0 and m.rangeSum(start, start) == 0)
            start--;
        
        for (int num = start; num >= 1; )
        {
            int left = 1, right = num - 1;
            int next = 0;
            
            while (left <= right)
            {
                int mid = std::midpoint(left, right);
                if (c[mid] - sub > 0 and m.rangeSum(mid, num) > m.rangeSum(num, num))
                    next = mid, left = mid + 1;
                else
                    right = mid - 1;
            }
            
            int have = std::min(m.rangeSum(num, num), c[num] - sub);
            have = std::max(0, have);
            
            sub += have;
            total += have;
            m.add(num, -have);
            for (int i = 0; i < have; i++)
                ans.back().emplace_back(num);
            
            num = next;
        }
    }
    
    std::cout << std::size(ans) << "\n";
    for (auto &a : ans)
        a.disp();
    
    return 0;
}