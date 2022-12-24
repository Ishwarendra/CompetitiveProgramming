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

    i64 ans = 0;

    for (int i = 0; i < n; i++)  
    {
        std::vector<int> freq(10);
        int distinct = 0;
        for (int j = i; j >= std::max(0, i - 100); j--)
        {
            int cur = s[j] - '0';
            freq[cur]++;
            if (freq[cur] == 1)
                distinct++;

            if (*std::max_element(std::begin(freq), std::end(freq)) <= distinct)
                ans++;
        }
    }

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