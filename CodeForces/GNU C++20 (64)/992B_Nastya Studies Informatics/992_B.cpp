#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * A = p1^a1 * p2^a2 * ...
 * B = p1^b1 * p2^b2 * ...
 * GCD(A, B) = p1^(min(a1, b1)) * p2^(min(a2, b2)) * ...
 * LCM(A, B) = p1^(max(a1, b1)) * p2^(max(a2, b2)) * ...
 * 
 * Thus if first number has minimum power and another should have maximum power.
 * which gives us 2 choices every time we encounter a_i != b_i
 * Total distinct prime factors of a number n <= log(log(n))
 * So total choices <= log(n)
 * Just brute force over all choices
 * 
 * Remove the case when lcm % gcd != 0 since that can lead us to having more than log(n) choices for a and b
 */

bool between(int x, int l, int r) { return l <= x and x <= r; }

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int l, r, x, y;
    std::cin >> l >> r >> x >> y;
    
    if (y % x)
    {
        std::cout << 0;
        return 0;
    }
    
    auto primeFactor = [&](int x)
    {
        std::map<int, int> m;
        for (i64 i = 2; i * i <= x; i++)  
        {
            int cnt = 0;
            while (x % i == 0)
                cnt++, x /= i;
            
            if (cnt)
                m[i] = cnt;
        }
        
        if (x)
            m[x]++;
        
        return m;
    };
    
    auto pf_lcm = primeFactor(y);
    auto pf_gcd = primeFactor(x);
    
    int a = 1, b = 1;
    std::vector<std::tuple<int, int, int>> choices;
    std::set<std::pair<int, int>> ans;
    
    for (auto &[p, f] : pf_lcm)
    {
        int fg = pf_gcd[p];
        if (fg == f)
        {
            while (fg--)
                a *= p, b *= p;
        }
        else
            choices.emplace_back(p, fg, f);
    }
    
    int sz = std::size(choices);
    for (int mask = 0; mask < (1 << sz); mask++)
    {
        int old_a = a, old_b = b;
        for (int i = 0; i < sz; i++)
        {
            auto [p, fg, f] = choices[i];
            if (mask >> i & 1)
                std::swap(fg, f);
            
            while (fg--)
                a *= p;
            while (f--)
                b *= p;
        }
        
        if (between(a, l, r) and between(b, l, r))
            ans.emplace(a, b);
        
        a = old_a, b = old_b;
    }

    std::cout << std::size(ans);
    
    return 0;
}