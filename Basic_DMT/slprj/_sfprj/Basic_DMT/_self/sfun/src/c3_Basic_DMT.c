/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c3_Basic_DMT.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Basic_DMT_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_b_u1                        (0.0)
#define c3_b_u2                        (1.0)
#define c3_b_u3                        (1.0)
#define c3_b_u4                        (1.0)
#define c3_b_u5                        (1.0)
#define c3_b_u6                        (1.0)
#define c3_b_u7                        (1.0)
#define c3_b_u8                        (1.0)
#define c3_b_u9                        (0.0)
#define c3_b_u10                       (1.0)
#define c3_b_u11                       (1.0)
#define c3_b_u12                       (1.0)
#define c3_b_u13                       (1.0)
#define c3_b_u14                       (1.0)
#define c3_b_u15                       (1.0)
#define c3_b_u16                       (1.0)
#define c3_b_freqDivSubcAlloc          (5.0)
#define c3_b_bitsPerFrame              (56.0)
#define c3_b_bitPerSymb                (4.0)
#define c3_b_fftLen                    (16.0)
#define c3_b_usedSubCar                (14.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[47] = { "usub1", "usub2", "usub3",
  "usub4", "usub5", "usub6", "usub7", "usub8", "usub9", "usub10", "usub11",
  "usub12", "usub13", "usub14", "usub15", "usub16", "conPush", "conPop",
  "usedSubCar", "bitPerSymb", "fftLen", "freqDivSubcAlloc", "bitsPerFrame", "u1",
  "u2", "u3", "u4", "u5", "u6", "u7", "u8", "u9", "u10", "u11", "u12", "u13",
  "u14", "u15", "u16", "nargin", "nargout", "num", "frameEn", "sel", "push",
  "pop", "frameStart" };

/* Function Declarations */
static void initialize_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance);
static void initialize_params_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance);
static void disable_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance);
static void set_sim_state_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance);
static void mdl_start_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance);
static void c3_chartstep_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance);
static void initSimStructsc3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_b_frameStart, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_Basic_DMT, const char_T *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static real_T c3_get_bitCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex);
static void c3_set_bitCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex, real_T c3_elementValue);
static real_T *c3_access_bitCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly);
static real_T c3_get_loopCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex);
static void c3_set_loopCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex, real_T c3_elementValue);
static real_T *c3_access_loopCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly);
static real_T c3_get_start(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex);
static void c3_set_start(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex, real_T c3_elementValue);
static real_T *c3_access_start(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly);
static real_T c3_get_state(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex);
static void c3_set_state(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex, real_T c3_elementValue);
static real_T *c3_access_state(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly);
static real_T c3_get_subCar(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex);
static void c3_set_subCar(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex, real_T c3_elementValue);
static real_T *c3_access_subCar(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly);
static real_T c3_get_subCarCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex);
static void c3_set_subCarCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex, real_T c3_elementValue);
static real_T *c3_access_subCarCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly);
static void init_dsm_address_info(SFc3_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_Basic_DMTInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_Basic_DMT = 0U;
}

