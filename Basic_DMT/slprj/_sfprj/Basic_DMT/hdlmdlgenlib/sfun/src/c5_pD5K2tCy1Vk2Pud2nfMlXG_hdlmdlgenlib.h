#ifndef __c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_h__
#define __c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlibInstanceStruct
#define typedef_SFc5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c5_pD5K2tCy1Vk2Pud2nfMlXG_is_active_c5_pD5K2tCy1Vk2Pud2nfMlXG_hd;
  boolean_T *c5_pD5K2tCy1Vk2Pud2nfMlXG_u1;
  uint8_T *c5_pD5K2tCy1Vk2Pud2nfMlXG_y;
  boolean_T *c5_pD5K2tCy1Vk2Pud2nfMlXG_u2;
} SFc5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlibInstanceStruct;

#endif                                 /*typedef_SFc5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_get_check_sum(mxArray
  *plhs[]);
extern void c5_pD5K2tCy1Vk2Pud2nfMlXG_hdlmdlgenlib_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
