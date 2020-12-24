#include "Item.h"

std::string Item::toString() {
    return this->name + std::to_string(this->price) + std::to_string(this->calories);
}
