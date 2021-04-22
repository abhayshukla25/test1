#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,q;
       cin>>n>>q;
       int a[n];
       for(int i=0;i<n;i++)
       cin>>a[i];
       int b[n];
       int c[n];
       b[0]=a[0];
       c[n-1]=a[n-1];
       for(int i=1;i<n;i++)
       b[i]=b[i-1]|b[i];
       for(int i=n-2;i>=0;i--)
       c[i]=c[i+1]|c[i];
        cout<<b[n]<<endl;
       for(int i=0;i<q;i++)
       {
          int x,y;
          cin>>x>>y;
          int ans;
          if(x==0&&n==1)
          ans=y;
          else if(x==0)
          ans=y|c[1];
          else if(x==n-1)
          ans=b[n-2]|y;
          else
          {ans=y|b[x-1];
          ans=ans|c[x+1];}
          cout<<ans<<endl;
       }
   }
   return 0;
}