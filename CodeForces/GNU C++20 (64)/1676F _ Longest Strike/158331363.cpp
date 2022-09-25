#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define endl '\n'
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<ll> a(n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        vector<int> v;
        for(auto u:m){
            if(u.second>=k){
                v.push_back(u.first);
            }
        }
        sort(v.begin(),v.end());
        int p=0;
        int c=0;
        int l=-1,r=-1;
        for(int i=1;i<v.size();i++){
            if(v[i]!=v[i-1]+1){
                if(i-p>c){
                    c=i-p;
                    r=v[i-1];
                    l=v[i-1]-(i-p)+1;
                }
                p=i;
            }
        }
        if(v.size()-p>c){
            c=p;
            r=v.back();
            l=v.back()-v.size()+p+1;
        }
        if(l==-1){
            cout<<-1<<endl;
        }
        else{
            cout<<l<<" "<<r<<endl;
        }
    }
}