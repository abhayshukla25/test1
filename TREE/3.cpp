#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() 
{ 
	ll x,y,z;
	cin>>x>>y>>z;
	ll a[x],b[y],c[z];
    ll s=0;
	for(ll i=0;i<x;i++)
	   cin>>a[i],s+=a[i];
	for(ll i=0;i<y;i++)
	   cin>>b[i],s+=b[i];
	for(ll i=0;i<z;i++)
	   cin>>c[i],s+=c[i];
	sort(a,a+x);
	sort(b,b+y);
	sort(c,c+z);
	ll ans=INT64_MAX;
    ans=min(ans,a[0]+b[0]);
    ans=min(ans,a[0]+c[0]);
    ans=min(ans,b[0]+c[0]);

	 cout<<s-2*ans; 
 }
  
int main()
{
   solve();
    return 0;
}