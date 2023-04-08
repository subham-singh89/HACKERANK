#include <iostream>
using namespace std;\
void min_max(unsigned  long  int arr[]){
            unsigned  long  int max = arr[0];
            unsigned  long  int min = arr[0];
            for(int i=1; i<5; i++){
            if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
        }
        cout << min << " " << max;
    }

unsigned  long  int Sum(unsigned  long  int arr[], int n){
    unsigned  long  int sum = 0;
    for(int i = 0; i<5; i++){
        sum += arr[i];
    }
    sum = sum - arr[n];
    return sum;
}

int main(){
    unsigned  long  int arr[5];
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }

    unsigned  long  int SUM[5];
    for(int j=0; j<5; j++){
        SUM[j] = Sum(arr, j);
    }
    min_max(SUM);
}
