/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c7_Basic_DMT.h"
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
static const char * c7_debug_family_names[8] = { "nargin", "nargout", "sent",
  "recv", "rst", "sent_out", "error", "ber" };

static const mxArray *c7_eml_mx;
static const mxArray *c7_b_eml_mx;

/* Function Declarations */
static void initialize_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance);
static void initialize_params_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance);
static void disable_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance);
static void set_sim_state_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c7_st);
static void finalize_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance);
static void mdl_start_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance);
static void initSimStructsc7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_b_ber, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_info_helper(const mxArray **c7_info);
static const mxArray *c7_emlrt_marshallOut(const char * c7_u);
static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u);
static boolean_T c7_ne(SFc7_Basic_DMTInstanceStruct *chartInstance, uint8_T
  c7_a0, uint8_T c7_b0);
static void c7_eml_scalar_eg(SFc7_Basic_DMTInstanceStruct *chartInstance);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_c_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static uint8_T c7_d_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_Basic_DMT, const char_T *c7_identifier);
static uint8_T c7_e_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static real_T c7_get_ber_r(SFc7_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c7_elementIndex);
static void c7_set_ber_r(SFc7_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c7_elementIndex, real_T c7_elementValue);
static real_T *c7_access_ber_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_rdOnly);
static real_T c7_get_error_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_elementIndex);
static void c7_set_error_r(SFc7_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c7_elementIndex, real_T c7_elementValue);
static real_T *c7_access_error_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_rdOnly);
static real_T c7_get_sent_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_elementIndex);
static void c7_set_sent_r(SFc7_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c7_elementIndex, real_T c7_elementValue);
static real_T *c7_access_sent_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_rdOnly);
static void init_dsm_address_info(SFc7_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc7_Basic_DMTInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_is_active_c7_Basic_DMT = 0U;
  sf_mex_assign(&c7_b_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 14U, 15, "SignednessBool", 3, false, 15, "Signedness", 15,
    "Unsigned", 15, "WordLength", 6, 1.0, 15, "FractionLength", 6, 0.0, 15,
    "BinaryPoint", 6, 0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0),
                true);
  sf_mex_assign(&c7_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "fimath", 1U, 42U, 15, "RoundMode", 15, "nearest", 15, "RoundingMethod", 15,
    "Nearest", 15, "OverflowMode", 15, "saturate", 15, "OverflowAction", 15,
    "Saturate", 15, "ProductMode", 15, "FullPrecision", 15, "ProductWordLength",
    6, 32.0, 15, "MaxProductWordLength", 6, 65535.0, 15, "ProductFractionLength",
    6, 30.0, 15, "ProductFixedExponent", 6, -30.0, 15, "ProductSlope", 6,
    9.3132257461547852E-10, 15, "ProductSlopeAdjustmentFactor", 6, 1.0, 15,
    "ProductBias", 6, 0.0, 15, "SumMode", 15, "FullPrecision", 15,
    "SumWordLength", 6, 32.0, 15, "MaxSumWordLength", 6, 65535.0, 15,
    "SumFractionLength", 6, 30.0, 15, "SumFixedExponent", 6, -30.0, 15,
    "SumSlope", 6, 9.3132257461547852E-10, 15, "SumSlopeAdjustmentFactor", 6,
    1.0, 15, "SumBias", 6, 0.0, 15, "CastBeforeSum", 3, true), true);
}

static void initialize_params_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  uint8_T c7_d_hoistedGlobal;
  uint8_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(4, 1), false);
  c7_hoistedGlobal = *chartInstance->c7_ber;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *chartInstance->c7_error;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *chartInstance->c7_sent_out;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = chartInstance->c7_is_active_c7_Basic_DMT;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  *chartInstance->c7_ber = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 0)), "ber");
  *chartInstance->c7_error = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 1)), "error");
  *chartInstance->c7_sent_out = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 2)), "sent_out");
  chartInstance->c7_is_active_c7_Basic_DMT = c7_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 3)), "is_active_c7_Basic_DMT");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_Basic_DMT(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
  sf_mex_destroy(&c7_eml_mx);
  sf_mex_destroy(&c7_b_eml_mx);
}

