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
    if(b[0]<min(a[0],c[0]))
    {
    	
    }
    else if(a[0]<min(b[0],c[0]))
    {
    	s1=s1-a[0];
    	if(b[0]<c[0])
    	{
    		s2=s2-b[0];
            if(b[0]-s1<0)
    		s3=s3+s1-b[0];
    	   else
    	   	s2=s2+b[0]-s1;
    		ans=s3+s2-a[0];
    	}
    	else
    	{
    		s3=s3-c[0];
            if(c[0]-s1<0)
    		s2=s2+s1-c[0];
            else
             s3=s3+c[0]-s1;    
    		ans=s3+s2-a[0];
    	}
    }
    else
    {
    	s3=s3-c[0];
    	if(a[0]<b[0])
    	{
    		s1=s1-a[0];
            if(a[0]-s3<0)
    		s2=s2+s3-a[0];
            else
            s1=s1+a[0]-s3;
            
    		ans=s2+s1-c[0];
    	}
    	else
    	{
    		s2=s2-b[0];
            if(b[0]-s3<0)
    		s1=s1+s3-b[0];
            else
            s2=s2+b[0]-s3;
            
    		ans=s2+s1-c[0];
    	}
    }

	 cout<<ans; 
 }
  
int main()
{
   solve();
    return 0;
}