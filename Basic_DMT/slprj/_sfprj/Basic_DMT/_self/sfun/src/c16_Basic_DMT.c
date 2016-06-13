/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c16_Basic_DMT.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Basic_DMT_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c16_b_u1                       (0.0)
#define c16_b_u2                       (1.0)
#define c16_b_u3                       (1.0)
#define c16_b_u4                       (1.0)
#define c16_b_u5                       (1.0)
#define c16_b_u6                       (1.0)
#define c16_b_u7                       (1.0)
#define c16_b_u8                       (1.0)
#define c16_b_u9                       (0.0)
#define c16_b_u10                      (1.0)
#define c16_b_u11                      (1.0)
#define c16_b_u12                      (1.0)
#define c16_b_u13                      (1.0)
#define c16_b_u14                      (1.0)
#define c16_b_u15                      (1.0)
#define c16_b_u16                      (1.0)
#define c16_b_Tb                       (2.0E-8)
#define c16_b_SystemPeriod             (4.0E-9)
#define c16_b_fftLen                   (16.0)
#define c16_b_GI_Active                (8.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c16_debug_family_names[44] = { "usub1", "usub2", "usub3",
  "usub4", "usub5", "usub6", "usub7", "usub8", "usub9", "usub10", "usub11",
  "usub12", "usub13", "usub14", "usub15", "usub16", "conPop", "conPush",
  "fftLen", "GI_Active", "Tb", "SystemPeriod", "u1", "u2", "u3", "u4", "u5",
  "u6", "u7", "u8", "u9", "u10", "u11", "u12", "u13", "u14", "u15", "u16",
  "nargin", "nargout", "frameEn", "bitPerSymb", "push", "pop" };

/* Function Declarations */
static void initialize_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance);
static void initialize_params_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *chartInstance);
static void disable_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_Basic_DMT
  (SFc16_Basic_DMTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *
  chartInstance);
static void set_sim_state_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_st);
static void finalize_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance);
static void mdl_start_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *chartInstance);
static void c16_chartstep_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance);
static void initSimStructsc16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c16_b_pop, const char_T *c16_identifier);
static real_T c16_b_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_info_helper(const mxArray **c16_info);
static const mxArray *c16_emlrt_marshallOut(const char * c16_u);
static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_c_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_d_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_Basic_DMT, const char_T
  *c16_identifier);
static uint8_T c16_e_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static real_T c16_get_enable(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex);
static void c16_set_enable(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex, real_T c16_elementValue);
static real_T *c16_access_enable(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly);
static real_T c16_get_loopCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex);
static void c16_set_loopCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex, real_T c16_elementValue);
static real_T *c16_access_loopCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly);
static real_T c16_get_start(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex);
static void c16_set_start(SFc16_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c16_elementIndex, real_T c16_elementValue);
static real_T *c16_access_start(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly);
static real_T c16_get_state(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex);
static void c16_set_state(SFc16_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c16_elementIndex, real_T c16_elementValue);
static real_T *c16_access_state(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly);
static real_T c16_get_subCar(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex);
static void c16_set_subCar(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex, real_T c16_elementValue);
static real_T *c16_access_subCar(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly);
static real_T c16_get_subCarCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex);
static void c16_set_subCarCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex, real_T c16_elementValue);
static real_T *c16_access_subCarCount(SFc16_Basic_DMTInstanceStruct
  *chartInstance, uint32_T c16_rdOnly);
static void init_dsm_address_info(SFc16_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc16_Basic_DMTInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c16_is_active_c16_Basic_DMT = 0U;
}

