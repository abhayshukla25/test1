#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll m=-1000000000;
        for(ll i=0;i<n;i++)
        {  cin>>a[i];
         m=max(m,a[i]);}
        int f=-1;
        for(ll i=0;i<n-2;i++)
        {
           if(a[i]>m)
           {
               f=1;
               break;
           }
           ll k=m-a[i];
           a[i]+=k;
           if((a[i+1]>m-k)||(a[i+2]>m-k))
           {
               f=1;
               break;
           }
           a[i+1]+=k;
           a[i+2]+=k;
        }
        if(a[n-2]!=m)
        f=1;
        if(a[n-1]!=m)
        f=1;
        if(f==1)
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
    }
    return 0;
}