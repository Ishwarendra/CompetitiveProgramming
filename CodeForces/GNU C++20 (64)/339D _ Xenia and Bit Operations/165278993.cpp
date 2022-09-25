#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif
 
struct custom_seg 
{
    const int n;
    std::vector<int> a;
 
    custom_seg(std::vector<int> &in) : n(int(std::size(in))), a(n * 2)
    {
        for (int i = 0; i < n; i++)
            a[i + n] = in[i];
 
        int rem = n, st = n - 1;
        int doOr = 1;
 
        while (rem)
        {
            for (int i = 0; i < rem / 2; i++)
            {
                if (doOr)
                    a[st] = a[(st << 1) ^ 1] | a[st << 1];
                else
                    a[st] = a[(st << 1) ^ 1] ^ a[st << 1];
 
                st--;
            }
 
            doOr ^= 1;
            rem >>= 1;
        }
    }
 
    void update(int id, int x)
    {
        int doOr = 1;
 
        for (a[id += n] = x; id; id >>= 1)
        {
            if (doOr)
                a[id >> 1] = a[id ^ 1] | a[id];
            else
                a[id >> 1] = a[id ^ 1] ^ a[id]; 
 
            doOr ^= 1;
        }
    }
};
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
 
    std::vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); ++i)
        std::cin >> a[i];
 
    custom_seg st(a);
    while (m--)
    {
        int id, val;
        std::cin >> id >> val;
 
        st.update(--id, val);
        std::cout << st.a[1] << "\n";
    }
    
    return 0;
}