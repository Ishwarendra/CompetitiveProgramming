#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Use greedy for E1. Keep making new strings if you cannot add in any of
 * the existing string.
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s;
    std::cin >> n >> s;
    
    std::vector<std::string> ans(1);
    std::vector<int> col;
    for (int i = 0; i < n; i++)
    {
        int ok = 0, id = 0;
        for (auto &t : ans)
        {
            if (t.empty() or t.back() <= s[i])
            {
                col.emplace_back(id);
                t += s[i];
                ok = 1;
                break;
            }
            
            id++;
        }
        
        if (!ok)
        {
            col.emplace_back(id);
            ans.emplace_back(std::string(1, s[i]));
        }
    }
    
    std::cout << std::size(std::set(std::begin(col), std::end(col))) << "\n";
    for (int i = 0; i < n; i++)
        std::cout << col[i] + 1 << " \n"[i == n - 1];
    
    return 0;
}