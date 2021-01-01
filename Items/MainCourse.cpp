#include "Item.h"
#include "MainCourse.h"

MainCourse::MainCourse(const std::string &name, float price, int calories) {
    this->name = name;
    this->price = price;
    this->calories = calories;
}
