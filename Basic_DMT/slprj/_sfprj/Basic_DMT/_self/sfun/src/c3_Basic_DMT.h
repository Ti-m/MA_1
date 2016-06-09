#ifndef __c3_Basic_DMT_h__
#define __c3_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_Basic_DMTInstanceStruct
#define typedef_SFc3_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_Basic_DMT;
  real_T c3_usedSubCar;
  real_T c3_bitPerSymb;
  real_T c3_fftLen;
  real_T c3_freqDivSubcAlloc;
  real_T c3_bitsPerFrame;
  real_T c3_u1;
  real_T c3_u2;
  real_T c3_u3;
  real_T c3_u4;
  real_T c3_u5;
  real_T c3_u6;
  real_T c3_u7;
  real_T c3_u8;
  real_T c3_u9;
  real_T c3_u10;
  real_T c3_u11;
  real_T c3_u12;
  real_T c3_u13;
  real_T c3_u14;
  real_T c3_u15;
  real_T c3_u16;
  real_T *c3_bitCount_address;
  int32_T c3_bitCount_index;
  real_T *c3_loopCount_address;
  int32_T c3_loopCount_index;
  real_T *c3_start_address;
  int32_T c3_start_index;
  real_T *c3_state_address;
  int32_T c3_state_index;
  real_T *c3_subCar_address;
  int32_T c3_subCar_index;
  real_T *c3_subCarCount_address;
  int32_T c3_subCarCount_index;
  uint32_T *c3_num;
  real_T *c3_frameEn;
  real_T *c3_sel;
  real_T *c3_push;
  real_T *c3_pop;
  real_T *c3_frameStart;
} SFc3_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc3_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c3_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
