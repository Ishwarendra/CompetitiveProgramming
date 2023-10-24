#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k, M;
    std::cin >> n >> k >> M;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);

    int ans = 0;
    for (int end = 0; end <= n; end++)
    {
        if (1LL * end * sum > M)
            break;

        int rem = M - end * sum;
        int cur_ans = (k + 1) * end;

        for (int j = 0; j < k and rem > 0; j++)
        {
            for (int i = end; i < n; i++)
            {
                if (rem - a[j] < 0)
                    break;
                cur_ans++;
                rem -= a[j];
            }
        }

        ans = std::max(ans, cur_ans);
    }

    std::cout << ans;
    
    return 0;
}