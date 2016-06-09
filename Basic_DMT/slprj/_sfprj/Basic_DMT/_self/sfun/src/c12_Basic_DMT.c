/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c12_Basic_DMT.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Basic_DMT_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c12_b_u1                       (0.0)
#define c12_b_u2                       (1.0)
#define c12_b_u3                       (1.0)
#define c12_b_u4                       (1.0)
#define c12_b_u5                       (1.0)
#define c12_b_u6                       (1.0)
#define c12_b_u7                       (1.0)
#define c12_b_u8                       (1.0)
#define c12_b_u9                       (0.0)
#define c12_b_u10                      (1.0)
#define c12_b_u11                      (1.0)
#define c12_b_u12                      (1.0)
#define c12_b_u13                      (1.0)
#define c12_b_u14                      (1.0)
#define c12_b_u15                      (1.0)
#define c12_b_u16                      (1.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c12_debug_family_names[50] = { "u1", "u2", "u3", "u4", "u5",
  "u6", "u7", "u8", "u9", "u10", "u11", "u12", "u13", "u14", "u15", "u16",
  "nargin", "nargout", "i1", "i2", "i3", "i4", "i5", "i6", "i7", "i8", "i9",
  "i10", "i11", "i12", "i13", "i14", "i15", "i16", "o1", "o2", "o3", "o4", "o5",
  "o6", "o7", "o8", "o9", "o10", "o11", "o12", "o13", "o14", "o15", "o16" };

static const mxArray *c12_eml_mx;
static const mxArray *c12_b_eml_mx;

/* Function Declarations */
static void initialize_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance);
static void initialize_params_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *chartInstance);
static void disable_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_Basic_DMT
  (SFc12_Basic_DMTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *
  chartInstance);
static void set_sim_state_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_st);
static void finalize_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance);
static void mdl_start_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *chartInstance);
static void c12_chartstep_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance);
static void initSimStructsc12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static cint16_T c12_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_b_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static void c12_info_helper(const mxArray **c12_info);
static const mxArray *c12_emlrt_marshallOut(const char * c12_u);
static const mxArray *c12_b_emlrt_marshallOut(const uint32_T c12_u);
static void c12_strcmpi(SFc12_Basic_DMTInstanceStruct *chartInstance);
static void c12_eml_scalar_eg(SFc12_Basic_DMTInstanceStruct *chartInstance);
static cint16_T c12_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static void c12_b_strcmpi(SFc12_Basic_DMTInstanceStruct *chartInstance);
static cint16_T c12_b_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_c_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_d_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_e_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_f_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_g_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_h_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_i_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_j_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_k_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_l_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_m_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static cint16_T c12_n_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_c_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static cint16_T c12_d_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_b_o1, const char_T *c12_identifier);
static cint16_T c12_e_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_f_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_Basic_DMT, const char_T
  *c12_identifier);
