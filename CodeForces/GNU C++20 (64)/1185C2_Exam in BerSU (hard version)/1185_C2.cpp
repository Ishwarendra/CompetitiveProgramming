#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <class Info>
struct SegmentTree
{
    int n;
    std::vector<Info> info;
    SegmentTree(int n = 0) : n(n), info(4 << std::__lg(n), Info()) {}
 
    template <typename T>
    SegmentTree(const std::vector<T> a) 
    {
        n = std::size(a);
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l], 1);
                return;
            }
 
            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            merge(id);
        }; 
        build(0, n - 1, 0);
    } 
    void merge(int id)
    {
        info[id] = info[id * 2 + 1] + info[id * 2 + 2];
    }
    void update(int id, int x, int nl, int nr, const Info &v)
    {
        if (nl > nr)
            return;
        if (nl == nr)
        {
            info[id] = info[id] + v;
            return;
        }
 
        int m = (nl + nr) >> 1;
        if (x <= m)
            update(2 * id + 1, x, nl, m, v);
        else
            update(2 * id + 2, x, m + 1, nr, v);
        merge(id);
    }
    void update(int x, const Info &v)
    {
        update(0, x, 0, n - 1, v);
    }
    Info get(int id, int l, int r, int nl, int nr)
    {
        if (r < nl or l > nr)
            return Info();
        if (l >= nl and r <= nr)
            return info[id];
 
        int m = (l + r) >> 1;
        return get(2 * id + 1, l, m, nl, nr) + get(2 * id + 2, m + 1, r, nl, nr);
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };
};

struct Info
{
    int cnt;
    i64 sum;
    Info() : cnt(0), sum(0) {}
    Info(int cnt, i64 sum) : cnt(cnt), sum(sum) {}
};

Info operator+ (Info a, Info b)
{
    a.cnt += b.cnt;
    a.sum += b.sum;
    return a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++)
        std::cin >> t[i];

    constexpr int N = 101;
    SegmentTree<Info> st(N);
    i64 sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (m - sum >= t[i])
        {
            std::cout << 0 << " \n"[i == n - 1];
            sum += t[i];
            st.update(t[i], Info(1, t[i]));
            continue;
        }

        auto good = [&](int mid)
        {
            return m - sum + st.get(mid, N - 1).sum >= t[i];
        };  

        int left = 1, right = N;
        int ans = 0;
        while (left <= right)
        {   
            int mid = std::midpoint(left, right);
            if (good(mid))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        auto [total, add] = st.get(ans, N - 1);
        i64 X = m - sum + st.get(ans, N - 1).sum;
        int x = (X - t[i]) / ans;
        total -= x;

        sum += t[i];
        st.update(t[i], Info(1, t[i]));
        std::cout << total << " \n"[i == n - 1];
    }

    return 0;
}