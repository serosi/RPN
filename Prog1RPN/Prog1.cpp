#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "RPNEval.h"
using namespace std;

int main() {
   int num_expressions;
   cin >> num_expressions;

   for (int i = 1; i <= num_expressions; i++) {
      RPNEval myRPN = RPNEval();
      cout << "Expression " << i << ":" << endl;
      myRPN.ProcessExpression();

      if (myRPN.IsValid() == true)
         myRPN.PrintExpressionValue();
      else
         cout << "Invalid Expression" << endl;

      myRPN.PrintIntermediateResults();
      cout << "\n\n";
   }
   
   cout << "Normal Termination of Program 1!" << endl;
}