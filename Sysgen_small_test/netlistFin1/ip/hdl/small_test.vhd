-- Generated from Simulink block small_test/16-QAM1
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity small_test_16_qam1 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end small_test_16_qam1;
architecture structural of small_test_16_qam1 is 
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal ce_net : std_logic;
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal serial_to_parallel_dout_net : std_logic_vector( 4-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal clk_net : std_logic;
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  serial_to_parallel_dout_net <= in1;
  clk_net <= clk_4;
  ce_net <= ce_4;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_6f934eab2e 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => serial_to_parallel_dout_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_8298a0350f 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_12484bd0f1 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_dd6c28fc92 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_bfc89839f9 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_bfc89839f9 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_8298a0350f 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_12484bd0f1 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_dd6c28fc92 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_017810f7a9 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => clk_net,
    ce => ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_017810f7a9 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => clk_net,
    ce => ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block small_test_struct
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity small_test_struct is
  port (
    inp_recv_im1 : in std_logic_vector( 16-1 downto 0 );
    inp_recv_re1 : in std_logic_vector( 16-1 downto 0 );
    inp_trans : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    clk_8 : in std_logic;
    ce_8 : in std_logic;
    out_recv : out std_logic_vector( 1-1 downto 0 );
    out_trans_im : out std_logic_vector( 16-1 downto 0 );
    out_trans_re : out std_logic_vector( 16-1 downto 0 )
  );
end small_test_struct;
architecture structural of small_test_struct is 
  signal down_sample_q_net : std_logic_vector( 16-1 downto 0 );
  signal down_sample1_q_net : std_logic_vector( 16-1 downto 0 );
  signal register11_q_net : std_logic_vector( 1-1 downto 0 );
  signal up_sample_q_net : std_logic_vector( 1-1 downto 0 );
  signal register1_q_net : std_logic_vector( 1-1 downto 0 );
  signal register6_q_net : std_logic_vector( 16-1 downto 0 );
  signal register9_q_net : std_logic_vector( 16-1 downto 0 );
  signal dest_clk_net : std_logic;
  signal inp_recv_re1_net : std_logic_vector( 16-1 downto 0 );
  signal dest_ce_net_x0 : std_logic;
  signal clk_net : std_logic;
  signal ce_net : std_logic;
  signal inp_trans_net : std_logic_vector( 1-1 downto 0 );
  signal inp_recv_im1_net : std_logic_vector( 16-1 downto 0 );
  signal register5_q_net : std_logic_vector( 16-1 downto 0 );
  signal register7_q_net : std_logic_vector( 16-1 downto 0 );
  signal register8_q_net : std_logic_vector( 16-1 downto 0 );
  signal register4_q_net : std_logic_vector( 16-1 downto 0 );
  signal register10_q_net : std_logic_vector( 1-1 downto 0 );
  signal src_clk_net : std_logic;
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal dest_ce_net : std_logic;
  signal parallel_to_serial_dout_net : std_logic_vector( 1-1 downto 0 );
  signal dest_clk_net_x0 : std_logic;
  signal mcode1_y1_net : std_logic_vector( 4-1 downto 0 );
  signal up_sample1_q_net : std_logic_vector( 16-1 downto 0 );
  signal serial_to_parallel_dout_net : std_logic_vector( 4-1 downto 0 );
  signal src_ce_net : std_logic;
  signal up_sample2_q_net : std_logic_vector( 16-1 downto 0 );
  signal register3_q_net : std_logic_vector( 16-1 downto 0 );
  signal down_sample2_q_net : std_logic_vector( 1-1 downto 0 );
  signal register2_q_net : std_logic_vector( 16-1 downto 0 );
  signal register_q_net : std_logic_vector( 1-1 downto 0 );
begin
  inp_recv_im1_net <= inp_recv_im1;
  inp_recv_re1_net <= inp_recv_re1;
  inp_trans_net <= inp_trans;
  out_recv <= register1_q_net;
  out_trans_im <= register6_q_net;
  out_trans_re <= register9_q_net;
  dest_clk_net <= clk_1;
  dest_ce_net_x0 <= ce_1;
  clk_net <= clk_4;
  ce_net <= ce_4;
  src_clk_net <= clk_5;
  src_ce_net <= ce_5;
  dest_clk_net_x0 <= clk_8;
  dest_ce_net <= ce_8;
  x16_qam1 : entity xil_defaultlib.small_test_16_qam1 
  port map (
    in1 => serial_to_parallel_dout_net,
    clk_4 => clk_net,
    ce_4 => ce_net,
    out2 => mux_y_net,
    out3 => mux1_y_net
  );
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_108a9ea098 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => up_sample1_q_net,
    q => up_sample2_q_net,
    y1 => mcode1_y1_net
  );
  parallel_to_serial : entity xil_defaultlib.small_test_xlp2s 
  generic map (
    din_arith => xlUnsigned,
    din_bin_pt => 0,
    din_width => 4,
    dout_arith => xlUnsigned,
    dout_bin_pt => 0,
    dout_width => 1,
    latency => 1,
    lsb_first => 0,
    num_outputs => 4
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    din => mcode1_y1_net,
    src_clk => clk_net,
    src_ce => ce_net,
    dest_clk => dest_clk_net,
    dest_ce => dest_ce_net_x0,
    dout => parallel_to_serial_dout_net
  );
  serial_to_parallel : entity xil_defaultlib.small_test_xls2p 
  generic map (
    din_arith => xlUnsigned,
    din_bin_pt => 0,
    din_width => 1,
    dout_arith => xlUnsigned,
    dout_bin_pt => 0,
    dout_width => 4,
    latency => 1,
    lsb_first => 0,
    num_inputs => 4
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    din => up_sample_q_net,
    src_clk => dest_clk_net,
    src_ce => dest_ce_net_x0,
    dest_clk => clk_net,
    dest_ce => ce_net,
    dout => serial_to_parallel_dout_net
  );
  up_sample : entity xil_defaultlib.small_test_xlusamp 
  generic map (
    copy_samples => 1,
    d_arith => xlUnsigned,
    d_bin_pt => 0,
    d_width => 1,
    latency => 0,
    q_arith => xlUnsigned,
    q_bin_pt => 0,
    q_width => 1
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    d => register11_q_net,
    src_clk => src_clk_net,
    src_ce => src_ce_net,
    dest_clk => dest_clk_net,
    dest_ce => dest_ce_net_x0,
    q => up_sample_q_net
  );
  down_sample : entity xil_defaultlib.small_test_xldsamp 
  generic map (
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 16,
    ds_ratio => 2,
    latency => 1,
    phase => 1,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 16
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => mux_y_net,
    src_clk => clk_net,
    src_ce => ce_net,
    dest_clk => dest_clk_net_x0,
    dest_ce => dest_ce_net,
    q => down_sample_q_net
  );
  down_sample1 : entity xil_defaultlib.small_test_xldsamp 
  generic map (
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 16,
    ds_ratio => 2,
    latency => 1,
    phase => 1,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 16
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => mux1_y_net,
    src_clk => clk_net,
    src_ce => ce_net,
    dest_clk => dest_clk_net_x0,
    dest_ce => dest_ce_net,
    q => down_sample1_q_net
  );
  up_sample1 : entity xil_defaultlib.small_test_xlusamp 
  generic map (
    copy_samples => 1,
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 16,
    latency => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 16
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    d => register2_q_net,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net,
    dest_clk => clk_net,
    dest_ce => ce_net,
    q => up_sample1_q_net
  );
  register_x0 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 1,
    init_value => b"0"
  )
  port map (
    en => "1",
    rst => "0",
    d => down_sample2_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => register_q_net
  );
  register1 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 1,
    init_value => b"0"
  )
  port map (
    en => "1",
    rst => "0",
    d => register_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => register1_q_net
  );
  register2 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 16,
    init_value => b"0000000000000000"
  )
  port map (
    en => "1",
    rst => "0",
    d => register3_q_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net,
    q => register2_q_net
  );
  register3 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 16,
    init_value => b"0000000000000000"
  )
  port map (
    en => "1",
    rst => "0",
    d => inp_recv_re1_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net,
    q => register3_q_net
  );
  register4 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 16,
    init_value => b"0000000000000000"
  )
  port map (
    en => "1",
    rst => "0",
    d => inp_recv_im1_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net,
    q => register4_q_net
  );
  register5 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 16,
    init_value => b"0000000000000000"
  )
  port map (
    en => "1",
    rst => "0",
    d => register4_q_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net,
    q => register5_q_net
  );
  register6 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 16,
    init_value => b"0000000000000000"
  )
  port map (
    en => "1",
    rst => "0",
    d => register7_q_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net,
    q => register6_q_net
  );
  register7 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 16,
    init_value => b"0000000000000000"
  )
  port map (
    en => "1",
    rst => "0",
    d => down_sample1_q_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net,
    q => register7_q_net
  );
  register8 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 16,
    init_value => b"0000000000000000"
  )
  port map (
    en => "1",
    rst => "0",
    d => down_sample_q_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net,
    q => register8_q_net
  );
  register9 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 16,
    init_value => b"0000000000000000"
  )
  port map (
    en => "1",
    rst => "0",
    d => register8_q_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net,
    q => register9_q_net
  );
  register10 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 1,
    init_value => b"0"
  )
  port map (
    en => "1",
    rst => "0",
    d => inp_trans_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => register10_q_net
  );
  register11 : entity xil_defaultlib.small_test_xlregister 
  generic map (
    d_width => 1,
    init_value => b"0"
  )
  port map (
    en => "1",
    rst => "0",
    d => register10_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => register11_q_net
  );
  up_sample2 : entity xil_defaultlib.small_test_xlusamp 
  generic map (
    copy_samples => 1,
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 16,
    latency => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 16
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    d => register5_q_net,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net,
    dest_clk => clk_net,
    dest_ce => ce_net,
    q => up_sample2_q_net
  );
  down_sample2 : entity xil_defaultlib.small_test_xldsamp 
  generic map (
    d_arith => xlUnsigned,
    d_bin_pt => 0,
    d_width => 1,
    ds_ratio => 5,
    latency => 1,
    phase => 4,
    q_arith => xlUnsigned,
    q_bin_pt => 0,
    q_width => 1
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => parallel_to_serial_dout_net,
    src_clk => dest_clk_net,
    src_ce => dest_ce_net_x0,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net,
    q => down_sample2_q_net
  );
