/*

Name: John Runyard
Class: IT 226-001
Assignment 5 - main.cpp
Fall 2019

This is the class that declares Matrix objects and uses their now defined methods.

*/

#include "mhead.h"
#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    // Ensures that random values are used everytime by setting the random seed to the current time
    srand(time(0));
     auto start = std::chrono::high_resolution_clock::now();
    // Declaring Matrix objects for my use later
    Matrix matrix1;
    Matrix matrix2;
    Matrix add;
    Matrix mult;

    // Line break to help make things pretty
    string const br = "-----------------------\n";

    //Populate Matrix 1 and Matrix 2
    matrix1.populateArray();
    matrix2.populateArray();

    //Use the populated values to multiply and add matrices to demonstrate functionality
    add = matrix1 + matrix2;
    mult = matrix1 * matrix2;

    //Displaying contents of matrices
    cout << br << "Matrix 1\n"
         << br << matrix1.toString() << br << endl;
    cout << br << "Matrix 2\n"
         << br << matrix2.toString() << br << endl;

    //Tests to see if the two randomly generated matrices are equal to each other, which is very unlikely (but possible)
    if (matrix1 == matrix2)
    {
        cout << "Matrices are equal?!\n"
             << endl;
    }
    else
    {
        cout << "Matrices are not equal!\n"
             << endl;
    }

    //Displays contents of multiplied and added matrices
    cout << br << "Matrix 1 + Matrix 2\n"
         << br << add.toString() << br << endl;
    cout << br << "Matrix 1 * Matrix 2\n"
         << br << mult.toString() << br << endl;
     auto finish = std::chrono::high_resolution_clock::now();

     std::chrono::duration<double> elapsed = finish - start;


     std::cout<<"Elapsed Time: " << elapsed.count() <<"s\n";
}