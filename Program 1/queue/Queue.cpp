/**
 *
 * Name: John Runyard
 * IT 279-002
 * Program 1
 *
 * This is the class I used to define the adt for my linked-list queue structure
 *
 */

#include "Queue.h"

/**
 * Queue constructor
 */
Queue::Queue() {
  head = NULL;
  rear = NULL;
  size = 0;
}

/**
 * Queue destructor
 */
Queue::~Queue() {
  if (head != NULL) {
    Node* temp = head;

    while (temp != NULL) {
      Node *current = temp;
      temp = temp->next;
      delete current;
    }
  }
}

/**
 * Returns value from head node
 * @return value from head node
 */
int Queue::peek() {
  if (getSize()) {
    return head->value;
  } else {
    return INT_MIN;
  }
}

/**
 * places item at rear
 * @param i integer to enqueue
 */
void Queue::enqueue(int i) {
  // increment size regardless of what happens
  size++;
  // create node to append
  Node* temp = new Node(i);
  if (rear == NULL) {
    // if empty new item is rear and head
    rear = head = temp;
  } else {
    // append to end
    rear->next = temp;
    rear = temp;
  }
}

/**
 * remove item from front of queue
 */
void Queue::dequeue() {
  if (!isEmpty()) {
    // decrement size only if queue isn't empty
    size--;
    // create temp
    Node* temp = head;
    head = head->next;
    // get rid of old values memory
    delete (temp);
    // If we removed the last node in stack
    if (isEmpty()) {
      rear = NULL;
    }
  }
}

/**
 * Returns true if queue is empty
 * @return bool
 */
bool Queue::isEmpty() {
  if (head==NULL) {
    return true;
  } else {
    return false;
  }
}

/**
 * Returns size of Queue
 * @return size of queue
 */
int Queue::getSize(){
  return size;
}