static void initialize_params_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d8;
  real_T c3_d9;
  real_T c3_d10;
  real_T c3_d11;
  real_T c3_d12;
  real_T c3_d13;
  real_T c3_d14;
  real_T c3_d15;
  real_T c3_d16;
  real_T c3_d17;
  real_T c3_d18;
  real_T c3_d19;
  real_T c3_d20;
  sf_mex_import_named("usedSubCar", sf_mex_get_sfun_param(chartInstance->S, 20,
    0), &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_usedSubCar = c3_d0;
  sf_mex_import_named("bitPerSymb", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_bitPerSymb = c3_d1;
  sf_mex_import_named("fftLen", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c3_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_fftLen = c3_d2;
  sf_mex_import_named("freqDivSubcAlloc", sf_mex_get_sfun_param(chartInstance->S,
    3, 0), &c3_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_freqDivSubcAlloc = c3_d3;
  sf_mex_import_named("bitsPerFrame", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c3_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_bitsPerFrame = c3_d4;
  sf_mex_import_named("u1", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c3_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u1 = c3_d5;
  sf_mex_import_named("u2", sf_mex_get_sfun_param(chartInstance->S, 12, 0),
                      &c3_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u2 = c3_d6;
  sf_mex_import_named("u3", sf_mex_get_sfun_param(chartInstance->S, 13, 0),
                      &c3_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u3 = c3_d7;
  sf_mex_import_named("u4", sf_mex_get_sfun_param(chartInstance->S, 14, 0),
                      &c3_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u4 = c3_d8;
  sf_mex_import_named("u5", sf_mex_get_sfun_param(chartInstance->S, 15, 0),
                      &c3_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u5 = c3_d9;
  sf_mex_import_named("u6", sf_mex_get_sfun_param(chartInstance->S, 16, 0),
                      &c3_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u6 = c3_d10;
  sf_mex_import_named("u7", sf_mex_get_sfun_param(chartInstance->S, 17, 0),
                      &c3_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u7 = c3_d11;
  sf_mex_import_named("u8", sf_mex_get_sfun_param(chartInstance->S, 18, 0),
                      &c3_d12, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u8 = c3_d12;
  sf_mex_import_named("u9", sf_mex_get_sfun_param(chartInstance->S, 19, 0),
                      &c3_d13, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u9 = c3_d13;
  sf_mex_import_named("u10", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c3_d14, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u10 = c3_d14;
  sf_mex_import_named("u11", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c3_d15, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u11 = c3_d15;
  sf_mex_import_named("u12", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c3_d16, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u12 = c3_d16;
  sf_mex_import_named("u13", sf_mex_get_sfun_param(chartInstance->S, 8, 0),
                      &c3_d17, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u13 = c3_d17;
  sf_mex_import_named("u14", sf_mex_get_sfun_param(chartInstance->S, 9, 0),
                      &c3_d18, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u14 = c3_d18;
  sf_mex_import_named("u15", sf_mex_get_sfun_param(chartInstance->S, 10, 0),
                      &c3_d19, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u15 = c3_d19;
  sf_mex_import_named("u16", sf_mex_get_sfun_param(chartInstance->S, 11, 0),
                      &c3_d20, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_u16 = c3_d20;
}

static void enable_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(5, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_frameStart;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_pop;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *chartInstance->c3_push;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *chartInstance->c3_sel;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_Basic_DMT;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_frameStart = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "frameStart");
  *chartInstance->c3_pop = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "pop");
  *chartInstance->c3_push = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "push");
  *chartInstance->c3_sel = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "sel");
  chartInstance->c3_is_active_c3_Basic_DMT = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 4)), "is_active_c3_Basic_DMT");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Basic_DMT(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_num, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_frameEn, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_usedSubCar, 2U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_Basic_DMT(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sel, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_bitPerSymb, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_push, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_fftLen, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_freqDivSubcAlloc, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_bitsPerFrame, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u1, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u2, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u3, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u4, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u5, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u6, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u7, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u8, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u9, 17U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u10, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u11, 19U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u12, 20U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u13, 21U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u14, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u15, 23U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_u16, 24U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_pop, 25U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_frameStart, 26U);
}

static void mdl_start_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_chartstep_c3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance)
{
  uint32_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  uint32_T c3_b_num;
  real_T c3_b_frameEn;
  uint32_T c3_debug_family_var_map[47];
  real_T c3_usub1;
  real_T c3_usub2;
  real_T c3_usub3;
  real_T c3_usub4;
  real_T c3_usub5;
  real_T c3_usub6;
  real_T c3_usub7;
  real_T c3_usub8;
  real_T c3_usub9;
  real_T c3_usub10;
  real_T c3_usub11;
  real_T c3_usub12;
  real_T c3_usub13;
  real_T c3_usub14;
  real_T c3_usub15;
  real_T c3_usub16;
  real_T c3_conPush;
  real_T c3_conPop;
  real_T c3_c_usedSubCar;
  real_T c3_c_bitPerSymb;
  real_T c3_c_fftLen;
  real_T c3_c_freqDivSubcAlloc;
  real_T c3_c_bitsPerFrame;
  real_T c3_c_u1;
  real_T c3_c_u2;
  real_T c3_c_u3;
  real_T c3_c_u4;
  real_T c3_c_u5;
  real_T c3_c_u6;
  real_T c3_c_u7;
  real_T c3_c_u8;
  real_T c3_c_u9;
  real_T c3_c_u10;
  real_T c3_c_u11;
  real_T c3_c_u12;
  real_T c3_c_u13;
  real_T c3_c_u14;
  real_T c3_c_u15;
  real_T c3_c_u16;
  real_T c3_nargin = 23.0;
  real_T c3_nargout = 4.0;
  real_T c3_b_sel;
  real_T c3_b_push;
  real_T c3_b_pop;
  real_T c3_b_frameStart;
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
  boolean_T guard18 = false;
  boolean_T guard19 = false;
  boolean_T guard20 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *chartInstance->c3_num;
  c3_b_hoistedGlobal = *chartInstance->c3_frameEn;
  c3_b_num = c3_hoistedGlobal;
  c3_b_frameEn = c3_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 47U, 47U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub1, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub2, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub3, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub4, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub5, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub6, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub7, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub8, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub9, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub10, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub11, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub12, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub13, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub14, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub15, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_usub16, 15U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_conPush, 16U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_conPop, 17U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_usedSubCar, 18U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_bitPerSymb, 19U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_fftLen, 20U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_freqDivSubcAlloc, 21U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_bitsPerFrame, 22U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u1, 23U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u2, 24U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u3, 25U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u4, 26U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u5, 27U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u6, 28U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u7, 29U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u8, 30U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u9, 31U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u10, 32U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u11, 33U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u12, 34U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u13, 35U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u14, 36U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u15, 37U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_u16, 38U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 39U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 40U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_num, 41U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_frameEn, 42U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_sel, 43U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_push, 44U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_pop, 45U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_frameStart, 46U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_c_u16 = c3_b_u16;
  c3_c_u15 = c3_b_u15;
  c3_c_u14 = c3_b_u14;
  c3_c_u13 = c3_b_u13;
  c3_c_u12 = c3_b_u12;
  c3_c_u11 = c3_b_u11;
  c3_c_u10 = c3_b_u10;
  c3_c_u9 = c3_b_u9;
  c3_c_u8 = c3_b_u8;
  c3_c_u7 = c3_b_u7;
  c3_c_u6 = c3_b_u6;
  c3_c_u5 = c3_b_u5;
  c3_c_u4 = c3_b_u4;
  c3_c_u3 = c3_b_u3;
  c3_c_u2 = c3_b_u2;
  c3_c_u1 = c3_b_u1;
  c3_c_bitsPerFrame = c3_b_bitsPerFrame;
  c3_c_freqDivSubcAlloc = c3_b_freqDivSubcAlloc;
  c3_c_fftLen = c3_b_fftLen;
  c3_c_bitPerSymb = c3_b_bitPerSymb;
  c3_c_usedSubCar = c3_b_usedSubCar;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  switch ((int32_T)_SFD_INTEGER_CHECK("state", c3_get_state(chartInstance, 0)))
  {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
    c3_b_sel = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
    c3_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
    c3_b_push = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
    c3_b_frameStart = 0.0;
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
    c3_b_sel = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
    c3_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
    c3_b_push = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
    c3_b_frameStart = 0.0;
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
    c3_b_sel = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
    c3_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
    c3_b_push = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
    c3_b_frameStart = 0.0;
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
    c3_b_sel = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
    c3_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
    c3_b_push = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
    c3_b_frameStart = 0.0;
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
    c3_b_sel = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
    c3_b_pop = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
    c3_b_push = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
    c3_b_frameStart = 0.0;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
  c3_usub1 = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
  c3_usub2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
  c3_usub3 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
  c3_usub4 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
  c3_usub5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
  c3_usub6 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
  c3_usub7 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
  c3_usub8 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
  c3_usub9 = 9.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
  c3_usub10 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
  c3_usub11 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 60);
  c3_usub12 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 61);
  c3_usub13 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
  c3_usub14 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 63);
  c3_usub15 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 64);
  c3_usub16 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c3_get_loopCount
        (chartInstance, 0), 1.0, -1, 0U, c3_get_loopCount(chartInstance, 0) ==
        1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
    c3_conPush = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 69);
    c3_conPush = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 71);
  c3_set_loopCount(chartInstance, 0, c3_get_loopCount(chartInstance, 0) + 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 72);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c3_get_loopCount
        (chartInstance, 0), c3_b_freqDivSubcAlloc, -1, 5U, c3_get_loopCount
        (chartInstance, 0) >= c3_b_freqDivSubcAlloc))) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 73);
    c3_set_loopCount(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 76);
  c3_conPop = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 77);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 2, (real_T)c3_b_num,
        c3_b_bitsPerFrame, -1, 5U, (real_T)c3_b_num >= c3_b_bitsPerFrame))) {
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 3, c3_get_bitCount
          (chartInstance, 0), 0.0, -1, 0U, c3_get_bitCount(chartInstance, 0) ==
          0.0))) {
      if (CV_EML_COND(0, 1, 2, c3_b_frameEn != 0.0)) {
        guard4 = true;
      } else if (CV_EML_COND(0, 1, 3, c3_get_start(chartInstance, 0) != 0.0)) {
        guard4 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard5 = true;
    }
  } else {
    guard5 = true;
  }

  if (guard5 == true) {
    guard3 = true;
  }

  if (guard4 == true) {
    guard2 = true;
  }

  if (guard3 == true) {
    if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c3_get_bitCount
          (chartInstance, 0), 0.0, -1, 4U, c3_get_bitCount(chartInstance, 0) >
          0.0))) {
      if (CV_EML_COND(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, c3_get_bitCount
            (chartInstance, 0), c3_b_bitsPerFrame, -1, 3U, c3_get_bitCount
            (chartInstance, 0) <= c3_b_bitsPerFrame))) {
        guard2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 2, true);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 78);
    c3_set_start(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 79);
    if (CV_EML_IF(0, 1, 3, c3_b_frameEn != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 80);
      c3_b_frameStart = 1.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 83);
    c3_set_subCarCount(chartInstance, 0, c3_get_subCarCount(chartInstance, 0) +
                       1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 84);
    if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 6, c3_get_subCarCount
          (chartInstance, 0), c3_b_bitPerSymb, -1, 5U, c3_get_subCarCount
          (chartInstance, 0) >= c3_b_bitPerSymb))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 85);
      c3_set_subCar(chartInstance, 0, c3_get_subCar(chartInstance, 0) + 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 86);
      c3_set_subCarCount(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 88);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 7, c3_get_subCar
          (chartInstance, 0), c3_b_fftLen, -1, 4U, c3_get_subCar(chartInstance,
           0) > c3_b_fftLen))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 89);
      c3_set_subCar(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 92);
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
    guard17 = false;
    guard18 = false;
    guard19 = false;
    guard20 = false;
    if (CV_EML_COND(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 8, c3_get_subCar
          (chartInstance, 0), c3_usub1, -1, 1U, c3_get_subCar(chartInstance, 0)
          != c3_usub1))) {
      if (CV_EML_COND(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 9, c3_get_subCar
            (chartInstance, 0), c3_usub2, -1, 1U, c3_get_subCar(chartInstance, 0)
            != c3_usub2))) {
        if (CV_EML_COND(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 10, c3_get_subCar
              (chartInstance, 0), c3_usub3, -1, 1U, c3_get_subCar(chartInstance,
               0) != c3_usub3))) {
          if (CV_EML_COND(0, 1, 9, CV_RELATIONAL_EVAL(4U, 0U, 11, c3_get_subCar
                (chartInstance, 0), c3_usub4, -1, 1U, c3_get_subCar
                (chartInstance, 0) != c3_usub4))) {
            if (CV_EML_COND(0, 1, 10, CV_RELATIONAL_EVAL(4U, 0U, 12,
                  c3_get_subCar(chartInstance, 0), c3_usub5, -1, 1U,
                  c3_get_subCar(chartInstance, 0) != c3_usub5))) {
              if (CV_EML_COND(0, 1, 11, CV_RELATIONAL_EVAL(4U, 0U, 13,
                    c3_get_subCar(chartInstance, 0), c3_usub6, -1, 1U,
                    c3_get_subCar(chartInstance, 0) != c3_usub6))) {
                if (CV_EML_COND(0, 1, 12, CV_RELATIONAL_EVAL(4U, 0U, 14,
                      c3_get_subCar(chartInstance, 0), c3_usub7, -1, 1U,
                      c3_get_subCar(chartInstance, 0) != c3_usub7))) {
                  if (CV_EML_COND(0, 1, 13, CV_RELATIONAL_EVAL(4U, 0U, 15,
                        c3_get_subCar(chartInstance, 0), c3_usub8, -1, 1U,
                        c3_get_subCar(chartInstance, 0) != c3_usub8))) {
                    if (CV_EML_COND(0, 1, 14, CV_RELATIONAL_EVAL(4U, 0U, 16,
                          c3_get_subCar(chartInstance, 0), c3_usub9, -1, 1U,
                          c3_get_subCar(chartInstance, 0) != c3_usub9))) {
                      if (CV_EML_COND(0, 1, 15, CV_RELATIONAL_EVAL(4U, 0U, 17,
                            c3_get_subCar(chartInstance, 0), c3_usub10, -1, 1U,
                            c3_get_subCar(chartInstance, 0) != c3_usub10))) {
                        if (CV_EML_COND(0, 1, 16, CV_RELATIONAL_EVAL(4U, 0U, 18,
                              c3_get_subCar(chartInstance, 0), c3_usub11, -1, 1U,
                              c3_get_subCar(chartInstance, 0) != c3_usub11))) {
                          if (CV_EML_COND(0, 1, 17, CV_RELATIONAL_EVAL(4U, 0U,
                                19, c3_get_subCar(chartInstance, 0), c3_usub12,
                                -1, 1U, c3_get_subCar(chartInstance, 0) !=
                                c3_usub12))) {
                            if (CV_EML_COND(0, 1, 18, CV_RELATIONAL_EVAL(4U, 0U,
                                  20, c3_get_subCar(chartInstance, 0), c3_usub13,
                                  -1, 1U, c3_get_subCar(chartInstance, 0) !=
                                  c3_usub13))) {
                              if (CV_EML_COND(0, 1, 19, CV_RELATIONAL_EVAL(4U,
                                    0U, 21, c3_get_subCar(chartInstance, 0),
                                    c3_usub14, -1, 1U, c3_get_subCar
                                    (chartInstance, 0) != c3_usub14))) {
                                if (CV_EML_COND(0, 1, 20, CV_RELATIONAL_EVAL(4U,
                                      0U, 22, c3_get_subCar(chartInstance, 0),
                                      c3_usub15, -1, 1U, c3_get_subCar
                                      (chartInstance, 0) != c3_usub15))) {
                                  if (CV_EML_COND(0, 1, 21, CV_RELATIONAL_EVAL
                                                  (4U, 0U, 23, c3_get_subCar
                                                   (chartInstance, 0), c3_usub16,
                                                   -1, 1U, c3_get_subCar
                                                   (chartInstance, 0) !=
                                                   c3_usub16))) {
                                    CV_EML_MCDC(0, 1, 1, true);
                                    CV_EML_IF(0, 1, 6, true);
                                    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent,
                                                  98);
                                    c3_conPop = 1.0;
                                    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent,
                                                  99);
                                    c3_set_bitCount(chartInstance, 0,
                                                    c3_get_bitCount
                                                    (chartInstance, 0) + 1.0);
                                    ssUpdateDataStoreLog(chartInstance->S, 0);
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
              guard17 = true;
            }
          } else {
            guard18 = true;
          }
        } else {
          guard19 = true;
        }
      } else {
        guard20 = true;
      }
    } else {
      guard20 = true;
    }

    if (guard20 == true) {
      guard19 = true;
    }

    if (guard19 == true) {
      guard18 = true;
    }

    if (guard18 == true) {
      guard17 = true;
    }

    if (guard17 == true) {
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
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 6, false);
    }
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 2, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 104);
  if (CV_EML_IF(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 24, c3_get_bitCount
        (chartInstance, 0), 56.0, -1, 5U, c3_get_bitCount(chartInstance, 0) >=
        56.0))) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 105);
    c3_set_bitCount(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 106);
    c3_set_start(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 2);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 109);
  if (CV_EML_IF(0, 1, 8, c3_conPop != 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 110);
    if (CV_EML_IF(0, 1, 9, c3_conPush != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 111);
      c3_set_state(chartInstance, 0, 3.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 113);
      c3_set_state(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 116);
    if (CV_EML_IF(0, 1, 10, c3_conPush != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 117);
      c3_set_state(chartInstance, 0, 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 119);
      c3_set_state(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -119);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_sel = c3_b_sel;
  *chartInstance->c3_push = c3_b_push;
  *chartInstance->c3_pop = c3_b_pop;
  *chartInstance->c3_frameStart = c3_b_frameStart;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_Basic_DMT(SFc3_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc3_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_b_frameStart, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_frameStart),
    &c3_thisId);
  sf_mex_destroy(&c3_b_frameStart);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d21;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d21, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d21;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_frameStart;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc3_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c3_b_frameStart = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_frameStart),
    &c3_thisId);
  sf_mex_destroy(&c3_b_frameStart);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc3_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc3_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc3_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_Basic_DMT, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Basic_DMT), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Basic_DMT);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static real_T c3_get_bitCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c3_elementIndex);
  return *chartInstance->c3_bitCount_address;
}

