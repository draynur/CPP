/**
 *
 * Name: John Runyard
 * IT 279 - 002
 * Program 1
 * This is my queue testing program
 *
 * p.s. the store opens @8:00
 *
 */

#include <iostream>

#include "Queue.h"

/**
 * Returns a random number from 1 to and including the number given
 * @param  max user input
 * @return     random number
 */
int getRand(int max) {
  return (rand() % max) +1;
}

/**
 * Returns a formatted time string HH:MM
 * @param  minutes amount of minutes
 * @return         formatted time string
 */
string getTime(int minutes) {
  // making sure we dont accidentally create a double
  int hour = (minutes + 60) / 60;
  int minute = minutes % 60;
  // Only add 7 since we added an hour earlier
  string formatted = to_string(hour + 7)+":";

  if (minute == 0) {
    formatted += "00";
  } else  if (minute < 10){
    formatted += "0"+to_string(minute);
  } else {
    formatted += to_string(minute);
  }
  return formatted;
}


int main () {
  // I used the current time to set the random seed on runtime so we can get different results each run through
  srand(time(0));
  // Declaring variables
  Queue line, wait;
  int timeInput, poorCustomer, tempServe, watch, currentTime, tempSize, maxWait;
  int maxServe = maxWait = tempSize = 0;
  int count = 1;
  int totalTime = watch = 720;

  cout << "\nChoose time interval: ";
  cin >> timeInput;

  // Calculating first arrival
  int arrival = getRand(timeInput);
  // Calculating service time
  int serviceTime = arrival + getRand(timeInput);

  while (--watch > 0){
    // Current clock time in minutes
    currentTime = totalTime - watch;

    // Someones here!
    if (currentTime == arrival) {
      cout<<"Customer "<<count<<" arrived at "<<getTime(currentTime)<<"."<<endl;
      // enqueue the customer counter
      line.enqueue(count++);
      // enqueue the current amount of time left
      wait.enqueue(watch);
      // calculate next arrival
      arrival += getRand(timeInput);
    }

    // Someones been served!
    if (currentTime == serviceTime) {
      if (line.getSize()){
        cout<<"Customer "<<line.peek()<<" left at "<<getTime(currentTime)<<"."<<endl;
        // Seeing if there wait time was the longest
        if (maxWait < wait.peek() - watch){
          poorCustomer = line.peek();
          maxWait = wait.peek() - watch;
        }
        // Getting rid of customers wait and id
        line.dequeue();
        wait.dequeue();
      }
      // calculate service time for next customer
      serviceTime += getRand(timeInput);
    }

    // calculate the max size of the line
    if (tempSize < line.getSize()) {
      tempSize = line.getSize();
    }
  }
  // Display results
  cout<<"\nUser input: "<<timeInput<<"\nMax size: "<<tempSize-1<<" customers\nMax wait: Customer "<<poorCustomer<<" for "<<maxWait<<" minutes\n"<<endl;
}
