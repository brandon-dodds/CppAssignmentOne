/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "ItemLists/Menu.h"
#include "ItemLists/Order.h"
#include "Items/Item.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
		    /*
		     * Error checking for the size of the array, should exit out nicely if it fails.
		     */
		    for (int i = 1; i < parameters.size(); i++){
                if(stoi(parameters[i]) > menu.getItems().size()){
                    throw invalid_argument("Received number too large!");
                }
                Item* choice = menu.getItems()[stoi(parameters[i]) - 1];  // you need to instantiate this using the menu object!
                order.add(choice);
            }
			// You may also wish to implement the ability to add multiple items at once!
			// e.g. add 1 5 9
		}
		else if (command.compare("remove") == 0)
		{
            /*
            * Error checking for the size of the array, should exit out nicely if it fails.
            */
            vector<int> indexesToRemove;
            for(int i = 1; i < parameters.size(); i++){
                if(stoi(parameters[i]) > order.getItems().size()){
                    throw invalid_argument("Received number too large!");
                }
                indexesToRemove.push_back(stoi(parameters[i]));
            }
            sort(indexesToRemove.rbegin(), indexesToRemove.rend());
            for(int i : indexesToRemove){
                order.remove(i - 1);
            }
		}
		else if (command.compare("checkout") == 0)
		{
		    /*
		     * Asks if the user wants to finish their order and calls the specific to string
		     * and printReceipt method to make the txt file.
		     */
		    string userOrder = order.toString();
            cout << userOrder;
            string userInput;
            cin >> userInput;
            if (userInput == "y"){
                Order::printReceipt(userOrder);
            }
            cin.ignore();
		}
		else if (command.compare("help") == 0)
		{
            cout << "Menu to print menu. Checkout to checkout. Add and remove index!";
		}
		parameters.clear();
	}

	cout << "Press any key to quit...";
	std::getchar();

}