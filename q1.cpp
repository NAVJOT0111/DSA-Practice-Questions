// swap two numbers by using swap by reference , value and addresss
#include <bits/stdc++.h>
using namespace std;

void swapValue(int a, int b){
       // swap by value
        int temp = a;
        a = b;
        b = temp;
        cout << "Swapped by values: " << a << " "<< b ;
 }
    
// swap by reference
void swapReference(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
    cout << "Swapped by reference: " << a << " "<< b ;
}

void swapAddress(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Swapped by reference: " << a << " "<< b ;
}

int main(){
    int a=5, b= 10;

    swapValue(a,b);
    swapReference(a,b);
    swapAddress(&a,&b);

    return 0;
}
