#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string LongestPalindromicPrefix(std::string str)
{
    std::string temp = str + '#';
    std::reverse(str.begin(), str.end());
 
    temp += str;
    
    int n = std::size(temp); 
    int lps[n];
 
    std::fill(lps, lps + n, 0);
    for (int i = 1; i < n; i++) 
    {
        int len = lps[i - 1];
        while (len > 0 && temp[len] != temp[i])
            len = lps[len - 1];
 
        if (temp[i] == temp[len]) 
            len++;
        lps[i] = len;
    }
    
    return temp.substr(0, lps[n - 1]);
}

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (s[i] == s[j])
            i++, j--;
        else
            break;
    }

    if (i == j)
    {
        std::cout << s << "\n";
        return;
    }

    auto mid = std::string(std::begin(s) + i, std::begin(s) + j + 1);
    auto t1 = LongestPalindromicPrefix(mid);

    std::reverse(std::begin(mid), std::end(mid));
    auto t2 = LongestPalindromicPrefix(mid);

    if (std::size(t1) < std::size(t2))
        std::swap(t1, t2);

    std::string ans;

    for (int id = 0; id < i; id++)
        ans += s[id];

    ans += t1;

    for (int id = j + 1; id < n; id++)
        ans += s[id];

    std::cout << ans << "\n";
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