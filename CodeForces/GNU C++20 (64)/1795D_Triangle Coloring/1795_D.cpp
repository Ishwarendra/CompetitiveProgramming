#include "bits/stdc++.h"
#include <slowmokit.hpp>

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
 
constexpr int P = 998244353;
using Z = MInt<P>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n / 3);

    for (int i = 0; i < n / 3; i++)
    {
        std::map<int, int> m;
        for (int j = 0; j < 3; j++)
        {
            int x;
            std::cin >> x;
            m[x]++;
        }

        if (std::size(m) == 1)
            a[i] = 3;
        else if (std::size(m) == 2)
            a[i] = (std::begin(m)->second == 2) + 1;
        else
            a[i] = 1;
    }

    std::function<Z(int, int)> C = [&](int n, int r)
    {
        if (r == 0)
            return Z(1);

        return Z(n) * C(n - 1, r - 1) / r;
    };

    Z ans = 1;
    for (int i = 0; i < n / 3; i++)
        ans *= a[i];

    ans *= C(n / 3, n / 6);
    std::cout << ans;

    return 0;
}