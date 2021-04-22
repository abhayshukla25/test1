 
#include <bits/stdc++.h> 
using namespace std; 
 
 int c=0;
 void dfs(vector<vector<char>> &dp,int n,int m,int i,int j)
 {
	 if(i>=n||j>=m||i<0||j<0)
	 return;
	 if(dp[i][j]!='.')
	 return ;
	 dp[i][j]='*';
	 c++;
	 dfs(dp,n,m,i+1,j);
	 dfs(dp,n,m,i,j+1);
	 dfs(dp,n,m,i-1,j);
	 dfs(dp,n,m,i,j-1);
	 return;
 }

// Driver code 
int main() 
{ 
	int n,m;
	cin>>n>>m;
	vector<vector<char>> dp;
	for(int i=0;i<n;i++)
    {
		vector<char> v;
		for(int i=0;i<m;i++)
		{
			char x;
			cin>>x;
			v.push_back(x);
		}
		dp.push_back(v);
   }
   int ans=INT_MIN;
   for(int i=0;i<n;i++)
   {
	   for(int j=0;j<m;j++)
	   {   
		   if(dp[i][j]=='.')
		   {
			   c=0;
			   dfs(dp,n,m,i,j);
			   ans=max(ans,c);
		   }
	   }
   }
   cout<<ans<<endl;
	return 0; 
} 
