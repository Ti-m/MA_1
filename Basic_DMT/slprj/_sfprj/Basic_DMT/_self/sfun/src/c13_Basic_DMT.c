/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c13_Basic_DMT.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Basic_DMT_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c13_b_fftLenActive             (32.0)
#define c13_b_GI_Active                (8.0)
#define c13_b_bitPerSymb               (4.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c13_debug_family_names[14] = { "conPush", "conPop",
  "fftLenActive", "GI_Active", "bitPerSymb", "nargin", "nargout", "num",
  "frameEn", "chanDownFact", "sel", "push", "pop", "frameStart" };

/* Function Declarations */
static void initialize_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance);
static void initialize_params_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *chartInstance);
static void disable_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_Basic_DMT
  (SFc13_Basic_DMTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *
  chartInstance);
static void set_sim_state_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_st);
static void finalize_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance);
static void mdl_start_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *chartInstance);
static void c13_chartstep_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance);
static void initSimStructsc13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c13_b_frameStart, const char_T *c13_identifier);
static real_T c13_b_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_c_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_d_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_Basic_DMT, const char_T
  *c13_identifier);
static uint8_T c13_e_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static real_T c13_get_loopCount(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex);
static void c13_set_loopCount(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex, real_T c13_elementValue);
static real_T *c13_access_loopCount(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_rdOnly);
static real_T c13_get_loopOut(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex);
static void c13_set_loopOut(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex, real_T c13_elementValue);
static real_T *c13_access_loopOut(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_rdOnly);
static real_T c13_get_outputBitCount(SFc13_Basic_DMTInstanceStruct
  *chartInstance, uint32_T c13_elementIndex);
static void c13_set_outputBitCount(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex, real_T c13_elementValue);
static real_T *c13_access_outputBitCount(SFc13_Basic_DMTInstanceStruct
  *chartInstance, uint32_T c13_rdOnly);
static real_T c13_get_start(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex);
static void c13_set_start(SFc13_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c13_elementIndex, real_T c13_elementValue);
static real_T *c13_access_start(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_rdOnly);
static real_T c13_get_state(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex);
static void c13_set_state(SFc13_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c13_elementIndex, real_T c13_elementValue);
static real_T *c13_access_state(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_rdOnly);
static void init_dsm_address_info(SFc13_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc13_Basic_DMTInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_is_active_c13_Basic_DMT = 0U;
}

static void initialize_params_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c13_d0;
  real_T c13_d1;
  real_T c13_d2;
  real_T c13_d3;
  sf_mex_import_named("fftLenActive", sf_mex_get_sfun_param(chartInstance->S, 3,
    0), &c13_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c13_fftLenActive = c13_d0;
  sf_mex_import_named("GI_Active", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c13_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c13_GI_Active = c13_d1;
  sf_mex_import_named("chanDownFact", sf_mex_get_sfun_param(chartInstance->S, 2,
    0), &c13_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c13_chanDownFact = c13_d2;
  sf_mex_import_named("bitPerSymb", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c13_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c13_bitPerSymb = c13_d3;
}

static void enable_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c13_update_debugger_state_c13_Basic_DMT
  (SFc13_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *
  chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  real_T c13_hoistedGlobal;
  real_T c13_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_b_hoistedGlobal;
  real_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_c_hoistedGlobal;
  real_T c13_c_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_d_hoistedGlobal;
  real_T c13_d_u;
  const mxArray *c13_e_y = NULL;
  uint8_T c13_e_hoistedGlobal;
  uint8_T c13_e_u;
  const mxArray *c13_f_y = NULL;
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(5, 1), false);
  c13_hoistedGlobal = *chartInstance->c13_frameStart;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = *chartInstance->c13_pop;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_c_hoistedGlobal = *chartInstance->c13_push;
  c13_c_u = c13_c_hoistedGlobal;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 2, c13_d_y);
  c13_d_hoistedGlobal = *chartInstance->c13_sel;
  c13_d_u = c13_d_hoistedGlobal;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 3, c13_e_y);
  c13_e_hoistedGlobal = chartInstance->c13_is_active_c13_Basic_DMT;
  c13_e_u = c13_e_hoistedGlobal;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 4, c13_f_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  chartInstance->c13_doneDoubleBufferReInit = true;
  c13_u = sf_mex_dup(c13_st);
  *chartInstance->c13_frameStart = c13_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 0)), "frameStart");
  *chartInstance->c13_pop = c13_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 1)), "pop");
  *chartInstance->c13_push = c13_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 2)), "push");
  *chartInstance->c13_sel = c13_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 3)), "sel");
  chartInstance->c13_is_active_c13_Basic_DMT = c13_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 4)),
     "is_active_c13_Basic_DMT");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_Basic_DMT(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c13_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c13_num, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c13_frameEn, 1U);
  chartInstance->c13_sfEvent = CALL_EVENT;
  c13_chartstep_c13_Basic_DMT(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c13_sel, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c13_push, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c13_pop, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c13_frameStart, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c13_fftLenActive, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c13_GI_Active, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c13_chanDownFact, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c13_bitPerSymb, 14U);
}

