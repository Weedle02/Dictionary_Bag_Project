/*
* File:   ABag.h
* Author: Prof Terri Sipantzi
*/

#ifndef ABAG_H
#define	ABAG_H

#include "book.h"
#include "bagADT.h"

template <typename E>
class ABag : public Bag<E> 
{
private:
	int used; 	 
	int capacity;   

	E array[20];
	E *data;	
public:

//Default Constructor for bag
ABag() {
    capacity = 10; 
    data = new E[20]; 
    used = 0;
};

//Parameters for Constructor
ABag(const size_t size) {
    capacity = size;
    data = new E[20];
    used = 0;
};

//returns used variable ie. size
int size() const {
    return used;
};

//returns capacity
int bagCapacity() const {
    return capacity;
};

//empties the bag by setting used to 0
void emptyBag() {
    used = 0;
};

//Adds item to bag if bag has room else will return false
bool addItem(const E& item) {
    if (used < capacity) {
        data[used++] = item;
        return true;
    } else {
        return false;
    }
};

//removes item from
bool remove(E& item) {
 for (int i = 0; i < used; i++) { 
		if (data[i] == item) { 
		item = data[i]; 
		used--; 
		return true;
		}
 		}
		return false;
};

//returns t or f based on if it can find the variable or not 
bool find(E& returnValue) const {
    for (int i = 0; i < used; i++) {
        if (data[i] == returnValue) {
            returnValue = data[i];
            return true;
        }
    }
    return false;
};

// returns t or f based on if the item was added or not
bool inspectTop(E& item) const {
    if (used > 0) {
        item = data[used - 1];
        return true;
    } else {
        return false;
    }
};

//removes top value
bool removeTop(E& returnValue) {
		if (used > 0) { 
			used--; 
			returnValue = data[used];
			return true;
		}
		return false;
	}; 


//overload function
bool operator+=(const E& addend) {
		if (addItem(addend)) { 
			return true; 
		}
		else {
			return false;
		}
	}; 


// Destructor
	~ABag() {};

};

#endif	/* ABAG_H */
