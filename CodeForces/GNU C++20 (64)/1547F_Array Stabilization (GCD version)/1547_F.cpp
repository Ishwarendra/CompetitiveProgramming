#include <bits/stdc++.h>

#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define MOD (int)1000000007
#define endl '\n'
#define sp ' '
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop \
    int t;              \
    cin >> t;           \
    loop(tc, 1, t + 1)
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);cout.tie(NULL);
#define find_ele(ele, set) set.find(ele) != set.end()
#define loop(var, initial, final) for (int var = initial; var < final; var++)
#define rloop(var, init, end) for (int var = init; var >= end; var--)
#define ff first
#define ss second
#define iter(itr, start, end) for (itr = start; itr != end; itr++)
#define yesno(var) cout << (var ? "YES" : "NO") << endl;
#define vpii vector<pii>
#define prt(x) cout << x.first << ' ' << x.second << endl;
#define vrt(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
typedef long long ll;

using namespace std;

vector<int> divisors(int n)
{
    vector<int> ans;
    ans.pb(1);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.pb(i);
            if (n / i != i)
                ans.pb(n / i);
        }
    }
    ans.pb(n);
    return ans;
}
void precision_print(float n, int p)
{
    cout << fixed << setprecision(p) << n << endl;
    return;
}

int ceil_(int n, int k)
{
    return n/k + (bool)(n%k);
}
int _gcd(int a, int b){
    if (a < b) swap(a, b);
    if (b)
        return _gcd(b, a%b);
    return a;
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
// We'll perform binary search on each index to calculate the minimum number of operations reqd to make that ele equal to gcd of the array
// Now, we need an O(1) good fn to get a time complexity of O(nlogn) -> n indices and logn binary search
// So, to get this we'll make use of sparse table to get gcd of a sub-array in O(1) time

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    const int n;
    std::vector<std::vector<T>> mat;
    F func;

    SparseTable(const std::vector<T>& a, const F& f) : func(f), n(std::size(a))
    {
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);

        }
    }

    T get(int from, int to) const
    {
        assert(0 <= from && to <= n - 1 and from <= to);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

int bin_srch(int n, int idx, vi &arr, int g, auto &st){
    int lo = 1, hi = n;
    int ans = n;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (idx + mid - 1 >= n){
            if (_gcd(st.get(idx, n - 1), st.get(0, mid - n + idx - 1)) == g){
                hi = mid - 1;
                ans = min(ans, mid);
                // cout << idx << sp << mid << sp << ans << endl;
            }
            else{
                lo = mid + 1;
            }
        }
        else {
            if (st.get(idx, idx + mid - 1) == g){
                hi = mid - 1;
                ans = min(ans, mid);
                // cout << idx << sp << mid << sp << ans << endl;
            }
            else{
                lo = mid + 1;
            }
        }
    }
    // cout << ans << endl;
    return ans - 1;
}

void solve()
{
    int n; cin >> n;
    
    vi arr(n);
    int g = 0;
    loop(i, 0, n)
    {
        cin >> arr[i];
        g = _gcd(g, arr[i]);
    }

    SparseTable<int> st(arr, [&](int x, int y) { return std::gcd(x, y); });
    int ans = 0;
    loop(i, 0, n){
        if (arr[i] == g) continue;
        ans = max(ans, bin_srch(n, i, arr, g, st));
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int32_t main()
{
    FIO
        test_cases_loop
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
