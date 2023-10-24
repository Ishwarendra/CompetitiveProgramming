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
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    for (int i = 0; i < n / 2; i++)
        std::swap(s[2 * i], s[2 * i + 1]);

    std::cout << s;
    
    return 0;
}