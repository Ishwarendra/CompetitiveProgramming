#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

// https://atcoder.jp/contests/dp/tasks/dp_c
void vacation()
{
    int n; cin >> n;
    int a, b, c;

    cin >> a >> b >> c;    
    ll x_1 = a, y_1 = b, z_1 = c, x_2, y_2, z_2; // x = f(0, i - 1), y = f(1, i - 1), z = f(2, i - 1)

    for(int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        x_2 = a + max(y_1, z_1);
        y_2 = b + max(x_1, z_1);
        z_2 = c + max(x_1, y_1);

        x_1 = x_2, y_1 = y_2, z_1 = z_2;
    }

    cout << max({x_1, y_1, z_1}) << endl;
}

int main()
{
    vacation();
    return 0;
}