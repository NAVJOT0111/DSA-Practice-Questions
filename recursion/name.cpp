
// In your main function, you have cout << name(5);. This statement tries to print the return value of name(5). 
// Since name is a void function, it doesn't return anything that cout can display. This will typically result in a compilation error.

#include<bits/stdc++.h>
using namespace std;

void name(int n){
    if(n<=0){
        return ;
    }
    cout << "Navjot ";
    name(n-1);
}
int main(){
    // cout << name(5) ;
// In your main function, you have cout << name(5);. This statement tries to print the return value of name(5). 
// Since name is a void function, it doesn't return anything that cout can display. This will typically result in a compilation error.
    name(5);
    return 0;
}