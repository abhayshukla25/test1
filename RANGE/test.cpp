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
    fseek(ptr,0,SEEK_SET);
    char ch=fgetc(ptr);
    if(ch==EOF)
    {
        cout<<"end"<<endl;
        cout<<ch<<endl;
    }
    int p=ftell(ptr);
    cout<<p<<endl;
        //cout<<ss<<endl;
        //cout<<ss.Str()<<endl;
        //cout<<ss.str()<<endl;
        //printf("\n%s",ss);
        //printf("\n%s",ss.Str());
       // printf("\n%s",ss.str());
      // printf("\n%s",ss.str().c_str());
     
    return 0; 
} 