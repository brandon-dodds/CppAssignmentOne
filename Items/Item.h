#ifndef CPPASSIGNMENTONE_ITEM_H
#define CPPASSIGNMENTONE_ITEM_H

#include <string>

class Item {
protected:
    int calories;
    float price;
    std::string name;
public:
    virtual std::string toString();
    int getCalories() const;
    float getPrice() const;
    std::string getName();
};

#endif //CPPASSIGNMENTONE_ITEM_H
