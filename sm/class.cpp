#include<bits/stdc++.h>
using namespace std;
class A{
    int a;
};
class B:A
{
    int b;
};
int main()
{
   B ob1;
   cout<<sizeof(ob1)<<endl;
}