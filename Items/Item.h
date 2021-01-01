#ifndef CPPASSIGNMENTONE_ITEM_H
#define CPPASSIGNMENTONE_ITEM_H

#include <string>

class Item {
public:
    int calories;
    float price;
    std::string name;

    virtual std::string toString();
};

#endif //CPPASSIGNMENTONE_ITEM_H