end structural;
-- Generated from Simulink block 
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity small_test_default_clock_driver is
  port (
    small_test_sysclk : in std_logic;
    small_test_sysce : in std_logic;
    small_test_sysclr : in std_logic;
    small_test_clk1 : out std_logic;
    small_test_ce1 : out std_logic;
    small_test_clk4 : out std_logic;
    small_test_ce4 : out std_logic;
    small_test_clk5 : out std_logic;
    small_test_ce5 : out std_logic;
    small_test_clk8 : out std_logic;
    small_test_ce8 : out std_logic
  );
end small_test_default_clock_driver;
architecture structural of small_test_default_clock_driver is 
begin
  clockdriver_x2 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 1,
    log_2_period => 1
  )
  port map (
    sysclk => small_test_sysclk,
    sysce => small_test_sysce,
    sysclr => small_test_sysclr,
    clk => small_test_clk1,
    ce => small_test_ce1
  );
  clockdriver_x1 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 4,
    log_2_period => 3
  )
  port map (
    sysclk => small_test_sysclk,
    sysce => small_test_sysce,
    sysclr => small_test_sysclr,
    clk => small_test_clk4,
    ce => small_test_ce4
  );
  clockdriver_x0 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 5,
    log_2_period => 3
  )
  port map (
    sysclk => small_test_sysclk,
    sysce => small_test_sysce,
    sysclr => small_test_sysclr,
    clk => small_test_clk5,
    ce => small_test_ce5
  );
  clockdriver : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 8,
    log_2_period => 4
  )
  port map (
    sysclk => small_test_sysclk,
    sysce => small_test_sysce,
    sysclr => small_test_sysclr,
    clk => small_test_clk8,
    ce => small_test_ce8
  );
