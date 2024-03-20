#include<iostream>
#include<string>

std::string sum(std::string a, std::string b);

int main() {
    std::string firstNumber, secondNumber;

    std::cout << "First Number: ";
    std::cin >> firstNumber;
    
    std::cout << "Second Number: ";
    std::cin >> secondNumber;

    std::cout << "Sum: " << sum(firstNumber, secondNumber) << std::endl;
}