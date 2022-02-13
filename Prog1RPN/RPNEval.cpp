#include <iostream>
#include <string>

#include "RPNEval.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;


   //---------------------------------------------------------------- 
   // Reads and processes the next RPN expression from the input.
   //---------------------------------------------------------------- 
   void RPNEval::ProcessExpression() {
      valid = true;
      bool done = false;
      bool optr = false; // has ProcessOperator been called?
      char ch;

      while (valid && !done) {
         cin >> ch;

         if (ch >= '0' && ch <= '9') {
            cin.putback(ch); // put ch back into input stream
            RPNEval::ProcessOperand();
         }
         else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            RPNEval::ProcessOperator(ch, answer, valid);
            optr = true;
            cout << ch << " ";
         }
         else if (ch == '#')
            done = true; // done, exit while loop
         else {
            cout << ch << " ";
            valid = false;
         }
      }
      cin.ignore(256, '\n');

      if (stack.Size() == 0 && queue.isEmpty() && !optr) {
         answer = stack.Top();
      // if expression contains one value & no operands value will be the answer
      }                             

      if (stack.isEmpty()) {
         valid = false;
      }
      else if (valid) {
         stack.Pop();
         if (!stack.isEmpty()) {
            valid = false;
         }
      }
      cout << endl;
   }

   //---------------------------------------------------------------- 
   // Processes the next operand(s) from the input.
   //---------------------------------------------------------------- 
   void RPNEval::ProcessOperand() {
      float float_operand = 0;
      cin >> float_operand;
      cout << float_operand << " ";
      stack.Push(float_operand); 
   }

   //---------------------------------------------------------------- 
   // Processes the next operator from the input, evaluates the
   // expression, and pushes to intermediate result queue.
   //---------------------------------------------------------------- 
   void RPNEval::ProcessOperator(char ch, float answer, bool valid) {
      float op1, op2 = 0;

      if (stack.isEmpty()) {
         valid = false;
      }

      op2 = stack.Pop();

      if (stack.isEmpty()) {
         valid = false;
      }

      op1 = stack.Pop();

      switch (ch) {
      case '+':
         answer = op1 + op2;
         break;
      case '-':
         answer = op1 - op2;
         break;
      case '*':
         answer = op1 * op2;
         break;
      case '/':
         if (op2 == 0) {
            valid = false; // can't divide by 0
         }
         answer = op1 / op2;
         break;
      }

      if (valid) {
         stack.Push(answer);
         queue.Enqueue(answer);
      }

   }

   //---------------------------------------------------------------- 
   // Print out the intermediate results to the standard 
   // output, with one space after each result. 
   // Does NOT print any header or any newlines. 
   //---------------------------------------------------------------- 
   void RPNEval::PrintIntermediateResults() {
      cout << "The Intermediate Results are: ";
      queue.PrintQueue();
      queue.MakeEmpty();
   }

   //---------------------------------------------------------------- 
   // Print the value of the expression
   //---------------------------------------------------------------- 
   void RPNEval::PrintExpressionValue() {
      if (valid && !queue.isEmpty()) {
         answer = queue.LastElement(); // if queue IS empty, there was one operand
      }
      else if (valid) {
         cout << "The value is: " << answer << "\n";
      }

   }