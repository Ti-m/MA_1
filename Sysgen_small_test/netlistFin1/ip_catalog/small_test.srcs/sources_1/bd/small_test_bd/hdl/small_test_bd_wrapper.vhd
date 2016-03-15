--Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2014.4 (win64) Build 1071353 Tue Nov 18 18:29:27 MST 2014
--Date        : Tue Mar 15 10:36:06 2016
--Host        : UML-02 running 64-bit major release  (build 9200)
--Command     : generate_target small_test_bd_wrapper.bd
--Design      : small_test_bd_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity small_test_bd_wrapper is
  port (
    clk : in STD_LOGIC;
    inp_recv_im1 : in STD_LOGIC_VECTOR ( 15 downto 0 );
    inp_recv_re1 : in STD_LOGIC_VECTOR ( 15 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 15 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 15 downto 0 )
  );
end small_test_bd_wrapper;

architecture STRUCTURE of small_test_bd_wrapper is
  component small_test_bd is
  port (
    clk : in STD_LOGIC;
    inp_recv_im1 : in STD_LOGIC_VECTOR ( 15 downto 0 );
    inp_recv_re1 : in STD_LOGIC_VECTOR ( 15 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 15 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 15 downto 0 )
  );
  end component small_test_bd;
begin
small_test_bd_i: component small_test_bd
    port map (
      clk => clk,
      inp_recv_im1(15 downto 0) => inp_recv_im1(15 downto 0),
      inp_recv_re1(15 downto 0) => inp_recv_re1(15 downto 0),
      inp_trans(0) => inp_trans(0),
      out_recv(0) => out_recv(0),
      out_trans_im(15 downto 0) => out_trans_im(15 downto 0),
      out_trans_re(15 downto 0) => out_trans_re(15 downto 0)
    );
end STRUCTURE;
