#ifndef __c17_Basic_DMT_h__
#define __c17_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc17_Basic_DMTInstanceStruct
#define typedef_SFc17_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  boolean_T c17_isStable;
  boolean_T c17_doneDoubleBufferReInit;
  uint8_T c17_is_active_c17_Basic_DMT;
  real_T *c17_ber_r_address;
  int32_T c17_ber_r_index;
  real_T *c17_error_r_address;
  int32_T c17_error_r_index;
  real_T *c17_sent_r_address;
  int32_T c17_sent_r_index;
  uint8_T *c17_sent;
  real_T *c17_sent_out;
  real_T *c17_error;
  boolean_T *c17_recv;
  real_T *c17_ber;
  real_T *c17_rst;
} SFc17_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc17_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c17_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