static void mdl_start_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_chartstep_c13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance)
{
  uint32_T c13_hoistedGlobal;
  real_T c13_b_hoistedGlobal;
  real_T c13_c_hoistedGlobal;
  uint32_T c13_b_num;
  real_T c13_b_frameEn;
  real_T c13_b_chanDownFact;
  uint32_T c13_debug_family_var_map[14];
  real_T c13_conPush;
  real_T c13_conPop;
  real_T c13_c_fftLenActive;
  real_T c13_c_GI_Active;
  real_T c13_c_bitPerSymb;
  real_T c13_nargin = 6.0;
  real_T c13_nargout = 4.0;
  real_T c13_b_sel;
  real_T c13_b_push;
  real_T c13_b_pop;
  real_T c13_b_frameStart;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c13_sfEvent);
  c13_hoistedGlobal = *chartInstance->c13_num;
  c13_b_hoistedGlobal = *chartInstance->c13_frameEn;
  c13_c_hoistedGlobal = chartInstance->c13_chanDownFact;
  c13_b_num = c13_hoistedGlobal;
  c13_b_frameEn = c13_b_hoistedGlobal;
  c13_b_chanDownFact = c13_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_conPush, 0U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_conPop, 1U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_c_fftLenActive, 2U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_c_GI_Active, 3U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_c_bitPerSymb, 4U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 5U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 6U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_b_num, 7U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_b_frameEn, 8U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_chanDownFact, 9U,
    c13_sf_marshallOut, c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_sel, 10U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_push, 11U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_pop, 12U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_frameStart, 13U,
    c13_sf_marshallOut, c13_sf_marshallIn);
  c13_c_bitPerSymb = c13_b_bitPerSymb;
  c13_c_GI_Active = c13_b_GI_Active;
  c13_c_fftLenActive = c13_b_fftLenActive;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 10);
  switch ((int32_T)_SFD_INTEGER_CHECK("state", c13_get_state(chartInstance, 0)))
  {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 12);
    c13_b_sel = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 13);
    c13_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 14);
    c13_b_push = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 15);
    c13_b_frameStart = 0.0;
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 19);
    c13_b_sel = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 20);
    c13_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 21);
    c13_b_push = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 22);
    c13_b_frameStart = 0.0;
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 25);
    c13_b_sel = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 26);
    c13_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 27);
    c13_b_push = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 28);
    c13_b_frameStart = 0.0;
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 31);
    c13_b_sel = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 32);
    c13_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 33);
    c13_b_push = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 34);
    c13_b_frameStart = 0.0;
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 37);
    c13_b_sel = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 38);
    c13_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 39);
    c13_b_push = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 40);
    c13_b_frameStart = 0.0;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 43);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c13_get_loopCount
        (chartInstance, 0), 1.0, -1, 0U, c13_get_loopCount(chartInstance, 0) ==
        1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 44);
    c13_conPush = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 46);
    c13_conPush = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 48);
  c13_set_loopCount(chartInstance, 0, c13_get_loopCount(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 49);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c13_get_loopCount
        (chartInstance, 0), c13_b_chanDownFact, -1, 5U, c13_get_loopCount
        (chartInstance, 0) >= c13_b_chanDownFact))) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 50);
    c13_set_loopCount(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 53);
  c13_conPop = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 54);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  guard6 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 2, (real_T)c13_b_num, 40.0,
        -1, 5U, (real_T)c13_b_num >= 40.0))) {
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 3,
          c13_get_outputBitCount(chartInstance, 0), 0.0, -1, 0U,
          c13_get_outputBitCount(chartInstance, 0) == 0.0))) {
      if (CV_EML_COND(0, 1, 2, c13_b_frameEn != 0.0)) {
        guard4 = true;
      } else if (CV_EML_COND(0, 1, 3, c13_get_start(chartInstance, 0) != 0.0)) {
        guard4 = true;
      } else {
        guard5 = true;
      }
    } else {
      guard6 = true;
    }
  } else {
    guard6 = true;
  }

  if (guard6 == true) {
    guard5 = true;
  }

  if (guard5 == true) {
    if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4,
          c13_get_outputBitCount(chartInstance, 0), 0.0, -1, 4U,
          c13_get_outputBitCount(chartInstance, 0) > 0.0))) {
      if (CV_EML_COND(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5,
            c13_get_outputBitCount(chartInstance, 0), 40.0, -1, 3U,
            c13_get_outputBitCount(chartInstance, 0) <= 40.0))) {
        if (CV_EML_COND(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, c13_get_loopOut
              (chartInstance, 0), 0.0, -1, 0U, c13_get_loopOut(chartInstance, 0)
              == 0.0))) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
  }

  if (guard4 == true) {
    guard2 = true;
  }

  if (guard3 == true) {
    guard1 = true;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 2, true);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 55);
    c13_set_start(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 56);
    guard7 = false;
    if (CV_EML_COND(0, 1, 7, c13_b_frameEn != 0.0)) {
      if (CV_EML_COND(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 7,
            c13_get_outputBitCount(chartInstance, 0), 0.0, -1, 0U,
            c13_get_outputBitCount(chartInstance, 0) == 0.0))) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 3, true);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 57);
        c13_b_frameStart = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 58);
        c13_set_loopOut(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 1);
      } else {
        guard7 = true;
      }
    } else {
      guard7 = true;
    }

    if (guard7 == true) {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 3, false);
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 61);
    c13_conPop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 62);
    c13_set_outputBitCount(chartInstance, 0, c13_get_outputBitCount
      (chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 2, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 67);
  c13_set_loopOut(chartInstance, 0, c13_get_loopOut(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 68);
  if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 8, c13_get_loopOut
        (chartInstance, 0), c13_b_bitPerSymb, -1, 5U, c13_get_loopOut
        (chartInstance, 0) >= c13_b_bitPerSymb))) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 69);
    c13_set_loopOut(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 72);
  if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 9, c13_get_outputBitCount
        (chartInstance, 0), 40.0, -1, 5U, c13_get_outputBitCount(chartInstance,
         0) >= 40.0))) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 73);
    c13_set_outputBitCount(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 74);
    c13_set_start(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 77);
  if (CV_EML_IF(0, 1, 6, c13_conPop != 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 78);
    if (CV_EML_IF(0, 1, 7, c13_conPush != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 79);
      c13_set_state(chartInstance, 0, 3.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 81);
      c13_set_state(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 84);
    if (CV_EML_IF(0, 1, 8, c13_conPush != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 85);
      c13_set_state(chartInstance, 0, 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 87);
      c13_set_state(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -87);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c13_sel = c13_b_sel;
  *chartInstance->c13_push = c13_b_push;
  *chartInstance->c13_pop = c13_b_pop;
  *chartInstance->c13_frameStart = c13_b_frameStart;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c13_sfEvent);
}

static void initSimStructsc13_Basic_DMT(SFc13_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber)
{
  (void)c13_machineNumber;
  (void)c13_chartNumber;
  (void)c13_instanceNumber;
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc13_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c13_b_frameStart, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_frameStart),
    &c13_thisId);
  sf_mex_destroy(&c13_b_frameStart);
  return c13_y;
}

