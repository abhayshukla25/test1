#include <bits/stdc++.h>
using namespace std;

void dfs( int src, int par,int l,map<int, vector<int>> &m,vector<int> &lev)
{  
    lev[src]=l;
    for (auto nb : m[src])
    {
        if (nb == par)
            continue;
       dfs(nb,src,l+1,m,lev);
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
    vector<int> lev1(n+1,0);
    dfs(x,x,0,m,lev1);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {   
    int value=INT_MAX;
    int c;
    int y,z;
    cin>>y>>z;
    vector<int> lev2(n+1,0);
    vector<int> lev3(n+1,0);
    dfs(y,y,0,m,lev2);
    dfs(z,z,0,m,lev3);
    cout<<c<<endl;
    }
    return 0;
}