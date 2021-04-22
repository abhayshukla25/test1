#include<bits/stdc++.h>
using namespace std;
int b[505][505];
int dp[505][505];
int maxpathsum1(int n,int m,int i,int j)
{
    if(i<0||i>=n||j<0||j>=m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int s=b[i][j]+max(maxpathsum1(n,m,i+1,j),max(maxpathsum1(n,m,i+1,j-1),maxpathsum1(n,m,i+1,j+1)));
    return dp[i][j]=s;

}
int maxpathsum2(int n,int m,int i,int j)
{
    if(i<0||i>=n||j<0||j>=m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int s=b[i][j]+max(maxpathsum2(n,m,i-1,j),max(maxpathsum2(n,m,i-1,j-1),maxpathsum2(n,m,i-1,j+1)));
    return dp[i][j]=s;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>b[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        dp[i][j]=-1;
    }
    int p,q;
    cin>>p>>q;
    int x=maxpathsum1(n,m,0,p);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        dp[i][j]=-1;
    }
    int y=maxpathsum2(n,m,n-1,q);
    //cout<<x<<" "<<y<<endl;
    cout<<max(x,y)<<endl;
    return 0;
}