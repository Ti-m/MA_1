#ifndef __c9_Basic_DMT_h__
#define __c9_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_Basic_DMTInstanceStruct
#define typedef_SFc9_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_Basic_DMT;
  real_T c9_u1;
  real_T c9_u2;
  real_T c9_u3;
  real_T c9_u4;
  real_T c9_u5;
  real_T c9_u6;
  real_T c9_u7;
  real_T c9_u8;
  real_T c9_u9;
  real_T c9_u10;
  real_T c9_u11;
  real_T c9_u12;
  real_T c9_u13;
  real_T c9_u14;
  real_T c9_u15;
  real_T c9_u16;
  cint16_T *c9_i1;
  cint16_T *c9_o1;
  cint16_T *c9_o2;
  cint16_T *c9_o3;
  cint16_T *c9_o4;
  cint16_T *c9_o5;
  cint16_T *c9_o6;
  cint16_T *c9_o7;
  cint16_T *c9_o8;
  cint16_T *c9_o9;
  cint16_T *c9_o10;
  cint16_T *c9_o11;
  cint16_T *c9_o12;
  cint16_T *c9_o13;
  cint16_T *c9_o14;
  cint16_T *c9_o15;
  cint16_T *c9_o16;
  cint16_T *c9_i2;
  cint16_T *c9_i3;
  cint16_T *c9_i4;
  cint16_T *c9_i5;
  cint16_T *c9_i6;
  cint16_T *c9_i7;
  cint16_T *c9_i8;
  cint16_T *c9_i9;
  cint16_T *c9_i10;
  cint16_T *c9_i11;
  cint16_T *c9_i12;
  cint16_T *c9_i13;
  cint16_T *c9_i14;
  cint16_T *c9_i15;
  cint16_T *c9_i16;
} SFc9_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc9_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c9_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
