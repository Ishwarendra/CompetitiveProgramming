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
    std::cin >> n;

    if (n == 1)
    {
        std::cout << "a\n";
        return;
    }

    int count = n / 2 - 1;
    std::string ans; 

    if (count > 0)
        ans += std::string(count, 'a');  

    int rem = n - 2 * std::max(0, count) - 1;

    for (int i = 1; i < 26 and rem > 0; i++, rem--) 
        ans += char('a' + i);

    if (count + 1 > 0)
        ans += std::string(count + 1, 'a');

    std::cout << ans << "\n";
    assert(std::ssize(ans) == n);
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