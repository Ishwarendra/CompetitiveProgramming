#include<bits/stdc++.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
using namespace std;
 
 
int main()
{
 
    int t,flag,val;   cin>>t;
      while(t--){
    long long int tem,k,counts;
     //  long long int a[200009];
    // long long int b[200009];long long int pp[200009];
 
        long long int i,x,y,z,j,rem;
 
        unordered_map<int,int> mp,mm;
     //    vector<long long int>ar;
  //      vector<string>s
  //long long int ans,btt,q,h,l,r,nn,n;
 long long int aa,bb,d,m,sum,cc,n;
  // double a,b,c,d,pp,m;
 
    cin>>n;
sum=0;
for(i=0;i<n;i++){
        char c;
cin>>c;
    if(c=='0'){
        mp[i+1]=1;
    }
}
 
for(i=1;i<=n;i++){
 
    for(j=i;j<=n;j+=i){
            if(mp[j]==0){
            break;
        }
            if(mp[j]==1){
            sum+=i;
            mp[j]=2;}
           //  cout<<" j "<<j<<" ";
 
    }}
 
cout<<sum;
    cout<<"\n";
}
}
 