#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        int a[n];
        if(s[0]=='-')
        a[0]=-1;
        else
        a[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='-')
            a[i]=a[i-1]-1;
            else
            a[i]=a[i-1]+1;
       //     cout<<a[i]<<" ";
        }
       // cout<<endl;
        int mins[n],mine[n],maxs[n],maxe[n];
        mins[0]=a[0];
        mine[n-1]=a[n-1];
        maxs[0]=a[0];
        maxe[n-1]=a[n-1];
        for(int i=1;i<n;i++)
        {
            mins[i]=min(mins[i-1],a[i]);
            maxs[i]=max(maxs[i-1],a[i]);
         //   cout<<mins[i]<<" "<<maxs[i]<<",";
        }
        for(int i=n-2;i>=0;i--)
        {
            mine[i]=min(mine[i+1],a[i]);
            maxe[i]=max(maxe[i+1],a[i]);

        }
        
        for(int i=0;i<m;i++)
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int min1=0;
            int max1=0;
            if(r<n-1)
            {
               
               if(l>0)
               {
                   
                   min1=min(min1,mine[r+1]-(a[r]-a[l-1]));
                   max1=max(max1,maxe[r+1]-(a[r]-a[l-1]));
               }
               else
               {
                   min1=min(min1,mine[r+1]-(a[r]));
                   max1=max(max1,maxe[r+1]-(a[r]));
               }
            }
            if(l>0)
            {
                max1=max(max1,maxs[l-1]); 
                   min1=min(min1,mins[l-1]);
            }
            
            
         // cout<<max1<<" "<<min1<<endl;
            cout<<max1-min1+1<<endl;
        }
        
    }
    return 0;
}