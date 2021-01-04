#ifndef CPPASSIGNMENTONE_MENU_H
#define CPPASSIGNMENTONE_MENU_H


#include "ItemList.h"

class Menu : public ItemList {
public:
    explicit Menu(const std::string &menuTxtInput);
    std::string toString() override;
};


#endif //CPPASSIGNMENTONE_MENU_H
