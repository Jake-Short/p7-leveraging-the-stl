#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto integers = randomIntegers();
    std::cout << "Initial: " << integers << "\n";

    // Get the vector size, then split the vector into two halves
    std::size_t sizeOfVector = integers.size();
    std::vector<int> leftHalf(integers.begin(), integers.begin() + (sizeOfVector / 2));
    std::vector<int> rightHalf(integers.begin() + (sizeOfVector / 2), integers.end());

    // Sort the left half in ascending order
    std::sort(leftHalf.begin(), leftHalf.end());

    // Sort the right half in descending order
    std::sort(rightHalf.begin(), rightHalf.end(), [](int a, int b) {
        return a > b;
    });

    // Combine the vectors together
    std::vector<int> finalIntegers(leftHalf);
    finalIntegers.insert(finalIntegers.end(), rightHalf.begin(), rightHalf.end());

    // Print the bitonic sequence
    std::cout << "Bitonic: " << finalIntegers << "\n";
}