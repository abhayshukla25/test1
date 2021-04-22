#include <bits/stdc++.h>
using namespace std;
int ans;
int dfs(map<int, vector<int>> &m, int src, int par)
{  
    int x=0,y=0;
    for (auto nb : m[src])
    {
        if (nb == par)
            continue;
       int h= dfs(m, nb, src);
     //  cout<<h<<",";
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
    map<int, vector<int>> m;
    for (int i = 2; i <= n; i++)
    {
        int x,y;
        cin >> x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    ans=0;
    dfs(m, 1, 1);
    cout<<ans<<endl;
    return 0;
}