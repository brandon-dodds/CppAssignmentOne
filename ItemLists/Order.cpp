#include <iostream>
#include "Order.h"
#include "../Items/Appetiser.h"

using namespace std;

string Order::toString() {
    return ItemList::toString();
}

void Order::add(Item *pItem) {
    cout << pItem->name << '\n';
    items.push_back(pItem);
    cout << items.size() << '\n' << calculateTotal() << '\n';

}

float Order::calculateTotal() {
    float total = 0;
    int total241 = 0;
    float saving241 = 0;
    for(auto item : items){
        total += item->price;
        if(auto *appetiser = dynamic_cast<Appetiser *>(item)){
            if (appetiser->twoForOne == "y"){
                total241 += 1;
                saving241 = appetiser->price;
            }
        }
        for(int i = 0; i < total241 / 2; i++){
            total -= saving241;
        }
    }
    return total;
}
