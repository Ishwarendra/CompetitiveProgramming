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
    
    int n;    
    std::string s;
    std::cin >> n >> s;

    std::string t;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'n' and i + 1 < n and s[i + 1] == 'a')
            t += "nya", i++;
        else
            t += s[i];
    }

    std::cout << t << "\n";
    
    return 0;
}