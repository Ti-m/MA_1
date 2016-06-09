#ifndef __c7_Basic_DMT_h__
#define __c7_Basic_DMT_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_Basic_DMTInstanceStruct
#define typedef_SFc7_Basic_DMTInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_Basic_DMT;
  real_T *c7_ber_r_address;
  int32_T c7_ber_r_index;
  real_T *c7_error_r_address;
  int32_T c7_error_r_index;
  real_T *c7_sent_r_address;
  int32_T c7_sent_r_index;
  uint8_T *c7_sent;
  real_T *c7_sent_out;
  real_T *c7_error;
  uint8_T *c7_recv;
  real_T *c7_ber;
  real_T *c7_rst;
} SFc7_Basic_DMTInstanceStruct;

#endif                                 /*typedef_SFc7_Basic_DMTInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_Basic_DMT_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_Basic_DMT_get_check_sum(mxArray *plhs[]);
extern void c7_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
