#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);
bool isPrime(const int& value);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool anyPrime(const std::vector<int>& values) {
    auto result = false;

    // Determine if any of the values are prime, and store
    // that result in the result variable
    result = std::any_of(values.begin(), values.end(), [](const int& value) {
        return isPrime(value);
    });

    return result;
}

bool isPrime(const int& value) {
    // Isn't prime
    if(value <= 1) {
        return false;
    }

    // Loop from i=2 to value, and determine if it
    // is divisble by i
    for(int i = 2; i < value; i++) {
        if(value % i == 0) {
            return false;
        }
    }

    return true;
}