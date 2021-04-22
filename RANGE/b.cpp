#include<bits/stdc++.h>
using namespace std;
int ma=0;
void dfs(map<int,vector<int>> &m,int src,int n,int vis[],int l)
{
    vis[src]=1;
    
    for(auto nb:m[src])
    {
        if(vis[nb]==1)
        continue;
        dfs(m,nb,n,vis,l+1);
        ma=max(ma,l);
    } 

}
bool isCyclicUtil(map<int,vector<int>> &m,int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        vector<int>::iterator i; 
        for(i = m[v].begin(); i != m[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(m,*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  
    return false; 
} 
  
bool isCyclic(map<int,vector<int>> &m,int n) 
{ 

    bool *visited = new bool[n]; 
    bool *recStack = new bool[n]; 
    for(int i = 0; i < n; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    for(int i = 0; i < n; i++) 
        if (isCyclicUtil(m,i, visited, recStack)) 
            return true; 
  
    return false; 
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
         map<int,vector<int>> m;
         map<int,vector<int>> m1;
         
        for(int i=0;i<e;i++)
        {
            int u,v;
            cin>>u>>v;
            m[v].push_back(u);
            m1[u].push_back(v);
        }
        map<int,set<int>> ans;
        
        
    bool res=isCyclic(m,n);
    if(res==true)
    {cout<<"Not Possible!"<<endl;
    continue;}

    for(int i=0;i<n;i++)
    {
        int vis[n]={0};
        ma=0;
        dfs(m1,i,n,vis,0);
        ans[ma].insert(i);
        cout<<ma<<" ";
    }
    for(auto it=ans.begin();it!=ans.end();it++)
    {
        set<int> s=it->second;
        for(auto it1=s.begin();it1!=s.end();it1++)
        cout<<*it1<<" ";
        cout<<endl;
    }
    }
    return 0;
}