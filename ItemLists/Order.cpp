#include <iostream>
#include <sstream>
#include <iomanip>
#include "Order.h"
#include "../Items/Appetiser.h"
#include "../Items/MainCourse.h"
#include "../Items/Beverage.h"

using namespace std;

string Order::toString() {
    string OrderReturn("==== Checkout ===== \n");
    vector<float> checkout = calculateTotal();
    int orderIndex = 0;
    for(auto & item : items){
        orderIndex += 1;
        if(auto *appetiser = dynamic_cast<Appetiser *>(item)){
            OrderReturn+= "("  + to_string(orderIndex) + ") " + appetiser->toString() + '\n';
        }
        else if (auto *mainCourse = dynamic_cast<MainCourse *>(item)){
            OrderReturn+= "("  + to_string(orderIndex) + ") " + mainCourse->toString() + '\n';
        }
        else {
            auto *beverage = dynamic_cast<Beverage *>(item);
            OrderReturn+= "("  + to_string(orderIndex) + ") " + beverage->toString() + '\n';
        }
    }
    OrderReturn+= "--------- \n";
    if (checkout[1] != 0){
        stringstream savings;
        savings << fixed << setprecision(2) << checkout[1];
        OrderReturn += "2-4-1 discount applied! Savings: £" + savings.str() + '\n';
    }
    stringstream totalPrice;
    totalPrice << fixed << setprecision(2) << checkout[0];
    OrderReturn += "Total: £" + totalPrice.str() + '\n';

    OrderReturn += "Do you want to place your order? Type 'y' to confirm, or 'n' to go back and modify it. \n";
    return OrderReturn;
}

void Order::add(Item *pItem) {
    items.push_back(pItem);
    cout << pItem->name << " Added to order! \n";
}

void Order::remove(int userInputIndex){
    cout << items[userInputIndex]->name + " have been removed! \n";
    items.erase(items.begin() + userInputIndex);
}

vector<float> Order::calculateTotal() {
    float total = 0;
    int total241 = 0;
    float saving241 = 0;
    for(auto item : items) {
        total += item->price;
        if (auto *appetiser = dynamic_cast<Appetiser *>(item)) {
            if (appetiser->twoForOne == "y") {
                total241 += 1;
                saving241 = appetiser->price;
            }
        }
    }
    for(int i = 0; i < total241 / 2; i++){
        total -= saving241;
    }
    return vector<float>{total, saving241};
}
