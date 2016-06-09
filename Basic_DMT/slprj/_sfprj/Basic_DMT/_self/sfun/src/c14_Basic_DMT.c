/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c14_Basic_DMT.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Basic_DMT_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c14_debug_family_names[8] = { "nargin", "nargout", "inp",
  "frameEn", "GI_Active", "fftLenActive", "out", "pop" };

static const mxArray *c14_eml_mx;
static const mxArray *c14_b_eml_mx;

/* Function Declarations */
static void initialize_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance);
static void initialize_params_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *chartInstance);
static void disable_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *chartInstance);
static void c14_update_debugger_state_c14_Basic_DMT
  (SFc14_Basic_DMTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *
  chartInstance);
static void set_sim_state_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_st);
static void finalize_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance);
static void mdl_start_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *chartInstance);
static void c14_chartstep_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance);
static void initSimStructsc14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c14_b_pop, const char_T *c14_identifier);
static real_T c14_b_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static cint16_T c14_c_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_info_helper(const mxArray **c14_info);
static const mxArray *c14_emlrt_marshallOut(const char * c14_u);
static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u);
static void c14_strcmpi(SFc14_Basic_DMTInstanceStruct *chartInstance);
static void c14_eml_scalar_eg(SFc14_Basic_DMTInstanceStruct *chartInstance);
static cint16_T c14_mtimes(SFc14_Basic_DMTInstanceStruct *chartInstance, int16_T
  c14_b0);
static void c14_b_strcmpi(SFc14_Basic_DMTInstanceStruct *chartInstance);
static cint16_T c14_plus(SFc14_Basic_DMTInstanceStruct *chartInstance, real_T
  c14_a0, cint16_T c14_b0);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_d_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static cint16_T c14_e_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_b_out, const char_T *c14_identifier);
static cint16_T c14_f_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int16_T c14_g_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_h_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_Basic_DMT, const char_T
  *c14_identifier);
static uint8_T c14_i_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static int16_T c14_get_convert(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex);
static void c14_set_convert(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex, int16_T c14_elementValue);
static int16_T *c14_access_convert(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_rdOnly);
static real_T c14_get_loopCount(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex);
static void c14_set_loopCount(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex, real_T c14_elementValue);
static real_T *c14_access_loopCount(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_rdOnly);
static real_T c14_get_start(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex);
static void c14_set_start(SFc14_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c14_elementIndex, real_T c14_elementValue);
static real_T *c14_access_start(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_rdOnly);
static real_T c14_get_state(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex);
static void c14_set_state(SFc14_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c14_elementIndex, real_T c14_elementValue);
static real_T *c14_access_state(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_rdOnly);
static void init_dsm_address_info(SFc14_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc14_Basic_DMTInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_is_active_c14_Basic_DMT = 0U;
  sf_mex_assign(&c14_b_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 10U, 15, "WordLength", 6, 9.0, 15, "FractionLength", 6,
    3.0, 15, "BinaryPoint", 6, 3.0, 15, "Slope", 6, 0.125, 15, "FixedExponent",
    6, -3.0), true);
  sf_mex_assign(&c14_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "fimath", 1U, 42U, 15, "RoundMode", 15, "nearest", 15, "RoundingMethod", 15,
    "Nearest", 15, "OverflowMode", 15, "saturate", 15, "OverflowAction", 15,
    "Saturate", 15, "ProductMode", 15, "SpecifyPrecision", 15,
    "ProductWordLength", 6, 9.0, 15, "MaxProductWordLength", 6, 65535.0, 15,
    "ProductFractionLength", 6, 3.0, 15, "ProductFixedExponent", 6, -3.0, 15,
    "ProductSlope", 6, 0.125, 15, "ProductSlopeAdjustmentFactor", 6, 1.0, 15,
    "ProductBias", 6, 0.0, 15, "SumMode", 15, "SpecifyPrecision", 15,
    "SumWordLength", 6, 9.0, 15, "MaxSumWordLength", 6, 65535.0, 15,
    "SumFractionLength", 6, 3.0, 15, "SumFixedExponent", 6, -3.0, 15, "SumSlope",
    6, 0.125, 15, "SumSlopeAdjustmentFactor", 6, 1.0, 15, "SumBias", 6, 0.0, 15,
    "CastBeforeSum", 3, true), true);
}

