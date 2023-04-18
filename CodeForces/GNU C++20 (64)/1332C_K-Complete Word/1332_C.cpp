#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int left = 0, right = k - 1;
    int ans = 0;
    while (left <= right) 
    {
        std::array<int, 26> f{};
        for (int j = 0; j < n / k; j++)
        {
            f[s[left + j * k] - 'a']++;
            if (left != right)
                f[s[right + j * k] - 'a']++;
        }

        left++, right--;
        ans += *std::max_element(std::begin(f), std::end(f));
    }

    std::cout << n - ans << "\n";
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