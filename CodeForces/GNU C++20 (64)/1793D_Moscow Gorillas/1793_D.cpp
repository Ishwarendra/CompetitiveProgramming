#include "bits/stdc++.h"

#undef LOCAL

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool between(auto x, auto l, auto r)
{
    return l <= x and x <= r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    auto get_pos = [&](auto &x)
    {
        std::vector<int> pos(n);
        for (int i = 0; auto &ele : x)
            pos[--ele] = i++;

        return pos;
    };

    std::vector<int> pos[2], min[2], max[2];
    pos[0] = get_pos(a), pos[1] = get_pos(b);
    
    for (int i = 0; i < 2; i++)
    {
        min[i].resize(n);
        max[i].resize(n);
        std::fill(std::begin(min[i]), std::end(min[i]), n);
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
                min[i][j] = min[i][j - 1], max[i][j] = max[i][j - 1];

            min[i][j] = std::min(min[i][j], pos[i][j]);
            max[i][j] = std::max(max[i][j], pos[i][j]);
        }
    }
    
    i64 ans = 1;
    for (int mex = 1; mex < n; mex++)
    {
        std::array<int, 2> l{}, r{};
        bool none = false;
        for (int i = 0; i < 2; i++)
        {
            if (between(pos[i][mex], min[i][mex - 1], max[i][mex - 1]))
                none = true;

            if (pos[i][mex] < min[i][mex - 1])
            {
                l[i] = pos[i][mex] + 1;
                r[i] = n - 1;                
            }

            if (pos[i][mex] > max[i][mex - 1])
            {
                l[i] = 0;
                r[i] = pos[i][mex] - 1;
            }
        }

        int left_st = std::max(l[0], l[1]);
        int left_en = std::min(min[0][mex - 1], min[1][mex - 1]);

        int right_st = std::max(max[0][mex - 1], max[1][mex - 1]);
        int right_en = std::min(r[0], r[1]);

        print(left_st, left_en, right_st, right_en, none, mex + 1)
        if (!none and left_st <= left_en and right_st <= right_en)
            ans += 1LL * (left_en - left_st + 1) * (right_en - right_st + 1);
    }   

    // mex: 0
    std::array<int, 4> ones{-1, pos[0][0], pos[1][0], n};
    std::sort(std::begin(ones), std::end(ones));
    print(ones)
    for (int i = 1; i < 4; i++)
        ans += 1LL * (ones[i] - ones[i - 1] - 1) * (ones[i] - ones[i - 1]) / 2;

    std::cout << ans;
    
    return 0;
}