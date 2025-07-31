// takes an element and place it in the correct order in the sorted array
#include <iostream>
#include <utility>   // for std::swap
using namespace std;

// arr[6] = {9,7,4,3,8,5}

void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int key = arr[i];        // element to be inserted / 9 7 
        int j = i-1;              // last index of sorted part

        // Move elements greater than key one position ahead
        while(j >= 0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// recursive approach
void insertionSort(int arr[], int i, int n){
    if(i == n) return ;

    int j = i;
    while(j>0 && arr[j-1] > arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }
    insertionSort(arr, i+1, n);
}