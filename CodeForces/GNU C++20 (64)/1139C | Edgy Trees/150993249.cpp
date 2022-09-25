#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
#define all(a)      ((a).begin()), ((a).end())
#define log(v)      for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int         long long
#define fps(x, y)   fixed<<setprecision((y))<<(x)
 
#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};
 
using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename T>
using maxheap  =    priority_queue<T>;
template<typename T>
using minheap  =    priority_queue<T, vector<T>, greater<T>>;
 
template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};
 
constexpr int mod = 1e9 + 7;
int n, k;
vvi adj;
 
template<class T>
T power(T a, T b) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res % mod) * (a % mod) % mod;
        }
    }
    return (res % mod);
} 
 
void dfs(int cur, vector<bool> &vis, int &cnt)
{
 vis[cur] = true;
 cnt++;
 
 for (int nb : adj[cur])
 {
  if (not vis[nb])
   dfs(nb, vis, cnt);
 }
}
 
void solve()
{
 cin >> n >> k;
 
 adj.resize(n + 1);
 
 for (int i = 0; i < n - 1; ++i)
 {
  int u, v, x;
  cin >> u >> v >> x;
  
  if (x == 0)
  {
   adj[u].push_back(v);
   adj[v].push_back(u);
  }
 } 
 
 std::vector<bool> vis(n + 1);
 
 int ans = power(n, k);
 
 for (int i = 1; i <= n; ++i)
 {
  int cnt = 0;
  
  if (not vis[i])
  {
   dfs(i, vis, cnt);
   ans -= power(cnt, k);
   
   if (ans < 0)
    ans += mod;
  }
 }
 
 std::cout << (ans + mod) % mod << "\n";
}
 
int32_t main()
{
 std::ios::sync_with_stdio(false);
 std::cin.tie(nullptr);
 
 int t = 1;
 // std::cin >> t;
 
 for(int i = 1; i <= t; i++)
 {
  // std::cout << "Case #" << i << ": ";
  solve();
 }
 
 return 0;
}