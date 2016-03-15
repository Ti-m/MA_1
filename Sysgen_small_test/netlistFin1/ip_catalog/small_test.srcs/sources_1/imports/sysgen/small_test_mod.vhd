-- Generated from Simulink block 
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
entity small_test_stub is
  port (
    inp_recv_im1 : in std_logic_vector( 16-1 downto 0 );
    inp_recv_re1 : in std_logic_vector( 16-1 downto 0 );
    inp_trans : in std_logic_vector( 1-1 downto 0 );
    clk : in std_logic;
    out_recv : out std_logic_vector( 1-1 downto 0 );
    out_trans_im : out std_logic_vector( 16-1 downto 0 );
    out_trans_re : out std_logic_vector( 16-1 downto 0 )
  );
end small_test_stub;
architecture structural of small_test_stub is 
begin
  sysgen_dut : entity xil_defaultlib.small_test 
  port map (
    inp_recv_im1 => inp_recv_im1,
    inp_recv_re1 => inp_recv_re1,
    inp_trans => inp_trans,
    clk => clk,
    out_recv => out_recv,
    out_trans_im => out_trans_im,
    out_trans_re => out_trans_re
  );
end structural;