static void initialize_params_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c16_d0;
  real_T c16_d1;
  real_T c16_d2;
  real_T c16_d3;
  real_T c16_d4;
  real_T c16_d5;
  real_T c16_d6;
  real_T c16_d7;
  real_T c16_d8;
  real_T c16_d9;
  real_T c16_d10;
  real_T c16_d11;
  real_T c16_d12;
  real_T c16_d13;
  real_T c16_d14;
  real_T c16_d15;
  real_T c16_d16;
  real_T c16_d17;
  real_T c16_d18;
  real_T c16_d19;
  real_T c16_d20;
  sf_mex_import_named("fftLen", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c16_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_fftLen = c16_d0;
  sf_mex_import_named("GI_Active", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c16_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_GI_Active = c16_d1;
  sf_mex_import_named("bitPerSymb", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c16_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_bitPerSymb = c16_d2;
  sf_mex_import_named("Tb", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c16_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_Tb = c16_d3;
  sf_mex_import_named("SystemPeriod", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c16_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_SystemPeriod = c16_d4;
  sf_mex_import_named("u1", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c16_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u1 = c16_d5;
  sf_mex_import_named("u2", sf_mex_get_sfun_param(chartInstance->S, 13, 0),
                      &c16_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u2 = c16_d6;
  sf_mex_import_named("u3", sf_mex_get_sfun_param(chartInstance->S, 14, 0),
                      &c16_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u3 = c16_d7;
  sf_mex_import_named("u4", sf_mex_get_sfun_param(chartInstance->S, 15, 0),
                      &c16_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u4 = c16_d8;
  sf_mex_import_named("u5", sf_mex_get_sfun_param(chartInstance->S, 16, 0),
                      &c16_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u5 = c16_d9;
  sf_mex_import_named("u6", sf_mex_get_sfun_param(chartInstance->S, 17, 0),
                      &c16_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u6 = c16_d10;
  sf_mex_import_named("u7", sf_mex_get_sfun_param(chartInstance->S, 18, 0),
                      &c16_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u7 = c16_d11;
  sf_mex_import_named("u8", sf_mex_get_sfun_param(chartInstance->S, 19, 0),
                      &c16_d12, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u8 = c16_d12;
  sf_mex_import_named("u9", sf_mex_get_sfun_param(chartInstance->S, 20, 0),
                      &c16_d13, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u9 = c16_d13;
  sf_mex_import_named("u10", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c16_d14, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u10 = c16_d14;
  sf_mex_import_named("u11", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c16_d15, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u11 = c16_d15;
  sf_mex_import_named("u12", sf_mex_get_sfun_param(chartInstance->S, 8, 0),
                      &c16_d16, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u12 = c16_d16;
  sf_mex_import_named("u13", sf_mex_get_sfun_param(chartInstance->S, 9, 0),
                      &c16_d17, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u13 = c16_d17;
  sf_mex_import_named("u14", sf_mex_get_sfun_param(chartInstance->S, 10, 0),
                      &c16_d18, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u14 = c16_d18;
  sf_mex_import_named("u15", sf_mex_get_sfun_param(chartInstance->S, 11, 0),
                      &c16_d19, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u15 = c16_d19;
  sf_mex_import_named("u16", sf_mex_get_sfun_param(chartInstance->S, 12, 0),
                      &c16_d20, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c16_u16 = c16_d20;
}

static void enable_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c16_update_debugger_state_c16_Basic_DMT
  (SFc16_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *
  chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  real_T c16_hoistedGlobal;
  real_T c16_u;
  const mxArray *c16_b_y = NULL;
  real_T c16_b_hoistedGlobal;
  real_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  uint8_T c16_c_hoistedGlobal;
  uint8_T c16_c_u;
  const mxArray *c16_d_y = NULL;
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellmatrix(3, 1), false);
  c16_hoistedGlobal = *chartInstance->c16_pop;
  c16_u = c16_hoistedGlobal;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_hoistedGlobal = *chartInstance->c16_push;
  c16_b_u = c16_b_hoistedGlobal;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  c16_c_hoistedGlobal = chartInstance->c16_is_active_c16_Basic_DMT;
  c16_c_u = c16_c_hoistedGlobal;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 2, c16_d_y);
  sf_mex_assign(&c16_st, c16_y, false);
  return c16_st;
}

static void set_sim_state_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_st)
{
  const mxArray *c16_u;
  chartInstance->c16_doneDoubleBufferReInit = true;
  c16_u = sf_mex_dup(c16_st);
  *chartInstance->c16_pop = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 0)), "pop");
  *chartInstance->c16_push = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 1)), "push");
  chartInstance->c16_is_active_c16_Basic_DMT = c16_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 2)),
     "is_active_c16_Basic_DMT");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_Basic_DMT(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c16_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_frameEn, 0U);
  chartInstance->c16_sfEvent = CALL_EVENT;
  c16_chartstep_c16_Basic_DMT(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_push, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_pop, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_fftLen, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_GI_Active, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_bitPerSymb, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_Tb, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_SystemPeriod, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u1, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u2, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u3, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u4, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u5, 17U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u6, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u7, 19U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u8, 20U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u9, 21U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u10, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u11, 23U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u12, 24U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u13, 25U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u14, 26U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u15, 27U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c16_u16, 28U);
}

static void mdl_start_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c16_chartstep_c16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c16_hoistedGlobal;
  real_T c16_b_hoistedGlobal;
  real_T c16_b_frameEn;
  real_T c16_b_bitPerSymb;
  uint32_T c16_debug_family_var_map[44];
  real_T c16_usub1;
  real_T c16_usub2;
  real_T c16_usub3;
  real_T c16_usub4;
  real_T c16_usub5;
  real_T c16_usub6;
  real_T c16_usub7;
  real_T c16_usub8;
  real_T c16_usub9;
  real_T c16_usub10;
  real_T c16_usub11;
  real_T c16_usub12;
  real_T c16_usub13;
  real_T c16_usub14;
  real_T c16_usub15;
  real_T c16_usub16;
  real_T c16_conPop;
  real_T c16_conPush;
  real_T c16_c_fftLen;
  real_T c16_c_GI_Active;
  real_T c16_c_Tb;
  real_T c16_c_SystemPeriod;
  real_T c16_c_u1;
  real_T c16_c_u2;
  real_T c16_c_u3;
  real_T c16_c_u4;
  real_T c16_c_u5;
  real_T c16_c_u6;
  real_T c16_c_u7;
  real_T c16_c_u8;
  real_T c16_c_u9;
  real_T c16_c_u10;
  real_T c16_c_u11;
  real_T c16_c_u12;
  real_T c16_c_u13;
  real_T c16_c_u14;
  real_T c16_c_u15;
  real_T c16_c_u16;
  real_T c16_nargin = 22.0;
  real_T c16_nargout = 2.0;
  real_T c16_b_push;
  real_T c16_b_pop;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  boolean_T guard13 = false;
  boolean_T guard14 = false;
  boolean_T guard15 = false;
  boolean_T guard16 = false;
  boolean_T guard17 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c16_sfEvent);
  c16_hoistedGlobal = *chartInstance->c16_frameEn;
  c16_b_hoistedGlobal = chartInstance->c16_bitPerSymb;
  c16_b_frameEn = c16_hoistedGlobal;
  c16_b_bitPerSymb = c16_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 44U, 44U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub1, 0U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub2, 1U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub3, 2U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub4, 3U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub5, 4U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub6, 5U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub7, 6U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub8, 7U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub9, 8U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub10, 9U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub11, 10U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub12, 11U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub13, 12U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub14, 13U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub15, 14U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_usub16, 15U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_conPop, 16U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_conPush, 17U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_fftLen, 18U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_c_GI_Active, 19U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_Tb, 20U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_SystemPeriod, 21U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u1, 22U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u2, 23U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u3, 24U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u4, 25U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u5, 26U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u6, 27U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u7, 28U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u8, 29U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u9, 30U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u10, 31U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u11, 32U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u12, 33U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u13, 34U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u14, 35U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u15, 36U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_c_u16, 37U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 38U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 39U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_frameEn, 40U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_bitPerSymb, 41U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_push, 42U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_pop, 43U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  c16_c_u16 = c16_b_u16;
  c16_c_u15 = c16_b_u15;
  c16_c_u14 = c16_b_u14;
  c16_c_u13 = c16_b_u13;
  c16_c_u12 = c16_b_u12;
  c16_c_u11 = c16_b_u11;
  c16_c_u10 = c16_b_u10;
  c16_c_u9 = c16_b_u9;
  c16_c_u8 = c16_b_u8;
  c16_c_u7 = c16_b_u7;
  c16_c_u6 = c16_b_u6;
  c16_c_u5 = c16_b_u5;
  c16_c_u4 = c16_b_u4;
  c16_c_u3 = c16_b_u3;
  c16_c_u2 = c16_b_u2;
  c16_c_u1 = c16_b_u1;
  c16_c_SystemPeriod = c16_b_SystemPeriod;
  c16_c_Tb = c16_b_Tb;
  c16_c_GI_Active = c16_b_GI_Active;
  c16_c_fftLen = c16_b_fftLen;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 12);
  switch ((int32_T)_SFD_INTEGER_CHECK("state", c16_get_state(chartInstance, 0)))
  {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 14);
    c16_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 15);
    c16_b_push = 0.0;
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 17);
    c16_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 18);
    c16_b_push = 1.0;
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 20);
    c16_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 21);
    c16_b_push = 0.0;
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 23);
    c16_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 24);
    c16_b_push = 1.0;
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 26);
    c16_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 27);
    c16_b_push = 0.0;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 31);
  c16_usub1 = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 32);
  c16_usub2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 33);
  c16_usub3 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 34);
  c16_usub4 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 35);
  c16_usub5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 36);
  c16_usub6 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 37);
  c16_usub7 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 38);
  c16_usub8 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 39);
  c16_usub9 = 9.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 40);
  c16_usub10 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 41);
  c16_usub11 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 42);
  c16_usub12 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 43);
  c16_usub13 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 44);
  c16_usub14 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 45);
  c16_usub15 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 46);
  c16_usub16 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 49);
  guard17 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c16_get_loopCount
        (chartInstance, 0), 0.0, -1, 0U, c16_get_loopCount(chartInstance, 0) ==
        0.0))) {
    if (CV_EML_COND(0, 1, 1, c16_get_enable(chartInstance, 0) != 0.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 50);
      c16_conPop = 1.0;
    } else {
      guard17 = true;
    }
  } else {
    guard17 = true;
  }

  if (guard17 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 52);
    c16_conPop = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 55);
  c16_set_loopCount(chartInstance, 0, c16_get_loopCount(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 56);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c16_get_loopCount
        (chartInstance, 0), 5.0, -1, 5U, c16_get_loopCount(chartInstance, 0) >=
        5.0))) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 57);
    c16_set_loopCount(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 60);
  c16_set_subCarCount(chartInstance, 0, c16_get_subCarCount(chartInstance, 0) +
                      1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 61);
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c16_get_subCarCount
        (chartInstance, 0), c16_b_bitPerSymb, -1, 5U, c16_get_subCarCount
        (chartInstance, 0) >= c16_b_bitPerSymb))) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 62);
    c16_set_subCar(chartInstance, 0, c16_get_subCar(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 4);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 63);
    c16_set_subCarCount(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 66);
  if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c16_get_subCar
        (chartInstance, 0), c16_b_fftLen, -1, 4U, c16_get_subCar(chartInstance,
         0) > c16_b_fftLen))) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 67);
    c16_set_subCar(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 4);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 68);
    c16_set_start(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 71);
  if (CV_EML_IF(0, 1, 4, c16_b_frameEn != 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 72);
    c16_set_start(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 73);
    c16_set_enable(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 74);
    c16_set_subCar(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 4);
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 77);
  c16_conPush = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 78);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  guard6 = false;
  guard7 = false;
  guard8 = false;
  guard9 = false;
  guard10 = false;
  guard11 = false;
  guard12 = false;
  guard13 = false;
  guard14 = false;
  guard15 = false;
  guard16 = false;
  if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 4, c16_get_subCar
        (chartInstance, 0), c16_usub1, -1, 1U, c16_get_subCar(chartInstance, 0)
        != c16_usub1))) {
    if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 5, c16_get_subCar
          (chartInstance, 0), c16_usub2, -1, 1U, c16_get_subCar(chartInstance, 0)
          != c16_usub2))) {
      if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 6, c16_get_subCar
            (chartInstance, 0), c16_usub3, -1, 1U, c16_get_subCar(chartInstance,
             0) != c16_usub3))) {
        if (CV_EML_COND(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 7, c16_get_subCar
              (chartInstance, 0), c16_usub4, -1, 1U, c16_get_subCar
              (chartInstance, 0) != c16_usub4))) {
          if (CV_EML_COND(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 8, c16_get_subCar
                (chartInstance, 0), c16_usub5, -1, 1U, c16_get_subCar
                (chartInstance, 0) != c16_usub5))) {
            if (CV_EML_COND(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 9,
                  c16_get_subCar(chartInstance, 0), c16_usub6, -1, 1U,
                  c16_get_subCar(chartInstance, 0) != c16_usub6))) {
              if (CV_EML_COND(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 10,
                    c16_get_subCar(chartInstance, 0), c16_usub7, -1, 1U,
                    c16_get_subCar(chartInstance, 0) != c16_usub7))) {
                if (CV_EML_COND(0, 1, 9, CV_RELATIONAL_EVAL(4U, 0U, 11,
                      c16_get_subCar(chartInstance, 0), c16_usub8, -1, 1U,
                      c16_get_subCar(chartInstance, 0) != c16_usub8))) {
                  if (CV_EML_COND(0, 1, 10, CV_RELATIONAL_EVAL(4U, 0U, 12,
                        c16_get_subCar(chartInstance, 0), c16_usub9, -1, 1U,
                        c16_get_subCar(chartInstance, 0) != c16_usub9))) {
                    if (CV_EML_COND(0, 1, 11, CV_RELATIONAL_EVAL(4U, 0U, 13,
                          c16_get_subCar(chartInstance, 0), c16_usub10, -1, 1U,
                          c16_get_subCar(chartInstance, 0) != c16_usub10))) {
                      if (CV_EML_COND(0, 1, 12, CV_RELATIONAL_EVAL(4U, 0U, 14,
                            c16_get_subCar(chartInstance, 0), c16_usub11, -1, 1U,
                            c16_get_subCar(chartInstance, 0) != c16_usub11))) {
                        if (CV_EML_COND(0, 1, 13, CV_RELATIONAL_EVAL(4U, 0U, 15,
                              c16_get_subCar(chartInstance, 0), c16_usub12, -1,
                              1U, c16_get_subCar(chartInstance, 0) != c16_usub12)))
                        {
                          if (CV_EML_COND(0, 1, 14, CV_RELATIONAL_EVAL(4U, 0U,
                                16, c16_get_subCar(chartInstance, 0), c16_usub13,
                                -1, 1U, c16_get_subCar(chartInstance, 0) !=
                                c16_usub13))) {
                            if (CV_EML_COND(0, 1, 15, CV_RELATIONAL_EVAL(4U, 0U,
                                  17, c16_get_subCar(chartInstance, 0),
                                  c16_usub14, -1, 1U, c16_get_subCar
                                  (chartInstance, 0) != c16_usub14))) {
                              if (CV_EML_COND(0, 1, 16, CV_RELATIONAL_EVAL(4U,
                                    0U, 18, c16_get_subCar(chartInstance, 0),
                                    c16_usub15, -1, 1U, c16_get_subCar
                                    (chartInstance, 0) != c16_usub15))) {
                                if (CV_EML_COND(0, 1, 17, CV_RELATIONAL_EVAL(4U,
                                      0U, 19, c16_get_subCar(chartInstance, 0),
                                      c16_usub16, -1, 1U, c16_get_subCar
                                      (chartInstance, 0) != c16_usub16))) {
                                  if (CV_EML_COND(0, 1, 18, c16_get_start
                                                  (chartInstance, 0) != 0.0)) {
                                    CV_EML_MCDC(0, 1, 1, true);
                                    CV_EML_IF(0, 1, 5, true);
                                    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent,
                                                  85);
                                    c16_conPush = 1.0;
                                  } else {
                                    guard1 = true;
                                  }
                                } else {
                                  guard2 = true;
                                }
                              } else {
                                guard3 = true;
                              }
                            } else {
                              guard4 = true;
                            }
                          } else {
                            guard5 = true;
                          }
                        } else {
                          guard6 = true;
                        }
                      } else {
                        guard7 = true;
                      }
                    } else {
                      guard8 = true;
                    }
                  } else {
                    guard9 = true;
                  }
                } else {
                  guard10 = true;
                }
              } else {
                guard11 = true;
              }
            } else {
              guard12 = true;
            }
          } else {
            guard13 = true;
          }
        } else {
          guard14 = true;
        }
      } else {
        guard15 = true;
      }
    } else {
      guard16 = true;
    }
  } else {
    guard16 = true;
  }

  if (guard16 == true) {
    guard15 = true;
  }

  if (guard15 == true) {
    guard14 = true;
  }

  if (guard14 == true) {
    guard13 = true;
  }

  if (guard13 == true) {
    guard12 = true;
  }

  if (guard12 == true) {
    guard11 = true;
  }

  if (guard11 == true) {
    guard10 = true;
  }

  if (guard10 == true) {
    guard9 = true;
  }

  if (guard9 == true) {
    guard8 = true;
  }

  if (guard8 == true) {
    guard7 = true;
  }

  if (guard7 == true) {
    guard6 = true;
  }

  if (guard6 == true) {
    guard5 = true;
  }

  if (guard5 == true) {
    guard4 = true;
  }

  if (guard4 == true) {
    guard3 = true;
  }

  if (guard3 == true) {
    guard2 = true;
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 1, false);
    CV_EML_IF(0, 1, 5, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 88);
  if (CV_EML_IF(0, 1, 6, c16_conPush != 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 89);
    if (CV_EML_IF(0, 1, 7, c16_conPop != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 90);
      c16_set_state(chartInstance, 0, 3.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 92);
      c16_set_state(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 96);
    if (CV_EML_IF(0, 1, 8, c16_conPop != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 97);
      c16_set_state(chartInstance, 0, 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 99);
      c16_set_state(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -99);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c16_push = c16_b_push;
  *chartInstance->c16_pop = c16_b_pop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c16_sfEvent);
}

static void initSimStructsc16_Basic_DMT(SFc16_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber)
{
  (void)c16_machineNumber;
  (void)c16_chartNumber;
  (void)c16_instanceNumber;
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc16_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c16_b_pop, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_pop),
    &c16_thisId);
  sf_mex_destroy(&c16_b_pop);
  return c16_y;
}

