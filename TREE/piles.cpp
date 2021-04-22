#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll x=((a%4)+(b%4)+(c%4));
        if((x%4)!=0)
        {cout<<"NO"<<endl;
        continue;}
        ll y=min(a,min(b,c));
        ll z=(a-y)+(b-y)+(c-y);
        if(z>y)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;

    }
    return 0;
}