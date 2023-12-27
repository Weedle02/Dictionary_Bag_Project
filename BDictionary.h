/*
* File:   BDictionary.h -- implement a dictionary use an array-based bag
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your Dictionary
*/

#ifndef BDICTIONARY_H
#define	BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
private:
	ABag<KVpair<Key, E>>* dictionary; // Pointer to an ABag object.
	
public:
    // Initial Constructor
	BDictionary() 
	{
        dictionary = new ABag<KVpair<Key, E>>();
    };

    // Constructor but has parameters, controls initial size of bag.
	 BDictionary(const size_t size) 
	{
        dictionary = new ABag<KVpair<Key, E>>(size);
    };

	// Returns the size of the dictionary.
    int size() 
    {
    return dictionary->size();
    }

    // Clears all items in the dictionary.
    void clear() 
    {
    dictionary->emptyBag();
    };

    // Inserts a key-value pair into the dictionary.
    // Returns true if successful, false otherwise.
    bool insert(const Key& k, const E& e) 
    {
    return dictionary->addItem(KVpair<Key, E>(k, e));
    }

    // Removes the value associated with the given key.
    // Returns true if successful, false if the key is not found.
    bool remove(const Key& k, E& rtnval) 
    {
    // Create a key-value pair for the search
    KVpair<Key, E> pair(k, rtnval);
    // Attempt to remove the pair from the dictionary
    if (dictionary->remove(pair)) 
    {
        // If successful, update the return value and return true
        rtnval = pair.value();
        return true;
    }
    // Return false if the key is not found
    return false;
    }

    // Removes any value from the dictionary.
    // Returns true if successful, false if the dictionary is empty.
    bool removeAny(E& returnvalue) 
    {
    // Create a key-value pair for the removal
    KVpair<Key, E> pair;
    // Attempt to remove the top pair from the dictionary
    if (dictionary->removeTop(pair)) 
    {
        // If successful, update the return value and return true
        returnvalue = pair.value();
        return true;
    }
    // Return false if the dictionary is empty
    return false;
    }

    // Finds a value associated with the given key in the dictionary.
    // Updates the return value and returns true if the key is found, false otherwise.
     find(const Key& k, E& returnvalue) const 
    {
    // Create a key-value pair for the search
    KVpair<Key, E> pair(k, returnvalue);
    // Check if the pair is found in the dictionary
    if (dictionary->find(pair)) 
    {
        // If found, update the return value and return true
        returnvalue = pair.value();
        return true;
    }

    // Return false if the key is not found
    return false;
    }


	 ~BDictionary() {}; // Destructor

};


#endif	/* BDICTIONARY_H */

