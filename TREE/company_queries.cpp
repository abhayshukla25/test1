#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n>>q;
    int par[n+1];
    par[1]=-1;
    for(int i=2;i<=n;i++)
    cin>>par[i];
    for(int i=1;i<=q;i++)
    { 
       int a,b;
       cin>>a>>b;  
       stack<int> s1,s2;
       int ans=-1;
       while(a!=-1)
       {
           s1.push(a);
           a=par[a];
       } 
       while(b!=-1)
       {
            s2.push(b);
            b=par[b];
       }   
       while(!s1.empty()&&!s2.empty()&&s1.top()==s2.top())
       {
           ans=s1.top();
           s1.pop();
           s2.pop();
       }
       cout<<ans<<endl;
    }
    return 0;
}