static void initialize_params_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c14_d0;
  real_T c14_d1;
  sf_mex_import_named("GI_Active", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c14_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c14_GI_Active = c14_d0;
  sf_mex_import_named("fftLenActive", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c14_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c14_fftLenActive = c14_d1;
}

static void enable_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c14_update_debugger_state_c14_Basic_DMT
  (SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *
  chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  const mxArray *c14_b_y = NULL;
  cint16_T c14_u;
  const mxArray *c14_c_y = NULL;
  real_T c14_hoistedGlobal;
  real_T c14_b_u;
  const mxArray *c14_d_y = NULL;
  uint8_T c14_b_hoistedGlobal;
  uint8_T c14_c_u;
  const mxArray *c14_e_y = NULL;
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellmatrix(3, 1), false);
  c14_b_y = NULL;
  c14_u.re = chartInstance->c14_out->re;
  c14_u.im = chartInstance->c14_out->im;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c14_eml_mx), 15, "numerictype", 14, sf_mex_dup(c14_b_eml_mx),
    15, "simulinkarray", 14, c14_c_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_hoistedGlobal = *chartInstance->c14_pop;
  c14_b_u = c14_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 1, c14_d_y);
  c14_b_hoistedGlobal = chartInstance->c14_is_active_c14_Basic_DMT;
  c14_c_u = c14_b_hoistedGlobal;
  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 2, c14_e_y);
  sf_mex_assign(&c14_st, c14_y, false);
  return c14_st;
}

static void set_sim_state_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  chartInstance->c14_doneDoubleBufferReInit = true;
  c14_u = sf_mex_dup(c14_st);
  *chartInstance->c14_out = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 0)), "out");
  *chartInstance->c14_pop = c14_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 1)), "pop");
  chartInstance->c14_is_active_c14_Basic_DMT = c14_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 2)),
     "is_active_c14_Basic_DMT");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_Basic_DMT(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
  sf_mex_destroy(&c14_eml_mx);
  sf_mex_destroy(&c14_b_eml_mx);
}

static void sf_gateway_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c14_sfEvent);
  chartInstance->c14_sfEvent = CALL_EVENT;
  c14_chartstep_c14_Basic_DMT(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c14_pop, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c14_frameEn, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c14_GI_Active, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c14_fftLenActive, 8U);
}

