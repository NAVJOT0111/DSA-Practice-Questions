#include<bits/stdc++.h>
using namespace std;

int fun(int n){
    static int x =0;
    if(n>0){
        x++;
        // return fun(n-1)+n;
        return fun(n-1)+x;
    }
    return 0;
}

int main(){
    int r;
    r = fun(5);
    cout << r;      //25

    
    // r = fun(5);
    // cout << r << " ";    //50

    return 0;
}