#include <iostream>
#include <utility>   // for std::swap

using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[mini],arr[i]);
    }
}