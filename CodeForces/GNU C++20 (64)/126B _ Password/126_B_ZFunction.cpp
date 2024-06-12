#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * For all prefix which matches suffix find if
 * there exist i > 0 such that some prefix of s[i..n-2] is equal to the prefix we fixed.
 * We don't need to check all prefixes, just two are fine
 * 
 * [xxxx | ..... | xxxx]
 * If longest doesn't match find the longest prefix of "xxxx" which matches suffix.
 * This is guaranteed to exist atleast 4 times in the string.
 * 
 * Z[i] = Longest prefix match between s and s[i..n-1]
 * If for i = 1 to n - 1 we can find any prefix that matches suffix and we have found 
 * a Z value big enough to cover up this prefix then we have found the answer.
 * Iterate on all len and find it out
 */

std::vector<int> zFunction(const std::string &s)
{
    int n = std::size(s);
    std::vector<int> Z(n);
    
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n and s[r] == s[r - l])
                r++;
            r--;
            Z[i] = r - l + 1;
        }
        else
        {
            if (Z[i - l] + i <= r)
                Z[i] = Z[i - l];
            else
            {
                l = i;
                while (r < n and s[r] == s[r - l])
                    r++;
                r--;
                Z[i] = r - l + 1;
            }
        }
    }
    
    return Z;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    int n = std::size(s);
    auto Z = zFunction(s);
    
    int maxZ = 0;
    
    // Z[i] => length of suffix = n - i
    for (int len = 1; len < n; len++)
    {
        if (Z [len] == n - len and maxZ >= n - len)
        {
            std::cout << s.substr(0, n - len);
            return 0;
        }
        
        maxZ = std::max(maxZ, Z[len]);
    }
    
    std::cout << "Just a legend";
    
    return 0;
}