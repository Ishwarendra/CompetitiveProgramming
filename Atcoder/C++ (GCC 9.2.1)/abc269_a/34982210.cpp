#include <bits/stdc++.h>

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
    
    std::string s = "Takahashi";
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::cout << (a + b) * (c - d) << "\n";
    std::cout << s << "\n";
    
    return 0;
}