static void sf_gateway_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  uint8_T c7_hoistedGlobal;
  uint8_T c7_b_hoistedGlobal;
  real_T c7_c_hoistedGlobal;
  uint8_T c7_b_sent;
  uint8_T c7_b_recv;
  real_T c7_b_rst;
  uint32_T c7_debug_family_var_map[8];
  real_T c7_nargin = 3.0;
  real_T c7_nargout = 3.0;
  real_T c7_b_sent_out;
  real_T c7_b_error;
  real_T c7_b_ber;
  int8_T c7_i0;
  int8_T c7_i1;
  int8_T c7_i2;
  int8_T c7_i3;
  int8_T c7_i4;
  int8_T c7_i5;
  real_T c7_d0;
  int8_T c7_i6;
  int8_T c7_i7;
  real_T c7_d_hoistedGlobal;
  real_T c7_e_hoistedGlobal;
  real_T c7_A;
  real_T c7_B;
  real_T c7_x;
  real_T c7_y;
  real_T c7_b_x;
  real_T c7_b_y;
  real_T c7_c_x;
  real_T c7_c_y;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_sent, 0U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *chartInstance->c7_sent;
  c7_b_hoistedGlobal = *chartInstance->c7_recv;
  c7_c_hoistedGlobal = *chartInstance->c7_rst;
  c7_b_sent = c7_hoistedGlobal;
  c7_b_recv = c7_b_hoistedGlobal;
  c7_b_rst = c7_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_sent, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_recv, 3U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_rst, 4U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_sent_out, 5U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_error, 6U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_ber, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_set_sent_r(chartInstance, 0, c7_get_sent_r(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  c7_i0 = (int8_T)c7_b_sent;
  c7_i1 = (int8_T)c7_b_recv;
  c7_i2 = (int8_T)c7_b_sent;
  c7_i3 = (int8_T)c7_b_recv;
  if ((int8_T)(c7_i0 & 2) != 0) {
    c7_i4 = (int8_T)(c7_i0 | -2);
  } else {
    c7_i4 = (int8_T)(c7_i0 & 1);
  }

  if ((int8_T)(c7_i1 & 2) != 0) {
    c7_i5 = (int8_T)(c7_i1 | -2);
  } else {
    c7_i5 = (int8_T)(c7_i1 & 1);
  }

  if (c7_i4 < c7_i5) {
    c7_d0 = 1.0;
  } else {
    if ((int8_T)(c7_i2 & 2) != 0) {
      c7_i6 = (int8_T)(c7_i2 | -2);
    } else {
      c7_i6 = (int8_T)(c7_i2 & 1);
    }

    if ((int8_T)(c7_i3 & 2) != 0) {
      c7_i7 = (int8_T)(c7_i3 | -2);
    } else {
      c7_i7 = (int8_T)(c7_i3 & 1);
    }

    if (c7_i6 > c7_i7) {
      c7_d0 = 3.0;
    } else {
      c7_d0 = 2.0;
    }
  }

  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c7_d0, 0.0, -2, 1U,
        (int32_T)c7_ne(chartInstance, c7_b_sent, c7_b_recv)))) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
    c7_set_error_r(chartInstance, 0, c7_get_error_r(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_d_hoistedGlobal = c7_get_error_r(chartInstance, 0);
  c7_e_hoistedGlobal = c7_get_sent_r(chartInstance, 0);
  c7_A = c7_d_hoistedGlobal;
  c7_B = c7_e_hoistedGlobal;
  c7_x = c7_A;
  c7_y = c7_B;
  c7_b_x = c7_x;
  c7_b_y = c7_y;
  c7_c_x = c7_b_x;
  c7_c_y = c7_b_y;
  c7_set_ber_r(chartInstance, 0, c7_c_x / c7_c_y);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c7_b_rst, 1.0, -1, 0U,
        c7_b_rst == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
    c7_set_ber_r(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
    c7_set_sent_r(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 17);
    c7_set_error_r(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
  c7_b_sent_out = c7_get_sent_r(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 21);
  c7_b_error = c7_get_error_r(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 22);
  c7_b_ber = c7_get_ber_r(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c7_sent_out = c7_b_sent_out;
  *chartInstance->c7_error = c7_b_error;
  *chartInstance->c7_ber = c7_b_ber;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_sent_out, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_error, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_recv, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_ber, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_rst, 8U);
}

static void mdl_start_c7_Basic_DMT(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc7_Basic_DMT(SFc7_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc7_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_b_ber, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_ber), &c7_thisId);
  sf_mex_destroy(&c7_b_ber);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d1;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d1, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_ber;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc7_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c7_b_ber = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_ber), &c7_thisId);
  sf_mex_destroy(&c7_b_ber);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  uint8_T c7_u;
  const mxArray *c7_y = NULL;
  uint8_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  SFc7_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc7_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c7_u = *(uint8_T *)c7_inData;
    c7_y = NULL;
    c7_b_u = c7_u;
    c7_b_y = NULL;
    sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), false);
    sf_mex_assign(&c7_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c7_eml_mx), 15, "numerictype", 14, sf_mex_dup(c7_b_eml_mx), 15,
      "simulinkarray", 14, c7_b_y, 15, "fimathislocal", 3, false), false);
    sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  } else {
    sf_mex_assign(&c7_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c7_mxArrayOutData;
}

const mxArray *sf_c7_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_createstruct("structure", 2, 30, 1),
                false);
  c7_info_helper(&c7_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(const mxArray **c7_info)
{
  const mxArray *c7_rhs0 = NULL;
  const mxArray *c7_lhs0 = NULL;
  const mxArray *c7_rhs1 = NULL;
  const mxArray *c7_lhs1 = NULL;
  const mxArray *c7_rhs2 = NULL;
  const mxArray *c7_lhs2 = NULL;
  const mxArray *c7_rhs3 = NULL;
  const mxArray *c7_lhs3 = NULL;
  const mxArray *c7_rhs4 = NULL;
  const mxArray *c7_lhs4 = NULL;
  const mxArray *c7_rhs5 = NULL;
  const mxArray *c7_lhs5 = NULL;
  const mxArray *c7_rhs6 = NULL;
  const mxArray *c7_lhs6 = NULL;
  const mxArray *c7_rhs7 = NULL;
  const mxArray *c7_lhs7 = NULL;
  const mxArray *c7_rhs8 = NULL;
  const mxArray *c7_lhs8 = NULL;
  const mxArray *c7_rhs9 = NULL;
  const mxArray *c7_lhs9 = NULL;
  const mxArray *c7_rhs10 = NULL;
  const mxArray *c7_lhs10 = NULL;
  const mxArray *c7_rhs11 = NULL;
  const mxArray *c7_lhs11 = NULL;
  const mxArray *c7_rhs12 = NULL;
  const mxArray *c7_lhs12 = NULL;
  const mxArray *c7_rhs13 = NULL;
  const mxArray *c7_lhs13 = NULL;
  const mxArray *c7_rhs14 = NULL;
  const mxArray *c7_lhs14 = NULL;
  const mxArray *c7_rhs15 = NULL;
  const mxArray *c7_lhs15 = NULL;
  const mxArray *c7_rhs16 = NULL;
  const mxArray *c7_lhs16 = NULL;
  const mxArray *c7_rhs17 = NULL;
  const mxArray *c7_lhs17 = NULL;
  const mxArray *c7_rhs18 = NULL;
  const mxArray *c7_lhs18 = NULL;
  const mxArray *c7_rhs19 = NULL;
  const mxArray *c7_lhs19 = NULL;
  const mxArray *c7_rhs20 = NULL;
  const mxArray *c7_lhs20 = NULL;
  const mxArray *c7_rhs21 = NULL;
  const mxArray *c7_lhs21 = NULL;
  const mxArray *c7_rhs22 = NULL;
  const mxArray *c7_lhs22 = NULL;
  const mxArray *c7_rhs23 = NULL;
  const mxArray *c7_lhs23 = NULL;
  const mxArray *c7_rhs24 = NULL;
  const mxArray *c7_lhs24 = NULL;
  const mxArray *c7_rhs25 = NULL;
  const mxArray *c7_lhs25 = NULL;
  const mxArray *c7_rhs26 = NULL;
  const mxArray *c7_lhs26 = NULL;
  const mxArray *c7_rhs27 = NULL;
  const mxArray *c7_lhs27 = NULL;
  const mxArray *c7_rhs28 = NULL;
  const mxArray *c7_lhs28 = NULL;
  const mxArray *c7_rhs29 = NULL;
  const mxArray *c7_lhs29 = NULL;
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("ne"), "name", "name", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/ne.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1397257424U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c7_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/ne.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c7_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/ne.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("isfi"), "name", "name", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c7_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c7_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/ne.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("get"), "name", "name", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.fimath"),
                  "dominantType", "dominantType", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c7_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/ne.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("strcmpi"), "name", "name", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c7_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c7_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_charmax"), "name", "name",
                  7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c7_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("intmax"), "name", "name", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c7_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c7_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("min"), "name", "name", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c7_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c7_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c7_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c7_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c7_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c7_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c7_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c7_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c7_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/ne.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("isscaledtype"), "name", "name",
                  19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1346510380U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c7_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("isfixed"), "name", "name", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1346510378U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c7_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("get"), "name", "name", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c7_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/ne.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_make_same_complexity"),
                  "name", "name", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_make_same_complexity.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1289519646U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c7_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("mrdivide"), "name", "name", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c7_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c7_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("rdivide"), "name", "name", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c7_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c7_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c7_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_div"), "name", "name", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c7_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c7_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs29), "lhs", "lhs",
                  29);
  sf_mex_destroy(&c7_rhs0);
  sf_mex_destroy(&c7_lhs0);
  sf_mex_destroy(&c7_rhs1);
  sf_mex_destroy(&c7_lhs1);
  sf_mex_destroy(&c7_rhs2);
  sf_mex_destroy(&c7_lhs2);
  sf_mex_destroy(&c7_rhs3);
  sf_mex_destroy(&c7_lhs3);
  sf_mex_destroy(&c7_rhs4);
  sf_mex_destroy(&c7_lhs4);
  sf_mex_destroy(&c7_rhs5);
  sf_mex_destroy(&c7_lhs5);
  sf_mex_destroy(&c7_rhs6);
  sf_mex_destroy(&c7_lhs6);
  sf_mex_destroy(&c7_rhs7);
  sf_mex_destroy(&c7_lhs7);
  sf_mex_destroy(&c7_rhs8);
  sf_mex_destroy(&c7_lhs8);
  sf_mex_destroy(&c7_rhs9);
  sf_mex_destroy(&c7_lhs9);
  sf_mex_destroy(&c7_rhs10);
  sf_mex_destroy(&c7_lhs10);
  sf_mex_destroy(&c7_rhs11);
  sf_mex_destroy(&c7_lhs11);
  sf_mex_destroy(&c7_rhs12);
  sf_mex_destroy(&c7_lhs12);
  sf_mex_destroy(&c7_rhs13);
  sf_mex_destroy(&c7_lhs13);
  sf_mex_destroy(&c7_rhs14);
  sf_mex_destroy(&c7_lhs14);
  sf_mex_destroy(&c7_rhs15);
  sf_mex_destroy(&c7_lhs15);
  sf_mex_destroy(&c7_rhs16);
  sf_mex_destroy(&c7_lhs16);
  sf_mex_destroy(&c7_rhs17);
  sf_mex_destroy(&c7_lhs17);
  sf_mex_destroy(&c7_rhs18);
  sf_mex_destroy(&c7_lhs18);
  sf_mex_destroy(&c7_rhs19);
  sf_mex_destroy(&c7_lhs19);
  sf_mex_destroy(&c7_rhs20);
  sf_mex_destroy(&c7_lhs20);
  sf_mex_destroy(&c7_rhs21);
  sf_mex_destroy(&c7_lhs21);
  sf_mex_destroy(&c7_rhs22);
  sf_mex_destroy(&c7_lhs22);
  sf_mex_destroy(&c7_rhs23);
  sf_mex_destroy(&c7_lhs23);
  sf_mex_destroy(&c7_rhs24);
  sf_mex_destroy(&c7_lhs24);
  sf_mex_destroy(&c7_rhs25);
  sf_mex_destroy(&c7_lhs25);
  sf_mex_destroy(&c7_rhs26);
  sf_mex_destroy(&c7_lhs26);
  sf_mex_destroy(&c7_rhs27);
  sf_mex_destroy(&c7_lhs27);
  sf_mex_destroy(&c7_rhs28);
  sf_mex_destroy(&c7_lhs28);
  sf_mex_destroy(&c7_rhs29);
  sf_mex_destroy(&c7_lhs29);
}

