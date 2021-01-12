#include <iostream>
#include <fstream>
#include <iomanip>
#include "Menu.h"
#include "../Items/Appetiser.h"
#include "../Items/MainCourse.h"
#include "../Items/Beverage.h"

using namespace std;

string Menu::toString() {
    /* This is a huge mess, honestly I wish I knew an easier way to do this.
     * It works, the issue is that it looks awful and can probably be simplified with the item->toString() method.
     * Printing the headers would be difficult though.
     */
    string MenuReturn("----------------------Appetisers------------------------- \n");
    int MenuIndex = 0;
    while(auto *appetiser = dynamic_cast<Appetiser*>(items[MenuIndex])){
        MenuReturn += '(' + to_string(MenuIndex + 1) + ") " + appetiser->toString() + '\n';
        MenuIndex++;
    }
    MenuReturn+= "----------------------Main Course------------------------- \n";
    while(auto *mainCourse = dynamic_cast<MainCourse*>(items[MenuIndex])){
        MenuReturn += '(' + to_string(MenuIndex + 1) + ") " + mainCourse->toString() + '\n';
        MenuIndex++;
    }
    MenuReturn += "----------------------Beverages------------------------- \n";
    while (auto *beverage = dynamic_cast<Beverage*>(items[MenuIndex])){
        MenuReturn += '(' + to_string(MenuIndex + 1) + ") " + beverage->toString() + '\n';
        if(MenuIndex < items.size() - 1){
            MenuIndex++;
        }
        else{
            break;
        }
    }
    return MenuReturn;
}

Menu::Menu(const string &menuTxtInput) {
    /* Creates the menu Item* vector
     * Does this by checking if the first element in a vector made up of the whole line is a specific value.
     */
    ifstream myFile(menuTxtInput);
    if (!myFile.is_open()) throw runtime_error("Could not open file!");
    string myLine, myWord;
    while (getline(myFile, myLine)) {
        stringstream ss(myLine);
        vector<string> itemAdding;
        while (getline(ss, myWord, ',')) {
            itemAdding.push_back(myWord);
        }
        if (itemAdding[0] == "a") {
            Item *appetiser = new Appetiser(itemAdding[1], stof(itemAdding[2]), stoi(itemAdding[3]), itemAdding[4],
                                            itemAdding[5]);
            this->items.push_back(appetiser);
        } else if (itemAdding[0] == "m") {
            Item *main = new MainCourse(itemAdding[1], stof(itemAdding[2]), stoi(itemAdding[3]));
            this->items.push_back(main);
        } else {
            Item *beverage = new Beverage(itemAdding[1], stof(itemAdding[2]), stoi(itemAdding[3]), stoi(itemAdding[6]),
                                          stof(itemAdding[7]));
            this->items.push_back(beverage);
        }
    }
}
