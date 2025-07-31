#include <iostream>
#include <utility>   // for std::swap
using namespace std;

// basic
void bubbbleSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j =0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//optimised
void bubble(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool swapp = false;
        for (int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                swapp = true;
            }
        }
        if(!swapp){
            break;
        }
    }
}

// recursive : O(n2). Space Complexity: O(N) auxiliary stack space.
void bubble_sort(int arr[], int n){
    if(n==1) return;

    for(int j = 0; j<= n-2; j++){
        if(arr[j] > arr[j+1]){
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
        }
    }
    bubble_sort(arr, n-1);
}
// In Bubble Sort, we compare arr[j] with arr[j + 1].
// For the last comparison:
// j + 1 must be a valid index.
// If j goes up to n - 1, then arr[j + 1] would be out of bounds.
// So we stop at j = n - 2.


//optimised recursive : O(n)
void bubb(int arr[], int n){
    if(n==1) return;

    int didSwap = 0;
    for(int j = 0; j<= n-2; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j+1],arr[j]);
            didSwap = 1;
        }
    }
    if(didSwap == 0) return ;
    bubble_sort(arr, n-1);
}