// Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2014.4 (win64) Build 1071353 Tue Nov 18 18:29:27 MST 2014
// Date        : Mon May 30 12:12:12 2016
// Host        : UML-02 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               D:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_0_stub.v
// Design      : basic_dmt_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "basic_dmt,Vivado 2014.4" *)
module basic_dmt_0(inp_recv_im, inp_recv_re, inp_trans, clk, diffsig, out_recv, out_trans_im, out_trans_re)
/* synthesis syn_black_box black_box_pad_pin="inp_recv_im[8:0],inp_recv_re[8:0],inp_trans[0:0],clk,diffsig[0:0],out_recv[0:0],out_trans_im[8:0],out_trans_re[8:0]" */;
  input [8:0]inp_recv_im;
  input [8:0]inp_recv_re;
  input [0:0]inp_trans;
  input clk;
  output [0:0]diffsig;
  output [0:0]out_recv;
  output [8:0]out_trans_im;
  output [8:0]out_trans_re;
endmodule
