#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    vector<string> mat;
    for(int i=0;i<n;i++)
    {
      string s;
      cin>>s;
      mat.push_back(s);
    }
    int c1=0,c2=0;

    for(int i=0;i<n;i++)
    {
      string s=mat[i];
      for(int j=0;j<m;j++)
      {
        if(i%2==0)
        {
          if(j%2==1)
          {
            if(s[j]=='.')
            c1++;
            else
            c2++;
          }
          else
          {
            if(s[j]=='*')
            c1++;
            else
            c2++;
          }
        }
        else
        {
          if(j%2==1)
          {
            if(s[j]=='*')
            c1++;
            else
            c2++;
          }
          else
          {
            if(s[j]=='.')
            c1++;
            else
            c2++; 
          }
        }
      }
    }
    if(n%2!=0&&m%2!=0)
    cout<<min(c1,c2)<<endl;
    else
    cout<<c2<<endl;
    
  }
    return 0;
}
