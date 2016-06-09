#ifndef __c4_Basic_DMT_h__
#define __c4_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_Basic_DMTInstanceStruct
#define typedef_SFc4_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_Basic_DMT;
  real_T c4_chanDownFact;
  real_T *c4_loopCount_address;
  int32_T c4_loopCount_index;
  real_T *c4_popEn_address;
  int32_T c4_popEn_index;
  real_T *c4_state_address;
  int32_T c4_state_index;
  real_T *c4_push_en;
  real_T *c4_push;
  real_T *c4_pop;
} SFc4_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc4_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c4_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
