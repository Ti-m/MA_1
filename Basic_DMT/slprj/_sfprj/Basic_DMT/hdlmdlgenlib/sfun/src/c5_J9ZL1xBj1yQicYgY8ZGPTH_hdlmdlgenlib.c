/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hdlmdlgenlib_sfun.h"
#include "c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_eml_mx;
static const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_eml_mx;

/* Function Declarations */
static void initialize_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void initialize_params_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void enable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void disable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void set_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_st);
static void finalize_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void sf_gateway_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void mdl_start_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void initSimStructsc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T
  c5_J9ZL1xBj1yQicYgY8ZGPTH_machineNumber, uint32_T
  c5_J9ZL1xBj1yQicYgY8ZGPTH_chartNumber, uint32_T
  c5_J9ZL1xBj1yQicYgY8ZGPTH_instanceNumber);
static void c5_J9ZL1xBj1yQicYgY8ZGPTH_info_helper(const mxArray
  **c5_J9ZL1xBj1yQicYgY8ZGPTH_info);
static const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(const char
  * c5_J9ZL1xBj1yQicYgY8ZGPTH_u);
static const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(const
  uint32_T c5_J9ZL1xBj1yQicYgY8ZGPTH_u);
static uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallIn
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y, const char_T
   *c5_J9ZL1xBj1yQicYgY8ZGPTH_identifier);
static uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallIn
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_u, const emlrtMsgIdentifier
   *c5_J9ZL1xBj1yQicYgY8ZGPTH_parentId);
static uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_c_emlrt_marshallIn
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_,
   const char_T *c5_J9ZL1xBj1yQicYgY8ZGPTH_identifier);
static uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_d_emlrt_marshallIn
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_u, const emlrtMsgIdentifier
   *c5_J9ZL1xBj1yQicYgY8ZGPTH_parentId);
static void init_dsm_address_info
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_hd
    = 0U;
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_b_eml_mx, sf_mex_call("numerictype",
    1U, 14U, 15, "SignednessBool", 3, false, 15, "Signedness", 15, "Unsigned",
    15, "WordLength", 6, 3.0, 15, "FractionLength", 6, 0.0, 15, "BinaryPoint", 6,
    0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0), true);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_eml_mx, sf_mex_call("fimath", 1U, 42U,
    15, "RoundMode", 15, "nearest", 15, "RoundingMethod", 15, "Nearest", 15,
    "OverflowMode", 15, "saturate", 15, "OverflowAction", 15, "Saturate", 15,
    "ProductMode", 15, "FullPrecision", 15, "ProductWordLength", 6, 32.0, 15,
    "MaxProductWordLength", 6, 65535.0, 15, "ProductFractionLength", 6, 30.0, 15,
    "ProductFixedExponent", 6, -30.0, 15, "ProductSlope", 6,
    9.3132257461547852E-10, 15, "ProductSlopeAdjustmentFactor", 6, 1.0, 15,
    "ProductBias", 6, 0.0, 15, "SumMode", 15, "FullPrecision", 15,
    "SumWordLength", 6, 32.0, 15, "MaxSumWordLength", 6, 65535.0, 15,
    "SumFractionLength", 6, 30.0, 15, "SumFixedExponent", 6, -30.0, 15,
    "SumSlope", 6, 9.3132257461547852E-10, 15, "SumSlopeAdjustmentFactor", 6,
    1.0, 15, "SumBias", 6, 0.0, 15, "CastBeforeSum", 3, true), true);
}

