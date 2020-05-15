#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList() // set default values
{
    size = 0;
    capacity = 1;
    array = new int[capacity];
}

ArrayList::~ArrayList() // get rid of dynamically allocated array
{ 
    delete[] array;
}

void ArrayList::push(int item)
{
    if (size == 0)
    {
        array[0] = item; // if new array
    }

    if (size == capacity) // if the array is full
    {                                     
        capacity = capacity + capacity; // capacity is double
        int *replace = new int[capacity]; // new temp array to replace old one
        for (int i = 0; i <= size; i++)
        {
            replace[i] = array[i]; // copy values into new array
        }
        delete[] array; // delete array
        array = new int[capacity]; // assign array to new capacity
        for (int i = 0; i <= size; i++)
        {
            array[i] = replace[i]; // copy back old values
        }
        delete[] replace;   // delete temp
        array[size] = item; // add item
    }
    else
    {
        array[size] = item; // size is less than capacity, so add item like usual
    }
    size++; // indicate that array is now one larger
}

int ArrayList::erase(int item)
{
    for (int i = 0; i < size; i++) // look through whole array
    {
        if (array[i] == item) // first value that matches passed in value to delete (leftmost)
        {
            for (i; i < size; i++) // starting from here
            {                            
                array[i] = array[i + 1]; // assign values from right to left
            }
            array[size - 1] = 0; // assign 0 to last value so no duplicates
            size--; // indicate that array is now one smaller
            return item; // return item that was deleted to display
        }
    }
    if (size < (capacity / 2)) // if used space is less that half of capacity
    {
        capacity = capacity / 2; // capacity is halfed
        int *replace = new int[capacity]; // replacement array
        for (int i = 0; i < size; i++)
        {
            replace[i] = array[i]; // copy values
        }
        delete[] array; // delete old array
        array = new int[capacity]; // make new array with new capacity
        for (int i = 0; i < size; i++)
        {
            array[i] = replace[i]; // copy back old values
        }
        delete[] replace; // delete temp
    }

    return 0; // return indicating that no values were repeated
}

string ArrayList::toString()
{
    string s = "Size: " + to_string(size) + "\nCapacity: " + to_string(capacity) + "\n"; // display stats
    for (int i = 0; i < size; i++)
    {
        s += "Array Index[" + to_string(i) + "]: " + to_string(array[i]) + "\n"; // display contents
    }
    return s;
}