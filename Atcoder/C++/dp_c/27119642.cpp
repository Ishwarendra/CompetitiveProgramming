#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long
using vi = vector<int>;
// using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, w;
    cin >> n >> w;

    vector<int> val(n), wt(n);

    for(int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    vector<vi> dp(n, vi(w + 1));

    // Base-Case
    for(int i = wt[0]; i <= w; i++)
        dp[0][i] = val[0];
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if (wt[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j : dp[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }

    cout << dp[n - 1][w] << "\n";
}

int32_t main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}