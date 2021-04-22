#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       int l=0,r=0,q=0;
       int f=-1;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]=='(')
           l++;
           else if(s[i]==')')
           r++;
           else
           q++;
           if((l+q)<r)
           {   
               f=1;
               break;
           }
       }
       int k=abs(l-r);
       int p=q-k;
       if((p<0)||(p%2!=0))
       f=1;
       if(f==1)
       cout<<"NO"<<endl;
       else 
       cout<<"YES"<<endl;
    }
    return 0;
}