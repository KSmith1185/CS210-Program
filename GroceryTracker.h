#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

class GroceryTracker {
private:
	map<string, int> itemFreq; // Map for item frequencies
	void loadData();  // Loads data from input file
	void BackupData();  // Stores data in output file

public:
	GroceryTracker();
	int getItemFreq(const string& item);  // Gets frequency of a specific item
	void displayFreq();  // Displays frequency of all items
	void displayHisto();  // Displays histogram for all items
	void menu();  // Diplays user menu
};

#endif