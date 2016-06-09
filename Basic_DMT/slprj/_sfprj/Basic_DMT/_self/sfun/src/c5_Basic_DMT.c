/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c5_Basic_DMT.h"
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
static const char * c5_debug_family_names[38] = { "nargin", "nargout", "inp",
  "i1", "i2", "i3", "i4", "i5", "i6", "i7", "i8", "i9", "i10", "i11", "i12",
  "i13", "i14", "i15", "i16", "frameEN", "out", "o1", "o2", "o3", "o4", "o5",
  "o6", "o7", "o8", "o9", "o10", "o11", "o12", "o13", "o14", "o15", "o16", "pop"
};

static const mxArray *c5_eml_mx;
static const mxArray *c5_b_eml_mx;

/* Function Declarations */
static void initialize_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance);
static void initialize_params_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance);
static void disable_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance);
static void set_sim_state_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance);
static void mdl_start_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance);
static void c5_chartstep_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance);
static void initSimStructsc5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_b_pop, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static cint16_T c5_c_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static void c5_eml_scalar_eg(SFc5_Basic_DMTInstanceStruct *chartInstance);
static cint16_T c5_mtimes(SFc5_Basic_DMTInstanceStruct *chartInstance, int16_T
  c5_b0);
static void c5_strcmpi(SFc5_Basic_DMTInstanceStruct *chartInstance);
static cint16_T c5_b_mtimes(SFc5_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c5_a0, int16_T c5_b0);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static cint16_T c5_e_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c5_b_out, const char_T *c5_identifier);
static cint16_T c5_f_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int16_T c5_g_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_h_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_Basic_DMT, const char_T *c5_identifier);
static uint8_T c5_i_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static int16_T c5_get_convert(SFc5_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c5_elementIndex);
static void c5_set_convert(SFc5_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c5_elementIndex, int16_T c5_elementValue);
static int16_T *c5_access_convert(SFc5_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c5_rdOnly);
static real_T c5_get_state(SFc5_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c5_elementIndex);
static void c5_set_state(SFc5_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c5_elementIndex, real_T c5_elementValue);
static real_T *c5_access_state(SFc5_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c5_rdOnly);
static void init_dsm_address_info(SFc5_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc5_Basic_DMTInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_Basic_DMT = 0U;
  sf_mex_assign(&c5_b_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 10U, 15, "WordLength", 6, 9.0, 15, "FractionLength", 6,
    3.0, 15, "BinaryPoint", 6, 3.0, 15, "Slope", 6, 0.125, 15, "FixedExponent",
    6, -3.0), true);
  sf_mex_assign(&c5_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
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

static void initialize_params_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  const mxArray *c5_b_y = NULL;
  cint16_T c5_u;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  cint16_T c5_b_u;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  cint16_T c5_c_u;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  cint16_T c5_d_u;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  cint16_T c5_e_u;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  cint16_T c5_f_u;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  cint16_T c5_g_u;
  const mxArray *c5_o_y = NULL;
  const mxArray *c5_p_y = NULL;
  cint16_T c5_h_u;
  const mxArray *c5_q_y = NULL;
  const mxArray *c5_r_y = NULL;
  cint16_T c5_i_u;
  const mxArray *c5_s_y = NULL;
  const mxArray *c5_t_y = NULL;
  cint16_T c5_j_u;
  const mxArray *c5_u_y = NULL;
  const mxArray *c5_v_y = NULL;
  cint16_T c5_k_u;
  const mxArray *c5_w_y = NULL;
  const mxArray *c5_x_y = NULL;
  cint16_T c5_l_u;
  const mxArray *c5_y_y = NULL;
  const mxArray *c5_ab_y = NULL;
  cint16_T c5_m_u;
  const mxArray *c5_bb_y = NULL;
  const mxArray *c5_cb_y = NULL;
  cint16_T c5_n_u;
  const mxArray *c5_db_y = NULL;
  const mxArray *c5_eb_y = NULL;
  cint16_T c5_o_u;
  const mxArray *c5_fb_y = NULL;
  const mxArray *c5_gb_y = NULL;
  cint16_T c5_p_u;
  const mxArray *c5_hb_y = NULL;
  const mxArray *c5_ib_y = NULL;
  cint16_T c5_q_u;
  const mxArray *c5_jb_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_r_u;
  const mxArray *c5_kb_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_s_u;
  const mxArray *c5_lb_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(19, 1), false);
  c5_b_y = NULL;
  c5_u.re = chartInstance->c5_o1->re;
  c5_u.im = chartInstance->c5_o1->im;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_c_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_d_y = NULL;
  c5_b_u.re = chartInstance->c5_o10->re;
  c5_b_u.im = chartInstance->c5_o10->im;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_d_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_e_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 1, c5_d_y);
  c5_f_y = NULL;
  c5_c_u.re = chartInstance->c5_o11->re;
  c5_c_u.im = chartInstance->c5_o11->im;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_c_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_f_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_g_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 2, c5_f_y);
  c5_h_y = NULL;
  c5_d_u.re = chartInstance->c5_o12->re;
  c5_d_u.im = chartInstance->c5_o12->im;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_d_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_h_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_i_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 3, c5_h_y);
  c5_j_y = NULL;
  c5_e_u.re = chartInstance->c5_o13->re;
  c5_e_u.im = chartInstance->c5_o13->im;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_e_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_j_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_k_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 4, c5_j_y);
  c5_l_y = NULL;
  c5_f_u.re = chartInstance->c5_o14->re;
  c5_f_u.im = chartInstance->c5_o14->im;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_f_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_l_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_m_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 5, c5_l_y);
  c5_n_y = NULL;
  c5_g_u.re = chartInstance->c5_o15->re;
  c5_g_u.im = chartInstance->c5_o15->im;
  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_g_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_n_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_o_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 6, c5_n_y);
  c5_p_y = NULL;
  c5_h_u.re = chartInstance->c5_o16->re;
  c5_h_u.im = chartInstance->c5_o16->im;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_create("y", &c5_h_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_p_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_q_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 7, c5_p_y);
  c5_r_y = NULL;
  c5_i_u.re = chartInstance->c5_o2->re;
  c5_i_u.im = chartInstance->c5_o2->im;
  c5_s_y = NULL;
  sf_mex_assign(&c5_s_y, sf_mex_create("y", &c5_i_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_r_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_s_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 8, c5_r_y);
  c5_t_y = NULL;
  c5_j_u.re = chartInstance->c5_o3->re;
  c5_j_u.im = chartInstance->c5_o3->im;
  c5_u_y = NULL;
  sf_mex_assign(&c5_u_y, sf_mex_create("y", &c5_j_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_t_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_u_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 9, c5_t_y);
  c5_v_y = NULL;
  c5_k_u.re = chartInstance->c5_o4->re;
  c5_k_u.im = chartInstance->c5_o4->im;
  c5_w_y = NULL;
  sf_mex_assign(&c5_w_y, sf_mex_create("y", &c5_k_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_v_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_w_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 10, c5_v_y);
  c5_x_y = NULL;
  c5_l_u.re = chartInstance->c5_o5->re;
  c5_l_u.im = chartInstance->c5_o5->im;
  c5_y_y = NULL;
  sf_mex_assign(&c5_y_y, sf_mex_create("y", &c5_l_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_x_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_y_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 11, c5_x_y);
  c5_ab_y = NULL;
  c5_m_u.re = chartInstance->c5_o6->re;
  c5_m_u.im = chartInstance->c5_o6->im;
  c5_bb_y = NULL;
  sf_mex_assign(&c5_bb_y, sf_mex_create("y", &c5_m_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_ab_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_bb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 12, c5_ab_y);
  c5_cb_y = NULL;
  c5_n_u.re = chartInstance->c5_o7->re;
  c5_n_u.im = chartInstance->c5_o7->im;
  c5_db_y = NULL;
  sf_mex_assign(&c5_db_y, sf_mex_create("y", &c5_n_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_cb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_db_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 13, c5_cb_y);
  c5_eb_y = NULL;
  c5_o_u.re = chartInstance->c5_o8->re;
  c5_o_u.im = chartInstance->c5_o8->im;
  c5_fb_y = NULL;
  sf_mex_assign(&c5_fb_y, sf_mex_create("y", &c5_o_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_eb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_fb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 14, c5_eb_y);
  c5_gb_y = NULL;
  c5_p_u.re = chartInstance->c5_o9->re;
  c5_p_u.im = chartInstance->c5_o9->im;
  c5_hb_y = NULL;
  sf_mex_assign(&c5_hb_y, sf_mex_create("y", &c5_p_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_gb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_hb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 15, c5_gb_y);
  c5_ib_y = NULL;
  c5_q_u.re = chartInstance->c5_out->re;
  c5_q_u.im = chartInstance->c5_out->im;
  c5_jb_y = NULL;
  sf_mex_assign(&c5_jb_y, sf_mex_create("y", &c5_q_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_ib_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_jb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c5_y, 16, c5_ib_y);
  c5_hoistedGlobal = *chartInstance->c5_pop;
  c5_r_u = c5_hoistedGlobal;
  c5_kb_y = NULL;
  sf_mex_assign(&c5_kb_y, sf_mex_create("y", &c5_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 17, c5_kb_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_active_c5_Basic_DMT;
  c5_s_u = c5_b_hoistedGlobal;
  c5_lb_y = NULL;
  sf_mex_assign(&c5_lb_y, sf_mex_create("y", &c5_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 18, c5_lb_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *chartInstance->c5_o1 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 0)), "o1");
  *chartInstance->c5_o10 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 1)), "o10");
  *chartInstance->c5_o11 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 2)), "o11");
  *chartInstance->c5_o12 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 3)), "o12");
  *chartInstance->c5_o13 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 4)), "o13");
  *chartInstance->c5_o14 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 5)), "o14");
  *chartInstance->c5_o15 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 6)), "o15");
  *chartInstance->c5_o16 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 7)), "o16");
  *chartInstance->c5_o2 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 8)), "o2");
  *chartInstance->c5_o3 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 9)), "o3");
  *chartInstance->c5_o4 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 10)), "o4");
  *chartInstance->c5_o5 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 11)), "o5");
  *chartInstance->c5_o6 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 12)), "o6");
  *chartInstance->c5_o7 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 13)), "o7");
  *chartInstance->c5_o8 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 14)), "o8");
  *chartInstance->c5_o9 = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 15)), "o9");
  *chartInstance->c5_out = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 16)), "out");
  *chartInstance->c5_pop = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 17)), "pop");
  chartInstance->c5_is_active_c5_Basic_DMT = c5_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 18)), "is_active_c5_Basic_DMT");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_Basic_DMT(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
  sf_mex_destroy(&c5_eml_mx);
  sf_mex_destroy(&c5_b_eml_mx);
}

