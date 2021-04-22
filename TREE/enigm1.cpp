#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 ll** dp = new ll*[100001];
   
 
    // assign values to allocated memory
    
ll dfs(ll i,ll j,ll x)
{
    if(i==0||j==0)
    return x;
  //  if(dp[i][j]!=-1)
    //return dp[i][j];
    ll res=0;
    for(ll p=0;p<=i;p++)
    res=((res%mod)+(dfs(p,j-1,x)%mod))%mod;
       
    return res;
}  
int main()
{  
     for (ll i = 0; i < 100001; i++)
        dp[i] = new ll[100001];
        for(ll i=0;i<100001;i++)
        for(ll j=0;j<100001;j++)
        dp[i][j]=-1;
    int t;
    cin>>t;
    while(t--)
    {
      ll x,i,j;
      cin>>x>>i>>j;
       ll k=dfs(i,j,x)%mod;
    
      cout<<k<<endl;
    }
    return 0;
}