static void mdl_start_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c14_chartstep_c14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c14_hoistedGlobal;
  real_T c14_b_hoistedGlobal;
  real_T c14_c_hoistedGlobal;
  cint16_T c14_b_inp;
  real_T c14_b_frameEn;
  real_T c14_b_GI_Active;
  real_T c14_b_fftLenActive;
  uint32_T c14_debug_family_var_map[8];
  real_T c14_nargin = 4.0;
  real_T c14_nargout = 2.0;
  cint16_T c14_b_out;
  real_T c14_b_pop;
  cint16_T c14_ic0;
  cint16_T c14_ic1;
  int16_T c14_d_hoistedGlobal;
  cint16_T c14_a;
  int16_T c14_b0;
  int16_T c14_b_b0;
  int16_T c14_b;
  int16_T c14_b_b;
  int16_T c14_ar;
  int16_T c14_ai;
  int32_T c14_i0;
  int32_T c14_i1;
  int16_T c14_cr;
  int32_T c14_i2;
  int32_T c14_i3;
  int16_T c14_ci;
  const mxArray *c14_errID = NULL;
  const mxArray *c14_a2SD = NULL;
  const mxArray *c14_b2SD = NULL;
  const mxArray *c14_Tsd = NULL;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c14_sfEvent);
  c14_hoistedGlobal = *chartInstance->c14_frameEn;
  c14_b_hoistedGlobal = chartInstance->c14_GI_Active;
  c14_c_hoistedGlobal = chartInstance->c14_fftLenActive;
  c14_b_inp = *chartInstance->c14_inp;
  c14_b_frameEn = c14_hoistedGlobal;
  c14_b_GI_Active = c14_b_hoistedGlobal;
  c14_b_fftLenActive = c14_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 0U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 1U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_b_inp, 2U, c14_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_b_frameEn, 3U, c14_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_GI_Active, 4U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_fftLenActive, 5U,
    c14_sf_marshallOut, c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_out, 6U, c14_b_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_pop, 7U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 8);
  c14_b_pop = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 9);
  c14_ic0 = c14_mtimes(chartInstance, c14_get_convert(chartInstance, 0));
  c14_b_out = c14_plus(chartInstance, 0.0, c14_ic0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 11);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c14_b_frameEn, 1.0, -1,
        0U, c14_b_frameEn == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 12);
    c14_set_loopCount(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 13);
    c14_set_start(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 16);
  c14_set_loopCount(chartInstance, 0, c14_get_loopCount(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 18);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c14_get_loopCount
        (chartInstance, 0), c14_b_GI_Active + c14_b_fftLenActive, -1, 4U,
        c14_get_loopCount(chartInstance, 0) > c14_b_GI_Active +
        c14_b_fftLenActive))) {
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 19);
    c14_set_start(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 22);
  switch ((int32_T)_SFD_INTEGER_CHECK("state", c14_get_state(chartInstance, 0)))
  {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 24);
    c14_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 25);
    c14_ic1 = c14_mtimes(chartInstance, c14_get_convert(chartInstance, 0));
    c14_b_out = c14_plus(chartInstance, 0.0, c14_ic1);
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 26);
    guard2 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 2, c14_get_loopCount
          (chartInstance, 0), c14_b_GI_Active, -1, 4U, c14_get_loopCount
          (chartInstance, 0) > c14_b_GI_Active))) {
      if (CV_EML_COND(0, 1, 1, c14_get_start(chartInstance, 0) != 0.0)) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 2, true);
        _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 27);
        c14_set_state(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 3);
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 2, false);
      _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 29);
      c14_set_state(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    }
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 33);
    c14_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 34);
    c14_d_hoistedGlobal = c14_get_convert(chartInstance, 0);
    c14_a = c14_b_inp;
    c14_b0 = c14_d_hoistedGlobal;
    c14_b_b0 = c14_b0;
    c14_b = c14_b_b0;
    c14_b_strcmpi(chartInstance);
    c14_b_b = c14_b;
    c14_ar = c14_a.re;
    c14_ai = c14_a.im;
    c14_i0 = c14_ar * c14_b_b;
    c14_i1 = (c14_i0 >> 3) + ((c14_i0 & 4) != 0);
    if (c14_i1 > 255) {
      CV_SATURATION_EVAL(4, 0, 0, 0, 1);
      c14_i1 = 255;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 0, 0, c14_i1 < -256)) {
        c14_i1 = -256;
      }
    }

    c14_cr = (int16_T)c14_i1;
    c14_i2 = c14_ai * c14_b_b;
    c14_i3 = (c14_i2 >> 3) + ((c14_i2 & 4) != 0);
    if (c14_i3 > 255) {
      CV_SATURATION_EVAL(4, 0, 0, 0, 1);
      c14_i3 = 255;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 0, 0, c14_i3 < -256)) {
        c14_i3 = -256;
      }
    }

    c14_ci = (int16_T)c14_i3;
    c14_a.re = c14_cr;
    c14_a.im = c14_ci;
    c14_b_out = c14_a;
    sf_mex_destroy(&c14_errID);
    sf_mex_destroy(&c14_a2SD);
    sf_mex_destroy(&c14_b2SD);
    sf_mex_destroy(&c14_Tsd);
    _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 35);
    guard1 = false;
    if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 3, c14_get_loopCount
          (chartInstance, 0), c14_b_GI_Active, -1, 4U, c14_get_loopCount
          (chartInstance, 0) > c14_b_GI_Active))) {
      if (CV_EML_COND(0, 1, 3, c14_get_start(chartInstance, 0) != 0.0)) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 3, true);
        _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 36);
        c14_set_state(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 3);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 3, false);
      _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 38);
      c14_set_state(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c14_out = c14_b_out;
  *chartInstance->c14_pop = c14_b_pop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c14_sfEvent);
}

static void initSimStructsc14_Basic_DMT(SFc14_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber)
{
  (void)c14_machineNumber;
  (void)c14_chartNumber;
  (void)c14_instanceNumber;
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static real_T c14_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c14_b_pop, const char_T *c14_identifier)
{
  real_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_pop),
    &c14_thisId);
  sf_mex_destroy(&c14_b_pop);
  return c14_y;
}

