#include <sstream>
#include <iomanip>
#include "Item.h"
#include "Beverage.h"

using namespace std;
std::string Beverage::toString() {
    /*
     * Creates the overridden toString.
     */
    stringstream beveragePrice;
    string returnBev;
    beveragePrice << fixed << setprecision(2) << price;
    returnBev += name + ": £" + beveragePrice.str() + ", " + to_string(calories) + " cal ("
    + to_string(volume) + "ml";
    if(abv != 0){
        stringstream beverageAbv;
        beverageAbv << fixed << setprecision(1) << abv;
        returnBev += ", " + beverageAbv.str() + "% abv";
    }
    returnBev += ")";
    return returnBev;
}

bool Beverage::isAlcoholic() {
    return abv > 0;
}

Beverage::Beverage(const std::string &name, float price, int calories, int volume, float abv) {
    this->name = name;
    this->price = price;
    this->calories = calories;
    this->volume = volume;
    this->abv = abv;
}
