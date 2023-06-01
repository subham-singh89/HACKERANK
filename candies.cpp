#include <cmath>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
     
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> dp(n);
        for(int i=0;i<n;i++)
                 cin>>arr[i];
        dp[0]=1;
        for(int i=1;i<n;i++){
                if(arr[i]>arr[i-1])
                           dp[i]=dp[i-1]+1; 
                else if(arr[i]<=arr[i-1])
                         dp[i]=1;            
        }
        for(int i=n-2;i>=0;i--){
                if(arr[i]>arr[i+1])
                           dp[i]=max(dp[i],dp[i+1]+1);     
        }                                                
        long long sum=0;
        for(int i=0;i<n;i++){
                 sum+=dp[i];
        }
        cout<<sum<<endl;
    return 0;
}
