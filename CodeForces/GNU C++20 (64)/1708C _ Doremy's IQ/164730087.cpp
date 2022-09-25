#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif
 
void solve()
{
    int n, iq;
    std::cin >> n >> iq;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];
 
    if (iq > *std::max_element(std::begin(a), std::end(a)))
    {
        std::cout << std::string(n, '1') << "\n";
        return;
    }
 
    int left = 0, right = n, ans = 0;
    std::string todo;
    std::vector<int> tested(n);
 
    auto good = [&](int mid, int &cur_ans)
    {
        std::fill(std::begin(tested), std::end(tested), 0);
        int count = 0;
        int q = iq;
 
        for (int i = 0; i < mid; i++)
        {
            if (a[i] <= q)
                count++, tested[i] = 1;
        }
 
        for (int i = mid; i < n; i++)
        {
        //     if (tested[i])
        //         continue;
 
            if (a[i] <= q)
                tested[i] = 1, count++;
            else
                tested[i] = 1, count++, q--;
 
            if (q < 0)                
                return 0;
        }
 
        cur_ans = count;
        return 1;
    };
 
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        int cur_ans = 0;
        if (good(mid, cur_ans))
        {
            if (cur_ans > ans)
            {
                ans = cur_ans;
                todo.clear();
 
                for (int i = 0; i < n; i++)
                    todo += char('0' + tested[i]);
            }
 
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
 
    std::cout << todo << "\n";
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