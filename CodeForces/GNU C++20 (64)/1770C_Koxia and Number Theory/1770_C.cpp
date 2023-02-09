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

    bool isPrime(int n)
    {
        if (n < 2)
            return false; 
        for (int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
        {
            if (n == x)
                return true;
            bool flag = true;
            int r = 1;
            int t = 1;
            while (r <= ((n - 1) >> __builtin_ctz(n - 1)))
            {
                if (r & ((n - 1) >> __builtin_ctz(n - 1)))
                    t = (1LL * t * x) % n;
                x = (1LL * x * x) % n;
                r <<= 1;
            }
            if (t == 1 || t == n - 1)
                flag = false;
            for (r = 0; r < __builtin_ctz(n - 1); r++)
            {
                t = (1LL * t * t) % n;
                if (t == n - 1)
                    flag = false;
            }
            if (flag)
                return false;
        }
        return true;
    }
    
};


void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (std::size(std::set(std::begin(a), std::end(a))) != n)
    {
        std::cout << "NO\n";
        return;
    }

    int cnt = 0;
    for (int i = 2; cnt < n; i++)
    {
        if (nt::isPrime(i))
        {
            cnt++;
            std::vector<int> b(i);
            for (int j = 0; j < n; j++)
                b[a[j] % i]++;

            int min = *std::min_element(std::begin(b), std::end(b));

            if (min > 1)
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}