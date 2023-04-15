//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_untitled_api.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Mar-2023 16:47:13
//

// Include Files
#include "_coder_untitled_api.h"
#include "_coder_untitled_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131642U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "untitled",                                           // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *inputArg1,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *inputArg1
//                const char_T *identifier
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *inputArg1,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(inputArg1), &thisId);
  emlrtDestroyArray(&inputArg1);
  return y;
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const real_T u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const mxArray * const prhs[2]
//                int32_T nlhs
//                const mxArray *plhs[2]
// Return Type  : void
//
void untitled_api(const mxArray *const prhs[2], int32_T nlhs,
                  const mxArray *plhs[2])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T inputArg1;
  real_T inputArg2;
  real_T outputArg1;
  real_T outputArg2;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  inputArg1 = emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "inputArg1");
  inputArg2 = emlrt_marshallIn(st, emlrtAliasP(prhs[1]), "inputArg2");
  // Invoke the target function
  untitled(inputArg1, inputArg2, &outputArg1, &outputArg2);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(outputArg1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(outputArg2);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void untitled_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  untitled_xil_terminate();
  untitled_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void untitled_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void untitled_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_untitled_api.cpp
//
// [EOF]
//
