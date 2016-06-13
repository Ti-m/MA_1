/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Basic_DMT_sfun.h"
#include "c10_Basic_DMT.h"
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
static const char * c10_debug_family_names[70] = { "nargin", "nargout", "inp",
  "i1", "i2", "i3", "i4", "i5", "i6", "i7", "i8", "i9", "i10", "i11", "i12",
  "i13", "i14", "i15", "i16", "i17", "i18", "i19", "i20", "i21", "i22", "i23",
  "i24", "i25", "i26", "i27", "i28", "i29", "i30", "i31", "i32", "frameEN",
  "out", "o1", "o2", "o3", "o4", "o5", "o6", "o7", "o8", "o9", "o10", "o11",
  "o12", "o13", "o14", "o15", "o16", "o17", "o18", "o19", "o20", "o21", "o22",
  "o23", "o24", "o25", "o26", "o27", "o28", "o29", "o30", "o31", "o32", "pop" };

static const mxArray *c10_eml_mx;
static const mxArray *c10_b_eml_mx;

/* Function Declarations */
static void initialize_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance);
static void initialize_params_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance);
static void enable_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *chartInstance);
static void disable_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_Basic_DMT
  (SFc10_Basic_DMTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *
  chartInstance);
static void set_sim_state_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_st);
static void finalize_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *chartInstance);
static void sf_gateway_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance);
static void mdl_start_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *chartInstance);
static void c10_chartstep_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance);
static void initSimStructsc10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c10_b_pop, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static cint16_T c10_c_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(const char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u);
static void c10_strcmpi(SFc10_Basic_DMTInstanceStruct *chartInstance);
static void c10_eml_scalar_eg(SFc10_Basic_DMTInstanceStruct *chartInstance);
static cint16_T c10_mtimes(SFc10_Basic_DMTInstanceStruct *chartInstance, int16_T
  c10_b0);
static void c10_b_strcmpi(SFc10_Basic_DMTInstanceStruct *chartInstance);
static cint16_T c10_plus(SFc10_Basic_DMTInstanceStruct *chartInstance, real_T
  c10_a0, cint16_T c10_b0);
static cint16_T c10_b_mtimes(SFc10_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c10_a0, int16_T c10_b0);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_d_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static cint16_T c10_e_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_b_out, const char_T *c10_identifier);
static cint16_T c10_f_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int16_T c10_g_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_h_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_Basic_DMT, const char_T
  *c10_identifier);
