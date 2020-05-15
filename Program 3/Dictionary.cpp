/**
 * Name: John Runyard
 * IT 279 - Program 3 - Part 1
 * 
 * This is my implementation of a hash table as descripted for Program 3
 */

#include "Dictionary.h"

/**
 * Hashing function that was provided for us in figure 5.4
 */
unsigned int hashFunction(const string & key, int size) {

  unsigned int hashVal = 0;

  for (char c : key) 
    hashVal = 37 * hashVal + c;
  
  return hashVal % size;
}

/**
 * This will find the next prime number that is more than twice the size of the given parameter.
 */
int nextPrime(int key) {
  ifstream primes("primesThrough3Mil.txt");
  int prime = 0;
  string p;
  while (primes >> p){
    prime = stoi(p);
    if (prime > (key * 2)) {
      break;
    }
  }
  primes.close();
  return prime;
}

/**
 * This function will try to insert at a given index, only if the index is not in use.
 * Returns true if succesful, false otherwise
 */
bool insert (HashTableEntry* table, unsigned int index, string anEntry) {
  if (table[index].active == false) {
    table[index].data = anEntry;
    table[index].active = true;
    return true;
  }
  return false;
}

/**
 * This function will quadraticly probe a hash table for an available cell, giving the 
 * starting point of hash.
 */
void probe(string anEntry, HashTableEntry* table, unsigned int hash, int size) {
  bool pass = insert(table, hash, anEntry);
  int count = 1;

  while (!pass) {
    // hash = (hash + (count * count)) % size;
    pass = insert(table, (hash+(count*count++)%size) , anEntry);
  }
}

// Constructor
Dictionary::Dictionary()
{
  this->size = 101;
  this->count = 0;
  this->table = new HashTableEntry[size];
}

// Copy Construcotr
Dictionary::Dictionary(const Dictionary& orig)
{
  this->size = orig.size;
  this->count = orig.count;
  this->table = new HashTableEntry[size];

  for (int i = 0; i <= size; i++) {
    this->table[i].data = orig.table[i].data;
    this->table[i].active = orig.table[i].active;
  }

}

// Destructor
Dictionary::~Dictionary()
{
  delete [] this->table;
}

// Equals operator overloader
Dictionary& Dictionary::operator=(const Dictionary& orig)
{
  if (this != &orig)
    {
      delete [] this->table;
      this->table = new HashTableEntry[orig.size];
      this->count = orig.count;
      this->size = orig.size;
      for (int i = 0; i <= size; i++) {
        table[i] = orig.table[i];
      }
    }
  return *this;
}

/**
 * This method will create a new hash table using a prime number atleast twice as large.
 * Then generates new hash values for each value in the old hash table and copies them over.
 */
void Dictionary::rehash() {
  int oldSize = this->size;
  unsigned int h;

  this->size = nextPrime(this->size);

  HashTableEntry* newTable = new HashTableEntry[this->size];

  for (int i = 0; i < oldSize; i++) {
    if (this->table[i].active == true) {
      h = hashFunction(table[i].data, this->size);
      probe(table[i].data, newTable, h, this->size);
    }
  }
  // delete [] this->table;
  this->table = newTable;
}


/**
 * Adds a new entry, if full then rehash.
 */
void Dictionary::addEntry(string anEntry)
{
  if ((this->count += 1) >= size / 2) {
    this->rehash();
  }

  unsigned int hval = hashFunction(anEntry,this->size);

  probe(anEntry, this->table, hval, this->size);
}

/**
 * This method searches for an entry by hashing the value given and trying to find a match within the 
 * computed hash values. If it finds an inactive entry then value isn't present and returns false
 */
bool Dictionary::findEntry(string key)
{
  bool found = false;

  unsigned int i = hashFunction(key, this->size);

  int count = 1;
  int temp;

  if (table[i].active && table[i].data == key)
    return true;
  
  temp = (i + (count*count++)) % this->size;

  while (true) {
    if (!table[temp].active)
      return false;
    if (table[temp].data == key)
      return true;

    temp = (i + (count*count++)) % this->size;
  }
}

/**
 * Prints contents of Hash Table
 */
void Dictionary::printSorted(ostream& outStream) {
  for (int i = 0; i < this->size; i++) {
    if (this->table[i].data != "") {
      outStream << this->table[i].data << " ";
    }
  }
  cout << endl;
}
