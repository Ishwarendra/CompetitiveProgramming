#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<int> h(n);

    for(int &x : h) cin >> x;
    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    int ans = abs(h[1] - h[0]), prev2 = 0, prev1 = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++)
    {
        ans = min(prev1 + abs(h[i] - h[i - 1]), prev2 + abs(h[i] - h[i - 2]));
        prev2 = prev1;
        prev1 = ans;
    }

    cout << ans << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}