static uint8_T c12_g_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc12_Basic_DMTInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c12_is_active_c12_Basic_DMT = 0U;
  sf_mex_assign(&c12_b_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 10U, 15, "WordLength", 6, 9.0, 15, "FractionLength", 6,
    3.0, 15, "BinaryPoint", 6, 3.0, 15, "Slope", 6, 0.125, 15, "FixedExponent",
    6, -3.0), true);
  sf_mex_assign(&c12_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
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

static void initialize_params_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c12_d0;
  real_T c12_d1;
  real_T c12_d2;
  real_T c12_d3;
  real_T c12_d4;
  real_T c12_d5;
  real_T c12_d6;
  real_T c12_d7;
  real_T c12_d8;
  real_T c12_d9;
  real_T c12_d10;
  real_T c12_d11;
  real_T c12_d12;
  real_T c12_d13;
  real_T c12_d14;
  real_T c12_d15;
  sf_mex_import_named("u1", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c12_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u1 = c12_d0;
  sf_mex_import_named("u2", sf_mex_get_sfun_param(chartInstance->S, 8, 0),
                      &c12_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u2 = c12_d1;
  sf_mex_import_named("u3", sf_mex_get_sfun_param(chartInstance->S, 9, 0),
                      &c12_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u3 = c12_d2;
  sf_mex_import_named("u4", sf_mex_get_sfun_param(chartInstance->S, 10, 0),
                      &c12_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u4 = c12_d3;
  sf_mex_import_named("u5", sf_mex_get_sfun_param(chartInstance->S, 11, 0),
                      &c12_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u5 = c12_d4;
  sf_mex_import_named("u6", sf_mex_get_sfun_param(chartInstance->S, 12, 0),
                      &c12_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u6 = c12_d5;
  sf_mex_import_named("u7", sf_mex_get_sfun_param(chartInstance->S, 13, 0),
                      &c12_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u7 = c12_d6;
  sf_mex_import_named("u8", sf_mex_get_sfun_param(chartInstance->S, 14, 0),
                      &c12_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u8 = c12_d7;
  sf_mex_import_named("u9", sf_mex_get_sfun_param(chartInstance->S, 15, 0),
                      &c12_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u9 = c12_d8;
  sf_mex_import_named("u10", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c12_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u10 = c12_d9;
  sf_mex_import_named("u11", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c12_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u11 = c12_d10;
  sf_mex_import_named("u12", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c12_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u12 = c12_d11;
  sf_mex_import_named("u13", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c12_d12, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u13 = c12_d12;
  sf_mex_import_named("u14", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c12_d13, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u14 = c12_d13;
  sf_mex_import_named("u15", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c12_d14, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u15 = c12_d14;
  sf_mex_import_named("u16", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c12_d15, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_u16 = c12_d15;
}

static void enable_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c12_update_debugger_state_c12_Basic_DMT
  (SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *
  chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  const mxArray *c12_b_y = NULL;
  cint16_T c12_u;
  const mxArray *c12_c_y = NULL;
  const mxArray *c12_d_y = NULL;
  cint16_T c12_b_u;
  const mxArray *c12_e_y = NULL;
  const mxArray *c12_f_y = NULL;
  cint16_T c12_c_u;
  const mxArray *c12_g_y = NULL;
  const mxArray *c12_h_y = NULL;
  cint16_T c12_d_u;
  const mxArray *c12_i_y = NULL;
  const mxArray *c12_j_y = NULL;
  cint16_T c12_e_u;
  const mxArray *c12_k_y = NULL;
  const mxArray *c12_l_y = NULL;
  cint16_T c12_f_u;
  const mxArray *c12_m_y = NULL;
  const mxArray *c12_n_y = NULL;
  cint16_T c12_g_u;
  const mxArray *c12_o_y = NULL;
  const mxArray *c12_p_y = NULL;
  cint16_T c12_h_u;
  const mxArray *c12_q_y = NULL;
  const mxArray *c12_r_y = NULL;
  cint16_T c12_i_u;
  const mxArray *c12_s_y = NULL;
  const mxArray *c12_t_y = NULL;
  cint16_T c12_j_u;
  const mxArray *c12_u_y = NULL;
  const mxArray *c12_v_y = NULL;
  cint16_T c12_k_u;
  const mxArray *c12_w_y = NULL;
  const mxArray *c12_x_y = NULL;
  cint16_T c12_l_u;
  const mxArray *c12_y_y = NULL;
  const mxArray *c12_ab_y = NULL;
  cint16_T c12_m_u;
  const mxArray *c12_bb_y = NULL;
  const mxArray *c12_cb_y = NULL;
  cint16_T c12_n_u;
  const mxArray *c12_db_y = NULL;
  const mxArray *c12_eb_y = NULL;
  cint16_T c12_o_u;
  const mxArray *c12_fb_y = NULL;
  const mxArray *c12_gb_y = NULL;
  cint16_T c12_p_u;
  const mxArray *c12_hb_y = NULL;
  uint8_T c12_hoistedGlobal;
  uint8_T c12_q_u;
  const mxArray *c12_ib_y = NULL;
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellmatrix(17, 1), false);
  c12_b_y = NULL;
  c12_u.re = chartInstance->c12_o1->re;
  c12_u.im = chartInstance->c12_o1->im;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_c_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_d_y = NULL;
  c12_b_u.re = chartInstance->c12_o10->re;
  c12_b_u.im = chartInstance->c12_o10->im;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_d_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_e_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 1, c12_d_y);
  c12_f_y = NULL;
  c12_c_u.re = chartInstance->c12_o11->re;
  c12_c_u.im = chartInstance->c12_o11->im;
  c12_g_y = NULL;
  sf_mex_assign(&c12_g_y, sf_mex_create("y", &c12_c_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_f_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_g_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 2, c12_f_y);
  c12_h_y = NULL;
  c12_d_u.re = chartInstance->c12_o12->re;
  c12_d_u.im = chartInstance->c12_o12->im;
  c12_i_y = NULL;
  sf_mex_assign(&c12_i_y, sf_mex_create("y", &c12_d_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_h_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_i_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 3, c12_h_y);
  c12_j_y = NULL;
  c12_e_u.re = chartInstance->c12_o13->re;
  c12_e_u.im = chartInstance->c12_o13->im;
  c12_k_y = NULL;
  sf_mex_assign(&c12_k_y, sf_mex_create("y", &c12_e_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_j_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_k_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 4, c12_j_y);
  c12_l_y = NULL;
  c12_f_u.re = chartInstance->c12_o14->re;
  c12_f_u.im = chartInstance->c12_o14->im;
  c12_m_y = NULL;
  sf_mex_assign(&c12_m_y, sf_mex_create("y", &c12_f_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_l_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_m_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 5, c12_l_y);
  c12_n_y = NULL;
  c12_g_u.re = chartInstance->c12_o15->re;
  c12_g_u.im = chartInstance->c12_o15->im;
  c12_o_y = NULL;
  sf_mex_assign(&c12_o_y, sf_mex_create("y", &c12_g_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_n_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_o_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 6, c12_n_y);
  c12_p_y = NULL;
  c12_h_u.re = chartInstance->c12_o16->re;
  c12_h_u.im = chartInstance->c12_o16->im;
  c12_q_y = NULL;
  sf_mex_assign(&c12_q_y, sf_mex_create("y", &c12_h_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_p_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_q_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 7, c12_p_y);
  c12_r_y = NULL;
  c12_i_u.re = chartInstance->c12_o2->re;
  c12_i_u.im = chartInstance->c12_o2->im;
  c12_s_y = NULL;
  sf_mex_assign(&c12_s_y, sf_mex_create("y", &c12_i_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_r_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_s_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 8, c12_r_y);
  c12_t_y = NULL;
  c12_j_u.re = chartInstance->c12_o3->re;
  c12_j_u.im = chartInstance->c12_o3->im;
  c12_u_y = NULL;
  sf_mex_assign(&c12_u_y, sf_mex_create("y", &c12_j_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_t_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_u_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 9, c12_t_y);
  c12_v_y = NULL;
  c12_k_u.re = chartInstance->c12_o4->re;
  c12_k_u.im = chartInstance->c12_o4->im;
  c12_w_y = NULL;
  sf_mex_assign(&c12_w_y, sf_mex_create("y", &c12_k_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_v_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_w_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 10, c12_v_y);
  c12_x_y = NULL;
  c12_l_u.re = chartInstance->c12_o5->re;
  c12_l_u.im = chartInstance->c12_o5->im;
  c12_y_y = NULL;
  sf_mex_assign(&c12_y_y, sf_mex_create("y", &c12_l_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_x_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx),
    15, "simulinkarray", 14, c12_y_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 11, c12_x_y);
  c12_ab_y = NULL;
  c12_m_u.re = chartInstance->c12_o6->re;
  c12_m_u.im = chartInstance->c12_o6->im;
  c12_bb_y = NULL;
  sf_mex_assign(&c12_bb_y, sf_mex_create("y", &c12_m_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_ab_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx), 15,
    "simulinkarray", 14, c12_bb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 12, c12_ab_y);
  c12_cb_y = NULL;
  c12_n_u.re = chartInstance->c12_o7->re;
  c12_n_u.im = chartInstance->c12_o7->im;
  c12_db_y = NULL;
  sf_mex_assign(&c12_db_y, sf_mex_create("y", &c12_n_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_cb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx), 15,
    "simulinkarray", 14, c12_db_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 13, c12_cb_y);
  c12_eb_y = NULL;
  c12_o_u.re = chartInstance->c12_o8->re;
  c12_o_u.im = chartInstance->c12_o8->im;
  c12_fb_y = NULL;
  sf_mex_assign(&c12_fb_y, sf_mex_create("y", &c12_o_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_eb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx), 15,
    "simulinkarray", 14, c12_fb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 14, c12_eb_y);
  c12_gb_y = NULL;
  c12_p_u.re = chartInstance->c12_o9->re;
  c12_p_u.im = chartInstance->c12_o9->im;
  c12_hb_y = NULL;
  sf_mex_assign(&c12_hb_y, sf_mex_create("y", &c12_p_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_gb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx), 15,
    "simulinkarray", 14, c12_hb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c12_y, 15, c12_gb_y);
  c12_hoistedGlobal = chartInstance->c12_is_active_c12_Basic_DMT;
  c12_q_u = c12_hoistedGlobal;
  c12_ib_y = NULL;
  sf_mex_assign(&c12_ib_y, sf_mex_create("y", &c12_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 16, c12_ib_y);
  sf_mex_assign(&c12_st, c12_y, false);
  return c12_st;
}

static void set_sim_state_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  chartInstance->c12_doneDoubleBufferReInit = true;
  c12_u = sf_mex_dup(c12_st);
  *chartInstance->c12_o1 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 0)), "o1");
  *chartInstance->c12_o10 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 1)), "o10");
  *chartInstance->c12_o11 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 2)), "o11");
  *chartInstance->c12_o12 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 3)), "o12");
  *chartInstance->c12_o13 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 4)), "o13");
  *chartInstance->c12_o14 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 5)), "o14");
  *chartInstance->c12_o15 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 6)), "o15");
  *chartInstance->c12_o16 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 7)), "o16");
  *chartInstance->c12_o2 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 8)), "o2");
  *chartInstance->c12_o3 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 9)), "o3");
  *chartInstance->c12_o4 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 10)), "o4");
  *chartInstance->c12_o5 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 11)), "o5");
  *chartInstance->c12_o6 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 12)), "o6");
  *chartInstance->c12_o7 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 13)), "o7");
  *chartInstance->c12_o8 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 14)), "o8");
  *chartInstance->c12_o9 = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 15)), "o9");
  chartInstance->c12_is_active_c12_Basic_DMT = c12_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 16)),
     "is_active_c12_Basic_DMT");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_Basic_DMT(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
  sf_mex_destroy(&c12_eml_mx);
  sf_mex_destroy(&c12_b_eml_mx);
}

