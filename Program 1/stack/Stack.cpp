/**
 * Name: John Runyard
 * IT 279-002
 * Program 1
 *
 * This is my Queue data structure for Program 1
 */

#include "Stack.h"

/**
 * Stack constructor
 */
Stack::Stack() {
  head = NULL;
  size = 0;
}

/**
 * Push character onto Stack
 * @param c char
 */
void Stack::push(char c) {
  Node* temp = new Node(c);
  temp -> next = head;
  head = temp;
  size++;
}

/**
 * Push integer onto Stack
 * @param i integer
 */
void Stack::push(int i) {
  Node *temp = new Node(i);
  temp -> next = head;
  head = temp;
  size++;
}

/**
 * Remove top item from stack
 */
void Stack:: pop() {
  if (head != NULL) {
    size--;
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

/**
 * Return char value from top of stack
 * @return char value of head
 */
char Stack::peekChar() {
  return head->symbol;
}

/**
 * Return int value from top of Stack
 * @return int value of head
 */
int Stack::peekInt() {
  return head->value;
}

/**
 * Determine if stack is empty
 * @return bool
 */
bool Stack::isEmpty() {
  if (size > 0) {
    return false;
  } else {
    return true;
  }
}
