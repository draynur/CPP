/*

Name: John Runyard
Class: IT 226-001
Assignment 5 - Matrix.cpp
Fall 2019

This is the class that defines all methods in mhead.

*/
#include "mhead.h"

using namespace std;

void Matrix ::populateArray() // This method populates each value in m_matrix, int[][] declared in mhead.h
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m_matrix[i][j] = rand() % 101; // Ensures value is from 0 to 100 to make checking easy
        }
    }
}

string Matrix ::toString() // Appends matrix value and \t to string to build pretty matrix, adds \n to make next row
{
    string string;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            string += to_string(m_matrix[i][j]) + '\t';
        }
        string += '\n';
    }

    return string; // returns result
}

Matrix Matrix ::operator+(Matrix &matrix1) // Operator overloader that defines + to be Matrix addition
{
    Matrix matrix;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix.m_matrix[i][j] = m_matrix[i][j] + matrix1.m_matrix[i][j]; // Adds each index of two matrices and places value in same index in new matrix
        }
    }

    return matrix; // returns result
}

Matrix Matrix ::operator*(Matrix &matrix1) // Operator overloader that defines * to be Matrix multiplication
{
    Matrix matrix;
    int sum;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            sum = 0;
            for (int c = 0; c < 3; c++)
            {
                sum += (m_matrix[a][c] * matrix1.m_matrix[c][b]); // Multiplies row [a][c] by column [c][b] and adds to sum
            }
            matrix.m_matrix[a][b] = sum; // Assigns sum to correct index in new Matrix
        }
    }

    return matrix;
}

bool Matrix ::operator==(Matrix &addMatrix) // Operator overloader that defines == so that two matrices must have the same values for each index
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_matrix[i][j] != addMatrix.m_matrix[i][j]) // If corresponding index to compared array is a different value
            {
                return false; // Return false
            }
        }
    }

    return true; // If no values are different, return true
}
