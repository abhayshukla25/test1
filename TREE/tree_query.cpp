#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs1( int src, int par,int l,map<int, vector<int>> &m,vector<int> &lev,vector<int> &parant)
{  
    lev[src]=l;
    parant[src]=par;
    for (auto nb : m[src])
    {
        if (nb == par)
            continue;
       dfs1(nb,src,l+1,m,lev,parant);
    }
}

int main()
{
    int n,x;
    cin>>n>>x;
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
    vector<int> parant(n+1,-1);
    dfs1(x,x,0,m,lev,parant);
    parant[x]=-1;
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {   
    int value=INT_MAX;
    int c;
    int y,z;
    cin>>y>>z;
    int par=y;
    int k=y;
    map<int,int> m1;
    m1[y]=lev[y];
    while(k!=-1)
    {
      par=parant[k];
      if(par!=-1)
      m1[par]=lev[k]-1;
      k=par;
    }
    k=z;
    par=z;
    while(k!=-1)
    {
      
      if(m1.find(par)!=m1.end())
      {
         if(value>(lev[y]+lev[z]-m1[par]))
         {
             value=lev[y]+lev[z]-m1[par];
             c=par;
         }
      }
      par=parant[k];
      k=par;
    }
    cout<<c<<endl;
    }
    return 0;
}