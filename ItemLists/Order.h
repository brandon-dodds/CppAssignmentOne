#ifndef CPPASSIGNMENTONE_ORDER_H
#define CPPASSIGNMENTONE_ORDER_H


#include "ItemList.h"

class Order : public ItemList {
public:
    std::string toString() override;

    void add(Item *pItem);
    std::vector<float> calculateTotal();
    std::string printReceipt();

    void remove(int userInputIndex);
};


#endif //CPPASSIGNMENTONE_ORDER_H
