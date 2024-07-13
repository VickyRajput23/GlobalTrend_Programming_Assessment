#include <iostream>

// Function to compute the sum
int sumOfDigits(int number) {
    int sum = 0;
    
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    
    return sum;
}
int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    int sum = sumOfDigits(num);
    std::cout << "Sum of digits of " << num << " is: " << sum << std::endl;
    
    return 0;
}