static void sf_gateway_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c12_sfEvent);
  chartInstance->c12_sfEvent = CALL_EVENT;
  c12_chartstep_c12_Basic_DMT(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u1, 32U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u2, 33U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u3, 34U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u4, 35U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u5, 36U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u6, 37U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u7, 38U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u8, 39U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u9, 40U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u10, 41U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u11, 42U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u12, 43U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u13, 44U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u14, 45U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u15, 46U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_u16, 47U);
}

static void mdl_start_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c12_chartstep_c12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance)
{
  cint16_T c12_b_i1;
  cint16_T c12_b_i2;
  cint16_T c12_b_i3;
  cint16_T c12_b_i4;
  cint16_T c12_b_i5;
  cint16_T c12_b_i6;
  cint16_T c12_b_i7;
  cint16_T c12_b_i8;
  cint16_T c12_b_i9;
  cint16_T c12_b_i10;
  cint16_T c12_b_i11;
  cint16_T c12_b_i12;
  cint16_T c12_b_i13;
  cint16_T c12_b_i14;
  cint16_T c12_b_i15;
  cint16_T c12_b_i16;
  uint32_T c12_debug_family_var_map[50];
  real_T c12_c_u1;
  real_T c12_c_u2;
  real_T c12_c_u3;
  real_T c12_c_u4;
  real_T c12_c_u5;
  real_T c12_c_u6;
  real_T c12_c_u7;
  real_T c12_c_u8;
  real_T c12_c_u9;
  real_T c12_c_u10;
  real_T c12_c_u11;
  real_T c12_c_u12;
  real_T c12_c_u13;
  real_T c12_c_u14;
  real_T c12_c_u15;
  real_T c12_c_u16;
  real_T c12_nargin = 32.0;
  real_T c12_nargout = 16.0;
  cint16_T c12_b_o1;
  cint16_T c12_b_o2;
  cint16_T c12_b_o3;
  cint16_T c12_b_o4;
  cint16_T c12_b_o5;
  cint16_T c12_b_o6;
  cint16_T c12_b_o7;
  cint16_T c12_b_o8;
  cint16_T c12_b_o9;
  cint16_T c12_b_o10;
  cint16_T c12_b_o11;
  cint16_T c12_b_o12;
  cint16_T c12_b_o13;
  cint16_T c12_b_o14;
  cint16_T c12_b_o15;
  cint16_T c12_b_o16;
  cint16_T c12_a;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  int16_T c12_b_ar;
  int16_T c12_b_ai;
  int16_T c12_b_cr;
  int16_T c12_b_ci;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c12_sfEvent);
  c12_b_i1 = *chartInstance->c12_i1;
  c12_b_i2 = *chartInstance->c12_i2;
  c12_b_i3 = *chartInstance->c12_i3;
  c12_b_i4 = *chartInstance->c12_i4;
  c12_b_i5 = *chartInstance->c12_i5;
  c12_b_i6 = *chartInstance->c12_i6;
  c12_b_i7 = *chartInstance->c12_i7;
  c12_b_i8 = *chartInstance->c12_i8;
  c12_b_i9 = *chartInstance->c12_i9;
  c12_b_i10 = *chartInstance->c12_i10;
  c12_b_i11 = *chartInstance->c12_i11;
  c12_b_i12 = *chartInstance->c12_i12;
  c12_b_i13 = *chartInstance->c12_i13;
  c12_b_i14 = *chartInstance->c12_i14;
  c12_b_i15 = *chartInstance->c12_i15;
  c12_b_i16 = *chartInstance->c12_i16;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 50U, 50U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u1, 0U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u2, 1U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u3, 2U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u4, 3U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u5, 4U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u6, 5U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u7, 6U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u8, 7U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u9, 8U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u10, 9U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u11, 10U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u12, 11U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u13, 12U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u14, 13U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u15, 14U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_c_u16, 15U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 16U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 17U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i1, 18U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i2, 19U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i3, 20U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i4, 21U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i5, 22U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i6, 23U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i7, 24U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i8, 25U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i9, 26U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i10, 27U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i11, 28U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i12, 29U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i13, 30U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i14, 31U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i15, 32U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_i16, 33U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o1, 34U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o2, 35U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o3, 36U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o4, 37U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o5, 38U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o6, 39U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o7, 40U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o8, 41U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o9, 42U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o10, 43U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o11, 44U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o12, 45U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o13, 46U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o14, 47U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o15, 48U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_o16, 49U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  c12_c_u16 = c12_b_u16;
  c12_c_u15 = c12_b_u15;
  c12_c_u14 = c12_b_u14;
  c12_c_u13 = c12_b_u13;
  c12_c_u12 = c12_b_u12;
  c12_c_u11 = c12_b_u11;
  c12_c_u10 = c12_b_u10;
  c12_c_u9 = c12_b_u9;
  c12_c_u8 = c12_b_u8;
  c12_c_u7 = c12_b_u7;
  c12_c_u6 = c12_b_u6;
  c12_c_u5 = c12_b_u5;
  c12_c_u4 = c12_b_u4;
  c12_c_u3 = c12_b_u3;
  c12_c_u2 = c12_b_u2;
  c12_c_u1 = c12_b_u1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 9);
  c12_b_o1 = c12_mtimes(chartInstance, c12_b_i1);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 10);
  c12_b_o2 = c12_b_mtimes(chartInstance, c12_b_i2);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 11);
  c12_b_o3 = c12_c_mtimes(chartInstance, c12_b_i3);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 12);
  c12_b_o4 = c12_d_mtimes(chartInstance, c12_b_i4);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 13);
  c12_b_o5 = c12_e_mtimes(chartInstance, c12_b_i5);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 14);
  c12_b_o6 = c12_f_mtimes(chartInstance, c12_b_i6);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 15);
  c12_b_o7 = c12_g_mtimes(chartInstance, c12_b_i7);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 16);
  c12_b_o8 = c12_h_mtimes(chartInstance, c12_b_i8);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 17);
  c12_b_o9 = c12_i_mtimes(chartInstance, c12_b_i9);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 18);
  c12_b_o10 = c12_j_mtimes(chartInstance, c12_b_i10);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 19);
  c12_b_o11 = c12_k_mtimes(chartInstance, c12_b_i11);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 20);
  c12_b_o12 = c12_l_mtimes(chartInstance, c12_b_i12);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 21);
  c12_b_o13 = c12_m_mtimes(chartInstance, c12_b_i13);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 22);
  c12_b_o14 = c12_n_mtimes(chartInstance, c12_b_i14);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 23);
  c12_a = c12_b_i15;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a.re;
  c12_ai = c12_a.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_a.re = c12_cr;
  c12_a.im = c12_ci;
  c12_b_o15 = c12_a;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 24);
  c12_a = c12_b_i16;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_b_ar = c12_a.re;
  c12_b_ai = c12_a.im;
  c12_b_cr = c12_b_ar;
  c12_b_ci = c12_b_ai;
  c12_a.re = c12_b_cr;
  c12_a.im = c12_b_ci;
  c12_b_o16 = c12_a;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c12_o1 = c12_b_o1;
  *chartInstance->c12_o2 = c12_b_o2;
  *chartInstance->c12_o3 = c12_b_o3;
  *chartInstance->c12_o4 = c12_b_o4;
  *chartInstance->c12_o5 = c12_b_o5;
  *chartInstance->c12_o6 = c12_b_o6;
  *chartInstance->c12_o7 = c12_b_o7;
  *chartInstance->c12_o8 = c12_b_o8;
  *chartInstance->c12_o9 = c12_b_o9;
  *chartInstance->c12_o10 = c12_b_o10;
  *chartInstance->c12_o11 = c12_b_o11;
  *chartInstance->c12_o12 = c12_b_o12;
  *chartInstance->c12_o13 = c12_b_o13;
  *chartInstance->c12_o14 = c12_b_o14;
  *chartInstance->c12_o15 = c12_b_o15;
  *chartInstance->c12_o16 = c12_b_o16;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c12_sfEvent);
}