static void c3_set_bitCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex, real_T c3_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c3_elementIndex);
  *chartInstance->c3_bitCount_address = c3_elementValue;
}

static real_T *c3_access_bitCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly)
{
  real_T *c3_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c3_dsmAddr = chartInstance->c3_bitCount_address;
  if (c3_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c3_dsmAddr;
}

static real_T c3_get_loopCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c3_elementIndex);
  return *chartInstance->c3_loopCount_address;
}

static void c3_set_loopCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex, real_T c3_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c3_elementIndex);
  *chartInstance->c3_loopCount_address = c3_elementValue;
}

static real_T *c3_access_loopCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly)
{
  real_T *c3_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c3_dsmAddr = chartInstance->c3_loopCount_address;
  if (c3_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c3_dsmAddr;
}

static real_T c3_get_start(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c3_elementIndex);
  return *chartInstance->c3_start_address;
}

static void c3_set_start(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex, real_T c3_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c3_elementIndex);
  *chartInstance->c3_start_address = c3_elementValue;
}

static real_T *c3_access_start(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly)
{
  real_T *c3_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c3_dsmAddr = chartInstance->c3_start_address;
  if (c3_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c3_dsmAddr;
}

static real_T c3_get_state(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 3, NULL, c3_elementIndex);
  return *chartInstance->c3_state_address;
}

