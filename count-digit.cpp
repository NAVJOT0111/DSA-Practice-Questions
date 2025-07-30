#include <iostream>
using namespace std;

int count_digit(int n){
    int count;   // Uninitialized count variable
    while(n){       // Missing n update in while loop
        int i = n % 10;
        count++;
    }
    cout << "The no of digits are" << count << endl;
}

// The count_digit function is declared to return an int, but it doesn't explicitly return any value. 
// This leads to undefined behavior when its return value is assigned to abb in main.
// Redundant cout in count_digit: The function count_digit prints "The no of digits are" along with the count.
//  Typically, a function designed to return a value should not also print it, as it restricts how the returned value can be used. 
// The printing should ideally happen in main after receiving the returned value

// int main(){
//     int abb = count_digit(1098);
//     cout << abb << endl;
//     return 0;
// }

// in main: Since count_digit doesn't return a meaningful value, abb will contain an undefined value,
//  and printing it will not yield the expected digit count

// NOW THE REVISED VERSION

int count(int n){
    int count = 0;
    if(n==0){
        return 1;
    }
    while(n){
        n = n /10;
        count++;
    }
    return count;
}

int main(){
    int x = 1098;
    int dig = count(x);
    cout << "The number of digits in " << x << " are: " << dig << endl;
}