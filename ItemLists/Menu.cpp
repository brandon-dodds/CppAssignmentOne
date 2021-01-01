//
// Created by brandon on 24/12/2020.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "../Items/Appetiser.h"
#include "../Items/MainCourse.h"
#include "../Items/Beverage.h"

using namespace std;
string Menu::toString() {
    return ItemList::toString();
}

Menu::Menu(const string& menuTxtInput) {
    cout << "Running Menu constructor!";
    ifstream myFile(menuTxtInput);
    if(!myFile.is_open()) throw runtime_error("Could not open file!");
    string myLine, myWord;
    while(getline(myFile, myLine)){
        stringstream ss(myLine);
        vector<string> itemAdding;
        while(getline(ss, myWord, ',')){
            itemAdding.push_back(myWord);
        }
        if(itemAdding[0] == "a"){
            Item *appetiser = new Appetiser(itemAdding[1], stof(itemAdding[2]), stoi(itemAdding[3]), itemAdding[4], itemAdding[5]);
            this->items.push_back(appetiser);
        }
        else if (itemAdding[0] == "m"){
            Item *main = new MainCourse(itemAdding[1], stof(itemAdding[2]), stoi(itemAdding[3]));
            this->items.push_back(main);
        }
        else {
            Item *beverage = new Beverage(itemAdding[1], stof(itemAdding[2]), stoi(itemAdding[3]), stoi(itemAdding[6]), stof(itemAdding[7]));
            this->items.push_back(beverage);
        }
    }
    cout << items.size() << '\n';
}
