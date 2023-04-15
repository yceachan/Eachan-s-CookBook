//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_untitled_info.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Mar-2023 16:47:13
//

// Include Files
#include "_coder_untitled_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *emlrtMexFcnResolvedFunctionsInfo();

// Function Definitions
//
// Arguments    : void
// Return Type  : const mxArray *
//
static const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  static const int32_T iv[2]{0, 1};
  const mxArray *m;
  const mxArray *nameCaptureInfo;
  nameCaptureInfo = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&nameCaptureInfo, m);
  return nameCaptureInfo;
}

//
// Arguments    : void
// Return Type  : mxArray *
//
mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[7]{
      "Version",      "ResolvedFunctions", "Checksum",    "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "PropertyList"};
  const char_T *epFieldName[6]{
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("untitled"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString("C:\\Users\\yceachan\\Desktop\\C_"
                          "class\\\xe6\x95\xb0\xe6\x8d\xae\xe7\xbb\x93\xe6\x9e"
                          "\x84\xe4\xb8\x8e\xe7\xae\x97\xe6\xb3\x95\\\xe6"
                          "\x95\xb0\xe8\xae\xba\\untitled.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(738975.69746527774));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("9.14.0.2206163 (R2023a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("UZNV6GSDjNHqUjgyPa3PcG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

//
// File trailer for _coder_untitled_info.cpp
//
// [EOF]
//