static real_T c16_b_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d21;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d21, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d21;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_pop;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc16_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c16_b_pop = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_pop),
    &c16_thisId);
  sf_mex_destroy(&c16_b_pop);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                false);
  c16_info_helper(&c16_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(const mxArray **c16_info)
{
  const mxArray *c16_rhs0 = NULL;
  const mxArray *c16_lhs0 = NULL;
  const mxArray *c16_rhs1 = NULL;
  const mxArray *c16_lhs1 = NULL;
  const mxArray *c16_rhs2 = NULL;
  const mxArray *c16_lhs2 = NULL;
  const mxArray *c16_rhs3 = NULL;
  const mxArray *c16_lhs3 = NULL;
  const mxArray *c16_rhs4 = NULL;
  const mxArray *c16_lhs4 = NULL;
  const mxArray *c16_rhs5 = NULL;
  const mxArray *c16_lhs5 = NULL;
  const mxArray *c16_rhs6 = NULL;
  const mxArray *c16_lhs6 = NULL;
  const mxArray *c16_rhs7 = NULL;
  const mxArray *c16_lhs7 = NULL;
  const mxArray *c16_rhs8 = NULL;
  const mxArray *c16_lhs8 = NULL;
  const mxArray *c16_rhs9 = NULL;
  const mxArray *c16_lhs9 = NULL;
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c16_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c16_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c16_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mrdivide"), "name", "name",
                  3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c16_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c16_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("rdivide"), "name", "name", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c16_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c16_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c16_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_div"), "name", "name", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c16_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c16_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c16_rhs0);
  sf_mex_destroy(&c16_lhs0);
  sf_mex_destroy(&c16_rhs1);
  sf_mex_destroy(&c16_lhs1);
  sf_mex_destroy(&c16_rhs2);
  sf_mex_destroy(&c16_lhs2);
  sf_mex_destroy(&c16_rhs3);
  sf_mex_destroy(&c16_lhs3);
  sf_mex_destroy(&c16_rhs4);
  sf_mex_destroy(&c16_lhs4);
  sf_mex_destroy(&c16_rhs5);
  sf_mex_destroy(&c16_lhs5);
  sf_mex_destroy(&c16_rhs6);
  sf_mex_destroy(&c16_lhs6);
  sf_mex_destroy(&c16_rhs7);
  sf_mex_destroy(&c16_lhs7);
  sf_mex_destroy(&c16_rhs8);
  sf_mex_destroy(&c16_lhs8);
  sf_mex_destroy(&c16_rhs9);
  sf_mex_destroy(&c16_lhs9);
}

static const mxArray *c16_emlrt_marshallOut(const char * c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c16_u)), false);
  return c16_y;
}

