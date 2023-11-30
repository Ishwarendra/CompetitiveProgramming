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
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int one = std::count(std::begin(s), std::end(s), '1');
    int zero = n - one;

    int st = (1 << one);
    int end = (1 << n) - (1 << zero) + 1;

    for (int i = st; i <= end; i++)
        std::cout << i << " \n"[i == end];
    
    return 0;
}