static const mxArray *c7_emlrt_marshallOut(const char * c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c7_u)), false);
  return c7_y;
}

static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 7, 0U, 0U, 0U, 0), false);
  return c7_y;
}

static boolean_T c7_ne(SFc7_Basic_DMTInstanceStruct *chartInstance, uint8_T
  c7_a0, uint8_T c7_b0)
{
  uint8_T c7_a;
  uint8_T c7_b;
  uint8_T c7_b_a0;
  uint8_T c7_b_b0;
  uint8_T c7_a1;
  uint8_T c7_b1;
  uint8_T c7_b_a1;
  uint8_T c7_b_b1;
  c7_eml_scalar_eg(chartInstance);
  c7_eml_scalar_eg(chartInstance);
  c7_a = c7_a0;
  c7_b = c7_b0;
  c7_b_a0 = c7_a;
  c7_b_b0 = c7_b;
  c7_a1 = c7_b_a0;
  c7_b1 = c7_b_b0;
  c7_b_a1 = c7_a1;
  c7_b_b1 = c7_b1;
  return c7_b_a1 != c7_b_b1;
}

static void c7_eml_scalar_eg(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc7_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_c_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i8;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i8, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i8;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc7_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  uint8_T c7_u;
  const mxArray *c7_y = NULL;
  uint8_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  SFc7_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc7_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c7_u = *(uint8_T *)c7_inData;
    c7_y = NULL;
    c7_b_u = c7_u;
    c7_b_y = NULL;
    sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), false);
    sf_mex_assign(&c7_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c7_eml_mx), 15, "numerictype", 14, sf_mex_dup(c7_b_eml_mx), 15,
      "simulinkarray", 14, c7_b_y, 15, "fimathislocal", 3, true), false);
    sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  } else {
    sf_mex_assign(&c7_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c7_mxArrayOutData;
}

static uint8_T c7_d_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_Basic_DMT, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_Basic_DMT), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_Basic_DMT);
  return c7_y;
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static real_T c7_get_ber_r(SFc7_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c7_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c7_elementIndex);
  return *chartInstance->c7_ber_r_address;
}

