//
// Created by Gang-Ryung Uh on 6/2/18.
//
#include "myMath.h"


/**
 * \brief myFmod  double version of modulo operation
 * @param operand1 double data type
 * @param operand2 double data type
 * @return modulo value of operand1 by operand2
 */
double myFmod(double operand1, double operand2) {

   double quotient=operand1/operand2;
   double floor = (double)((int)quotient - (quotient < 0.0f));

   return operand1-(operand2*floor);
}


/**
 * \brief mySin
 * @param opreand double value in terms of radian [-2*PI .. 2*PI]
 *                where PI = 3.14159265358979323846
 * @return double value in [-1.0 .. 1.0]
 *
 *    Using Taylor expansion
 *    sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 *
 *    Note:  sin(pi/6) = sin(0.523598775598299...) = 1/2
 *           We use identity sin(x) = sin(x + 2*PI) to pre-process
 *           x to be between -2*PI and 2*PI.
 */
double mySin(double operand) {

   const double PI = 3.14159265358979323846;
   double x = myFmod(operand, 2*PI); // modulo operation on double value

   // implement Talyor expansion for the sin function above
   double term = 1.0;  // ith term = x^i / i!
   double sum = 0.0;   // sum of first i terms in taylor series

   for (int i = 1; term != 0.0; i++) {
      term = term * (x / i);
      if (i % 4 == 1)
         sum += term;
      else if (i % 4 == 3)
         sum -= term;
   }
   return sum;
}
