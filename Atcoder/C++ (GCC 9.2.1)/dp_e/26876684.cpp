#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

long long maximumAmount(int arr[], int n)
{
    long long dp[n][n]{};

    // Base-Case
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
        if (i < n - 1)
            dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }

    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            long long term1 = arr[i] + min(dp[i + 2][i + gap], dp[i + 1][i + gap - 1]);       // pick coin-i
            long long term2 = arr[i + gap] + min(dp[i + 1][i + gap - 1], dp[i][i + gap - 2]); // pick coin-j
            dp[i][i + gap] = max(term1, term2);
        }
    }

    return dp[0][n - 1];
}

/*  https://atcoder.jp/contests/dp/tasks/dp_d
1 <= N <= 100
1 <= W <= 10^5
1 <= Wt[i] <= W
1 <= Val[i] <= 10^9
*/
void knapsack_less_weight()
{
    int n, w;
    cin >> n >> w;

    vector<ll> wt(n), val(n);

    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    vector<vector<ll>> dp(n, vector<ll>(w + 1));
    // dp[i, w] => max profit considering first (i + 1) choices with "target on w" i.e (choose or not choose w);
    // i -> items_count u can pick (0 - based), w -> weight of knapsack

    // Base-Case (if u can pick first item then pick it up)
    for (int i = wt[0]; i <= w; i++)
    {
        dp[0][i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j <= w; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n - 1][w];
}

/*  https://atcoder.jp/contests/dp/tasks/dp_e
1 <= N <= 100
1 <= W <= 10^9
1 <= Wt[i] <= W
1 <= Val[i] <= 10^3
*/
void knapsack_less_value()
{
    ll n, w;
    cin >> n >> w;

    vector<ll> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    // vector<ll> dp(n*1000 + 1, vector<ll>(n*1000 + 1, 999999999999));
    // dp[i, v] -> minimum number of wt you should pick upto (i + 1)th choice, to get a profit of v;

    vector<ll> prev(n * 1000 + 1, 99999999999999LL); // replace LONG_LONG_LONG with 999999999 and it works
    vector<ll> cur(n * 1000 + 1, 99999999999999LL); // same as up dem

    // Base-Case
    prev[0] = 0;           // Minimum weight = 0 as value = 0
    prev[val[0]] = wt[0]; // To get value = val[0] from taking only 1-item will add a weight of wt[0]

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n * 1000; j++)
        {
            if (val[i] > j) // exclude
                cur[j] = prev[j];
            else
                cur[j] = min(prev[j], prev[j - val[i]] + wt[i]);
        }
        prev = cur;
        fill(cur.begin(), cur.end(), 99999999999999LL);
    }

    long long ans = 0LL;
    for (ll i = 0; i <= n * 1000; i++)
    {
        if (prev[i] <= w)
            ans = i;
    }
    
    cout << ans;
}

int main()
{
    knapsack_less_value();
    return 0;
}