static real_T c14_b_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d2;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d2, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d2;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_pop;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_b_pop = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_pop),
    &c14_thisId);
  sf_mex_destroy(&c14_b_pop);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData;
  cint16_T c14_u;
  const mxArray *c14_y = NULL;
  cint16_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_mxArrayOutData = NULL;
  c14_u = *(cint16_T *)c14_inData;
  c14_y = NULL;
  c14_b_u.re = c14_u.re;
  c14_b_u.im = c14_u.im;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c14_eml_mx), 15, "numerictype", 14, sf_mex_dup(c14_b_eml_mx), 15,
    "simulinkarray", 14, c14_b_y, 15, "fimathislocal", 3, false), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static cint16_T c14_c_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  cint16_T c14_y;
  const mxArray *c14_mxFi = NULL;
  const mxArray *c14_mxInt = NULL;
  cint16_T c14_ic2;
  (void)chartInstance;
  sf_mex_check_fi(c14_parentId, c14_u, true, 0U, NULL, c14_eml_mx, c14_b_eml_mx);
  sf_mex_assign(&c14_mxFi, sf_mex_dup(c14_u), false);
  sf_mex_assign(&c14_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c14_mxFi)), false);
  sf_mex_import(c14_parentId, sf_mex_dup(c14_mxInt), &c14_ic2, 1, 4, 1U, 0, 0U,
                0);
  sf_mex_destroy(&c14_mxFi);
  sf_mex_destroy(&c14_mxInt);
  c14_y = c14_ic2;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_out;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  cint16_T c14_y;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_b_out = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_out),
    &c14_thisId);
  sf_mex_destroy(&c14_b_out);
  *(cint16_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c14_info_helper(&c14_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(const mxArray **c14_info)
{
  const mxArray *c14_rhs0 = NULL;
  const mxArray *c14_lhs0 = NULL;
  const mxArray *c14_rhs1 = NULL;
  const mxArray *c14_lhs1 = NULL;
  const mxArray *c14_rhs2 = NULL;
  const mxArray *c14_lhs2 = NULL;
  const mxArray *c14_rhs3 = NULL;
  const mxArray *c14_lhs3 = NULL;
  const mxArray *c14_rhs4 = NULL;
  const mxArray *c14_lhs4 = NULL;
  const mxArray *c14_rhs5 = NULL;
  const mxArray *c14_lhs5 = NULL;
  const mxArray *c14_rhs6 = NULL;
  const mxArray *c14_lhs6 = NULL;
  const mxArray *c14_rhs7 = NULL;
  const mxArray *c14_lhs7 = NULL;
  const mxArray *c14_rhs8 = NULL;
  const mxArray *c14_lhs8 = NULL;
  const mxArray *c14_rhs9 = NULL;
  const mxArray *c14_lhs9 = NULL;
  const mxArray *c14_rhs10 = NULL;
  const mxArray *c14_lhs10 = NULL;
  const mxArray *c14_rhs11 = NULL;
  const mxArray *c14_lhs11 = NULL;
  const mxArray *c14_rhs12 = NULL;
  const mxArray *c14_lhs12 = NULL;
  const mxArray *c14_rhs13 = NULL;
  const mxArray *c14_lhs13 = NULL;
  const mxArray *c14_rhs14 = NULL;
  const mxArray *c14_lhs14 = NULL;
  const mxArray *c14_rhs15 = NULL;
  const mxArray *c14_lhs15 = NULL;
  const mxArray *c14_rhs16 = NULL;
  const mxArray *c14_lhs16 = NULL;
  const mxArray *c14_rhs17 = NULL;
  const mxArray *c14_lhs17 = NULL;
  const mxArray *c14_rhs18 = NULL;
  const mxArray *c14_lhs18 = NULL;
  const mxArray *c14_rhs19 = NULL;
  const mxArray *c14_lhs19 = NULL;
  const mxArray *c14_rhs20 = NULL;
  const mxArray *c14_lhs20 = NULL;
  const mxArray *c14_rhs21 = NULL;
  const mxArray *c14_lhs21 = NULL;
  const mxArray *c14_rhs22 = NULL;
  const mxArray *c14_lhs22 = NULL;
  const mxArray *c14_rhs23 = NULL;
  const mxArray *c14_lhs23 = NULL;
  const mxArray *c14_rhs24 = NULL;
  const mxArray *c14_lhs24 = NULL;
  const mxArray *c14_rhs25 = NULL;
  const mxArray *c14_lhs25 = NULL;
  const mxArray *c14_rhs26 = NULL;
  const mxArray *c14_lhs26 = NULL;
  const mxArray *c14_rhs27 = NULL;
  const mxArray *c14_lhs27 = NULL;
  const mxArray *c14_rhs28 = NULL;
  const mxArray *c14_lhs28 = NULL;
  const mxArray *c14_rhs29 = NULL;
  const mxArray *c14_lhs29 = NULL;
  const mxArray *c14_rhs30 = NULL;
  const mxArray *c14_lhs30 = NULL;
  const mxArray *c14_rhs31 = NULL;
  const mxArray *c14_lhs31 = NULL;
  const mxArray *c14_rhs32 = NULL;
  const mxArray *c14_lhs32 = NULL;
  const mxArray *c14_rhs33 = NULL;
  const mxArray *c14_lhs33 = NULL;
  const mxArray *c14_rhs34 = NULL;
  const mxArray *c14_lhs34 = NULL;
  const mxArray *c14_rhs35 = NULL;
  const mxArray *c14_lhs35 = NULL;
  const mxArray *c14_rhs36 = NULL;
  const mxArray *c14_lhs36 = NULL;
  const mxArray *c14_rhs37 = NULL;
  const mxArray *c14_lhs37 = NULL;
  const mxArray *c14_rhs38 = NULL;
  const mxArray *c14_lhs38 = NULL;
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510384U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c14_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isfi"), "name", "name", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c14_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c14_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isfi"), "name", "name", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c14_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c14_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("get"), "name", "name", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c14_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("times"), "name", "name", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510386U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c14_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c14_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isfi"), "name", "name", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c14_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isfi"), "name", "name", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c14_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isscaledtype"), "name",
                  "name", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510380U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c14_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isfixed"), "name", "name",
                  11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510378U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c14_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("get"), "name", "name", 12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c14_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("get"), "name", "name", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fimath"),
                  "dominantType", "dominantType", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c14_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("strcmpi"), "name", "name",
                  14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c14_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c14_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c14_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("intmax"), "name", "name", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c14_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c14_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("min"), "name", "name", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c14_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 20);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c14_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 21);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 21);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c14_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 22);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c14_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 23);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 23);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c14_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 24);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c14_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 25);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 25);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c14_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 26);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 26);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c14_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 27);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c14_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("get"), "name", "name", 28);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 28);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c14_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_fixpt_times"), "name",
                  "name", 29);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 29);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_fixpt_times.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1289519646U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c14_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("plus"), "name", "name", 30);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 30);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510384U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c14_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 31);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 31);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c14_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isfi"), "name", "name", 32);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c14_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isfi"), "name", "name", 33);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 33);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c14_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isscaledtype"), "name",
                  "name", 34);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 34);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510380U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c14_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("get"), "name", "name", 35);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fimath"),
                  "dominantType", "dominantType", 35);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c14_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("strcmpi"), "name", "name",
                  36);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c14_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("get"), "name", "name", 37);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 37);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c14_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_checkfimathforbinaryops"),
                  "name", "name", 38);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 38);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_checkfimathforbinaryops.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346510368U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c14_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c14_rhs0);
  sf_mex_destroy(&c14_lhs0);
  sf_mex_destroy(&c14_rhs1);
  sf_mex_destroy(&c14_lhs1);
  sf_mex_destroy(&c14_rhs2);
  sf_mex_destroy(&c14_lhs2);
  sf_mex_destroy(&c14_rhs3);
  sf_mex_destroy(&c14_lhs3);
  sf_mex_destroy(&c14_rhs4);
  sf_mex_destroy(&c14_lhs4);
  sf_mex_destroy(&c14_rhs5);
  sf_mex_destroy(&c14_lhs5);
  sf_mex_destroy(&c14_rhs6);
  sf_mex_destroy(&c14_lhs6);
  sf_mex_destroy(&c14_rhs7);
  sf_mex_destroy(&c14_lhs7);
  sf_mex_destroy(&c14_rhs8);
  sf_mex_destroy(&c14_lhs8);
  sf_mex_destroy(&c14_rhs9);
  sf_mex_destroy(&c14_lhs9);
  sf_mex_destroy(&c14_rhs10);
  sf_mex_destroy(&c14_lhs10);
  sf_mex_destroy(&c14_rhs11);
  sf_mex_destroy(&c14_lhs11);
  sf_mex_destroy(&c14_rhs12);
  sf_mex_destroy(&c14_lhs12);
  sf_mex_destroy(&c14_rhs13);
  sf_mex_destroy(&c14_lhs13);
  sf_mex_destroy(&c14_rhs14);
  sf_mex_destroy(&c14_lhs14);
  sf_mex_destroy(&c14_rhs15);
  sf_mex_destroy(&c14_lhs15);
  sf_mex_destroy(&c14_rhs16);
  sf_mex_destroy(&c14_lhs16);
  sf_mex_destroy(&c14_rhs17);
  sf_mex_destroy(&c14_lhs17);
  sf_mex_destroy(&c14_rhs18);
  sf_mex_destroy(&c14_lhs18);
  sf_mex_destroy(&c14_rhs19);
  sf_mex_destroy(&c14_lhs19);
  sf_mex_destroy(&c14_rhs20);
  sf_mex_destroy(&c14_lhs20);
  sf_mex_destroy(&c14_rhs21);
  sf_mex_destroy(&c14_lhs21);
  sf_mex_destroy(&c14_rhs22);
  sf_mex_destroy(&c14_lhs22);
  sf_mex_destroy(&c14_rhs23);
  sf_mex_destroy(&c14_lhs23);
  sf_mex_destroy(&c14_rhs24);
  sf_mex_destroy(&c14_lhs24);
  sf_mex_destroy(&c14_rhs25);
  sf_mex_destroy(&c14_lhs25);
  sf_mex_destroy(&c14_rhs26);
  sf_mex_destroy(&c14_lhs26);
  sf_mex_destroy(&c14_rhs27);
  sf_mex_destroy(&c14_lhs27);
  sf_mex_destroy(&c14_rhs28);
  sf_mex_destroy(&c14_lhs28);
  sf_mex_destroy(&c14_rhs29);
  sf_mex_destroy(&c14_lhs29);
  sf_mex_destroy(&c14_rhs30);
  sf_mex_destroy(&c14_lhs30);
  sf_mex_destroy(&c14_rhs31);
  sf_mex_destroy(&c14_lhs31);
  sf_mex_destroy(&c14_rhs32);
  sf_mex_destroy(&c14_lhs32);
  sf_mex_destroy(&c14_rhs33);
  sf_mex_destroy(&c14_lhs33);
  sf_mex_destroy(&c14_rhs34);
  sf_mex_destroy(&c14_lhs34);
  sf_mex_destroy(&c14_rhs35);
  sf_mex_destroy(&c14_lhs35);
  sf_mex_destroy(&c14_rhs36);
  sf_mex_destroy(&c14_lhs36);
  sf_mex_destroy(&c14_rhs37);
  sf_mex_destroy(&c14_lhs37);
  sf_mex_destroy(&c14_rhs38);
  sf_mex_destroy(&c14_lhs38);
}