static void initSimStructsc12_Basic_DMT(SFc12_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber)
{
  (void)c12_machineNumber;
  (void)c12_chartNumber;
  (void)c12_instanceNumber;
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  cint16_T c12_u;
  const mxArray *c12_y = NULL;
  cint16_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u = *(cint16_T *)c12_inData;
  c12_y = NULL;
  c12_b_u.re = c12_u.re;
  c12_b_u.im = c12_u.im;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx), 15,
    "simulinkarray", 14, c12_b_y, 15, "fimathislocal", 3, false), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static cint16_T c12_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  cint16_T c12_y;
  const mxArray *c12_mxFi = NULL;
  const mxArray *c12_mxInt = NULL;
  cint16_T c12_ic0;
  (void)chartInstance;
  sf_mex_check_fi(c12_parentId, c12_u, true, 0U, NULL, c12_eml_mx, c12_b_eml_mx);
  sf_mex_assign(&c12_mxFi, sf_mex_dup(c12_u), false);
  sf_mex_assign(&c12_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c12_mxFi)), false);
  sf_mex_import(c12_parentId, sf_mex_dup(c12_mxInt), &c12_ic0, 1, 4, 1U, 0, 0U,
                0);
  sf_mex_destroy(&c12_mxFi);
  sf_mex_destroy(&c12_mxInt);
  c12_y = c12_ic0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_o16;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  cint16_T c12_y;
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c12_b_o16 = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_o16), &c12_thisId);
  sf_mex_destroy(&c12_b_o16);
  *(cint16_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static real_T c12_b_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d16;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d16, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d16;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_createstruct("structure", 2, 29, 1),
                false);
  c12_info_helper(&c12_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static void c12_info_helper(const mxArray **c12_info)
{
  const mxArray *c12_rhs0 = NULL;
  const mxArray *c12_lhs0 = NULL;
  const mxArray *c12_rhs1 = NULL;
  const mxArray *c12_lhs1 = NULL;
  const mxArray *c12_rhs2 = NULL;
  const mxArray *c12_lhs2 = NULL;
  const mxArray *c12_rhs3 = NULL;
  const mxArray *c12_lhs3 = NULL;
  const mxArray *c12_rhs4 = NULL;
  const mxArray *c12_lhs4 = NULL;
  const mxArray *c12_rhs5 = NULL;
  const mxArray *c12_lhs5 = NULL;
  const mxArray *c12_rhs6 = NULL;
  const mxArray *c12_lhs6 = NULL;
  const mxArray *c12_rhs7 = NULL;
  const mxArray *c12_lhs7 = NULL;
  const mxArray *c12_rhs8 = NULL;
  const mxArray *c12_lhs8 = NULL;
  const mxArray *c12_rhs9 = NULL;
  const mxArray *c12_lhs9 = NULL;
  const mxArray *c12_rhs10 = NULL;
  const mxArray *c12_lhs10 = NULL;
  const mxArray *c12_rhs11 = NULL;
  const mxArray *c12_lhs11 = NULL;
  const mxArray *c12_rhs12 = NULL;
  const mxArray *c12_lhs12 = NULL;
  const mxArray *c12_rhs13 = NULL;
  const mxArray *c12_lhs13 = NULL;
  const mxArray *c12_rhs14 = NULL;
  const mxArray *c12_lhs14 = NULL;
  const mxArray *c12_rhs15 = NULL;
  const mxArray *c12_lhs15 = NULL;
  const mxArray *c12_rhs16 = NULL;
  const mxArray *c12_lhs16 = NULL;
  const mxArray *c12_rhs17 = NULL;
  const mxArray *c12_lhs17 = NULL;
  const mxArray *c12_rhs18 = NULL;
  const mxArray *c12_lhs18 = NULL;
  const mxArray *c12_rhs19 = NULL;
  const mxArray *c12_lhs19 = NULL;
  const mxArray *c12_rhs20 = NULL;
  const mxArray *c12_lhs20 = NULL;
  const mxArray *c12_rhs21 = NULL;
  const mxArray *c12_lhs21 = NULL;
  const mxArray *c12_rhs22 = NULL;
  const mxArray *c12_lhs22 = NULL;
  const mxArray *c12_rhs23 = NULL;
  const mxArray *c12_lhs23 = NULL;
  const mxArray *c12_rhs24 = NULL;
  const mxArray *c12_lhs24 = NULL;
  const mxArray *c12_rhs25 = NULL;
  const mxArray *c12_lhs25 = NULL;
  const mxArray *c12_rhs26 = NULL;
  const mxArray *c12_lhs26 = NULL;
  const mxArray *c12_rhs27 = NULL;
  const mxArray *c12_lhs27 = NULL;
  const mxArray *c12_rhs28 = NULL;
  const mxArray *c12_lhs28 = NULL;
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1346510384U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c12_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isfi"), "name", "name", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c12_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c12_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("get"), "name", "name", 3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c12_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("times"), "name", "name", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1346510386U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c12_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c12_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isfi"), "name", "name", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c12_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c12_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isscaledtype"), "name",
                  "name", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1346510380U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c12_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isfixed"), "name", "name", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1346510378U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c12_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("get"), "name", "name", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c12_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isfi"), "name", "name", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c12_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("get"), "name", "name", 12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.fimath"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c12_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("strcmpi"), "name", "name",
                  13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c12_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c12_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c12_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("intmax"), "name", "name", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c12_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c12_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("min"), "name", "name", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c12_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c12_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 20);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 20);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c12_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 21);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c12_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 22);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 22);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c12_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 23);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c12_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 24);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c12_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 25);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 25);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c12_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 26);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c12_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("get"), "name", "name", 27);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 27);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c12_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_fixpt_times"), "name",
                  "name", 28);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 28);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_fixpt_times.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1289519646U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c12_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs28), "lhs", "lhs",
                  28);
  sf_mex_destroy(&c12_rhs0);
  sf_mex_destroy(&c12_lhs0);
  sf_mex_destroy(&c12_rhs1);
  sf_mex_destroy(&c12_lhs1);
  sf_mex_destroy(&c12_rhs2);
  sf_mex_destroy(&c12_lhs2);
  sf_mex_destroy(&c12_rhs3);
  sf_mex_destroy(&c12_lhs3);
  sf_mex_destroy(&c12_rhs4);
  sf_mex_destroy(&c12_lhs4);
  sf_mex_destroy(&c12_rhs5);
  sf_mex_destroy(&c12_lhs5);
  sf_mex_destroy(&c12_rhs6);
  sf_mex_destroy(&c12_lhs6);
  sf_mex_destroy(&c12_rhs7);
  sf_mex_destroy(&c12_lhs7);
  sf_mex_destroy(&c12_rhs8);
  sf_mex_destroy(&c12_lhs8);
  sf_mex_destroy(&c12_rhs9);
  sf_mex_destroy(&c12_lhs9);
  sf_mex_destroy(&c12_rhs10);
  sf_mex_destroy(&c12_lhs10);
  sf_mex_destroy(&c12_rhs11);
  sf_mex_destroy(&c12_lhs11);
  sf_mex_destroy(&c12_rhs12);
  sf_mex_destroy(&c12_lhs12);
  sf_mex_destroy(&c12_rhs13);
  sf_mex_destroy(&c12_lhs13);
  sf_mex_destroy(&c12_rhs14);
  sf_mex_destroy(&c12_lhs14);
  sf_mex_destroy(&c12_rhs15);
  sf_mex_destroy(&c12_lhs15);
  sf_mex_destroy(&c12_rhs16);
  sf_mex_destroy(&c12_lhs16);
  sf_mex_destroy(&c12_rhs17);
  sf_mex_destroy(&c12_lhs17);
  sf_mex_destroy(&c12_rhs18);
  sf_mex_destroy(&c12_lhs18);
  sf_mex_destroy(&c12_rhs19);
  sf_mex_destroy(&c12_lhs19);
  sf_mex_destroy(&c12_rhs20);
  sf_mex_destroy(&c12_lhs20);
  sf_mex_destroy(&c12_rhs21);
  sf_mex_destroy(&c12_lhs21);
  sf_mex_destroy(&c12_rhs22);
  sf_mex_destroy(&c12_lhs22);
  sf_mex_destroy(&c12_rhs23);
  sf_mex_destroy(&c12_lhs23);
  sf_mex_destroy(&c12_rhs24);
  sf_mex_destroy(&c12_lhs24);
  sf_mex_destroy(&c12_rhs25);
  sf_mex_destroy(&c12_lhs25);
  sf_mex_destroy(&c12_rhs26);
  sf_mex_destroy(&c12_lhs26);
  sf_mex_destroy(&c12_rhs27);
  sf_mex_destroy(&c12_lhs27);
  sf_mex_destroy(&c12_rhs28);
  sf_mex_destroy(&c12_lhs28);
}

