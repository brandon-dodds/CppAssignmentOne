cmake_minimum_required(VERSION 3.17)
project(CppAssignmentOne)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppAssignmentOne Takeaway.cpp Items/Item.cpp Items/Item.h Items/Appetiser.cpp Items/Appetiser.h Items/MainCourse.cpp Items/MainCourse.h Items/Beverage.cpp Items/Beverage.h ItemLists/ItemList.cpp ItemLists/ItemList.h ItemLists/Menu.cpp ItemLists/Menu.h ItemLists/Order.cpp ItemLists/Order.h)