static void sf_gateway_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_Basic_DMT(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_pop, 19U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c5_frameEN, 37U);
}

static void mdl_start_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_chartstep_c5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance)
{
  boolean_T c5_hoistedGlobal;
  cint16_T c5_b_inp;
  cint16_T c5_b_i1;
  cint16_T c5_b_i2;
  cint16_T c5_b_i3;
  cint16_T c5_b_i4;
  cint16_T c5_b_i5;
  cint16_T c5_b_i6;
  cint16_T c5_b_i7;
  cint16_T c5_b_i8;
  cint16_T c5_b_i9;
  cint16_T c5_b_i10;
  cint16_T c5_b_i11;
  cint16_T c5_b_i12;
  cint16_T c5_b_i13;
  cint16_T c5_b_i14;
  cint16_T c5_b_i15;
  cint16_T c5_b_i16;
  boolean_T c5_b_frameEN;
  uint32_T c5_debug_family_var_map[38];
  real_T c5_nargin = 18.0;
  real_T c5_nargout = 18.0;
  cint16_T c5_b_out;
  cint16_T c5_b_o1;
  cint16_T c5_b_o2;
  cint16_T c5_b_o3;
  cint16_T c5_b_o4;
  cint16_T c5_b_o5;
  cint16_T c5_b_o6;
  cint16_T c5_b_o7;
  cint16_T c5_b_o8;
  cint16_T c5_b_o9;
  cint16_T c5_b_o10;
  cint16_T c5_b_o11;
  cint16_T c5_b_o12;
  cint16_T c5_b_o13;
  cint16_T c5_b_o14;
  cint16_T c5_b_o15;
  cint16_T c5_b_o16;
  real_T c5_b_pop;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *chartInstance->c5_frameEN;
  c5_b_inp = *chartInstance->c5_inp;
  c5_b_i1 = *chartInstance->c5_i1;
  c5_b_i2 = *chartInstance->c5_i2;
  c5_b_i3 = *chartInstance->c5_i3;
  c5_b_i4 = *chartInstance->c5_i4;
  c5_b_i5 = *chartInstance->c5_i5;
  c5_b_i6 = *chartInstance->c5_i6;
  c5_b_i7 = *chartInstance->c5_i7;
  c5_b_i8 = *chartInstance->c5_i8;
  c5_b_i9 = *chartInstance->c5_i9;
  c5_b_i10 = *chartInstance->c5_i10;
  c5_b_i11 = *chartInstance->c5_i11;
  c5_b_i12 = *chartInstance->c5_i12;
  c5_b_i13 = *chartInstance->c5_i13;
  c5_b_i14 = *chartInstance->c5_i14;
  c5_b_i15 = *chartInstance->c5_i15;
  c5_b_i16 = *chartInstance->c5_i16;
  c5_b_frameEN = c5_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 38U, 38U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_inp, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i1, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i2, 4U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i3, 5U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i4, 6U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i5, 7U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i6, 8U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i7, 9U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i8, 10U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i9, 11U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i10, 12U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i11, 13U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i12, 14U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i13, 15U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i14, 16U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i15, 17U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_i16, 18U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_frameEN, 19U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_out, 20U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o1, 21U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o2, 22U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o3, 23U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o4, 24U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o5, 25U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o6, 26U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o7, 27U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o8, 28U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o9, 29U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o10, 30U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o11, 31U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o12, 32U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o13, 33U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o14, 34U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o15, 35U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_o16, 36U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_pop, 37U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_b_o1 = c5_b_i1;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_b_o2 = c5_b_i2;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_b_o3 = c5_b_i3;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  c5_b_o4 = c5_b_i4;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  c5_b_o5 = c5_b_i5;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  c5_b_o6 = c5_b_i6;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_b_o7 = c5_b_i7;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  c5_b_o8 = c5_b_i8;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_b_o9 = c5_b_i9;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  c5_b_o10 = c5_b_i10;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_b_o11 = c5_b_i11;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
  c5_b_o12 = c5_b_i12;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
  c5_b_o13 = c5_b_i13;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  c5_b_o14 = c5_b_i14;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  c5_b_o15 = c5_b_i15;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
  c5_b_o16 = c5_b_i16;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
  c5_b_pop = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
  c5_b_out = c5_mtimes(chartInstance, c5_get_convert(chartInstance, 0));
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
  switch ((int32_T)_SFD_INTEGER_CHECK("state", c5_get_state(chartInstance, 0)))
  {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
    if (CV_EML_IF(0, 1, 0, c5_b_frameEN)) {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
      c5_set_state(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 1);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 32);
      c5_set_state(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 1);
    }
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 36);
    c5_b_o1 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 37);
    c5_set_state(chartInstance, 0, 2.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 39);
    c5_b_o2 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 40);
    c5_set_state(chartInstance, 0, 3.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 42);
    c5_b_o3 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 43);
    c5_set_state(chartInstance, 0, 4.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 45);
    c5_b_o4 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 46);
    c5_set_state(chartInstance, 0, 5.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 5:
    CV_EML_SWITCH(0, 1, 0, 6);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 48);
    c5_b_o5 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 49);
    c5_set_state(chartInstance, 0, 6.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 6:
    CV_EML_SWITCH(0, 1, 0, 7);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 51);
    c5_b_o6 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 52);
    c5_set_state(chartInstance, 0, 7.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 7:
    CV_EML_SWITCH(0, 1, 0, 8);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 54);
    c5_b_o7 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 55);
    c5_set_state(chartInstance, 0, 8.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 8:
    CV_EML_SWITCH(0, 1, 0, 9);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 57);
    c5_b_o8 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 58);
    c5_set_state(chartInstance, 0, 9.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 9:
    CV_EML_SWITCH(0, 1, 0, 10);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 60);
    c5_b_o9 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 61);
    c5_set_state(chartInstance, 0, 10.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 10:
    CV_EML_SWITCH(0, 1, 0, 11);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 63);
    c5_b_o10 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 64);
    c5_set_state(chartInstance, 0, 11.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 11:
    CV_EML_SWITCH(0, 1, 0, 12);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 66);
    c5_b_o11 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 67);
    c5_set_state(chartInstance, 0, 12.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 12:
    CV_EML_SWITCH(0, 1, 0, 13);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 69);
    c5_b_o12 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 70);
    c5_set_state(chartInstance, 0, 13.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 13:
    CV_EML_SWITCH(0, 1, 0, 14);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 72);
    c5_b_o13 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 73);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_inp, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 74);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 75);
    c5_set_state(chartInstance, 0, 14.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 14:
    CV_EML_SWITCH(0, 1, 0, 15);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 77);
    c5_b_o14 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 78);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_inp, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 79);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 80);
    c5_set_state(chartInstance, 0, 15.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 15:
    CV_EML_SWITCH(0, 1, 0, 16);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 82);
    c5_b_o15 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 83);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_inp, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 84);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 85);
    c5_set_state(chartInstance, 0, 16.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 16:
    CV_EML_SWITCH(0, 1, 0, 17);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 87);
    c5_b_o16 = c5_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 88);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_inp, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 89);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 90);
    c5_set_state(chartInstance, 0, 17.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 17:
    CV_EML_SWITCH(0, 1, 0, 18);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 92);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i1, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 93);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 94);
    c5_set_state(chartInstance, 0, 18.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 18:
    CV_EML_SWITCH(0, 1, 0, 19);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 96);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i2, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 97);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 98);
    c5_set_state(chartInstance, 0, 19.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 19:
    CV_EML_SWITCH(0, 1, 0, 20);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 100);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i3, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 101);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 102);
    c5_set_state(chartInstance, 0, 20.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 20:
    CV_EML_SWITCH(0, 1, 0, 21);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 104);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i4, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 105);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 106);
    c5_set_state(chartInstance, 0, 21.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 21:
    CV_EML_SWITCH(0, 1, 0, 22);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 108);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i5, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 109);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 110);
    c5_set_state(chartInstance, 0, 22.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 22:
    CV_EML_SWITCH(0, 1, 0, 23);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 112);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i6, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 113);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 114);
    c5_set_state(chartInstance, 0, 23.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 23:
    CV_EML_SWITCH(0, 1, 0, 24);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 116);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i7, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 117);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 118);
    c5_set_state(chartInstance, 0, 24.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 24:
    CV_EML_SWITCH(0, 1, 0, 25);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 120);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i8, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 121);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 122);
    c5_set_state(chartInstance, 0, 25.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 25:
    CV_EML_SWITCH(0, 1, 0, 26);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 124);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i9, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 125);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 126);
    c5_set_state(chartInstance, 0, 26.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 26:
    CV_EML_SWITCH(0, 1, 0, 27);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 128U);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i10, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 129U);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 130U);
    c5_set_state(chartInstance, 0, 27.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 27:
    CV_EML_SWITCH(0, 1, 0, 28);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 132U);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i11, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 133U);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 134U);
    c5_set_state(chartInstance, 0, 28.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 28:
    CV_EML_SWITCH(0, 1, 0, 29);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 136U);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i12, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 137U);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 138U);
    c5_set_state(chartInstance, 0, 29.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 29:
    CV_EML_SWITCH(0, 1, 0, 30);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 140U);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i13, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 141U);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 142U);
    c5_set_state(chartInstance, 0, 30.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 30:
    CV_EML_SWITCH(0, 1, 0, 31);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 144U);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i14, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 145U);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 146U);
    c5_set_state(chartInstance, 0, 31.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 31:
    CV_EML_SWITCH(0, 1, 0, 32);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 148U);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i15, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 149U);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 150U);
    c5_set_state(chartInstance, 0, 32.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 32:
    CV_EML_SWITCH(0, 1, 0, 33);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 152U);
    c5_b_out = c5_b_mtimes(chartInstance, c5_b_i16, c5_get_convert(chartInstance,
      0));
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 153U);
    c5_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 154U);
    c5_set_state(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -154);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c5_out = c5_b_out;
  *chartInstance->c5_o1 = c5_b_o1;
  *chartInstance->c5_o2 = c5_b_o2;
  *chartInstance->c5_o3 = c5_b_o3;
  *chartInstance->c5_o4 = c5_b_o4;
  *chartInstance->c5_o5 = c5_b_o5;
  *chartInstance->c5_o6 = c5_b_o6;
  *chartInstance->c5_o7 = c5_b_o7;
  *chartInstance->c5_o8 = c5_b_o8;
  *chartInstance->c5_o9 = c5_b_o9;
  *chartInstance->c5_o10 = c5_b_o10;
  *chartInstance->c5_o11 = c5_b_o11;
  *chartInstance->c5_o12 = c5_b_o12;
  *chartInstance->c5_o13 = c5_b_o13;
  *chartInstance->c5_o14 = c5_b_o14;
  *chartInstance->c5_o15 = c5_b_o15;
  *chartInstance->c5_o16 = c5_b_o16;
  *chartInstance->c5_pop = c5_b_pop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_Basic_DMT(SFc5_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_b_pop, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_pop), &c5_thisId);
  sf_mex_destroy(&c5_b_pop);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_pop;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_b_pop = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_pop), &c5_thisId);
  sf_mex_destroy(&c5_b_pop);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  cint16_T c5_u;
  const mxArray *c5_y = NULL;
  cint16_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_u = *(cint16_T *)c5_inData;
  c5_y = NULL;
  c5_b_u.re = c5_u.re;
  c5_b_u.im = c5_u.im;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_b_y, 15, "fimathislocal", 3, false), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static cint16_T c5_c_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  cint16_T c5_y;
  const mxArray *c5_mxFi = NULL;
  const mxArray *c5_mxInt = NULL;
  cint16_T c5_ic0;
  (void)chartInstance;
  sf_mex_check_fi(c5_parentId, c5_u, true, 0U, NULL, c5_eml_mx, c5_b_eml_mx);
  sf_mex_assign(&c5_mxFi, sf_mex_dup(c5_u), false);
  sf_mex_assign(&c5_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c5_mxFi)), false);
  sf_mex_import(c5_parentId, sf_mex_dup(c5_mxInt), &c5_ic0, 1, 4, 1U, 0, 0U, 0);
  sf_mex_destroy(&c5_mxFi);
  sf_mex_destroy(&c5_mxInt);
  c5_y = c5_ic0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_o16;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  cint16_T c5_y;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_b_o16 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_o16), &c5_thisId);
  sf_mex_destroy(&c5_b_o16);
  *(cint16_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  boolean_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(boolean_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  const mxArray *c5_rhs4 = NULL;
  const mxArray *c5_lhs4 = NULL;
  const mxArray *c5_rhs5 = NULL;
  const mxArray *c5_lhs5 = NULL;
  const mxArray *c5_rhs6 = NULL;
  const mxArray *c5_lhs6 = NULL;
  const mxArray *c5_rhs7 = NULL;
  const mxArray *c5_lhs7 = NULL;
  const mxArray *c5_rhs8 = NULL;
  const mxArray *c5_lhs8 = NULL;
  const mxArray *c5_rhs9 = NULL;
  const mxArray *c5_lhs9 = NULL;
  const mxArray *c5_rhs10 = NULL;
  const mxArray *c5_lhs10 = NULL;
  const mxArray *c5_rhs11 = NULL;
  const mxArray *c5_lhs11 = NULL;
  const mxArray *c5_rhs12 = NULL;
  const mxArray *c5_lhs12 = NULL;
  const mxArray *c5_rhs13 = NULL;
  const mxArray *c5_lhs13 = NULL;
  const mxArray *c5_rhs14 = NULL;
  const mxArray *c5_lhs14 = NULL;
  const mxArray *c5_rhs15 = NULL;
  const mxArray *c5_lhs15 = NULL;
  const mxArray *c5_rhs16 = NULL;
  const mxArray *c5_lhs16 = NULL;
  const mxArray *c5_rhs17 = NULL;
  const mxArray *c5_lhs17 = NULL;
  const mxArray *c5_rhs18 = NULL;
  const mxArray *c5_lhs18 = NULL;
  const mxArray *c5_rhs19 = NULL;
  const mxArray *c5_lhs19 = NULL;
  const mxArray *c5_rhs20 = NULL;
  const mxArray *c5_lhs20 = NULL;
  const mxArray *c5_rhs21 = NULL;
  const mxArray *c5_lhs21 = NULL;
  const mxArray *c5_rhs22 = NULL;
  const mxArray *c5_lhs22 = NULL;
  const mxArray *c5_rhs23 = NULL;
  const mxArray *c5_lhs23 = NULL;
  const mxArray *c5_rhs24 = NULL;
  const mxArray *c5_lhs24 = NULL;
  const mxArray *c5_rhs25 = NULL;
  const mxArray *c5_lhs25 = NULL;
  const mxArray *c5_rhs26 = NULL;
  const mxArray *c5_lhs26 = NULL;
  const mxArray *c5_rhs27 = NULL;
  const mxArray *c5_lhs27 = NULL;
  const mxArray *c5_rhs28 = NULL;
  const mxArray *c5_lhs28 = NULL;
  const mxArray *c5_rhs29 = NULL;
  const mxArray *c5_lhs29 = NULL;
  const mxArray *c5_rhs30 = NULL;
  const mxArray *c5_lhs30 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510384U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isfi"), "name", "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isfi"), "name", "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c5_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("get"), "name", "name", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c5_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("times"), "name", "name", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510386U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c5_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c5_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isfi"), "name", "name", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c5_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isfi"), "name", "name", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c5_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isscaledtype"), "name", "name",
                  10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510380U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c5_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isfixed"), "name", "name", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510378U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c5_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("get"), "name", "name", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c5_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("get"), "name", "name", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fimath"),
                  "dominantType", "dominantType", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c5_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("strcmpi"), "name", "name", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c5_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c5_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_charmax"), "name", "name",
                  16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c5_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c5_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c5_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("min"), "name", "name", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c5_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c5_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c5_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c5_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c5_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c5_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c5_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c5_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c5_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("get"), "name", "name", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c5_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_fixpt_times"), "name",
                  "name", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_fixpt_times.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1289519646U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c5_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_checkfimathforbinaryops"),
                  "name", "name", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("embedded.fi"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_checkfimathforbinaryops.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346510368U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c5_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs30), "lhs", "lhs",
                  30);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
  sf_mex_destroy(&c5_rhs4);
  sf_mex_destroy(&c5_lhs4);
  sf_mex_destroy(&c5_rhs5);
  sf_mex_destroy(&c5_lhs5);
  sf_mex_destroy(&c5_rhs6);
  sf_mex_destroy(&c5_lhs6);
  sf_mex_destroy(&c5_rhs7);
  sf_mex_destroy(&c5_lhs7);
  sf_mex_destroy(&c5_rhs8);
  sf_mex_destroy(&c5_lhs8);
  sf_mex_destroy(&c5_rhs9);
  sf_mex_destroy(&c5_lhs9);
  sf_mex_destroy(&c5_rhs10);
  sf_mex_destroy(&c5_lhs10);
  sf_mex_destroy(&c5_rhs11);
  sf_mex_destroy(&c5_lhs11);
  sf_mex_destroy(&c5_rhs12);
  sf_mex_destroy(&c5_lhs12);
  sf_mex_destroy(&c5_rhs13);
  sf_mex_destroy(&c5_lhs13);
  sf_mex_destroy(&c5_rhs14);
  sf_mex_destroy(&c5_lhs14);
  sf_mex_destroy(&c5_rhs15);
  sf_mex_destroy(&c5_lhs15);
  sf_mex_destroy(&c5_rhs16);
  sf_mex_destroy(&c5_lhs16);
  sf_mex_destroy(&c5_rhs17);
  sf_mex_destroy(&c5_lhs17);
  sf_mex_destroy(&c5_rhs18);
  sf_mex_destroy(&c5_lhs18);
  sf_mex_destroy(&c5_rhs19);
  sf_mex_destroy(&c5_lhs19);
  sf_mex_destroy(&c5_rhs20);
  sf_mex_destroy(&c5_lhs20);
  sf_mex_destroy(&c5_rhs21);
  sf_mex_destroy(&c5_lhs21);
  sf_mex_destroy(&c5_rhs22);
  sf_mex_destroy(&c5_lhs22);
  sf_mex_destroy(&c5_rhs23);
  sf_mex_destroy(&c5_lhs23);
  sf_mex_destroy(&c5_rhs24);
  sf_mex_destroy(&c5_lhs24);
  sf_mex_destroy(&c5_rhs25);
  sf_mex_destroy(&c5_lhs25);
  sf_mex_destroy(&c5_rhs26);
  sf_mex_destroy(&c5_lhs26);
  sf_mex_destroy(&c5_rhs27);
  sf_mex_destroy(&c5_lhs27);
  sf_mex_destroy(&c5_rhs28);
  sf_mex_destroy(&c5_lhs28);
  sf_mex_destroy(&c5_rhs29);
  sf_mex_destroy(&c5_lhs29);
  sf_mex_destroy(&c5_rhs30);
  sf_mex_destroy(&c5_lhs30);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static void c5_eml_scalar_eg(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static cint16_T c5_mtimes(SFc5_Basic_DMTInstanceStruct *chartInstance, int16_T
  c5_b0)
{
  cint16_T c5_cout;
  int16_T c5_cr;
  int16_T c5_ci;
  (void)c5_b0;
  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  c5_strcmpi(chartInstance);
  c5_cr = 0;
  c5_ci = 0;
  c5_cout.re = c5_cr;
  c5_cout.im = c5_ci;
  return c5_cout;
}

static void c5_strcmpi(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
}

static cint16_T c5_b_mtimes(SFc5_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c5_a0, int16_T c5_b0)
{
  cint16_T c5_cout;
  int16_T c5_b_b0;
  int16_T c5_b;
  int16_T c5_b_b;
  int16_T c5_ar;
  int16_T c5_ai;
  int32_T c5_i0;
  int32_T c5_b_i1;
  int16_T c5_cr;
  int32_T c5_b_i2;
  int32_T c5_b_i3;
  int16_T c5_ci;
  const mxArray *c5_errID = NULL;
  const mxArray *c5_a2SD = NULL;
  const mxArray *c5_b2SD = NULL;
  const mxArray *c5_Tsd = NULL;
  c5_b_b0 = c5_b0;
  c5_b = c5_b_b0;
  c5_strcmpi(chartInstance);
  c5_b_b = c5_b;
  c5_ar = c5_a0.re;
  c5_ai = c5_a0.im;
  c5_i0 = c5_ar * c5_b_b;
  c5_b_i1 = (c5_i0 >> 3) + ((c5_i0 & 4) != 0);
  if (c5_b_i1 > 255) {
    c5_b_i1 = 255;
  } else {
    if (c5_b_i1 < -256) {
      c5_b_i1 = -256;
    }
  }

  c5_cr = (int16_T)c5_b_i1;
  c5_b_i2 = c5_ai * c5_b_b;
  c5_b_i3 = (c5_b_i2 >> 3) + ((c5_b_i2 & 4) != 0);
  if (c5_b_i3 > 255) {
    c5_b_i3 = 255;
  } else {
    if (c5_b_i3 < -256) {
      c5_b_i3 = -256;
    }
  }

  c5_ci = (int16_T)c5_b_i3;
  c5_cout.re = c5_cr;
  c5_cout.im = c5_ci;
  sf_mex_destroy(&c5_errID);
  sf_mex_destroy(&c5_a2SD);
  sf_mex_destroy(&c5_b2SD);
  sf_mex_destroy(&c5_Tsd);
  return c5_cout;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_b_i4;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_b_i4, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_b_i4;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  cint16_T c5_u;
  const mxArray *c5_y = NULL;
  cint16_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_u = *(cint16_T *)c5_inData;
  c5_y = NULL;
  c5_b_u.re = c5_u.re;
  c5_b_u.im = c5_u.im;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
    "simulinkarray", 14, c5_b_y, 15, "fimathislocal", 3, true), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static cint16_T c5_e_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c5_b_out, const char_T *c5_identifier)
{
  cint16_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_out), &c5_thisId);
  sf_mex_destroy(&c5_b_out);
  return c5_y;
}

