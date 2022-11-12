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
    
    int h, w, xs, ys, n;
    std::cin >> h >> w >> xs >> ys >> n;

    std::map<int, std::set<int>> row, col;
    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;

        row[x].emplace(y);
        col[y].emplace(x);
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        char d;
        int l;
        std::cin >> d >> l;

        row[xs].emplace(0), row[xs].emplace(w + 1);
        col[ys].emplace(0), col[ys].emplace(h + 1);

        if (d == 'L')
        {
            auto it = row[xs].lower_bound(ys);
            it--;

            if (ys - l <= *it)
                ys = *it + 1;
            else
                ys -= l;
        }
        else if (d == 'R')
        {
            auto it = row[xs].lower_bound(ys);

            if (ys + l >= *it)
                ys = *it - 1;
            else
                ys += l;
        }
        else if (d == 'U')
        {
            auto it = col[ys].lower_bound(xs);
            it--;

            if (xs - l <= *it)
                xs = *it + 1;
            else
                xs -= l;
        }
        else
        {
            auto it = col[ys].lower_bound(xs);

            if (xs + l >= *it)
                xs = *it - 1;
            else
                xs += l;
        }

        std::cout << xs << " " << ys << "\n"; 
    }
    
    return 0;
}