static const mxArray *c12_emlrt_marshallOut(const char * c12_u)
{
  const mxArray *c12_y = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c12_u)), false);
  return c12_y;
}

static const mxArray *c12_b_emlrt_marshallOut(const uint32_T c12_u)
{
  const mxArray *c12_y = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 7, 0U, 0U, 0U, 0), false);
  return c12_y;
}

static void c12_strcmpi(SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  c12_eml_scalar_eg(chartInstance);
  c12_eml_scalar_eg(chartInstance);
}

static void c12_eml_scalar_eg(SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static cint16_T c12_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_cr;
  int16_T c12_ci;
  (void)c12_a0;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_cr = 0;
  c12_ci = 0;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static void c12_b_strcmpi(SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  c12_eml_scalar_eg(chartInstance);
  c12_eml_scalar_eg(chartInstance);
}

static cint16_T c12_b_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_c_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_d_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_e_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_f_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_g_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_h_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_i_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_cr;
  int16_T c12_ci;
  (void)c12_a0;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_cr = 0;
  c12_ci = 0;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_j_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_k_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_l_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_m_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static cint16_T c12_n_mtimes(SFc12_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c12_a0)
{
  cint16_T c12_cout;
  int16_T c12_ar;
  int16_T c12_ai;
  int16_T c12_cr;
  int16_T c12_ci;
  c12_strcmpi(chartInstance);
  c12_b_strcmpi(chartInstance);
  c12_ar = c12_a0.re;
  c12_ai = c12_a0.im;
  c12_cr = c12_ar;
  c12_ci = c12_ai;
  c12_cout.re = c12_cr;
  c12_cout.im = c12_ci;
  return c12_cout;
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int32_T c12_c_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i0, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  cint16_T c12_u;
  const mxArray *c12_y = NULL;
  cint16_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u = *(cint16_T *)c12_inData;
  c12_y = NULL;
  c12_b_u.re = c12_u.re;
  c12_b_u.im = c12_u.im;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c12_eml_mx), 15, "numerictype", 14, sf_mex_dup(c12_b_eml_mx), 15,
    "simulinkarray", 14, c12_b_y, 15, "fimathislocal", 3, true), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static cint16_T c12_d_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_b_o1, const char_T *c12_identifier)
{
  cint16_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_o1),
    &c12_thisId);
  sf_mex_destroy(&c12_b_o1);
  return c12_y;
}

