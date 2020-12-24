#include "Item.h"
#include "Beverage.h"

std::string Beverage::toString() {
    return Item::toString();
}

bool Beverage::isAlcoholic() {
    return false;
}
