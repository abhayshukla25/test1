#include<bits/stdc++.h>
using namespace std;
int ans;
void recur(int i,int dis,int c,int a[],int b[],bool vis[],int n)
{   
    if(dis>ans)
    return;
    if(c==n)
    {
      ans=min(ans,dis+abs(a[i]-a[n+1])+abs(b[i]-b[n+1]));
      return;
    }
    //cout<<c<<" "<<dis<<endl;
    vis[i]=true;
    for(int j=1;j<=n;j++)
    {
        if(vis[j])
        continue;
        int z=dis+abs(a[i]-a[j])+abs(b[i]-b[j]);
        recur(j,z,c+1,a,b,vis,n);
    }
    vis[i]=false;
    return;
}
int main()
{  
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[n+2];
    int b[n+2];
    bool vis[n+2];
    for(int i=0;i<n+2;i++)
    {
      cin>>a[i]>>b[i];
      vis[i]=false;
    }
    swap(a[1],a[n+1]);
    swap(b[1],b[n+1]);
    ans=INT_MAX;
    recur(0,0,0,a,b,vis,n);
    cout<<ans<<endl;
    }
    return 0;
}