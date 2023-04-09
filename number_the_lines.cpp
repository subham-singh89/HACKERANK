#include<iostream>
using namespace std;
int   check(int x1,int v1,int x2,int v2)
{
    int c=0;
    if(x1==x2)
    {
        c++;
    }
    if(x1>x2 && v2>v1)
    {
        int k1=x1,k2=x2;
        while(k1>k2)
        {
            k1=k1+v1;
            k2=k2+v2;
            if(k1==k2)
            {
                c++;
            } 
               
        }
    }
    if(x2>x1 && v1>v2)
    {
        int k1=x1,k2=x2;
        while(k2>k1)
        {
            k1=k1+v1;
            k2=k2+v2;
            if(k1==k2)
            {
                c++ ;
            } 
            
        }
    }
    return c;
    
}
int main()
{
    int  s;
    int x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;
    s=check(x1,v1,x2,v2);
    if(s==0)
    {
        cout<<"NO";
    }
    if(s!=0)
    {
        cout<<"YES";
    }
    
}
