#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    int x=INT_MAX,y=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	       cin>>a[i];
	       x=min(x,a[i]);
	       y=max(y,a[i]);
	     }
	     cout<<2*(y-x)<<endl;
	}
	return 0;
}