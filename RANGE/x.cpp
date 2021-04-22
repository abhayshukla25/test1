#include<bits/stdc++.h>
using namespace std;
int main()
{
    const int x=50;
    const int *y=&x;
    int *z=const_cast<int *> (y);
    int a=10;
    int *b=&a;
    z=b;
    cout<<"new "<<*y<<endl;

    
    
    char *err=NULL;
    char ** aerrmsg=&err;
    string s="abhay";
    *aerrmsg=strdup (s.c_str());
    cout<<err<<endl;
    string p="omk";
    
    cout<<p<<endl;
    if(!err)
    cout<<"ok"<<endl;
}