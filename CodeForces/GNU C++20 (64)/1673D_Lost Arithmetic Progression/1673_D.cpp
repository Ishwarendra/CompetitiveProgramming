#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

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

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

/**
  * If any element of C is not in A => 0
  *     if first or last term is outside A
  *     d_c % d_a != 0 then impossible
  *     if any term of c not in a then also impossible (only check first term)
  * You already know common differences for B (Factor of d_c)
  * For a particular d:
  *     (d_c / d) choices for first element and same for last.
  */
void solve()
{
    int aa, da, na, ac, dc, nc;
    std::cin >> aa >> da >> na >> ac >> dc >> nc;
    
    auto getNth = [&](int a, int d, int n) { return a + (n - 1LL) * d;  };
    
    if (dc % da || getNth(ac, dc, 1) < getNth(aa, da, 1) || getNth(ac, dc, nc) > getNth(aa, da, na))
    {
        std::cout << "0\n";
        return;
    }
    
    if (ac != getNth(aa, da, (ac - aa) / da + 1) || getNth(ac, dc, nc) != getNth(aa, da, (getNth(ac, dc, nc) - aa) / da + 1))
    {
        std::cout << "0\n";
        return;
    }
    
    if (getNth(ac, dc, 0) < getNth(aa, da, 1) || getNth(ac, dc, nc + 1) > getNth(aa, da, na))    
    {
        std::cout << "-1\n";
        return;
    }
    
    Z ans = 0;
    for (int i = 1; i * i <= dc; i++)
    {
        if (dc % i == 0)
        {
            if (std::lcm<i64>(da, dc / i) == dc)
                ans += Z(i) * i;
            if (i * i != dc and std::lcm<i64>(da, i) == dc)
                ans += Z(dc / i) * (dc / i);
        }
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
}