static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 7, 0U, 0U, 0U, 0), false);
  return c16_y;
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc16_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static int32_T c16_c_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i0, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc16_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_d_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_Basic_DMT, const char_T
  *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_Basic_DMT), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_Basic_DMT);
  return c16_y;
}

static uint8_T c16_e_emlrt_marshallIn(SFc16_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static real_T c16_get_enable(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c16_elementIndex);
  return *chartInstance->c16_enable_address;
}

static void c16_set_enable(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex, real_T c16_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c16_elementIndex);
  *chartInstance->c16_enable_address = c16_elementValue;
}

static real_T *c16_access_enable(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly)
{
  real_T *c16_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c16_dsmAddr = chartInstance->c16_enable_address;
  if (c16_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c16_dsmAddr;
}

static real_T c16_get_loopCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c16_elementIndex);
  return *chartInstance->c16_loopCount_address;
}

static void c16_set_loopCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex, real_T c16_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c16_elementIndex);
  *chartInstance->c16_loopCount_address = c16_elementValue;
}

static real_T *c16_access_loopCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly)
{
  real_T *c16_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c16_dsmAddr = chartInstance->c16_loopCount_address;
  if (c16_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c16_dsmAddr;
}

static real_T c16_get_start(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c16_elementIndex);
  return *chartInstance->c16_start_address;
}

