#pragma once
#include <string>
#include <ostream>
#include <random>

class Car {
public:
    Car(std::string vin, double price);

    std::string vin() const;
    double price() const;
    void updatePrice(double value);

    static Car createRandom();

private:
    std::string _vin;
    double _price;

    inline static std::mt19937 _generator{ std::random_device{}() };
    inline static std::uniform_real_distribution<> _priceDistribution{ 5000., 20000. };
    inline static std::uniform_int_distribution<> _letterDistribution{ 65, 90 };
};

bool operator==(const Car& first, const Car& second);
std::ostream& operator<<(std::ostream& out, const Car& car);