static uint8_T c10_i_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static int16_T c10_get_convert(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_elementIndex);
static void c10_set_convert(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_elementIndex, int16_T c10_elementValue);
static int16_T *c10_access_convert(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_rdOnly);
static real_T c10_get_state(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_elementIndex);
static void c10_set_state(SFc10_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c10_elementIndex, real_T c10_elementValue);
static real_T *c10_access_state(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_rdOnly);
static void init_dsm_address_info(SFc10_Basic_DMTInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc10_Basic_DMTInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_Basic_DMT = 0U;
  sf_mex_assign(&c10_b_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 10U, 15, "WordLength", 6, 9.0, 15, "FractionLength", 6,
    3.0, 15, "BinaryPoint", 6, 3.0, 15, "Slope", 6, 0.125, 15, "FixedExponent",
    6, -3.0), true);
  sf_mex_assign(&c10_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
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

static void initialize_params_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c10_update_debugger_state_c10_Basic_DMT
  (SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *
  chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  const mxArray *c10_b_y = NULL;
  cint16_T c10_u;
  const mxArray *c10_c_y = NULL;
  const mxArray *c10_d_y = NULL;
  cint16_T c10_b_u;
  const mxArray *c10_e_y = NULL;
  const mxArray *c10_f_y = NULL;
  cint16_T c10_c_u;
  const mxArray *c10_g_y = NULL;
  const mxArray *c10_h_y = NULL;
  cint16_T c10_d_u;
  const mxArray *c10_i_y = NULL;
  const mxArray *c10_j_y = NULL;
  cint16_T c10_e_u;
  const mxArray *c10_k_y = NULL;
  const mxArray *c10_l_y = NULL;
  cint16_T c10_f_u;
  const mxArray *c10_m_y = NULL;
  const mxArray *c10_n_y = NULL;
  cint16_T c10_g_u;
  const mxArray *c10_o_y = NULL;
  const mxArray *c10_p_y = NULL;
  cint16_T c10_h_u;
  const mxArray *c10_q_y = NULL;
  const mxArray *c10_r_y = NULL;
  cint16_T c10_i_u;
  const mxArray *c10_s_y = NULL;
  const mxArray *c10_t_y = NULL;
  cint16_T c10_j_u;
  const mxArray *c10_u_y = NULL;
  const mxArray *c10_v_y = NULL;
  cint16_T c10_k_u;
  const mxArray *c10_w_y = NULL;
  const mxArray *c10_x_y = NULL;
  cint16_T c10_l_u;
  const mxArray *c10_y_y = NULL;
  const mxArray *c10_ab_y = NULL;
  cint16_T c10_m_u;
  const mxArray *c10_bb_y = NULL;
  const mxArray *c10_cb_y = NULL;
  cint16_T c10_n_u;
  const mxArray *c10_db_y = NULL;
  const mxArray *c10_eb_y = NULL;
  cint16_T c10_o_u;
  const mxArray *c10_fb_y = NULL;
  const mxArray *c10_gb_y = NULL;
  cint16_T c10_p_u;
  const mxArray *c10_hb_y = NULL;
  const mxArray *c10_ib_y = NULL;
  cint16_T c10_q_u;
  const mxArray *c10_jb_y = NULL;
  const mxArray *c10_kb_y = NULL;
  cint16_T c10_r_u;
  const mxArray *c10_lb_y = NULL;
  const mxArray *c10_mb_y = NULL;
  cint16_T c10_s_u;
  const mxArray *c10_nb_y = NULL;
  const mxArray *c10_ob_y = NULL;
  cint16_T c10_t_u;
  const mxArray *c10_pb_y = NULL;
  const mxArray *c10_qb_y = NULL;
  cint16_T c10_u_u;
  const mxArray *c10_rb_y = NULL;
  const mxArray *c10_sb_y = NULL;
  cint16_T c10_v_u;
  const mxArray *c10_tb_y = NULL;
  const mxArray *c10_ub_y = NULL;
  cint16_T c10_w_u;
  const mxArray *c10_vb_y = NULL;
  const mxArray *c10_wb_y = NULL;
  cint16_T c10_x_u;
  const mxArray *c10_xb_y = NULL;
  const mxArray *c10_yb_y = NULL;
  cint16_T c10_y_u;
  const mxArray *c10_ac_y = NULL;
  const mxArray *c10_bc_y = NULL;
  cint16_T c10_ab_u;
  const mxArray *c10_cc_y = NULL;
  const mxArray *c10_dc_y = NULL;
  cint16_T c10_bb_u;
  const mxArray *c10_ec_y = NULL;
  const mxArray *c10_fc_y = NULL;
  cint16_T c10_cb_u;
  const mxArray *c10_gc_y = NULL;
  const mxArray *c10_hc_y = NULL;
  cint16_T c10_db_u;
  const mxArray *c10_ic_y = NULL;
  const mxArray *c10_jc_y = NULL;
  cint16_T c10_eb_u;
  const mxArray *c10_kc_y = NULL;
  const mxArray *c10_lc_y = NULL;
  cint16_T c10_fb_u;
  const mxArray *c10_mc_y = NULL;
  const mxArray *c10_nc_y = NULL;
  cint16_T c10_gb_u;
  const mxArray *c10_oc_y = NULL;
  const mxArray *c10_pc_y = NULL;
  cint16_T c10_hb_u;
  const mxArray *c10_qc_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_ib_u;
  const mxArray *c10_rc_y = NULL;
  uint8_T c10_b_hoistedGlobal;
  uint8_T c10_jb_u;
  const mxArray *c10_sc_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(35, 1), false);
  c10_b_y = NULL;
  c10_u.re = chartInstance->c10_o1->re;
  c10_u.im = chartInstance->c10_o1->im;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_c_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_d_y = NULL;
  c10_b_u.re = chartInstance->c10_o10->re;
  c10_b_u.im = chartInstance->c10_o10->im;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_d_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_e_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 1, c10_d_y);
  c10_f_y = NULL;
  c10_c_u.re = chartInstance->c10_o11->re;
  c10_c_u.im = chartInstance->c10_o11->im;
  c10_g_y = NULL;
  sf_mex_assign(&c10_g_y, sf_mex_create("y", &c10_c_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_f_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_g_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 2, c10_f_y);
  c10_h_y = NULL;
  c10_d_u.re = chartInstance->c10_o12->re;
  c10_d_u.im = chartInstance->c10_o12->im;
  c10_i_y = NULL;
  sf_mex_assign(&c10_i_y, sf_mex_create("y", &c10_d_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_h_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_i_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 3, c10_h_y);
  c10_j_y = NULL;
  c10_e_u.re = chartInstance->c10_o13->re;
  c10_e_u.im = chartInstance->c10_o13->im;
  c10_k_y = NULL;
  sf_mex_assign(&c10_k_y, sf_mex_create("y", &c10_e_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_j_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_k_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 4, c10_j_y);
  c10_l_y = NULL;
  c10_f_u.re = chartInstance->c10_o14->re;
  c10_f_u.im = chartInstance->c10_o14->im;
  c10_m_y = NULL;
  sf_mex_assign(&c10_m_y, sf_mex_create("y", &c10_f_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_l_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_m_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 5, c10_l_y);
  c10_n_y = NULL;
  c10_g_u.re = chartInstance->c10_o15->re;
  c10_g_u.im = chartInstance->c10_o15->im;
  c10_o_y = NULL;
  sf_mex_assign(&c10_o_y, sf_mex_create("y", &c10_g_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_n_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_o_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 6, c10_n_y);
  c10_p_y = NULL;
  c10_h_u.re = chartInstance->c10_o16->re;
  c10_h_u.im = chartInstance->c10_o16->im;
  c10_q_y = NULL;
  sf_mex_assign(&c10_q_y, sf_mex_create("y", &c10_h_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_p_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_q_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 7, c10_p_y);
  c10_r_y = NULL;
  c10_i_u.re = chartInstance->c10_o17->re;
  c10_i_u.im = chartInstance->c10_o17->im;
  c10_s_y = NULL;
  sf_mex_assign(&c10_s_y, sf_mex_create("y", &c10_i_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_r_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_s_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 8, c10_r_y);
  c10_t_y = NULL;
  c10_j_u.re = chartInstance->c10_o18->re;
  c10_j_u.im = chartInstance->c10_o18->im;
  c10_u_y = NULL;
  sf_mex_assign(&c10_u_y, sf_mex_create("y", &c10_j_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_t_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_u_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 9, c10_t_y);
  c10_v_y = NULL;
  c10_k_u.re = chartInstance->c10_o19->re;
  c10_k_u.im = chartInstance->c10_o19->im;
  c10_w_y = NULL;
  sf_mex_assign(&c10_w_y, sf_mex_create("y", &c10_k_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_v_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_w_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 10, c10_v_y);
  c10_x_y = NULL;
  c10_l_u.re = chartInstance->c10_o2->re;
  c10_l_u.im = chartInstance->c10_o2->im;
  c10_y_y = NULL;
  sf_mex_assign(&c10_y_y, sf_mex_create("y", &c10_l_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_x_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                 (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
    15, "simulinkarray", 14, c10_y_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 11, c10_x_y);
  c10_ab_y = NULL;
  c10_m_u.re = chartInstance->c10_o20->re;
  c10_m_u.im = chartInstance->c10_o20->im;
  c10_bb_y = NULL;
  sf_mex_assign(&c10_bb_y, sf_mex_create("y", &c10_m_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_ab_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_bb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 12, c10_ab_y);
  c10_cb_y = NULL;
  c10_n_u.re = chartInstance->c10_o21->re;
  c10_n_u.im = chartInstance->c10_o21->im;
  c10_db_y = NULL;
  sf_mex_assign(&c10_db_y, sf_mex_create("y", &c10_n_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_cb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_db_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 13, c10_cb_y);
  c10_eb_y = NULL;
  c10_o_u.re = chartInstance->c10_o22->re;
  c10_o_u.im = chartInstance->c10_o22->im;
  c10_fb_y = NULL;
  sf_mex_assign(&c10_fb_y, sf_mex_create("y", &c10_o_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_eb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_fb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 14, c10_eb_y);
  c10_gb_y = NULL;
  c10_p_u.re = chartInstance->c10_o23->re;
  c10_p_u.im = chartInstance->c10_o23->im;
  c10_hb_y = NULL;
  sf_mex_assign(&c10_hb_y, sf_mex_create("y", &c10_p_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_gb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_hb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 15, c10_gb_y);
  c10_ib_y = NULL;
  c10_q_u.re = chartInstance->c10_o24->re;
  c10_q_u.im = chartInstance->c10_o24->im;
  c10_jb_y = NULL;
  sf_mex_assign(&c10_jb_y, sf_mex_create("y", &c10_q_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_ib_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_jb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 16, c10_ib_y);
  c10_kb_y = NULL;
  c10_r_u.re = chartInstance->c10_o25->re;
  c10_r_u.im = chartInstance->c10_o25->im;
  c10_lb_y = NULL;
  sf_mex_assign(&c10_lb_y, sf_mex_create("y", &c10_r_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_kb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_lb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 17, c10_kb_y);
  c10_mb_y = NULL;
  c10_s_u.re = chartInstance->c10_o26->re;
  c10_s_u.im = chartInstance->c10_o26->im;
  c10_nb_y = NULL;
  sf_mex_assign(&c10_nb_y, sf_mex_create("y", &c10_s_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_nb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 18, c10_mb_y);
  c10_ob_y = NULL;
  c10_t_u.re = chartInstance->c10_o27->re;
  c10_t_u.im = chartInstance->c10_o27->im;
  c10_pb_y = NULL;
  sf_mex_assign(&c10_pb_y, sf_mex_create("y", &c10_t_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_ob_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_pb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 19, c10_ob_y);
  c10_qb_y = NULL;
  c10_u_u.re = chartInstance->c10_o28->re;
  c10_u_u.im = chartInstance->c10_o28->im;
  c10_rb_y = NULL;
  sf_mex_assign(&c10_rb_y, sf_mex_create("y", &c10_u_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_qb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_rb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 20, c10_qb_y);
  c10_sb_y = NULL;
  c10_v_u.re = chartInstance->c10_o29->re;
  c10_v_u.im = chartInstance->c10_o29->im;
  c10_tb_y = NULL;
  sf_mex_assign(&c10_tb_y, sf_mex_create("y", &c10_v_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_sb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_tb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 21, c10_sb_y);
  c10_ub_y = NULL;
  c10_w_u.re = chartInstance->c10_o3->re;
  c10_w_u.im = chartInstance->c10_o3->im;
  c10_vb_y = NULL;
  sf_mex_assign(&c10_vb_y, sf_mex_create("y", &c10_w_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_ub_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_vb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 22, c10_ub_y);
  c10_wb_y = NULL;
  c10_x_u.re = chartInstance->c10_o30->re;
  c10_x_u.im = chartInstance->c10_o30->im;
  c10_xb_y = NULL;
  sf_mex_assign(&c10_xb_y, sf_mex_create("y", &c10_x_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_wb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_xb_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 23, c10_wb_y);
  c10_yb_y = NULL;
  c10_y_u.re = chartInstance->c10_o31->re;
  c10_y_u.im = chartInstance->c10_o31->im;
  c10_ac_y = NULL;
  sf_mex_assign(&c10_ac_y, sf_mex_create("y", &c10_y_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_yb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_ac_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 24, c10_yb_y);
  c10_bc_y = NULL;
  c10_ab_u.re = chartInstance->c10_o32->re;
  c10_ab_u.im = chartInstance->c10_o32->im;
  c10_cc_y = NULL;
  sf_mex_assign(&c10_cc_y, sf_mex_create("y", &c10_ab_u, 4, 1U, 0U, 0U, 0),
                false);
  sf_mex_assign(&c10_bc_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_cc_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 25, c10_bc_y);
  c10_dc_y = NULL;
  c10_bb_u.re = chartInstance->c10_o4->re;
  c10_bb_u.im = chartInstance->c10_o4->im;
  c10_ec_y = NULL;
  sf_mex_assign(&c10_ec_y, sf_mex_create("y", &c10_bb_u, 4, 1U, 0U, 0U, 0),
                false);
  sf_mex_assign(&c10_dc_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_ec_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 26, c10_dc_y);
  c10_fc_y = NULL;
  c10_cb_u.re = chartInstance->c10_o5->re;
  c10_cb_u.im = chartInstance->c10_o5->im;
  c10_gc_y = NULL;
  sf_mex_assign(&c10_gc_y, sf_mex_create("y", &c10_cb_u, 4, 1U, 0U, 0U, 0),
                false);
  sf_mex_assign(&c10_fc_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_gc_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 27, c10_fc_y);
  c10_hc_y = NULL;
  c10_db_u.re = chartInstance->c10_o6->re;
  c10_db_u.im = chartInstance->c10_o6->im;
  c10_ic_y = NULL;
  sf_mex_assign(&c10_ic_y, sf_mex_create("y", &c10_db_u, 4, 1U, 0U, 0U, 0),
                false);
  sf_mex_assign(&c10_hc_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_ic_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 28, c10_hc_y);
  c10_jc_y = NULL;
  c10_eb_u.re = chartInstance->c10_o7->re;
  c10_eb_u.im = chartInstance->c10_o7->im;
  c10_kc_y = NULL;
  sf_mex_assign(&c10_kc_y, sf_mex_create("y", &c10_eb_u, 4, 1U, 0U, 0U, 0),
                false);
  sf_mex_assign(&c10_jc_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_kc_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 29, c10_jc_y);
  c10_lc_y = NULL;
  c10_fb_u.re = chartInstance->c10_o8->re;
  c10_fb_u.im = chartInstance->c10_o8->im;
  c10_mc_y = NULL;
  sf_mex_assign(&c10_mc_y, sf_mex_create("y", &c10_fb_u, 4, 1U, 0U, 0U, 0),
                false);
  sf_mex_assign(&c10_lc_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_mc_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 30, c10_lc_y);
  c10_nc_y = NULL;
  c10_gb_u.re = chartInstance->c10_o9->re;
  c10_gb_u.im = chartInstance->c10_o9->im;
  c10_oc_y = NULL;
  sf_mex_assign(&c10_oc_y, sf_mex_create("y", &c10_gb_u, 4, 1U, 0U, 0U, 0),
                false);
  sf_mex_assign(&c10_nc_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_oc_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 31, c10_nc_y);
  c10_pc_y = NULL;
  c10_hb_u.re = chartInstance->c10_out->re;
  c10_hb_u.im = chartInstance->c10_out->im;
  c10_qc_y = NULL;
  sf_mex_assign(&c10_qc_y, sf_mex_create("y", &c10_hb_u, 4, 1U, 0U, 0U, 0),
                false);
  sf_mex_assign(&c10_pc_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
    sf_mex_dup(c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_qc_y, 15, "fimathislocal", 3, true), false);
  sf_mex_setcell(c10_y, 32, c10_pc_y);
  c10_hoistedGlobal = *chartInstance->c10_pop;
  c10_ib_u = c10_hoistedGlobal;
  c10_rc_y = NULL;
  sf_mex_assign(&c10_rc_y, sf_mex_create("y", &c10_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c10_y, 33, c10_rc_y);
  c10_b_hoistedGlobal = chartInstance->c10_is_active_c10_Basic_DMT;
  c10_jb_u = c10_b_hoistedGlobal;
  c10_sc_y = NULL;
  sf_mex_assign(&c10_sc_y, sf_mex_create("y", &c10_jb_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c10_y, 34, c10_sc_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  *chartInstance->c10_o1 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "o1");
  *chartInstance->c10_o10 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 1)), "o10");
  *chartInstance->c10_o11 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 2)), "o11");
  *chartInstance->c10_o12 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 3)), "o12");
  *chartInstance->c10_o13 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 4)), "o13");
  *chartInstance->c10_o14 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 5)), "o14");
  *chartInstance->c10_o15 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 6)), "o15");
  *chartInstance->c10_o16 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 7)), "o16");
  *chartInstance->c10_o17 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 8)), "o17");
  *chartInstance->c10_o18 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 9)), "o18");
  *chartInstance->c10_o19 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 10)), "o19");
  *chartInstance->c10_o2 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 11)), "o2");
  *chartInstance->c10_o20 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 12)), "o20");
  *chartInstance->c10_o21 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 13)), "o21");
  *chartInstance->c10_o22 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 14)), "o22");
  *chartInstance->c10_o23 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 15)), "o23");
  *chartInstance->c10_o24 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 16)), "o24");
  *chartInstance->c10_o25 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 17)), "o25");
  *chartInstance->c10_o26 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 18)), "o26");
  *chartInstance->c10_o27 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 19)), "o27");
  *chartInstance->c10_o28 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 20)), "o28");
  *chartInstance->c10_o29 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 21)), "o29");
  *chartInstance->c10_o3 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 22)), "o3");
  *chartInstance->c10_o30 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 23)), "o30");
  *chartInstance->c10_o31 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 24)), "o31");
  *chartInstance->c10_o32 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 25)), "o32");
  *chartInstance->c10_o4 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 26)), "o4");
  *chartInstance->c10_o5 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 27)), "o5");
  *chartInstance->c10_o6 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 28)), "o6");
  *chartInstance->c10_o7 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 29)), "o7");
  *chartInstance->c10_o8 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 30)), "o8");
  *chartInstance->c10_o9 = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 31)), "o9");
  *chartInstance->c10_out = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 32)), "out");
  *chartInstance->c10_pop = c10_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 33)), "pop");
  chartInstance->c10_is_active_c10_Basic_DMT = c10_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 34)),
     "is_active_c10_Basic_DMT");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_Basic_DMT(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
  sf_mex_destroy(&c10_eml_mx);
  sf_mex_destroy(&c10_b_eml_mx);
}

