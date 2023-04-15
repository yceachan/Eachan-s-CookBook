//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_untitled_api.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Mar-2023 16:47:13
//

#ifndef _CODER_UNTITLED_API_H
#define _CODER_UNTITLED_API_H

// Include Files
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void untitled(real_T inputArg1, real_T inputArg2, real_T *outputArg1,
              real_T *outputArg2);

void untitled_api(const mxArray *const prhs[2], int32_T nlhs,
                  const mxArray *plhs[2]);

void untitled_atexit();

void untitled_initialize();

void untitled_terminate();

void untitled_xil_shutdown();

void untitled_xil_terminate();

#endif
//
// File trailer for _coder_untitled_api.h
//
// [EOF]
//
