#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Operate in reverse fashion
 * In i^th operation pick a number such p_i (p_i + l_i - 1 < n)
 * Color all uncolored cells in color-i
 * 
 * Case: No need to color all cells, just need all color once
 * Try to paint as right as possible.
 * 
 * Case: Color all cells
 * When paint non-rightmost?
 *     when you cannot paint all left cells using given colors.
 *     When is that not possible?
 *         When sum(l[0..i]) is less than x (x is rightmost uncolored cell)
 *     If it is not possible then try to go left (but how much left should we go? Just keep a pointer and keep moving backward while checking if this point is ok or not)
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> l(m);
    for (int i = 0; i < m; i++)
        std::cin >> l[i];
    
    std::vector<i64> p(m + 1);
    for (int i = 0; i < m; i++)
        p[i + 1] = p[i] + l[i];
    
    int funcolored = n; // first un colored
    std::vector<int> ans(m);
    
    for (int i = m - 1; i >= 0; i--)
    {
        auto good = [&](int mid)
        {
            bool res = mid <= funcolored and funcolored <= mid + l[i] - 1;
            res = res and p[i] >= mid - 1;
            return res;
        };
        
        int rightmost = std::min(n - l[i] + 1, funcolored);
        while (rightmost >= 0 and !good(rightmost))
            rightmost--;
        
        if (rightmost <= 0)
        {
            std::cout << -1;
            return 0;
        }
        
        ans[i] = rightmost;
        funcolored = rightmost - 1;
    }
    
    for (int i = 0; i < m; i++)
        std::cout << ans[i] << " \n"[i == m - 1];
    
    return 0;
}