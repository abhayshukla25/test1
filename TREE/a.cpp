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
        int s=9;
        if(n==1)
        cout<<s;
        else if(n==2)
            cout<<"98";
            else
            {
                cout<<"98";
                
        for(int i=2;i<n;i++)
        {
            cout<<s;
            s++;
            if(s>9)
            s=0;
        }
            }
        cout<<endl;
    }
    return 0;
}