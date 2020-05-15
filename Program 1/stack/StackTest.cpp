/**
 * Name: John Runyard
 * Programming Assignment 1
 * Stack Test Program
 *
 */

#include "Stack.h"
#include <iostream>

using namespace std;

int main ()
{
  // Declaring variables to keep track of values
  Stack undoVal, undoChar, redoVal, redoChar;
  int current = 0;
  int value;
  string input;
  undoVal.push(0);
  undoChar.push('a');

  cout<<"Enter an operator followed by a number. \nSpecial commands are \nQ: quit\nR: redo\nU: undo\nC: clear\n"<<endl;
  // Q gets out of the loop
  while (input != "Q") {
    // display status
    cout<<current<<"\n>";
    cin>>input;
    char symbol = input[0];
    // making sure we ingore the symbol here
    if (input.length() > 1) {
      value = stoi(input.substr(1));
    }
    if (symbol == '*') {
      undoChar.push(symbol);
      int temp = undoVal.peekInt();
      undoVal.push(value);
      current *= value;
    } else if (symbol == '+') {
      undoChar.push(symbol);
      int temp = undoVal.peekInt();
      undoVal.push(value);
      current += value;
    } else if (symbol == '-') {
      undoChar.push(symbol);
      int temp = undoVal.peekInt();
      undoVal.push(value);
      current = current - value;
    } else if (symbol == '/') {
      undoChar.push(symbol);
      int temp = undoVal.peekInt();
      undoVal.push(value);
      current = current / value;
    } else if (symbol == 'R') {
      if (!redoVal.isEmpty()) {
        int integer = redoVal.peekInt();
        char character = redoChar.peekChar();
        switch (character) {
          case '*':
            current = current * integer;
            redoVal.pop();
            redoChar.pop();
            break;
          case '/':
            current = current / integer;
            redoVal.pop();
            redoChar.pop();
            break;
          case '+':
            current = current + integer;
            redoVal.pop();
            redoChar.pop();
            break;
          case '-':
            current = current - integer;
            redoVal.pop();
            redoChar.pop();
            break;
          default:
            break;
        }
      } else {
        cout<<"Nothing left to redo!"<<endl;
      }
    } else if (symbol == 'U') {
      int integer = undoVal.peekInt();
      char character = undoChar.peekChar();
      switch (character) {
        case '*':
          current = current / integer;
          redoVal.push(integer);
          redoChar.push(character);
          undoChar.pop();
          undoVal.pop();
          break;
        case '/':
          current *= integer;
          redoVal.push(integer);
          redoChar.push(character);
          undoChar.pop();
          undoVal.pop();
          break;
        case '+':
          current = current - integer;
          redoVal.push(integer);
          redoChar.push(character);
          undoChar.pop();
          undoVal.pop();
          break;
        case '-':
          current += integer;
          redoVal.push(integer);
          redoChar.push(character);
          undoChar.pop();
          undoVal.pop();
          break;
        case 'c':
          current = integer;
          undoChar.pop();
          undoVal.pop();
          break;
        default:
          cout<<"Nothing left to undo!"<<endl;
          break;
      }

    } else if (symbol == 'C') {
      undoVal.push(current);
      undoChar.push('c');
      current = 0;
    }
  }

  cout<<"\nGoodbye!"<<endl;

}
