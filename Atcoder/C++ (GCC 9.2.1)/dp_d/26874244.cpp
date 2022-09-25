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

    for(int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];
    
    vector<vector<ll>> dp(n, vector<ll>(w + 1));
    // dp[i, w] => max profit considering first (i + 1) choices with "target on w" i.e (choose or not choose w);
    // i -> items_count u can pick (0 - based), w -> weight of knapsack

    // Base-Case (if u can pick first item then pick it up)
    for(int i = wt[0]; i <= w; i++)
    {
        dp[0][i] = val[0];
    }

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
    //     for(int j = 0; j <= w; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n-1][w];
}


int main()
{
    knapsack_less_weight();
    return 0;
}