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
    
    int n, m, k;
    std::cin >> n >> m >> k;
    int k_ = k;

    if (k > 4 * m * n - 2 * n - 2 * m || (n == m and n == 1))
    {
        std::cout << "NO";
        return 0;
    }

    std::cout << "YES\n";
    std::vector<std::pair<std::string, int>> ans;
    if (n == 1 || m == 1)
    {
        int sub = std::min(k, std::max(n, m) - 1);
        ans.emplace_back((n == 1 ? "R" : "D"), sub);
        k -= sub;
        sub = std::min(k, std::max(n, m) - 1);
        ans.emplace_back((n == 1 ? "L" : "U"), sub);
    }
    else
    {
        int row = 1;
        while (k > 0 and row < n)
        {
            for (std::string s : {"R", "D", "ULD"})
            {
                if (k == 0)
                    break;

                if (s == "R")
                {
                    int sub = std::min(k, m - 1);
                    ans.emplace_back(s, sub);
                    k -= sub;
                }
                else if (s == "D")
                    ans.emplace_back(s, 1), k--;
                else
                {
                    int can = std::min(m - 1, k / 3);
                    ans.emplace_back(s, can);
                    k -= can * 3;

                    if (can != m - 1 and 0 < k and k < 3)
                        ans.emplace_back(s.substr(0, k), 1), k = 0;
                }
            }

            row++;
        }

        if (k > 0)
        {
            assert(row == n);
            int sub = std::min(k, m - 1);
            ans.emplace_back("R", sub);
            k -= sub;

            for (std::string s : {"L", "U"})
            {
                int max = (s == "L" ? m - 1 : n - 1);
                sub = std::min(max, k);
                ans.emplace_back(s, sub);    
                k -= sub;   
            }
        }
    }

    int cnt = std::size(ans);
    for (auto &[s, f] : ans)
        cnt -= (f == 0);
    std::cout << cnt << "\n";
    assert(cnt <= 4000);
    int s_ = 0;
    for (auto &[s, f] : ans)
    {
        s_ += f * std::size(s);
        if (f == 0)
            continue;
        std::cout << f << " " << s << "\n"; 
    }

    // assert(s_ == k_);

    return 0;
}