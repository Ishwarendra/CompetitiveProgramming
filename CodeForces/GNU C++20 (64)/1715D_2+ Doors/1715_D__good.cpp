#include <iostream>
#include <vector>

using namespace std;

inline bool get_bit(uint32_t &x, uint32_t &bt) { return (x >> bt) & 1; }
inline void make_one(uint32_t &x, uint32_t &bt) { x |= (1 << bt); }
inline void make_null(uint32_t &x, uint32_t &bt) { x &= (~(1 << bt)); }

inline bool solve_bit(vector<uint32_t> &ans,
                      vector<vector<pair<uint32_t, uint32_t>>> &g,
                      uint32_t &bt) {
    for (uint32_t i = 0; i < (uint32_t)ans.size(); ++i)
        for (auto &it : g[i])
            if (!get_bit(it.second, bt))
                make_null(ans[i], bt);
            else if (!get_bit(ans[i], bt) && !get_bit(ans[it.first], bt))
                return false;
    for (uint32_t i = 0; i < (uint32_t)ans.size(); ++i)
        if (get_bit(ans[i], bt)) {
            make_null(ans[i], bt);
            for (auto &it : g[i])
                if (!get_bit(ans[it.first], bt) && get_bit(it.second, bt)) {
                    make_one(ans[i], bt);
                    break;
                }
        }

    return true;
}

inline void solve() {
    uint32_t n, m;
    cin >> n >> m;
    vector<vector<pair<uint32_t, uint32_t>>> g(n);
    while (m--) {
        uint32_t a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        if (a > b)
            swap(a, b);
    }
    const int pt = 31;
    vector<uint32_t> ans(n, ~(1 << pt));
    for (uint32_t i = 0; i < pt; ++i)
        if (!solve_bit(ans, g, i)) {
            cout << "-1\n";
            return;
        }
    for (auto &it : ans)
        cout << it << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}