static cint16_T c5_f_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  cint16_T c5_y;
  const mxArray *c5_mxFi = NULL;
  const mxArray *c5_mxInt = NULL;
  cint16_T c5_ic1;
  (void)chartInstance;
  sf_mex_check_fi(c5_parentId, c5_u, true, 0U, NULL, c5_eml_mx, c5_b_eml_mx);
  sf_mex_assign(&c5_mxFi, sf_mex_dup(c5_u), false);
  sf_mex_assign(&c5_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c5_mxFi)), false);
  sf_mex_import(c5_parentId, sf_mex_dup(c5_mxInt), &c5_ic1, 1, 4, 1U, 0, 0U, 0);
  sf_mex_destroy(&c5_mxFi);
  sf_mex_destroy(&c5_mxInt);
  c5_y = c5_ic1;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_out;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  cint16_T c5_y;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_b_out = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_out), &c5_thisId);
  sf_mex_destroy(&c5_b_out);
  *(cint16_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  int16_T c5_u;
  const mxArray *c5_y = NULL;
  int16_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c5_u = *(int16_T *)c5_inData;
    c5_y = NULL;
    c5_b_u = c5_u;
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 4, 0U, 0U, 0U, 0), false);
    sf_mex_assign(&c5_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
      (c5_eml_mx), 15, "numerictype", 14, sf_mex_dup(c5_b_eml_mx), 15,
      "simulinkarray", 14, c5_b_y, 15, "fimathislocal", 3, false), false);
    sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  } else {
    sf_mex_assign(&c5_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c5_mxArrayOutData;
}

static int16_T c5_g_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int16_T c5_y;
  const mxArray *c5_mxFi = NULL;
  const mxArray *c5_mxInt = NULL;
  int16_T c5_b_i5;
  (void)chartInstance;
  sf_mex_check_fi(c5_parentId, c5_u, false, 0U, NULL, c5_eml_mx, c5_b_eml_mx);
  sf_mex_assign(&c5_mxFi, sf_mex_dup(c5_u), false);
  sf_mex_assign(&c5_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c5_mxFi)), false);
  sf_mex_import(c5_parentId, sf_mex_dup(c5_mxInt), &c5_b_i5, 1, 4, 0U, 0, 0U, 0);
  sf_mex_destroy(&c5_mxFi);
  sf_mex_destroy(&c5_mxInt);
  c5_y = c5_b_i5;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_convert;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int16_T c5_y;
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)chartInstanceVoid;
  if (sf_debug_check_fi_license()) {
    c5_convert = sf_mex_dup(c5_mxArrayInData);
    c5_identifier = c5_varName;
    c5_thisId.fIdentifier = c5_identifier;
    c5_thisId.fParent = NULL;
    c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_convert),
      &c5_thisId);
    sf_mex_destroy(&c5_convert);
    *(int16_T *)c5_outData = c5_y;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_h_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_Basic_DMT, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_Basic_DMT), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Basic_DMT);
  return c5_y;
}

