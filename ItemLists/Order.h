#ifndef CPPASSIGNMENTONE_ORDER_H
#define CPPASSIGNMENTONE_ORDER_H


#include "ItemList.h"

class Order : public ItemList {
public:
    std::string toString() override;

    void add(Item *pItem);
    std::vector<float> calculateTotal();
    static void printReceipt(const std::string& fileString);
    void remove(int userInputIndex);

private:
};


#endif //CPPASSIGNMENTONE_ORDER_H
