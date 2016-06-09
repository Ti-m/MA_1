/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c4_Basic_DMT.h"
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
static const char * c4_debug_family_names[8] = { "conPush", "conPop", "nargin",
  "nargout", "push_en", "chanDownFact", "push", "pop" };

/* Function Declarations */
static void initialize_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance);
static void initialize_params_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance);
static void disable_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance);
static void set_sim_state_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance);
static void mdl_start_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance);
static void initSimStructsc4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_b_pop, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_c_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_d_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_Basic_DMT, const char_T *c4_identifier);
static uint8_T c4_e_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static real_T c4_get_loopCount(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_elementIndex);
static void c4_set_loopCount(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_elementIndex, real_T c4_elementValue);
static real_T *c4_access_loopCount(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_rdOnly);
static real_T c4_get_popEn(SFc4_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c4_elementIndex);
static void c4_set_popEn(SFc4_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c4_elementIndex, real_T c4_elementValue);
static real_T *c4_access_popEn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_rdOnly);
static real_T c4_get_state(SFc4_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c4_elementIndex);
static void c4_set_state(SFc4_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c4_elementIndex, real_T c4_elementValue);
static real_T *c4_access_state(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_rdOnly);
static void init_dsm_address_info(SFc4_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_Basic_DMTInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_Basic_DMT = 0U;
}

static void initialize_params_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c4_d0;
  sf_mex_import_named("chanDownFact", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c4_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_chanDownFact = c4_d0;
}

static void enable_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  uint8_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(3, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_pop;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *chartInstance->c4_push;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = chartInstance->c4_is_active_c4_Basic_DMT;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_pop = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "pop");
  *chartInstance->c4_push = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "push");
  chartInstance->c4_is_active_c4_Basic_DMT = c4_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 2)), "is_active_c4_Basic_DMT");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_Basic_DMT(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_push_en;
  real_T c4_b_chanDownFact;
  uint32_T c4_debug_family_var_map[8];
  real_T c4_conPush;
  real_T c4_conPop;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 2.0;
  real_T c4_b_push;
  real_T c4_b_pop;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_push_en, 0U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *chartInstance->c4_push_en;
  c4_b_hoistedGlobal = chartInstance->c4_chanDownFact;
  c4_b_push_en = c4_hoistedGlobal;
  c4_b_chanDownFact = c4_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_conPush, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_conPop, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_push_en, 4U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_chanDownFact, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_push, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_pop, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  switch ((int32_T)_SFD_INTEGER_CHECK("state", c4_get_state(chartInstance, 0)))
  {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
    c4_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
    c4_b_push = 1.0;
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
    c4_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
    c4_b_push = 1.0;
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
    c4_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
    c4_b_push = 0.0;
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
    c4_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
    c4_b_push = 0.0;
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
    c4_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
    c4_b_push = 0.0;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
  if (CV_EML_IF(0, 1, 0, c4_b_push_en != 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
    c4_conPush = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
    c4_set_popEn(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 29);
    c4_conPush = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c4_get_loopCount
        (chartInstance, 0), 0.0, -1, 0U, c4_get_loopCount(chartInstance, 0) ==
        0.0))) {
    if (CV_EML_COND(0, 1, 1, c4_get_popEn(chartInstance, 0) != 0.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 1, true);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 33);
      c4_conPop = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 1, false);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 35);
    c4_conPop = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 38);
  c4_set_loopCount(chartInstance, 0, c4_get_loopCount(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 39);
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 1, c4_get_loopCount
        (chartInstance, 0), c4_b_chanDownFact, -1, 5U, c4_get_loopCount
        (chartInstance, 0) >= c4_b_chanDownFact))) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 40);
    c4_set_loopCount(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
  if (CV_EML_IF(0, 1, 3, c4_conPush != 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 45);
    if (CV_EML_IF(0, 1, 4, c4_conPop != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 46);
      c4_set_state(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 2);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 48);
      c4_set_state(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 2);
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 52);
    if (CV_EML_IF(0, 1, 5, c4_conPop != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 53);
      c4_set_state(chartInstance, 0, 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 2);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 55);
      c4_set_state(chartInstance, 0, 3.0);
      ssUpdateDataStoreLog(chartInstance->S, 2);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -55);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c4_push = c4_b_push;
  *chartInstance->c4_pop = c4_b_pop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_push, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_pop, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_chanDownFact, 6U);
}

static void mdl_start_c4_Basic_DMT(SFc4_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc4_Basic_DMT(SFc4_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc4_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_b_pop, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_pop), &c4_thisId);
  sf_mex_destroy(&c4_b_pop);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_pop;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc4_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c4_b_pop = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_pop), &c4_thisId);
  sf_mex_destroy(&c4_b_pop);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc4_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_c_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i0, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc4_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_Basic_DMT, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Basic_DMT), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Basic_DMT);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static real_T c4_get_loopCount(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c4_elementIndex);
  return *chartInstance->c4_loopCount_address;
}