static void sf_gateway_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c10_sfEvent);
  chartInstance->c10_sfEvent = CALL_EVENT;
  c10_chartstep_c10_Basic_DMT(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Basic_DMTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c10_pop, 35U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c10_frameEN, 69U);
}

static void mdl_start_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_chartstep_c10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance)
{
  real_T c10_hoistedGlobal;
  cint16_T c10_b_inp;
  cint16_T c10_b_i1;
  cint16_T c10_b_i2;
  cint16_T c10_b_i3;
  cint16_T c10_b_i4;
  cint16_T c10_b_i5;
  cint16_T c10_b_i6;
  cint16_T c10_b_i7;
  cint16_T c10_b_i8;
  cint16_T c10_b_i9;
  cint16_T c10_b_i10;
  cint16_T c10_b_i11;
  cint16_T c10_b_i12;
  cint16_T c10_b_i13;
  cint16_T c10_b_i14;
  cint16_T c10_b_i15;
  cint16_T c10_b_i16;
  cint16_T c10_b_i17;
  cint16_T c10_b_i18;
  cint16_T c10_b_i19;
  cint16_T c10_b_i20;
  cint16_T c10_b_i21;
  cint16_T c10_b_i22;
  cint16_T c10_b_i23;
  cint16_T c10_b_i24;
  cint16_T c10_b_i25;
  cint16_T c10_b_i26;
  cint16_T c10_b_i27;
  cint16_T c10_b_i28;
  cint16_T c10_b_i29;
  cint16_T c10_b_i30;
  cint16_T c10_b_i31;
  cint16_T c10_b_i32;
  real_T c10_b_frameEN;
  uint32_T c10_debug_family_var_map[70];
  real_T c10_nargin = 34.0;
  real_T c10_nargout = 34.0;
  cint16_T c10_b_out;
  cint16_T c10_b_o1;
  cint16_T c10_b_o2;
  cint16_T c10_b_o3;
  cint16_T c10_b_o4;
  cint16_T c10_b_o5;
  cint16_T c10_b_o6;
  cint16_T c10_b_o7;
  cint16_T c10_b_o8;
  cint16_T c10_b_o9;
  cint16_T c10_b_o10;
  cint16_T c10_b_o11;
  cint16_T c10_b_o12;
  cint16_T c10_b_o13;
  cint16_T c10_b_o14;
  cint16_T c10_b_o15;
  cint16_T c10_b_o16;
  cint16_T c10_b_o17;
  cint16_T c10_b_o18;
  cint16_T c10_b_o19;
  cint16_T c10_b_o20;
  cint16_T c10_b_o21;
  cint16_T c10_b_o22;
  cint16_T c10_b_o23;
  cint16_T c10_b_o24;
  cint16_T c10_b_o25;
  cint16_T c10_b_o26;
  cint16_T c10_b_o27;
  cint16_T c10_b_o28;
  cint16_T c10_b_o29;
  cint16_T c10_b_o30;
  cint16_T c10_b_o31;
  cint16_T c10_b_o32;
  real_T c10_b_pop;
  cint16_T c10_ic0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *chartInstance->c10_frameEN;
  c10_b_inp = *chartInstance->c10_inp;
  c10_b_i1 = *chartInstance->c10_i1;
  c10_b_i2 = *chartInstance->c10_i2;
  c10_b_i3 = *chartInstance->c10_i3;
  c10_b_i4 = *chartInstance->c10_i4;
  c10_b_i5 = *chartInstance->c10_i5;
  c10_b_i6 = *chartInstance->c10_i6;
  c10_b_i7 = *chartInstance->c10_i7;
  c10_b_i8 = *chartInstance->c10_i8;
  c10_b_i9 = *chartInstance->c10_i9;
  c10_b_i10 = *chartInstance->c10_i10;
  c10_b_i11 = *chartInstance->c10_i11;
  c10_b_i12 = *chartInstance->c10_i12;
  c10_b_i13 = *chartInstance->c10_i13;
  c10_b_i14 = *chartInstance->c10_i14;
  c10_b_i15 = *chartInstance->c10_i15;
  c10_b_i16 = *chartInstance->c10_i16;
  c10_b_i17 = *chartInstance->c10_i17;
  c10_b_i18 = *chartInstance->c10_i18;
  c10_b_i19 = *chartInstance->c10_i19;
  c10_b_i20 = *chartInstance->c10_i20;
  c10_b_i21 = *chartInstance->c10_i21;
  c10_b_i22 = *chartInstance->c10_i22;
  c10_b_i23 = *chartInstance->c10_i23;
  c10_b_i24 = *chartInstance->c10_i24;
  c10_b_i25 = *chartInstance->c10_i25;
  c10_b_i26 = *chartInstance->c10_i26;
  c10_b_i27 = *chartInstance->c10_i27;
  c10_b_i28 = *chartInstance->c10_i28;
  c10_b_i29 = *chartInstance->c10_i29;
  c10_b_i30 = *chartInstance->c10_i30;
  c10_b_i31 = *chartInstance->c10_i31;
  c10_b_i32 = *chartInstance->c10_i32;
  c10_b_frameEN = c10_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 70U, 70U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_inp, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i1, 3U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i2, 4U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i3, 5U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i4, 6U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i5, 7U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i6, 8U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i7, 9U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i8, 10U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i9, 11U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i10, 12U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i11, 13U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i12, 14U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i13, 15U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i14, 16U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i15, 17U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i16, 18U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i17, 19U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i18, 20U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i19, 21U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i20, 22U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i21, 23U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i22, 24U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i23, 25U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i24, 26U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i25, 27U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i26, 28U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i27, 29U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i28, 30U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i29, 31U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i30, 32U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i31, 33U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_i32, 34U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_b_frameEN, 35U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 36U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o1, 37U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o2, 38U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o3, 39U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o4, 40U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o5, 41U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o6, 42U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o7, 43U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o8, 44U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o9, 45U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o10, 46U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o11, 47U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o12, 48U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o13, 49U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o14, 50U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o15, 51U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o16, 52U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o17, 53U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o18, 54U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o19, 55U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o20, 56U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o21, 57U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o22, 58U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o23, 59U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o24, 60U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o25, 61U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o26, 62U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o27, 63U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o28, 64U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o29, 65U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o30, 66U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o31, 67U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_o32, 68U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_pop, 69U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 12);
  c10_b_o1 = c10_b_i1;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 13);
  c10_b_o2 = c10_b_i2;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 14);
  c10_b_o3 = c10_b_i3;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 15);
  c10_b_o4 = c10_b_i4;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 16);
  c10_b_o5 = c10_b_i5;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 17);
  c10_b_o6 = c10_b_i6;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 18);
  c10_b_o7 = c10_b_i7;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 19);
  c10_b_o8 = c10_b_i8;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 20);
  c10_b_o9 = c10_b_i9;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 21);
  c10_b_o10 = c10_b_i10;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 22);
  c10_b_o11 = c10_b_i11;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 23);
  c10_b_o12 = c10_b_i12;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 24);
  c10_b_o13 = c10_b_i13;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 25);
  c10_b_o14 = c10_b_i14;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 26);
  c10_b_o15 = c10_b_i15;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 27);
  c10_b_o16 = c10_b_i16;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 28);
  c10_b_o17 = c10_b_i17;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 29);
  c10_b_o18 = c10_b_i18;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 30);
  c10_b_o19 = c10_b_i19;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 31);
  c10_b_o20 = c10_b_i20;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 32);
  c10_b_o21 = c10_b_i21;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 33);
  c10_b_o22 = c10_b_i22;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 34);
  c10_b_o23 = c10_b_i23;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 35);
  c10_b_o24 = c10_b_i24;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 36);
  c10_b_o25 = c10_b_i25;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 37);
  c10_b_o26 = c10_b_i26;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 38);
  c10_b_o27 = c10_b_i27;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 39);
  c10_b_o28 = c10_b_i28;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 40);
  c10_b_o29 = c10_b_i29;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 41);
  c10_b_o30 = c10_b_i30;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 42);
  c10_b_o31 = c10_b_i31;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 43);
  c10_b_o32 = c10_b_i32;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 44);
  c10_b_pop = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 45);
  c10_ic0 = c10_mtimes(chartInstance, c10_get_convert(chartInstance, 0));
  c10_b_out = c10_plus(chartInstance, 0.0, c10_ic0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 46);
  switch ((int32_T)_SFD_INTEGER_CHECK("state", c10_get_state(chartInstance, 0)))
  {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 48);
    if (CV_EML_IF(0, 1, 0, c10_b_frameEN != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 49);
      c10_set_state(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 1);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 51);
      c10_set_state(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 1);
    }
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 55);
    c10_b_o1 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 56);
    c10_set_state(chartInstance, 0, 2.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 58);
    c10_b_o2 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 59);
    c10_set_state(chartInstance, 0, 3.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 61);
    c10_b_o3 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 62);
    c10_set_state(chartInstance, 0, 4.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 64);
    c10_b_o4 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 65);
    c10_set_state(chartInstance, 0, 5.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 5:
    CV_EML_SWITCH(0, 1, 0, 6);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 67);
    c10_b_o5 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 68);
    c10_set_state(chartInstance, 0, 6.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 6:
    CV_EML_SWITCH(0, 1, 0, 7);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 70);
    c10_b_o6 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 71);
    c10_set_state(chartInstance, 0, 7.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 7:
    CV_EML_SWITCH(0, 1, 0, 8);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 73);
    c10_b_o7 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 74);
    c10_set_state(chartInstance, 0, 8.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 8:
    CV_EML_SWITCH(0, 1, 0, 9);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 76);
    c10_b_o8 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 77);
    c10_set_state(chartInstance, 0, 9.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 9:
    CV_EML_SWITCH(0, 1, 0, 10);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 79);
    c10_b_o9 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 80);
    c10_set_state(chartInstance, 0, 10.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 10:
    CV_EML_SWITCH(0, 1, 0, 11);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 82);
    c10_b_o10 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 83);
    c10_set_state(chartInstance, 0, 11.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 11:
    CV_EML_SWITCH(0, 1, 0, 12);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 85);
    c10_b_o11 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 86);
    c10_set_state(chartInstance, 0, 12.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 12:
    CV_EML_SWITCH(0, 1, 0, 13);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 88);
    c10_b_o12 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 89);
    c10_set_state(chartInstance, 0, 13.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 13:
    CV_EML_SWITCH(0, 1, 0, 14);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 91);
    c10_b_o13 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 92);
    c10_set_state(chartInstance, 0, 14.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 14:
    CV_EML_SWITCH(0, 1, 0, 15);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 94);
    c10_b_o14 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 95);
    c10_set_state(chartInstance, 0, 15.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 15:
    CV_EML_SWITCH(0, 1, 0, 16);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 97);
    c10_b_o15 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 98);
    c10_set_state(chartInstance, 0, 16.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 16:
    CV_EML_SWITCH(0, 1, 0, 17);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 100);
    c10_b_o16 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 101);
    c10_set_state(chartInstance, 0, 17.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 17:
    CV_EML_SWITCH(0, 1, 0, 18);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 103);
    c10_b_o17 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 104);
    c10_set_state(chartInstance, 0, 18.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 18:
    CV_EML_SWITCH(0, 1, 0, 19);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 106);
    c10_b_o18 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 107);
    c10_set_state(chartInstance, 0, 19.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 19:
    CV_EML_SWITCH(0, 1, 0, 20);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 109);
    c10_b_o19 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 110);
    c10_set_state(chartInstance, 0, 20.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 20:
    CV_EML_SWITCH(0, 1, 0, 21);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 112);
    c10_b_o20 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 113);
    c10_set_state(chartInstance, 0, 21.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 21:
    CV_EML_SWITCH(0, 1, 0, 22);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 115);
    c10_b_o21 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 116);
    c10_set_state(chartInstance, 0, 22.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 22:
    CV_EML_SWITCH(0, 1, 0, 23);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 118);
    c10_b_o22 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 119);
    c10_set_state(chartInstance, 0, 23.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 23:
    CV_EML_SWITCH(0, 1, 0, 24);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 121);
    c10_b_o23 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 122);
    c10_set_state(chartInstance, 0, 24.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 24:
    CV_EML_SWITCH(0, 1, 0, 25);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 124);
    c10_b_o24 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 125);
    c10_set_state(chartInstance, 0, 25.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 25:
    CV_EML_SWITCH(0, 1, 0, 26);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, MAX_int8_T);
    c10_b_o25 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 128U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_inp, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 129U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 130U);
    c10_set_state(chartInstance, 0, 26.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 26:
    CV_EML_SWITCH(0, 1, 0, 27);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 132U);
    c10_b_o26 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 133U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_inp, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 134U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 135U);
    c10_set_state(chartInstance, 0, 27.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 27:
    CV_EML_SWITCH(0, 1, 0, 28);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 137U);
    c10_b_o27 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 138U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_inp, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 139U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 140U);
    c10_set_state(chartInstance, 0, 28.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 28:
    CV_EML_SWITCH(0, 1, 0, 29);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 142U);
    c10_b_o28 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 143U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_inp, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 144U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 145U);
    c10_set_state(chartInstance, 0, 29.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 29:
    CV_EML_SWITCH(0, 1, 0, 30);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 147U);
    c10_b_o29 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 148U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_inp, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 149U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 150U);
    c10_set_state(chartInstance, 0, 30.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 30:
    CV_EML_SWITCH(0, 1, 0, 31);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 152U);
    c10_b_o30 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 153U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_inp, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 154U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 155U);
    c10_set_state(chartInstance, 0, 31.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 31:
    CV_EML_SWITCH(0, 1, 0, 32);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 157U);
    c10_b_o31 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 158U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_inp, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 159U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 160U);
    c10_set_state(chartInstance, 0, 32.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 32:
    CV_EML_SWITCH(0, 1, 0, 33);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 162U);
    c10_b_o32 = c10_b_inp;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 163U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_inp, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 164U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 165U);
    c10_set_state(chartInstance, 0, 33.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 33:
    CV_EML_SWITCH(0, 1, 0, 34);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 167U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i1, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 168U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 169U);
    c10_set_state(chartInstance, 0, 34.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 34:
    CV_EML_SWITCH(0, 1, 0, 35);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 171U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i2, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 172U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 173U);
    c10_set_state(chartInstance, 0, 35.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 35:
    CV_EML_SWITCH(0, 1, 0, 36);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 175U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i3, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 176U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 177U);
    c10_set_state(chartInstance, 0, 36.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 36:
    CV_EML_SWITCH(0, 1, 0, 37);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 179U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i4, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 180U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 181U);
    c10_set_state(chartInstance, 0, 37.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 37:
    CV_EML_SWITCH(0, 1, 0, 38);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 183U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i5, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 184U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 185U);
    c10_set_state(chartInstance, 0, 38.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 38:
    CV_EML_SWITCH(0, 1, 0, 39);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 187U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i6, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 188U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 189U);
    c10_set_state(chartInstance, 0, 39.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 39:
    CV_EML_SWITCH(0, 1, 0, 40);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 191U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i7, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 192U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 193U);
    c10_set_state(chartInstance, 0, 40.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 40:
    CV_EML_SWITCH(0, 1, 0, 41);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 195U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i8, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 196U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 197U);
    c10_set_state(chartInstance, 0, 41.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 41:
    CV_EML_SWITCH(0, 1, 0, 42);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 199U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i9, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 200U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 201U);
    c10_set_state(chartInstance, 0, 42.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 42:
    CV_EML_SWITCH(0, 1, 0, 43);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 203U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i10, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 204U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 205U);
    c10_set_state(chartInstance, 0, 43.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 43:
    CV_EML_SWITCH(0, 1, 0, 44);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 207U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i11, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 208U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 209U);
    c10_set_state(chartInstance, 0, 44.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 44:
    CV_EML_SWITCH(0, 1, 0, 45);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 211U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i12, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 212U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 213U);
    c10_set_state(chartInstance, 0, 45.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 45:
    CV_EML_SWITCH(0, 1, 0, 46);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 215U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i13, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 216U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 217U);
    c10_set_state(chartInstance, 0, 46.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 46:
    CV_EML_SWITCH(0, 1, 0, 47);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 219U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i14, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 220U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 221U);
    c10_set_state(chartInstance, 0, 47.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 47:
    CV_EML_SWITCH(0, 1, 0, 48);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 223U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i15, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 224U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 225U);
    c10_set_state(chartInstance, 0, 48.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 48:
    CV_EML_SWITCH(0, 1, 0, 49);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 227U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i16, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 228U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 229U);
    c10_set_state(chartInstance, 0, 49.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 49:
    CV_EML_SWITCH(0, 1, 0, 50);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 231U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i17, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 232U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 233U);
    c10_set_state(chartInstance, 0, 50.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 50:
    CV_EML_SWITCH(0, 1, 0, 51);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 235U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i18, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 236U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 237U);
    c10_set_state(chartInstance, 0, 51.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 51:
    CV_EML_SWITCH(0, 1, 0, 52);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 239U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i19, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 240U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 241U);
    c10_set_state(chartInstance, 0, 52.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 52:
    CV_EML_SWITCH(0, 1, 0, 53);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 243U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i20, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 244U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 245U);
    c10_set_state(chartInstance, 0, 53.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 53:
    CV_EML_SWITCH(0, 1, 0, 54);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 247U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i21, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 248U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 249U);
    c10_set_state(chartInstance, 0, 54.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 54:
    CV_EML_SWITCH(0, 1, 0, 55);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 251U);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i22, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 252U);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 253U);
    c10_set_state(chartInstance, 0, 55.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 55:
    CV_EML_SWITCH(0, 1, 0, 56);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, MAX_uint8_T);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i23, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 256);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 257);
    c10_set_state(chartInstance, 0, 56.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 56:
    CV_EML_SWITCH(0, 1, 0, 57);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 259);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i24, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 260);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 261);
    c10_set_state(chartInstance, 0, 57.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 57:
    CV_EML_SWITCH(0, 1, 0, 58);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 263);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i25, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 264);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 265);
    c10_set_state(chartInstance, 0, 58.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 58:
    CV_EML_SWITCH(0, 1, 0, 59);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 267);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i26, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 268);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 269);
    c10_set_state(chartInstance, 0, 59.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 59:
    CV_EML_SWITCH(0, 1, 0, 60);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 271);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i27, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 272);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 273);
    c10_set_state(chartInstance, 0, 60.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 60:
    CV_EML_SWITCH(0, 1, 0, 61);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 275);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i28, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 276);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 277);
    c10_set_state(chartInstance, 0, 61.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 61:
    CV_EML_SWITCH(0, 1, 0, 62);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 279);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i29, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 280);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 281);
    c10_set_state(chartInstance, 0, 62.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 62:
    CV_EML_SWITCH(0, 1, 0, 63);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 283);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i30, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 284);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 285);
    c10_set_state(chartInstance, 0, 63.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 63:
    CV_EML_SWITCH(0, 1, 0, 64);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 287);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i31, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 288);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 289);
    c10_set_state(chartInstance, 0, 64.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   case 64:
    CV_EML_SWITCH(0, 1, 0, 65);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 291);
    c10_b_out = c10_b_mtimes(chartInstance, c10_b_i32, c10_get_convert
      (chartInstance, 0));
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 292);
    c10_b_pop = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 293);
    c10_set_state(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -293);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c10_out = c10_b_out;
  *chartInstance->c10_o1 = c10_b_o1;
  *chartInstance->c10_o2 = c10_b_o2;
  *chartInstance->c10_o3 = c10_b_o3;
  *chartInstance->c10_o4 = c10_b_o4;
  *chartInstance->c10_o5 = c10_b_o5;
  *chartInstance->c10_o6 = c10_b_o6;
  *chartInstance->c10_o7 = c10_b_o7;
  *chartInstance->c10_o8 = c10_b_o8;
  *chartInstance->c10_o9 = c10_b_o9;
  *chartInstance->c10_o10 = c10_b_o10;
  *chartInstance->c10_o11 = c10_b_o11;
  *chartInstance->c10_o12 = c10_b_o12;
  *chartInstance->c10_o13 = c10_b_o13;
  *chartInstance->c10_o14 = c10_b_o14;
  *chartInstance->c10_o15 = c10_b_o15;
  *chartInstance->c10_o16 = c10_b_o16;
  *chartInstance->c10_o17 = c10_b_o17;
  *chartInstance->c10_o18 = c10_b_o18;
  *chartInstance->c10_o19 = c10_b_o19;
  *chartInstance->c10_o20 = c10_b_o20;
  *chartInstance->c10_o21 = c10_b_o21;
  *chartInstance->c10_o22 = c10_b_o22;
  *chartInstance->c10_o23 = c10_b_o23;
  *chartInstance->c10_o24 = c10_b_o24;
  *chartInstance->c10_o25 = c10_b_o25;
  *chartInstance->c10_o26 = c10_b_o26;
  *chartInstance->c10_o27 = c10_b_o27;
  *chartInstance->c10_o28 = c10_b_o28;
  *chartInstance->c10_o29 = c10_b_o29;
  *chartInstance->c10_o30 = c10_b_o30;
  *chartInstance->c10_o31 = c10_b_o31;
  *chartInstance->c10_o32 = c10_b_o32;
  *chartInstance->c10_pop = c10_b_pop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c10_sfEvent);
}

