#ifndef __c13_Basic_DMT_h__
#define __c13_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_Basic_DMTInstanceStruct
#define typedef_SFc13_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_Basic_DMT;
  real_T c13_fftLenActive;
  real_T c13_GI_Active;
  real_T c13_chanDownFact;
  real_T c13_bitPerSymb;
  real_T *c13_loopCount_address;
  int32_T c13_loopCount_index;
  real_T *c13_loopOut_address;
  int32_T c13_loopOut_index;
  real_T *c13_outputBitCount_address;
  int32_T c13_outputBitCount_index;
  real_T *c13_start_address;
  int32_T c13_start_index;
  real_T *c13_state_address;
  int32_T c13_state_index;
  uint32_T *c13_num;
  real_T *c13_frameEn;
  real_T *c13_sel;
  real_T *c13_push;
  real_T *c13_pop;
  real_T *c13_frameStart;
} SFc13_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc13_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c13_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