static uint8_T c5_i_emlrt_marshallIn(SFc5_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static int16_T c5_get_convert(SFc5_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c5_elementIndex);
  return *chartInstance->c5_convert_address;
}

static void c5_set_convert(SFc5_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c5_elementIndex, int16_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c5_elementIndex);
  *chartInstance->c5_convert_address = c5_elementValue;
}

static int16_T *c5_access_convert(SFc5_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c5_rdOnly)
{
  int16_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c5_dsmAddr = chartInstance->c5_convert_address;
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c5_dsmAddr;
}

static real_T c5_get_state(SFc5_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c5_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c5_elementIndex);
  return *chartInstance->c5_state_address;
}

static void c5_set_state(SFc5_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c5_elementIndex, real_T c5_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c5_elementIndex);
  *chartInstance->c5_state_address = c5_elementValue;
}

static real_T *c5_access_state(SFc5_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c5_rdOnly)
{
  real_T *c5_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c5_dsmAddr = chartInstance->c5_state_address;
  if (c5_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c5_dsmAddr;
}

static void init_dsm_address_info(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "convert", (void **)
    &chartInstance->c5_convert_address, &chartInstance->c5_convert_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "state", (void **)
    &chartInstance->c5_state_address, &chartInstance->c5_state_index);
}

static void init_simulink_io_address(SFc5_Basic_DMTInstanceStruct *chartInstance)
{
  chartInstance->c5_inp = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_i1 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_out = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_o1 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_o2 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_o3 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c5_o4 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c5_o5 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c5_o6 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c5_o7 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c5_o8 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c5_o9 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c5_o10 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c5_o11 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c5_o12 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c5_o13 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c5_o14 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c5_o15 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c5_o16 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 17);
  chartInstance->c5_pop = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 18);
  chartInstance->c5_i2 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_i3 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_i4 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c5_i5 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c5_i6 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c5_i7 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c5_i8 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c5_i9 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c5_i10 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c5_i11 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c5_i12 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c5_i13 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c5_i14 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c5_i15 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c5_i16 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c5_frameEN = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 17);
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

