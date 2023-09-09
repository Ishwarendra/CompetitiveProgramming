#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace __gnu_pbds;

template<typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C,
      rb_tree_tag, tree_order_statistics_node_update>; 

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
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> p(n + 1);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    ordered_set<i64, std::less_equal<>> pbds;
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        pbds.insert(p[i - 1]);
        ans += pbds.order_of_key(p[i]);
    }

    std::cout << ans;

    return 0;
}