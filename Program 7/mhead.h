#ifndef MHEAD_H
#define MHEAD_H 
#include <string>
class Matrix
{
public: // Declared all methods and values public so I wouldn't run into problems
    int m_matrix[3][3]; // where matrix data is stored, all matrices are sized 3,3
    void populateArray(); // randomly assigns value to index in matrix
    std::string toString(); // had to include string because this method returns string
    Matrix operator+(Matrix &matrix1); // operator overloader
    Matrix operator*(Matrix &matrix1); // operator overloader
    bool operator==(Matrix &addMatrix); // operator overloader
};
#endif