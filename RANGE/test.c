#include<bits/stdc++.h> 
using namespace std;
int main() 
{ 
    FILE* ptr = fopen("abc.txt","r"); 
    if (ptr==NULL) 
    { 
        printf("no such file."); 
        return 0; 
    } 
  
    /* Assuming that abc.txt has content in below 
       format 
       NAME    AGE   CITY 
       abc     12    hyderbad 
       bef     25    delhi 
       cce     65    bangalore */
    char buf[100]; 
    int d;
    int k=fscanf(ptr,"%d",&d);
        printf("\n%d %d",k,d);
        k=fscanf(ptr,"%d",&d);
        printf("\n%d %d",k,d);
        k=fscanf(ptr,"%d",&d);
        printf("\n%d %d",k,d);
        k=fscanf(ptr,"%d",&d);
        printf("\n%d %d",k,d);
       k=fscanf(ptr,"%d",&d);
        printf("\n%d %d",k,d);
        stringstream ss;
        ss<<"abhay"<<" "<<"pratap";
        //cout<<ss<<endl;
        //cout<<ss.Str()<<endl;
        //cout<<ss.str()<<endl;
        //printf("\n%s",ss);
        //printf("\n%s",ss.Str());
       // printf("\n%s",ss.str());
      // printf("\n%s",ss.str().c_str());
      unsigned int b=10;
      signed long long c=static_cast<signed long long>(b);
      cout<<c<<endl;
      char *p="abhay";
      printf("%s",p);
      cout<<strlen(p)<<endl;
      cout<<"OK"<<endl;
    return 0; 
} 