static void c4_set_loopCount(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_elementIndex, real_T c4_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c4_elementIndex);
  *chartInstance->c4_loopCount_address = c4_elementValue;
}

static real_T *c4_access_loopCount(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_rdOnly)
{
  real_T *c4_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c4_dsmAddr = chartInstance->c4_loopCount_address;
  if (c4_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c4_dsmAddr;
}

static real_T c4_get_popEn(SFc4_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c4_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c4_elementIndex);
  return *chartInstance->c4_popEn_address;
}

static void c4_set_popEn(SFc4_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c4_elementIndex, real_T c4_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c4_elementIndex);
  *chartInstance->c4_popEn_address = c4_elementValue;
}

static real_T *c4_access_popEn(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_rdOnly)
{
  real_T *c4_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c4_dsmAddr = chartInstance->c4_popEn_address;
  if (c4_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c4_dsmAddr;
}

static real_T c4_get_state(SFc4_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c4_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c4_elementIndex);
  return *chartInstance->c4_state_address;
}

static void c4_set_state(SFc4_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c4_elementIndex, real_T c4_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c4_elementIndex);
  *chartInstance->c4_state_address = c4_elementValue;
}

static real_T *c4_access_state(SFc4_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c4_rdOnly)
{
  real_T *c4_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c4_dsmAddr = chartInstance->c4_state_address;
  if (c4_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c4_dsmAddr;
}

static void init_dsm_address_info(SFc4_Basic_DMTInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "loopCount", (void **)
    &chartInstance->c4_loopCount_address, &chartInstance->c4_loopCount_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "popEn", (void **)
    &chartInstance->c4_popEn_address, &chartInstance->c4_popEn_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "state", (void **)
    &chartInstance->c4_state_address, &chartInstance->c4_state_index);
}

static void init_simulink_io_address(SFc4_Basic_DMTInstanceStruct *chartInstance)
{
  chartInstance->c4_push_en = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_push = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_pop = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c4_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2233790078U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3298292740U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2804037583U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1213830573U);
}

mxArray* sf_c4_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c4_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("otQo3G2eH36MufqBIZbbGF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c4_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"pop\",},{M[1],M[10],T\"push\",},{M[8],M[0],T\"is_active_c4_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           4,
           1,
           1,
           0,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"push_en");
          _SFD_SET_DATA_PROPS(1,2,0,1,"push");
          _SFD_SET_DATA_PROPS(2,2,0,1,"pop");
          _SFD_SET_DATA_PROPS(3,11,0,0,"state");
          _SFD_SET_DATA_PROPS(4,11,0,0,"loopCount");
          _SFD_SET_DATA_PROPS(5,11,0,0,"popEn");
          _SFD_SET_DATA_PROPS(6,10,0,0,"chanDownFact");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,0,1,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,763);
        _SFD_CV_INIT_EML_IF(0,1,0,370,380,409,432);
        _SFD_CV_INIT_EML_IF(0,1,1,434,460,477,501);
        _SFD_CV_INIT_EML_IF(0,1,2,529,557,-1,580);
        _SFD_CV_INIT_EML_IF(0,1,3,587,597,668,758);
        _SFD_CV_INIT_EML_IF(0,1,4,602,611,635,666);
        _SFD_CV_INIT_EML_IF(0,1,5,688,697,721,751);

        {
          static int caseStart[] = { 318, 131, 178, 226, 273 };

          static int caseExprEnd[] = { 327, 137, 184, 232, 279 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,114,127,368,5,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 437, 455 };

          static int condEnd[] = { 451, 460 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,437,460,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,437,451,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,532,557,-1,5);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c4_push_en);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c4_push);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c4_pop);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c4_state_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c4_loopCount_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c4_popEn_address);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c4_chanDownFact);
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
  return "6rBYi7wixSdSxToVa8LORD";
}

static void sf_opaque_initialize_c4_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_Basic_DMT(void *chartInstanceVar)
{
  enable_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_Basic_DMT(void *chartInstanceVar)
{
  disable_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_Basic_DMT(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c4_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Basic_DMT(SimStruct *S)
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
    initialize_params_c4_Basic_DMT((SFc4_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_Basic_DMT(SimStruct *S)
{
  /* Actual parameters from chart:
     chanDownFact
   */
  const char_T *rtParamNames[] = { "chanDownFact" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for chanDownFact*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(872044693U));
  ssSetChecksum1(S,(640131461U));
  ssSetChecksum2(S,(1231720644U));
  ssSetChecksum3(S,(1469220082U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c4_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Basic_DMT(SimStruct *S)
{
  SFc4_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc4_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_Basic_DMT;
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

void c4_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
