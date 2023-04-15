//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Mar-2023 16:47:13
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "untitled.h"
#include "untitled_terminate.h"

// Function Declarations
static double argInit_real_T();

// Function Definitions
//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_untitled();
  // Terminate the application.
  // You do not need to do this more than one time.
  untitled_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_untitled()
{
  double inputArg1_tmp;
  double outputArg1;
  double outputArg2;
  // Initialize function 'untitled' input arguments.
  inputArg1_tmp = argInit_real_T();
  // Call the entry-point 'untitled'.
  untitled(inputArg1_tmp, inputArg1_tmp, &outputArg1, &outputArg2);
}

//
// File trailer for main.cpp
//
// [EOF]
//
