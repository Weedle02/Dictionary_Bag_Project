/*
* File:   bagtestmain.cpp
* Author: Prof Sipantzi -- CSIS 215 -- Programming Assignment 1 -- Bag Dictionary
*
* Created on July 14, 2012, 11:45 AM
* Updated pointers to smart pointers in ABag and BDictionary on 12/14/2018
*/

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "ABag.h"
#include "BDictionary.h"

using namespace std;

const size_t DICTIONARY_SIZE = 20;

void PauseScreen(); //Used to pause screen output

/*
* Tests BDictionary with int and string objects only.
*/

int main(int argc, char** argv) {

	cout << "<William Brooks> -- CSIS 215 Programming Assignment 1 -- Bag Dictionary" << endl << endl;

	BDictionary<int, string> myIntStrDict(DICTIONARY_SIZE);
	BDictionary<string, int> myStrIntDict(DICTIONARY_SIZE);

	// myIntStrDict tests
	// INSERT: myIntStrDict
	cout << "Testing dictionary with <int, string> KV Pair\n";
	for (int i = 1; i <= DICTIONARY_SIZE; i++) {
		stringstream sn;
		sn << "Beth " << i * 10;
		myIntStrDict.insert(i * 10, sn.str());
	}
	cout << "INSERT: Size of myIntStrDict is " << myIntStrDict.size() << endl;

	// REMOVEANY: myIntStrDict
	string strData;
	if (myIntStrDict.removeAny(strData) == true) {
		cout << "REMOVEANY: My string data is " << strData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";

	// FIND: test for myIntStrDict.find
	int intKey = 40;
	if (myIntStrDict.find(intKey, strData) == true) {
		cout << "FIND: My data at key==" << intKey << " is: " << strData << "\n";
		cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << intKey << "\n";
	}

	// REMOVE: myIntStrDict
	intKey = 60;
	if (myIntStrDict.remove(intKey, strData) == true) {
		cout << "REMOVE: Removed key " << intKey << " which was " << strData << "\n";
	}
	else {
		cout << "Could not find key " << intKey << "\n";
	}
	cout << "Size of my dictionary is " << myIntStrDict.size() << "\n";

	// CLEAR: myIntStrDict
	myIntStrDict.clear();
	cout << "CLEAR: Size of myIntStrDict is " << myIntStrDict.size() << "\n\n";

	/* end myIntStrDict tests ---------------------------------------------*/

	// myStrIntDict tests
	// INSERT: myStrIntDict
	cout << "Testing dictionary with <string, int> KV Pair\n";
	myStrIntDict.insert("Terri", 57);
	myStrIntDict.insert("Beth", 53);
	myStrIntDict.insert("Jeremy", 19);
	myStrIntDict.insert("Nathan", 17);
	myStrIntDict.insert("Zipper", 2);
	myStrIntDict.insert("Button", 1);
	myStrIntDict.insert("Kiwi", 7);
	myStrIntDict.insert("Masoala", 10);

	cout << "INSERT: Size of myStrIntDict is " << myStrIntDict.size() << endl;

	// REMOVEANY: myStrIntDict
	int intData;
	if (myStrIntDict.removeAny(intData) == true) {
		cout << "REMOVEANY: My int data is " << intData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myStrIntDict.size() << "\n";

	// FIND: myStrIntDict.find
	string strKey = "Kiwi";
	if (myStrIntDict.find(strKey, intData) == true) {
		cout << "FIND: " << strKey << "\'s age is " << intData << endl;
		cout << "Size of myStrIntDict is " << myStrIntDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << strKey << "\n";
	}

	// REMOVE: myStrIntDict
	strKey = "Button";
	if (myStrIntDict.remove(strKey, intData) == true) {
		cout << "REMOVE: Removed key " << strKey << " which was " << intData << "\n";
	}
	else {
		cout << "Could not find key " << strKey << "\n";
	}
	cout << "Size of my dictionary is " << myStrIntDict.size() << "\n";

	// CLEAR: myStrIntDict
	myStrIntDict.clear();
	cout << "CLEAR: Size of myStrIntDict is " << myStrIntDict.size() << "\n\n";

	/* end myStrIntDict tests ---------------------------------------------*/

	ABag<KVpair<int, string>> myBag; //Used to test bag functions not previously demonstrated 

	KVpair<int, string> pair1, pair2, pair3; 
	pair1 = KVpair<int, string>(18, "Devin");
	pair2 = KVpair<int, string>(17, "Aidan");
	pair3 = KVpair<int, string>(16, "Regan");

	cout << "Testing: KVpair<int, string>." << endl; 	
	cout << "Size: " << myBag.size() << endl;


// Add pair1 to myBag and check if successful
if (myBag.addItem(pair1)) 
{
    // Display success message along with the updated bag size
    cout << "ADD: Bag size is now: " << myBag.size() << endl;
} else 
{
    // Display failure message if adding pair1 failed
    cout << "ADD: Failed" << endl;
}

// Find pair1 in myBag and check if successful
if (myBag.find(pair1)) 
{
    // Display success message if pair1 is found in the bag
    cout << "FIND: Item found in the bag" << endl;
} else 
{
    // Display failure message if finding pair1 failed
    cout << "FIND: Failed" << endl;
}

// Inspect the top of myBag with pair1 and check if successful
if (myBag.inspectTop(pair1)) 
{
    // Display success message if inspecting the top with pair1 is successful
    cout << "INSPECT TOP: Item found at the top" << endl;
} else 
{
    // Display failure message if inspecting the top with pair1 failed
    cout << "INSPECT TOP: Failed" << endl;
}

// Display a message indicating the intent to add two more items
cout << "ADD ITEM: Adding two more items." << endl;
// Add pair2 and pair3 to myBag
myBag.addItem(pair2);
myBag.addItem(pair3);

// Remove pair2 from myBag and check if successful
if (myBag.remove(pair2)) 
{
    // Display success message if removing pair2 is successful
    cout << "REMOVE: Removed the second item." << endl;
} else 
{
    // Display failure message if removing pair2 failed
    cout << "REMOVE: Failed" << endl;
}

// Remove the top item from myBag with pair1 and check if successful
if (myBag.removeTop(pair1)) 
{
    // Display success message if removing the top item with pair1 is successful
    cout << "REMOVE TOP: Removed the top item." << endl;
} else 
{
    // Display failure message if removing the top item with pair1 failed
    cout << "REMOVE TOP: Failed" << endl;
}

// Pause the screen
PauseScreen();
// Return 0 to indicate successful completion of the program
return 0;

}

//Used to pause the screen wherever desired
void PauseScreen()
{
	char ch;
	cout << "\nPress the Enter key to continue ... ";
	cin.get(ch);
}
