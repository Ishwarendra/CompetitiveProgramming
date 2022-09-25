#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int count = 0;

int query(int a, int b, int c, int d)
{
    count++;
    assert(count <= 20);
    std::cout << "? " << a << " " << c << " " << b << " " << d << std::endl;
    int t;
    std::cin >> t;

    return t; 
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    int r = -1, c = -1;
    int left = 1, right = n;
    while (left <= right)    
    {
        int mid = (left + right) >> 1;
        int rooks = query(left, 1, mid, n);

        if (rooks == mid - left)
            right = mid - 1, r = mid;
        else
            left = mid + 1;
    }

    left = 1, right = n;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        int rooks = query(1, left, n, mid);

        if (rooks == mid - left)
            right = mid - 1, c = mid;
        else
            left = mid + 1;
    }

    std::cout << "! " << r << " " << c << std::endl;

    return 0;
}