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
 
constexpr int inf = 7e12;
 
// vi par;
vector<pii> *adj;
 
vi dijkstra(int n, int src)
{
 // fill(all(par), 0);
 
 vi dist(n + 1, inf);
 
 set<pii> edges;
 edges.emplace(0, src);
 dist[src] = 0;
 
 while (!edges.empty())
 {
  auto it = edges.begin();
  int node = it->second, cost = it->first;
  edges.erase(it);
  
  for (auto nb : adj[node])
  {
   if (dist[nb.first] > dist[node] + nb.second)
   {
    edges.erase({dist[nb.first], nb.first});
    dist[nb.first] = dist[node] + nb.second;
    // par[nb.first] = node;
    edges.insert({dist[nb.first], nb.first});
   }
  }
 }
 
 return dist;
}
 
int get_ans(int i, int j, vvi &route, vvi &d)
{
 int ans = 0;
 int n = d.size() - 1;
 
 for (int _ = 0; _ < route.size(); _++)
 {
  int u = route[_][0], v = route[_][1];
  // print(i, v, d.size(), d[1].size())
  ans += min({d[u][v], d[u][i] + d[j][v], d[u][j] + d[i][v]});    
 }
 
 return ans;
}
 
void solve()
{
 int n, m, k;
 cin >> n >> m >> k;
 
 adj = new vector<pair<int, int>>[n + 1];
 // par.resize(n + 1);
 map<pair<int, int>, int> weights;
 
 for (int i = 0; i < m; i++)
 {
  int u, v, w; 
  cin >> u >> v >> w;
  adj[u].push_back({v, w});
  adj[v].push_back({u, w});
  
  weights[{u, v}] = weights[{v, u}] = w;
 }
 
 vvi apsp(n + 1);
 
 for (int i = 1; i <= n; i++)
  apsp[i] = dijkstra(n, i);
 
 int ans = inf;
 
 vvi route(k, vi(2));
 
 for (int i = 0; i < k; i++)
  cin >> route[i][0] >> route[i][1];
 
 for (auto i : weights)
 {
  int u = i.first.first, v = i.first.second;
  
  ans = min(ans, get_ans(u, v, route, apsp)); 
 }
 
 cout << ans << "\n";
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
/* credits: harasees_singh :maaf_karo:
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/