static const mxArray *c14_emlrt_marshallOut(const char * c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c14_u)), false);
  return c14_y;
}

static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 7, 0U, 0U, 0U, 0), false);
  return c14_y;
}

static void c14_strcmpi(SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  c14_eml_scalar_eg(chartInstance);
  c14_eml_scalar_eg(chartInstance);
}

static void c14_eml_scalar_eg(SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static cint16_T c14_mtimes(SFc14_Basic_DMTInstanceStruct *chartInstance, int16_T
  c14_b0)
{
  cint16_T c14_cout;
  int16_T c14_cr;
  int16_T c14_ci;
  (void)c14_b0;
  c14_strcmpi(chartInstance);
  c14_b_strcmpi(chartInstance);
  c14_cr = 0;
  c14_ci = 0;
  c14_cout.re = c14_cr;
  c14_cout.im = c14_ci;
  return c14_cout;
}

static void c14_b_strcmpi(SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  c14_eml_scalar_eg(chartInstance);
  c14_eml_scalar_eg(chartInstance);
}

static cint16_T c14_plus(SFc14_Basic_DMTInstanceStruct *chartInstance, real_T
  c14_a0, cint16_T c14_b0)
{
  cint16_T c14_c;
  real_T c14_u;
  real_T c14_v;
  real_T c14_d3;
  int16_T c14_i4;
  int16_T c14_a;
  int32_T c14_i5;
  c14_strcmpi(chartInstance);
  c14_u = c14_a0 * 8.0;
  c14_v = muDoubleScalarAbs(c14_u);
  if (c14_v < 4.503599627370496E+15) {
    if (c14_v >= 0.5) {
      c14_d3 = muDoubleScalarFloor(c14_u + 0.5);
    } else {
      c14_d3 = c14_u * 0.0;
    }
  } else {
    c14_d3 = c14_u;
  }

  if (c14_d3 < 256.0) {
    if (c14_d3 >= -256.0) {
      c14_i4 = (int16_T)c14_d3;
    } else {
      c14_i4 = -256;
    }
  } else if (c14_d3 >= 256.0) {
    c14_i4 = 255;
  } else {
    c14_i4 = 0;
  }

  c14_a = c14_i4;
  c14_b_strcmpi(chartInstance);
  c14_i5 = c14_a + c14_b0.re;
  if (c14_i5 > 255) {
    c14_i5 = 255;
  } else {
    if (c14_i5 < -256) {
      c14_i5 = -256;
    }
  }

  c14_c.re = (int16_T)c14_i5;
  c14_c.im = c14_b0.im;
  return c14_c;
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static int32_T c14_d_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i6;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i6, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i6;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData;
  cint16_T c14_u;
  const mxArray *c14_y = NULL;
  cint16_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_mxArrayOutData = NULL;
  c14_u = *(cint16_T *)c14_inData;
  c14_y = NULL;
  c14_b_u.re = c14_u.re;
  c14_b_u.im = c14_u.im;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c14_eml_mx), 15, "numerictype", 14, sf_mex_dup(c14_b_eml_mx), 15,
    "simulinkarray", 14, c14_b_y, 15, "fimathislocal", 3, true), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static cint16_T c14_e_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_b_out, const char_T *c14_identifier)
{
  cint16_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_out),
    &c14_thisId);
  sf_mex_destroy(&c14_b_out);
  return c14_y;
}

