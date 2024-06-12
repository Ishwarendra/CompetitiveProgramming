#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Some math and find out common terms exist or not
 * How to check if AP have one or more common terms?
 *     If there is a common AP then common difference of AP is lcm(d1, d2)
 *     a1 + x * d1 = a2 (is there any solution for integer x?)
 *     if yes then answer is yes else no
 *     How to find x? Extended euclidean method
 * or Brute force since a and d are small
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 d1, a1, d2, a2;
    std::cin >> d1 >> a1 >> d2 >> a2;
    
    const int N = 1e5;
    std::set<i64> s;
    
    while (std::size(s) <= N)
    {
        s.emplace(a1);
        a1 += d1;
    }

    i64 max = *std::rbegin(s);
    while (a2 <= max)
    {
        if (s.count(a2))
        {
            std::cout << a2;
            return 0;
        }
        
        a2 += d2;
    }
    
    std::cout << -1;
    
    return 0;
}