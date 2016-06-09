--Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2014.4 (win64) Build 1071353 Tue Nov 18 18:29:27 MST 2014
--Date        : Mon May 30 16:44:15 2016
--Host        : UML-02 running 64-bit major release  (build 9200)
--Command     : generate_target basic_dmt_bd_wrapper.bd
--Design      : basic_dmt_bd_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity basic_dmt_bd_wrapper is
  port (
    clk : in STD_LOGIC;
    diffsig : out STD_LOGIC_VECTOR ( 0 to 0 );
    inp_recv_im : in STD_LOGIC_VECTOR ( 8 downto 0 );
    inp_recv_re : in STD_LOGIC_VECTOR ( 8 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 8 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 8 downto 0 )
  );
end basic_dmt_bd_wrapper;

architecture STRUCTURE of basic_dmt_bd_wrapper is
  component basic_dmt_bd is
  port (
    clk : in STD_LOGIC;
    diffsig : out STD_LOGIC_VECTOR ( 0 to 0 );
    inp_recv_im : in STD_LOGIC_VECTOR ( 8 downto 0 );
    inp_recv_re : in STD_LOGIC_VECTOR ( 8 downto 0 );
    inp_trans : in STD_LOGIC_VECTOR ( 0 to 0 );
    out_recv : out STD_LOGIC_VECTOR ( 0 to 0 );
    out_trans_im : out STD_LOGIC_VECTOR ( 8 downto 0 );
    out_trans_re : out STD_LOGIC_VECTOR ( 8 downto 0 )
  );
  end component basic_dmt_bd;
begin
basic_dmt_bd_i: component basic_dmt_bd
    port map (
      clk => clk,
      diffsig(0) => diffsig(0),
      inp_recv_im(8 downto 0) => inp_recv_im(8 downto 0),
      inp_recv_re(8 downto 0) => inp_recv_re(8 downto 0),
      inp_trans(0) => inp_trans(0),
      out_recv(0) => out_recv(0),
      out_trans_im(8 downto 0) => out_trans_im(8 downto 0),
      out_trans_re(8 downto 0) => out_trans_re(8 downto 0)
    );
end STRUCTURE;
