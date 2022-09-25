#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
#define all(a)     ((a).begin()), ((a).end())
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
 
#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};
 
using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};
 
int get_min_diff(vi &a, int x)
{
 int minimum = 1e10;
 int id = 0;
 
 for(int i = 0; i < a.size(); i++)
 {
  if (abs(x - a[i]) < minimum)
   id = i, minimum = abs(x - a[i]);  
 }
 
 return id; 
}
 
void solve()
{
 int n; cin >> n;
 
 vi a(n), b(n);
 
 for(int i = 0; i < n; i++)
  cin >> a[i];
 for(int i = 0; i < n; i++)
  cin >> b[i];
 
 int sum = 0;
 
 // Case-1
 sum = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
 
 // Case-2
 sum = min(sum, abs(a[n - 1] - b[0]) + abs(a[0] - b[n - 1]));
 
 int a0b = get_min_diff(b, a[0]);
 int anb = get_min_diff(b, a[n - 1]);
 int b0a = get_min_diff(a, b[0]);
 int bna = get_min_diff(a, b[n - 1]);
 
 int mini1 = abs(b[a0b] - a[0]),
  mini2 = abs(b[anb] - a[n - 1]),
  mini3 = abs(a[b0a] - b[0]),
  mini4 = abs(a[bna] - b[n - 1]);
  
 // Case-3
 sum = min(sum, abs(a[0] - b[0]) + mini2 + mini4);
 
 //case-4
 sum = min(sum, abs(a[0] - b[n - 1]) + mini2 + mini3);
 
 //case-5
 sum = min(sum, abs(b[0] - a[n - 1]) + mini1 + mini4);
 
 //case-6 7
 sum = min(sum, abs(a[n - 1] - b[n - 1]) + mini1 + mini3);
 
 sum = min(sum, mini1 + mini2 + mini3 + mini4);
 
 // print(mini1, mini2, mini3, mini4)
 
 cout << sum << "\n";
}
 
int32_t main()
{
 std::ios::sync_with_stdio(false);
 std::cin.tie(nullptr);
 
 int t = 1;
 cin >> t;
 
 for(int i = 1; i <= t; i++)
 {
  // cout << "Case #" << i << ": ";
  solve();
 }
 
 return 0;
}