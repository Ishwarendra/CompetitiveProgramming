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
    std::string r, c;
    std::cin >> n >> r >> c;

    auto check = [&](std::vector<std::string> a)
    {
        for (int j = 0; j < n; j++)
        {
            std::array<int, 3> cnt{};
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] == '.')
                    continue;
                cnt[a[i][j] - 'A']++;
            }
            if (cnt[0] == cnt[1] and cnt[1] == cnt[2] and cnt[0] == 1);
            else
                return false;
        }

        std::string left, top;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == '.')
                    continue;
                left += a[i][j];
                break;
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] == '.')
                    continue;
                top += a[i][j];
                break;
            }
        }

        return left == r and top == c;
    };

    auto canPlace = [&](std::string &s, char ch)
    {
        if (ch == '.')
            return std::count(std::begin(s), std::end(s), '.') < n - 3;

        return s.find(ch) == std::string::npos;
    };

    std::pair<bool, std::vector<std::string>> ans{};
    std::vector a(n, std::string(n, '!'));
    
    auto f = [&](auto &&self, int x, int y)
    {
        if (x == n or ans.first)
        {
            if (check(a) and !ans.first)
                ans = {true, a};
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[x][i] == '.' or a[x][i] == '!')
                continue;

            if (a[x][i] != r[x])
                return;
            break;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i][y] == '.' or a[i][y] == '!')
                continue;

            if (a[i][y] != c[y])
                return;
            break;
        }

        for (auto ch : {'.', 'A', 'B', 'C'})
        {
            if (canPlace(a[x], ch))
            {
                a[x][y] = ch;

                if (y + 1 == n)
                    self(self, x + 1, 0);
                else
                    self(self, x, y + 1);

                a[x][y] = '!';
            }
        }
    }; f(f, 0, 0);

    if (ans.first)
    {
        std::cout << "Yes\n";
        for (auto s : ans.second)
            std::cout << s << "\n";
    }
    else
        std::cout << "No";

    return 0;
}