static cint16_T c14_f_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  cint16_T c14_y;
  const mxArray *c14_mxFi = NULL;
  const mxArray *c14_mxInt = NULL;
  cint16_T c14_ic3;
  (void)chartInstance;
  sf_mex_check_fi(c14_parentId, c14_u, true, 0U, NULL, c14_eml_mx, c14_b_eml_mx);
  sf_mex_assign(&c14_mxFi, sf_mex_dup(c14_u), false);
  sf_mex_assign(&c14_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c14_mxFi)), false);
  sf_mex_import(c14_parentId, sf_mex_dup(c14_mxInt), &c14_ic3, 1, 4, 1U, 0, 0U,
                0);
  sf_mex_destroy(&c14_mxFi);
  sf_mex_destroy(&c14_mxInt);
  c14_y = c14_ic3;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_out;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  cint16_T c14_y;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_b_out = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_out),
    &c14_thisId);
  sf_mex_destroy(&c14_b_out);
  *(cint16_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData;
  int16_T c14_u;
  const mxArray *c14_y = NULL;
  int16_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c14_u = *(int16_T *)c14_inData;
    c14_y = NULL;
    c14_b_u = c14_u;
    c14_b_y = NULL;
    sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 4, 0U, 0U, 0U, 0),
                  false);
    sf_mex_assign(&c14_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                   (c14_eml_mx), 15, "numerictype", 14, sf_mex_dup(c14_b_eml_mx),
      15, "simulinkarray", 14, c14_b_y, 15, "fimathislocal", 3, false), false);
    sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  } else {
    sf_mex_assign(&c14_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c14_mxArrayOutData;
}

static int16_T c14_g_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int16_T c14_y;
  const mxArray *c14_mxFi = NULL;
  const mxArray *c14_mxInt = NULL;
  int16_T c14_i7;
  (void)chartInstance;
  sf_mex_check_fi(c14_parentId, c14_u, false, 0U, NULL, c14_eml_mx, c14_b_eml_mx);
  sf_mex_assign(&c14_mxFi, sf_mex_dup(c14_u), false);
  sf_mex_assign(&c14_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c14_mxFi)), false);
  sf_mex_import(c14_parentId, sf_mex_dup(c14_mxInt), &c14_i7, 1, 4, 0U, 0, 0U, 0);
  sf_mex_destroy(&c14_mxFi);
  sf_mex_destroy(&c14_mxInt);
  c14_y = c14_i7;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_convert;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int16_T c14_y;
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)chartInstanceVoid;
  if (sf_debug_check_fi_license()) {
    c14_convert = sf_mex_dup(c14_mxArrayInData);
    c14_identifier = c14_varName;
    c14_thisId.fIdentifier = c14_identifier;
    c14_thisId.fParent = NULL;
    c14_y = c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_convert),
      &c14_thisId);
    sf_mex_destroy(&c14_convert);
    *(int16_T *)c14_outData = c14_y;
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_h_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_Basic_DMT, const char_T
  *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_Basic_DMT), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_Basic_DMT);
  return c14_y;
}

