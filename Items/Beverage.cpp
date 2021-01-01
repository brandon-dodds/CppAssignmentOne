#include "Item.h"
#include "Beverage.h"

std::string Beverage::toString() {
    return Item::toString();
}

bool Beverage::isAlcoholic() {
    return false;
}

Beverage::Beverage(const std::string& name, float price, int calories, int volume, float abv) {
    this->name = name;
    this->price = price;
    this->calories = calories;
    this->volume = volume;
    this->abv = abv;
}
