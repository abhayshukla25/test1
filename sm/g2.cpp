#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int n,m;
        cin>>n>>m;
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          cin>>dp[i][j];
        }
        map<pair<int,int>,vector<int>> mp;
        for(int i=0;i<m;i++)
        {
            int u=0;
            for(int j=0;j<n;j++)
            {
                if(dp[j][i]==0)
                {  u=0;
                    continue;}
              mp[{j,i}].push_back(u+1);
              u++;
            }
        }
        for(int i=0;i<m;i++)
        {
            int d=0;
            for(int j=n-1;j>=0;j--)
            {
                if(dp[j][i]==0)
               {d=0; continue;}
               
                mp[{j,i}].push_back(d+1);
              d++;
            }
        }
         for(int i=0;i<n;i++)
        {
            int l=0;
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==0)
               {l=0; continue;}
             mp[{i,j}].push_back(l+1);
              l++;
            }
        }
    
         for(int i=0;i<n;i++)
        {
            int r=0;
            for(int j=m-1;j>=0;j--)
            {
                if(dp[i][j]==0)
               {r=0; continue;}
               mp[{i,j}].push_back(r+1);
                 r++;
            }
        }
    
      int ans=0;
      for(auto it=mp.begin();it!=mp.end();it++)
      {  
          vector<int> v=it->second;
          if((v[0]<2&&v[1]<2)||(v[2]<2&&v[3]<2))
          continue;
          cout<<(it->first).first<<" "<<(it->first).second<<" "<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" ";
        
          if(v[0]>1)
          {
             int k=v[3];
             k=k/2;
             if(k>=2)
             {  
                 if(k<=v[0])
                 ans+=k-2+1;
                 else
                 ans+=v[0]-2+1;
             }
              k=v[2];
             k=k/2;
             if(k>=2)
             {  
                 if(k<=v[0])
                 ans+=k-2+1;
                 else
                 ans+=v[0]-2+1;
             }
          }
           if(v[1]>1)
          {
             int k=v[3];
             k=k/2;
             if(k>=2)
             {  
                 if(k<=v[1])
                 ans+=k-2+1;
                 else
                 ans+=v[1]-2+1;
             }
              k=v[2];
             k=k/2;
             if(k>=2)
             {  
                 if(k<=v[1])
                 ans+=k-2+1;
                 else
                 ans+=v[1]-2+1;
             }
          }
           if(v[2]>1)
          {
             int k=v[0];
             k=k/2;
             if(k>=2)
             {  
                 if(k<=v[2])
                 ans+=k-2+1;
                 else
                 ans+=v[2]-2+1;
             }
              k=v[1];
             k=k/2;
             if(k>=2)
             {  
                 if(k<=v[2])
                 ans+=k-2+1;
                 else
                 ans+=v[2]-2+1;
             }
          }
           if(v[3]>1)
          {
             int k=v[0];
             k=k/2;
             if(k>=2)
             {  
                 if(k<=v[3])
                 ans+=k-2+1;
                 else
                 ans+=v[3]-2+1;
             }
              k=v[1];
             k=k/2;
             if(k>=2)
             {  
                 if(k<=v[3])
                 ans+=k-2+1;
                 else
                 ans+=v[3]-2+1;
             }
          }
          cout<<ans<<endl;
      }
      cout<<ans<<endl;
    }
   return 0;
}