static cint16_T c12_e_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  cint16_T c12_y;
  const mxArray *c12_mxFi = NULL;
  const mxArray *c12_mxInt = NULL;
  cint16_T c12_ic1;
  (void)chartInstance;
  sf_mex_check_fi(c12_parentId, c12_u, true, 0U, NULL, c12_eml_mx, c12_b_eml_mx);
  sf_mex_assign(&c12_mxFi, sf_mex_dup(c12_u), false);
  sf_mex_assign(&c12_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c12_mxFi)), false);
  sf_mex_import(c12_parentId, sf_mex_dup(c12_mxInt), &c12_ic1, 1, 4, 1U, 0, 0U,
                0);
  sf_mex_destroy(&c12_mxFi);
  sf_mex_destroy(&c12_mxInt);
  c12_y = c12_ic1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_o1;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  cint16_T c12_y;
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c12_b_o1 = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_o1),
    &c12_thisId);
  sf_mex_destroy(&c12_b_o1);
  *(cint16_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_f_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_Basic_DMT, const char_T
  *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_Basic_DMT), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_Basic_DMT);
  return c12_y;
}

static uint8_T c12_g_emlrt_marshallIn(SFc12_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc12_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c12_i1 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c12_o1 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_o2 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c12_o3 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c12_o4 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c12_o5 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c12_o6 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c12_o7 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c12_o8 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c12_o9 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c12_o10 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c12_o11 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c12_o12 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c12_o13 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c12_o14 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c12_o15 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c12_o16 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c12_i2 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_i3 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c12_i4 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c12_i5 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c12_i6 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c12_i7 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c12_i8 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c12_i9 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c12_i10 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c12_i11 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c12_i12 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c12_i13 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c12_i14 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c12_i15 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c12_i16 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 15);
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