static uint8_T c14_i_emlrt_marshallIn(SFc14_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static int16_T c14_get_convert(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c14_elementIndex);
  return *chartInstance->c14_convert_address;
}

static void c14_set_convert(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex, int16_T c14_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c14_elementIndex);
  *chartInstance->c14_convert_address = c14_elementValue;
}

static int16_T *c14_access_convert(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_rdOnly)
{
  int16_T *c14_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c14_dsmAddr = chartInstance->c14_convert_address;
  if (c14_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c14_dsmAddr;
}

static real_T c14_get_loopCount(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c14_elementIndex);
  return *chartInstance->c14_loopCount_address;
}

static void c14_set_loopCount(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex, real_T c14_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c14_elementIndex);
  *chartInstance->c14_loopCount_address = c14_elementValue;
}

static real_T *c14_access_loopCount(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_rdOnly)
{
  real_T *c14_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c14_dsmAddr = chartInstance->c14_loopCount_address;
  if (c14_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c14_dsmAddr;
}

static real_T c14_get_start(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c14_elementIndex);
  return *chartInstance->c14_start_address;
}

static void c14_set_start(SFc14_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c14_elementIndex, real_T c14_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c14_elementIndex);
  *chartInstance->c14_start_address = c14_elementValue;
}

static real_T *c14_access_start(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_rdOnly)
{
  real_T *c14_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c14_dsmAddr = chartInstance->c14_start_address;
  if (c14_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c14_dsmAddr;
}

static real_T c14_get_state(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 3, NULL, c14_elementIndex);
  return *chartInstance->c14_state_address;
}

