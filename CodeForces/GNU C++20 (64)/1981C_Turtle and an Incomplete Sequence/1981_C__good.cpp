#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * -1...-1 a -1...-1
 * multiply and divide alternately
 * a -1 -1 ... -1 -1 b
 * Some multiply by 2 + 0/1, some divide by 2 and take floor
 * to reach from a to b
 * Case-1: a = b (number of -1 should be odd)
 * Case-2: a > b, if b > a swap and apply reverse operation
 * Divide a and b by 2 until they become 1.
 * Find intersection point to find out the numbers that can fit in between
 * Repeat by multiply divide if needed
 */

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), pos;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] != -1)
            pos.emplace_back(i);
    }
    
    if (pos.empty())
    {
        for (int i = 0; i < n; i++)
            std::cout << (i % 2) + 1 << " \n"[i == n - 1];
        return;
    }
    
    auto work = [&](int L, int R)
    {
        if (R - L - 1 <= 0)
            return 1;
        
        int x = a[L], y = a[R];
        if (x == y)
        {   
            for (int i = L; i < R; i += 2)
            {
                a[i] = a[L];
                if (i + 1 < R)
                    a[i + 1] = a[L] * 2;
            }

            return 1;
        }
        
        std::vector<int> nums1, nums2, nums;
        
        int rev = 0;
        if (x < y)
        {
            std::swap(x, y);
            rev = 1;
        }
        
        while (x > 1)
        {
            x /= 2;
            nums1.emplace_back(x);
            if (x == y)
                break;
        }
        
        while (y > 1 and x != y)
        {
            y /= 2;
            nums2.emplace_back(y);
        }
        
        x = 1;
        for (int i = 0; i < std::size(nums1); i++)
        {
            nums.emplace_back(nums1[i]);
            if (std::binary_search(std::begin(nums2), std::end(nums2), nums1[i], std::greater<int>()))
            {
                x = nums1[i];
                break;
            }
        }
        
        int id = std::size(nums);
        
        for (int i = 0; i < std::size(nums2) and nums2[i] != x; i++)
            nums.emplace_back(nums2[i]);
        if (!nums.empty() and nums.back() == std::min(a[L], a[R]))
            nums.pop_back();

        if (id < std::size(nums))
            std::reverse(std::begin(nums) + id, std::end(nums));
        
        int sz = std::size(nums), len = R - L - 1;
        if (len < sz)
            return -1;
        if ((len - sz) % 2)
            return -1;
        
        if (rev)
            std::reverse(std::begin(a) + L, std::begin(a) + R + 1);
        print(a)
        for (int i = L + 1, turn = 1; i < R; i++)
        {
            if (i - L - 1 < sz)
                a[i] = nums[i - L - 1];
            else
            {
                if (turn)
                    a[i] = a[i - 1] * 2;
                else
                    a[i] = a[i - 1] / 2;
                
                turn ^= 1;
            }
        }
        
        if (rev)
            std::reverse(std::begin(a) + L, std::begin(a) + R + 1);
        return 1;
    };
    
    for (int i = 1; i < std::size(pos); i++)
    {
        auto res = work(pos[i - 1], pos[i]);
        if (res == -1)
        {
            std::cout << "-112\n";
            return;
        }
    }
    
    int turn = 1;
    for (int i = pos.front() - 1; i >= 0; i--, turn ^= 1)
    {
        if (turn)
            a[i] = a[i + 1] * 2;
        else
            a[i] = a[i + 1] / 2;
    }
    
    turn = 1;
    for (int i = pos.back() + 1; i < n; i++, turn ^= 1)
    {
        if (turn)
            a[i] = a[i - 1] * 2;
        else
            a[i] = a[i - 1] / 2;
    }

    print(a)
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1] / 2 and a[i + 1] != a[i] / 2)
        {
            std::cout << "-112\n";
            return;
        }
        
        if (a[i] <= 0)
        {
            std::cout << "-112\n";
            return;
        }
    }
    
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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