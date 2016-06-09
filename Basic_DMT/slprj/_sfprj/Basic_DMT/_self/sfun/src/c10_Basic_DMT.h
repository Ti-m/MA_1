#ifndef __c10_Basic_DMT_h__
#define __c10_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc10_Basic_DMTInstanceStruct
#define typedef_SFc10_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  boolean_T c10_isStable;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_Basic_DMT;
  int16_T *c10_convert_address;
  int32_T c10_convert_index;
  real_T *c10_state_address;
  int32_T c10_state_index;
  cint16_T *c10_inp;
  cint16_T *c10_i1;
  cint16_T *c10_out;
  cint16_T *c10_o1;
  cint16_T *c10_o2;
  cint16_T *c10_o3;
  cint16_T *c10_o4;
  cint16_T *c10_o5;
  cint16_T *c10_o6;
  cint16_T *c10_o7;
  cint16_T *c10_o8;
  cint16_T *c10_o9;
  cint16_T *c10_o10;
  cint16_T *c10_o11;
  cint16_T *c10_o12;
  cint16_T *c10_o13;
  cint16_T *c10_o14;
  cint16_T *c10_o15;
  cint16_T *c10_o16;
  cint16_T *c10_o17;
  cint16_T *c10_o18;
  cint16_T *c10_o19;
  cint16_T *c10_o20;
  cint16_T *c10_o21;
  cint16_T *c10_o22;
  cint16_T *c10_o23;
  cint16_T *c10_o24;
  cint16_T *c10_o25;
  cint16_T *c10_o26;
  cint16_T *c10_o27;
  cint16_T *c10_o28;
  cint16_T *c10_o29;
  cint16_T *c10_o30;
  cint16_T *c10_o31;
  cint16_T *c10_o32;
  real_T *c10_pop;
  cint16_T *c10_i2;
  cint16_T *c10_i3;
  cint16_T *c10_i4;
  cint16_T *c10_i5;
  cint16_T *c10_i6;
  cint16_T *c10_i7;
  cint16_T *c10_i8;
  cint16_T *c10_i9;
  cint16_T *c10_i10;
  cint16_T *c10_i11;
  cint16_T *c10_i12;
  cint16_T *c10_i13;
  cint16_T *c10_i14;
  cint16_T *c10_i15;
  cint16_T *c10_i16;
  cint16_T *c10_i17;
  cint16_T *c10_i18;
  cint16_T *c10_i19;
  cint16_T *c10_i20;
  cint16_T *c10_i21;
  cint16_T *c10_i22;
  cint16_T *c10_i23;
  cint16_T *c10_i24;
  cint16_T *c10_i25;
  cint16_T *c10_i26;
  cint16_T *c10_i27;
  cint16_T *c10_i28;
  cint16_T *c10_i29;
  cint16_T *c10_i30;
  cint16_T *c10_i31;
  cint16_T *c10_i32;
  real_T *c10_frameEN;
} SFc10_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc10_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c10_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c10_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
