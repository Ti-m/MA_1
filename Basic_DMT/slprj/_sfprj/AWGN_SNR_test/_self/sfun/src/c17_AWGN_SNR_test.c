/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AWGN_SNR_test_sfun.h"
#include "c17_AWGN_SNR_test.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AWGN_SNR_test_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c17_debug_family_names[8] = { "nargin", "nargout", "send",
  "recv", "rst", "send_out", "error", "ber" };

/* Function Declarations */
static void initialize_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);
static void initialize_params_c17_AWGN_SNR_test
  (SFc17_AWGN_SNR_testInstanceStruct *chartInstance);
static void enable_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);
static void disable_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);
static void c17_update_debugger_state_c17_AWGN_SNR_test
  (SFc17_AWGN_SNR_testInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_AWGN_SNR_test
  (SFc17_AWGN_SNR_testInstanceStruct *chartInstance);
static void set_sim_state_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_st);
static void finalize_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);
static void sf_gateway_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);
static void mdl_start_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);
static void initSimStructsc17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_b_ber, const char_T *c17_identifier);
static real_T c17_b_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_info_helper(const mxArray **c17_info);
static const mxArray *c17_emlrt_marshallOut(const char * c17_u);
static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_c_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_d_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_AWGN_SNR_test, const char_T
  *c17_identifier);
static uint8_T c17_e_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static real_T c17_get_ber_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex);
static void c17_set_ber_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex, real_T c17_elementValue);
static real_T *c17_access_ber_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_rdOnly);
static real_T c17_get_error_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex);
static void c17_set_error_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex, real_T c17_elementValue);
static real_T *c17_access_error_r(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, uint32_T c17_rdOnly);
static real_T c17_get_send_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex);
static void c17_set_send_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex, real_T c17_elementValue);
static real_T *c17_access_send_r(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, uint32_T c17_rdOnly);
static void init_dsm_address_info(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c17_is_active_c17_AWGN_SNR_test = 0U;
}

