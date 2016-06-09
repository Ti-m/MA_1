#ifndef __c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_h__
#define __c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlibInstanceStruct
#define typedef_SFc5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c5_YReYssZ4nohWJHGDbcUR4F_is_active_c5_YReYssZ4nohWJHGDbcUR4F_hd;
  uint8_T *c5_YReYssZ4nohWJHGDbcUR4F_u1;
  uint8_T *c5_YReYssZ4nohWJHGDbcUR4F_y;
  boolean_T *c5_YReYssZ4nohWJHGDbcUR4F_u2;
} SFc5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlibInstanceStruct;

#endif                                 /*typedef_SFc5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_get_check_sum(mxArray
  *plhs[]);
extern void c5_YReYssZ4nohWJHGDbcUR4F_hdlmdlgenlib_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