void sf_c12_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4082365850U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(863354404U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4236295703U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3141335925U);
}

mxArray* sf_c12_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c12_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sHw7e1OYdV2mmpdhfNXUcC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,16,3,dataFields);

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

      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,16,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,16,3,dataFields);

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

      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c12_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c12_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c12_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c12_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c12_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c12_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[10],T\"o1\",},{M[1],M[36],T\"o10\",},{M[1],M[37],T\"o11\",},{M[1],M[38],T\"o12\",},{M[1],M[39],T\"o13\",},{M[1],M[40],T\"o14\",},{M[1],M[41],T\"o15\",},{M[1],M[42],T\"o16\",},{M[1],M[28],T\"o2\",},{M[1],M[29],T\"o3\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[30],T\"o4\",},{M[1],M[31],T\"o5\",},{M[1],M[32],T\"o6\",},{M[1],M[33],T\"o7\",},{M[1],M[34],T\"o8\",},{M[1],M[35],T\"o9\",},{M[8],M[0],T\"is_active_c12_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 17, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc12_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           12,
           1,
           1,
           0,
           48,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"i1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"o1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"o2");
          _SFD_SET_DATA_PROPS(3,2,0,1,"o3");
          _SFD_SET_DATA_PROPS(4,2,0,1,"o4");
          _SFD_SET_DATA_PROPS(5,2,0,1,"o5");
          _SFD_SET_DATA_PROPS(6,2,0,1,"o6");
          _SFD_SET_DATA_PROPS(7,2,0,1,"o7");
          _SFD_SET_DATA_PROPS(8,2,0,1,"o8");
          _SFD_SET_DATA_PROPS(9,2,0,1,"o9");
          _SFD_SET_DATA_PROPS(10,2,0,1,"o10");
          _SFD_SET_DATA_PROPS(11,2,0,1,"o11");
          _SFD_SET_DATA_PROPS(12,2,0,1,"o12");
          _SFD_SET_DATA_PROPS(13,2,0,1,"o13");
          _SFD_SET_DATA_PROPS(14,2,0,1,"o14");
          _SFD_SET_DATA_PROPS(15,2,0,1,"o15");
          _SFD_SET_DATA_PROPS(16,2,0,1,"o16");
          _SFD_SET_DATA_PROPS(17,1,1,0,"i2");
          _SFD_SET_DATA_PROPS(18,1,1,0,"i3");
          _SFD_SET_DATA_PROPS(19,1,1,0,"i4");
          _SFD_SET_DATA_PROPS(20,1,1,0,"i5");
          _SFD_SET_DATA_PROPS(21,1,1,0,"i6");
          _SFD_SET_DATA_PROPS(22,1,1,0,"i7");
          _SFD_SET_DATA_PROPS(23,1,1,0,"i8");
          _SFD_SET_DATA_PROPS(24,1,1,0,"i9");
          _SFD_SET_DATA_PROPS(25,1,1,0,"i10");
          _SFD_SET_DATA_PROPS(26,1,1,0,"i11");
          _SFD_SET_DATA_PROPS(27,1,1,0,"i12");
          _SFD_SET_DATA_PROPS(28,1,1,0,"i13");
          _SFD_SET_DATA_PROPS(29,1,1,0,"i14");
          _SFD_SET_DATA_PROPS(30,1,1,0,"i15");
          _SFD_SET_DATA_PROPS(31,1,1,0,"i16");
          _SFD_SET_DATA_PROPS(32,10,0,0,"u1");
          _SFD_SET_DATA_PROPS(33,10,0,0,"u2");
          _SFD_SET_DATA_PROPS(34,10,0,0,"u3");
          _SFD_SET_DATA_PROPS(35,10,0,0,"u4");
          _SFD_SET_DATA_PROPS(36,10,0,0,"u5");
          _SFD_SET_DATA_PROPS(37,10,0,0,"u6");
          _SFD_SET_DATA_PROPS(38,10,0,0,"u7");
          _SFD_SET_DATA_PROPS(39,10,0,0,"u8");
          _SFD_SET_DATA_PROPS(40,10,0,0,"u9");
          _SFD_SET_DATA_PROPS(41,10,0,0,"u10");
          _SFD_SET_DATA_PROPS(42,10,0,0,"u11");
          _SFD_SET_DATA_PROPS(43,10,0,0,"u12");
          _SFD_SET_DATA_PROPS(44,10,0,0,"u13");
          _SFD_SET_DATA_PROPS(45,10,0,0,"u14");
          _SFD_SET_DATA_PROPS(46,10,0,0,"u15");
          _SFD_SET_DATA_PROPS(47,10,0,0,"u16");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,589);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)
          c12_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c12_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c12_i1);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c12_o1);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c12_o2);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c12_o3);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c12_o4);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c12_o5);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c12_o6);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c12_o7);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c12_o8);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c12_o9);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c12_o10);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c12_o11);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c12_o12);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c12_o13);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c12_o14);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c12_o15);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c12_o16);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c12_i2);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c12_i3);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c12_i4);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c12_i5);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c12_i6);
        _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c12_i7);
        _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c12_i8);
        _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c12_i9);
        _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c12_i10);
        _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c12_i11);
        _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c12_i12);
        _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c12_i13);
        _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c12_i14);
        _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c12_i15);
        _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c12_i16);
        _SFD_SET_DATA_VALUE_PTR(32U, &chartInstance->c12_u1);
        _SFD_SET_DATA_VALUE_PTR(33U, &chartInstance->c12_u2);
        _SFD_SET_DATA_VALUE_PTR(34U, &chartInstance->c12_u3);
        _SFD_SET_DATA_VALUE_PTR(35U, &chartInstance->c12_u4);
        _SFD_SET_DATA_VALUE_PTR(36U, &chartInstance->c12_u5);
        _SFD_SET_DATA_VALUE_PTR(37U, &chartInstance->c12_u6);
        _SFD_SET_DATA_VALUE_PTR(38U, &chartInstance->c12_u7);
        _SFD_SET_DATA_VALUE_PTR(39U, &chartInstance->c12_u8);
        _SFD_SET_DATA_VALUE_PTR(40U, &chartInstance->c12_u9);
        _SFD_SET_DATA_VALUE_PTR(41U, &chartInstance->c12_u10);
        _SFD_SET_DATA_VALUE_PTR(42U, &chartInstance->c12_u11);
        _SFD_SET_DATA_VALUE_PTR(43U, &chartInstance->c12_u12);
        _SFD_SET_DATA_VALUE_PTR(44U, &chartInstance->c12_u13);
        _SFD_SET_DATA_VALUE_PTR(45U, &chartInstance->c12_u14);
        _SFD_SET_DATA_VALUE_PTR(46U, &chartInstance->c12_u15);
        _SFD_SET_DATA_VALUE_PTR(47U, &chartInstance->c12_u16);
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
  return "6hdXuW5bxYBzfsZYBrpB2E";
}