end structural;
-- Generated from Simulink block 
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity small_test is
  port (
    inp_recv_im1 : in std_logic_vector( 16-1 downto 0 );
    inp_recv_re1 : in std_logic_vector( 16-1 downto 0 );
    inp_trans : in std_logic_vector( 1-1 downto 0 );
    clk : in std_logic;
    out_recv : out std_logic_vector( 1-1 downto 0 );
    out_trans_im : out std_logic_vector( 16-1 downto 0 );
    out_trans_re : out std_logic_vector( 16-1 downto 0 )
  );
end small_test;
architecture structural of small_test is 
  attribute core_generation_info : string;
  attribute core_generation_info of structural : architecture is "small_test,sysgen_core_2014_4,{,compilation=IP Catalog,block_icon_display=Default,family=zynq,part=xc7z020,speed=-1,package=clg400,synthesis_language=vhdl,hdl_library=xil_defaultlib,synthesis_strategy=Vivado Synthesis Defaults,implementation_strategy=Vivado Implementation Defaults,clock_loc=,testbench=1,interface_doc=1,ce_clr=0,clock_period=4,system_simulink_period=4e-09,simulation_time=4e-05,bitbasher=1,constant=8,dsamp=3,mcode=1,mux=2,p2s=1,register=12,s2p=1,usamp=3,}";
  signal clk_1_net : std_logic;
  signal ce_4_net : std_logic;
  signal clk_4_net : std_logic;
  signal ce_1_net : std_logic;
  signal clk_5_net : std_logic;
  signal ce_5_net : std_logic;
  signal clk_8_net : std_logic;
  signal ce_8_net : std_logic;
begin
  small_test_default_clock_driver : entity xil_defaultlib.small_test_default_clock_driver 
  port map (
    small_test_sysclk => clk,
    small_test_sysce => '1',
    small_test_sysclr => '0',
    small_test_clk1 => clk_1_net,
    small_test_ce1 => ce_1_net,
    small_test_clk4 => clk_4_net,
    small_test_ce4 => ce_4_net,
    small_test_clk5 => clk_5_net,
    small_test_ce5 => ce_5_net,
    small_test_clk8 => clk_8_net,
    small_test_ce8 => ce_8_net
  );
  small_test_struct : entity xil_defaultlib.small_test_struct 
  port map (
    inp_recv_im1 => inp_recv_im1,
    inp_recv_re1 => inp_recv_re1,
    inp_trans => inp_trans,
    clk_1 => clk_1_net,
    ce_1 => ce_1_net,
    clk_4 => clk_4_net,
    ce_4 => ce_4_net,
    clk_5 => clk_5_net,
    ce_5 => ce_5_net,
    clk_8 => clk_8_net,
    ce_8 => ce_8_net,
    out_recv => out_recv,
    out_trans_im => out_trans_im,
    out_trans_re => out_trans_re
  );
end structural;
