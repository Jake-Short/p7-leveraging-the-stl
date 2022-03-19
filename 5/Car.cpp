#include "Car.h"
#include <iomanip>

Car Car::createRandom()
{
    std::string vin;
    for (int i = 0; i < 17; i++)
        vin.push_back(static_cast<char>(_letterDistribution(_generator)));
    
    double price = _priceDistribution(_generator);

    return Car{ vin, price };
}

Car::Car(std::string vin, double price)
    : _vin{ vin }, _price{ price } {}

std::string Car::vin() const { return _vin; }
double Car::price() const { return _price; }

void Car::updatePrice(double value)
{
    if (value >= 0)
        _price = value;
}

bool operator==(const Car& first, const Car& second) {
    return first.vin() == second.vin() && first.price() == second.price();
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    out << "CAR: vin(" << car.vin() << "), price($"
        << std::setprecision(2) << std::fixed << car.price() << ")";
    return out;
}