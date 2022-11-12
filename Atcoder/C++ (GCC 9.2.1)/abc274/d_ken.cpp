#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";
using namespace std;

bool canPartition(vector<int>& nums) {
    ll totalSum = accumulate(begin(nums), end(nums), 0LL), halfSum = totalSum / 2;
    if (totalSum & 1) return false;
    vector<bool> dp(totalSum + 100002);
    dp[100000] = true;
    for (int num : nums)
        for (int j = totalSum; j >= num; j--)
            if (dp[j - num + 100000])
                dp[j + 100000] = true;

    return dp[halfSum + 100000];
}

int main()
{
    FIO
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> horz;
    vector<int> vert = {y};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i == 0) {
            horz.push_back(x - a);
        }
        else if (i % 2 == 0) {
            horz.push_back(a);
        }
        else {
            vert.push_back(a);
        }
    }
    // for(int &a : horz) if(a != 0) a += 11;
    // for(int &a: vert) if(a != 0) a += 11;
    // for(int a: horz) cout << a << " ";
    // cout << "\n";
    // for(int a: vert) cout << a << " ";
    // cout << "\n";
    if (canPartition(horz) && canPartition(vert)) YES
        else NO
            return 0;
}