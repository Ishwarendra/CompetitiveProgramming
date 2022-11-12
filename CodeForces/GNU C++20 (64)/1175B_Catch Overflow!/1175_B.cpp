#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 LIMIT = (1LL << 32) - 1LL;
constexpr int N = 101;

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

bool overflow(i64 x)
{
    return x > LIMIT;
}

int find(i64 p, int n)
{
    int ans = 0;
    while (!overflow(p))
        p *= n, ans++;

    return ans;
}

struct Product
{
    std::vector<int> nums;
    std::vector<int> last;

    Product() : nums(N), last(0) {}

    i64 get()
    {
        i64 ans = 1;
        for (int i = 2; i < N; i++)
        {
            if (nums[i] < find(ans, i))
                ans *= power(i64(i), nums[i]);
            else
                return -1;
        }

        return ans;
    }

    void add(int x) { nums[x]++; last.emplace_back(x); }
    void remove() { nums[last.back()]--; last.pop_back(); }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l;
    std::cin >> l;

    i64 x = 0;
    Product p;

    while (l--)
    {
        std::string s;
        int n;
        std::cin >> s;

        if (s == "for")
        {
            std::cin >> n;
            p.add(n);
        }
        else if (s == "end")
            p.remove();
        else
        {
            i64 add = p.get();
            if (overflow(x + add) or add == -1)
            {
                std::cout << "OVERFLOW!!!";
                std::exit(0);
            }

            x += add;
        }
    }

    assert(x <= LIMIT);
    std::cout << x;

    return 0;
}