static void c3_set_state(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex, real_T c3_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 3, NULL, c3_elementIndex);
  *chartInstance->c3_state_address = c3_elementValue;
}

static real_T *c3_access_state(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly)
{
  real_T *c3_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 3, NULL);
  c3_dsmAddr = chartInstance->c3_state_address;
  if (c3_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 3, NULL);
  }

  return c3_dsmAddr;
}

static real_T c3_get_subCar(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 4, NULL, c3_elementIndex);
  return *chartInstance->c3_subCar_address;
}

static void c3_set_subCar(SFc3_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c3_elementIndex, real_T c3_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 4, NULL, c3_elementIndex);
  *chartInstance->c3_subCar_address = c3_elementValue;
}

static real_T *c3_access_subCar(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly)
{
  real_T *c3_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 4, NULL);
  c3_dsmAddr = chartInstance->c3_subCar_address;
  if (c3_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 4, NULL);
  }

  return c3_dsmAddr;
}

static real_T c3_get_subCarCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 5, NULL, c3_elementIndex);
  return *chartInstance->c3_subCarCount_address;
}

static void c3_set_subCarCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_elementIndex, real_T c3_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 5, NULL, c3_elementIndex);
  *chartInstance->c3_subCarCount_address = c3_elementValue;
}

