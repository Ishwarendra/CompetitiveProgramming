#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, T b, T mod) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res % mod) * (a % mod) % mod;
        }
    }
    return (res % mod);
} 

void gcd(int a, int b, i64 &x, i64 &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }

    i64 x1, y1;
    gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - 1LL * y1 * (a / b);
};

i64 inv(i64 a, const i64 p)
{
    i64 x, y;
    gcd(a, p, x, y);
    return (x % p + p) % p;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> primes {4, 5, 9, 7, 11, 13, 17, 19, 23};
    const int m = std::accumulate(std::begin(primes), std::end(primes), 0);
    i64 M = 1;

    for (auto prime : primes)    
        M *= prime;

    std::cout << m << std::endl;
    std::vector<int> a(m);
    std::iota(std::begin(a), std::end(a), 0);

    for (int i = 0; auto prime : primes)
    {
        std::rotate(std::begin(a) + i, std::begin(a) + i + 1, std::begin(a) + i + prime);
        i += prime;
    }

    for (int i = 0; i < m; i++)
        std::cout << a[i] + 1 << ' ';
    std::cout << std::endl;

    std::vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i];
        b[i]--;
    }   

    std::vector<int> c;
    for (auto i = 0; auto prime : primes)
    {
        int cur = (b[i] - a[i] + 1) % prime;
        cur = (cur + prime) % prime;
        i += prime;
        c.emplace_back(cur);
    } 

    i64 ans = c[0], P = primes[0];
    i64 prev = c[0];
    for (int i = 1; i < std::size(c); i++)
    {
        i64 x = (c[i] - prev) % primes[i];
        x = (x + primes[i]) % primes[i];

        x = (x * inv(P, primes[i])) % primes[i];
        ans = (ans + P * x) % M;
        prev = ans;
        P *= primes[i];
    }

    std::cout << ans << std::endl;

    return 0;
}