#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    ordered_set<int, std::greater_equal<>> greater;
    ordered_set<int, std::less_equal<>> less;

    greater.insert(a[0]), less.insert(a[0]);

    i64 ans = 0;
    for (int i = 1; i < n; i++)
    {
        int front = less.order_of_key(a[i]);
        int back = greater.order_of_key(a[i]);

        ans += std::min(front, back);
    
        greater.insert(a[i]);
        less.insert(a[i]);
    }

    std::cout << ans << "\n";
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