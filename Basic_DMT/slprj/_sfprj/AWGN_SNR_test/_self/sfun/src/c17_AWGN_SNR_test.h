#ifndef __c17_AWGN_SNR_test_h__
#define __c17_AWGN_SNR_test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc17_AWGN_SNR_testInstanceStruct
#define typedef_SFc17_AWGN_SNR_testInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  boolean_T c17_isStable;
  boolean_T c17_doneDoubleBufferReInit;
  uint8_T c17_is_active_c17_AWGN_SNR_test;
  real_T *c17_ber_r_address;
  int32_T c17_ber_r_index;
  real_T *c17_error_r_address;
  int32_T c17_error_r_index;
  real_T *c17_send_r_address;
  int32_T c17_send_r_index;
  boolean_T *c17_send;
  real_T *c17_send_out;
  real_T *c17_error;
  boolean_T *c17_recv;
  real_T *c17_ber;
  real_T *c17_rst;
} SFc17_AWGN_SNR_testInstanceStruct;

#endif                                 /*typedef_SFc17_AWGN_SNR_testInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_AWGN_SNR_test_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_AWGN_SNR_test_get_check_sum(mxArray *plhs[]);
extern void c17_AWGN_SNR_test_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