static void c16_set_start(SFc16_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c16_elementIndex, real_T c16_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c16_elementIndex);
  *chartInstance->c16_start_address = c16_elementValue;
}

static real_T *c16_access_start(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly)
{
  real_T *c16_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c16_dsmAddr = chartInstance->c16_start_address;
  if (c16_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c16_dsmAddr;
}

static real_T c16_get_state(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 3, NULL, c16_elementIndex);
  return *chartInstance->c16_state_address;
}

static void c16_set_state(SFc16_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c16_elementIndex, real_T c16_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 3, NULL, c16_elementIndex);
  *chartInstance->c16_state_address = c16_elementValue;
}

static real_T *c16_access_state(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly)
{
  real_T *c16_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 3, NULL);
  c16_dsmAddr = chartInstance->c16_state_address;
  if (c16_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 3, NULL);
  }

  return c16_dsmAddr;
}

static real_T c16_get_subCar(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 4, NULL, c16_elementIndex);
  return *chartInstance->c16_subCar_address;
}

static void c16_set_subCar(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex, real_T c16_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 4, NULL, c16_elementIndex);
  *chartInstance->c16_subCar_address = c16_elementValue;
}

static real_T *c16_access_subCar(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_rdOnly)
{
  real_T *c16_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 4, NULL);
  c16_dsmAddr = chartInstance->c16_subCar_address;
  if (c16_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 4, NULL);
  }

  return c16_dsmAddr;
}

