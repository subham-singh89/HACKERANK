#include<iostream>
using namespace std;
int divisibleSumPairs(int n, int k, int  ar[]) {
    
    int result=0;
    int fin;
    int division;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            division=(ar[i]+ar[j])%k;
            if(division==0)
            {
                if(i==j)
                {
                    
                }
                else
                {
                    result++;
                }
            }
            
        }
    }
    fin=result/2;
    return fin;
}

int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int answer;
    answer=divisibleSumPairs(n,k,arr);
    cout<<answer;
}
