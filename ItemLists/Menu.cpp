//
// Created by brandon on 24/12/2020.
//

#include <iostream>
#include <fstream>
#include "Menu.h"

std::string Menu::toString() {
    return ItemList::toString();
}

Menu::Menu(const std::string& menuTxtInput) {
    std::ifstream myFile(menuTxtInput);
    if(!myFile.is_open()) throw std::runtime_error("Could not open file!");
    std::string myLine;
    while(getline(myFile, myLine)){
        std::cout << myLine << '\n';
    }
}
