#include<bits/stdc++.h>
using namespace std;
int calc(int h[],int c[],int m,int n)
{
    int res=0;
    for(int i=0;i<n;i++)
        res=res+(abs(h[i]-m))*c[i];
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {  
        cout<<"ok"<<endl;
        int n;
        cin>>n;
        int h[n];
        int r=INT_MIN,l=0;
        for(int i=0;i<n;i++)
       { 
         cin>>h[i];
         r=max(r,h[i]);
       }
        int cost[n];
        for(int i=0;i<n;i++)
        cin>>cost[i];
        
        while(r-l>3)
        {
           int m1=l+(r-l)/3;
           int m2=r-(r-l)/3;
           int v1=calc(h,cost,m1,n);
           int v2=calc(h,cost,m2,n);
          if(v1>v2)
          l=v1;
          else 
          r=v2;
        }
        int k1=calc(h,cost,l,n);
        int k2=calc(h,cost,l+(r-l)/2,n);
        int k3=calc(h,cost,r,n);
        int res=min(k1,min(k2,k3));
        cout<<res<<endl;
    }
}