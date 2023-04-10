#include<iostream>
#include <vector>
#include<map>
#include <cmath>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
 
    map<int, int> m;
    for(auto x: s) {
        m[x % k] += 1; 
    }
 
    int ans = 0;
    if(m[0] > 0)
        ans++;
    for(int i = 1; i < k; i++) {
        if(m[i] == 0) continue;
        if(i + i == k ) {
            ans++;
        } else {
            ans += max(m[i], m[k - i]);
            m[i] = 0;
            m[k - i] = 0;
        }         
    }
    return ans;
}

int main()
{
    vector<int> s;
    int n, k;
    int result;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int element;
        cin>>element;
        s.push_back(element);
    }
    result=nonDivisibleSubset( k, s);
    cout<<result<<endl;
    return 0;
}
