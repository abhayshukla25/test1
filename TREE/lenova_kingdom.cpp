#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs1( int src, int par,int l,map<int, vector<int>> &m,vector<int> &lev)
{  
    lev[src]=l;
    for (auto nb : m[src])
    {
        if (nb == par)
            continue;
       dfs1(nb,src,l+1,m,lev);
    }

}
void dfs2( int src, int par,map<int, vector<int>> &m,vector<int> &count)
{  
    
    for (auto nb : m[src])
    {
        if (nb == par)
            continue;
            dfs2(nb,src,m,count);
       count[src]+=count[nb];
    }
   count[src]++;
}
int main()
{
    int n,k;
    cin>>n>>k;
    map<int, vector<int>> m;
    for (int i = 2; i <= n; i++)
    {
        int x,y;
        cin >> x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    ll ans=0;
    vector<int> lev(n+1,0);
    vector<int> count(n+1,0);
    dfs1(1,1,0,m,lev);
    dfs2(1,1,m,count);
    vector<int> hap;
    for(int i=1;i<=n;i++)
    {   
      //  cout<<lev[i]<<" "<<count[i]<<endl;
        hap.push_back(lev[i]-count[i]+1);
    }
    sort(hap.begin(),hap.end(),greater<int>());
    for(int i=0;i<k;i++)
    ans=ans+hap[i];
    cout<<ans<<endl;
    return 0;
}