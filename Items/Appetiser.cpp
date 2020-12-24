#include "Item.h"
#include "Appetiser.h"

std::string Appetiser::toString(){
    return this->name + std::to_string(this->price) + std::to_string(this->calories) + this->shareable + this->twoForOne;
}