static real_T c16_get_subCarCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 5, NULL, c16_elementIndex);
  return *chartInstance->c16_subCarCount_address;
}

static void c16_set_subCarCount(SFc16_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c16_elementIndex, real_T c16_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 5, NULL, c16_elementIndex);
  *chartInstance->c16_subCarCount_address = c16_elementValue;
}

static real_T *c16_access_subCarCount(SFc16_Basic_DMTInstanceStruct
  *chartInstance, uint32_T c16_rdOnly)
{
  real_T *c16_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 5, NULL);
  c16_dsmAddr = chartInstance->c16_subCarCount_address;
  if (c16_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 5, NULL);
  }

  return c16_dsmAddr;
}

static void init_dsm_address_info(SFc16_Basic_DMTInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "enable", (void **)
    &chartInstance->c16_enable_address, &chartInstance->c16_enable_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "loopCount", (void **)
    &chartInstance->c16_loopCount_address, &chartInstance->c16_loopCount_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "start", (void **)
    &chartInstance->c16_start_address, &chartInstance->c16_start_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "state", (void **)
    &chartInstance->c16_state_address, &chartInstance->c16_state_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "subCar", (void **)
    &chartInstance->c16_subCar_address, &chartInstance->c16_subCar_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "subCarCount", (void **)
    &chartInstance->c16_subCarCount_address,
    &chartInstance->c16_subCarCount_index);
}