static void initialize_params_c17_AWGN_SNR_test
  (SFc17_AWGN_SNR_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c17_update_debugger_state_c17_AWGN_SNR_test
  (SFc17_AWGN_SNR_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c17_AWGN_SNR_test
  (SFc17_AWGN_SNR_testInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  real_T c17_hoistedGlobal;
  real_T c17_u;
  const mxArray *c17_b_y = NULL;
  real_T c17_b_hoistedGlobal;
  real_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T c17_c_hoistedGlobal;
  real_T c17_c_u;
  const mxArray *c17_d_y = NULL;
  uint8_T c17_d_hoistedGlobal;
  uint8_T c17_d_u;
  const mxArray *c17_e_y = NULL;
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellmatrix(4, 1), false);
  c17_hoistedGlobal = *chartInstance->c17_ber;
  c17_u = c17_hoistedGlobal;
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_b_hoistedGlobal = *chartInstance->c17_error;
  c17_b_u = c17_b_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  c17_c_hoistedGlobal = *chartInstance->c17_send_out;
  c17_c_u = c17_c_hoistedGlobal;
  c17_d_y = NULL;
  sf_mex_assign(&c17_d_y, sf_mex_create("y", &c17_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 2, c17_d_y);
  c17_d_hoistedGlobal = chartInstance->c17_is_active_c17_AWGN_SNR_test;
  c17_d_u = c17_d_hoistedGlobal;
  c17_e_y = NULL;
  sf_mex_assign(&c17_e_y, sf_mex_create("y", &c17_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 3, c17_e_y);
  sf_mex_assign(&c17_st, c17_y, false);
  return c17_st;
}

static void set_sim_state_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_st)
{
  const mxArray *c17_u;
  chartInstance->c17_doneDoubleBufferReInit = true;
  c17_u = sf_mex_dup(c17_st);
  *chartInstance->c17_ber = c17_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c17_u, 0)), "ber");
  *chartInstance->c17_error = c17_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c17_u, 1)), "error");
  *chartInstance->c17_send_out = c17_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c17_u, 2)), "send_out");
  chartInstance->c17_is_active_c17_AWGN_SNR_test = c17_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 3)),
     "is_active_c17_AWGN_SNR_test");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_AWGN_SNR_test(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  boolean_T c17_hoistedGlobal;
  boolean_T c17_b_hoistedGlobal;
  real_T c17_c_hoistedGlobal;
  boolean_T c17_b_send;
  boolean_T c17_b_recv;
  real_T c17_b_rst;
  uint32_T c17_debug_family_var_map[8];
  real_T c17_nargin = 3.0;
  real_T c17_nargout = 3.0;
  real_T c17_b_send_out;
  real_T c17_b_error;
  real_T c17_b_ber;
  real_T c17_d_hoistedGlobal;
  real_T c17_e_hoistedGlobal;
  real_T c17_A;
  real_T c17_B;
  real_T c17_x;
  real_T c17_y;
  real_T c17_b_x;
  real_T c17_b_y;
  real_T c17_c_x;
  real_T c17_c_y;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c17_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c17_send, 0U);
  chartInstance->c17_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c17_sfEvent);
  c17_hoistedGlobal = *chartInstance->c17_send;
  c17_b_hoistedGlobal = *chartInstance->c17_recv;
  c17_c_hoistedGlobal = *chartInstance->c17_rst;
  c17_b_send = c17_hoistedGlobal;
  c17_b_recv = c17_b_hoistedGlobal;
  c17_b_rst = c17_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 0U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 1U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_b_send, 2U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_b_recv, 3U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_b_rst, 4U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_send_out, 5U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_error, 6U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_ber, 7U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 7);
  c17_set_send_r(chartInstance, 0, c17_get_send_r(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, (int32_T)c17_b_send != (int32_T)c17_b_recv)) {
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 10);
    c17_set_error_r(chartInstance, 0, c17_get_error_r(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 11);
    c17_d_hoistedGlobal = c17_get_error_r(chartInstance, 0);
    c17_e_hoistedGlobal = c17_get_send_r(chartInstance, 0);
    c17_A = c17_d_hoistedGlobal;
    c17_B = c17_e_hoistedGlobal;
    c17_x = c17_A;
    c17_y = c17_B;
    c17_b_x = c17_x;
    c17_b_y = c17_y;
    c17_c_x = c17_b_x;
    c17_c_y = c17_b_y;
    c17_set_ber_r(chartInstance, 0, c17_c_x / c17_c_y);
    ssUpdateDataStoreLog(chartInstance->S, 0);
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 15);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c17_b_rst, 1.0, -1, 0U,
        c17_b_rst == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 16);
    c17_set_ber_r(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 17);
    c17_set_send_r(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 18);
    c17_set_error_r(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 21);
  c17_b_send_out = c17_get_send_r(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 22);
  c17_b_error = c17_get_error_r(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 23);
  c17_b_ber = c17_get_ber_r(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -23);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c17_send_out = c17_b_send_out;
  *chartInstance->c17_error = c17_b_error;
  *chartInstance->c17_ber = c17_b_ber;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c17_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AWGN_SNR_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c17_send_out, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c17_error, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c17_recv, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c17_ber, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c17_rst, 8U);
}

static void mdl_start_c17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc17_AWGN_SNR_test(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber)
{
  (void)c17_machineNumber;
  (void)c17_chartNumber;
  (void)c17_instanceNumber;
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_AWGN_SNR_testInstanceStruct *chartInstance;
  chartInstance = (SFc17_AWGN_SNR_testInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static real_T c17_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_b_ber, const char_T *c17_identifier)
{
  real_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_ber),
    &c17_thisId);
  sf_mex_destroy(&c17_b_ber);
  return c17_y;
}

