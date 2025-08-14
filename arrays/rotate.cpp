#include <bits/stdc++.h> 
using namespace std;

int rotate(int arr[],int n){

    // one place
    // int temp = arr[0];
    // for(int i=0; i<n;i++){
    //     arr[i-1] = arr[i];
    // } arr[n-1] = temp;

    // d places
    int d = d%n;
    vector<int> temp(d);    // for dynamic memory allocation

    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    } 
    for(int i=d; i<n; i++){
        arr[i-d]= arr[i];
    } 
    for(int i=n-d; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }
}