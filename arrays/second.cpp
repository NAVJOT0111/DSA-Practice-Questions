#include <iostream>
#include <algorithm>
using namespace std;

int secondLargestElement(int a[], int n){
    int largest = a[0];
    int slargest = INT16_MIN;
    for(int i=0; i<n; i++){
        if(a[i] > largest){
            slargest =  largest;
            largest = a[i];
        }
         else if(a[0] > slargest && a[i] != largest){
            slargest = a[i];
        }
    } return slargest;
}
