#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include <unordered_set>
#include<algorithm>
#include <numeric>
#include<cstdlib>
#include <chrono>
#include <random>
#include <cstring>
#include<bitset>
#include<iomanip>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <cassert>
#define pb push_back
#define int long long int
#define INF 1000000
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int mod= 1e9 +7;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt=1;
   //cin>>tt;
   
    while(tt-->0){
       
       int n,m,k;
       cin>>n>>m>>k;
       vector<vector<int>> g(n+1);
       int i;
       int a,b,c;
       for(i=0;i<m;i++){
        c=1;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);

       }
       vector<vector<int> > dist(n+1,vector<int>(n+1,INF));//(n+1 X (n+1)
       
        vector<vector<int> > path(n+1,vector<int>(n+1));
       set<vector<int> > possible;
       for(i=0;i<k;i++){
          cin>>a>>b>>c;
          possible.insert({a,b,c});
         
       }
       if(n==2){
           cout<<1<<'\n';
           cout<<1<<' '<<2<<'\n';
           return 0;
       }
       priority_queue<vector<int> >pq;
        for(i=1;i<=n;i++)dist[1][i]=0;
       for(int node  : g[1]){
           dist[node][1]=1;
           pq.push({-dist[node][1],node,1});
       }
       
     
     
       while(!pq.empty()){
             int dis =-pq.top()[0];
             int curr = pq.top()[1];
             int last= pq.top()[2];
            
             pq.pop();
             if(dist[curr][last]<dis)continue;
       
             for(int node: g[curr]){
                 auto pos =possible.find({last,curr,node});
               if(pos==possible.end()){
               
              
                    if(dist[node][curr]>dist[curr][last] + 1){
                         dist[node][curr]=dist[curr][last]+1;
                         pq.push({-dist[node][curr],node,curr});
                          path[node][curr]=last;
                         
                    }
               }
             }
       }
      int ans= INF;
      for(i=1;i<=n;i++){
          ans=min(ans,dist[n][i]);
      }
      if(ans==INF)cout<<-1<<'\n';
      else{
          cout<<ans<<'\n';
          vector<int>st;
          int nd = n;
          int mn,id;
        
            mn=INF;
              id=-1;
              for(int i : g[nd]){
                  if(dist[nd][i]<mn){
                      mn=dist[nd][i];
                      id=i;
                  }
              }
             
              mn=INF;
              int x=nd;
              int y =id;
              int z = path[nd][id];
              st.pb(x);
              st.pb(y);
         int counter=0;
          while(z!=1){
              st.pb(z);
              //st.pb(y);
              //st.pb(z);
              x=y;
              y=z;
              z=path[x][y];
              counter++;
              assert(counter<=1e7);
          }
         if(st.back()!=1)st.pb(1);
          reverse(st.begin(),st.end());
          // for(int x : st)cout<<x<<' ';
      }

}
}