static real_T *c3_access_subCarCount(SFc3_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c3_rdOnly)
{
  real_T *c3_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 5, NULL);
  c3_dsmAddr = chartInstance->c3_subCarCount_address;
  if (c3_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 5, NULL);
  }

  return c3_dsmAddr;
}

static void init_dsm_address_info(SFc3_Basic_DMTInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "bitCount", (void **)
    &chartInstance->c3_bitCount_address, &chartInstance->c3_bitCount_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "loopCount", (void **)
    &chartInstance->c3_loopCount_address, &chartInstance->c3_loopCount_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "start", (void **)
    &chartInstance->c3_start_address, &chartInstance->c3_start_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "state", (void **)
    &chartInstance->c3_state_address, &chartInstance->c3_state_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "subCar", (void **)
    &chartInstance->c3_subCar_address, &chartInstance->c3_subCar_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "subCarCount", (void **)
    &chartInstance->c3_subCarCount_address, &chartInstance->c3_subCarCount_index);
}

static void init_simulink_io_address(SFc3_Basic_DMTInstanceStruct *chartInstance)
{
  chartInstance->c3_num = (uint32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_frameEn = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_sel = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_push = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_pop = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_frameStart = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c3_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3183222316U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3464261907U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(113306691U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2790440932U);
}

mxArray* sf_c3_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c3_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("O4JWTbWSreCrQUhJnBsuqE");
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
    mxArray* mxPostCodegenInfo = sf_c3_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c3_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[31],T\"frameStart\",},{M[1],M[30],T\"pop\",},{M[1],M[9],T\"push\",},{M[1],M[5],T\"sel\",},{M[8],M[0],T\"is_active_c3_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           3,
           1,
           1,
           0,
           33,
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
          _SFD_SET_DATA_PROPS(2,10,0,0,"usedSubCar");
          _SFD_SET_DATA_PROPS(3,2,0,1,"sel");
          _SFD_SET_DATA_PROPS(4,10,0,0,"bitPerSymb");
          _SFD_SET_DATA_PROPS(5,2,0,1,"push");
          _SFD_SET_DATA_PROPS(6,10,0,0,"fftLen");
          _SFD_SET_DATA_PROPS(7,10,0,0,"freqDivSubcAlloc");
          _SFD_SET_DATA_PROPS(8,10,0,0,"bitsPerFrame");
          _SFD_SET_DATA_PROPS(9,10,0,0,"u1");
          _SFD_SET_DATA_PROPS(10,10,0,0,"u2");
          _SFD_SET_DATA_PROPS(11,10,0,0,"u3");
          _SFD_SET_DATA_PROPS(12,10,0,0,"u4");
          _SFD_SET_DATA_PROPS(13,10,0,0,"u5");
          _SFD_SET_DATA_PROPS(14,10,0,0,"u6");
          _SFD_SET_DATA_PROPS(15,10,0,0,"u7");
          _SFD_SET_DATA_PROPS(16,10,0,0,"u8");
          _SFD_SET_DATA_PROPS(17,10,0,0,"u9");
          _SFD_SET_DATA_PROPS(18,10,0,0,"u10");
          _SFD_SET_DATA_PROPS(19,10,0,0,"u11");
          _SFD_SET_DATA_PROPS(20,10,0,0,"u12");
          _SFD_SET_DATA_PROPS(21,10,0,0,"u13");
          _SFD_SET_DATA_PROPS(22,10,0,0,"u14");
          _SFD_SET_DATA_PROPS(23,10,0,0,"u15");
          _SFD_SET_DATA_PROPS(24,10,0,0,"u16");
          _SFD_SET_DATA_PROPS(25,2,0,1,"pop");
          _SFD_SET_DATA_PROPS(26,2,0,1,"frameStart");
          _SFD_SET_DATA_PROPS(27,11,0,0,"state");
          _SFD_SET_DATA_PROPS(28,11,0,0,"loopCount");
          _SFD_SET_DATA_PROPS(29,11,0,0,"subCarCount");
          _SFD_SET_DATA_PROPS(30,11,0,0,"subCar");
          _SFD_SET_DATA_PROPS(31,11,0,0,"start");
          _SFD_SET_DATA_PROPS(32,11,0,0,"bitCount");
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
        _SFD_CV_INIT_EML(0,1,1,11,0,0,1,0,0,22,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2335);
        _SFD_CV_INIT_EML_IF(0,1,0,1163,1180,1201,1224);
        _SFD_CV_INIT_EML_IF(0,1,1,1251,1283,-1,1312);
        _SFD_CV_INIT_EML_IF(0,1,2,1326,1436,-1,2097);
        _SFD_CV_INIT_EML_IF(0,1,3,1454,1464,-1,1494);
        _SFD_CV_INIT_EML_IF(0,1,4,1538,1566,-1,1625);
        _SFD_CV_INIT_EML_IF(0,1,5,1630,1648,-1,1674);
        _SFD_CV_INIT_EML_IF(0,1,6,1684,2040,-1,2092);
        _SFD_CV_INIT_EML_IF(0,1,7,2099,2135,-1,2168);
        _SFD_CV_INIT_EML_IF(0,1,8,2170,2179,2250,2328);
        _SFD_CV_INIT_EML_IF(0,1,9,2184,2194,2218,2249);
        _SFD_CV_INIT_EML_IF(0,1,10,2259,2269,2293,2324);

        {
          static int caseStart[] = { 785, 430, 509, 607, 696 };

          static int caseExprEnd[] = { 794, 436, 515, 613, 702 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,413,426,860,5,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 1331, 1356, 1372, 1383, 1395, 1409 };

          static int condEnd[] = { 1352, 1367, 1379, 1388, 1405, 1434 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -2, -3, 4, 5, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,1330,1435,6,0,&(condStart[0]),&(condEnd[0]),
                                11,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1687, 1707, 1727, 1754, 1774, 1794, 1821,
            1841, 1861, 1888, 1908, 1928, 1956, 1976, 1996, 2024 };

          static int condEnd[] = { 1702, 1722, 1742, 1769, 1789, 1809, 1836,
            1856, 1876, 1904, 1924, 1944, 1972, 1992, 2012, 2040 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3, 5, -3, 6, -3,
            7, -3, 8, -3, 9, -3, 10, -3, 11, -3, 12, -3, 13, -3, 14, -3, 15, -3
          };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1687,2040,16,6,&(condStart[0]),&(condEnd[0]),
                                31,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,1166,1180,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,1254,1283,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,1331,1352,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,1356,1367,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,1395,1405,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,1409,1434,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,1541,1566,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,1633,1648,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,8,1687,1702,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,9,1707,1722,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,10,1727,1742,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,11,1754,1769,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,12,1774,1789,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,13,1794,1809,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,14,1821,1836,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,15,1841,1856,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,16,1861,1876,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,17,1888,1904,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,18,1908,1924,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,19,1928,1944,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,20,1956,1972,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,21,1976,1992,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,22,1996,2012,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,23,2024,2040,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,24,2102,2135,-1,5);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_num);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_frameEn);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c3_usedSubCar);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_sel);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c3_bitPerSymb);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_push);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c3_fftLen);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c3_freqDivSubcAlloc);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c3_bitsPerFrame);
        _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c3_u1);
        _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c3_u2);
        _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c3_u3);
        _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c3_u4);
        _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c3_u5);
        _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c3_u6);
        _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c3_u7);
        _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c3_u8);
        _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c3_u9);
        _SFD_SET_DATA_VALUE_PTR(18U, &chartInstance->c3_u10);
        _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance->c3_u11);
        _SFD_SET_DATA_VALUE_PTR(20U, &chartInstance->c3_u12);
        _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c3_u13);
        _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance->c3_u14);
        _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c3_u15);
        _SFD_SET_DATA_VALUE_PTR(24U, &chartInstance->c3_u16);
        _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c3_pop);
        _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c3_frameStart);
        _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c3_state_address);
        _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c3_loopCount_address);
        _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c3_subCarCount_address);
        _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c3_subCar_address);
        _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c3_start_address);
        _SFD_SET_DATA_VALUE_PTR(32U, chartInstance->c3_bitCount_address);
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
  return "w4jWV5JkZqtqdkUgwxW9YB";
}

