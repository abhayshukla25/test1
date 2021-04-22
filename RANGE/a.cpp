#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      n=2*n;
      int arr[n];
      for(int i=0;i<n;i++)
      cin>>arr[i];
      sort(arr,arr+n);
      int x=arr[n-1];
      multiset<int> m;
      int f=1;
      for(int i=0;i<n-1;i++)
      {  
          //cout<<a[i]<<" ";
       for(int j=0;j<n-1;j++)
       {
           if(j==i)
           continue;
           m.insert(arr[j]);
           //cout<<arr[j]<<" ";
       }
     //  cout<<endl;
       f=1;
       x=arr[n-1];
       while(m.size()>0)
       {
         int a=*m.rbegin();
         m.erase(m.find(a));
         if(m.find(x-a)==m.end())
         {
             f=-1;
             //cout<<arr[i]<<" ===="<<x<<endl;
            // cout<<m.size()<<endl;
             break;
         }
         
         m.erase(m.find(x-a));
         x=a;
       }
       m.clear();
       if(f!=-1)
       {
           f=i;
           break;
       }
      }
      //cout<<endl;
      if(f==-1)
      {cout<<"NO"<<endl;
       continue;}
      for(int i=0;i<n-1;i++)
      m.insert(arr[i]);
      m.erase(m.find(arr[f]));
      cout<<"YES"<<endl;
      cout<<arr[n-1]+arr[f]<<endl;
      cout<<arr[n-1]<<" "<<arr[f]<<endl;
      x=arr[n-1];
      while(m.size()!=0)
      {
          int a=*m.rbegin();
          cout<<a<<" "<<x-a<<endl;
          m.erase(m.find(x-a));
          m.erase(m.find(a));
          x=a;
      }
    }
    return 0;
}