static void initSimStructsc10_Basic_DMT(SFc10_Basic_DMTInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  (void)c10_chartNumber;
  (void)c10_instanceNumber;
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct *chartInstance,
  const mxArray *c10_b_pop, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_pop),
    &c10_thisId);
  sf_mex_destroy(&c10_b_pop);
  return c10_y;
}

static real_T c10_b_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_pop;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_b_pop = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_pop),
    &c10_thisId);
  sf_mex_destroy(&c10_b_pop);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData;
  cint16_T c10_u;
  const mxArray *c10_y = NULL;
  cint16_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_mxArrayOutData = NULL;
  c10_u = *(cint16_T *)c10_inData;
  c10_y = NULL;
  c10_b_u.re = c10_u.re;
  c10_b_u.im = c10_u.im;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_b_y, 15, "fimathislocal", 3, false), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static cint16_T c10_c_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  cint16_T c10_y;
  const mxArray *c10_mxFi = NULL;
  const mxArray *c10_mxInt = NULL;
  cint16_T c10_ic1;
  (void)chartInstance;
  sf_mex_check_fi(c10_parentId, c10_u, true, 0U, NULL, c10_eml_mx, c10_b_eml_mx);
  sf_mex_assign(&c10_mxFi, sf_mex_dup(c10_u), false);
  sf_mex_assign(&c10_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c10_mxFi)), false);
  sf_mex_import(c10_parentId, sf_mex_dup(c10_mxInt), &c10_ic1, 1, 4, 1U, 0, 0U,
                0);
  sf_mex_destroy(&c10_mxFi);
  sf_mex_destroy(&c10_mxInt);
  c10_y = c10_ic1;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_o32;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  cint16_T c10_y;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_b_o32 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_o32),
    &c10_thisId);
  sf_mex_destroy(&c10_b_o32);
  *(cint16_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_Basic_DMT_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  const mxArray *c10_rhs1 = NULL;
  const mxArray *c10_lhs1 = NULL;
  const mxArray *c10_rhs2 = NULL;
  const mxArray *c10_lhs2 = NULL;
  const mxArray *c10_rhs3 = NULL;
  const mxArray *c10_lhs3 = NULL;
  const mxArray *c10_rhs4 = NULL;
  const mxArray *c10_lhs4 = NULL;
  const mxArray *c10_rhs5 = NULL;
  const mxArray *c10_lhs5 = NULL;
  const mxArray *c10_rhs6 = NULL;
  const mxArray *c10_lhs6 = NULL;
  const mxArray *c10_rhs7 = NULL;
  const mxArray *c10_lhs7 = NULL;
  const mxArray *c10_rhs8 = NULL;
  const mxArray *c10_lhs8 = NULL;
  const mxArray *c10_rhs9 = NULL;
  const mxArray *c10_lhs9 = NULL;
  const mxArray *c10_rhs10 = NULL;
  const mxArray *c10_lhs10 = NULL;
  const mxArray *c10_rhs11 = NULL;
  const mxArray *c10_lhs11 = NULL;
  const mxArray *c10_rhs12 = NULL;
  const mxArray *c10_lhs12 = NULL;
  const mxArray *c10_rhs13 = NULL;
  const mxArray *c10_lhs13 = NULL;
  const mxArray *c10_rhs14 = NULL;
  const mxArray *c10_lhs14 = NULL;
  const mxArray *c10_rhs15 = NULL;
  const mxArray *c10_lhs15 = NULL;
  const mxArray *c10_rhs16 = NULL;
  const mxArray *c10_lhs16 = NULL;
  const mxArray *c10_rhs17 = NULL;
  const mxArray *c10_lhs17 = NULL;
  const mxArray *c10_rhs18 = NULL;
  const mxArray *c10_lhs18 = NULL;
  const mxArray *c10_rhs19 = NULL;
  const mxArray *c10_lhs19 = NULL;
  const mxArray *c10_rhs20 = NULL;
  const mxArray *c10_lhs20 = NULL;
  const mxArray *c10_rhs21 = NULL;
  const mxArray *c10_lhs21 = NULL;
  const mxArray *c10_rhs22 = NULL;
  const mxArray *c10_lhs22 = NULL;
  const mxArray *c10_rhs23 = NULL;
  const mxArray *c10_lhs23 = NULL;
  const mxArray *c10_rhs24 = NULL;
  const mxArray *c10_lhs24 = NULL;
  const mxArray *c10_rhs25 = NULL;
  const mxArray *c10_lhs25 = NULL;
  const mxArray *c10_rhs26 = NULL;
  const mxArray *c10_lhs26 = NULL;
  const mxArray *c10_rhs27 = NULL;
  const mxArray *c10_lhs27 = NULL;
  const mxArray *c10_rhs28 = NULL;
  const mxArray *c10_lhs28 = NULL;
  const mxArray *c10_rhs29 = NULL;
  const mxArray *c10_lhs29 = NULL;
  const mxArray *c10_rhs30 = NULL;
  const mxArray *c10_lhs30 = NULL;
  const mxArray *c10_rhs31 = NULL;
  const mxArray *c10_lhs31 = NULL;
  const mxArray *c10_rhs32 = NULL;
  const mxArray *c10_lhs32 = NULL;
  const mxArray *c10_rhs33 = NULL;
  const mxArray *c10_lhs33 = NULL;
  const mxArray *c10_rhs34 = NULL;
  const mxArray *c10_lhs34 = NULL;
  const mxArray *c10_rhs35 = NULL;
  const mxArray *c10_lhs35 = NULL;
  const mxArray *c10_rhs36 = NULL;
  const mxArray *c10_lhs36 = NULL;
  const mxArray *c10_rhs37 = NULL;
  const mxArray *c10_lhs37 = NULL;
  const mxArray *c10_rhs38 = NULL;
  const mxArray *c10_lhs38 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510384U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c10_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfi"), "name", "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c10_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c10_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfi"), "name", "name", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c10_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c10_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("get"), "name", "name", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c10_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/mtimes.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("times"), "name", "name", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510386U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c10_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c10_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfi"), "name", "name", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c10_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfi"), "name", "name", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c10_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isscaledtype"), "name",
                  "name", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510380U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c10_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfixed"), "name", "name",
                  11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510378U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c10_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isfixed.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("get"), "name", "name", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c10_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("get"), "name", "name", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fimath"),
                  "dominantType", "dominantType", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c10_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("strcmpi"), "name", "name",
                  14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c10_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c10_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c10_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("intmax"), "name", "name", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c10_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c10_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("min"), "name", "name", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c10_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c10_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c10_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c10_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c10_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c10_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c10_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c10_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c10_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("get"), "name", "name", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c10_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_fixpt_times"), "name",
                  "name", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_fixpt_times.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1289519646U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c10_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("plus"), "name", "name", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510384U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c10_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c10_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfi"), "name", "name", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c10_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isfi"), "name", "name", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c10_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isscaledtype"), "name",
                  "name", 34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/isscaledtype.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510380U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c10_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("get"), "name", "name", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fimath"),
                  "dominantType", "dominantType", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fimath/get.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c10_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("strcmpi"), "name", "name",
                  36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strcmpi.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1327419110U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c10_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/plus.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("get"), "name", "name", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.numerictype"),
                  "dominantType", "dominantType", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@numerictype/get.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1378295982U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c10_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/times.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_checkfimathforbinaryops"),
                  "name", "name", 38);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("embedded.fi"),
                  "dominantType", "dominantType", 38);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/eml_checkfimathforbinaryops.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1346510368U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c10_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
  sf_mex_destroy(&c10_rhs1);
  sf_mex_destroy(&c10_lhs1);
  sf_mex_destroy(&c10_rhs2);
  sf_mex_destroy(&c10_lhs2);
  sf_mex_destroy(&c10_rhs3);
  sf_mex_destroy(&c10_lhs3);
  sf_mex_destroy(&c10_rhs4);
  sf_mex_destroy(&c10_lhs4);
  sf_mex_destroy(&c10_rhs5);
  sf_mex_destroy(&c10_lhs5);
  sf_mex_destroy(&c10_rhs6);
  sf_mex_destroy(&c10_lhs6);
  sf_mex_destroy(&c10_rhs7);
  sf_mex_destroy(&c10_lhs7);
  sf_mex_destroy(&c10_rhs8);
  sf_mex_destroy(&c10_lhs8);
  sf_mex_destroy(&c10_rhs9);
  sf_mex_destroy(&c10_lhs9);
  sf_mex_destroy(&c10_rhs10);
  sf_mex_destroy(&c10_lhs10);
  sf_mex_destroy(&c10_rhs11);
  sf_mex_destroy(&c10_lhs11);
  sf_mex_destroy(&c10_rhs12);
  sf_mex_destroy(&c10_lhs12);
  sf_mex_destroy(&c10_rhs13);
  sf_mex_destroy(&c10_lhs13);
  sf_mex_destroy(&c10_rhs14);
  sf_mex_destroy(&c10_lhs14);
  sf_mex_destroy(&c10_rhs15);
  sf_mex_destroy(&c10_lhs15);
  sf_mex_destroy(&c10_rhs16);
  sf_mex_destroy(&c10_lhs16);
  sf_mex_destroy(&c10_rhs17);
  sf_mex_destroy(&c10_lhs17);
  sf_mex_destroy(&c10_rhs18);
  sf_mex_destroy(&c10_lhs18);
  sf_mex_destroy(&c10_rhs19);
  sf_mex_destroy(&c10_lhs19);
  sf_mex_destroy(&c10_rhs20);
  sf_mex_destroy(&c10_lhs20);
  sf_mex_destroy(&c10_rhs21);
  sf_mex_destroy(&c10_lhs21);
  sf_mex_destroy(&c10_rhs22);
  sf_mex_destroy(&c10_lhs22);
  sf_mex_destroy(&c10_rhs23);
  sf_mex_destroy(&c10_lhs23);
  sf_mex_destroy(&c10_rhs24);
  sf_mex_destroy(&c10_lhs24);
  sf_mex_destroy(&c10_rhs25);
  sf_mex_destroy(&c10_lhs25);
  sf_mex_destroy(&c10_rhs26);
  sf_mex_destroy(&c10_lhs26);
  sf_mex_destroy(&c10_rhs27);
  sf_mex_destroy(&c10_lhs27);
  sf_mex_destroy(&c10_rhs28);
  sf_mex_destroy(&c10_lhs28);
  sf_mex_destroy(&c10_rhs29);
  sf_mex_destroy(&c10_lhs29);
  sf_mex_destroy(&c10_rhs30);
  sf_mex_destroy(&c10_lhs30);
  sf_mex_destroy(&c10_rhs31);
  sf_mex_destroy(&c10_lhs31);
  sf_mex_destroy(&c10_rhs32);
  sf_mex_destroy(&c10_lhs32);
  sf_mex_destroy(&c10_rhs33);
  sf_mex_destroy(&c10_lhs33);
  sf_mex_destroy(&c10_rhs34);
  sf_mex_destroy(&c10_lhs34);
  sf_mex_destroy(&c10_rhs35);
  sf_mex_destroy(&c10_lhs35);
  sf_mex_destroy(&c10_rhs36);
  sf_mex_destroy(&c10_lhs36);
  sf_mex_destroy(&c10_rhs37);
  sf_mex_destroy(&c10_lhs37);
  sf_mex_destroy(&c10_rhs38);
  sf_mex_destroy(&c10_lhs38);
}

