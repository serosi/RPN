#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "RPNEval.h"
using namespace std;

int main() {
   int num_expressions;
   cin >> num_expressions;

   RPNEval myRPN = RPNEval();

   for (int i = 1; i <= num_expressions; i++) {
      myRPN.ProcessExpression();
      cout << "Expression " << i << ":" << endl;
      myRPN.PrintExpressionValue();
      myRPN.PrintIntermediateResults();
      cout << "\n\n";
   }
   
   cout << "Normal Termination of Program 1!" << endl;
}