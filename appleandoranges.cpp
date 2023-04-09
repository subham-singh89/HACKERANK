#include<iostream>
using namespace std;

void countApplesAndOranges(int apple[],int orange[],int m,int n,int s,int t,int a,int b)
{
    int count_apple=0;
    int count_oranges=0;
    int orange_begin=b-t;
    int orange_end=b-s;
    int apple_begin=s-a; 
    int apple_end=t-a;
    
    for(int i=0;i<m;i++)
    {
        if(apple[i]>0)
        {
            if(apple[i]>=apple_begin && apple[i]<=apple_end)
            {
                ++count_apple;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(orange[i]<0)
        {
            orange[i]=-orange[i];
            if(orange[i]>=orange_begin&& orange[i]<=orange_end)
            {
                ++count_oranges;
            }
        }
    }
    cout<<count_apple<<endl;
    cout<<count_oranges<<endl;
}
int main()
{
    int s,t;
    cin>>s>>t;
    int a,b;
    cin>>a>>b;
    int m,n;
    cin>>m>>n;
    int apples[m];
    int oranges[n];
    for(int i=0;i<m;i++)
    {
        cin>>apples[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>oranges[i];
    }
    countApplesAndOranges(apples,oranges,m,n,s,t,a,b);
    return 0; 
    
}
