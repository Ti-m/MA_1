#ifndef __c16_Basic_DMT_h__
#define __c16_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc16_Basic_DMTInstanceStruct
#define typedef_SFc16_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c16_sfEvent;
  boolean_T c16_isStable;
  boolean_T c16_doneDoubleBufferReInit;
  uint8_T c16_is_active_c16_Basic_DMT;
  real_T c16_fftLen;
  real_T c16_GI_Active;
  real_T c16_bitPerSymb;
  real_T c16_Tb;
  real_T c16_SystemPeriod;
  real_T c16_u1;
  real_T c16_u2;
  real_T c16_u3;
  real_T c16_u4;
  real_T c16_u5;
  real_T c16_u6;
  real_T c16_u7;
  real_T c16_u8;
  real_T c16_u9;
  real_T c16_u10;
  real_T c16_u11;
  real_T c16_u12;
  real_T c16_u13;
  real_T c16_u14;
  real_T c16_u15;
  real_T c16_u16;
  real_T *c16_enable_address;
  int32_T c16_enable_index;
  real_T *c16_loopCount_address;
  int32_T c16_loopCount_index;
  real_T *c16_start_address;
  int32_T c16_start_index;
  real_T *c16_state_address;
  int32_T c16_state_index;
  real_T *c16_subCar_address;
  int32_T c16_subCar_index;
  real_T *c16_subCarCount_address;
  int32_T c16_subCarCount_index;
  real_T *c16_frameEn;
  real_T *c16_push;
  real_T *c16_pop;
} SFc16_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc16_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c16_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c16_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