static void initialize_params_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static const mxArray *get_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_st;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_c_y = NULL;
  uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_u;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_d_y = NULL;
  uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_b_u;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_e_y = NULL;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_st = NULL;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = NULL;
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y, sf_mex_createcellmatrix(2, 1),
                false);
  c5_J9ZL1xBj1yQicYgY8ZGPTH_c_y = NULL;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_u = *chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_y;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_d_y = NULL;
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_d_y, sf_mex_create("y",
    &c5_J9ZL1xBj1yQicYgY8ZGPTH_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_c_y, sf_mex_call("fi", 1U, 8U, 15,
    "fimath", 14, sf_mex_dup(c5_J9ZL1xBj1yQicYgY8ZGPTH_eml_mx), 15,
    "numerictype", 14, sf_mex_dup(c5_J9ZL1xBj1yQicYgY8ZGPTH_b_eml_mx), 15,
    "simulinkarray", 14, c5_J9ZL1xBj1yQicYgY8ZGPTH_d_y, 15, "fimathislocal", 3,
    true), false);
  sf_mex_setcell(c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y, 0, c5_J9ZL1xBj1yQicYgY8ZGPTH_c_y);
  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_u =
    chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_hd;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_e_y = NULL;
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_e_y, sf_mex_create("y",
    &c5_J9ZL1xBj1yQicYgY8ZGPTH_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y, 1, c5_J9ZL1xBj1yQicYgY8ZGPTH_e_y);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_st, c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y,
                false);
  return c5_J9ZL1xBj1yQicYgY8ZGPTH_st;
}

static void set_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_st)
{
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_u;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_u = sf_mex_dup(c5_J9ZL1xBj1yQicYgY8ZGPTH_st);
  *chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_y =
    c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_J9ZL1xBj1yQicYgY8ZGPTH_u, 0)), "y");
  chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_hd
    = c5_J9ZL1xBj1yQicYgY8ZGPTH_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_J9ZL1xBj1yQicYgY8ZGPTH_u, 1)),
    "is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib");
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_u);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_st);
}

static void finalize_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  (void)chartInstance;
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_eml_mx);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_b_eml_mx);
}

static void sf_gateway_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  int32_T c5_J9ZL1xBj1yQicYgY8ZGPTH_i0;
  _sfTime_ = sf_get_time(chartInstance->S);
  if (*chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_u2) {
    c5_J9ZL1xBj1yQicYgY8ZGPTH_i0 = 1;
  } else {
    c5_J9ZL1xBj1yQicYgY8ZGPTH_i0 = 0;
  }

  *chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_y = (uint8_T)
    ((((*chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_u1 & 7) << 1 & 7) |
      c5_J9ZL1xBj1yQicYgY8ZGPTH_i0) & 7);
}

static void mdl_start_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T
  c5_J9ZL1xBj1yQicYgY8ZGPTH_machineNumber, uint32_T
  c5_J9ZL1xBj1yQicYgY8ZGPTH_chartNumber, uint32_T
  c5_J9ZL1xBj1yQicYgY8ZGPTH_instanceNumber)
{
  (void)c5_J9ZL1xBj1yQicYgY8ZGPTH_machineNumber;
  (void)c5_J9ZL1xBj1yQicYgY8ZGPTH_chartNumber;
  (void)c5_J9ZL1xBj1yQicYgY8ZGPTH_instanceNumber;
}

const mxArray
  *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_nameCaptureInfo = NULL;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_nameCaptureInfo, sf_mex_createstruct(
    "structure", 2, 18, 1), false);
  c5_J9ZL1xBj1yQicYgY8ZGPTH_info_helper
    (&c5_J9ZL1xBj1yQicYgY8ZGPTH_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a
    (&c5_J9ZL1xBj1yQicYgY8ZGPTH_nameCaptureInfo);
  return c5_J9ZL1xBj1yQicYgY8ZGPTH_nameCaptureInfo;
}