static void sf_opaque_initialize_c3_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Basic_DMT(void *chartInstanceVar)
{
  enable_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Basic_DMT(void *chartInstanceVar)
{
  disable_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Basic_DMT(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Basic_DMT(SimStruct *S)
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
    initialize_params_c3_Basic_DMT((SFc3_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Basic_DMT(SimStruct *S)
{
  /* Actual parameters from chart:
     bitPerSymb bitsPerFrame fftLen freqDivSubcAlloc u1 u10 u11 u12 u13 u14 u15 u16 u2 u3 u4 u5 u6 u7 u8 u9 usedSubCar
   */
  const char_T *rtParamNames[] = { "bitPerSymb", "bitsPerFrame", "fftLen",
    "freqDivSubcAlloc", "u1", "u10", "u11", "u12", "u13", "u14", "u15", "u16",
    "u2", "u3", "u4", "u5", "u6", "u7", "u8", "u9", "usedSubCar" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for bitPerSymb*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for bitsPerFrame*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for fftLen*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for freqDivSubcAlloc*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for u1*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for u10*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for u11*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for u12*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);

  /* registration for u13*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_DOUBLE);

  /* registration for u14*/
  ssRegDlgParamAsRunTimeParam(S, 9, 9, rtParamNames[9], SS_DOUBLE);

  /* registration for u15*/
  ssRegDlgParamAsRunTimeParam(S, 10, 10, rtParamNames[10], SS_DOUBLE);

  /* registration for u16*/
  ssRegDlgParamAsRunTimeParam(S, 11, 11, rtParamNames[11], SS_DOUBLE);

  /* registration for u2*/
  ssRegDlgParamAsRunTimeParam(S, 12, 12, rtParamNames[12], SS_DOUBLE);

  /* registration for u3*/
  ssRegDlgParamAsRunTimeParam(S, 13, 13, rtParamNames[13], SS_DOUBLE);

  /* registration for u4*/
  ssRegDlgParamAsRunTimeParam(S, 14, 14, rtParamNames[14], SS_DOUBLE);

  /* registration for u5*/
  ssRegDlgParamAsRunTimeParam(S, 15, 15, rtParamNames[15], SS_DOUBLE);

  /* registration for u6*/
  ssRegDlgParamAsRunTimeParam(S, 16, 16, rtParamNames[16], SS_DOUBLE);

  /* registration for u7*/
  ssRegDlgParamAsRunTimeParam(S, 17, 17, rtParamNames[17], SS_DOUBLE);

  /* registration for u8*/
  ssRegDlgParamAsRunTimeParam(S, 18, 18, rtParamNames[18], SS_DOUBLE);

  /* registration for u9*/
  ssRegDlgParamAsRunTimeParam(S, 19, 19, rtParamNames[19], SS_DOUBLE);

  /* registration for usedSubCar*/
  ssRegDlgParamAsRunTimeParam(S, 20, 20, rtParamNames[20], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3877228823U));
  ssSetChecksum1(S,(310323795U));
  ssSetChecksum2(S,(9812002U));
  ssSetChecksum3(S,(227141598U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c3_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Basic_DMT(SimStruct *S)
{
  SFc3_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc3_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Basic_DMT;
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

void c3_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
