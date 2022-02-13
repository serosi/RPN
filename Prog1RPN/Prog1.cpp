#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "RPNEval.h"
using namespace std;

int main() {
   int num_expressions;
   cin >> num_expressions;

   for (int i = 1; i <= num_expressions; i++) {
      RPNEval myRPN = RPNEval(); // create new instance of RPNeval class
      cout << "Expression " << i << ":" << endl;
      myRPN.ProcessExpression(); // process user input

      if (myRPN.IsValid() == true) // print value only if valid
         myRPN.PrintExpressionValue();
      else
         cout << "Invalid Expression" << endl;

      myRPN.PrintIntermediateResults(); // print intermediate results regardless of validity
      cout << "\n\n";
   }
   
   cout << "Normal Termination of Program 1!" << endl; // exit the program
}