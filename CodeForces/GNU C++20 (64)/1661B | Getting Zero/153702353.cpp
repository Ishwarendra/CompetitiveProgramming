#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=32768;
 
ll func(ll x, vector<ll> &v1)
{
 if (v1[x] != -1)
  return v1[x];
 
 v1[x] = 1 + func((x * 2) % MOD, v1);
 v1[x] = min(v1[x], 1LL + func((x + 1) % MOD, v1));
 return v1[x];
}
 
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> v1(40000,-1);
    v1[0]=0;
    for(int i=0;i<n;i++){
        ll ans=func(arr[i],v1);
        cout<<ans<<' ';
    }
    // cout<<func(0,v1)<<"\n"<<func((1 << 15) - 1,v1);
}