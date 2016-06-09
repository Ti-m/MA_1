#ifndef __c5_Basic_DMT_h__
#define __c5_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_Basic_DMTInstanceStruct
#define typedef_SFc5_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_Basic_DMT;
  int16_T *c5_convert_address;
  int32_T c5_convert_index;
  real_T *c5_state_address;
  int32_T c5_state_index;
  cint16_T *c5_inp;
  cint16_T *c5_i1;
  cint16_T *c5_out;
  cint16_T *c5_o1;
  cint16_T *c5_o2;
  cint16_T *c5_o3;
  cint16_T *c5_o4;
  cint16_T *c5_o5;
  cint16_T *c5_o6;
  cint16_T *c5_o7;
  cint16_T *c5_o8;
  cint16_T *c5_o9;
  cint16_T *c5_o10;
  cint16_T *c5_o11;
  cint16_T *c5_o12;
  cint16_T *c5_o13;
  cint16_T *c5_o14;
  cint16_T *c5_o15;
  cint16_T *c5_o16;
  real_T *c5_pop;
  cint16_T *c5_i2;
  cint16_T *c5_i3;
  cint16_T *c5_i4;
  cint16_T *c5_i5;
  cint16_T *c5_i6;
  cint16_T *c5_i7;
  cint16_T *c5_i8;
  cint16_T *c5_i9;
  cint16_T *c5_i10;
  cint16_T *c5_i11;
  cint16_T *c5_i12;
  cint16_T *c5_i13;
  cint16_T *c5_i14;
  cint16_T *c5_i15;
  cint16_T *c5_i16;
  boolean_T *c5_frameEN;
} SFc5_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc5_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c5_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
