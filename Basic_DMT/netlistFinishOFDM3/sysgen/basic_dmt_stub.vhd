-- Generated from Simulink block 
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
entity basic_dmt_stub is
  port (
    inp_recv_im : in std_logic_vector( 9-1 downto 0 );
    inp_recv_re : in std_logic_vector( 9-1 downto 0 );
    inp_trans : in std_logic_vector( 1-1 downto 0 );
    clk : in std_logic;
    diffsig : out std_logic_vector( 1-1 downto 0 );
    out_recv : out std_logic_vector( 1-1 downto 0 );
    out_trans_im : out std_logic_vector( 9-1 downto 0 );
    out_trans_re : out std_logic_vector( 9-1 downto 0 )
  );
end basic_dmt_stub;
architecture structural of basic_dmt_stub is 
begin
  sysgen_dut : entity xil_defaultlib.basic_dmt 
  port map (
    inp_recv_im => inp_recv_im,
    inp_recv_re => inp_recv_re,
    inp_trans => inp_trans,
    clk => clk,
    diffsig => diffsig,
    out_recv => out_recv,
    out_trans_im => out_trans_im,
    out_trans_re => out_trans_re
  );
end structural;
