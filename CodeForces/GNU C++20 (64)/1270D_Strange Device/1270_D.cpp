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

    if (n == 1)
    {
        std::cout << "! 1" << std::endl;
        return 0;
    }

    std::map<int, int> freq, idx;
    auto query = [&](std::vector<int> q)
    {
        std::cout << "? ";
        for (int i = 0; i < k; i++)
            std::cout << q[i] + 1 << " \n"[i == k - 1];
        std::cout.flush();

        int pos, ele;
        std::cin >> pos >> ele;
        freq[ele]++;
        idx[ele] = pos;
    };

    for (int i = 0; i <= k; i++)
    {
        std::vector<int> q;
        for (int j = 0; j <= k; j++)
        {
            if (i != j)
                q.emplace_back(j);
        }

        query(q);
    }

    std::array<int, 2> max{};

    for (auto &[p, f] : freq)
        max = std::max(max, std::array {p, f});

    std::cout << "! " << max[1] << std::endl;

    return 0;
}