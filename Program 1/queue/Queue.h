/**
 *
 * Name: John Runyard
 * IT 279-002
 * Program 1
 *
 * This is the header for the Queue.cpp
 *
 */
#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <cstddef>
#include <bits/stdc++.h>

using namespace std;

class Queue {
public:
  // struct to hold data
  struct Node {
    int value;
    Node *next;
    Node(int i) {
      value = i;
      next = NULL;
    }
    Node& operator=(const Node& node) {
      if (this != &node) {
        delete next;
        next = node.next;
        value = node.value;
      }
      return *this;
    }
  };
  // nodes to denote front and back of queue
  Node* head;
  Node* rear;
  // value to hold size
  int size;
  // Constructor & Destructor
  Queue();
  ~Queue();
  // Returns value of head node
  int peek();
  // places new node with value i at back of queue
  void enqueue(int i);
  // removes head node
  void dequeue();
  // returns true if empty
  bool isEmpty();
  // returns size of queue
  int getSize();
};
#endif