static void c7_set_ber_r(SFc7_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c7_elementIndex, real_T c7_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c7_elementIndex);
  *chartInstance->c7_ber_r_address = c7_elementValue;
}

static real_T *c7_access_ber_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_rdOnly)
{
  real_T *c7_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c7_dsmAddr = chartInstance->c7_ber_r_address;
  if (c7_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c7_dsmAddr;
}

static real_T c7_get_error_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c7_elementIndex);
  return *chartInstance->c7_error_r_address;
}

static void c7_set_error_r(SFc7_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c7_elementIndex, real_T c7_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c7_elementIndex);
  *chartInstance->c7_error_r_address = c7_elementValue;
}

static real_T *c7_access_error_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_rdOnly)
{
  real_T *c7_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c7_dsmAddr = chartInstance->c7_error_r_address;
  if (c7_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c7_dsmAddr;
}

static real_T c7_get_sent_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c7_elementIndex);
  return *chartInstance->c7_sent_r_address;
}

static void c7_set_sent_r(SFc7_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c7_elementIndex, real_T c7_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c7_elementIndex);
  *chartInstance->c7_sent_r_address = c7_elementValue;
}

static real_T *c7_access_sent_r(SFc7_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c7_rdOnly)
{
  real_T *c7_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c7_dsmAddr = chartInstance->c7_sent_r_address;
  if (c7_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c7_dsmAddr;
}

static void init_dsm_address_info(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "ber_r", (void **)
    &chartInstance->c7_ber_r_address, &chartInstance->c7_ber_r_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "error_r", (void **)
    &chartInstance->c7_error_r_address, &chartInstance->c7_error_r_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "sent_r", (void **)
    &chartInstance->c7_sent_r_address, &chartInstance->c7_sent_r_index);
}

