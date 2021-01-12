#include <iostream>
#include <iomanip>
#include <fstream>
#include "Order.h"
#include "../Items/Appetiser.h"

using namespace std;

string Order::toString() {
    /*
     * Makes the string needed for the checkout operation. Uses the Order itemlist in a decent way to create this.
     */
    string OrderReturn("==== Checkout ===== \n");
    vector<float> checkout = calculateTotal();
    int orderIndex = 0;
    for(auto & item : items){
        orderIndex += 1;
        OrderReturn+= "("  + to_string(orderIndex) + ") " + item->toString() + '\n';
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
    /*
     * Adds an item based on what is in the menu list to the orders list.
     */
    items.push_back(pItem);
    cout << pItem->getName() << " added to order! \n";
}

void Order::remove(int userInputIndex){
    /*
     * Removes the object from the items list.
     */
    cout << items[userInputIndex]->getName() + " have been removed! \n";
    items.erase(items.begin() + userInputIndex);
}

vector<float> Order::calculateTotal() {
    /*
     * Calculates the total and returns a vector with the first element being the total
     * and the second being the total savings.
     */
    float total = 0;
    int total241 = 0;
    float saving241 = 0;
    for(auto item : items) {
        total += item->getPrice();
        if (auto *appetiser = dynamic_cast<Appetiser *>(item)) {
            if (appetiser->getTwoForOne() == "y") {
                total241 += 1;
                saving241 = appetiser->getPrice();
            }
        }
    }
    for(int i = 0; i < total241 / 2; i++){
        total -= saving241;
    }
    return vector<float>{total, saving241};
}

void Order::printReceipt(const std::string& fileString) {
    /*
     * Simple file handling.
     * Outputs the checkout to the file.
     */
    ofstream myFile;
    myFile.open("receipt.txt");
    myFile << fileString;
    myFile.close();
}