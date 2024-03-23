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

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get()
};
std::mt19937_64 rng(seed);

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

const int B = get_rand(255, 1087);

std::vector<int> val(26);

std::vector<Z> getHash(std::string &s)
{
    int n = std::size(s);
    std::vector<Z> hash(n);
    hash[0] = val[s[0] - 'a'];

    Z mul = 1;
    for (int i = 1; i < n; i++)
    {
        mul *= B;
        hash[i] = hash[i - 1] + mul * val[s[i] - 'a'];
    }

    return hash;
}

Z sum(Z a, int r, int n)
{
    return (a * (power<Z>(r, n) - 1)) / (r - 1);
}

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    for (int i = 0; i < 26; i++)
        val[i] = get_rand(i * 100 + 1, i * 100 + 100);

    auto hash = getHash(s);
    std::reverse(std::begin(s), std::end(s));
    auto rhash = getHash(s);
    std::reverse(std::begin(s), std::end(s));

    auto f = [&](auto &a, int l, int r)
    {
        return (a[r] - (l ? a[l - 1] : Z(0))) / power<Z>(B, l);
    };

    auto isPalindrome = [&](int l, int r)
    {
        Z h = f(hash, l, r);
        l = n - l - 1, r = n - r - 1;
        Z rh = f(rhash, r, l);
        return h == rh;
    };

    while (q--)  
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        int len = r - l + 1;

        int ch = s[l] - 'a';
        if (val[ch] * sum(Z(1), B, len) == f(hash, l, r))
            std::cout << "0\n";
        else
        {
            int ch1 = s[l] - 'a';
            int ch2 = s[l + 1] - 'a';

            Z h = f(hash, l, r);
            Z nh = val[ch1] * sum(Z(1), B * B, (len + 1) / 2);
            nh += val[ch2] * sum(Z(B), B * B, len / 2);

            i64 ans = len * (len + 1LL) / 2 - 1;
            if (h == nh)
            {
                int x = len / 2;
                ans -= 1LL * x * x;
                ans++;
            }

            ans -= isPalindrome(l, r) ? len : 0;

            std::cout << ans << "\n";
        }
    }
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