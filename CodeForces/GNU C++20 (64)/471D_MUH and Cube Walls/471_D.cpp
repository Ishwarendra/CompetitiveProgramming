#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> prefixFunction(auto &s)
{
    int n = std::size(s);

    std::vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        if (s[pi[i - 1]] == s[i])
            pi[i] = pi[i - 1] + 1;
    }

    return pi;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a, b;
    int prev;
    std::cin >> prev;

    for (int i = 0; i < n - 1; i++)
    {
        int next;
        std::cin >> next;
        a.emplace_back(next - prev);
        prev = next;
    }

    std::cin >> prev;
    for (int i = 0; i < m - 1; i++)
    {
        int next;
        std::cin >> next;
        b.emplace_back(next - prev);
        prev = next;
    }

    if (m > n)
    {
        std::cout << 0;
        return 0;
    }

    if (m == 1)
    {
        std::cout << n << "\n";
        return 0;
    }

    n--, m--;
    auto pi = prefixFunction(b);
    int ans = 0;
    for (int i = 0, j = 0; i < n; )
    {
        if (a[i] == b[j] and j == m - 1)
        {
            ans++;
            i++;
            j = pi[j];
        }
        else if (a[i] == b[j])
            i++, j++;
        else if (j == 0)
            i++;
        else
            j = pi[j - 1];
    }

    std::cout << ans;
    
    return 0;
}