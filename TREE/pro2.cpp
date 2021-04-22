#include <iostream> 
using namespace std; 
long long int power(long long int  x, long long int y, long long int p)  
{  
    long long int res = 1;      
  
    x = x % p;
   
    if (x == 0) return 0; 
  
    while (y > 0)  
    {  
       
        if (y & 1)  
            res = ((res%p)*(x%p)) % p;  
  

        y = y>>1; 
        x = ((x%p)*(x%p)) % p;  
    }  
    return res;  
}  
int main()
{   long long int p=1000000007;
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,m;
        cin>>n>>m;
        long long int x=m-1;
        if(n%2==0)
        {
            x=(-1)*x;
        }
        long long int res=power(m-1,n-1,p);
        if(x<0)
        res=res
        res=((res%p)+(x%p))%p;
        cout<<res<<endl;
    }
}

if(res<0)
res=res+p;