static const mxArray *c10_emlrt_marshallOut(const char * c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c10_u)), false);
  return c10_y;
}

static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), false);
  return c10_y;
}

static void c10_strcmpi(SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
}

static void c10_eml_scalar_eg(SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static cint16_T c10_mtimes(SFc10_Basic_DMTInstanceStruct *chartInstance, int16_T
  c10_b0)
{
  cint16_T c10_cout;
  int16_T c10_cr;
  int16_T c10_ci;
  (void)c10_b0;
  c10_strcmpi(chartInstance);
  c10_b_strcmpi(chartInstance);
  c10_cr = 0;
  c10_ci = 0;
  c10_cout.re = c10_cr;
  c10_cout.im = c10_ci;
  return c10_cout;
}

static void c10_b_strcmpi(SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
}

static cint16_T c10_plus(SFc10_Basic_DMTInstanceStruct *chartInstance, real_T
  c10_a0, cint16_T c10_b0)
{
  cint16_T c10_c;
  real_T c10_u;
  real_T c10_v;
  real_T c10_d1;
  int16_T c10_i0;
  int16_T c10_a;
  int32_T c10_b_i1;
  c10_strcmpi(chartInstance);
  c10_u = c10_a0 * 8.0;
  c10_v = muDoubleScalarAbs(c10_u);
  if (c10_v < 4.503599627370496E+15) {
    if (c10_v >= 0.5) {
      c10_d1 = muDoubleScalarFloor(c10_u + 0.5);
    } else {
      c10_d1 = c10_u * 0.0;
    }
  } else {
    c10_d1 = c10_u;
  }

  if (c10_d1 < 256.0) {
    if (c10_d1 >= -256.0) {
      c10_i0 = (int16_T)c10_d1;
    } else {
      c10_i0 = -256;
    }
  } else if (c10_d1 >= 256.0) {
    c10_i0 = 255;
  } else {
    c10_i0 = 0;
  }

  c10_a = c10_i0;
  c10_b_strcmpi(chartInstance);
  c10_b_i1 = c10_a + c10_b0.re;
  if (c10_b_i1 > 255) {
    c10_b_i1 = 255;
  } else {
    if (c10_b_i1 < -256) {
      c10_b_i1 = -256;
    }
  }

  c10_c.re = (int16_T)c10_b_i1;
  c10_c.im = c10_b0.im;
  return c10_c;
}

static cint16_T c10_b_mtimes(SFc10_Basic_DMTInstanceStruct *chartInstance,
  cint16_T c10_a0, int16_T c10_b0)
{
  cint16_T c10_cout;
  int16_T c10_b_b0;
  int16_T c10_b;
  int16_T c10_b_b;
  int16_T c10_ar;
  int16_T c10_ai;
  int32_T c10_b_i2;
  int32_T c10_b_i3;
  int16_T c10_cr;
  int32_T c10_b_i4;
  int32_T c10_b_i5;
  int16_T c10_ci;
  const mxArray *c10_errID = NULL;
  const mxArray *c10_a2SD = NULL;
  const mxArray *c10_b2SD = NULL;
  const mxArray *c10_Tsd = NULL;
  c10_b_b0 = c10_b0;
  c10_b = c10_b_b0;
  c10_b_strcmpi(chartInstance);
  c10_b_b = c10_b;
  c10_ar = c10_a0.re;
  c10_ai = c10_a0.im;
  c10_b_i2 = c10_ar * c10_b_b;
  c10_b_i3 = (c10_b_i2 >> 3) + ((c10_b_i2 & 4) != 0);
  if (c10_b_i3 > 255) {
    c10_b_i3 = 255;
  } else {
    if (c10_b_i3 < -256) {
      c10_b_i3 = -256;
    }
  }

  c10_cr = (int16_T)c10_b_i3;
  c10_b_i4 = c10_ai * c10_b_b;
  c10_b_i5 = (c10_b_i4 >> 3) + ((c10_b_i4 & 4) != 0);
  if (c10_b_i5 > 255) {
    c10_b_i5 = 255;
  } else {
    if (c10_b_i5 < -256) {
      c10_b_i5 = -256;
    }
  }

  c10_ci = (int16_T)c10_b_i5;
  c10_cout.re = c10_cr;
  c10_cout.im = c10_ci;
  sf_mex_destroy(&c10_errID);
  sf_mex_destroy(&c10_a2SD);
  sf_mex_destroy(&c10_b2SD);
  sf_mex_destroy(&c10_Tsd);
  return c10_cout;
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_d_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_b_i6;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_b_i6, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_b_i6;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData;
  cint16_T c10_u;
  const mxArray *c10_y = NULL;
  cint16_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_mxArrayOutData = NULL;
  c10_u = *(cint16_T *)c10_inData;
  c10_y = NULL;
  c10_b_u.re = c10_u.re;
  c10_b_u.im = c10_u.im;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 4, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx), 15,
    "simulinkarray", 14, c10_b_y, 15, "fimathislocal", 3, true), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static cint16_T c10_e_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_b_out, const char_T *c10_identifier)
{
  cint16_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_out),
    &c10_thisId);
  sf_mex_destroy(&c10_b_out);
  return c10_y;
}

