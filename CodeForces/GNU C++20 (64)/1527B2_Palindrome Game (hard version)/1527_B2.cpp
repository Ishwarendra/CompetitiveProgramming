#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string alice = "ALICE\n", bob = "BOB\n", draw = "DRAW\n";

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    int prob = 0, zero = 0;
    int i = 0, j = n - 1;
    while (i <= j)  
    {
        if (s[i] != s[j])
            prob++;
        i++, j--;
    }

    int cnt = std::count(std::begin(s), std::end(s), '0');
    if (prob == 0)
    {
        if (cnt == 1 or cnt % 2 == 0)
            std::cout << bob;
        else
            std::cout << alice;
        return;
    }
    std::array<int, 2> cost {0, 0};
    cost[1] += prob;

    int turn = 0;
    std::cout << (cnt == 2 && n % 2 && s[n / 2] == '0' ? draw : alice);
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