static real_T c13_b_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d4;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d4, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d4;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_frameStart;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc13_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c13_b_frameStart = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_frameStart),
    &c13_thisId);
  sf_mex_destroy(&c13_b_frameStart);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  uint32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc13_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(uint32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

const mxArray *sf_c13_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc13_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int32_T c13_c_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i0, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc13_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_d_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_Basic_DMT, const char_T
  *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_Basic_DMT), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_Basic_DMT);
  return c13_y;
}

static uint8_T c13_e_emlrt_marshallIn(SFc13_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static real_T c13_get_loopCount(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c13_elementIndex);
  return *chartInstance->c13_loopCount_address;
}

static void c13_set_loopCount(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex, real_T c13_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c13_elementIndex);
  *chartInstance->c13_loopCount_address = c13_elementValue;
}

static real_T *c13_access_loopCount(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_rdOnly)
{
  real_T *c13_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c13_dsmAddr = chartInstance->c13_loopCount_address;
  if (c13_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c13_dsmAddr;
}

static real_T c13_get_loopOut(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c13_elementIndex);
  return *chartInstance->c13_loopOut_address;
}

static void c13_set_loopOut(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex, real_T c13_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c13_elementIndex);
  *chartInstance->c13_loopOut_address = c13_elementValue;
}

