#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * If you get a string s, then you have following options:
 *     This string complete and other string complete (or partial)
 *     This string partial (other complete)
 * m[sz][l][sum] => Frequency of having sum = sum, when you are considering prefix of length l (and string size is sz)
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto digitSum = [&](std::string & s)
    {
        int res = 0;
        for (auto ch : s)
            res += ch - '0';
        return res;
    };

    auto get = [&]()
    {
        std::map<int, int> m[6][6] {};
        i64 ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto s = a[i];
            int sz = std::size(s);
            int sum = digitSum(s);
            
            for (int len = 1; len <= 5; len++)
            {
                if ((len + sz) % 2)
                    continue;

                int x = (len + sz) / 2;
                if (sz <= x)
                {
                    int need = x - sz;
                    ans += m[len][len - need][sum];
                }
                else
                {
                    int need = sz - x;
                    int sumNeeded = -sum;
                    for (int id = need; id < sz; id++)
                        sumNeeded += 2 * (s[id] - '0');

                    ans += m[len][len][sumNeeded];
                }
            }

            for (int len = sz; len > 0; len--)
            {
                m[sz][len][sum]++;
                sum -= 2 * (s[len - 1] - '0');
            }
        }
        
        return ans;
    };
    
    i64 ans = n + get();
    std::reverse(std::begin(a), std::end(a));
    ans += get();
    std::cout << ans << "\n";

    return 0;
}