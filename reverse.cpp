#include <iostream>
using namespace std;

int reverse(int n){
    int x, i=0, a;      //a is not initialized
    while(n){       //not updating n inside the while(n) loop. This will lead to an infinite loop
        x = n % 10;
        a = 10*i + x;       // This logic is not correctly building the reversed number.
        i++;
    }
    return a;
}

int rev_num(int n){
    int reversed = 0;
    if(n == 0){
        return 0;
    }

    while(n){
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int main(){
    int x = 1098;
    int rev = rev_num(x);
    cout << "Reverse no is " << rev << endl;
}