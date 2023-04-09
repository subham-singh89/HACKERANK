#include<iostream>
#include <vector>
using namespace std;
void gradingStudents(vector<int> &v)
{
    for(int i=0;i<(v.size());i++)
    {
        int m;
        m=v[i]%5;
        int n;
        n=v[i]+5-m;
        if(v[i]>=38 && m>=3)
        {
            cout<<n<<endl;
        }
        else
        {
            cout<<v[i]<<endl;
        }
        
    }
}
int main()
{
   int n;
   cin>>n;
   vector<int> vac1;
    int element;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        vac1.push_back(element);
    }
    gradingStudents(vac1);
    return 0;
    
}
