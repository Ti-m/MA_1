#ifndef __c14_Basic_DMT_h__
#define __c14_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc14_Basic_DMTInstanceStruct
#define typedef_SFc14_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c14_sfEvent;
  boolean_T c14_isStable;
  boolean_T c14_doneDoubleBufferReInit;
  uint8_T c14_is_active_c14_Basic_DMT;
  real_T c14_GI_Active;
  real_T c14_fftLenActive;
  int16_T *c14_convert_address;
  int32_T c14_convert_index;
  real_T *c14_loopCount_address;
  int32_T c14_loopCount_index;
  real_T *c14_start_address;
  int32_T c14_start_index;
  real_T *c14_state_address;
  int32_T c14_state_index;
  cint16_T *c14_inp;
  cint16_T *c14_out;
  real_T *c14_pop;
  real_T *c14_frameEn;
} SFc14_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc14_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c14_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c14_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c14_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
