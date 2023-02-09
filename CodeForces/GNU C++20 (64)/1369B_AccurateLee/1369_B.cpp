#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    int start = 0, end = n - 1;
    while (start < n and s[start] == '0')
        start++;
    while (end > start and s[end] == '1')
        end--;

    if (end > start)
        std::cout << std::string(start, '0') + '0' + std::string(end, '0') << "\n";
    else
        std::cout << s << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}