static void init_simulink_io_address(SFc7_Basic_DMTInstanceStruct *chartInstance)
{
  chartInstance->c7_sent = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c7_sent_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_recv = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_ber = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c7_rst = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c7_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2580223037U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3614803600U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4010280523U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1677846152U);
}

mxArray* sf_c7_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c7_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hRzn4GUISU3r3zY2HtKnIE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c7_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c7_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c7_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[40],T\"ber\",},{M[1],M[6],T\"error\",},{M[1],M[10],T\"sent_out\",},{M[8],M[0],T\"is_active_c7_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc7_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           7,
           1,
           1,
           0,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"sent");
          _SFD_SET_DATA_PROPS(1,2,0,1,"sent_out");
          _SFD_SET_DATA_PROPS(2,2,0,1,"error");
          _SFD_SET_DATA_PROPS(3,1,1,0,"recv");
          _SFD_SET_DATA_PROPS(4,11,0,0,"ber_r");
          _SFD_SET_DATA_PROPS(5,11,0,0,"sent_r");
          _SFD_SET_DATA_PROPS(6,11,0,0,"error_r");
          _SFD_SET_DATA_PROPS(7,2,0,1,"ber");
          _SFD_SET_DATA_PROPS(8,1,1,0,"rst");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,311);
        _SFD_CV_INIT_EML_IF(0,1,0,126,141,-1,174);
        _SFD_CV_INIT_EML_IF(0,1,1,200,211,-1,257);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,129,141,-2,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,203,211,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,1,0,1,0,1,0,0,
          (MexFcnForType)c7_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,1,0,1,0,1,0,0,
          (MexFcnForType)c7_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c7_sent);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c7_sent_out);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c7_error);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c7_recv);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c7_ber_r_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c7_sent_r_address);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c7_error_r_address);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c7_ber);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c7_rst);
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
  return "mrNuRBvJm6nFh7AnJpypWE";
}

static void sf_opaque_initialize_c7_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_Basic_DMT(void *chartInstanceVar)
{
  enable_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_Basic_DMT(void *chartInstanceVar)
{
  disable_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_Basic_DMT(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c7_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Basic_DMT(SimStruct *S)
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
    initialize_params_c7_Basic_DMT((SFc7_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3783222783U));
  ssSetChecksum1(S,(2064263043U));
  ssSetChecksum2(S,(281317762U));
  ssSetChecksum3(S,(2896787334U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c7_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Basic_DMT(SimStruct *S)
{
  SFc7_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc7_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc7_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_Basic_DMT;
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

void c7_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
