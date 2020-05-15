// file to implement a hast table of Entry objects

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct HashTableEntry
{
  string data;
  bool active;
};

class Dictionary
{
 private:
  HashTableEntry* table;
  int size;
  int count;

 public:

  Dictionary();
  // Creates an empty dictionary;

  Dictionary(const Dictionary& orig);
  // Copy constructor

  virtual ~Dictionary();
  // Destructor

  Dictionary& operator=(const Dictionary& orig);
  // assignment operator
 

  void addEntry(string anEntry);
  // Preconditions: anEntry has a key not already in the dictionary
  // Postconditions: anEntry has been added to the dictionary

  bool findEntry(string key);
  // Postconditions: if key is found in the dictionary, returns true 
  //   and anEntry is the entry with key; otherwise returns false

  void printSorted(ostream& outStream);
  // Postconditions: has printed contents of the dictionary in order

 private:

  void rehash();
  // Postconditions: has rehashed table with size of the next prime number > 2x current size

};

#endif


