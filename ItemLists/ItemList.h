#ifndef CPPASSIGNMENTONE_ITEMLIST_H
#define CPPASSIGNMENTONE_ITEMLIST_H


#include <vector>
#include "../Items/Item.h"

class ItemList {
public:
    std::vector<Item*> items;
    virtual std::string toString();
};


#endif //CPPASSIGNMENTONE_ITEMLIST_H