static real_T *c13_access_loopOut(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_rdOnly)
{
  real_T *c13_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c13_dsmAddr = chartInstance->c13_loopOut_address;
  if (c13_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c13_dsmAddr;
}

static real_T c13_get_outputBitCount(SFc13_Basic_DMTInstanceStruct
  *chartInstance, uint32_T c13_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c13_elementIndex);
  return *chartInstance->c13_outputBitCount_address;
}

static void c13_set_outputBitCount(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex, real_T c13_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c13_elementIndex);
  *chartInstance->c13_outputBitCount_address = c13_elementValue;
}

static real_T *c13_access_outputBitCount(SFc13_Basic_DMTInstanceStruct
  *chartInstance, uint32_T c13_rdOnly)
{
  real_T *c13_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c13_dsmAddr = chartInstance->c13_outputBitCount_address;
  if (c13_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c13_dsmAddr;
}

static real_T c13_get_start(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 3, NULL, c13_elementIndex);
  return *chartInstance->c13_start_address;
}

static void c13_set_start(SFc13_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c13_elementIndex, real_T c13_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 3, NULL, c13_elementIndex);
  *chartInstance->c13_start_address = c13_elementValue;
}

static real_T *c13_access_start(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_rdOnly)
{
  real_T *c13_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 3, NULL);
  c13_dsmAddr = chartInstance->c13_start_address;
  if (c13_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 3, NULL);
  }

  return c13_dsmAddr;
}

static real_T c13_get_state(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 4, NULL, c13_elementIndex);
  return *chartInstance->c13_state_address;
}

static void c13_set_state(SFc13_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c13_elementIndex, real_T c13_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 4, NULL, c13_elementIndex);
  *chartInstance->c13_state_address = c13_elementValue;
}

static real_T *c13_access_state(SFc13_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c13_rdOnly)
{
  real_T *c13_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 4, NULL);
  c13_dsmAddr = chartInstance->c13_state_address;
  if (c13_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 4, NULL);
  }

  return c13_dsmAddr;
}

static void init_dsm_address_info(SFc13_Basic_DMTInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "loopCount", (void **)
    &chartInstance->c13_loopCount_address, &chartInstance->c13_loopCount_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "loopOut", (void **)
    &chartInstance->c13_loopOut_address, &chartInstance->c13_loopOut_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "outputBitCount",
    (void **)&chartInstance->c13_outputBitCount_address,
    &chartInstance->c13_outputBitCount_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "start", (void **)
    &chartInstance->c13_start_address, &chartInstance->c13_start_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "state", (void **)
    &chartInstance->c13_state_address, &chartInstance->c13_state_index);
}

static void init_simulink_io_address(SFc13_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c13_num = (uint32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c13_frameEn = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c13_sel = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c13_push = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c13_pop = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c13_frameStart = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
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

void sf_c13_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1530755036U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1190690576U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1991335832U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2595762580U);
}

