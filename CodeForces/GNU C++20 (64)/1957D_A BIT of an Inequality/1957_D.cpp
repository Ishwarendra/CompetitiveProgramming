#include "bits/stdc++.h"
qwertyqwertyqwerty

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * XOR(i, j) ^ a[k] > XOR(i, j)
 * a[k] => any one bit odd whose frequency is even in range [i, j] work
 * Unset lower bit but set higher bit also works
 * Fix (k, pos):
 *     if I can set this bit at any cost (not harming higher bit) then ok
 *     if pos bit is set in k:
 *         find (i, j) pair such that [i, k) and (k, j] has same parity of 1 in pos bit
 */

constexpr int M = 4;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    
    std::vector pref(n, std::array<int, M>());
    auto suff = pref;
    for (int i = 0; i < n; i++)
    {
        if (i)
            pref[i] = pref[i - 1];
        for (int pos = 0; pos < M; pos++)
            pref[i][pos] += getBit(a[i], pos);
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
            suff[i] = suff[i + 1];
        for (int pos = 0; pos < M; pos++)
            suff[i][pos] += getBit(a[i], pos);
    }
    
    auto add = [&](auto &p, int x)
    {
        if (x > 0)  
            p[x & 1]++;
    };
    
    auto sub = [&](auto &p, int x)
    {
        if (x > 0)
            p[x & 1]--;
    };
    
    std::vector start(M, std::array<int, 2>());
    auto end = start;
    
    
    i64 ans = 0;
    for (int k = 0; k < n; k++)
    {
        for (int pos = 0; pos < M; pos++)
            add(start[pos], getBit(a[k], pos));
        
        for (int pos = M - 1; pos >= 0; pos--)
        {
            if (!getBit(a[k], pos))           
                continue;
            
            i64 z = 1LL * start[pos][0] * end[pos][0];
            i64 o = 1LL * start[pos][1] * end[pos][1];
            print(z, o, k)
            ans += z + o;
        }
        
        for (int pos = 0; pos < M; pos++)
            sub(end[pos], getBit(a[k], pos));
    }
    
    std::cout << ans << "\n";
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