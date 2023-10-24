#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

void solve()
{
    int n; 
    std::string s, t;

    std::cin >> n >> s >> t;

    std::vector<int> pos(1, -1);

    for (int i = 0; i < n; i++)  
    {
        if (s[i] != 'C' and t[i] == 'C')
        {
            std::cout << "No\n";
            return;
        }

        if (s[i] == 'C' and t[i] == 'C')
            pos.emplace_back(i);
    }

    pos.emplace_back(n);
    for (int _ = 1; _ < std::size(pos); _++)
    {
        int st = pos[_ - 1] + 1, end = pos[_];
        std::array<int, 3> cnts{}, cntt{};
        for (int i = st; i < end; i++)
        {
            cnts[s[i] - 'A']++;
            cntt[t[i] - 'A']++;
        }

        if (cnts[0] > cntt[0])
        {
            std::cout << "No\n";
            return;
        }

        int bal = 0, d = cntt[0] - cnts[0];
        for (int i = st; i < end; i++)
        {
            if (s[i] == 'C')
            {
                if (d)
                    d--, s[i] = 'A';
                else
                    s[i] = 'B';
            }

            bal += s[i] == 'A';
            bal -= t[i] == 'A';

            if (bal < 0)
            {
                std::cout << "No\n";
                return;
            }
        }
    }

    std::cout << "Yes\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}