static void c5_J9ZL1xBj1yQicYgY8ZGPTH_info_helper(const mxArray
  **c5_J9ZL1xBj1yQicYgY8ZGPTH_info)
{
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs0 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs0 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs1 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs1 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs2 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs2 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs3 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs3 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs4 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs4 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs5 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs5 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs6 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs6 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs7 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs7 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs8 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs8 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs9 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs9 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs10 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs10 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs11 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs11 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs12 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs12 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs13 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs13 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs14 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs14 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs15 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs15 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs16 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs16 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs17 = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs17 = NULL;
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(""), "context",
                  "context", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("cast_to_fi"),
                  "name", "name", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/hdlcoder/hdllib/sl_lib/cast_to_fi.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1368183166U),
                  "fileTimeLo", "fileTimeLo", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 0);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs0, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs0, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(""), "context",
                  "context", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("cast_to_fi"),
                  "name", "name", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("logical"),
                  "dominantType", "dominantType", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/hdlcoder/hdllib/sl_lib/cast_to_fi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1368183166U),
                  "fileTimeLo", "fileTimeLo", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 1);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs1, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs1, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/hdlcoder/hdllib/sl_lib/cast_to_fi.m!convertBool2Ufix1"),
                  "context", "context", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("fi_impl"), "name",
                  "name", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(""),
                  "dominantType", "dominantType", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1386423952U),
                  "fileTimeLo", "fileTimeLo", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 2);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs2, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs2, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("isnumerictype"),
                  "name", "name", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1398875598U),
                  "fileTimeLo", "fileTimeLo", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 3);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs3, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs3, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper"),
                  "context", "context", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("length"), "name",
                  "name", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("cell"),
                  "dominantType", "dominantType", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1303146206U),
                  "fileTimeLo", "fileTimeLo", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 4);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs4, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs4, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper"),
                  "context", "context", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "eml_fi_checkforconst"), "name", "name", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforconst.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1346510352U),
                  "fileTimeLo", "fileTimeLo", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 5);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs5, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs5, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper"),
                  "context", "context", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("isfi"), "name",
                  "name", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("double"),
                  "dominantType", "dominantType", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1346510358U),
                  "fileTimeLo", "fileTimeLo", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 6);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs6, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs6, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("isnumerictype"),
                  "name", "name", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("char"),
                  "dominantType", "dominantType", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1398875598U),
                  "fileTimeLo", "fileTimeLo", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 7);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs7, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs7, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper"),
                  "context", "context", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "eml_fi_constructor_helper"), "name", "name", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(""),
                  "dominantType", "dominantType", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/fixedpoint/fixedpoint/eml_fi_constructor_helper.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1375980696U),
                  "fileTimeLo", "fileTimeLo", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 8);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs8, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs8, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper"),
                  "context", "context", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "eml_fi_checkforerror"), "name", "name", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "embedded.numerictype"), "dominantType", "dominantType", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforerror.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1360282346U),
                  "fileTimeLo", "fileTimeLo", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 9);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs9, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs9, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/hdlcoder/hdllib/sl_lib/cast_to_fi.m!convertBool2Ufix1"),
                  "context", "context", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("length"), "name",
                  "name", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("logical"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1303146206U),
                  "fileTimeLo", "fileTimeLo", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 10);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs10, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs10, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs10), "rhs", "rhs", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs10), "lhs", "lhs", 10);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(""), "context",
                  "context", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("bitconcat"),
                  "name", "name", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/bitconcat.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1402614496U),
                  "fileTimeLo", "fileTimeLo", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 11);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs11, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs11, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs11), "rhs", "rhs", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs11), "lhs", "lhs", 11);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/@embedded/@fi/bitconcat.m!bitconcat_checkarg"),
                  "context", "context", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("isfi"), "name",
                  "name", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1346510358U),
                  "fileTimeLo", "fileTimeLo", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 12);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs12, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs12, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs12), "rhs", "rhs", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs12), "lhs", "lhs", 12);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("isnumerictype"),
                  "name", "name", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "embedded.numerictype"), "dominantType", "dominantType", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1398875598U),
                  "fileTimeLo", "fileTimeLo", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 13);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs13, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs13, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs13), "rhs", "rhs", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs13), "lhs", "lhs", 13);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/@embedded/@fi/bitconcat.m!bitconcat_checkarg"),
                  "context", "context", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("isfixed"), "name",
                  "name", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1346510378U),
                  "fileTimeLo", "fileTimeLo", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 14);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs14, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs14, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs14), "rhs", "rhs", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs14), "lhs", "lhs", 14);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("get"), "name",
                  "name", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "embedded.numerictype"), "dominantType", "dominantType", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1378295982U),
                  "fileTimeLo", "fileTimeLo", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 15);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs15, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs15, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs15), "rhs", "rhs", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs15), "lhs", "lhs", 15);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/@embedded/@fi/bitconcat.m!bitconcat_checkarg"),
                  "context", "context", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "eml_isslopebiasscaled"), "name", "name", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_isslopebiasscaled.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1289519646U),
                  "fileTimeLo", "fileTimeLo", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 16);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs16, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs16, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs16), "rhs", "rhs", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs16), "lhs", "lhs", 16);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_isslopebiasscaled.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut("get"), "name",
                  "name", 17);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "embedded.numerictype"), "dominantType", "dominantType", 17);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(1378295982U),
                  "fileTimeLo", "fileTimeLo", 17);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "fileTimeHi", "fileTimeHi", 17);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeLo", "mFileTimeLo", 17);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(0U),
                  "mFileTimeHi", "mFileTimeHi", 17);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs17, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs17, sf_mex_createcellmatrix(0, 1),
                false);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs17), "rhs", "rhs", 17);
  sf_mex_addfield(*c5_J9ZL1xBj1yQicYgY8ZGPTH_info, sf_mex_duplicatearraysafe
                  (&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs17), "lhs", "lhs", 17);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs0);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs0);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs1);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs1);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs2);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs2);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs3);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs3);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs4);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs4);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs5);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs5);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs6);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs6);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs7);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs7);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs8);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs8);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs9);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs9);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs10);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs10);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs11);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs11);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs12);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs12);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs13);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs13);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs14);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs14);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs15);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs15);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs16);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs16);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_rhs17);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_lhs17);
}

