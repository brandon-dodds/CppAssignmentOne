#include "ItemList.h"
//Default ItemList class, nothing interesting here.
std::string ItemList::toString() {
    return std::string();
}

std::vector<Item *> ItemList::getItems() {
    return items;
}
