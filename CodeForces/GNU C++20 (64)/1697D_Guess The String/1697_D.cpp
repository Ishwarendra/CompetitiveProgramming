#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int count_1 = 0, count_2 = 0;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    auto query1 = [&](int i)
    {
        count_1++;
        // assert(count_1 <= 26 && "count_1 exceeded");

        std::cout << "? 1 " << i + 1 << std::endl;
        char ch;
        std::cin >> ch;

        return ch;      
    };

    auto query2 = [&](int i, int j)
    {
        // assert(i <= j && "i > j in query2");
        count_2++;
        // assert(count_2 <= 6000 && "count_2 exceeded");

        std::cout << "? 2 " << i + 1 << ' ' << j + 1 << std::endl;
        int d;
        std::cin >> d;

        return d;
    };

    int n;
    std::cin >> n;

    std::string ans(n, '!');

    auto distinct = [&](int i, int j)
    {
        auto part = ans.substr(i, j - i + 1);
        int cnt = std::size(std::set(std::begin(part), std::end(part)));

        return cnt;
    };

    ans[0] = query1(0);

    for (int i = 1; i < n; i++)
    {
        if (query2(0, i) == distinct(0, i - 1) + 1)
            ans[i] = query1(i);
        else
        {
            std::map<char, int> last;
            for (int j = 0; j < i; j++)
                last[ans[j]] = j;

            print(last)
            std::vector<int> index;
            for (auto [ch, id] : last)
                index.emplace_back(id);
            int id = -1;

            std::sort(std::begin(index), std::end(index));
            int left = 0, right = std::ssize(index) - 1;

            while (left <= right)
            {
                int mid = std::midpoint(left, right);
                int prev = query2(index[mid], i);
                int next = distinct(index[mid], i - 1);

                if (prev == next)
                    id = mid, left = mid + 1;
                else
                    right = mid - 1;
            }

            ans[i] = ans[index[id]]; 
        }
    }

    // print(count_1, count_2)
    std::cout << "! " << ans << std::endl;

    return 0;
}