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
    for (int i = 0; i + 1 < n; i++)
    {
        if (s[i + 1] < s[i])
        {
            std::cout << "NO";
            return 0;
        }
    }

    int a = std::count(std::begin(s), std::end(s), 'a');
    int b = std::count(std::begin(s), std::end(s), 'b');
    int c = std::count(std::begin(s), std::end(s), 'c');

    if (a == 0 || b == 0 || (c != a and c != b))
        std::cout << "NO";
    else
        std::cout << "YES";
    
    return 0;
}