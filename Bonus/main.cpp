#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include "Utility.h"
#include "Car.h"

std::vector<int> createElevationMap();

int main() {
    auto range = createElevationMap();
    std::cout << "Elevation Map: " << range << "\n";

    // TODO: print out the amount of trapped water after it rains
}

std::vector<int> createElevationMap() {
    // generate elevation data
    std::mt19937 generator{ std::random_device{}() };
    std::exponential_distribution<> elevationDist{ 0.5 };
    auto elevationCreator = [&generator, &elevationDist]() { 
        return static_cast<int>(elevationDist(generator));
    };
    auto elevationMap = randomVectorOfObjects<int, decltype(elevationCreator)>(elevationCreator);

    // ensure there is only one highest peak
    auto firstMaxPeakIt = std::max_element(elevationMap.begin(), elevationMap.end());
    *firstMaxPeakIt += 1;

    return elevationMap;
}
