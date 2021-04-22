#include<bits/stdc++.h>
using namespace std;
int a[100005];
int seg[4*100005];
int query(int ind,int l,int r,int low,int high)
{
      if(low>=l&&high<=r)
      return seg[ind];
      if(high<l||low>r)
      return INT_MIN;
      int mid=(low+high)/2;
      int left=query(2*ind+1,l,r,low,mid);
      int right=query(2*ind+2,l,r,mid+1,high);
      return max(left,right);
}
void build(int ind,int l,int r)
{
    if(l==r)
    {
        seg[ind]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*ind+1,l,m);
    build(2*ind+2,m+1,r);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    build(0,0,n-1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        int ans=query(0,l,r,0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}