-- Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2014.4 (win64) Build 1071353 Tue Nov 18 18:29:27 MST 2014
-- Date        : Mon May 30 12:12:12 2016
-- Host        : UML-02 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               D:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_0_stub.vhdl
-- Design      : basic_dmt_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity basic_dmt_0 is
  Port ( 
    inp_recv_im : in STD_LOGIC_VECTOR ( 8 downto 0 );
    inp_recv_re : in STD_LOGIC_VECTOR ( 8 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    clk : in STD_LOGIC;
    diffsig : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 8 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 8 downto 0 )
  );

end basic_dmt_0;

architecture stub of basic_dmt_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "inp_recv_im[8:0],inp_recv_re[8:0],inp_trans[0:0],clk,diffsig[0:0],out_recv[0:0],out_trans_im[8:0],out_trans_re[8:0]";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "basic_dmt,Vivado 2014.4";
begin
end;