static const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallOut(const char
  * c5_J9ZL1xBj1yQicYgY8ZGPTH_u)
{
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = NULL;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = NULL;
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y, sf_mex_create("y",
    c5_J9ZL1xBj1yQicYgY8ZGPTH_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_J9ZL1xBj1yQicYgY8ZGPTH_u)), false);
  return c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y;
}

static const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallOut(const
  uint32_T c5_J9ZL1xBj1yQicYgY8ZGPTH_u)
{
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = NULL;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = NULL;
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y, sf_mex_create("y",
    &c5_J9ZL1xBj1yQicYgY8ZGPTH_u, 7, 0U, 0U, 0U, 0), false);
  return c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y;
}

static uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_emlrt_marshallIn
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y, const char_T
   *c5_J9ZL1xBj1yQicYgY8ZGPTH_identifier)
{
  uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_c_y;
  emlrtMsgIdentifier c5_J9ZL1xBj1yQicYgY8ZGPTH_thisId;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_thisId.fIdentifier =
    c5_J9ZL1xBj1yQicYgY8ZGPTH_identifier;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_thisId.fParent = NULL;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_c_y = c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y),
     &c5_J9ZL1xBj1yQicYgY8ZGPTH_thisId);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y);
  return c5_J9ZL1xBj1yQicYgY8ZGPTH_c_y;
}

static uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_b_emlrt_marshallIn
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_u, const emlrtMsgIdentifier
   *c5_J9ZL1xBj1yQicYgY8ZGPTH_parentId)
{
  uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_mxFi = NULL;
  const mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_mxInt = NULL;
  uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_u0;
  (void)chartInstance;
  sf_mex_check_fi(c5_J9ZL1xBj1yQicYgY8ZGPTH_parentId,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_u, false, 0U, NULL,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_eml_mx,
                  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_eml_mx);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_mxFi, sf_mex_dup
                (c5_J9ZL1xBj1yQicYgY8ZGPTH_u), false);
  sf_mex_assign(&c5_J9ZL1xBj1yQicYgY8ZGPTH_mxInt, sf_mex_call("simulinkarray",
    1U, 1U, 14, sf_mex_dup(c5_J9ZL1xBj1yQicYgY8ZGPTH_mxFi)), false);
  sf_mex_import(c5_J9ZL1xBj1yQicYgY8ZGPTH_parentId, sf_mex_dup
                (c5_J9ZL1xBj1yQicYgY8ZGPTH_mxInt), &c5_J9ZL1xBj1yQicYgY8ZGPTH_u0,
                1, 3, 0U, 0, 0U, 0);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_mxFi);
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_mxInt);
  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = c5_J9ZL1xBj1yQicYgY8ZGPTH_u0;
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_u);
  return c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y;
}

static uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_c_emlrt_marshallIn
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_b_is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_,
   const char_T *c5_J9ZL1xBj1yQicYgY8ZGPTH_identifier)
{
  uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y;
  emlrtMsgIdentifier c5_J9ZL1xBj1yQicYgY8ZGPTH_thisId;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_thisId.fIdentifier =
    c5_J9ZL1xBj1yQicYgY8ZGPTH_identifier;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_thisId.fParent = NULL;
  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = c5_J9ZL1xBj1yQicYgY8ZGPTH_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup
     (c5_J9ZL1xBj1yQicYgY8ZGPTH_b_is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_),
     &c5_J9ZL1xBj1yQicYgY8ZGPTH_thisId);
  sf_mex_destroy
    (&c5_J9ZL1xBj1yQicYgY8ZGPTH_b_is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_);
  return c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y;
}

static uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_d_emlrt_marshallIn
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance, const
   mxArray *c5_J9ZL1xBj1yQicYgY8ZGPTH_u, const emlrtMsgIdentifier
   *c5_J9ZL1xBj1yQicYgY8ZGPTH_parentId)
{
  uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y;
  uint8_T c5_J9ZL1xBj1yQicYgY8ZGPTH_b_u1;
  (void)chartInstance;
  sf_mex_import(c5_J9ZL1xBj1yQicYgY8ZGPTH_parentId, sf_mex_dup
                (c5_J9ZL1xBj1yQicYgY8ZGPTH_u), &c5_J9ZL1xBj1yQicYgY8ZGPTH_b_u1,
                1, 3, 0U, 0, 0U, 0);
  c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y = c5_J9ZL1xBj1yQicYgY8ZGPTH_b_u1;
  sf_mex_destroy(&c5_J9ZL1xBj1yQicYgY8ZGPTH_u);
  return c5_J9ZL1xBj1yQicYgY8ZGPTH_b_y;
}

static void init_dsm_address_info
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance)
{
  chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_u1 = (uint8_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_y = (uint8_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c5_J9ZL1xBj1yQicYgY8ZGPTH_u2 = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4203782319U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2970176247U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2668166077U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4193192382U);
}

mxArray* sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_post_codegen_info(void);
mxArray *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yaJX5klncSD387p8cxFezG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(2));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(3));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray
  *sf_get_sim_state_info_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "J9ZL1xBj1yQicYgY8ZGPTH";
}

static void sf_opaque_initialize_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(void
  *chartInstanceVar)
{
  initialize_params_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
    ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*) chartInstanceVar);
  initialize_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
    ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(void
  *chartInstanceVar)
{
  enable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
    ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(void
  *chartInstanceVar)
{
  disable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
    ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(void
  *chartInstanceVar)
{
  sf_gateway_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
    ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*) chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
    ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
    ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hdlmdlgenlib_optimization_info();
    }

    finalize_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
      ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*)
       chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
    ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib
      ((SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hdlmdlgenlib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2811333836U));
  ssSetChecksum1(S,(1826100309U));
  ssSetChecksum2(S,(1793473652U));
  ssSetChecksum3(S,(154236476U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(SimStruct *S)
{
  SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct *)
    utMalloc(sizeof(SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
}

void c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_J9ZL1xBj1yQicYgY8ZGPTH_hdlmdlgenlib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
