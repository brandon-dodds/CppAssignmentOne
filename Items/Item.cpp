#include <sstream>
#include <iomanip>
#include "Item.h"

using namespace std;

string Item::toString() {
    stringstream stringPrice;
    stringPrice << fixed << setprecision(2) << price;
    return name + ": £" + stringPrice.str() + ", " + to_string(calories) + " cal";
}
