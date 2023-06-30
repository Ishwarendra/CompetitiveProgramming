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
    
    std::string s, t;
    std::cin >> s >> t;

    int n = std::size(s), m = std::size(t);
    std::vector<int> pref(m), suff(m);

    for (int i = 0, j = 0; i < n and j < m; i++)
    {
        if (s[i] == t[j])
            pref[j++] = i;
    }

    for (int i = n - 1, j = m - 1; i >= 0 and j >= 0; i--)
    {
        if (s[i] == t[j])
            suff[j--] = i;
    }

    int ans = std::max(suff[0], n - pref.back() - 1);
    for (int i = 0; i < m - 1; i++)
        ans = std::max(ans, suff[i + 1] - pref[i] - 1);


    std::cout << ans;
    
    return 0;
}