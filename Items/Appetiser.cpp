#include "Item.h"
#include "Appetiser.h"

#include <utility>

std::string Appetiser::toString() {
    return this->name + std::to_string(this->price) + std::to_string(this->calories) + this->shareable +
           this->twoForOne;
}

Appetiser::Appetiser(std::string name, float price, int calories, std::string shareable, std::string twoForOne) {
    this->name = std::move(name);
    this->price = price;
    this->calories = calories;
    this->shareable = std::move(shareable);
    this->twoForOne = std::move(twoForOne);
}

