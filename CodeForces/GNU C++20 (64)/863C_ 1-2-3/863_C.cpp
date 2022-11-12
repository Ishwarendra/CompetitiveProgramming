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
    
    i64 k;
    int a, b;
    std::cin >> k >> a >> b;
    --a, --b;

    int alice[3][3], bob[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> alice[i][j];
            alice[i][j]--;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> bob[i][j];
            bob[i][j]--;
        }
    }

    i64 A = 0, B = 0;

    auto work = [&]()
    {
        std::vector<std::pair<int, int>> cycle;
        std::pair<int, int> last {a, b};
        auto cur = last;

        while (std::count(std::begin(cycle), std::end(cycle), cur) == 0)
        {
            cycle.emplace_back(cur);
            last = cur;
            auto [alice_, bob_] = last;

            cur = {alice[alice_][bob_], bob[alice_][bob_]};
        }

        cycle.emplace_back(cur);
        return cycle;
    }; 

    auto win = [&](int x, int y) -> int
    {
        x++, y++;
        if (x == 3)
            return y == 2;
        if (x == 2)
            return y == 1;
        if (x == 1)
            return y == 3;

        return 0;
    };

    auto line = work();
    int point1 = 0, point2 = -1;
    for (int i = 0; i < std::size(line); i++)
    {
        if (line[i] == line.back())
        {
            point2 = i;
            break;
        }
    }
    
    line.pop_back();
    auto cycle = std::vector(std::begin(line) + point2, std::end(line));
    line.resize(point2);

    int pos = 0;
    while (k and pos < std::size(line))
    {
        auto [alice_, bob_] = line[pos++];
        A += win(alice_, bob_);
        B += win(bob_, alice_);
        k--;
    }

    int len = std::size(cycle);
    std::array<int, 2> win_count{};

    for (int i = 0; i < std::size(cycle); i++)
    {
        win_count[0] += win(cycle[i].first, cycle[i].second);
        win_count[1] += win(cycle[i].second, cycle[i].first);
    }

    i64 q = k / len, r = k % len;
    A += q * win_count[0];
    B += q * win_count[1];
    
    pos = 0;
    while (k and r--)
    {
        assert(pos < std::ssize(cycle));
        auto [alice_, bob_] = cycle[pos++];
        A += win(alice_, bob_);
        B += win(bob_, alice_);
        k--;
    }

    std::cout << A << " " << B;

    return 0;
}