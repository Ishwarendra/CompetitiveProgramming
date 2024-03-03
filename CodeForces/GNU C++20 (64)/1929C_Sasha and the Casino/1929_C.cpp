#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int k, x, a;
    std::cin >> k >> x >> a;

    i64 loss = 0;
    for (int i = 0; i <= x; i++)
    {
    	i64 y = loss / (k - 1) + 1;
    	loss += y;

    	if (loss > a)
    	{
    		std::cout << "NO\n";
    		return;
    	}
    }

    std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}