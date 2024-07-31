/*
Recursion is a technique in programming where a function calls itself. 
It's useful for solving problems that can be broken down into smaller, similar subproblems. 
*/

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = factorial(num); // Call the function and store the result
    cout << "Factorial of the number is: " << result << endl;

    return 0;
}