static real_T c17_b_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_ber;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_AWGN_SNR_testInstanceStruct *chartInstance;
  chartInstance = (SFc17_AWGN_SNR_testInstanceStruct *)chartInstanceVoid;
  c17_b_ber = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_ber),
    &c17_thisId);
  sf_mex_destroy(&c17_b_ber);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  boolean_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_AWGN_SNR_testInstanceStruct *chartInstance;
  chartInstance = (SFc17_AWGN_SNR_testInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(boolean_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

const mxArray *sf_c17_AWGN_SNR_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c17_info_helper(&c17_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c17_nameCaptureInfo);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(const mxArray **c17_info)
{
  const mxArray *c17_rhs0 = NULL;
  const mxArray *c17_lhs0 = NULL;
  const mxArray *c17_rhs1 = NULL;
  const mxArray *c17_lhs1 = NULL;
  const mxArray *c17_rhs2 = NULL;
  const mxArray *c17_lhs2 = NULL;
  const mxArray *c17_rhs3 = NULL;
  const mxArray *c17_lhs3 = NULL;
  const mxArray *c17_rhs4 = NULL;
  const mxArray *c17_lhs4 = NULL;
  const mxArray *c17_rhs5 = NULL;
  const mxArray *c17_lhs5 = NULL;
  const mxArray *c17_rhs6 = NULL;
  const mxArray *c17_lhs6 = NULL;
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c17_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c17_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c17_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c17_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c17_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c17_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c17_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c17_rhs0);
  sf_mex_destroy(&c17_lhs0);
  sf_mex_destroy(&c17_rhs1);
  sf_mex_destroy(&c17_lhs1);
  sf_mex_destroy(&c17_rhs2);
  sf_mex_destroy(&c17_lhs2);
  sf_mex_destroy(&c17_rhs3);
  sf_mex_destroy(&c17_lhs3);
  sf_mex_destroy(&c17_rhs4);
  sf_mex_destroy(&c17_lhs4);
  sf_mex_destroy(&c17_rhs5);
  sf_mex_destroy(&c17_lhs5);
  sf_mex_destroy(&c17_rhs6);
  sf_mex_destroy(&c17_lhs6);
}

static const mxArray *c17_emlrt_marshallOut(const char * c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c17_u)), false);
  return c17_y;
}

static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 7, 0U, 0U, 0U, 0), false);
  return c17_y;
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_AWGN_SNR_testInstanceStruct *chartInstance;
  chartInstance = (SFc17_AWGN_SNR_testInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static int32_T c17_c_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i0, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_AWGN_SNR_testInstanceStruct *chartInstance;
  chartInstance = (SFc17_AWGN_SNR_testInstanceStruct *)chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_d_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_AWGN_SNR_test, const char_T
  *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_AWGN_SNR_test), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_AWGN_SNR_test);
  return c17_y;
}

static uint8_T c17_e_emlrt_marshallIn(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static real_T c17_get_ber_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c17_elementIndex);
  return *chartInstance->c17_ber_r_address;
}

static void c17_set_ber_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex, real_T c17_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c17_elementIndex);
  *chartInstance->c17_ber_r_address = c17_elementValue;
}

static real_T *c17_access_ber_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_rdOnly)
{
  real_T *c17_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c17_dsmAddr = chartInstance->c17_ber_r_address;
  if (c17_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c17_dsmAddr;
}

static real_T c17_get_error_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c17_elementIndex);
  return *chartInstance->c17_error_r_address;
}

static void c17_set_error_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex, real_T c17_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c17_elementIndex);
  *chartInstance->c17_error_r_address = c17_elementValue;
}

static real_T *c17_access_error_r(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, uint32_T c17_rdOnly)
{
  real_T *c17_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c17_dsmAddr = chartInstance->c17_error_r_address;
  if (c17_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c17_dsmAddr;
}

static real_T c17_get_send_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c17_elementIndex);
  return *chartInstance->c17_send_r_address;
}

static void c17_set_send_r(SFc17_AWGN_SNR_testInstanceStruct *chartInstance,
  uint32_T c17_elementIndex, real_T c17_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c17_elementIndex);
  *chartInstance->c17_send_r_address = c17_elementValue;
}

static real_T *c17_access_send_r(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance, uint32_T c17_rdOnly)
{
  real_T *c17_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c17_dsmAddr = chartInstance->c17_send_r_address;
  if (c17_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c17_dsmAddr;
}

static void init_dsm_address_info(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "ber_r", (void **)
    &chartInstance->c17_ber_r_address, &chartInstance->c17_ber_r_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "error_r", (void **)
    &chartInstance->c17_error_r_address, &chartInstance->c17_error_r_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "send_r", (void **)
    &chartInstance->c17_send_r_address, &chartInstance->c17_send_r_index);
}

