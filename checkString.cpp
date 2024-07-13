#include <iostream>
#include <cctype>
#include <string>

bool containsOnlyAlphabetic(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string userInput;

    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    if (containsOnlyAlphabetic(userInput)) {
        std::cout << "The string contains only alphabetic characters." << std::endl;
    } else {
        std::cout << "The string contains non-alphabetic characters." << std::endl;
    }

    return 0;
}
