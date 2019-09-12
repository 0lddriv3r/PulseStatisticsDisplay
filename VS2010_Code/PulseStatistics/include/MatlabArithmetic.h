//
// MATLAB Compiler: 6.2 (R2016a)
// Date: Thu Apr 11 10:46:17 2019
// Arguments: "-B" "macro_default" "-B" "cpplib:MatlabArithmetic" "-W"
// "cpplib:MatlabArithmetic" "-T" "link:lib" "gf_allpulses_Cal_Para_V1.m"
// "gf_DataBase_Indentity_v1.m" "gf_CPIValidTableSetForOneFile_to_CSV_V1.m"
// "gf_datenum_to_datestr.m" "gf_find_ClusterPoints_ID_V4.m"
// "gf_find_ClusterPoints_ID_V5_forPRI.m" "gf_find_MaxFreqData_V1.m" 
//

#ifndef __MatlabArithmetic_h
#define __MatlabArithmetic_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_MatlabArithmetic
#define PUBLIC_MatlabArithmetic_C_API __global
#else
#define PUBLIC_MatlabArithmetic_C_API /* No import statement needed. */
#endif

#define LIB_MatlabArithmetic_C_API PUBLIC_MatlabArithmetic_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_MatlabArithmetic
#define PUBLIC_MatlabArithmetic_C_API __declspec(dllexport)
#else
#define PUBLIC_MatlabArithmetic_C_API __declspec(dllimport)
#endif

#define LIB_MatlabArithmetic_C_API PUBLIC_MatlabArithmetic_C_API


#else

#define LIB_MatlabArithmetic_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_MatlabArithmetic_C_API 
#define LIB_MatlabArithmetic_C_API /* No special import/export declaration */
#endif

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV MatlabArithmeticInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV MatlabArithmeticInitialize(void);

extern LIB_MatlabArithmetic_C_API 
void MW_CALL_CONV MatlabArithmeticTerminate(void);



extern LIB_MatlabArithmetic_C_API 
void MW_CALL_CONV MatlabArithmeticPrintStackTrace(void);

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV mlxGf_allpulses_Cal_Para_V1(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[]);

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV mlxGf_DataBase_Indentity_v1(int nlhs, mxArray *plhs[], int nrhs, 
                                              mxArray *prhs[]);

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV mlxGf_CPIValidTableSetForOneFile_to_CSV_V1(int nlhs, mxArray *plhs[], 
                                                             int nrhs, mxArray *prhs[]);

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV mlxGf_datenum_to_datestr(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[]);

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV mlxGf_find_ClusterPoints_ID_V4(int nlhs, mxArray *plhs[], int nrhs, 
                                                 mxArray *prhs[]);

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV mlxGf_find_ClusterPoints_ID_V5_forPRI(int nlhs, mxArray *plhs[], int 
                                                        nrhs, mxArray *prhs[]);

extern LIB_MatlabArithmetic_C_API 
bool MW_CALL_CONV mlxGf_find_MaxFreqData_V1(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                            *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_MatlabArithmetic
#define PUBLIC_MatlabArithmetic_CPP_API __declspec(dllexport)
#else
#define PUBLIC_MatlabArithmetic_CPP_API __declspec(dllimport)
#endif

#define LIB_MatlabArithmetic_CPP_API PUBLIC_MatlabArithmetic_CPP_API

#else

#if !defined(LIB_MatlabArithmetic_CPP_API)
#if defined(LIB_MatlabArithmetic_C_API)
#define LIB_MatlabArithmetic_CPP_API LIB_MatlabArithmetic_C_API
#else
#define LIB_MatlabArithmetic_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_MatlabArithmetic_CPP_API void MW_CALL_CONV gf_allpulses_Cal_Para_V1(const mwArray& infile, const mwArray& outfilepath, const mwArray& outfilename);

extern LIB_MatlabArithmetic_CPP_API void MW_CALL_CONV gf_DataBase_Indentity_v1(int nargout, mwArray& CPIValidTableSetForOneFile, const mwArray& CPIValidTableSetForOneFile_in1);

extern LIB_MatlabArithmetic_CPP_API void MW_CALL_CONV gf_CPIValidTableSetForOneFile_to_CSV_V1(const mwArray& CPIValidTableSetForOneFile, const mwArray& outfilepath, const mwArray& outfilename);

extern LIB_MatlabArithmetic_CPP_API void MW_CALL_CONV gf_datenum_to_datestr(int nargout, mwArray& dates, const mwArray& daten);

extern LIB_MatlabArithmetic_CPP_API void MW_CALL_CONV gf_find_ClusterPoints_ID_V4(int nargout, mwArray& RFS, mwArray& RfID, const mwArray& RfA, const mwArray& rferror, const mwArray& rfnum, const mwArray& rfRange);

extern LIB_MatlabArithmetic_CPP_API void MW_CALL_CONV gf_find_ClusterPoints_ID_V5_forPRI(int nargout, mwArray& RFS, mwArray& RfID, const mwArray& Rf, const mwArray& rferror, const mwArray& rfnum, const mwArray& rfRange);

extern LIB_MatlabArithmetic_CPP_API void MW_CALL_CONV gf_find_MaxFreqData_V1(int nargout, mwArray& mfd, mwArray& percent, const mwArray& temp, const mwArray& dotnum);

#endif
#endif
