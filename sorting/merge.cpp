// divide and merge
#include <iostream>
#include <utility>   // for std::swap
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l[n1],r[n2];
    // copy data to temp arrays
    for(int i=0; i<n1; i++)
        l[i] = arr[left+i];
    for(int j = 0; j< n2; j++)
        r[j] = arr[mid+1+j];
    
    // merge arrays
    int  i = 0;     // initial index of first subarray
    int j = 0;      // initial index of 2nd subarray
    int k = left;       // merged subarray
    // compare elements from l and r  and place them
    while(i<n1 && j<n2){
        if(l[i] <= r[j])
            arr[k++] = l[i++];
        else
            arr[k++] = r[j++]; 

    // Copy remaining elements
    while(i<n1)
        arr[k++] = l[i++];
    while(j<n2)
        arr[k++] = r[j++];
    }

}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = (left + right)/2 ;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

// Suppose left = 2 and mid = 4.
// The left half is arr[2] arr[3] arr[4].
// n1 = mid - left + 1 = 4 - 2 + 1 = 3.
// To copy into L[0], L[1], L[2], we do:
// L[0] = arr[left + 0] = arr[2]
// L[1] = arr[left + 1] = arr[3]
// L[2] = arr[left + 2] = arr[4]
// If we used arr[left] directly, we would copy the same element repeatedly.