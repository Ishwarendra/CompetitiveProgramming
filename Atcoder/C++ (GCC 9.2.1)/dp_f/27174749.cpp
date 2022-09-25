#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> val(n), wt(n);

    for(int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    const int v = 1000 * n + 1;
    vector<ll> prev(v, 99999999999999LL);
    vector<ll> cur(v, 99999999999999LL);

    // Base-Case
    prev[0] = 0;
    prev[val[0]] = wt[0];

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= v; j++)
        {
            if (val[i] > j) 
                cur[j] = prev[j];
            else    
                cur[j] = min(prev[j], prev[j - val[i]] + wt[i]);
        }
        prev = cur;
        fill(cur.begin(), cur.end(), 99999999999999LL);
    }

    ll ans = 0LL;
    for(ll i = 0; i < v; i++)
    {
        if (prev[i] <= w)
            ans = i;
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