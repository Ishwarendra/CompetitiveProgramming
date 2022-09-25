#include <bits/stdc++.h>
using namespace std;
 
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
 
int main()
{
    int n; cin >> n;
    vector<ll> x(n);
 
    for(int i = 0; i < n; i++)
        cin >> x[i];
 
    ll cur_min, cur_max;
 
    cur_min = x[1] - x[0];
    cur_max = x[x.size() - 1] - x[0];
 
    cout << cur_min << " " << cur_max << endl;
 
    for(int i = 1; i < n - 1; i++)
    {
        cur_min = min(x[i] - x[i - 1], x[i + 1] - x[i]);
        cur_max = max(x[i] - x[0], x[n - 1] - x[i]);
 
        cout << cur_min << " " << cur_max << endl;
    }
    
    cur_min = x[n - 1] - x[n - 2];
    cur_max = x[n - 1] - x[0];
 
    cout << cur_min << " " << cur_max << endl;
    cerr << "aise hi";
    return 0;
}