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

    std::vector<std::pair<char, int>> a;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
        {
            a.emplace_back(s[i - 1], cnt);
            cnt = 1;
        }
    }

    if (cnt)
        a.emplace_back(s.back(), cnt), cnt = 0;

    int sz = std::ssize(a);

    i64 ans = 1LL * n * (n - 1) / 2;
    for (int i = 1; i < sz; i++)
        ans -= a[i].second;
    for (int i = sz - 2; i >= 0; i--)
        ans -= a[i].second;

    ans += sz - 1;
    std::cout << ans;
    
    return 0;
}