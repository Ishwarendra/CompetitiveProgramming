#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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

    int cur_speed = 0, ans = 0;
    std::stack<int> speed_limit, overtake;
    speed_limit.push(301);
    overtake.push(1);

    while (n--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            std::cin >> cur_speed;
            while (cur_speed > speed_limit.top())
                ans++, speed_limit.pop();
        }
        else if (t == 2)
        {
            while (overtake.top() == 0)
                ans++, overtake.pop();
        }
        else if (t == 3)
        {
            int s;
            std::cin >> s;
            if (cur_speed <= s)
                speed_limit.push(s);
            else
                ans++;
        }
        else if (t == 4)
            overtake.push(1);
        else if (t == 5)
            speed_limit.push(301);
        else
            overtake.push(0);
    }

    std::cout << ans << "\n";
    
    return 0;
}