static void init_simulink_io_address(SFc17_AWGN_SNR_testInstanceStruct
  *chartInstance)
{
  chartInstance->c17_send = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c17_send_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c17_error = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c17_recv = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c17_ber = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c17_rst = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c17_AWGN_SNR_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(79110751U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(981149813U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2115592244U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1807905308U);
}

mxArray* sf_c17_AWGN_SNR_test_get_post_codegen_info(void);
mxArray *sf_c17_AWGN_SNR_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MXgfhsmsmKrs5ZR39pW3HH");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
    mxArray* mxPostCodegenInfo = sf_c17_AWGN_SNR_test_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c17_AWGN_SNR_test_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_AWGN_SNR_test_jit_fallback_info(void)
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

mxArray *sf_c17_AWGN_SNR_test_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c17_AWGN_SNR_test_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c17_AWGN_SNR_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[40],T\"ber\",},{M[1],M[6],T\"error\",},{M[1],M[10],T\"send_out\",},{M[8],M[0],T\"is_active_c17_AWGN_SNR_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_AWGN_SNR_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_AWGN_SNR_testInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc17_AWGN_SNR_testInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AWGN_SNR_testMachineNumber_,
           17,
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
        init_script_number_translation(_AWGN_SNR_testMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_AWGN_SNR_testMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _AWGN_SNR_testMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"send");
          _SFD_SET_DATA_PROPS(1,2,0,1,"send_out");
          _SFD_SET_DATA_PROPS(2,2,0,1,"error");
          _SFD_SET_DATA_PROPS(3,1,1,0,"recv");
          _SFD_SET_DATA_PROPS(4,11,0,0,"ber_r");
          _SFD_SET_DATA_PROPS(5,11,0,0,"send_r");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,313);
        _SFD_CV_INIT_EML_IF(0,1,0,127,142,-1,199);
        _SFD_CV_INIT_EML_IF(0,1,1,202,213,-1,259);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,205,213,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c17_send);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c17_send_out);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c17_error);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c17_recv);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c17_ber_r_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c17_send_r_address);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c17_error_r_address);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c17_ber);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c17_rst);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AWGN_SNR_testMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ueAqqMJ0uWaJe1EyOoV7yF";
}

static void sf_opaque_initialize_c17_AWGN_SNR_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_AWGN_SNR_testInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
    chartInstanceVar);
  initialize_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c17_AWGN_SNR_test(void *chartInstanceVar)
{
  enable_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_AWGN_SNR_test(void *chartInstanceVar)
{
  disable_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c17_AWGN_SNR_test(void *chartInstanceVar)
{
  sf_gateway_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c17_AWGN_SNR_test(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c17_AWGN_SNR_test(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c17_AWGN_SNR_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_AWGN_SNR_testInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AWGN_SNR_test_optimization_info();
    }

    finalize_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
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
  initSimStructsc17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_AWGN_SNR_test(SimStruct *S)
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
    initialize_params_c17_AWGN_SNR_test((SFc17_AWGN_SNR_testInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_AWGN_SNR_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AWGN_SNR_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,17,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3143753163U));
  ssSetChecksum1(S,(4097917599U));
  ssSetChecksum2(S,(3233771803U));
  ssSetChecksum3(S,(1500344549U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c17_AWGN_SNR_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_AWGN_SNR_test(SimStruct *S)
{
  SFc17_AWGN_SNR_testInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc17_AWGN_SNR_testInstanceStruct *)utMalloc(sizeof
    (SFc17_AWGN_SNR_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_AWGN_SNR_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_AWGN_SNR_test;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_AWGN_SNR_test;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_AWGN_SNR_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c17_AWGN_SNR_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c17_AWGN_SNR_test;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_AWGN_SNR_test;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_AWGN_SNR_test;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_AWGN_SNR_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_AWGN_SNR_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_AWGN_SNR_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c17_AWGN_SNR_test;
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

void c17_AWGN_SNR_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_AWGN_SNR_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_AWGN_SNR_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_AWGN_SNR_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_AWGN_SNR_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
