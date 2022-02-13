#include <iostream>
#include "Stack.h"

Stack::Stack() {
   top = -1;
}

//---------------------------------------------------------------- 
// Checks if stack is empty
//---------------------------------------------------------------- 
bool Stack::isEmpty() {
   if (top == -1)
      return true;
   else
      return false;
}

//---------------------------------------------------------------- 
// Checks if stack is full
//---------------------------------------------------------------- 
bool Stack::isFull() {
   if (Stack::top == MAX_VAL - 1)
      return true;
   else
      return false;
}

//---------------------------------------------------------------- 
// Returns the top element of the stack
//---------------------------------------------------------------- 
float Stack::Top() {
      return stack[top];
}

//---------------------------------------------------------------- 
// Pops the top element off of the stack & returns value
//---------------------------------------------------------------- 
float Stack::Pop() {
      return stack[top--];
}

//---------------------------------------------------------------- 
// Pushes an item to the stack
//---------------------------------------------------------------- 
void Stack::Push(float value) {
   stack[++top] = value;
}

//---------------------------------------------------------------- 
// Returns size of stack
//---------------------------------------------------------------- 
int Stack::Size() {
   return top;
}