#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            std::cin >> ch;
            a[i][j] = ch - '0';
        }
    }

    auto b = a;

    std::vector<std::array<int, 6>> ans;

    auto _2x2 = [&](int x1, int y1, int x2, int y2)
    {
        std::deque<std::pair<int, int>> ones, zeroes;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
                (a[i][j] ? ones : zeroes).emplace_back(i, j);
        }
        
        if (std::ssize(ones) == 4)
        {
            int pos = 0;
            std::array<int, 6> temp{};
            for (auto _ : {0, 0, 0})
            {
                temp[pos] = ones.front().first, temp[pos + 1] = ones.front().second;
                pos += 2;

                zeroes.emplace_back(ones.front());
                ones.pop_front();
            }

            ans.emplace_back(temp);
        }

        if (std::ssize(ones) == 0)
            return;
        
        if (std::ssize(ones) == 1)
        {
            ans.push_back({ones[0].first, ones[0].second, zeroes[0].first, zeroes[0].second, zeroes[1].first, zeroes[1].second});

            zeroes.emplace_back(ones[0]);
            ones.pop_front();
            
            for (int _ : {0, 0})
            {
                ones.emplace_back(zeroes.front());
                zeroes.pop_front();
            }
        }

        if (std::ssize(ones) == 2)
        {
            ans.push_back({ones[0].first, ones[0].second, zeroes[0].first, zeroes[0].second, zeroes[1].first, zeroes[1].second});

            zeroes.emplace_back(ones.front());
            ones.pop_front();

            for (int _ : {0, 0})
            {
                ones.emplace_back(zeroes.front());
                zeroes.pop_front();
            }
        }

        if (std::ssize(ones) == 3)
        {
            ans.push_back({ones[0].first, ones[0].second, ones[1].first, ones[1].second, ones[2].first, ones[2].second});
            for (int _ : {0, 0, 0})
            {
                ones.emplace_back(zeroes.front());
                zeroes.pop_front();
            }
        }
    };

    auto f = [&](int x1, int y1, int x2, int y2)
    {
        int d1 = (x2 - x1 + 1);
        int d2 = (y2 - y1 + 1);
        x2 += d1 % 2;
        y2 += d2 % 2;

        for (int i = x1; i <= x2 - 1; i += 2)
        {
            for (int j = y1; j <= y2 - 1; j += 2)
                _2x2(i, j, i + 1, j + 1);
        }
    };

    auto _2x1 = [&](int x1, int y1, int x2, int y2)
    {
        if (a[x1][y1] == 0 and a[x2][y2] == 0)
            return;
        else if (a[x1][y1] == 1 and a[x2][y2] == 1)
        {
            ans.push_back({x1, y1, x2, y2, x1, y1 + 1});
            a[x1][y1] ^= 1; 
            a[x2][y2] ^= 1;
            a[x1][y1 + 1] ^= 1;
        }
        else if (a[x1][y1] == 1)
        {
            ans.push_back({x1, y1, x1 + 1, y1 + 1, x1, y1 + 1});
            a[x1][y1] ^= 1;
            a[x1 + 1][y1 + 1] ^= 1;
            a[x1][y1 + 1] ^= 1;
        }
        else
        {
            ans.push_back({x2, y2, x1 + 1, y1 + 1, x1, y1 + 1});
            a[x2][y2] ^= 1;
            a[x1 + 1][y1 + 1] ^= 1;
            a[x1][y1 + 1] ^= 1;
        }
    };

    auto _1x2 = [&](int x1, int y1, int x2, int y2)
    {
        if (a[x1][y1] == 0 and a[x2][y2] == 0)
            return;
        else if (a[x1][y1] == 1 and a[x2][y2] == 1)
        {
            ans.push_back({x1, y1, x2, y2, x1 - 1, y1});
            a[x1][y1] ^= 1; 
            a[x2][y2] ^= 1;
            a[x1 - 1][y1] ^= 1;
        }
        else if (a[x1][y1] == 1)
        {
            ans.push_back({x1, y1, x1 - 1, y1, x1 - 1, y1 + 1});
            a[x1][y1] ^= 1;
            a[x1 - 1][y1] ^= 1;
            a[x1 - 1][y1 + 1] ^= 1;
        }
        else
        {
            ans.push_back({x2, y2, x2 - 1, y2, x1 - 1, y1});
            a[x2][y2] ^= 1;
            a[x2 - 1][y2] ^= 1;
            a[x1 - 1][y1] ^= 1;
        }
    }; 

    auto _3x1 = [&](int x)
    {
        _2x1(x, 0, x + 1, 0);
        _2x1(x + 1, 0, x + 2, 0);
    };

    if (n % 2 == 0 and m % 2 == 0)
        f(0, 0, n - 1, m - 1);
    else if (n % 2 == 0)
    {
        for (int x = 0; x < n - 1; x += 2)
            _2x1(x, 0, x + 1, 0);
        for (int y = 1; y < m - 1; y += 2)
            _1x2(n - 1, y, n - 1, y + 1);

        f(0, 1, n - 2, m - 1);
    }
    else if (m % 2 == 0)
    {
        for (int y = 0; y < m - 1; y += 2)
            _1x2(n - 1, y, n - 1, y + 1);
        // for (int x = 1; x < n - 1; x += 2)
        //     _1x2(x, 0, x + 1, 0);

        f(0, 0, n - 2, m - 1);
    }
    else
    {
        _3x1(0);
        for (int x = 3; x < n - 1; x += 2)
            _2x1(x, 0, x + 1, 0);
        for (int y = 1; y < m - 1; y += 2)
            _1x2(n - 1, y, n - 1, y + 1);

        f(0, 1, n - 2, m - 1);
    }

    assert(std::ssize(ans) <= n * m);
    std::cout << std::ssize(ans) << "\n";
    for (auto p : ans)
    {
        for (int i = 0; i < 6; i += 2)
            b[p[i]][p[i + 1]] ^= 1;

        for (auto ele : p)
            std::cout << ele + 1 << " ";
        std::cout << "\n";
    }

    for (auto i : b)
    {
        for (auto j : i)
            assert(j == 0);
    }
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