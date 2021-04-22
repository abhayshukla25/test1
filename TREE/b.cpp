#include <bits/stdc++.h>
using namespace std;

int main() 
{int t;
cin>>t;
while(t--)
{
    int n,m;
    cin>>n>>m;
    vector<string> dp;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        dp.push_back(s);
    }
    vector<int> v(500,0);
    char dp1[n][m];
    char dp2[n][m];
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {dp2[i][j]='*';
                    
                }
                else
                {
                    dp2[i][j]='.';
                }
            }
            else
            { if(j%2==0)
                {dp2[i][j]='.';
                    
                }
                else
                {
                    dp2[i][j]='*';
                }
                
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {dp1[i][j]='.';
                    
                }
                else
                {
                    dp1[i][j]='*';
                }
            }
            else
            { if(j%2==0)
                {dp1[i][j]='*';
                    
                }
                else
                {
                    dp1[i][j]='.';
                }
                
            }
        }
    }
   
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dp1[i][j]!=dp[i][j]){c1++;}
            if(dp2[i][j]!=dp[i][j]){c2++;}
        }
    }
    cout<<min(c1,c2)<<endl;
    
}
	
	return 0;
}