static void sf_opaque_initialize_c12_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_Basic_DMT(void *chartInstanceVar)
{
  enable_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_Basic_DMT(void *chartInstanceVar)
{
  disable_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c12_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c12_Basic_DMT(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c12_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_Basic_DMT(SimStruct *S)
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
    initialize_params_c12_Basic_DMT((SFc12_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_Basic_DMT(SimStruct *S)
{
  /* Actual parameters from chart:
     u1 u10 u11 u12 u13 u14 u15 u16 u2 u3 u4 u5 u6 u7 u8 u9
   */
  const char_T *rtParamNames[] = { "u1", "u10", "u11", "u12", "u13", "u14",
    "u15", "u16", "u2", "u3", "u4", "u5", "u6", "u7", "u8", "u9" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for u1*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for u10*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for u11*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for u12*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for u13*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for u14*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for u15*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for u16*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);

  /* registration for u2*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_DOUBLE);

  /* registration for u3*/
  ssRegDlgParamAsRunTimeParam(S, 9, 9, rtParamNames[9], SS_DOUBLE);

  /* registration for u4*/
  ssRegDlgParamAsRunTimeParam(S, 10, 10, rtParamNames[10], SS_DOUBLE);

  /* registration for u5*/
  ssRegDlgParamAsRunTimeParam(S, 11, 11, rtParamNames[11], SS_DOUBLE);

  /* registration for u6*/
  ssRegDlgParamAsRunTimeParam(S, 12, 12, rtParamNames[12], SS_DOUBLE);

  /* registration for u7*/
  ssRegDlgParamAsRunTimeParam(S, 13, 13, rtParamNames[13], SS_DOUBLE);

  /* registration for u8*/
  ssRegDlgParamAsRunTimeParam(S, 14, 14, rtParamNames[14], SS_DOUBLE);

  /* registration for u9*/
  ssRegDlgParamAsRunTimeParam(S, 15, 15, rtParamNames[15], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,12,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,16);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,16);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=16; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 16; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(569180837U));
  ssSetChecksum1(S,(4211914684U));
  ssSetChecksum2(S,(242278285U));
  ssSetChecksum3(S,(3849063364U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_Basic_DMT(SimStruct *S)
{
  SFc12_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc12_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc12_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c12_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c12_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_Basic_DMT;
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

void c12_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
