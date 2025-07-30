#include <iostream>
#include <vector>
#include <cmath> // for sqrt
#include <algorithm>
using namespace std;

vector<int> findDivisors(int n) {
    vector<int> divisors;

    // Iterate from 1 up to the square root of N
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            // If i divides N, then i is a divisor
            divisors.push_back(i);

            // If i*i is not equal to N, then N/i is also a divisor
            // This condition handles perfect squares to avoid adding the square root twice
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }

    // Sort the divisors for a clean, ordered output (optional)
    sort(divisors.begin(), divisors.end());

    return divisors;
}

int main() {
    int n;

    // Get input from the user
    cout << "Enter an integer N: ";
    cin >> n;

    // Handle non-positive input as divisors are typically defined for positive integers.
    // Or you can define what divisors mean for negative numbers based on the problem context.
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1; // Indicate an error
    }

    // Call the function to find divisors
    vector<int> resultDivisors = findDivisors(n);

    // Print the divisors
    cout << "Divisors of " << n << " are: ";
    for (int i = 0; i < resultDivisors.size(); ++i) {
        cout << resultDivisors[i];
        if (i < resultDivisors.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0; // Indicate successful execution
}