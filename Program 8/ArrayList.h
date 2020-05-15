#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <string>
class ArrayList {
    public:
    int size;
    int capacity;
    int *array;
    ArrayList();
    ~ArrayList();
    void push(int item);
    int erase(int item);
    std::string toString();
};
#endif