static cint16_T c10_f_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  cint16_T c10_y;
  const mxArray *c10_mxFi = NULL;
  const mxArray *c10_mxInt = NULL;
  cint16_T c10_ic2;
  (void)chartInstance;
  sf_mex_check_fi(c10_parentId, c10_u, true, 0U, NULL, c10_eml_mx, c10_b_eml_mx);
  sf_mex_assign(&c10_mxFi, sf_mex_dup(c10_u), false);
  sf_mex_assign(&c10_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c10_mxFi)), false);
  sf_mex_import(c10_parentId, sf_mex_dup(c10_mxInt), &c10_ic2, 1, 4, 1U, 0, 0U,
                0);
  sf_mex_destroy(&c10_mxFi);
  sf_mex_destroy(&c10_mxInt);
  c10_y = c10_ic2;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_out;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  cint16_T c10_y;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_b_out = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_out),
    &c10_thisId);
  sf_mex_destroy(&c10_b_out);
  *(cint16_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData;
  int16_T c10_u;
  const mxArray *c10_y = NULL;
  int16_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c10_u = *(int16_T *)c10_inData;
    c10_y = NULL;
    c10_b_u = c10_u;
    c10_b_y = NULL;
    sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 4, 0U, 0U, 0U, 0),
                  false);
    sf_mex_assign(&c10_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
                   (c10_eml_mx), 15, "numerictype", 14, sf_mex_dup(c10_b_eml_mx),
      15, "simulinkarray", 14, c10_b_y, 15, "fimathislocal", 3, false), false);
    sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  } else {
    sf_mex_assign(&c10_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c10_mxArrayOutData;
}

static int16_T c10_g_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int16_T c10_y;
  const mxArray *c10_mxFi = NULL;
  const mxArray *c10_mxInt = NULL;
  int16_T c10_b_i7;
  (void)chartInstance;
  sf_mex_check_fi(c10_parentId, c10_u, false, 0U, NULL, c10_eml_mx, c10_b_eml_mx);
  sf_mex_assign(&c10_mxFi, sf_mex_dup(c10_u), false);
  sf_mex_assign(&c10_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c10_mxFi)), false);
  sf_mex_import(c10_parentId, sf_mex_dup(c10_mxInt), &c10_b_i7, 1, 4, 0U, 0, 0U,
                0);
  sf_mex_destroy(&c10_mxFi);
  sf_mex_destroy(&c10_mxInt);
  c10_y = c10_b_i7;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_convert;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int16_T c10_y;
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)chartInstanceVoid;
  if (sf_debug_check_fi_license()) {
    c10_convert = sf_mex_dup(c10_mxArrayInData);
    c10_identifier = c10_varName;
    c10_thisId.fIdentifier = c10_identifier;
    c10_thisId.fParent = NULL;
    c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_convert),
      &c10_thisId);
    sf_mex_destroy(&c10_convert);
    *(int16_T *)c10_outData = c10_y;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_h_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_Basic_DMT, const char_T
  *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_Basic_DMT), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_Basic_DMT);
  return c10_y;
}

