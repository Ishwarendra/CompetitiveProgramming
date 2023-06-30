#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::map<char, char> m { {'1', 'l'}, {'l', '1'}, {'0', 'o'}, {'o', '0'} };
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i] and m[s[i]] != t[i])
        {
            std::cout << "No";
            return 0;
        }
    }

    std::cout << "Yes";
    
    return 0;
}