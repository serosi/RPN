#include <iostream>
#include "Queue.h"

//---------------------------------------------------------------- 
// Default constructor for queue
//---------------------------------------------------------------- 
Queue::Queue() {
   front = 0;
   back = 0;
}

//---------------------------------------------------------------- 
// Checks if queue is empty
//---------------------------------------------------------------- 
bool Queue::isEmpty() {
   if (front == back)
      return true;
   else
      return false;
}

//---------------------------------------------------------------- 
// Checks if queue is full
//---------------------------------------------------------------- 
bool Queue::isFull() {
   if (back == MAX_SIZE)
      return true;
   else
      return false;
}

//---------------------------------------------------------------- 
// Adds an item to the queue
//---------------------------------------------------------------- 
void Queue::Enqueue(float value) {
   queue[back++] = value;
}

//---------------------------------------------------------------- 
// Removes an item from the queue
//---------------------------------------------------------------- 
void Queue::Dequeue(float& value) {
   value = queue[front];
   int temp = 1;
   while (temp < back) {
      queue[temp - 1] = queue[temp];
      temp++;
   }
   back--;
}

//---------------------------------------------------------------- 
// Empties the stack by setting front & back values to 0
//---------------------------------------------------------------- 
void Queue::MakeEmpty() {
   front = 0;
   back = 0;
}

//---------------------------------------------------------------- 
// Prints the entire queue
//---------------------------------------------------------------- 
void Queue::PrintQueue() {
   for (int i = front; i < back; i++) {
      std::cout << queue[i] << " ";
   }
}

//---------------------------------------------------------------- 
// Returns last element of the queue
//---------------------------------------------------------------- 
float Queue::LastElement() {
   return queue[back-1];
}