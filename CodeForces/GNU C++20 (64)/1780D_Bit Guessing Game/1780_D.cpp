#include <iostream>

void solve()
{
    int cnt;
    std::cin >> cnt;

    auto query = [&](int x)
    {
        std::cout << "- " << x << std::endl;
        int new_cnt;
        std::cin >> new_cnt;

        return new_cnt;
    };

    int add = 0;
    int num = 0, tot = 0;
    for (int bit = 0; bit < 30; bit++)
    {
        int sub = 1 << bit;
        sub -= add;

        int new_cnt = query(sub);

        if (new_cnt == cnt - 1)
            num |= 1 << bit, tot++;

        add += sub;

        if (tot == cnt)
            break;
    }

    std::cout << "! " << num << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();
}
