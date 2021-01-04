#include <iostream>
#include "Order.h"

std::string Order::toString() {
    return ItemList::toString();
}

void Order::add(Item *pItem) {
    std::cout << pItem->price;
}
