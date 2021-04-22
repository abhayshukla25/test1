#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

map<pair<ll, ll>,ll> m;
ll dfs(ll i,ll j,ll x)
{
    if(i==0||j==0)
    return x;
    if(m.find({i,j})!=m.end())
    { auto it=m.find({i,j});
    return (it->second)%mod;}
    ll res=0;
    for(ll p=0;p<=i;p++)
    res=((res%mod)+(dfs(p,j-1,x)%mod))%mod;
    if(res<0)
    res=res+mod;
    m.insert({{i,j},res});
    return res;
}  
int main()
{  
    
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