#include <bits/stdc++.h>
using namespace std;
int dp[200001][2];
void dfs(map<int, vector<int>> &m, int src, int par)
{  
    int s=0;
    for (auto nb : m[src])
    {
        if (nb == par)
            continue;
        dfs(m, nb, src);
        s=s+max(dp[nb][0],dp[nb][1]);
    }
  dp[src][0]=s;
  dp[src][1]=0;
  for(auto nb:m[src])
  {
      if(nb==par)
      continue;
      dp[src][1]=max(dp[src][1],s-max(dp[nb][0],dp[nb][1])+dp[nb][0]+1);
  }
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
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
        dp[i][1]=0;
    }
    dfs(m, 1, 1);
    cout<<max(dp[1][0],dp[1][1])<<endl;
    return 0;
}