static uint8_T c10_i_emlrt_marshallIn(SFc10_Basic_DMTInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static int16_T c10_get_convert(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c10_elementIndex);
  return *chartInstance->c10_convert_address;
}

static void c10_set_convert(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_elementIndex, int16_T c10_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c10_elementIndex);
  *chartInstance->c10_convert_address = c10_elementValue;
}

static int16_T *c10_access_convert(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_rdOnly)
{
  int16_T *c10_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c10_dsmAddr = chartInstance->c10_convert_address;
  if (c10_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c10_dsmAddr;
}

static real_T c10_get_state(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c10_elementIndex);
  return *chartInstance->c10_state_address;
}

static void c10_set_state(SFc10_Basic_DMTInstanceStruct *chartInstance, uint32_T
  c10_elementIndex, real_T c10_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c10_elementIndex);
  *chartInstance->c10_state_address = c10_elementValue;
}

static real_T *c10_access_state(SFc10_Basic_DMTInstanceStruct *chartInstance,
  uint32_T c10_rdOnly)
{
  real_T *c10_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c10_dsmAddr = chartInstance->c10_state_address;
  if (c10_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c10_dsmAddr;
}

static void init_dsm_address_info(SFc10_Basic_DMTInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "convert", (void **)
    &chartInstance->c10_convert_address, &chartInstance->c10_convert_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "state", (void **)
    &chartInstance->c10_state_address, &chartInstance->c10_state_index);
}

static void init_simulink_io_address(SFc10_Basic_DMTInstanceStruct
  *chartInstance)
{
  chartInstance->c10_inp = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c10_i1 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c10_out = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c10_o1 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c10_o2 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c10_o3 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c10_o4 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c10_o5 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c10_o6 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c10_o7 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c10_o8 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c10_o9 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c10_o10 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c10_o11 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c10_o12 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c10_o13 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c10_o14 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c10_o15 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c10_o16 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 17);
  chartInstance->c10_o17 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 18);
  chartInstance->c10_o18 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 19);
  chartInstance->c10_o19 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 20);
  chartInstance->c10_o20 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 21);
  chartInstance->c10_o21 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 22);
  chartInstance->c10_o22 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 23);
  chartInstance->c10_o23 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 24);
  chartInstance->c10_o24 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 25);
  chartInstance->c10_o25 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 26);
  chartInstance->c10_o26 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 27);
  chartInstance->c10_o27 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 28);
  chartInstance->c10_o28 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 29);
  chartInstance->c10_o29 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 30);
  chartInstance->c10_o30 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 31);
  chartInstance->c10_o31 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 32);
  chartInstance->c10_o32 = (cint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 33);
  chartInstance->c10_pop = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 34);
  chartInstance->c10_i2 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c10_i3 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c10_i4 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c10_i5 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c10_i6 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c10_i7 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c10_i8 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c10_i9 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c10_i10 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c10_i11 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c10_i12 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c10_i13 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c10_i14 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c10_i15 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c10_i16 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c10_i17 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 17);
  chartInstance->c10_i18 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 18);
  chartInstance->c10_i19 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 19);
  chartInstance->c10_i20 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 20);
  chartInstance->c10_i21 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 21);
  chartInstance->c10_i22 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 22);
  chartInstance->c10_i23 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 23);
  chartInstance->c10_i24 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 24);
  chartInstance->c10_i25 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 25);
  chartInstance->c10_i26 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 26);
  chartInstance->c10_i27 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 27);
  chartInstance->c10_i28 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 28);
  chartInstance->c10_i29 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 29);
  chartInstance->c10_i30 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 30);
  chartInstance->c10_i31 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 31);
  chartInstance->c10_i32 = (cint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 32);
  chartInstance->c10_frameEN = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 33);
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

void sf_c10_Basic_DMT_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1771044116U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1960174994U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3655313251U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3562321180U);
}

