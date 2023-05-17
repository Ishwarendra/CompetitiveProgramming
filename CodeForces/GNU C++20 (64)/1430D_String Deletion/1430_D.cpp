#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct cmp
{
    bool operator() (const auto &a, const auto &b) const
    {
        if (a.first > 1 and b.first > 1)
            return a.second < b.second;
        else if (a.first == 1 and b.first > 1)
            return false;
        else if (a.first > 1 and b.first == 1)
            return true;

        return a.second < b.second;
    }
};

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;
    n = std::size(s);

    char ch = s[0];
    int cnt = 1;
    std::multiset<std::pair<int, int>, cmp> m;
    std::map<int, int> freq;
    int block_ = 0;

    for (int i = 1; i < n; i++)  
    {
        if (s[i] == ch)
            cnt++;
        else
        {
            m.emplace(cnt, block_);
            freq[block_++] = cnt;
            cnt = 1;
            ch = s[i];
        }
    }

    m.emplace(cnt, block_);
    freq[block_] = cnt;

    int ans = 0;
    for (auto &[block, f] : freq)
    {
        if (f == 0)
            continue;

        if (f > 1)
        {
            ans++;
            m.erase(m.find({f, block}));
            continue;
        }

        ans++;
        m.erase(m.find({f, block}));
        if (m.empty())
            break;

        auto [c, b] = *std::begin(m);
        m.erase(std::begin(m));
        freq[b]--;
        if (freq[b])
            m.emplace(freq[b], b);
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}