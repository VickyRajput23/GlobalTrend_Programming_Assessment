#include <iostream>
using namespace std;

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        unsigned long long fact = 1;
        for (int i = 2; i <= n; ++i) {
            fact *= i;
        }
        return fact;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Calculate factorial
    unsigned long long fact = factorial(num);

    cout << "Factorial of " << num << " is: " << fact << endl;

    return 0;
}
