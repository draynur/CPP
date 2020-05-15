#include "ArrayList.h"
#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    //declare variables and set rand() seed
    int sub;
    int i;
    int result;
    ArrayList array;
    srand(time(0));
    auto start = std::chrono::high_resolution_clock::now(); // start the clock

    cout << "Intial Array\n"
         << array.toString() << endl; // Prove initial variable values

    cout << "Adding 1 Number" << endl;

    array.push(rand() % 101);

    cout << array.toString() << endl;

    cout << "Adding 20 Numbers" << endl;
    for (i = 0; i < 20; i++)
    {
        array.push(rand() % 101);
    }

    cout << array.toString() << endl;

    cout << "Try to erase 10 random numbers" << endl;
    for (i = 0; i < 10; i++)
    {
        sub = rand() % 101; // setting number range to be same as arraylist
        result = array.erase(sub);
        if (result > 0)
        {
            cout << "Removed " << result << endl; // if erase returns positive number display
        }
    }
    
    cout << array.toString() << endl;

    cout << "Adding 20 Numbers" << endl;
    for (i = 0; i < 20; i++)
    {
        array.push(rand() % 101);
    }

    cout << array.toString() << endl;

    cout << "Try to erase 20 random numbers" << endl;
    for (i = 0; i < 20; i++)
    {
        sub = rand() % 101; // setting number range to be same as arraylist
        result = array.erase(sub);
        if (result > 0)
        {
            cout << "Removed " << result << endl; // if erase returns positive number display
        }
    }

    cout << array.toString() << "\n\nFinished!" <<endl;

    auto finish = chrono::high_resolution_clock::now(); // ends clock to time program

    chrono::duration<double> elapsed = finish - start; // calculates time as seconds 

    cout<<"Elapsed Time: "<<elapsed.count()<<"s"<<endl; // displays elapsed time
}