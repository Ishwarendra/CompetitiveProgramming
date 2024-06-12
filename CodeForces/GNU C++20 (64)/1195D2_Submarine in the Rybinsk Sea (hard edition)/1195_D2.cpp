#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Same logic as before: We will count contribution of each digit
 * But this time instead of iterating over digits we will just iterate over all numbers
 * summation(f(a[i], anything)) + summation(f(anything, a[i]))
 * Depending on length of anything we can figure out what a[i] is going to contribute
 */

template<class T>
T power(T a, i64 b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
}

template<class T>
T inverse(T a, T m) 
{
    T u = 0, v = 1;
    while (a != 0) 
    {
        T t = m / a;
        m -= t * a; 
        u -= t * v; 
        std::swap(a, m);
        std::swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<int P>
struct MInt 
{
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() 
    {
        if (P > 0) 
            return P;
        else 
            return Mod;
    }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }
    constexpr int norm(int x) const 
    {
        if (x < 0) 
            x += getMod();
        
        if (x >= getMod()) 
            x -= getMod();
        
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const 
    {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const 
    {
        assert(x != 0);
        return MInt(inverse(x, P));
    }
    constexpr MInt &operator*=(MInt rhs) & 
    {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & 
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & 
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & 
    {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};
 
template<>
int MInt<0>::Mod = 1;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;

constexpr int N = 11;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::string> a(n);
    std::array<int, N> ofLength{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        int sz = std::size(a[i]);
        ofLength[sz]++;
    }
    
    auto f = [&](std::string s, std::string t)
    {
        std::string res;
        int p = std::size(s), q = std::size(t);
        
        int i = 0, j = 0;
        if (p >= q)
        {
            res += s.substr(0, p - q + 1), i = p - q + 1;
            res += t[j++];
        }
        else
            res += t.substr(0, q - p), j = q - p;
        
        while (i < p)
            res += s[i++], res += t[j++];
        
        Z ans = 0;
        for (auto ch : res)
            ans = ans * 10 + (ch - '0');
        return ans;
    };
    
    Z ans = 0;
    for (auto s : a)
    {
        for (int len = 1; len < N; len++)
        {
            if (!ofLength[len])
                continue;
            
            ans += f(s, std::string(len, '0')) * ofLength[len];
            ans += f(std::string(len, '0'), s) * ofLength[len];
        }
    }
    
    std::cout << ans;
    
    return 0;
}