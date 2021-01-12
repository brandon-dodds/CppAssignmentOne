#ifndef CPPASSIGNMENTONE_ITEMLIST_H
#define CPPASSIGNMENTONE_ITEMLIST_H


#include <vector>
#include "../Items/Item.h"

class ItemList {
protected:
    std::vector<Item *> items;
public:
    virtual std::string toString();
    std::vector<Item *> getItems();
};


#endif //CPPASSIGNMENTONE_ITEMLIST_H
