#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
     cin>>a[i];
     vector<int> vis(n,-1);
      vis[0]=a[0];
      for(int i=0;i<n;i++)
      {   
          int p=a[i];
          for(int j=i+1;j<n;j++)
          {
              if(a[j]%p==0)
          }
      }
    }
    return 0;
}