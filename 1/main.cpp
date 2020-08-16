#include <iostream>

void ExceptionIfNotPrime(int number) {
    std::string err_msg = "Number " + std::to_string(number) + \
                          " is not prime";
    if (number == 1 || number == 0) {
        throw std::invalid_argument(err_msg);
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            throw std::invalid_argument(err_msg);
        }
    }
}

int main() {
    int number;
    std::cout << "Enter number:\n";
    while (std::cin >> number) {
        try {
            ExceptionIfNotPrime(number);
            std::cout << "Number " << number
                << " is prime" << std::endl;
        } catch (std::invalid_argument &ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "Enter another number or Ctrl+D to exit:\n";
    }
}
