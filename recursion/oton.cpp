#include<bits/stdc++.h>
using namespace std;

int num(int n){
    if(n<=0){
        return 1;
    }
    // num(n-1);
    cout << n;
    num(n-1);
}

int main(){
    int x = 5;
    num(x);
    return 0;
}