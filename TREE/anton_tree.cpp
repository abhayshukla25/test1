#include<bits/stdc++.h>
using namespace std;
int ans=-1;
int dfs(map<int, vector<int>> &m, int src, int par,int col[])
{  
    int x=0,y=0;
    for (auto nb : m[src])
    {
        if (nb == par)
            continue;
       int h= dfs(m, nb, src,col);
       if(col[nb-1]==col[src-1])
       h--;
       if(h>x)
       {  y=x;
           x=h;
           }
       else if(h>y)
       y=h;
    }
  ans=max(ans,x+y);
  //cout<<src<<"="<<ans<<" "<<x<<" "<<y<<endl;
  return x+1;
}
int main()
{
    int n;
    cin >> n;
    int col[n];
    for(int i=0;i<n;i++)
    cin>>col[i];
   
    map<int, vector<int>> m;
    for (int i = 2; i <= n; i++)
    {
        int x,y;
        cin >> x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    ans=-1;
    dfs(m, 1, 1,col);
    cout<<(ans+1)/2<<endl;
    return 0;
}