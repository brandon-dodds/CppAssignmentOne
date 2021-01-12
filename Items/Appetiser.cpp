#include "Item.h"
#include "Appetiser.h"

#include <sstream>
#include <iomanip>

using namespace std;

string Appetiser::toString() {
    /*
     * Creates the overridden toString.
     */
    stringstream stream;
    stream << fixed << setprecision(2) << price;
    string returnString;
    returnString += name + ": £" + stream.str() + ", " + to_string(calories) + " cal ";
    if(shareable == "y"){
        returnString += "(shareable)";
    }
    if (twoForOne == "y"){
        returnString += "(2-4-1)";
    }
    return returnString;
}

Appetiser::Appetiser(string name, float price, int calories, string shareable, string twoForOne) {
    this->name = move(name);
    this->price = price;
    this->calories = calories;
    this->shareable = move(shareable);
    this->twoForOne = move(twoForOne);
}

std::string Appetiser::getShareable() {
    return shareable;
}

std::string Appetiser::getTwoForOne() {
    return twoForOne;
}

