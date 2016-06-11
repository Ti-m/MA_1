--Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2014.4 (win64) Build 1071353 Tue Nov 18 18:29:27 MST 2014
--Date        : Mon Mar 21 13:57:13 2016
--Host        : UML-02 running 64-bit major release  (build 9200)
--Command     : generate_target basic_dmt_bd.bd
--Design      : basic_dmt_bd
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity basic_dmt_bd is
  port (
    clk : in STD_LOGIC;
    inp_recv_im : in STD_LOGIC_VECTOR ( 20 downto 0 );
    inp_recv_re : in STD_LOGIC_VECTOR ( 20 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 20 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 20 downto 0 )
  );
end basic_dmt_bd;

architecture STRUCTURE of basic_dmt_bd is
  component basic_dmt_bd_basic_dmt_1_0 is
  port (
    inp_recv_im : in STD_LOGIC_VECTOR ( 20 downto 0 );
    inp_recv_re : in STD_LOGIC_VECTOR ( 20 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    clk : in STD_LOGIC;
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 20 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 20 downto 0 )
  );
  end component basic_dmt_bd_basic_dmt_1_0;
  signal basic_dmt_1_out_recv : STD_LOGIC_VECTOR ( 0 to 0 );
  signal basic_dmt_1_out_trans_im : STD_LOGIC_VECTOR ( 20 downto 0 );
  signal basic_dmt_1_out_trans_re : STD_LOGIC_VECTOR ( 20 downto 0 );
  signal clk_1 : STD_LOGIC;
  signal inp_recv_im_1 : STD_LOGIC_VECTOR ( 20 downto 0 );
  signal inp_recv_re_1 : STD_LOGIC_VECTOR ( 20 downto 0 );
  signal inp_trans_1 : STD_LOGIC_VECTOR ( 0 to 0 );
begin
  clk_1 <= clk;
  inp_recv_im_1(20 downto 0) <= inp_recv_im(20 downto 0);
  inp_recv_re_1(20 downto 0) <= inp_recv_re(20 downto 0);
  inp_trans_1(0) <= inp_trans(0);
  out_recv(0) <= basic_dmt_1_out_recv(0);
  out_trans_im(20 downto 0) <= basic_dmt_1_out_trans_im(20 downto 0);
  out_trans_re(20 downto 0) <= basic_dmt_1_out_trans_re(20 downto 0);
basic_dmt_1: component basic_dmt_bd_basic_dmt_1_0
    port map (
      clk => clk_1,
      inp_recv_im(20 downto 0) => inp_recv_im_1(20 downto 0),
      inp_recv_re(20 downto 0) => inp_recv_re_1(20 downto 0),
      inp_trans(0) => inp_trans_1(0),
      out_recv(0) => basic_dmt_1_out_recv(0),
      out_trans_im(20 downto 0) => basic_dmt_1_out_trans_im(20 downto 0),
      out_trans_re(20 downto 0) => basic_dmt_1_out_trans_re(20 downto 0)
    );
end STRUCTURE;
