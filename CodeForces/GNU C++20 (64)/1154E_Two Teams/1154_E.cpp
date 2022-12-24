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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> next(n), prev(n), a(n);
    std::iota(std::begin(next), std::end(next), 1);
    std::iota(std::begin(prev), std::end(prev), -1);

    std::map<int, int, std::greater<>> pos;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    std::vector<int> ans(n, 0);
    int turn = 1;
    while (!pos.empty())
    {
        auto [num, id] = *std::begin(pos);
        ans[id] = turn;

        int back = id, steps = 0;
        std::set<int> done;

        while (back != -1 and steps <= k)
        {
            done.emplace(back);
            ans[back] = turn, back = prev[back];
            steps++;
        }

        steps = 0;
        int forward = id;
        while (forward != n and steps <= k)
        {
            done.emplace(forward);
            ans[forward] = turn, forward = next[forward];
            steps++;
        }

        for (auto id : done)
        {
            prev[id] = back;
            next[id] = forward;
            pos.erase(a[id]);
        }
        
        if (back >= 0)
            next[back] = forward;
        if (forward < n)
            prev[forward] = back;
        

        turn = 3 - turn;
    }

    for (auto i : ans)
        std::cout << i;

    return 0;
}