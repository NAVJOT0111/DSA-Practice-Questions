// takes an element and place it in the correct order in the sorted array
#include <iostream>
#include <utility>   // for std::swap
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int key = arr[i];        // element to be inserted
        int j = i-1;              // last index of sorted part

        // Move elements greater than key one position ahead
        while(j >= 0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}