static void c14_set_state(SFc14_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c14_elementIndex, real_T c14_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 3, NULL, c14_elementIndex);
  *chartInstance->c14_state_address = c14_elementValue;
}

static real_T *c14_access_state(SFc14_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c14_rdOnly)
{
  real_T *c14_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 3, NULL);
  c14_dsmAddr = chartInstance->c14_state_address;
  if (c14_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 3, NULL);
  }

  return c14_dsmAddr;
}

static void init_dsm_address_info(SFc14_Basic_DMTInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "convert", (void **)
    &chartInstance->c14_convert_address, &chartInstance->c14_convert_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "loopCount", (void **)
    &chartInstance->c14_loopCount_address, &chartInstance->c14_loopCount_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "start", (void **)
    &chartInstance->c14_start_address, &chartInstance->c14_start_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "state", (void **)
    &chartInstance->c14_state_address, &chartInstance->c14_state_index);
}

static void init_simulink_io_address(SFc14_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c14_inp = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c14_out = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c14_pop = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c14_frameEn = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c14_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1499065148U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(574643167U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1484760009U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3429536012U);
}

mxArray* sf_c14_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c14_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aCDJUyYPyszhwVpeoQ5ntC");
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
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(9));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(-3));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(9));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(-3));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c14_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c14_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c14_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c14_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c14_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[1],M[6],T\"pop\",},{M[8],M[0],T\"is_active_c14_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc14_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           14,
           1,
           1,
           0,
           10,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Basic_DMTMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Basic_DMTMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Basic_DMTMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"inp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"out");
          _SFD_SET_DATA_PROPS(2,2,0,1,"pop");
          _SFD_SET_DATA_PROPS(3,11,0,0,"start");
          _SFD_SET_DATA_PROPS(4,11,0,0,"state");
          _SFD_SET_DATA_PROPS(5,11,0,0,"loopCount");
          _SFD_SET_DATA_PROPS(6,1,1,0,"frameEn");
          _SFD_SET_DATA_PROPS(7,10,0,0,"GI_Active");
          _SFD_SET_DATA_PROPS(8,10,0,0,"fftLenActive");
          _SFD_SET_DATA_PROPS(9,11,0,0,"convert");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,4,0,1,1,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,740);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,576,-1,587);
        _SFD_CV_INIT_EML_IF(0,1,0,173,188,-1,224);
        _SFD_CV_INIT_EML_IF(0,1,1,252,289,-1,306);
        _SFD_CV_INIT_EML_IF(0,1,2,386,419,473,522);
        _SFD_CV_INIT_EML_IF(0,1,3,597,630,682,731);

        {
          static int caseStart[] = { -1, 325, 536 };

          static int caseExprEnd[] = { 8, 331, 542 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,308,321,736,3,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 389, 414 };

          static int condEnd[] = { 410, 419 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,389,419,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 600, 625 };

          static int condEnd[] = { 621, 630 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,600,630,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,176,188,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,255,289,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,389,410,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,600,621,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c14_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c14_d_sf_marshallOut,(MexInFcnForType)
          c14_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)c14_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT16,0,NULL,1,1,9,0,1,-3,0,
          (MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)
          c14_e_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c14_inp);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c14_out);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c14_pop);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c14_start_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c14_state_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c14_loopCount_address);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c14_frameEn);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c14_GI_Active);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c14_fftLenActive);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c14_convert_address);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Basic_DMTMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3oiy2KY4xYqI3TJ4boZcrG";
}

static void sf_opaque_initialize_c14_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c14_Basic_DMT(void *chartInstanceVar)
{
  enable_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_Basic_DMT(void *chartInstanceVar)
{
  disable_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c14_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c14_Basic_DMT(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c14_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_Basic_DMT(SimStruct *S)
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
    initialize_params_c14_Basic_DMT((SFc14_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_Basic_DMT(SimStruct *S)
{
  /* Actual parameters from chart:
     GI_Active fftLenActive
   */
  const char_T *rtParamNames[] = { "GI_Active", "fftLenActive" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for GI_Active*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for fftLenActive*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,14,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3462072150U));
  ssSetChecksum1(S,(1391409675U));
  ssSetChecksum2(S,(1525642285U));
  ssSetChecksum3(S,(1653718232U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c14_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_Basic_DMT(SimStruct *S)
{
  SFc14_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc14_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc14_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c14_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c14_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c14_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c14_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c14_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c14_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c14_Basic_DMT;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
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
  chart_debug_initialization(S,1);
}

void c14_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