void sf_c5_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(241600972U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(360609958U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2060710713U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3900159268U);
}

mxArray* sf_c5_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c5_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("br0ANFdrf9WjYv8GTpHEoF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,18,3,dataFields);

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

      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(1));

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,18,3,dataFields);

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

      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(1));

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c5_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c5_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[10],T\"o1\",},{M[1],M[36],T\"o10\",},{M[1],M[37],T\"o11\",},{M[1],M[38],T\"o12\",},{M[1],M[39],T\"o13\",},{M[1],M[40],T\"o14\",},{M[1],M[41],T\"o15\",},{M[1],M[42],T\"o16\",},{M[1],M[28],T\"o2\",},{M[1],M[29],T\"o3\",}}",
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[30],T\"o4\",},{M[1],M[31],T\"o5\",},{M[1],M[32],T\"o6\",},{M[1],M[33],T\"o7\",},{M[1],M[34],T\"o8\",},{M[1],M[35],T\"o9\",},{M[1],M[5],T\"out\",},{M[1],M[6],T\"pop\",},{M[8],M[0],T\"is_active_c5_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 19, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           5,
           1,
           1,
           0,
           38,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"i1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"out");
          _SFD_SET_DATA_PROPS(3,2,0,1,"o1");
          _SFD_SET_DATA_PROPS(4,2,0,1,"o2");
          _SFD_SET_DATA_PROPS(5,2,0,1,"o3");
          _SFD_SET_DATA_PROPS(6,2,0,1,"o4");
          _SFD_SET_DATA_PROPS(7,2,0,1,"o5");
          _SFD_SET_DATA_PROPS(8,2,0,1,"o6");
          _SFD_SET_DATA_PROPS(9,2,0,1,"o7");
          _SFD_SET_DATA_PROPS(10,2,0,1,"o8");
          _SFD_SET_DATA_PROPS(11,2,0,1,"o9");
          _SFD_SET_DATA_PROPS(12,2,0,1,"o10");
          _SFD_SET_DATA_PROPS(13,2,0,1,"o11");
          _SFD_SET_DATA_PROPS(14,2,0,1,"o12");
          _SFD_SET_DATA_PROPS(15,2,0,1,"o13");
          _SFD_SET_DATA_PROPS(16,2,0,1,"o14");
          _SFD_SET_DATA_PROPS(17,2,0,1,"o15");
          _SFD_SET_DATA_PROPS(18,2,0,1,"o16");
          _SFD_SET_DATA_PROPS(19,2,0,1,"pop");
          _SFD_SET_DATA_PROPS(20,11,0,0,"convert");
          _SFD_SET_DATA_PROPS(21,11,0,0,"state");
          _SFD_SET_DATA_PROPS(22,1,1,0,"i2");
          _SFD_SET_DATA_PROPS(23,1,1,0,"i3");
          _SFD_SET_DATA_PROPS(24,1,1,0,"i4");
          _SFD_SET_DATA_PROPS(25,1,1,0,"i5");
          _SFD_SET_DATA_PROPS(26,1,1,0,"i6");
          _SFD_SET_DATA_PROPS(27,1,1,0,"i7");
          _SFD_SET_DATA_PROPS(28,1,1,0,"i8");
          _SFD_SET_DATA_PROPS(29,1,1,0,"i9");
          _SFD_SET_DATA_PROPS(30,1,1,0,"i10");
          _SFD_SET_DATA_PROPS(31,1,1,0,"i11");
          _SFD_SET_DATA_PROPS(32,1,1,0,"i12");
          _SFD_SET_DATA_PROPS(33,1,1,0,"i13");
          _SFD_SET_DATA_PROPS(34,1,1,0,"i14");
          _SFD_SET_DATA_PROPS(35,1,1,0,"i15");
          _SFD_SET_DATA_PROPS(36,1,1,0,"i16");
          _SFD_SET_DATA_PROPS(37,1,1,0,"frameEN");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2694);
        _SFD_CV_INIT_EML_IF(0,1,0,500,510,579,628);

        {
          static int caseStart[] = { -1, 478, 642, 699, 743, 787, 831, 875, 919,
            963, 1007, 1052, 1099, 1146, 1193, 1304, 1391, 1478, 1565, 1650,
            1719, 1788, 1857, 1926, 1995, 2064, 2133, 2202, 2272, 2342, 2412,
            2482, 2552, 2622 };

          static int caseExprEnd[] = { 8, 484, 648, 705, 749, 793, 837, 881, 925,
            969, 1013, 1059, 1106, 1153, 1200, 1311, 1398, 1485, 1572, 1657,
            1726, 1795, 1864, 1933, 2002, 2071, 2140, 2209, 2279, 2349, 2419,
            2489, 2559, 2629 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,461,474,2690,34,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_INT16,0,NULL,1,1,9,0,1,-3,0,
          (MexFcnForType)c5_f_sf_marshallOut,(MexInFcnForType)c5_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_inp);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c5_i1);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c5_out);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c5_o1);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c5_o2);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c5_o3);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c5_o4);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c5_o5);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c5_o6);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c5_o7);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c5_o8);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c5_o9);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c5_o10);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c5_o11);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c5_o12);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c5_o13);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c5_o14);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c5_o15);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c5_o16);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c5_pop);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c5_convert_address);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c5_state_address);
        _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c5_i2);
        _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c5_i3);
        _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c5_i4);
        _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c5_i5);
        _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c5_i6);
        _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c5_i7);
        _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c5_i8);
        _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c5_i9);
        _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c5_i10);
        _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c5_i11);
        _SFD_SET_DATA_VALUE_PTR(32U, chartInstance->c5_i12);
        _SFD_SET_DATA_VALUE_PTR(33U, chartInstance->c5_i13);
        _SFD_SET_DATA_VALUE_PTR(34U, chartInstance->c5_i14);
        _SFD_SET_DATA_VALUE_PTR(35U, chartInstance->c5_i15);
        _SFD_SET_DATA_VALUE_PTR(36U, chartInstance->c5_i16);
        _SFD_SET_DATA_VALUE_PTR(37U, chartInstance->c5_frameEN);
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
  return "bVHfmmhq0JN2BgJk1n15TC";
}

static void sf_opaque_initialize_c5_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_Basic_DMT(void *chartInstanceVar)
{
  enable_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_Basic_DMT(void *chartInstanceVar)
{
  disable_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_Basic_DMT(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c5_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Basic_DMT(SimStruct *S)
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
    initialize_params_c5_Basic_DMT((SFc5_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
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
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,18);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,18);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=18; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 18; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4211448785U));
  ssSetChecksum1(S,(4033272163U));
  ssSetChecksum2(S,(2847888973U));
  ssSetChecksum3(S,(1634593639U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c5_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Basic_DMT(SimStruct *S)
{
  SFc5_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc5_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_Basic_DMT;
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

void c5_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