mxArray* sf_c10_Basic_DMT_get_post_codegen_info(void);
mxArray *sf_c10_Basic_DMT_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GvH7NdF04G6EcnZRlABHnC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,34,3,dataFields);

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

      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,21,"size",mxSize);
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

      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,22,"size",mxSize);
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

      mxSetField(mxData,22,"type",mxType);
    }

    mxSetField(mxData,22,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,23,"size",mxSize);
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

      mxSetField(mxData,23,"type",mxType);
    }

    mxSetField(mxData,23,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,24,"size",mxSize);
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

      mxSetField(mxData,24,"type",mxType);
    }

    mxSetField(mxData,24,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,25,"size",mxSize);
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

      mxSetField(mxData,25,"type",mxType);
    }

    mxSetField(mxData,25,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,26,"size",mxSize);
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

      mxSetField(mxData,26,"type",mxType);
    }

    mxSetField(mxData,26,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,27,"size",mxSize);
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

      mxSetField(mxData,27,"type",mxType);
    }

    mxSetField(mxData,27,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,28,"size",mxSize);
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

      mxSetField(mxData,28,"type",mxType);
    }

    mxSetField(mxData,28,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,29,"size",mxSize);
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

      mxSetField(mxData,29,"type",mxType);
    }

    mxSetField(mxData,29,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,30,"size",mxSize);
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

      mxSetField(mxData,30,"type",mxType);
    }

    mxSetField(mxData,30,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,31,"size",mxSize);
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

      mxSetField(mxData,31,"type",mxType);
    }

    mxSetField(mxData,31,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,32,"size",mxSize);
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

      mxSetField(mxData,32,"type",mxType);
    }

    mxSetField(mxData,32,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,33,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,33,"type",mxType);
    }

    mxSetField(mxData,33,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,34,3,dataFields);

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

      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(1));

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

      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,21,"size",mxSize);
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

      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,22,"size",mxSize);
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

      mxSetField(mxData,22,"type",mxType);
    }

    mxSetField(mxData,22,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,23,"size",mxSize);
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

      mxSetField(mxData,23,"type",mxType);
    }

    mxSetField(mxData,23,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,24,"size",mxSize);
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

      mxSetField(mxData,24,"type",mxType);
    }

    mxSetField(mxData,24,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,25,"size",mxSize);
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

      mxSetField(mxData,25,"type",mxType);
    }

    mxSetField(mxData,25,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,26,"size",mxSize);
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

      mxSetField(mxData,26,"type",mxType);
    }

    mxSetField(mxData,26,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,27,"size",mxSize);
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

      mxSetField(mxData,27,"type",mxType);
    }

    mxSetField(mxData,27,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,28,"size",mxSize);
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

      mxSetField(mxData,28,"type",mxType);
    }

    mxSetField(mxData,28,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,29,"size",mxSize);
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

      mxSetField(mxData,29,"type",mxType);
    }

    mxSetField(mxData,29,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,30,"size",mxSize);
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

      mxSetField(mxData,30,"type",mxType);
    }

    mxSetField(mxData,30,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,31,"size",mxSize);
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

      mxSetField(mxData,31,"type",mxType);
    }

    mxSetField(mxData,31,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,32,"size",mxSize);
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

      mxSetField(mxData,32,"type",mxType);
    }

    mxSetField(mxData,32,"complexity",mxCreateDoubleScalar(1));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,33,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,33,"type",mxType);
    }

    mxSetField(mxData,33,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c10_Basic_DMT_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_Basic_DMT_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_Basic_DMT_jit_fallback_info(void)
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

mxArray *sf_c10_Basic_DMT_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c10_Basic_DMT_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c10_Basic_DMT(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[10],T\"o1\",},{M[1],M[36],T\"o10\",},{M[1],M[37],T\"o11\",},{M[1],M[38],T\"o12\",},{M[1],M[39],T\"o13\",},{M[1],M[40],T\"o14\",},{M[1],M[41],T\"o15\",},{M[1],M[42],T\"o16\",},{M[1],M[61],T\"o17\",},{M[1],M[62],T\"o18\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[63],T\"o19\",},{M[1],M[28],T\"o2\",},{M[1],M[64],T\"o20\",},{M[1],M[65],T\"o21\",},{M[1],M[66],T\"o22\",},{M[1],M[67],T\"o23\",},{M[1],M[68],T\"o24\",},{M[1],M[69],T\"o25\",},{M[1],M[70],T\"o26\",},{M[1],M[71],T\"o27\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[72],T\"o28\",},{M[1],M[73],T\"o29\",},{M[1],M[29],T\"o3\",},{M[1],M[74],T\"o30\",},{M[1],M[75],T\"o31\",},{M[1],M[76],T\"o32\",},{M[1],M[30],T\"o4\",},{M[1],M[31],T\"o5\",},{M[1],M[32],T\"o6\",},{M[1],M[33],T\"o7\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[34],T\"o8\",},{M[1],M[35],T\"o9\",},{M[1],M[5],T\"out\",},{M[1],M[6],T\"pop\",},{M[8],M[0],T\"is_active_c10_Basic_DMT\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 35, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_Basic_DMT_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_Basic_DMTInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_Basic_DMTInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Basic_DMTMachineNumber_,
           10,
           1,
           1,
           0,
           70,
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
          _SFD_SET_DATA_PROPS(19,2,0,1,"o17");
          _SFD_SET_DATA_PROPS(20,2,0,1,"o18");
          _SFD_SET_DATA_PROPS(21,2,0,1,"o19");
          _SFD_SET_DATA_PROPS(22,2,0,1,"o20");
          _SFD_SET_DATA_PROPS(23,2,0,1,"o21");
          _SFD_SET_DATA_PROPS(24,2,0,1,"o22");
          _SFD_SET_DATA_PROPS(25,2,0,1,"o23");
          _SFD_SET_DATA_PROPS(26,2,0,1,"o24");
          _SFD_SET_DATA_PROPS(27,2,0,1,"o25");
          _SFD_SET_DATA_PROPS(28,2,0,1,"o26");
          _SFD_SET_DATA_PROPS(29,2,0,1,"o27");
          _SFD_SET_DATA_PROPS(30,2,0,1,"o28");
          _SFD_SET_DATA_PROPS(31,2,0,1,"o29");
          _SFD_SET_DATA_PROPS(32,2,0,1,"o30");
          _SFD_SET_DATA_PROPS(33,2,0,1,"o31");
          _SFD_SET_DATA_PROPS(34,2,0,1,"o32");
          _SFD_SET_DATA_PROPS(35,2,0,1,"pop");
          _SFD_SET_DATA_PROPS(36,11,0,0,"state");
          _SFD_SET_DATA_PROPS(37,11,0,0,"convert");
          _SFD_SET_DATA_PROPS(38,1,1,0,"i2");
          _SFD_SET_DATA_PROPS(39,1,1,0,"i3");
          _SFD_SET_DATA_PROPS(40,1,1,0,"i4");
          _SFD_SET_DATA_PROPS(41,1,1,0,"i5");
          _SFD_SET_DATA_PROPS(42,1,1,0,"i6");
          _SFD_SET_DATA_PROPS(43,1,1,0,"i7");
          _SFD_SET_DATA_PROPS(44,1,1,0,"i8");
          _SFD_SET_DATA_PROPS(45,1,1,0,"i9");
          _SFD_SET_DATA_PROPS(46,1,1,0,"i10");
          _SFD_SET_DATA_PROPS(47,1,1,0,"i11");
          _SFD_SET_DATA_PROPS(48,1,1,0,"i12");
          _SFD_SET_DATA_PROPS(49,1,1,0,"i13");
          _SFD_SET_DATA_PROPS(50,1,1,0,"i14");
          _SFD_SET_DATA_PROPS(51,1,1,0,"i15");
          _SFD_SET_DATA_PROPS(52,1,1,0,"i16");
          _SFD_SET_DATA_PROPS(53,1,1,0,"i17");
          _SFD_SET_DATA_PROPS(54,1,1,0,"i18");
          _SFD_SET_DATA_PROPS(55,1,1,0,"i19");
          _SFD_SET_DATA_PROPS(56,1,1,0,"i20");
          _SFD_SET_DATA_PROPS(57,1,1,0,"i21");
          _SFD_SET_DATA_PROPS(58,1,1,0,"i22");
          _SFD_SET_DATA_PROPS(59,1,1,0,"i23");
          _SFD_SET_DATA_PROPS(60,1,1,0,"i24");
          _SFD_SET_DATA_PROPS(61,1,1,0,"i25");
          _SFD_SET_DATA_PROPS(62,1,1,0,"i26");
          _SFD_SET_DATA_PROPS(63,1,1,0,"i27");
          _SFD_SET_DATA_PROPS(64,1,1,0,"i28");
          _SFD_SET_DATA_PROPS(65,1,1,0,"i29");
          _SFD_SET_DATA_PROPS(66,1,1,0,"i30");
          _SFD_SET_DATA_PROPS(67,1,1,0,"i31");
          _SFD_SET_DATA_PROPS(68,1,1,0,"i32");
          _SFD_SET_DATA_PROPS(69,1,1,0,"frameEN");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,5115);
        _SFD_CV_INIT_EML_IF(0,1,0,859,869,938,987);

        {
          static int caseStart[] = { -1, 837, 1001, 1058, 1102, 1146, 1190, 1234,
            1278, 1322, 1366, 1411, 1458, 1505, 1552, 1599, 1646, 1693, 1740,
            1794, 1841, 1888, 1935, 1982, 2029, 2076, 2123, 2246, 2333, 2420,
            2507, 2594, 2681, 2768, 2858, 2939, 3008, 3077, 3146, 3227, 3296,
            3365, 3434, 3503, 3573, 3643, 3713, 3783, 3853, 3923, 3993, 4063,
            4133, 4203, 4273, 4343, 4413, 4483, 4553, 4623, 4693, 4763, 4833,
            4903, 4973, 5043 };

          static int caseExprEnd[] = { 8, 843, 1007, 1064, 1108, 1152, 1196,
            1240, 1284, 1328, 1372, 1418, 1465, 1512, 1559, 1606, 1653, 1700,
            1747, 1801, 1848, 1895, 1942, 1989, 2036, 2083, 2130, 2253, 2340,
            2427, 2514, 2601, 2688, 2775, 2865, 2946, 3015, 3084, 3153, 3234,
            3303, 3372, 3441, 3510, 3580, 3650, 3720, 3790, 3860, 3930, 4000,
            4070, 4140, 4210, 4280, 4350, 4420, 4490, 4560, 4630, 4700, 4770,
            4840, 4910, 4980, 5050 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,820,833,5111,66,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
          c10_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_INT16,0,NULL,1,1,9,0,1,-3,0,
          (MexFcnForType)c10_e_sf_marshallOut,(MexInFcnForType)
          c10_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(53,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(57,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(58,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(60,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(61,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(62,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(63,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(64,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(65,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(66,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(67,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(68,SF_INT16,0,NULL,1,1,9,0,1,-3,1,
          (MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(69,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c10_inp);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c10_i1);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c10_out);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c10_o1);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c10_o2);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c10_o3);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c10_o4);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c10_o5);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c10_o6);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c10_o7);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c10_o8);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c10_o9);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c10_o10);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c10_o11);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c10_o12);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c10_o13);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c10_o14);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c10_o15);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c10_o16);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c10_o17);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c10_o18);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c10_o19);
        _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c10_o20);
        _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c10_o21);
        _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c10_o22);
        _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c10_o23);
        _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c10_o24);
        _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c10_o25);
        _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c10_o26);
        _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c10_o27);
        _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c10_o28);
        _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c10_o29);
        _SFD_SET_DATA_VALUE_PTR(32U, chartInstance->c10_o30);
        _SFD_SET_DATA_VALUE_PTR(33U, chartInstance->c10_o31);
        _SFD_SET_DATA_VALUE_PTR(34U, chartInstance->c10_o32);
        _SFD_SET_DATA_VALUE_PTR(35U, chartInstance->c10_pop);
        _SFD_SET_DATA_VALUE_PTR(36U, chartInstance->c10_state_address);
        _SFD_SET_DATA_VALUE_PTR(37U, chartInstance->c10_convert_address);
        _SFD_SET_DATA_VALUE_PTR(38U, chartInstance->c10_i2);
        _SFD_SET_DATA_VALUE_PTR(39U, chartInstance->c10_i3);
        _SFD_SET_DATA_VALUE_PTR(40U, chartInstance->c10_i4);
        _SFD_SET_DATA_VALUE_PTR(41U, chartInstance->c10_i5);
        _SFD_SET_DATA_VALUE_PTR(42U, chartInstance->c10_i6);
        _SFD_SET_DATA_VALUE_PTR(43U, chartInstance->c10_i7);
        _SFD_SET_DATA_VALUE_PTR(44U, chartInstance->c10_i8);
        _SFD_SET_DATA_VALUE_PTR(45U, chartInstance->c10_i9);
        _SFD_SET_DATA_VALUE_PTR(46U, chartInstance->c10_i10);
        _SFD_SET_DATA_VALUE_PTR(47U, chartInstance->c10_i11);
        _SFD_SET_DATA_VALUE_PTR(48U, chartInstance->c10_i12);
        _SFD_SET_DATA_VALUE_PTR(49U, chartInstance->c10_i13);
        _SFD_SET_DATA_VALUE_PTR(50U, chartInstance->c10_i14);
        _SFD_SET_DATA_VALUE_PTR(51U, chartInstance->c10_i15);
        _SFD_SET_DATA_VALUE_PTR(52U, chartInstance->c10_i16);
        _SFD_SET_DATA_VALUE_PTR(53U, chartInstance->c10_i17);
        _SFD_SET_DATA_VALUE_PTR(54U, chartInstance->c10_i18);
        _SFD_SET_DATA_VALUE_PTR(55U, chartInstance->c10_i19);
        _SFD_SET_DATA_VALUE_PTR(56U, chartInstance->c10_i20);
        _SFD_SET_DATA_VALUE_PTR(57U, chartInstance->c10_i21);
        _SFD_SET_DATA_VALUE_PTR(58U, chartInstance->c10_i22);
        _SFD_SET_DATA_VALUE_PTR(59U, chartInstance->c10_i23);
        _SFD_SET_DATA_VALUE_PTR(60U, chartInstance->c10_i24);
        _SFD_SET_DATA_VALUE_PTR(61U, chartInstance->c10_i25);
        _SFD_SET_DATA_VALUE_PTR(62U, chartInstance->c10_i26);
        _SFD_SET_DATA_VALUE_PTR(63U, chartInstance->c10_i27);
        _SFD_SET_DATA_VALUE_PTR(64U, chartInstance->c10_i28);
        _SFD_SET_DATA_VALUE_PTR(65U, chartInstance->c10_i29);
        _SFD_SET_DATA_VALUE_PTR(66U, chartInstance->c10_i30);
        _SFD_SET_DATA_VALUE_PTR(67U, chartInstance->c10_i31);
        _SFD_SET_DATA_VALUE_PTR(68U, chartInstance->c10_i32);
        _SFD_SET_DATA_VALUE_PTR(69U, chartInstance->c10_frameEN);
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
  return "UEQGMbl6DXViF1w9uaGplH";
}

static void sf_opaque_initialize_c10_Basic_DMT(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_Basic_DMTInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*)
    chartInstanceVar);
  initialize_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_Basic_DMT(void *chartInstanceVar)
{
  enable_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_Basic_DMT(void *chartInstanceVar)
{
  disable_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_Basic_DMT(void *chartInstanceVar)
{
  sf_gateway_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c10_Basic_DMT(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_Basic_DMT(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c10_Basic_DMT(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_Basic_DMTInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Basic_DMT_optimization_info();
    }

    finalize_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_Basic_DMT(SimStruct *S)
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
    initialize_params_c10_Basic_DMT((SFc10_Basic_DMTInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Basic_DMT_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
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
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 20, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 21, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 22, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 23, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 24, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 25, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 26, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 27, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 28, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 29, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 30, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 31, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 32, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 33, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,34);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,34);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=34; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 34; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2350232073U));
  ssSetChecksum1(S,(1775576207U));
  ssSetChecksum2(S,(683820810U));
  ssSetChecksum3(S,(1100760488U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c10_Basic_DMT(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_Basic_DMT(SimStruct *S)
{
  SFc10_Basic_DMTInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_Basic_DMTInstanceStruct *)utMalloc(sizeof
    (SFc10_Basic_DMTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_Basic_DMTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c10_Basic_DMT;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c10_Basic_DMT;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c10_Basic_DMT;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_Basic_DMT;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_Basic_DMT;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c10_Basic_DMT;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c10_Basic_DMT;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c10_Basic_DMT;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_Basic_DMT;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_Basic_DMT;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c10_Basic_DMT;
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

void c10_Basic_DMT_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_Basic_DMT(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_Basic_DMT(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_Basic_DMT(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_Basic_DMT_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
