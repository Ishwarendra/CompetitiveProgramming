#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 998244353;

// assume -MOD <= x < 2*MOD
int norm(int x) 
{
    if (x < 0) 
        x += MOD;
    
    if (x >= MOD) 
        x -= MOD;
    
    return x;
}
template<class T>
T power(T a, int b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(MOD - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, MOD - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = (long long)(x) * rhs.x % MOD;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        int v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
}; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, q;
    std::cin >> n >> m >> q;

    while (q--)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        auto sum = [&](int first, int hori, int verti) -> Z
        {
            Z ans = 0;
            if (hori <= 0 or verti <= 0)
                return ans;

            ans += verti;
            ans *= Z(first) + Z(verti - 1) * Z(m);
            
            ans *= hori;
            ans += Z(verti) * Z(hori) * Z(hori - 1);
            
            return ans;
        };

        auto f = [&](int i, int j) -> int
        {
            return (1LL * (i - 1) * m + j) % MOD;
        };  

        Z ans = 0;
        std::array<int, 2> first, hori, verti;

        int v = b - a + 1;
        int h = d - c + 1;

        if ((a + c) % 2)
        {
            // (a + 1, c) and (a, c + 1)
            first = {f(a + 1, c), f(a, c + 1)};
            hori = {(h + 1) / 2, h / 2};
            verti = {v / 2, (v + 1) / 2};
        }
        else
        {
            // (a, c) and (a + 1, c + 1)
            first = {f(a, c), f(a + 1, c + 1)};
            hori = {(h + 1) / 2, h / 2};
            verti = {(v + 1) / 2, v / 2};
        }
        
        ans += sum(first[0], hori[0], verti[0]) + sum(first[1], hori[1], verti[1]);
        std::cout << ans << "\n";
    }
    
    return 0;
}