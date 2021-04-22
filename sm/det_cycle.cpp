#include<bits/stdc++.h>
using namespace std;
bool dfs(int src,map<int,vector<int>> &m,int n,int vis[],stack<int> &s)
{
   vis[src]=2;
   s.push(src);
  // cout<<src<<endl;
   for(auto nb:m[src])
   {
       if(vis[nb]==2)
       {
           cout<<"1"<<endl;
           while(!s.empty()&&s.top()!=nb)
           {
               cout<<s.top()<<" ";
               s.pop();
           }
           cout<<nb<<endl;
           return true;
       }
       if(vis[nb]==1)
       continue;
       if(dfs(nb,m,n,vis,s))
       return true;
   }
   s.pop();
   vis[src]=1;
   return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    map<int,vector<int>> m;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);
    }
    int f=-1;
    int vis[n]={0};
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(vis[i])
        continue;
        if(dfs(i,m,n,vis,s))
        {
            f=1;
            break;
        }
    }
    if(f==-1)
    cout<<"0"<<endl;
    return 0;
}