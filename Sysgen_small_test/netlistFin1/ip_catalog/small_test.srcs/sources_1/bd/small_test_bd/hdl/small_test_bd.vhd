--Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2014.4 (win64) Build 1071353 Tue Nov 18 18:29:27 MST 2014
--Date        : Wed Mar 16 17:07:26 2016
--Host        : UML-02 running 64-bit major release  (build 9200)
--Command     : generate_target small_test_bd.bd
--Design      : small_test_bd
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity small_test_bd is
  port (
    clk : in STD_LOGIC;
    inp_recv_im1 : in STD_LOGIC_VECTOR ( 15 downto 0 );
    inp_recv_re1 : in STD_LOGIC_VECTOR ( 15 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 15 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 15 downto 0 );
    test_pin : out STD_LOGIC_VECTOR ( 0 to 0 )
  );
end small_test_bd;

architecture STRUCTURE of small_test_bd is
  component small_test_bd_small_test_1_0 is
  port (
    inp_recv_im1 : in STD_LOGIC_VECTOR ( 15 downto 0 );
    inp_recv_re1 : in STD_LOGIC_VECTOR ( 15 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    clk : in STD_LOGIC;
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 15 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 15 downto 0 );
    test_pin : out STD_LOGIC_VECTOR ( 0 to 0 )
  );
  end component small_test_bd_small_test_1_0;
  signal clk_1 : STD_LOGIC;
  signal inp_recv_im1_1 : STD_LOGIC_VECTOR ( 15 downto 0 );
  signal inp_recv_re1_1 : STD_LOGIC_VECTOR ( 15 downto 0 );
  signal inp_trans_1 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal small_test_1_out_recv : STD_LOGIC_VECTOR ( 0 to 0 );
  signal small_test_1_out_trans_im : STD_LOGIC_VECTOR ( 15 downto 0 );
  signal small_test_1_out_trans_re : STD_LOGIC_VECTOR ( 15 downto 0 );
  signal small_test_1_test_pin : STD_LOGIC_VECTOR ( 0 to 0 );
begin
  clk_1 <= clk;
  inp_recv_im1_1(15 downto 0) <= inp_recv_im1(15 downto 0);
  inp_recv_re1_1(15 downto 0) <= inp_recv_re1(15 downto 0);
  inp_trans_1(0) <= inp_trans(0);
  out_recv(0) <= small_test_1_out_recv(0);
  out_trans_im(15 downto 0) <= small_test_1_out_trans_im(15 downto 0);
  out_trans_re(15 downto 0) <= small_test_1_out_trans_re(15 downto 0);
  test_pin(0) <= small_test_1_test_pin(0);
small_test_1: component small_test_bd_small_test_1_0
    port map (
      clk => clk_1,
      inp_recv_im1(15 downto 0) => inp_recv_im1_1(15 downto 0),
      inp_recv_re1(15 downto 0) => inp_recv_re1_1(15 downto 0),
      inp_trans(0) => inp_trans_1(0),
      out_recv(0) => small_test_1_out_recv(0),
      out_trans_im(15 downto 0) => small_test_1_out_trans_im(15 downto 0),
      out_trans_re(15 downto 0) => small_test_1_out_trans_re(15 downto 0),
      test_pin(0) => small_test_1_test_pin(0)
    );
end STRUCTURE;
