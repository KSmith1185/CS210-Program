#include "GroceryTracker.h"
#include <fstream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to convert to lower case
string toLowerCase(const string& str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

// Constructor
GroceryTracker::GroceryTracker() {
	loadData();
	BackupData();
}

// Load data from input file
void GroceryTracker::loadData() {
	ifstream inFS;

	inFS.open("CS210_Project_Three_Input_File.txt");

	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
		return;
	}

	string item;
	while (inFS >> item) {
		item = toLowerCase(item);
		itemFreq[item]++;
	}
	inFS.close();
}

// Backup data to output file
void GroceryTracker::BackupData() {
	ofstream outFS;

	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat." << endl;
		return;
	}

	for (const auto& pair : itemFreq) {
		outFS << pair.first << " " << pair.second << endl;
	}
	outFS.close();
}

// Get frequency of a specific item
int GroceryTracker::getItemFreq(const string& item) {
	string lowerItem = toLowerCase(item);
	if (itemFreq.find(lowerItem) != itemFreq.end()) {
		return itemFreq[lowerItem];

	}
	else {
		return 0;
	}
}

// Display frequency of all items
void GroceryTracker::displayFreq() {
	for (const auto& pair : itemFreq) {
		cout << pair.first << " " << pair.second << endl;
	}
}

// Diplay histogram of all items
void GroceryTracker::displayHisto() {
	for (const auto& pair : itemFreq) {
		cout << setw(15) << left << pair.first << " ";
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
}

// Menu for interaction
void GroceryTracker::menu() {
	int choice;

	do {
		cout << "\nMenu:\n";
		cout << "1. Find frequency of an item\n";
		cout << "2. Display frequencies of all items\n";
		cout << "3. Display histogram of item frequencies\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << "\n";

		// Error handling for invalid input from user
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number between 1 and 4.\n";
		}

		switch (choice) {
		case 1: {
			string item;
			cout << "Enter item name: ";
			cin >> item;
			int frequency = getItemFreq(item);
			if (frequency > 0) {
				cout << "The item '" << item << "' appears " << frequency << " times.\n";  // Display frequency of specific item from list
			}
			else {
				cout << "The item '" << item << "' does not appear on the list.\n"; // Displays if item is not found in list
			}
			break;
		}

		case 2:
			displayFreq();
			break;

		case 3:
			displayHisto();
			break;

		case 4:
			cout << "Exiting. Have a nice day!";
			break;

		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);

}