#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> h(n);

    for(ll &x : h)
        cin >> x;

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    vector<ll> dp(n, 999999999);

    // Base-Case
    dp[0] = 0, dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++)
    {
        for(int j = 1; j <= (min(i, k)); j++)
        {
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }    

    cout << dp.back() << "\n";

}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}