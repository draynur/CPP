/**
 * Name: John Runyard
 * IT 279-002
 * Program 1
 *
 * This is my Queue data structure for Program 1
 */
#ifndef STACK_H
#define STACK_H
#include <cstddef>
class Stack
{
public:
  // Structure to hold data for both integer and character
  struct Node {
    int value;
    char symbol;
    // Reference to th next node
    Node* next;
    Node (int i) {
      value = i;
      symbol = 'a';
      next = NULL;
    }
    Node (char c) {
      value = 0;
      symbol = c;
      next = NULL;
    }
  };
  // Defuault constructor
  Stack();
  // Top node
  Node* head;
  // Size of stack
  int size;
  // Pushing int to stack
  void push(int i);
  // Pushing char to stack
  void push(char c);
  // Removing top node
  void pop();
  // Getting character
  char peekChar();
  // Getting int
  int peekInt();
  // Returns true if is size==0
  bool isEmpty();
};
#endif
