#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * If we have only two sides then answer is (a_1 + a_2) / 3
 * If we have more than two sides we can still make sum(a) / 3 sides (unless one side dominates):
 * If (max side) > 2 * (sum of rest) then cannot make more than sum of rest
 *     Take one point from "sum of rest" and two points from "max side"
 * else sum(a) / 3
 *     If max side = 1 then you can make 1 triangle (atmost)
 *     If max side > 1 then you can choose two points from a_i (let say leftmost) and 1 from it's neighbor (closest to a_i points)
 *     Total points decrease by 3 and you have new polygon now (remove the area covered by triangle or behind it)
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
    int max = *std::max_element(std::begin(a), std::end(a));
    
    if (max > 2 * (sum - max))
        std::cout << sum - max;
    else
        std::cout << sum / 3;
    
    return 0;
}