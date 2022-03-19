#include "Utility.h"

std::vector<int> randomIntegers() {
    std::mt19937 generator{ std::random_device{}() };
    std::uniform_int_distribution<> dist{ 0, 100 };

    auto creator = [&generator, &dist]() {
        return dist(generator);
    };

    return randomVectorOfObjects<int, decltype(creator)>(creator);
}


std::vector<Car> randomCars() {
    return randomVectorOfObjects<Car, decltype(Car::createRandom)>(Car::createRandom);
}