mxArray* sf_c13_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c13_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("oJ6Gta3KSy8dFIuwJpfAoD");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c13_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c13_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c13_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c13_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[38],T\"frameStart\",},{M[1],M[6],T\"pop\",},{M[1],M[10],T\"push\",},{M[1],M[5],T\"sel\",},{M[8],M[0],T\"is_active_c13_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc13_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           13,
           1,
           1,
           0,
           15,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"num");
          _SFD_SET_DATA_PROPS(1,1,1,0,"frameEn");
          _SFD_SET_DATA_PROPS(2,2,0,1,"sel");
          _SFD_SET_DATA_PROPS(3,2,0,1,"push");
          _SFD_SET_DATA_PROPS(4,2,0,1,"pop");
          _SFD_SET_DATA_PROPS(5,11,0,0,"outputBitCount");
          _SFD_SET_DATA_PROPS(6,11,0,0,"state");
          _SFD_SET_DATA_PROPS(7,11,0,0,"loopCount");
          _SFD_SET_DATA_PROPS(8,11,0,0,"loopOut");
          _SFD_SET_DATA_PROPS(9,11,0,0,"start");
          _SFD_SET_DATA_PROPS(10,2,0,1,"frameStart");
          _SFD_SET_DATA_PROPS(11,10,0,0,"fftLenActive");
          _SFD_SET_DATA_PROPS(12,10,0,0,"GI_Active");
          _SFD_SET_DATA_PROPS(13,10,0,0,"chanDownFact");
          _SFD_SET_DATA_PROPS(14,10,0,0,"bitPerSymb");
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
        _SFD_CV_INIT_EML(0,1,1,9,0,0,1,0,0,9,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1493);
        _SFD_CV_INIT_EML_IF(0,1,0,666,683,704,727);
        _SFD_CV_INIT_EML_IF(0,1,1,754,782,-1,811);
        _SFD_CV_INIT_EML_IF(0,1,2,825,989,-1,1161);
        _SFD_CV_INIT_EML_IF(0,1,3,1007,1038,-1,1089);
        _SFD_CV_INIT_EML_IF(0,1,4,1185,1209,-1,1240);
        _SFD_CV_INIT_EML_IF(0,1,5,1244,1287,-1,1326);
        _SFD_CV_INIT_EML_IF(0,1,6,1328,1337,1408,1486);
        _SFD_CV_INIT_EML_IF(0,1,7,1342,1352,1376,1407);
        _SFD_CV_INIT_EML_IF(0,1,8,1417,1427,1451,1482);

        {
          static int caseStart[] = { 589, 234, 313, 411, 500 };

          static int caseExprEnd[] = { 598, 240, 319, 417, 506 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,217,230,664,5,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 830, 865, 887, 898, 910, 930, 975 };

          static int condEnd[] = { 861, 882, 894, 903, 926, 971, 987 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -2, -3, 4, 5, -3, 6, -3, -2
          };

          _SFD_CV_INIT_EML_MCDC(0,1,0,829,988,7,0,&(condStart[0]),&(condEnd[0]),
                                13,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1010, 1021 };

          static int condEnd[] = { 1017, 1038 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1010,1038,2,7,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,669,683,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,757,782,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,830,861,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,865,882,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,910,926,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,930,971,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,975,987,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,1021,1038,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,8,1188,1209,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,9,1247,1287,-1,5);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c13_num);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c13_frameEn);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c13_sel);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c13_push);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c13_pop);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c13_outputBitCount_address);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c13_state_address);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c13_loopCount_address);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c13_loopOut_address);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c13_start_address);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c13_frameStart);
        _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c13_fftLenActive);
        _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c13_GI_Active);
        _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c13_chanDownFact);
        _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c13_bitPerSymb);
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
  return "apWkzRJylZe8dOk6eS6SOB";
}

static void sf_opaque_initialize_c13_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c13_Basic_DMT(void *chartInstanceVar)
{
  enable_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c13_Basic_DMT(void *chartInstanceVar)
{
  disable_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c13_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c13_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c13_Basic_DMT(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c13_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_Basic_DMT(SimStruct *S)
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
    initialize_params_c13_Basic_DMT((SFc13_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_Basic_DMT(SimStruct *S)
{
  /* Actual parameters from chart:
     GI_Active bitPerSymb chanDownFact fftLenActive
   */
  const char_T *rtParamNames[] = { "GI_Active", "bitPerSymb", "chanDownFact",
    "fftLenActive" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for GI_Active*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for bitPerSymb*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for chanDownFact*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for fftLenActive*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,13,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1719944293U));
  ssSetChecksum1(S,(2596214093U));
  ssSetChecksum2(S,(552402715U));
  ssSetChecksum3(S,(3590202294U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c13_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_Basic_DMT(SimStruct *S)
{
  SFc13_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc13_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc13_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c13_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c13_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c13_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c13_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c13_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c13_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c13_Basic_DMT;
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

void c13_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
