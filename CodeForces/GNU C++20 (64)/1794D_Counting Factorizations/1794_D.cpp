#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

namespace nt
{
    std::vector<bool> sieve(const int n)
    {
        std::vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i < n; i++)
        {
            for (int j = i * i; j < n; j += i)
                is_prime[j] = false;
        }

        return is_prime;
    }

    std::vector<bool> linear_sieve(const int n)
    {
        std::vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;

        std::vector<int> prime;

        for (int i = 2; i < n; i++)
        {
            if (is_prime[i])
                prime.emplace_back(i);

            for (int j = 0; j < std::size(prime) and i * prime[j] < n; j++)
            {
                is_prime[i * prime[j]] = false;
                if (i % prime[j] == 0)
                    break;

            }
        }

        return is_prime;
    }

    std::vector<int> phi_upton(const int n)
    {
        std::vector<int> phi(n), prime;
        phi[1] = 1;

        std::vector<bool> is_prime(n, true);

        for (int i = 2; i < n; i++)
        {
            if (is_prime[i])
            {
                phi[i] = i - 1;
                prime.emplace_back(i);
            }

            for (int j = 0; j < std::size(prime) and 1LL * i * prime[j] < n; j++)
            {
                is_prime[i * prime[j]] = false;

                if (i % prime[j])
                    phi[i * prime[j]] = phi[i] * phi[prime[j]];
                else
                {
                    phi[i * prime[j]] = prime[j] * phi[i];
                    break;
                }
            }
        }

        return phi;
    }

    template<class T>
    T phi(T x)
    {
        assert(x > 0);
        T res = 1;
        for (T i = 2; i * i <= x; i++)
        {
            if (x % i)
                continue;

            T cur = 1;
            while (x % i == 0)
                x /= i, cur *= i;
            res *= (cur - cur / i);
        }

        if (x > 1)
            res *= (x - 1);
        return res;
    }
};

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

    const int N = n + 10;
    constexpr int M = 1e6 + 1;

    auto is_prime = nt::sieve(M);

    std::vector<Z> fact(N), invFact(N);
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i;

    invFact[N - 1] = 1 / fact[N - 1];
    for (int i = N - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1);

    std::vector<int> a(n * 2);
    std::map<int, int> freq;

    for (int i = 0; i < n * 2; i++)
    {
        std::cin >> a[i];
        freq[a[i]]++;
    }

    std::vector<Z> dp(n + 1);
    dp[0] = 1; 

    for (auto [num, f] : freq)
    {
        std::vector<Z> ndp(n + 1);

        for (int expo = 0; expo <= n; expo++)
        {
            if (is_prime[num])
            {
                // use all in expo except one
                if (expo + f - 1 <= n)
                    ndp[expo + f - 1] += dp[expo] * invFact[f - 1];

                // use all in expo
                if (expo + f <= n)
                {
                    print(expo, expo + f, dp[expo].val())
                    ndp[expo + f] += dp[expo] * invFact[f];
                }
            }
            else
            {
                // must use all in expo
                if (expo + f <= n)
                    ndp[expo + f] += dp[expo] * invFact[f];
            }
        }

        std::swap(ndp, dp);
    }

    // for (auto x : dp) std::cout << x << " ";

    std::cout << dp.back() * fact[n] << "\n";
    
    return 0;
}