#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T, class G>
T power(T a, G b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
} 

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int mid = (n + 1) / 2;

    auto f = [&](int start)
    {
        std::set<i64> s;
        for (int num_mask = start; num_mask < power(3, mid); num_mask++)
        {
            int mask = num_mask;
            i64 sum = 0;
            for (int pos = 0; pos < mid; pos++)
            {
                int rem = mask % 3;
                rem = (rem == 2 ? -1 : rem);
                sum += a[pos] * rem;
                mask /= 3;
            }

            s.emplace(sum);
        }

        for (int num_mask = !start; num_mask < power(3, (n - mid)); num_mask++)
        {
            int mask = num_mask;
            i64 sum = 0;
            for (int pos = mid; pos < n; pos++)
            {
                int rem = mask % 3;
                rem = (rem == 2 ? -1 : rem);
                sum += a[pos] * rem;
                mask /= 3;
            }

            sum *= -1;
            if (s.count(sum))
                return true;
        }

        return false;
    };

    std::cout << (f(0) or f(1) ? "YES\n" : "NO\n");
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