static void init_simulink_io_address(SFc16_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c16_frameEn = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c16_push = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c16_pop = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c16_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1111237039U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1396479622U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4102815715U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(381230029U);
}

mxArray* sf_c16_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c16_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bT1Dhox4PfhnSWeUlyc2lE");
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

    mxArray *mxData = mxCreateStructMatrix(1,21,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));
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
    mxArray* mxPostCodegenInfo = sf_c16_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c16_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c16_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c16_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c16_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"pop\",},{M[1],M[10],T\"push\",},{M[8],M[0],T\"is_active_c16_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc16_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           16,
           1,
           1,
           0,
           30,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"frameEn");
          _SFD_SET_DATA_PROPS(1,2,0,1,"push");
          _SFD_SET_DATA_PROPS(2,2,0,1,"pop");
          _SFD_SET_DATA_PROPS(3,11,0,0,"state");
          _SFD_SET_DATA_PROPS(4,11,0,0,"loopCount");
          _SFD_SET_DATA_PROPS(5,11,0,0,"start");
          _SFD_SET_DATA_PROPS(6,10,0,0,"fftLen");
          _SFD_SET_DATA_PROPS(7,10,0,0,"GI_Active");
          _SFD_SET_DATA_PROPS(8,10,0,0,"bitPerSymb");
          _SFD_SET_DATA_PROPS(9,11,0,0,"subCar");
          _SFD_SET_DATA_PROPS(10,11,0,0,"subCarCount");
          _SFD_SET_DATA_PROPS(11,10,0,0,"Tb");
          _SFD_SET_DATA_PROPS(12,10,0,0,"SystemPeriod");
          _SFD_SET_DATA_PROPS(13,10,0,0,"u1");
          _SFD_SET_DATA_PROPS(14,10,0,0,"u2");
          _SFD_SET_DATA_PROPS(15,10,0,0,"u3");
          _SFD_SET_DATA_PROPS(16,10,0,0,"u4");
          _SFD_SET_DATA_PROPS(17,10,0,0,"u5");
          _SFD_SET_DATA_PROPS(18,10,0,0,"u6");
          _SFD_SET_DATA_PROPS(19,10,0,0,"u7");
          _SFD_SET_DATA_PROPS(20,10,0,0,"u8");
          _SFD_SET_DATA_PROPS(21,10,0,0,"u9");
          _SFD_SET_DATA_PROPS(22,10,0,0,"u10");
          _SFD_SET_DATA_PROPS(23,10,0,0,"u11");
          _SFD_SET_DATA_PROPS(24,10,0,0,"u12");
          _SFD_SET_DATA_PROPS(25,10,0,0,"u13");
          _SFD_SET_DATA_PROPS(26,10,0,0,"u14");
          _SFD_SET_DATA_PROPS(27,10,0,0,"u15");
          _SFD_SET_DATA_PROPS(28,10,0,0,"u16");
          _SFD_SET_DATA_PROPS(29,11,0,0,"enable");
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
        _SFD_CV_INIT_EML(0,1,1,9,0,0,1,0,0,19,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1789);
        _SFD_CV_INIT_EML_IF(0,1,0,859,886,909,933);
        _SFD_CV_INIT_EML_IF(0,1,1,961,992,-1,1015);
        _SFD_CV_INIT_EML_IF(0,1,2,1049,1077,-1,1124);
        _SFD_CV_INIT_EML_IF(0,1,3,1126,1144,-1,1175);
        _SFD_CV_INIT_EML_IF(0,1,4,1177,1187,-1,1229);
        _SFD_CV_INIT_EML_IF(0,1,5,1242,1587,-1,1609);
        _SFD_CV_INIT_EML_IF(0,1,6,1613,1623,1694,1784);
        _SFD_CV_INIT_EML_IF(0,1,7,1628,1637,1661,1692);
        _SFD_CV_INIT_EML_IF(0,1,8,1714,1723,1747,1777);

        {
          static int caseStart[] = { 520, 333, 380, 428, 475 };

          static int caseExprEnd[] = { 529, 339, 386, 434, 481 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,316,329,570,5,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 862, 880 };

          static int condEnd[] = { 876, 886 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,862,886,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1245, 1265, 1285, 1308, 1328, 1348, 1371,
            1391, 1411, 1434, 1454, 1474, 1498, 1518, 1538, 1562, 1582 };

          static int condEnd[] = { 1260, 1280, 1300, 1323, 1343, 1363, 1386,
            1406, 1426, 1450, 1470, 1490, 1514, 1534, 1554, 1578, 1587 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3, 5, -3, 6, -3,
            7, -3, 8, -3, 9, -3, 10, -3, 11, -3, 12, -3, 13, -3, 14, -3, 15, -3,
            16, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1245,1587,17,2,&(condStart[0]),&(condEnd[0]),
                                33,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,862,876,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,964,992,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,1052,1077,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,1129,1144,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,1245,1260,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,1265,1280,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,1285,1300,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,1308,1323,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,8,1328,1343,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,9,1348,1363,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,10,1371,1386,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,11,1391,1406,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,12,1411,1426,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,13,1434,1450,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,14,1454,1470,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,15,1474,1490,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,16,1498,1514,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,17,1518,1534,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,18,1538,1554,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,19,1562,1578,-1,1);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c16_frameEn);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c16_push);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c16_pop);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c16_state_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c16_loopCount_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c16_start_address);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c16_fftLen);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c16_GI_Active);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c16_bitPerSymb);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c16_subCar_address);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c16_subCarCount_address);
        _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c16_Tb);
        _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c16_SystemPeriod);
        _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c16_u1);
        _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c16_u2);
        _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c16_u3);
        _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c16_u4);
        _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c16_u5);
        _SFD_SET_DATA_VALUE_PTR(18U, &chartInstance->c16_u6);
        _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance->c16_u7);
        _SFD_SET_DATA_VALUE_PTR(20U, &chartInstance->c16_u8);
        _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c16_u9);
        _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance->c16_u10);
        _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c16_u11);
        _SFD_SET_DATA_VALUE_PTR(24U, &chartInstance->c16_u12);
        _SFD_SET_DATA_VALUE_PTR(25U, &chartInstance->c16_u13);
        _SFD_SET_DATA_VALUE_PTR(26U, &chartInstance->c16_u14);
        _SFD_SET_DATA_VALUE_PTR(27U, &chartInstance->c16_u15);
        _SFD_SET_DATA_VALUE_PTR(28U, &chartInstance->c16_u16);
        _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c16_enable_address);
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
  return "5fuTVj1NREvMLzp1IMnRwE";
}

