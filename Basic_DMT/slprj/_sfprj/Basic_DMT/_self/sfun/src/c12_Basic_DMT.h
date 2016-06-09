#ifndef __c12_Basic_DMT_h__
#define __c12_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc12_Basic_DMTInstanceStruct
#define typedef_SFc12_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_isStable;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_Basic_DMT;
  real_T c12_u1;
  real_T c12_u2;
  real_T c12_u3;
  real_T c12_u4;
  real_T c12_u5;
  real_T c12_u6;
  real_T c12_u7;
  real_T c12_u8;
  real_T c12_u9;
  real_T c12_u10;
  real_T c12_u11;
  real_T c12_u12;
  real_T c12_u13;
  real_T c12_u14;
  real_T c12_u15;
  real_T c12_u16;
  cint16_T *c12_i1;
  cint16_T *c12_o1;
  cint16_T *c12_o2;
  cint16_T *c12_o3;
  cint16_T *c12_o4;
  cint16_T *c12_o5;
  cint16_T *c12_o6;
  cint16_T *c12_o7;
  cint16_T *c12_o8;
  cint16_T *c12_o9;
  cint16_T *c12_o10;
  cint16_T *c12_o11;
  cint16_T *c12_o12;
  cint16_T *c12_o13;
  cint16_T *c12_o14;
  cint16_T *c12_o15;
  cint16_T *c12_o16;
  cint16_T *c12_i2;
  cint16_T *c12_i3;
  cint16_T *c12_i4;
  cint16_T *c12_i5;
  cint16_T *c12_i6;
  cint16_T *c12_i7;
  cint16_T *c12_i8;
  cint16_T *c12_i9;
  cint16_T *c12_i10;
  cint16_T *c12_i11;
  cint16_T *c12_i12;
  cint16_T *c12_i13;
  cint16_T *c12_i14;
  cint16_T *c12_i15;
  cint16_T *c12_i16;
} SFc12_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc12_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c12_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
