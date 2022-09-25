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
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};
 
vector<vector<int>> adj(26);
vi indeg(26);
 
bool first_diff(string &a, string &b)
{
 // a < b
 for (int i = 0; i < std::min(a.size(), b.size()); i++)
 {
  if (a[i] != b[i])
  {
   adj[a[i] - 'a'].push_back(b[i] - 'a');
   indeg[b[i] - 'a']++;
   return true;
  }
 }
 
 return a.size() < b.size(); // b is a prefix of a (impossible)
}
 
void solve()
{
 int n; cin >> n;
 
 vector<string> names;
 
 for (int i = 0; i < n; i++)
 {
  string s; cin >> s;
  names.push_back(s);
 }
 
 for (int i = 1; i < n; i++)
 {
  bool exist = first_diff(names[i - 1], names[i]);
 
  if (!exist)
  {
   std::cout << "Impossible\n";
   return;
  }
 }
 
 queue<int> q;
 vi path;
 
 for (int i = 0; i < 26; i++)
 {
  if (indeg[i] == 0)
   q.push(i);
 }
 
 while (!q.empty())
 {
  int cur = q.front();
  q.pop();
 
  if (indeg[cur] == 0)
   path.push_back(cur);
 
  for (int nb : adj[cur])
  {
   indeg[nb]--;
 
   if (indeg[nb] == 0)
    q.push(nb);
  }
 }
 
 
 if (path.size() == 26) {
  for (int i = 0; i < 26; i++)
   std::cout << (char)(path[i] + 'a');
 
  std::cout << "\n";
 }
 else
  std::cout << "Impossible\n";
 
}
 
int32_t main()
{
 std::ios::sync_with_stdio(false);
 std::cin.tie(nullptr);
 
 int t = 1;
 // std::cin >> t;
 
 for (int i = 1; i <= t; i++)
 {
  // std::cout << "Case #" << i << ": ";
  solve();
 }
 
 return 0;
}