static void sf_opaque_initialize_c16_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_Basic_DMT(void *chartInstanceVar)
{
  enable_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_Basic_DMT(void *chartInstanceVar)
{
  disable_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c16_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c16_Basic_DMT(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c16_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_Basic_DMT(SimStruct *S)
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
    initialize_params_c16_Basic_DMT((SFc16_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_Basic_DMT(SimStruct *S)
{
  /* Actual parameters from chart:
     GI_Active SystemPeriod Tb bitPerSymb fftLen u1 u10 u11 u12 u13 u14 u15 u16 u2 u3 u4 u5 u6 u7 u8 u9
   */
  const char_T *rtParamNames[] = { "GI_Active", "SystemPeriod", "Tb",
    "bitPerSymb", "fftLen", "u1", "u10", "u11", "u12", "u13", "u14", "u15",
    "u16", "u2", "u3", "u4", "u5", "u6", "u7", "u8", "u9" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for GI_Active*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for SystemPeriod*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for Tb*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for bitPerSymb*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for fftLen*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for u1*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for u10*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for u11*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);

  /* registration for u12*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_DOUBLE);

  /* registration for u13*/
  ssRegDlgParamAsRunTimeParam(S, 9, 9, rtParamNames[9], SS_DOUBLE);

  /* registration for u14*/
  ssRegDlgParamAsRunTimeParam(S, 10, 10, rtParamNames[10], SS_DOUBLE);

  /* registration for u15*/
  ssRegDlgParamAsRunTimeParam(S, 11, 11, rtParamNames[11], SS_DOUBLE);

  /* registration for u16*/
  ssRegDlgParamAsRunTimeParam(S, 12, 12, rtParamNames[12], SS_DOUBLE);

  /* registration for u2*/
  ssRegDlgParamAsRunTimeParam(S, 13, 13, rtParamNames[13], SS_DOUBLE);

  /* registration for u3*/
  ssRegDlgParamAsRunTimeParam(S, 14, 14, rtParamNames[14], SS_DOUBLE);

  /* registration for u4*/
  ssRegDlgParamAsRunTimeParam(S, 15, 15, rtParamNames[15], SS_DOUBLE);

  /* registration for u5*/
  ssRegDlgParamAsRunTimeParam(S, 16, 16, rtParamNames[16], SS_DOUBLE);

  /* registration for u6*/
  ssRegDlgParamAsRunTimeParam(S, 17, 17, rtParamNames[17], SS_DOUBLE);

  /* registration for u7*/
  ssRegDlgParamAsRunTimeParam(S, 18, 18, rtParamNames[18], SS_DOUBLE);

  /* registration for u8*/
  ssRegDlgParamAsRunTimeParam(S, 19, 19, rtParamNames[19], SS_DOUBLE);

  /* registration for u9*/
  ssRegDlgParamAsRunTimeParam(S, 20, 20, rtParamNames[20], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,16,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2615119179U));
  ssSetChecksum1(S,(2377528064U));
  ssSetChecksum2(S,(1124137637U));
  ssSetChecksum3(S,(3580043831U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c16_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_Basic_DMT(SimStruct *S)
{
  SFc16_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc16_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc16_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c16_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c16_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c16_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c16_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c16_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c16_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c16_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c16_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c16_Basic_DMT;
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

void c16_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
