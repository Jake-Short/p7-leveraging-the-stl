#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    // Accumulate all of the price values
    double totalPrice = std::accumulate(cars.begin(), cars.end(), 0, [](double i, const Car& car) {
        return car.price() + i;
    });
    // Find the average from the total price and size of the cars vector
    double averagePrice = totalPrice / (cars.size());


    //
    // Find the minimum and maximum values
    //
    auto min = *std::max_element(cars.begin(), cars.end(), [](const Car& car1, const Car& car2) {
        return car1.price() > car2.price();
    });
    auto max = *std::max_element(cars.begin(), cars.end(), [](const Car& car1, const Car& car2) {
        return car1.price() < car2.price();
    });

    // Print the average price and price range
    std::cout << "The average price is: $" << averagePrice << "\n";
    std::cout << "The range is: $" << min.price() << " to $" << max.price() << "\n";
}