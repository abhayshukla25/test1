#include<bits/stdc++.h>
using namespace std;
int dp[200001][19];
void dfs(int src,int pr,map<int,vector<int>> &m,int par[])
{
    dp[src][0]=par[src];
    for(int i=1;i<19;i++)
        dp[src][i]=dp[dp[src][i-1]][i-1];
    for(auto nb:m[src])
    {
        if(nb==pr)
        continue;
        dfs(nb,src,m,par);
    }
}
int main()
{
    int n,q;
    cin >> n>>q;
    int par[n+1];
    par[1]=-1;
    map<int,vector<int>> m;
    for(int i=2;i<=n;i++)
    {  cin>>par[i];
       m[par[i]].push_back(i);
       m[i].push_back(par[i]);}

    for(int i=0;i<=n;i++)
    {  
        for(int j=0;j<19;j++)
        dp[i][j]=-1;
    }
    dfs(1,1,m,par);
    for(int i=1;i<=q;i++)
    { 
       int a,b;
       cin>>a>>b;  
       int k=a;
       for(int j=18;j>=0;j--)
       {
           if(b&&(1<<j))
           k=dp[k][j];
           if(k==-1)
           break;
       }
       cout<<k<<endl;
    }
    return 0;
}