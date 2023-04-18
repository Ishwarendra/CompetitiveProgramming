#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
template<int P>
struct MInt {
    int x;
    MInt() : x{} {}
    MInt(i64 x) : x{norm(x % P)} {}
    
    int norm(int x) 
    {
        if (x < 0) 
            x += P;
        if (x >= P) 
            x -= P;
        return x;
    }
    int val() const { return x; }
    MInt operator-() const 
    {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    MInt inv() const 
    {
        assert(x != 0);
        return power(*this, P - 2);
    }
    MInt &operator*=(const MInt &rhs) 
    {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    MInt &operator+=(const MInt &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    MInt &operator-=(const MInt &rhs) 
    {
        x = norm(x - rhs.x);
        return *this;
    }
    MInt &operator/=(const MInt &rhs) { return *this *= rhs.inv(); }
    friend MInt operator*(const MInt &lhs, const MInt &rhs) 
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator+(const MInt &lhs, const MInt &rhs) 
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator-(const MInt &lhs, const MInt &rhs) 
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator/(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
};
 
constexpr int P = 1e9 + 7;
using Z = MInt<P>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<Z> dp(n + 1);
    dp[0] = 1;

    auto factor = [&](auto x)
    {
        std::vector<int> div;
        for (int i = 1; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (i <= n)
                    div.emplace_back(i);
                if (x / i <= n and 1LL * i * i != x)
                    div.emplace_back(x / i);
            }
        }

        return div;
    };

    for (int i = 1; i <= n; i++)
    {
        auto f = factor(a[i - 1]);
        std::sort(std::rbegin(f), std::rend(f));
        for (auto x : f)
        {
            // if (x == 2)
            //     print(a[i - 1])
            dp[x] += dp[x - 1];
        }
    }

    // for (auto x : dp) std::cout << x << " ";
    std::cout << std::accumulate(std::begin(dp) + 1, std::end(dp), Z(0));

    return 0;
}