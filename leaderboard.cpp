#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n,m;
    cin >> n;
    vector<int> lb(n);
    for (auto& e : lb) cin >> e;
    
    vector<int> ranks(n);
    ranks[0] = 1;
    for (size_t i = 1; i < n; ++i) {
        if (lb[i] == lb[i-1]) {
            ranks[i] = ranks[i-1];
            continue;
        }
        ranks[i] = ranks[i-1]+1;
    }
    ranks.push_back(ranks[n-1]+1);
    
    cin >> m;
    vector<int> alice(m);
    
    int curr = ranks[n], ci = n-1;
    for (auto& e : alice) {
        cin >> e;
        while(ci >= 0 && e > lb[ci]) {
            --ci;
        }
        if (lb[ci] == e)
            cout << ranks[ci];
        else if (lb[ci] > e)
            cout << ranks[ci]+1;
        else
            cout << 1;
        cout << '\n';
    }
    
    return 0;
}
