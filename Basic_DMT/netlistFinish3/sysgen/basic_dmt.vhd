-- Generated from Simulink block Basic_DMT/Sysgen_Channel/No_channel
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_no_channel is
  port (
    re : in std_logic_vector( 21-1 downto 0 );
    im : in std_logic_vector( 21-1 downto 0 );
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    re_out : out std_logic_vector( 21-1 downto 0 );
    im_out : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_no_channel;
architecture structural of basic_dmt_no_channel is 
  signal ce_net : std_logic;
  signal down_sample1_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay2_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay3_q_net : std_logic_vector( 21-1 downto 0 );
  signal clk_net : std_logic;
  signal down_sample_q_net : std_logic_vector( 21-1 downto 0 );
begin
  re_out <= delay2_q_net;
  im_out <= delay3_q_net;
  down_sample_q_net <= re;
  down_sample1_q_net <= im;
  clk_net <= clk_14;
  ce_net <= ce_14;
  delay2 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => down_sample_q_net,
    clk => clk_net,
    ce => ce_net,
    q => delay2_q_net
  );
  delay3 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => down_sample1_q_net,
    clk => clk_net,
    ce => ce_net,
    q => delay3_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Channel
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_sysgen_channel is
  port (
    re : in std_logic_vector( 21-1 downto 0 );
    im : in std_logic_vector( 21-1 downto 0 );
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    re_out : out std_logic_vector( 21-1 downto 0 );
    im_out : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_sysgen_channel;
architecture structural of basic_dmt_sysgen_channel is 
  signal ce_net : std_logic;
  signal down_sample_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay2_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay3_q_net : std_logic_vector( 21-1 downto 0 );
  signal down_sample1_q_net : std_logic_vector( 21-1 downto 0 );
  signal clk_net : std_logic;
begin
  re_out <= delay2_q_net;
  im_out <= delay3_q_net;
  down_sample_q_net <= re;
  down_sample1_q_net <= im;
  clk_net <= clk_14;
  ce_net <= ce_14;
  no_channel_x0 : entity xil_defaultlib.basic_dmt_no_channel 
  port map (
    re => down_sample_q_net,
    im => down_sample1_q_net,
    clk_14 => clk_net,
    ce_14 => ce_net,
    re_out => delay2_q_net,
    im_out => delay3_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Demodulation
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_sysgen_demodulation is
  port (
    re_sub1 : in std_logic_vector( 26-1 downto 0 );
    im_sub1 : in std_logic_vector( 26-1 downto 0 );
    re_sub2 : in std_logic_vector( 26-1 downto 0 );
    im_sub2 : in std_logic_vector( 26-1 downto 0 );
    re_sub3 : in std_logic_vector( 26-1 downto 0 );
    im_sub3 : in std_logic_vector( 26-1 downto 0 );
    re_sub4 : in std_logic_vector( 26-1 downto 0 );
    im_sub4 : in std_logic_vector( 26-1 downto 0 );
    re_sub5 : in std_logic_vector( 26-1 downto 0 );
    im_sub5 : in std_logic_vector( 26-1 downto 0 );
    re_sub6 : in std_logic_vector( 26-1 downto 0 );
    im_sub6 : in std_logic_vector( 26-1 downto 0 );
    re_sub7 : in std_logic_vector( 26-1 downto 0 );
    im_sub7 : in std_logic_vector( 26-1 downto 0 );
    re_sub8 : in std_logic_vector( 26-1 downto 0 );
    im_sub8 : in std_logic_vector( 26-1 downto 0 );
    re_sub9 : in std_logic_vector( 26-1 downto 0 );
    im_sub9 : in std_logic_vector( 26-1 downto 0 );
    re_sub10 : in std_logic_vector( 26-1 downto 0 );
    im_sub10 : in std_logic_vector( 26-1 downto 0 );
    re_sub11 : in std_logic_vector( 26-1 downto 0 );
    im_sub11 : in std_logic_vector( 26-1 downto 0 );
    re_sub12 : in std_logic_vector( 26-1 downto 0 );
    im_sub12 : in std_logic_vector( 26-1 downto 0 );
    re_sub13 : in std_logic_vector( 26-1 downto 0 );
    im_sub13 : in std_logic_vector( 26-1 downto 0 );
    re_sub14 : in std_logic_vector( 26-1 downto 0 );
    im_sub14 : in std_logic_vector( 26-1 downto 0 );
    re_sub15 : in std_logic_vector( 26-1 downto 0 );
    im_sub15 : in std_logic_vector( 26-1 downto 0 );
    re_sub16 : in std_logic_vector( 26-1 downto 0 );
    im_sub16 : in std_logic_vector( 26-1 downto 0 );
    bit_sub1 : out std_logic_vector( 4-1 downto 0 );
    bit_sub2 : out std_logic_vector( 4-1 downto 0 );
    bit_sub3 : out std_logic_vector( 4-1 downto 0 );
    bit_sub4 : out std_logic_vector( 4-1 downto 0 );
    bit_sub5 : out std_logic_vector( 4-1 downto 0 );
    bit_sub6 : out std_logic_vector( 4-1 downto 0 );
    bit_sub7 : out std_logic_vector( 4-1 downto 0 );
    bit_sub8 : out std_logic_vector( 4-1 downto 0 );
    bit_sub9 : out std_logic_vector( 4-1 downto 0 );
    bit_sub10 : out std_logic_vector( 4-1 downto 0 );
    bit_sub11 : out std_logic_vector( 4-1 downto 0 );
    bit_sub12 : out std_logic_vector( 4-1 downto 0 );
    bit_sub13 : out std_logic_vector( 4-1 downto 0 );
    bit_sub14 : out std_logic_vector( 4-1 downto 0 );
    bit_sub15 : out std_logic_vector( 4-1 downto 0 );
    bit_sub16 : out std_logic_vector( 4-1 downto 0 )
  );
end basic_dmt_sysgen_demodulation;
architecture structural of basic_dmt_sysgen_demodulation is 
  signal mcode3_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode9_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode5_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode10_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode12_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode14_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode15_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y1_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y2_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode7_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode16_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode6_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode8_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode13_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y2_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode11_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y1_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode4_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode2_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y4_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y14_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y14_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y15_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y12_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y13_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y7_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y15_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y16_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y16_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y7_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y6_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y12_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y6_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y11_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y13_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y4_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y5_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y5_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y9_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y9_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y11_re_net : std_logic_vector( 26-1 downto 0 );
begin
  bit_sub1 <= mcode1_y1_net;
  bit_sub2 <= mcode2_y1_net;
  bit_sub3 <= mcode3_y1_net;
  bit_sub4 <= mcode4_y1_net;
  bit_sub5 <= mcode5_y1_net;
  bit_sub6 <= mcode6_y1_net;
  bit_sub7 <= mcode7_y1_net;
  bit_sub8 <= mcode8_y1_net;
  bit_sub9 <= mcode9_y1_net;
  bit_sub10 <= mcode10_y1_net;
  bit_sub11 <= mcode11_y1_net;
  bit_sub12 <= mcode12_y1_net;
  bit_sub13 <= mcode13_y1_net;
  bit_sub14 <= mcode14_y1_net;
  bit_sub15 <= mcode15_y1_net;
  bit_sub16 <= mcode16_y1_net;
  mcode1_y1_re_net <= re_sub1;
  mcode1_y1_im_net <= im_sub1;
  mcode1_y2_re_net <= re_sub2;
  mcode1_y2_im_net <= im_sub2;
  mcode1_y3_re_net <= re_sub3;
  mcode1_y3_im_net <= im_sub3;
  mcode1_y4_re_net <= re_sub4;
  mcode1_y4_im_net <= im_sub4;
  mcode1_y5_re_net <= re_sub5;
  mcode1_y5_im_net <= im_sub5;
  mcode1_y6_re_net <= re_sub6;
  mcode1_y6_im_net <= im_sub6;
  mcode1_y7_re_net <= re_sub7;
  mcode1_y7_im_net <= im_sub7;
  mcode1_y8_re_net <= re_sub8;
  mcode1_y8_im_net <= im_sub8;
  mcode1_y9_re_net <= re_sub9;
  mcode1_y9_im_net <= im_sub9;
  mcode1_y10_re_net <= re_sub10;
  mcode1_y10_im_net <= im_sub10;
  mcode1_y11_re_net <= re_sub11;
  mcode1_y11_im_net <= im_sub11;
  mcode1_y12_re_net <= re_sub12;
  mcode1_y12_im_net <= im_sub12;
  mcode1_y13_re_net <= re_sub13;
  mcode1_y13_im_net <= im_sub13;
  mcode1_y14_re_net <= re_sub14;
  mcode1_y14_im_net <= im_sub14;
  mcode1_y15_re_net <= re_sub15;
  mcode1_y15_im_net <= im_sub15;
  mcode1_y16_re_net <= re_sub16;
  mcode1_y16_im_net <= im_sub16;
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y1_re_net,
    q => mcode1_y1_im_net,
    y1 => mcode1_y1_net
  );
  mcode10 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y10_re_net,
    q => mcode1_y10_im_net,
    y1 => mcode10_y1_net
  );
  mcode11 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y11_re_net,
    q => mcode1_y11_im_net,
    y1 => mcode11_y1_net
  );
  mcode12 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y12_re_net,
    q => mcode1_y12_im_net,
    y1 => mcode12_y1_net
  );
  mcode13 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y13_re_net,
    q => mcode1_y13_im_net,
    y1 => mcode13_y1_net
  );
  mcode14 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y14_re_net,
    q => mcode1_y14_im_net,
    y1 => mcode14_y1_net
  );
  mcode15 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y15_re_net,
    q => mcode1_y15_im_net,
    y1 => mcode15_y1_net
  );
  mcode16 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y16_re_net,
    q => mcode1_y16_im_net,
    y1 => mcode16_y1_net
  );
  mcode2 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y2_re_net,
    q => mcode1_y2_im_net,
    y1 => mcode2_y1_net
  );
  mcode3 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y3_re_net,
    q => mcode1_y3_im_net,
    y1 => mcode3_y1_net
  );
  mcode4 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y4_re_net,
    q => mcode1_y4_im_net,
    y1 => mcode4_y1_net
  );
  mcode5 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y5_re_net,
    q => mcode1_y5_im_net,
    y1 => mcode5_y1_net
  );
  mcode6 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y6_re_net,
    q => mcode1_y6_im_net,
    y1 => mcode6_y1_net
  );
  mcode7 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y7_re_net,
    q => mcode1_y7_im_net,
    y1 => mcode7_y1_net
  );
  mcode8 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y8_re_net,
    q => mcode1_y8_im_net,
    y1 => mcode8_y1_net
  );
  mcode9 : entity xil_defaultlib.sysgen_mcode_block_5010573108 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i => mcode1_y9_re_net,
    q => mcode1_y9_im_net,
    y1 => mcode9_y1_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_IFFTaPIS/Guard_Interval/Set_GI_OFDM
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_set_gi_ofdm is
  port (
    re_in : in std_logic_vector( 21-1 downto 0 );
    im_in : in std_logic_vector( 21-1 downto 0 );
    sgframestart : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    re : out std_logic_vector( 21-1 downto 0 );
    im : out std_logic_vector( 21-1 downto 0 );
    pop : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_set_gi_ofdm;
architecture structural of basic_dmt_set_gi_ofdm is 
  signal mcode_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_pop_net : std_logic_vector( 1-1 downto 0 );
  signal mcode1_framestart_net : std_logic_vector( 1-1 downto 0 );
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal dest_clk_net : std_logic;
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
  signal dest_ce_net : std_logic;
  signal delay5_q_net_x0 : std_logic_vector( 21-1 downto 0 );
  signal src_clk_net_x0 : std_logic;
  signal src_ce_net_x0 : std_logic;
  signal mcode_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert14_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert12_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o3_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert16_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o16_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert11_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o1_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o2_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o15_re_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_stateo_net : std_logic_vector( 8-1 downto 0 );
  signal assert19_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert17_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o14_re_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o5_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert15_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert18_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert2_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert1_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o4_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o7_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert10_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert13_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o16_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o6_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert_dout_net : std_logic_vector( 8-1 downto 0 );
  signal mcode_o6_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert28_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o7_re_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o5_re_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o12_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert29_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert3_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o9_re_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o14_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert30_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o11_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert26_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o3_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert20_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o4_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert23_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert27_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o13_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert24_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o15_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o10_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert25_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert22_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert21_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o8_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert9_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o10_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o1_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert32_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o8_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert4_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert31_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert5_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o2_re_net : std_logic_vector( 21-1 downto 0 );
  signal assert6_dout_net : std_logic_vector( 21-1 downto 0 );
  signal down_sample_q_net : std_logic_vector( 1-1 downto 0 );
  signal mcode_o12_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o13_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert7_dout_net : std_logic_vector( 21-1 downto 0 );
  signal assert8_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o11_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode_o9_im_net : std_logic_vector( 21-1 downto 0 );
  signal delay34_q_net : std_logic_vector( 21-1 downto 0 );
  signal up_sample_q_net : std_logic_vector( 1-1 downto 0 );
  signal delay35_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay32_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay7_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay21_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay13_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay5_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay33_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay22_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay12_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay2_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay9_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay31_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay28_q_net : std_logic_vector( 1-1 downto 0 );
  signal delay29_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay6_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay16_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay10_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay8_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay19_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay27_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay14_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay4_q_net_x0 : std_logic_vector( 21-1 downto 0 );
  signal delay17_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay15_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay25_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay20_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay1_q_net : std_logic_vector( 8-1 downto 0 );
  signal delay23_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay30_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay26_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay24_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay11_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay3_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay18_q_net : std_logic_vector( 21-1 downto 0 );
begin
  re <= mcode_out_re_net;
  im <= mcode_out_im_net;
  pop <= mcode_pop_net;
  delay4_q_net <= re_in;
  delay5_q_net_x0 <= im_in;
  mcode1_framestart_net <= sgframestart;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  dest_clk_net <= clk_4;
  dest_ce_net <= ce_4;
  src_clk_net_x0 <= clk_64;
  src_ce_net_x0 <= ce_64;
  assert_x0 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode_stateo_net,
    dout => assert_dout_net
  );
  assert1 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o16_im_net,
    dout => assert1_dout_net
  );
  assert10 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o7_im_net,
    dout => assert10_dout_net
  );
  assert11 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o6_im_net,
    dout => assert11_dout_net
  );
  assert12 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o5_im_net,
    dout => assert12_dout_net
  );
  assert13 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o4_im_net,
    dout => assert13_dout_net
  );
  assert14 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o3_im_net,
    dout => assert14_dout_net
  );
  assert15 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o2_im_net,
    dout => assert15_dout_net
  );
  assert16 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o1_im_net,
    dout => assert16_dout_net
  );
  assert17 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o16_re_net,
    dout => assert17_dout_net
  );
  assert18 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o15_re_net,
    dout => assert18_dout_net
  );
  assert19 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o14_re_net,
    dout => assert19_dout_net
  );
  assert2 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o15_im_net,
    dout => assert2_dout_net
  );
  assert20 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o13_re_net,
    dout => assert20_dout_net
  );
  assert21 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o12_re_net,
    dout => assert21_dout_net
  );
  assert22 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o11_re_net,
    dout => assert22_dout_net
  );
  assert23 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o10_re_net,
    dout => assert23_dout_net
  );
  assert24 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o9_re_net,
    dout => assert24_dout_net
  );
  assert25 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o8_re_net,
    dout => assert25_dout_net
  );
  assert26 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o7_re_net,
    dout => assert26_dout_net
  );
  assert27 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o6_re_net,
    dout => assert27_dout_net
  );
  assert28 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o5_re_net,
    dout => assert28_dout_net
  );
  assert29 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o4_re_net,
    dout => assert29_dout_net
  );
  assert3 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o14_im_net,
    dout => assert3_dout_net
  );
  assert30 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o3_re_net,
    dout => assert30_dout_net
  );
  assert31 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o2_re_net,
    dout => assert31_dout_net
  );
  assert32 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o1_re_net,
    dout => assert32_dout_net
  );
  assert4 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o13_im_net,
    dout => assert4_dout_net
  );
  assert5 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o12_im_net,
    dout => assert5_dout_net
  );
  assert6 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o11_im_net,
    dout => assert6_dout_net
  );
  assert7 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o10_im_net,
    dout => assert7_dout_net
  );
  assert8 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o9_im_net,
    dout => assert8_dout_net
  );
  assert9 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 21,
    dout_width => 21
  )
  port map (
    din => mcode_o8_im_net,
    dout => assert9_dout_net
  );
  down_sample : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlUnsigned,
    d_bin_pt => 0,
    d_width => 1,
    ds_ratio => 64,
    latency => 1,
    phase => 0,
    q_arith => xlUnsigned,
    q_bin_pt => 0,
    q_width => 1
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => mcode1_framestart_net,
    src_clk => src_clk_net,
    src_ce => src_ce_net,
    dest_clk => src_clk_net_x0,
    dest_ce => src_ce_net_x0,
    q => down_sample_q_net
  );
  mcode : entity xil_defaultlib.sysgen_mcode_block_2371105fd2 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    inp_re => delay35_q_net,
    inp_im => delay34_q_net,
    frameen => up_sample_q_net,
    i1_re => delay33_q_net,
    i2_re => delay32_q_net,
    i3_re => delay31_q_net,
    i4_re => delay30_q_net,
    i5_re => delay29_q_net,
    i6_re => delay21_q_net,
    i7_re => delay27_q_net,
    i8_re => delay26_q_net,
    i9_re => delay25_q_net,
    i10_re => delay24_q_net,
    i11_re => delay23_q_net,
    i12_re => delay22_q_net,
    i13_re => delay14_q_net,
    i14_re => delay20_q_net,
    i15_re => delay19_q_net,
    i16_re => delay18_q_net,
    i1_im => delay17_q_net,
    i2_im => delay16_q_net,
    i3_im => delay15_q_net,
    i4_im => delay7_q_net,
    i5_im => delay13_q_net,
    i6_im => delay12_q_net,
    i7_im => delay11_q_net,
    i8_im => delay10_q_net,
    i9_im => delay9_q_net,
    i10_im => delay8_q_net,
    i11_im => delay_q_net,
    i12_im => delay6_q_net,
    i13_im => delay5_q_net,
    i14_im => delay4_q_net_x0,
    i15_im => delay3_q_net,
    i16_im => delay2_q_net,
    statei => delay1_q_net,
    out_re => mcode_out_re_net,
    out_im => mcode_out_im_net,
    pop => mcode_pop_net,
    o1_re => mcode_o1_re_net,
    o2_re => mcode_o2_re_net,
    o3_re => mcode_o3_re_net,
    o4_re => mcode_o4_re_net,
    o5_re => mcode_o5_re_net,
    o6_re => mcode_o6_re_net,
    o7_re => mcode_o7_re_net,
    o8_re => mcode_o8_re_net,
    o9_re => mcode_o9_re_net,
    o10_re => mcode_o10_re_net,
    o11_re => mcode_o11_re_net,
    o12_re => mcode_o12_re_net,
    o13_re => mcode_o13_re_net,
    o14_re => mcode_o14_re_net,
    o15_re => mcode_o15_re_net,
    o16_re => mcode_o16_re_net,
    o1_im => mcode_o1_im_net,
    o2_im => mcode_o2_im_net,
    o3_im => mcode_o3_im_net,
    o4_im => mcode_o4_im_net,
    o5_im => mcode_o5_im_net,
    o6_im => mcode_o6_im_net,
    o7_im => mcode_o7_im_net,
    o8_im => mcode_o8_im_net,
    o9_im => mcode_o9_im_net,
    o10_im => mcode_o10_im_net,
    o11_im => mcode_o11_im_net,
    o12_im => mcode_o12_im_net,
    o13_im => mcode_o13_im_net,
    o14_im => mcode_o14_im_net,
    o15_im => mcode_o15_im_net,
    o16_im => mcode_o16_im_net,
    stateo => mcode_stateo_net
  );
  up_sample : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
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
    d => delay28_q_net,
    src_clk => src_clk_net_x0,
    src_ce => src_ce_net_x0,
    dest_clk => dest_clk_net,
    dest_ce => dest_ce_net,
    q => up_sample_q_net
  );
  delay : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert6_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay_q_net
  );
  delay1 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay1_q_net
  );
  delay10 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert9_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay10_q_net
  );
  delay11 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert10_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay11_q_net
  );
  delay12 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert11_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay12_q_net
  );
  delay13 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert12_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay13_q_net
  );
  delay14 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert20_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay14_q_net
  );
  delay15 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert14_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay15_q_net
  );
  delay16 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert15_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay16_q_net
  );
  delay17 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert16_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay17_q_net
  );
  delay18 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert17_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay18_q_net
  );
  delay19 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert18_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay19_q_net
  );
  delay2 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert1_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay2_q_net
  );
  delay20 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert19_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay20_q_net
  );
  delay21 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert27_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay21_q_net
  );
  delay22 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert21_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay22_q_net
  );
  delay23 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert22_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay23_q_net
  );
  delay24 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert23_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay24_q_net
  );
  delay25 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert24_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay25_q_net
  );
  delay26 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert25_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay26_q_net
  );
  delay27 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert26_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay27_q_net
  );
  delay28 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 8,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => down_sample_q_net,
    clk => src_clk_net_x0,
    ce => src_ce_net_x0,
    q => delay28_q_net
  );
  delay29 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert28_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay29_q_net
  );
  delay3 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert2_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay3_q_net
  );
  delay30 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert29_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay30_q_net
  );
  delay31 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert30_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay31_q_net
  );
  delay32 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert31_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay32_q_net
  );
  delay33 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert32_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay33_q_net
  );
  delay34 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => delay5_q_net_x0,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay34_q_net
  );
  delay35 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => delay4_q_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay35_q_net
  );
  delay4 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert3_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay4_q_net_x0
  );
  delay5 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert4_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay5_q_net
  );
  delay6 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert5_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay6_q_net
  );
  delay7 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert13_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay7_q_net
  );
  delay8 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert7_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay8_q_net
  );
  delay9 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => assert8_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay9_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_IFFTaPIS/Guard_Interval
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_guard_interval is
  port (
    re_in : in std_logic_vector( 21-1 downto 0 );
    im_in : in std_logic_vector( 21-1 downto 0 );
    sgframestart : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    re : out std_logic_vector( 21-1 downto 0 );
    im : out std_logic_vector( 21-1 downto 0 );
    pop : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_guard_interval;
architecture structural of basic_dmt_guard_interval is 
  signal mcode1_framestart_net : std_logic_vector( 1-1 downto 0 );
  signal dest_clk_net : std_logic;
  signal src_clk_net_x0 : std_logic;
  signal mcode_pop_net : std_logic_vector( 1-1 downto 0 );
  signal src_ce_net : std_logic;
  signal src_ce_net_x0 : std_logic;
  signal dest_ce_net : std_logic;
  signal mcode_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
  signal src_clk_net : std_logic;
  signal mcode_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal delay5_q_net : std_logic_vector( 21-1 downto 0 );
begin
  re <= mcode_out_re_net;
  im <= mcode_out_im_net;
  pop <= mcode_pop_net;
  delay4_q_net <= re_in;
  delay5_q_net <= im_in;
  mcode1_framestart_net <= sgframestart;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  dest_clk_net <= clk_4;
  dest_ce_net <= ce_4;
  src_clk_net_x0 <= clk_64;
  src_ce_net_x0 <= ce_64;
  set_gi_ofdm_x0 : entity xil_defaultlib.basic_dmt_set_gi_ofdm 
  port map (
    re_in => delay4_q_net,
    im_in => delay5_q_net,
    sgframestart => mcode1_framestart_net,
    clk_1 => src_clk_net,
    ce_1 => src_ce_net,
    clk_4 => dest_clk_net,
    ce_4 => dest_ce_net,
    clk_64 => src_clk_net_x0,
    ce_64 => src_ce_net_x0,
    re => mcode_out_re_net,
    im => mcode_out_im_net,
    pop => mcode_pop_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_IFFTaPIS/OFDMorDMT/IFFT_OFDM
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_ifft_ofdm is
  port (
    re_sub1 : in std_logic_vector( 16-1 downto 0 );
    im_sub1 : in std_logic_vector( 16-1 downto 0 );
    re_sub2 : in std_logic_vector( 16-1 downto 0 );
    im_sub2 : in std_logic_vector( 16-1 downto 0 );
    re_sub3 : in std_logic_vector( 16-1 downto 0 );
    im_sub3 : in std_logic_vector( 16-1 downto 0 );
    re_sub4 : in std_logic_vector( 16-1 downto 0 );
    im_sub4 : in std_logic_vector( 16-1 downto 0 );
    re_sub5 : in std_logic_vector( 16-1 downto 0 );
    im_sub5 : in std_logic_vector( 16-1 downto 0 );
    re_sub6 : in std_logic_vector( 16-1 downto 0 );
    im_sub6 : in std_logic_vector( 16-1 downto 0 );
    re_sub7 : in std_logic_vector( 16-1 downto 0 );
    im_sub7 : in std_logic_vector( 16-1 downto 0 );
    re_sub8 : in std_logic_vector( 16-1 downto 0 );
    im_sub8 : in std_logic_vector( 16-1 downto 0 );
    re_sub9 : in std_logic_vector( 16-1 downto 0 );
    im_sub9 : in std_logic_vector( 16-1 downto 0 );
    re_sub10 : in std_logic_vector( 16-1 downto 0 );
    im_sub10 : in std_logic_vector( 16-1 downto 0 );
    re_sub11 : in std_logic_vector( 16-1 downto 0 );
    im_sub11 : in std_logic_vector( 16-1 downto 0 );
    re_sub12 : in std_logic_vector( 16-1 downto 0 );
    im_sub12 : in std_logic_vector( 16-1 downto 0 );
    re_sub13 : in std_logic_vector( 16-1 downto 0 );
    im_sub13 : in std_logic_vector( 16-1 downto 0 );
    re_sub14 : in std_logic_vector( 16-1 downto 0 );
    im_sub14 : in std_logic_vector( 16-1 downto 0 );
    re_sub15 : in std_logic_vector( 16-1 downto 0 );
    im_sub15 : in std_logic_vector( 16-1 downto 0 );
    re_sub16 : in std_logic_vector( 16-1 downto 0 );
    im_sub16 : in std_logic_vector( 16-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_2 : in std_logic;
    ce_2 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    re : out std_logic_vector( 21-1 downto 0 );
    im : out std_logic_vector( 21-1 downto 0 );
    debug_re : out std_logic_vector( 16-1 downto 0 );
    debug_im : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_ifft_ofdm;
architecture structural of basic_dmt_ifft_ofdm is 
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
  signal mux1_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal delay5_q_net : std_logic_vector( 21-1 downto 0 );
  signal mux_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x15 : std_logic_vector( 16-1 downto 0 );
  signal dest_clk_net : std_logic;
  signal dest_ce_net : std_logic;
  signal mux1_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal src_ce_net : std_logic;
  signal dest_clk_net_x0 : std_logic;
  signal dest_ce_net_x0 : std_logic;
  signal mux_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x15 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal mux_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 1-1 downto 0 );
  signal relational_op_net : std_logic_vector( 1-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 4-1 downto 0 );
  signal clk_net : std_logic;
  signal constant4_op_net : std_logic_vector( 1-1 downto 0 );
  signal addsub_s_net : std_logic_vector( 1-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 1-1 downto 0 );
  signal convert_dout_net : std_logic_vector( 1-1 downto 0 );
  signal asserted_for_last_sample_q_net : std_logic_vector( 1-1 downto 0 );
  signal x1_for_fft_0_for_ifft_op_net : std_logic_vector( 1-1 downto 0 );
  signal timing_for_config_op_net : std_logic_vector( 1-1 downto 0 );
  signal delay7_q_net : std_logic_vector( 1-1 downto 0 );
  signal ce_net : std_logic;
  signal down_sample5_q_net : std_logic_vector( 1-1 downto 0 );
  signal fifo1_dout_net : std_logic_vector( 21-1 downto 0 );
  signal externel_slave_is_able_to_receive_data_op_net : std_logic_vector( 1-1 downto 0 );
  signal fast_fourier_transform_9_0_m_axis_data_tvalid_net : std_logic_vector( 1-1 downto 0 );
  signal fifo_empty_net : std_logic;
  signal reinterpret2_output_port_net : std_logic_vector( 21-1 downto 0 );
  signal re2_q_net : std_logic;
  signal fifo_full_net : std_logic;
  signal counter_op_net : std_logic_vector( 4-1 downto 0 );
  signal fifo_dout_net : std_logic_vector( 21-1 downto 0 );
  signal fast_fourier_transform_9_0_s_axis_config_tready_net : std_logic;
  signal fast_fourier_transform_9_0_s_axis_data_tready_net : std_logic;
  signal fast_fourier_transform_9_0_m_axis_data_tdata_xn_im_0_net : std_logic_vector( 21-1 downto 0 );
  signal fast_fourier_transform_9_0_m_axis_data_tuser_xk_index_net : std_logic_vector( 4-1 downto 0 );
  signal fifo1_percent_full_net : std_logic_vector( 4-1 downto 0 );
  signal fast_fourier_transform_9_0_event_frame_started_net : std_logic;
  signal fast_fourier_transform_9_0_event_tlast_unexpected_net : std_logic;
  signal fast_fourier_transform_9_0_event_tlast_missing_net : std_logic;
  signal fast_fourier_transform_9_0_event_data_in_channel_halt_net : std_logic;
  signal fast_fourier_transform_9_0_m_axis_data_tlast_net : std_logic;
  signal fast_fourier_transform_9_0_event_status_channel_halt_net : std_logic;
  signal fast_fourier_transform_9_0_event_data_out_channel_halt_net : std_logic;
  signal fifo1_full_net : std_logic;
  signal s_axis_data_tvalid1_q_net : std_logic;
  signal fast_fourier_transform_9_0_m_axis_data_tdata_xn_re_0_net : std_logic_vector( 21-1 downto 0 );
  signal s_axis_tdata_xn_re_output_port_net : std_logic_vector( 16-1 downto 0 );
  signal s_axis_tdata_xn_im_output_port_net : std_logic_vector( 16-1 downto 0 );
  signal aclken_q_net : std_logic;
  signal reinterpret3_output_port_net : std_logic_vector( 21-1 downto 0 );
  signal fifo1_empty_net : std_logic;
  signal mcode1_o2_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o3_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o11_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o12_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o5_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o6_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o15_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o16_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o7_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o8_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o10_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o13_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o9_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o14_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o4_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_o1_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o6_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o1_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o3_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o8_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o12_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o16_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o5_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o10_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o4_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o2_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o14_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o15_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o9_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o11_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o7_net : std_logic_vector( 16-1 downto 0 );
  signal mcode2_o13_net : std_logic_vector( 16-1 downto 0 );
  signal up_sample_q_net : std_logic_vector( 1-1 downto 0 );
  signal up_sample1_q_net : std_logic_vector( 1-1 downto 0 );
begin
  re <= delay4_q_net;
  im <= delay5_q_net;
  debug_re <= mux_y_net_x10;
  debug_im <= mux1_y_net_x11;
  mux_y_net_x11 <= re_sub1;
  mux1_y_net_x12 <= im_sub1;
  mux_y_net_x6 <= re_sub2;
  mux1_y_net_x6 <= im_sub2;
  mux_y_net_x5 <= re_sub3;
  mux1_y_net_x5 <= im_sub3;
  mux_y_net_x4 <= re_sub4;
  mux1_y_net_x4 <= im_sub4;
  mux_y_net_x3 <= re_sub5;
  mux1_y_net_x3 <= im_sub5;
  mux_y_net_x2 <= re_sub6;
  mux1_y_net_x2 <= im_sub6;
  mux_y_net_x1 <= re_sub7;
  mux1_y_net_x1 <= im_sub7;
  mux_y_net_x0 <= re_sub8;
  mux1_y_net_x0 <= im_sub8;
  mux_y_net <= re_sub9;
  mux1_y_net <= im_sub9;
  mux_y_net_x12 <= re_sub10;
  mux1_y_net_x13 <= im_sub10;
  mux_y_net_x13 <= re_sub11;
  mux1_y_net_x14 <= im_sub11;
  mux_y_net_x14 <= re_sub12;
  mux1_y_net_x15 <= im_sub12;
  mux_y_net_x15 <= re_sub13;
  mux1_y_net_x10 <= im_sub13;
  mux_y_net_x9 <= re_sub14;
  mux1_y_net_x9 <= im_sub14;
  mux_y_net_x8 <= re_sub15;
  mux1_y_net_x8 <= im_sub15;
  mux_y_net_x7 <= re_sub16;
  mux1_y_net_x7 <= im_sub16;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  dest_clk_net <= clk_2;
  dest_ce_net <= ce_2;
  dest_clk_net_x0 <= clk_4;
  dest_ce_net_x0 <= ce_4;
  clk_net <= clk_5;
  ce_net <= ce_5;
  x1_for_fft_0_for_ifft : entity xil_defaultlib.sysgen_constant_c4c1fd841d 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => x1_for_fft_0_for_ifft_op_net
  );
  addsub : entity xil_defaultlib.sysgen_addsub_a4a3676596 
  port map (
    clr => '0',
    a => timing_for_config_op_net,
    b => delay7_q_net,
    clk => clk_net,
    ce => ce_net,
    s => addsub_s_net
  );
  asserted_for_last_sample : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => relational_op_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q => asserted_for_last_sample_q_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_6047eef043 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  convert : entity xil_defaultlib.basic_dmt_xlconvert 
  generic map (
    bool_conversion => 1,
    din_arith => 1,
    din_bin_pt => 0,
    din_width => 1,
    dout_arith => 1,
    dout_bin_pt => 0,
    dout_width => 1,
    latency => 1,
    overflow => xlWrap,
    quantization => xlTruncate
  )
  port map (
    clr => '0',
    en => "1",
    din => addsub_s_net,
    clk => clk_net,
    ce => ce_net,
    dout => convert_dout_net
  );
  counter : entity xil_defaultlib.basic_dmt_xlcounter_limit 
  generic map (
    cnt_15_0 => 15,
    cnt_31_16 => 0,
    cnt_47_32 => 0,
    cnt_63_48 => 0,
    core_name0 => "basic_dmt_c_counter_binary_v12_0_0",
    count_limited => 0,
    op_arith => xlUnsigned,
    op_width => 4
  )
  port map (
    en => "1",
    rst => "0",
    clr => '0',
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    op => counter_op_net
  );
  delay4 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 8,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => fifo1_dout_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q => delay4_q_net
  );
  delay5 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 8,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => fifo_dout_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q => delay5_q_net
  );
  delay7 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => timing_for_config_op_net,
    clk => clk_net,
    ce => ce_net,
    q => delay7_q_net
  );
  down_sample5 : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlUnsigned,
    d_bin_pt => 0,
    d_width => 1,
    ds_ratio => 2,
    latency => 0,
    phase => 0,
    q_arith => xlUnsigned,
    q_bin_pt => 0,
    q_width => 1
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => fast_fourier_transform_9_0_m_axis_data_tvalid_net,
    src_clk => src_clk_net,
    src_ce => src_ce_net,
    dest_clk => dest_clk_net,
    dest_ce => dest_ce_net,
    q => down_sample5_q_net
  );
  externel_slave_is_able_to_receive_data : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => externel_slave_is_able_to_receive_data_op_net
  );
  fifo : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_2",
    data_count_width => 4,
    data_width => 21,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => reinterpret2_output_port_net,
    we => down_sample5_q_net(0),
    re => re2_q_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    we_ce => dest_ce_net,
    re_ce => dest_ce_net_x0,
    dout => fifo_dout_net,
    empty => fifo_empty_net,
    full => fifo_full_net
  );
  fifo1 : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_3",
    data_count_width => 4,
    data_width => 21,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => reinterpret3_output_port_net,
    we => down_sample5_q_net(0),
    re => re2_q_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    we_ce => dest_ce_net,
    re_ce => dest_ce_net_x0,
    dout => fifo1_dout_net,
    empty => fifo1_empty_net,
    percent_full => fifo1_percent_full_net,
    full => fifo1_full_net
  );
  fast_fourier_transform_9_0 : entity xil_defaultlib.xlfast_fourier_transform_56afb6d1c1e51bed448a5501b8c5efcd 
  port map (
    s_axis_config_tdata_fwd_inv => x1_for_fft_0_for_ifft_op_net,
    s_axis_config_tvalid => convert_dout_net(0),
    s_axis_data_tdata_xn_im_0 => s_axis_tdata_xn_im_output_port_net,
    s_axis_data_tdata_xn_re_0 => s_axis_tdata_xn_re_output_port_net,
    s_axis_data_tvalid => s_axis_data_tvalid1_q_net,
    s_axis_data_tlast => asserted_for_last_sample_q_net(0),
    m_axis_data_tready => externel_slave_is_able_to_receive_data_op_net(0),
    en => aclken_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    s_axis_config_tready => fast_fourier_transform_9_0_s_axis_config_tready_net,
    s_axis_data_tready => fast_fourier_transform_9_0_s_axis_data_tready_net,
    m_axis_data_tdata_xn_im_0 => fast_fourier_transform_9_0_m_axis_data_tdata_xn_im_0_net,
    m_axis_data_tdata_xn_re_0 => fast_fourier_transform_9_0_m_axis_data_tdata_xn_re_0_net,
    m_axis_data_tuser_xk_index => fast_fourier_transform_9_0_m_axis_data_tuser_xk_index_net,
    m_axis_data_tvalid => fast_fourier_transform_9_0_m_axis_data_tvalid_net(0),
    m_axis_data_tlast => fast_fourier_transform_9_0_m_axis_data_tlast_net,
    event_frame_started => fast_fourier_transform_9_0_event_frame_started_net,
    event_tlast_unexpected => fast_fourier_transform_9_0_event_tlast_unexpected_net,
    event_tlast_missing => fast_fourier_transform_9_0_event_tlast_missing_net,
    event_data_in_channel_halt => fast_fourier_transform_9_0_event_data_in_channel_halt_net,
    event_status_channel_halt => fast_fourier_transform_9_0_event_status_channel_halt_net,
    event_data_out_channel_halt => fast_fourier_transform_9_0_event_data_out_channel_halt_net
  );
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_5f9845ca1e 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i1 => mux_y_net_x11,
    i2 => mux_y_net_x6,
    i3 => mux_y_net_x5,
    i4 => mux_y_net_x4,
    i5 => mux_y_net_x3,
    i6 => mux_y_net_x2,
    i7 => mux_y_net_x1,
    i8 => mux_y_net_x0,
    i9 => mux_y_net,
    i10 => mux_y_net_x12,
    i11 => mux_y_net_x13,
    i12 => mux_y_net_x14,
    i13 => mux_y_net_x15,
    i14 => mux_y_net_x9,
    i15 => mux_y_net_x8,
    i16 => mux_y_net_x7,
    o1 => mcode1_o1_net,
    o2 => mcode1_o2_net,
    o3 => mcode1_o3_net,
    o4 => mcode1_o4_net,
    o5 => mcode1_o5_net,
    o6 => mcode1_o6_net,
    o7 => mcode1_o7_net,
    o8 => mcode1_o8_net,
    o9 => mcode1_o9_net,
    o10 => mcode1_o10_net,
    o11 => mcode1_o11_net,
    o12 => mcode1_o12_net,
    o13 => mcode1_o13_net,
    o14 => mcode1_o14_net,
    o15 => mcode1_o15_net,
    o16 => mcode1_o16_net
  );
  mcode2 : entity xil_defaultlib.sysgen_mcode_block_5f9845ca1e 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    i1 => mux1_y_net_x12,
    i2 => mux1_y_net_x6,
    i3 => mux1_y_net_x5,
    i4 => mux1_y_net_x4,
    i5 => mux1_y_net_x3,
    i6 => mux1_y_net_x2,
    i7 => mux1_y_net_x1,
    i8 => mux1_y_net_x0,
    i9 => mux1_y_net,
    i10 => mux1_y_net_x13,
    i11 => mux1_y_net_x14,
    i12 => mux1_y_net_x15,
    i13 => mux1_y_net_x10,
    i14 => mux1_y_net_x9,
    i15 => mux1_y_net_x8,
    i16 => mux1_y_net_x7,
    o1 => mcode2_o1_net,
    o2 => mcode2_o2_net,
    o3 => mcode2_o3_net,
    o4 => mcode2_o4_net,
    o5 => mcode2_o5_net,
    o6 => mcode2_o6_net,
    o7 => mcode2_o7_net,
    o8 => mcode2_o8_net,
    o9 => mcode2_o9_net,
    o10 => mcode2_o10_net,
    o11 => mcode2_o11_net,
    o12 => mcode2_o12_net,
    o13 => mcode2_o13_net,
    o14 => mcode2_o14_net,
    o15 => mcode2_o15_net,
    o16 => mcode2_o16_net
  );
  mux : entity xil_defaultlib.sysgen_mux_e10439f9cf 
  port map (
    clr => '0',
    sel => counter_op_net,
    d0 => mcode1_o1_net,
    d1 => mcode1_o2_net,
    d2 => mcode1_o3_net,
    d3 => mcode1_o4_net,
    d4 => mcode1_o5_net,
    d5 => mcode1_o6_net,
    d6 => mcode1_o7_net,
    d7 => mcode1_o8_net,
    d8 => mcode1_o9_net,
    d9 => mcode1_o10_net,
    d10 => mcode1_o11_net,
    d11 => mcode1_o12_net,
    d12 => mcode1_o13_net,
    d13 => mcode1_o14_net,
    d14 => mcode1_o15_net,
    d15 => mcode1_o16_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    y => mux_y_net_x10
  );
  mux1 : entity xil_defaultlib.sysgen_mux_e10439f9cf 
  port map (
    clr => '0',
    sel => counter_op_net,
    d0 => mcode2_o1_net,
    d1 => mcode2_o2_net,
    d2 => mcode2_o3_net,
    d3 => mcode2_o4_net,
    d4 => mcode2_o5_net,
    d5 => mcode2_o6_net,
    d6 => mcode2_o7_net,
    d7 => mcode2_o8_net,
    d8 => mcode2_o9_net,
    d9 => mcode2_o10_net,
    d10 => mcode2_o11_net,
    d11 => mcode2_o12_net,
    d12 => mcode2_o13_net,
    d13 => mcode2_o14_net,
    d14 => mcode2_o15_net,
    d15 => mcode2_o16_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    y => mux1_y_net_x11
  );
  reinterpret2 : entity xil_defaultlib.sysgen_reinterpret_f8109ce444 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    input_port => fast_fourier_transform_9_0_m_axis_data_tdata_xn_im_0_net,
    output_port => reinterpret2_output_port_net
  );
  reinterpret3 : entity xil_defaultlib.sysgen_reinterpret_f8109ce444 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    input_port => fast_fourier_transform_9_0_m_axis_data_tdata_xn_re_0_net,
    output_port => reinterpret3_output_port_net
  );
  relational : entity xil_defaultlib.sysgen_relational_c72c00b807 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => counter_op_net,
    b => constant1_op_net,
    op => relational_op_net
  );
  timing_for_config : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => timing_for_config_op_net
  );
  up_sample : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
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
    d => constant4_op_net,
    src_clk => dest_clk_net,
    src_ce => dest_ce_net,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net,
    q => up_sample_q_net
  );
  up_sample1 : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
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
    d => constant5_op_net,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net_x0,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net,
    q => up_sample1_q_net
  );
  aclken : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => up_sample_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q(0) => aclken_q_net
  );
  re2 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => constant3_op_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q(0) => re2_q_net
  );
  s_axis_data_tvalid1 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => up_sample1_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q(0) => s_axis_data_tvalid1_q_net
  );
  s_axis_tdata_xn_im : entity xil_defaultlib.sysgen_reinterpret_81a8d7a2c8 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    input_port => mux1_y_net_x11,
    output_port => s_axis_tdata_xn_im_output_port_net
  );
  s_axis_tdata_xn_re : entity xil_defaultlib.sysgen_reinterpret_81a8d7a2c8 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    input_port => mux_y_net_x10,
    output_port => s_axis_tdata_xn_re_output_port_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_IFFTaPIS/OFDMorDMT
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_ofdmordmt is
  port (
    re_sub1 : in std_logic_vector( 16-1 downto 0 );
    im_sub1 : in std_logic_vector( 16-1 downto 0 );
    re_sub2 : in std_logic_vector( 16-1 downto 0 );
    im_sub2 : in std_logic_vector( 16-1 downto 0 );
    re_sub3 : in std_logic_vector( 16-1 downto 0 );
    im_sub3 : in std_logic_vector( 16-1 downto 0 );
    re_sub4 : in std_logic_vector( 16-1 downto 0 );
    im_sub4 : in std_logic_vector( 16-1 downto 0 );
    re_sub5 : in std_logic_vector( 16-1 downto 0 );
    im_sub5 : in std_logic_vector( 16-1 downto 0 );
    re_sub6 : in std_logic_vector( 16-1 downto 0 );
    im_sub6 : in std_logic_vector( 16-1 downto 0 );
    re_sub7 : in std_logic_vector( 16-1 downto 0 );
    im_sub7 : in std_logic_vector( 16-1 downto 0 );
    re_sub8 : in std_logic_vector( 16-1 downto 0 );
    im_sub8 : in std_logic_vector( 16-1 downto 0 );
    re_sub9 : in std_logic_vector( 16-1 downto 0 );
    im_sub9 : in std_logic_vector( 16-1 downto 0 );
    re_sub10 : in std_logic_vector( 16-1 downto 0 );
    im_sub10 : in std_logic_vector( 16-1 downto 0 );
    re_sub11 : in std_logic_vector( 16-1 downto 0 );
    im_sub11 : in std_logic_vector( 16-1 downto 0 );
    re_sub12 : in std_logic_vector( 16-1 downto 0 );
    im_sub12 : in std_logic_vector( 16-1 downto 0 );
    re_sub13 : in std_logic_vector( 16-1 downto 0 );
    im_sub13 : in std_logic_vector( 16-1 downto 0 );
    re_sub14 : in std_logic_vector( 16-1 downto 0 );
    im_sub14 : in std_logic_vector( 16-1 downto 0 );
    re_sub15 : in std_logic_vector( 16-1 downto 0 );
    im_sub15 : in std_logic_vector( 16-1 downto 0 );
    re_sub16 : in std_logic_vector( 16-1 downto 0 );
    im_sub16 : in std_logic_vector( 16-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_2 : in std_logic;
    ce_2 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    re : out std_logic_vector( 21-1 downto 0 );
    im : out std_logic_vector( 21-1 downto 0 );
    debug_re : out std_logic_vector( 16-1 downto 0 );
    debug_im : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_ofdmordmt;
architecture structural of basic_dmt_ofdmordmt is 
  signal mux1_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay5_q_net : std_logic_vector( 21-1 downto 0 );
  signal mux1_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x15 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal src_ce_net : std_logic;
  signal dest_ce_net : std_logic;
  signal mux1_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal dest_ce_net_x0 : std_logic;
  signal ce_net : std_logic;
  signal mux1_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal dest_clk_net_x0 : std_logic;
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal clk_net : std_logic;
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal dest_clk_net : std_logic;
  signal mux1_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x15 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal mux_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x7 : std_logic_vector( 16-1 downto 0 );
begin
  re <= delay4_q_net;
  im <= delay5_q_net;
  debug_re <= mux_y_net_x14;
  debug_im <= mux1_y_net_x15;
  mux_y_net_x13 <= re_sub1;
  mux1_y_net_x14 <= im_sub1;
  mux_y_net_x6 <= re_sub2;
  mux1_y_net_x11 <= im_sub2;
  mux_y_net_x5 <= re_sub3;
  mux1_y_net_x5 <= im_sub3;
  mux_y_net_x4 <= re_sub4;
  mux1_y_net_x4 <= im_sub4;
  mux_y_net_x3 <= re_sub5;
  mux1_y_net_x3 <= im_sub5;
  mux_y_net_x2 <= re_sub6;
  mux1_y_net_x2 <= im_sub6;
  mux_y_net_x1 <= re_sub7;
  mux1_y_net_x1 <= im_sub7;
  mux_y_net_x0 <= re_sub8;
  mux1_y_net_x0 <= im_sub8;
  mux_y_net <= re_sub9;
  mux1_y_net <= im_sub9;
  mux_y_net_x12 <= re_sub10;
  mux1_y_net_x13 <= im_sub10;
  mux_y_net_x11 <= re_sub11;
  mux1_y_net_x12 <= im_sub11;
  mux_y_net_x15 <= re_sub12;
  mux1_y_net_x10 <= im_sub12;
  mux_y_net_x10 <= re_sub13;
  mux1_y_net_x9 <= im_sub13;
  mux_y_net_x9 <= re_sub14;
  mux1_y_net_x8 <= im_sub14;
  mux_y_net_x8 <= re_sub15;
  mux1_y_net_x7 <= im_sub15;
  mux_y_net_x7 <= re_sub16;
  mux1_y_net_x6 <= im_sub16;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  dest_clk_net <= clk_2;
  dest_ce_net <= ce_2;
  dest_clk_net_x0 <= clk_4;
  dest_ce_net_x0 <= ce_4;
  clk_net <= clk_5;
  ce_net <= ce_5;
  ifft_ofdm : entity xil_defaultlib.basic_dmt_ifft_ofdm 
  port map (
    re_sub1 => mux_y_net_x13,
    im_sub1 => mux1_y_net_x14,
    re_sub2 => mux_y_net_x6,
    im_sub2 => mux1_y_net_x11,
    re_sub3 => mux_y_net_x5,
    im_sub3 => mux1_y_net_x5,
    re_sub4 => mux_y_net_x4,
    im_sub4 => mux1_y_net_x4,
    re_sub5 => mux_y_net_x3,
    im_sub5 => mux1_y_net_x3,
    re_sub6 => mux_y_net_x2,
    im_sub6 => mux1_y_net_x2,
    re_sub7 => mux_y_net_x1,
    im_sub7 => mux1_y_net_x1,
    re_sub8 => mux_y_net_x0,
    im_sub8 => mux1_y_net_x0,
    re_sub9 => mux_y_net,
    im_sub9 => mux1_y_net,
    re_sub10 => mux_y_net_x12,
    im_sub10 => mux1_y_net_x13,
    re_sub11 => mux_y_net_x11,
    im_sub11 => mux1_y_net_x12,
    re_sub12 => mux_y_net_x15,
    im_sub12 => mux1_y_net_x10,
    re_sub13 => mux_y_net_x10,
    im_sub13 => mux1_y_net_x9,
    re_sub14 => mux_y_net_x9,
    im_sub14 => mux1_y_net_x8,
    re_sub15 => mux_y_net_x8,
    im_sub15 => mux1_y_net_x7,
    re_sub16 => mux_y_net_x7,
    im_sub16 => mux1_y_net_x6,
    clk_1 => src_clk_net,
    ce_1 => src_ce_net,
    clk_2 => dest_clk_net,
    ce_2 => dest_ce_net,
    clk_4 => dest_clk_net_x0,
    ce_4 => dest_ce_net_x0,
    clk_5 => clk_net,
    ce_5 => ce_net,
    re => delay4_q_net,
    im => delay5_q_net,
    debug_re => mux_y_net_x14,
    debug_im => mux1_y_net_x15
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_IFFTaPIS
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_sysgen_ifftapis is
  port (
    re_sub1 : in std_logic_vector( 16-1 downto 0 );
    im_sub1 : in std_logic_vector( 16-1 downto 0 );
    re_sub2 : in std_logic_vector( 16-1 downto 0 );
    im_sub2 : in std_logic_vector( 16-1 downto 0 );
    re_sub3 : in std_logic_vector( 16-1 downto 0 );
    im_sub3 : in std_logic_vector( 16-1 downto 0 );
    re_sub4 : in std_logic_vector( 16-1 downto 0 );
    im_sub4 : in std_logic_vector( 16-1 downto 0 );
    re_sub5 : in std_logic_vector( 16-1 downto 0 );
    im_sub5 : in std_logic_vector( 16-1 downto 0 );
    re_sub6 : in std_logic_vector( 16-1 downto 0 );
    im_sub6 : in std_logic_vector( 16-1 downto 0 );
    re_sub7 : in std_logic_vector( 16-1 downto 0 );
    im_sub7 : in std_logic_vector( 16-1 downto 0 );
    re_sub8 : in std_logic_vector( 16-1 downto 0 );
    im_sub8 : in std_logic_vector( 16-1 downto 0 );
    re_sub9 : in std_logic_vector( 16-1 downto 0 );
    im_sub9 : in std_logic_vector( 16-1 downto 0 );
    re_sub10 : in std_logic_vector( 16-1 downto 0 );
    im_sub10 : in std_logic_vector( 16-1 downto 0 );
    re_sub11 : in std_logic_vector( 16-1 downto 0 );
    im_sub11 : in std_logic_vector( 16-1 downto 0 );
    re_sub12 : in std_logic_vector( 16-1 downto 0 );
    im_sub12 : in std_logic_vector( 16-1 downto 0 );
    re_sub13 : in std_logic_vector( 16-1 downto 0 );
    im_sub13 : in std_logic_vector( 16-1 downto 0 );
    re_sub14 : in std_logic_vector( 16-1 downto 0 );
    im_sub14 : in std_logic_vector( 16-1 downto 0 );
    re_sub15 : in std_logic_vector( 16-1 downto 0 );
    im_sub15 : in std_logic_vector( 16-1 downto 0 );
    re_sub16 : in std_logic_vector( 16-1 downto 0 );
    im_sub16 : in std_logic_vector( 16-1 downto 0 );
    sgframestart : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_2 : in std_logic;
    ce_2 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    re : out std_logic_vector( 21-1 downto 0 );
    im : out std_logic_vector( 21-1 downto 0 );
    db_aft_frame_re : out std_logic_vector( 16-1 downto 0 );
    db_aft_frame_im : out std_logic_vector( 16-1 downto 0 );
    db_aft_fft_re : out std_logic_vector( 21-1 downto 0 );
    db_aft_fft_im : out std_logic_vector( 21-1 downto 0 );
    db_aft_gi_re : out std_logic_vector( 21-1 downto 0 );
    db_aft_gi_im : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_sysgen_ifftapis;
architecture structural of basic_dmt_sysgen_ifftapis is 
  signal down_sample_q_net : std_logic_vector( 21-1 downto 0 );
  signal down_sample1_q_net : std_logic_vector( 21-1 downto 0 );
  signal mux_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal delay4_q_net_x0 : std_logic_vector( 21-1 downto 0 );
  signal mux1_y_net_x15 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal mcode_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal mux1_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal mcode_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal mux_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal delay5_q_net_x0 : std_logic_vector( 21-1 downto 0 );
  signal mux_y_net_x15 : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net_x0 : std_logic;
  signal clk_net : std_logic;
  signal src_clk_net : std_logic;
  signal mux1_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal dest_ce_net : std_logic;
  signal dest_clk_net_x0 : std_logic;
  signal dest_clk_net : std_logic;
  signal clk_net_x0 : std_logic;
  signal mcode1_stateo_net : std_logic_vector( 2-1 downto 0 );
  signal assert5_dout_net : std_logic_vector( 1-1 downto 0 );
  signal mux_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal fifo1_dout_net : std_logic_vector( 21-1 downto 0 );
  signal mux1_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mcode1_framestart_net : std_logic_vector( 1-1 downto 0 );
  signal assert1_dout_net : std_logic_vector( 8-1 downto 0 );
  signal ce_net : std_logic;
  signal mcode_pop_net : std_logic_vector( 1-1 downto 0 );
  signal mcode1_popeno_net : std_logic_vector( 1-1 downto 0 );
  signal src_ce_net : std_logic;
  signal dest_ce_net_x0 : std_logic;
  signal src_ce_net_x0 : std_logic;
  signal assert_dout_net : std_logic_vector( 2-1 downto 0 );
  signal mcode1_loopcounto_net : std_logic_vector( 8-1 downto 0 );
  signal ce_net_x0 : std_logic;
  signal fifo2_full_net : std_logic;
  signal delay3_q_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_push_net : std_logic;
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
  signal fifo1_full_net : std_logic;
  signal fifo1_dcount_net : std_logic_vector( 7-1 downto 0 );
  signal fifo2_empty_net : std_logic;
  signal delay2_q_net : std_logic_vector( 8-1 downto 0 );
  signal delay6_q_net : std_logic_vector( 1-1 downto 0 );
  signal delay1_q_net : std_logic_vector( 2-1 downto 0 );
  signal up_sample3_q_net : std_logic_vector( 1-1 downto 0 );
  signal fifo1_empty_net : std_logic;
  signal mcode1_pop_net : std_logic_vector( 1-1 downto 0 );
  signal delay5_q_net : std_logic;
  signal fifo2_dout_net : std_logic_vector( 21-1 downto 0 );
  signal up_sample1_q_net : std_logic_vector( 21-1 downto 0 );
  signal up_sample2_q_net : std_logic_vector( 21-1 downto 0 );
begin
  re <= down_sample_q_net;
  im <= down_sample1_q_net;
  db_aft_frame_re <= mux_y_net_x12;
  db_aft_frame_im <= mux1_y_net_x12;
  db_aft_fft_re <= delay4_q_net_x0;
  db_aft_fft_im <= delay5_q_net_x0;
  db_aft_gi_re <= mcode_out_re_net;
  db_aft_gi_im <= mcode_out_im_net;
  mux_y_net_x11 <= re_sub1;
  mux1_y_net_x11 <= im_sub1;
  mux_y_net_x3 <= re_sub2;
  mux1_y_net_x3 <= im_sub2;
  mux_y_net_x2 <= re_sub3;
  mux1_y_net_x2 <= im_sub3;
  mux_y_net_x1 <= re_sub4;
  mux1_y_net_x1 <= im_sub4;
  mux_y_net_x0 <= re_sub5;
  mux1_y_net_x0 <= im_sub5;
  mux_y_net <= re_sub6;
  mux1_y_net <= im_sub6;
  mux_y_net_x15 <= re_sub7;
  mux1_y_net_x15 <= im_sub7;
  mux_y_net_x14 <= re_sub8;
  mux1_y_net_x14 <= im_sub8;
  mux_y_net_x13 <= re_sub9;
  mux1_y_net_x13 <= im_sub9;
  mux_y_net_x10 <= re_sub10;
  mux1_y_net_x10 <= im_sub10;
  mux_y_net_x9 <= re_sub11;
  mux1_y_net_x9 <= im_sub11;
  mux_y_net_x8 <= re_sub12;
  mux1_y_net_x8 <= im_sub12;
  mux_y_net_x7 <= re_sub13;
  mux1_y_net_x7 <= im_sub13;
  mux_y_net_x6 <= re_sub14;
  mux1_y_net_x6 <= im_sub14;
  mux_y_net_x5 <= re_sub15;
  mux1_y_net_x5 <= im_sub15;
  mux_y_net_x4 <= re_sub16;
  mux1_y_net_x4 <= im_sub16;
  mcode1_framestart_net <= sgframestart;
  src_clk_net_x0 <= clk_1;
  src_ce_net <= ce_1;
  dest_clk_net <= clk_2;
  dest_ce_net <= ce_2;
  dest_clk_net_x0 <= clk_4;
  dest_ce_net_x0 <= ce_4;
  clk_net <= clk_5;
  ce_net <= ce_5;
  clk_net_x0 <= clk_14;
  ce_net_x0 <= ce_14;
  src_clk_net <= clk_64;
  src_ce_net_x0 <= ce_64;
  guard_interval_x0 : entity xil_defaultlib.basic_dmt_guard_interval 
  port map (
    re_in => delay4_q_net_x0,
    im_in => delay5_q_net_x0,
    sgframestart => mcode1_framestart_net,
    clk_1 => src_clk_net_x0,
    ce_1 => src_ce_net,
    clk_4 => dest_clk_net_x0,
    ce_4 => dest_ce_net_x0,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net_x0,
    re => mcode_out_re_net,
    im => mcode_out_im_net,
    pop => mcode_pop_net
  );
  ofdmordmt_x1 : entity xil_defaultlib.basic_dmt_ofdmordmt 
  port map (
    re_sub1 => mux_y_net_x11,
    im_sub1 => mux1_y_net_x11,
    re_sub2 => mux_y_net_x3,
    im_sub2 => mux1_y_net_x3,
    re_sub3 => mux_y_net_x2,
    im_sub3 => mux1_y_net_x2,
    re_sub4 => mux_y_net_x1,
    im_sub4 => mux1_y_net_x1,
    re_sub5 => mux_y_net_x0,
    im_sub5 => mux1_y_net_x0,
    re_sub6 => mux_y_net,
    im_sub6 => mux1_y_net,
    re_sub7 => mux_y_net_x15,
    im_sub7 => mux1_y_net_x15,
    re_sub8 => mux_y_net_x14,
    im_sub8 => mux1_y_net_x14,
    re_sub9 => mux_y_net_x13,
    im_sub9 => mux1_y_net_x13,
    re_sub10 => mux_y_net_x10,
    im_sub10 => mux1_y_net_x10,
    re_sub11 => mux_y_net_x9,
    im_sub11 => mux1_y_net_x9,
    re_sub12 => mux_y_net_x8,
    im_sub12 => mux1_y_net_x8,
    re_sub13 => mux_y_net_x7,
    im_sub13 => mux1_y_net_x7,
    re_sub14 => mux_y_net_x6,
    im_sub14 => mux1_y_net_x6,
    re_sub15 => mux_y_net_x5,
    im_sub15 => mux1_y_net_x5,
    re_sub16 => mux_y_net_x4,
    im_sub16 => mux1_y_net_x4,
    clk_1 => src_clk_net_x0,
    ce_1 => src_ce_net,
    clk_2 => dest_clk_net,
    ce_2 => dest_ce_net,
    clk_4 => dest_clk_net_x0,
    ce_4 => dest_ce_net_x0,
    clk_5 => clk_net,
    ce_5 => ce_net,
    re => delay4_q_net_x0,
    im => delay5_q_net_x0,
    debug_re => mux_y_net_x12,
    debug_im => mux1_y_net_x12
  );
  assert_x0 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 2,
    dout_width => 2
  )
  port map (
    din => mcode1_stateo_net,
    dout => assert_dout_net
  );
  assert1 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode1_loopcounto_net,
    dout => assert1_dout_net
  );
  assert5 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 1,
    dout_width => 1
  )
  port map (
    din => mcode1_popeno_net,
    dout => assert5_dout_net
  );
  down_sample : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 21,
    ds_ratio => 14,
    latency => 1,
    phase => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 21
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => fifo1_dout_net,
    src_clk => src_clk_net_x0,
    src_ce => src_ce_net,
    dest_clk => clk_net_x0,
    dest_ce => ce_net_x0,
    q => down_sample_q_net
  );
  down_sample1 : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 21,
    ds_ratio => 14,
    latency => 1,
    phase => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 21
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => fifo2_dout_net,
    src_clk => src_clk_net_x0,
    src_ce => src_ce_net,
    dest_clk => clk_net_x0,
    dest_ce => ce_net_x0,
    q => down_sample1_q_net
  );
  fifo1 : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_0",
    data_count_width => 7,
    data_width => 21,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => delay3_q_net,
    we => mcode1_push_net,
    re => delay5_q_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    we_ce => src_ce_net,
    re_ce => src_ce_net,
    dout => fifo1_dout_net,
    empty => fifo1_empty_net,
    full => fifo1_full_net,
    dcount => fifo1_dcount_net
  );
  fifo2 : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_1",
    data_count_width => 7,
    data_width => 21,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => delay4_q_net,
    we => mcode1_push_net,
    re => delay5_q_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    we_ce => src_ce_net,
    re_ce => src_ce_net,
    dout => fifo2_dout_net,
    empty => fifo2_empty_net,
    full => fifo2_full_net
  );
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_08b11b7c87 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    pushen => up_sample3_q_net,
    statei => delay1_q_net,
    loopcounti => delay2_q_net,
    popeni => delay6_q_net,
    push(0) => mcode1_push_net,
    pop => mcode1_pop_net,
    stateo => mcode1_stateo_net,
    loopcounto => mcode1_loopcounto_net,
    popeno => mcode1_popeno_net
  );
  up_sample1 : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 21,
    latency => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 21
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    d => mcode_out_re_net,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net_x0,
    dest_clk => src_clk_net_x0,
    dest_ce => src_ce_net,
    q => up_sample1_q_net
  );
  up_sample2 : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 21,
    latency => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 21
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    d => mcode_out_im_net,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net_x0,
    dest_clk => src_clk_net_x0,
    dest_ce => src_ce_net,
    q => up_sample2_q_net
  );
  up_sample3 : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
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
    d => mcode_pop_net,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net_x0,
    dest_clk => src_clk_net_x0,
    dest_ce => src_ce_net,
    q => up_sample3_q_net
  );
  delay1 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 2
  )
  port map (
    en => '1',
    rst => '1',
    d => assert_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay1_q_net
  );
  delay2 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert1_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay2_q_net
  );
  delay3 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => up_sample1_q_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay3_q_net
  );
  delay4 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => up_sample2_q_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay4_q_net
  );
  delay5 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 13,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => mcode1_pop_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q(0) => delay5_q_net
  );
  delay6 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => assert5_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay6_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM1
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam1 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam1;
architecture structural of basic_dmt_16_qam1 is 
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal slice30_y_net : std_logic_vector( 4-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal src_ce_net : std_logic;
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice30_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice30_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM10
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam10 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam10;
architecture structural of basic_dmt_16_qam10 is 
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_ce_net : std_logic;
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal slice13_y_net : std_logic_vector( 4-1 downto 0 );
  signal src_clk_net : std_logic;
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice13_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice13_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM11
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam11 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam11;
architecture structural of basic_dmt_16_qam11 is 
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal slice14_y_net : std_logic_vector( 4-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal src_ce_net : std_logic;
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice14_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice14_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM12
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam12 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam12;
architecture structural of basic_dmt_16_qam12 is 
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal slice12_y_net : std_logic_vector( 4-1 downto 0 );
  signal src_ce_net : std_logic;
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal src_clk_net : std_logic;
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice12_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice12_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM13
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam13 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam13;
architecture structural of basic_dmt_16_qam13 is 
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal slice11_y_net : std_logic_vector( 4-1 downto 0 );
  signal src_ce_net : std_logic;
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice11_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice11_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM14
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam14 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam14;
architecture structural of basic_dmt_16_qam14 is 
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal slice10_y_net : std_logic_vector( 4-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice10_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice10_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM15
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam15 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam15;
architecture structural of basic_dmt_16_qam15 is 
  signal src_ce_net : std_logic;
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal slice8_y_net : std_logic_vector( 4-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice8_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice8_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM16
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam16 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam16;
architecture structural of basic_dmt_16_qam16 is 
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal slice9_y_net : std_logic_vector( 4-1 downto 0 );
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice9_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice9_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM2
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam2 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam2;
architecture structural of basic_dmt_16_qam2 is 
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal src_ce_net : std_logic;
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal slice29_y_net : std_logic_vector( 4-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice29_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice29_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM3
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam3 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam3;
architecture structural of basic_dmt_16_qam3 is 
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal src_ce_net : std_logic;
  signal slice7_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice7_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice7_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM4
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam4 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam4;
architecture structural of basic_dmt_16_qam4 is 
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal slice6_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice6_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice6_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM5
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam5 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam5;
architecture structural of basic_dmt_16_qam5 is 
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal src_ce_net : std_logic;
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal slice5_y_net : std_logic_vector( 4-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice5_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice5_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM6
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam6 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam6;
architecture structural of basic_dmt_16_qam6 is 
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal slice4_y_net : std_logic_vector( 4-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice4_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice4_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM7
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam7 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam7;
architecture structural of basic_dmt_16_qam7 is 
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal slice3_y_net : std_logic_vector( 4-1 downto 0 );
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal src_ce_net : std_logic;
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal src_clk_net : std_logic;
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice3_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice3_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM8
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam8 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam8;
architecture structural of basic_dmt_16_qam8 is 
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal slice2_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice2_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice2_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation/16-QAM9
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_16_qam9 is
  port (
    in1 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    out2 : out std_logic_vector( 16-1 downto 0 );
    out3 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_16_qam9;
architecture structural of basic_dmt_16_qam9 is 
  signal bitbasher_c_net : std_logic_vector( 2-1 downto 0 );
  signal bitbasher_b_net : std_logic_vector( 2-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant2_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant6_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant7_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 16-1 downto 0 );
  signal constant9_op_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal slice1_y_net : std_logic_vector( 4-1 downto 0 );
begin
  out2 <= mux_y_net;
  out3 <= mux1_y_net;
  slice1_y_net <= in1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  bitbasher : entity xil_defaultlib.sysgen_bitbasher_b99de7e501 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => slice1_y_net,
    b => bitbasher_b_net,
    c => bitbasher_c_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant2 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant2_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_7b97c80a71 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  constant6 : entity xil_defaultlib.sysgen_constant_e75a4c2335 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant6_op_net
  );
  constant7 : entity xil_defaultlib.sysgen_constant_1a3f20e021 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant7_op_net
  );
  constant9 : entity xil_defaultlib.sysgen_constant_9986852557 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant9_op_net
  );
  mux : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_b_net,
    d0 => constant1_op_net,
    d1 => constant2_op_net,
    d2 => constant3_op_net,
    d3 => constant4_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_1870d2b50d 
  port map (
    clr => '0',
    sel => bitbasher_c_net,
    d0 => constant9_op_net,
    d1 => constant5_op_net,
    d2 => constant6_op_net,
    d3 => constant7_op_net,
    clk => src_clk_net,
    ce => src_ce_net,
    y => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_Modulation
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_sysgen_modulation is
  port (
    sub1 : in std_logic_vector( 4-1 downto 0 );
    sub2 : in std_logic_vector( 4-1 downto 0 );
    sub3 : in std_logic_vector( 4-1 downto 0 );
    sub4 : in std_logic_vector( 4-1 downto 0 );
    sub5 : in std_logic_vector( 4-1 downto 0 );
    sub6 : in std_logic_vector( 4-1 downto 0 );
    sub7 : in std_logic_vector( 4-1 downto 0 );
    sub8 : in std_logic_vector( 4-1 downto 0 );
    sub9 : in std_logic_vector( 4-1 downto 0 );
    sub10 : in std_logic_vector( 4-1 downto 0 );
    sub11 : in std_logic_vector( 4-1 downto 0 );
    sub12 : in std_logic_vector( 4-1 downto 0 );
    sub13 : in std_logic_vector( 4-1 downto 0 );
    sub14 : in std_logic_vector( 4-1 downto 0 );
    sub15 : in std_logic_vector( 4-1 downto 0 );
    sub16 : in std_logic_vector( 4-1 downto 0 );
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    re_sub1 : out std_logic_vector( 16-1 downto 0 );
    im_sub1 : out std_logic_vector( 16-1 downto 0 );
    re_sub2 : out std_logic_vector( 16-1 downto 0 );
    im_sub2 : out std_logic_vector( 16-1 downto 0 );
    re_sub3 : out std_logic_vector( 16-1 downto 0 );
    im_sub3 : out std_logic_vector( 16-1 downto 0 );
    re_sub4 : out std_logic_vector( 16-1 downto 0 );
    im_sub4 : out std_logic_vector( 16-1 downto 0 );
    re_sub5 : out std_logic_vector( 16-1 downto 0 );
    im_sub5 : out std_logic_vector( 16-1 downto 0 );
    re_sub6 : out std_logic_vector( 16-1 downto 0 );
    im_sub6 : out std_logic_vector( 16-1 downto 0 );
    re_sub7 : out std_logic_vector( 16-1 downto 0 );
    im_sub7 : out std_logic_vector( 16-1 downto 0 );
    re_sub8 : out std_logic_vector( 16-1 downto 0 );
    im_sub8 : out std_logic_vector( 16-1 downto 0 );
    re_sub9 : out std_logic_vector( 16-1 downto 0 );
    im_sub9 : out std_logic_vector( 16-1 downto 0 );
    re_sub10 : out std_logic_vector( 16-1 downto 0 );
    im_sub10 : out std_logic_vector( 16-1 downto 0 );
    re_sub11 : out std_logic_vector( 16-1 downto 0 );
    im_sub11 : out std_logic_vector( 16-1 downto 0 );
    re_sub12 : out std_logic_vector( 16-1 downto 0 );
    im_sub12 : out std_logic_vector( 16-1 downto 0 );
    re_sub13 : out std_logic_vector( 16-1 downto 0 );
    im_sub13 : out std_logic_vector( 16-1 downto 0 );
    re_sub14 : out std_logic_vector( 16-1 downto 0 );
    im_sub14 : out std_logic_vector( 16-1 downto 0 );
    re_sub15 : out std_logic_vector( 16-1 downto 0 );
    im_sub15 : out std_logic_vector( 16-1 downto 0 );
    re_sub16 : out std_logic_vector( 16-1 downto 0 );
    im_sub16 : out std_logic_vector( 16-1 downto 0 )
  );
end basic_dmt_sysgen_modulation;
architecture structural of basic_dmt_sysgen_modulation is 
  signal mux_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal slice4_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice2_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice3_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux1_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal slice5_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice1_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal slice13_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice14_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice6_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice11_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice10_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux1_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal slice8_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice9_y_net : std_logic_vector( 4-1 downto 0 );
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal slice12_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal slice30_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice29_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice7_y_net : std_logic_vector( 4-1 downto 0 );
begin
  re_sub1 <= mux_y_net_x13;
  im_sub1 <= mux1_y_net_x14;
  re_sub2 <= mux_y_net_x6;
  im_sub2 <= mux1_y_net_x6;
  re_sub3 <= mux_y_net_x5;
  im_sub3 <= mux1_y_net_x5;
  re_sub4 <= mux_y_net_x4;
  im_sub4 <= mux1_y_net_x4;
  re_sub5 <= mux_y_net_x3;
  im_sub5 <= mux1_y_net_x3;
  re_sub6 <= mux_y_net_x2;
  im_sub6 <= mux1_y_net_x2;
  re_sub7 <= mux_y_net_x1;
  im_sub7 <= mux1_y_net_x1;
  re_sub8 <= mux_y_net_x0;
  im_sub8 <= mux1_y_net_x0;
  re_sub9 <= mux_y_net;
  im_sub9 <= mux1_y_net;
  re_sub10 <= mux_y_net_x12;
  im_sub10 <= mux1_y_net_x13;
  re_sub11 <= mux_y_net_x11;
  im_sub11 <= mux1_y_net_x12;
  re_sub12 <= mux_y_net_x10;
  im_sub12 <= mux1_y_net_x11;
  re_sub13 <= mux_y_net_x9;
  im_sub13 <= mux1_y_net_x10;
  re_sub14 <= mux_y_net_x8;
  im_sub14 <= mux1_y_net_x9;
  re_sub15 <= mux_y_net_x14;
  im_sub15 <= mux1_y_net_x8;
  re_sub16 <= mux_y_net_x7;
  im_sub16 <= mux1_y_net_x7;
  slice30_y_net <= sub1;
  slice29_y_net <= sub2;
  slice7_y_net <= sub3;
  slice6_y_net <= sub4;
  slice5_y_net <= sub5;
  slice4_y_net <= sub6;
  slice3_y_net <= sub7;
  slice2_y_net <= sub8;
  slice1_y_net <= sub9;
  slice13_y_net <= sub10;
  slice14_y_net <= sub11;
  slice12_y_net <= sub12;
  slice11_y_net <= sub13;
  slice10_y_net <= sub14;
  slice8_y_net <= sub15;
  slice9_y_net <= sub16;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  x16_qam1 : entity xil_defaultlib.basic_dmt_16_qam1 
  port map (
    in1 => slice30_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x13,
    out3 => mux1_y_net_x14
  );
  x16_qam10 : entity xil_defaultlib.basic_dmt_16_qam10 
  port map (
    in1 => slice13_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x12,
    out3 => mux1_y_net_x13
  );
  x16_qam11 : entity xil_defaultlib.basic_dmt_16_qam11 
  port map (
    in1 => slice14_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x11,
    out3 => mux1_y_net_x12
  );
  x16_qam12 : entity xil_defaultlib.basic_dmt_16_qam12 
  port map (
    in1 => slice12_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x10,
    out3 => mux1_y_net_x11
  );
  x16_qam13 : entity xil_defaultlib.basic_dmt_16_qam13 
  port map (
    in1 => slice11_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x9,
    out3 => mux1_y_net_x10
  );
  x16_qam14 : entity xil_defaultlib.basic_dmt_16_qam14 
  port map (
    in1 => slice10_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x8,
    out3 => mux1_y_net_x9
  );
  x16_qam15 : entity xil_defaultlib.basic_dmt_16_qam15 
  port map (
    in1 => slice8_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x14,
    out3 => mux1_y_net_x8
  );
  x16_qam16 : entity xil_defaultlib.basic_dmt_16_qam16 
  port map (
    in1 => slice9_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x7,
    out3 => mux1_y_net_x7
  );
  x16_qam2 : entity xil_defaultlib.basic_dmt_16_qam2 
  port map (
    in1 => slice29_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x6,
    out3 => mux1_y_net_x6
  );
  x16_qam3 : entity xil_defaultlib.basic_dmt_16_qam3 
  port map (
    in1 => slice7_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x5,
    out3 => mux1_y_net_x5
  );
  x16_qam4 : entity xil_defaultlib.basic_dmt_16_qam4 
  port map (
    in1 => slice6_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x4,
    out3 => mux1_y_net_x4
  );
  x16_qam5 : entity xil_defaultlib.basic_dmt_16_qam5 
  port map (
    in1 => slice5_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x3,
    out3 => mux1_y_net_x3
  );
  x16_qam6 : entity xil_defaultlib.basic_dmt_16_qam6 
  port map (
    in1 => slice4_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x2,
    out3 => mux1_y_net_x2
  );
  x16_qam7 : entity xil_defaultlib.basic_dmt_16_qam7 
  port map (
    in1 => slice3_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x1,
    out3 => mux1_y_net_x1
  );
  x16_qam8 : entity xil_defaultlib.basic_dmt_16_qam8 
  port map (
    in1 => slice2_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net_x0,
    out3 => mux1_y_net_x0
  );
  x16_qam9 : entity xil_defaultlib.basic_dmt_16_qam9 
  port map (
    in1 => slice1_y_net,
    clk_64 => src_clk_net,
    ce_64 => src_ce_net,
    out2 => mux_y_net,
    out3 => mux1_y_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_PIS/DelayVar/OFDM
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_ofdm is
  port (
    in1 : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    out1 : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_ofdm;
architecture structural of basic_dmt_ofdm is 
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal delay1_q_net : std_logic_vector( 1-1 downto 0 );
  signal delay7_q_net : std_logic_vector( 1-1 downto 0 );
begin
  out1 <= delay7_q_net;
  delay1_q_net <= in1;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  delay7 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 504,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => delay1_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => delay7_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_PIS/DelayVar
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_delayvar is
  port (
    in1 : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    out1 : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_delayvar;
architecture structural of basic_dmt_delayvar is 
  signal src_ce_net : std_logic;
  signal delay7_q_net : std_logic_vector( 1-1 downto 0 );
  signal delay1_q_net : std_logic_vector( 1-1 downto 0 );
  signal src_clk_net : std_logic;
begin
  out1 <= delay7_q_net;
  delay1_q_net <= in1;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  ofdm_x2 : entity xil_defaultlib.basic_dmt_ofdm 
  port map (
    in1 => delay1_q_net,
    clk_1 => src_clk_net,
    ce_1 => src_ce_net,
    out1 => delay7_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_PIS
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_sysgen_pis is
  port (
    bit_sub1 : in std_logic_vector( 4-1 downto 0 );
    bit_sub2 : in std_logic_vector( 4-1 downto 0 );
    bit_sub3 : in std_logic_vector( 4-1 downto 0 );
    bit_sub4 : in std_logic_vector( 4-1 downto 0 );
    bit_sub5 : in std_logic_vector( 4-1 downto 0 );
    bit_sub6 : in std_logic_vector( 4-1 downto 0 );
    bit_sub7 : in std_logic_vector( 4-1 downto 0 );
    bit_sub8 : in std_logic_vector( 4-1 downto 0 );
    bit_sub9 : in std_logic_vector( 4-1 downto 0 );
    bit_sub10 : in std_logic_vector( 4-1 downto 0 );
    bit_sub11 : in std_logic_vector( 4-1 downto 0 );
    bit_sub12 : in std_logic_vector( 4-1 downto 0 );
    bit_sub13 : in std_logic_vector( 4-1 downto 0 );
    bit_sub14 : in std_logic_vector( 4-1 downto 0 );
    bit_sub15 : in std_logic_vector( 4-1 downto 0 );
    bit_sub16 : in std_logic_vector( 4-1 downto 0 );
    sg_rev_framestart2 : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    bit : out std_logic_vector( 1-1 downto 0 );
    db_bef_fifo : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_sysgen_pis;
architecture structural of basic_dmt_sysgen_pis is 
  signal mcode12_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode15_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode9_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode5_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode16_y1_net : std_logic_vector( 4-1 downto 0 );
  signal src_clk_net : std_logic;
  signal mcode6_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode7_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode11_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode14_y1_net : std_logic_vector( 4-1 downto 0 );
  signal delay8_q_net : std_logic_vector( 1-1 downto 0 );
  signal down_sample17_q_net : std_logic_vector( 1-1 downto 0 );
  signal mcode8_y1_net : std_logic_vector( 4-1 downto 0 );
  signal delay1_q_net : std_logic_vector( 1-1 downto 0 );
  signal mcode2_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode13_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode3_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode4_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode10_y1_net : std_logic_vector( 4-1 downto 0 );
  signal src_ce_net_x0 : std_logic;
  signal assert1_dout_net : std_logic_vector( 1-1 downto 0 );
  signal assert2_dout_net : std_logic_vector( 8-1 downto 0 );
  signal mcode1_subcarcounto_net : std_logic_vector( 8-1 downto 0 );
  signal mcode1_enableo_net : std_logic_vector( 1-1 downto 0 );
  signal mcode1_subcaro_net : std_logic_vector( 8-1 downto 0 );
  signal assert4_dout_net : std_logic_vector( 8-1 downto 0 );
  signal mcode1_loopcounto_net : std_logic_vector( 8-1 downto 0 );
  signal assert5_dout_net : std_logic_vector( 2-1 downto 0 );
  signal mcode1_stateo_net : std_logic_vector( 2-1 downto 0 );
  signal mcode1_starto_net : std_logic_vector( 1-1 downto 0 );
  signal assert3_dout_net : std_logic_vector( 8-1 downto 0 );
  signal clk_net : std_logic;
  signal assert_dout_net : std_logic_vector( 1-1 downto 0 );
  signal delay7_q_net : std_logic_vector( 1-1 downto 0 );
  signal src_ce_net : std_logic;
  signal ce_net : std_logic;
  signal src_clk_net_x0 : std_logic;
  signal slice13_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice2_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice5_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice3_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice1_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice20_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice18_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice24_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice17_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice21_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice9_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice8_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice6_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice7_y_net : std_logic_vector( 4-1 downto 0 );
  signal concat_y_net : std_logic_vector( 64-1 downto 0 );
  signal slice19_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice4_y_net : std_logic_vector( 4-1 downto 0 );
  signal delay9_q_net : std_logic;
  signal fifo2_dout_net : std_logic_vector( 1-1 downto 0 );
  signal fifo2_dcount_net : std_logic_vector( 7-1 downto 0 );
  signal mcode1_push_net : std_logic_vector( 1-1 downto 0 );
  signal mcode1_pop_net : std_logic_vector( 1-1 downto 0 );
  signal fifo2_empty_net : std_logic;
  signal fifo2_full_net : std_logic;
  signal delay7_q_net_x0 : std_logic;
  signal delay1_q_net_x0 : std_logic_vector( 1-1 downto 0 );
  signal delay6_q_net : std_logic_vector( 2-1 downto 0 );
  signal parallel_to_serial_dout_net : std_logic_vector( 1-1 downto 0 );
  signal delay2_q_net : std_logic_vector( 1-1 downto 0 );
  signal delay5_q_net : std_logic_vector( 8-1 downto 0 );
  signal delay3_q_net : std_logic_vector( 8-1 downto 0 );
  signal delay4_q_net : std_logic_vector( 8-1 downto 0 );
begin
  bit <= down_sample17_q_net;
  db_bef_fifo <= delay8_q_net;
  mcode1_y1_net <= bit_sub1;
  mcode2_y1_net <= bit_sub2;
  mcode3_y1_net <= bit_sub3;
  mcode4_y1_net <= bit_sub4;
  mcode5_y1_net <= bit_sub5;
  mcode6_y1_net <= bit_sub6;
  mcode7_y1_net <= bit_sub7;
  mcode8_y1_net <= bit_sub8;
  mcode9_y1_net <= bit_sub9;
  mcode10_y1_net <= bit_sub10;
  mcode11_y1_net <= bit_sub11;
  mcode12_y1_net <= bit_sub12;
  mcode13_y1_net <= bit_sub13;
  mcode14_y1_net <= bit_sub14;
  mcode15_y1_net <= bit_sub15;
  mcode16_y1_net <= bit_sub16;
  delay1_q_net <= sg_rev_framestart2;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  clk_net <= clk_5;
  ce_net <= ce_5;
  src_clk_net_x0 <= clk_64;
  src_ce_net_x0 <= ce_64;
  delayvar_x1 : entity xil_defaultlib.basic_dmt_delayvar 
  port map (
    in1 => delay1_q_net,
    clk_1 => src_clk_net,
    ce_1 => src_ce_net,
    out1 => delay7_q_net
  );
  assert_x0 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 1,
    dout_width => 1
  )
  port map (
    din => mcode1_enableo_net,
    dout => assert_dout_net
  );
  assert1 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 1,
    dout_width => 1
  )
  port map (
    din => mcode1_starto_net,
    dout => assert1_dout_net
  );
  assert2 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode1_subcarcounto_net,
    dout => assert2_dout_net
  );
  assert3 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode1_subcaro_net,
    dout => assert3_dout_net
  );
  assert4 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode1_loopcounto_net,
    dout => assert4_dout_net
  );
  assert5 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 2,
    dout_width => 2
  )
  port map (
    din => mcode1_stateo_net,
    dout => assert5_dout_net
  );
  concat : entity xil_defaultlib.sysgen_concat_9b747ee43b 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    in0 => slice7_y_net,
    in1 => slice1_y_net,
    in2 => slice3_y_net,
    in3 => slice2_y_net,
    in4 => slice13_y_net,
    in5 => slice4_y_net,
    in6 => slice6_y_net,
    in7 => slice5_y_net,
    in8 => slice20_y_net,
    in9 => slice17_y_net,
    in10 => slice19_y_net,
    in11 => slice18_y_net,
    in12 => slice24_y_net,
    in13 => slice21_y_net,
    in14 => slice9_y_net,
    in15 => slice8_y_net,
    y => concat_y_net
  );
  down_sample17 : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlUnsigned,
    d_bin_pt => 0,
    d_width => 1,
    ds_ratio => 5,
    latency => 1,
    phase => 0,
    q_arith => xlUnsigned,
    q_bin_pt => 0,
    q_width => 1
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => fifo2_dout_net,
    src_clk => src_clk_net,
    src_ce => src_ce_net,
    dest_clk => clk_net,
    dest_ce => ce_net,
    q => down_sample17_q_net
  );
  fifo2 : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_4",
    data_count_width => 7,
    data_width => 1,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => delay8_q_net,
    we => delay9_q_net,
    re => delay7_q_net_x0,
    clk => src_clk_net,
    ce => src_ce_net,
    we_ce => src_ce_net,
    re_ce => src_ce_net,
    dout => fifo2_dout_net,
    empty => fifo2_empty_net,
    full => fifo2_full_net,
    dcount => fifo2_dcount_net
  );
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_7852e0a78d 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    frameen => delay7_q_net,
    statei => delay6_q_net,
    loopcounti => delay5_q_net,
    subcari => delay4_q_net,
    subcarcounti => delay3_q_net,
    starti => delay2_q_net,
    enablei => delay1_q_net_x0,
    push => mcode1_push_net,
    pop => mcode1_pop_net,
    stateo => mcode1_stateo_net,
    loopcounto => mcode1_loopcounto_net,
    subcaro => mcode1_subcaro_net,
    subcarcounto => mcode1_subcarcounto_net,
    starto => mcode1_starto_net,
    enableo => mcode1_enableo_net
  );
  parallel_to_serial : entity xil_defaultlib.basic_dmt_xlp2s 
  generic map (
    din_arith => xlUnsigned,
    din_bin_pt => 0,
    din_width => 64,
    dout_arith => xlUnsigned,
    dout_bin_pt => 0,
    dout_width => 1,
    latency => 1,
    lsb_first => 0,
    num_outputs => 64
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    din => concat_y_net,
    src_clk => src_clk_net_x0,
    src_ce => src_ce_net_x0,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net,
    dout => parallel_to_serial_dout_net
  );
  slice1 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode2_y1_net,
    y => slice1_y_net
  );
  slice13 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode5_y1_net,
    y => slice13_y_net
  );
  slice17 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode10_y1_net,
    y => slice17_y_net
  );
  slice18 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode12_y1_net,
    y => slice18_y_net
  );
  slice19 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode11_y1_net,
    y => slice19_y_net
  );
  slice2 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode4_y1_net,
    y => slice2_y_net
  );
  slice20 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode9_y1_net,
    y => slice20_y_net
  );
  slice21 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode14_y1_net,
    y => slice21_y_net
  );
  slice24 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode13_y1_net,
    y => slice24_y_net
  );
  slice3 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode3_y1_net,
    y => slice3_y_net
  );
  slice4 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode6_y1_net,
    y => slice4_y_net
  );
  slice5 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode8_y1_net,
    y => slice5_y_net
  );
  slice6 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode7_y1_net,
    y => slice6_y_net
  );
  slice7 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode1_y1_net,
    y => slice7_y_net
  );
  slice8 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode16_y1_net,
    y => slice8_y_net
  );
  slice9 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 4,
    y_width => 4
  )
  port map (
    x => mcode15_y1_net,
    y => slice9_y_net
  );
  delay1 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => assert_dout_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => delay1_q_net_x0
  );
  delay2 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => assert1_dout_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => delay2_q_net
  );
  delay3 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert2_dout_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => delay3_q_net
  );
  delay4 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert3_dout_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => delay4_q_net
  );
  delay5 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert4_dout_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => delay5_q_net
  );
  delay6 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 2
  )
  port map (
    en => '1',
    rst => '1',
    d => assert5_dout_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => delay6_q_net
  );
  delay7 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 23,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => mcode1_pop_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q(0) => delay7_q_net_x0
  );
  delay8 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 4,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => parallel_to_serial_dout_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q => delay8_q_net
  );
  delay9 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => mcode1_push_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q(0) => delay9_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIP
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_sysgen_sip is
  port (
    inp_trans : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    clk_256 : in std_logic;
    ce_256 : in std_logic;
    sub1 : out std_logic_vector( 4-1 downto 0 );
    sub2 : out std_logic_vector( 4-1 downto 0 );
    sub3 : out std_logic_vector( 4-1 downto 0 );
    sub4 : out std_logic_vector( 4-1 downto 0 );
    sub5 : out std_logic_vector( 4-1 downto 0 );
    sub6 : out std_logic_vector( 4-1 downto 0 );
    sub7 : out std_logic_vector( 4-1 downto 0 );
    sub8 : out std_logic_vector( 4-1 downto 0 );
    sub9 : out std_logic_vector( 4-1 downto 0 );
    sub10 : out std_logic_vector( 4-1 downto 0 );
    sub11 : out std_logic_vector( 4-1 downto 0 );
    sub12 : out std_logic_vector( 4-1 downto 0 );
    sub13 : out std_logic_vector( 4-1 downto 0 );
    sub14 : out std_logic_vector( 4-1 downto 0 );
    sub15 : out std_logic_vector( 4-1 downto 0 );
    sub16 : out std_logic_vector( 4-1 downto 0 );
    dbbitstream : out std_logic_vector( 1-1 downto 0 );
    sgframestart : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_sysgen_sip;
architecture structural of basic_dmt_sysgen_sip is 
  signal fifo1_full_net : std_logic;
  signal delay_q_net : std_logic_vector( 7-1 downto 0 );
  signal fifo1_dcount_net : std_logic_vector( 7-1 downto 0 );
  signal mcode1_sel_net : std_logic_vector( 1-1 downto 0 );
  signal mcode1_pop_net : std_logic;
  signal up_sample_q_net : std_logic_vector( 1-1 downto 0 );
  signal fifo1_empty_net : std_logic;
  signal mux_y_net : std_logic_vector( 1-1 downto 0 );
  signal serial_to_parallel_dout_net : std_logic_vector( 64-1 downto 0 );
  signal mcode1_push_net : std_logic;
  signal fifo1_dout_net : std_logic_vector( 1-1 downto 0 );
  signal slice2_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice1_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice12_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice11_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice30_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice10_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice8_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice13_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice29_y_net : std_logic_vector( 4-1 downto 0 );
  signal delay7_q_net : std_logic_vector( 1-1 downto 0 );
  signal slice9_y_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_framestart_net : std_logic_vector( 1-1 downto 0 );
  signal inp_trans_net : std_logic_vector( 1-1 downto 0 );
  signal src_clk_net_x0 : std_logic;
  signal slice4_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice14_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice5_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice3_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice6_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice7_y_net : std_logic_vector( 4-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 1-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 1-1 downto 0 );
  signal src_ce_net_x1 : std_logic;
  signal src_ce_net_x0 : std_logic;
  signal src_ce_net : std_logic;
  signal src_clk_net : std_logic;
  signal src_clk_net_x1 : std_logic;
begin
  sub1 <= slice30_y_net;
  sub2 <= slice29_y_net;
  sub3 <= slice7_y_net;
  sub4 <= slice6_y_net;
  sub5 <= slice5_y_net;
  sub6 <= slice4_y_net;
  sub7 <= slice3_y_net;
  sub8 <= slice2_y_net;
  sub9 <= slice1_y_net;
  sub10 <= slice13_y_net;
  sub11 <= slice14_y_net;
  sub12 <= slice12_y_net;
  sub13 <= slice11_y_net;
  sub14 <= slice10_y_net;
  sub15 <= slice8_y_net;
  sub16 <= slice9_y_net;
  dbbitstream <= delay7_q_net;
  sgframestart <= mcode1_framestart_net;
  inp_trans_net <= inp_trans;
  src_clk_net_x0 <= clk_1;
  src_ce_net_x0 <= ce_1;
  src_clk_net <= clk_64;
  src_ce_net <= ce_64;
  src_clk_net_x1 <= clk_256;
  src_ce_net_x1 <= ce_256;
  constant1 : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_c4c1fd841d 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  fifo1 : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_4",
    data_count_width => 7,
    data_width => 1,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => inp_trans_net,
    we => mcode1_push_net,
    re => mcode1_pop_net,
    clk => src_clk_net_x0,
    ce => src_ce_net_x0,
    we_ce => src_ce_net_x0,
    re_ce => src_ce_net_x0,
    dout => fifo1_dout_net,
    empty => fifo1_empty_net,
    full => fifo1_full_net,
    dcount => fifo1_dcount_net
  );
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_96bf53b8c9 
  port map (
    clr => '0',
    num => delay_q_net,
    frameen => up_sample_q_net,
    clk => src_clk_net_x0,
    ce => src_ce_net_x0,
    sel => mcode1_sel_net,
    push(0) => mcode1_push_net,
    pop(0) => mcode1_pop_net,
    framestart => mcode1_framestart_net
  );
  mux : entity xil_defaultlib.sysgen_mux_31e440a591 
  port map (
    clr => '0',
    sel => mcode1_sel_net,
    d0 => constant3_op_net,
    d1 => fifo1_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net_x0,
    y => mux_y_net
  );
  serial_to_parallel : entity xil_defaultlib.basic_dmt_xls2p 
  generic map (
    din_arith => xlUnsigned,
    din_bin_pt => 0,
    din_width => 1,
    dout_arith => xlUnsigned,
    dout_bin_pt => 0,
    dout_width => 64,
    latency => 1,
    lsb_first => 0,
    num_inputs => 64
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    din => delay7_q_net,
    src_clk => src_clk_net_x0,
    src_ce => src_ce_net_x0,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net,
    dout => serial_to_parallel_dout_net
  );
  slice1 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 28,
    new_msb => 31,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice1_y_net
  );
  slice10 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 8,
    new_msb => 11,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice10_y_net
  );
  slice11 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 12,
    new_msb => 15,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice11_y_net
  );
  slice12 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 16,
    new_msb => 19,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice12_y_net
  );
  slice13 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 24,
    new_msb => 27,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice13_y_net
  );
  slice14 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 20,
    new_msb => 23,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice14_y_net
  );
  slice2 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 32,
    new_msb => 35,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice2_y_net
  );
  slice29 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 56,
    new_msb => 59,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice29_y_net
  );
  slice3 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 36,
    new_msb => 39,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice3_y_net
  );
  slice30 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 60,
    new_msb => 63,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice30_y_net
  );
  slice4 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 40,
    new_msb => 43,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice4_y_net
  );
  slice5 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 44,
    new_msb => 47,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice5_y_net
  );
  slice6 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 48,
    new_msb => 51,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice6_y_net
  );
  slice7 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 52,
    new_msb => 55,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice7_y_net
  );
  slice8 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 4,
    new_msb => 7,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice8_y_net
  );
  slice9 : entity xil_defaultlib.basic_dmt_xlslice 
  generic map (
    new_lsb => 0,
    new_msb => 3,
    x_width => 64,
    y_width => 4
  )
  port map (
    x => serial_to_parallel_dout_net,
    y => slice9_y_net
  );
  up_sample : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
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
    d => constant1_op_net,
    src_clk => src_clk_net_x1,
    src_ce => src_ce_net_x1,
    dest_clk => src_clk_net_x0,
    dest_ce => src_ce_net_x0,
    q => up_sample_q_net
  );
  delay : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 7
  )
  port map (
    en => '1',
    rst => '1',
    d => fifo1_dcount_net,
    clk => src_clk_net_x0,
    ce => src_ce_net_x0,
    q => delay_q_net
  );
  delay7 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 58,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => mux_y_net,
    clk => src_clk_net_x0,
    ce => src_ce_net_x0,
    q => delay7_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/DelayVar/OFDM
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_ofdm_x0 is
  port (
    in1 : in std_logic_vector( 21-1 downto 0 );
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    out1 : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_ofdm_x0;
architecture structural of basic_dmt_ofdm_x0 is 
  signal clk_net : std_logic;
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
  signal inp_recv_im_net : std_logic_vector( 21-1 downto 0 );
  signal ce_net : std_logic;
begin
  out1 <= delay4_q_net;
  inp_recv_im_net <= in1;
  clk_net <= clk_14;
  ce_net <= ce_14;
  delay4 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 12,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => inp_recv_im_net,
    clk => clk_net,
    ce => ce_net,
    q => delay4_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/DelayVar
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_delayvar_x0 is
  port (
    in1 : in std_logic_vector( 21-1 downto 0 );
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    out1 : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_delayvar_x0;
architecture structural of basic_dmt_delayvar_x0 is 
  signal clk_net : std_logic;
  signal ce_net : std_logic;
  signal inp_recv_im_net : std_logic_vector( 21-1 downto 0 );
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
begin
  out1 <= delay4_q_net;
  inp_recv_im_net <= in1;
  clk_net <= clk_14;
  ce_net <= ce_14;
  ofdm_x2 : entity xil_defaultlib.basic_dmt_ofdm_x0 
  port map (
    in1 => inp_recv_im_net,
    clk_14 => clk_net,
    ce_14 => ce_net,
    out1 => delay4_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/DelayVar1/OFDM
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_ofdm_x1 is
  port (
    in1 : in std_logic_vector( 21-1 downto 0 );
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    out1 : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_ofdm_x1;
architecture structural of basic_dmt_ofdm_x1 is 
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
  signal clk_net : std_logic;
  signal inp_recv_re_net : std_logic_vector( 21-1 downto 0 );
  signal ce_net : std_logic;
begin
  out1 <= delay4_q_net;
  inp_recv_re_net <= in1;
  clk_net <= clk_14;
  ce_net <= ce_14;
  delay4 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 12,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => inp_recv_re_net,
    clk => clk_net,
    ce => ce_net,
    q => delay4_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/DelayVar1
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_delayvar1 is
  port (
    in1 : in std_logic_vector( 21-1 downto 0 );
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    out1 : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_delayvar1;
architecture structural of basic_dmt_delayvar1 is 
  signal clk_net : std_logic;
  signal inp_recv_re_net : std_logic_vector( 21-1 downto 0 );
  signal delay4_q_net : std_logic_vector( 21-1 downto 0 );
  signal ce_net : std_logic;
begin
  out1 <= delay4_q_net;
  inp_recv_re_net <= in1;
  clk_net <= clk_14;
  ce_net <= ce_14;
  ofdm_x2 : entity xil_defaultlib.basic_dmt_ofdm_x1 
  port map (
    in1 => inp_recv_re_net,
    clk_14 => clk_net,
    ce_14 => ce_net,
    out1 => delay4_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/FFT/FFT_OFDM
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_fft_ofdm is
  port (
    sg_re : in std_logic_vector( 21-1 downto 0 );
    sg_im : in std_logic_vector( 21-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_2 : in std_logic;
    ce_2 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    re_out : out std_logic_vector( 26-1 downto 0 );
    im_out : out std_logic_vector( 26-1 downto 0 );
    db_aft_dmt_re : out std_logic_vector( 1-1 downto 0 );
    db_aft_dmt_im : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_fft_ofdm;
architecture structural of basic_dmt_fft_ofdm is 
  signal fifo_dout_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal src_clk_net : std_logic;
  signal src_ce_net : std_logic;
  signal dest_clk_net : std_logic;
  signal fifo1_dout_net : std_logic_vector( 26-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 1-1 downto 0 );
  signal addsub_s_net : std_logic_vector( 1-1 downto 0 );
  signal dest_ce_net_x0 : std_logic;
  signal ce_net : std_logic;
  signal timing_for_config_op_net : std_logic_vector( 1-1 downto 0 );
  signal delay7_q_net : std_logic_vector( 1-1 downto 0 );
  signal clk_net : std_logic;
  signal asserted_for_last_sample_q_net : std_logic_vector( 1-1 downto 0 );
  signal dest_ce_net : std_logic;
  signal dest_clk_net_x0 : std_logic;
  signal x1_for_fft_0_for_ifft_op_net : std_logic_vector( 1-1 downto 0 );
  signal convert_dout_net : std_logic_vector( 1-1 downto 0 );
  signal relational_op_net : std_logic_vector( 1-1 downto 0 );
  signal delay3_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay_q_net : std_logic_vector( 21-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 4-1 downto 0 );
  signal constant5_op_net : std_logic_vector( 1-1 downto 0 );
  signal counter_op_net : std_logic_vector( 4-1 downto 0 );
  signal constant4_op_net : std_logic_vector( 1-1 downto 0 );
  signal shift_op_net : std_logic_vector( 26-1 downto 0 );
  signal fast_fourier_transform_9_0_m_axis_data_tvalid_net : std_logic_vector( 1-1 downto 0 );
  signal fifo1_empty_net : std_logic;
  signal fifo1_percent_full_net : std_logic_vector( 4-1 downto 0 );
  signal fifo1_full_net : std_logic;
  signal shift1_op_net : std_logic_vector( 26-1 downto 0 );
  signal re2_q_net : std_logic;
  signal re1_q_net : std_logic;
  signal fifo_full_net : std_logic;
  signal externel_slave_is_able_to_receive_data_op_net : std_logic_vector( 1-1 downto 0 );
  signal down_sample5_q_net : std_logic_vector( 1-1 downto 0 );
  signal fifo_empty_net : std_logic;
  signal fifo_percent_full_net : std_logic_vector( 4-1 downto 0 );
  signal s_axis_data_tvalid1_q_net : std_logic;
  signal fast_fourier_transform_9_0_event_data_in_channel_halt_net : std_logic;
  signal fast_fourier_transform_9_0_m_axis_data_tdata_xn_im_0_net : std_logic_vector( 26-1 downto 0 );
  signal fast_fourier_transform_9_0_m_axis_data_tlast_net : std_logic;
  signal fast_fourier_transform_9_0_s_axis_config_tready_net : std_logic;
  signal fast_fourier_transform_9_0_event_tlast_unexpected_net : std_logic;
  signal fast_fourier_transform_9_0_event_frame_started_net : std_logic;
  signal fast_fourier_transform_9_0_event_tlast_missing_net : std_logic;
  signal fast_fourier_transform_9_0_m_axis_data_tdata_xn_re_0_net : std_logic_vector( 26-1 downto 0 );
  signal reinterpret1_output_port_net : std_logic_vector( 21-1 downto 0 );
  signal reinterpret_output_port_net : std_logic_vector( 21-1 downto 0 );
  signal aclken_q_net : std_logic;
  signal fast_fourier_transform_9_0_s_axis_data_tready_net : std_logic;
  signal fast_fourier_transform_9_0_m_axis_data_tuser_xk_index_net : std_logic_vector( 4-1 downto 0 );
  signal fast_fourier_transform_9_0_event_status_channel_halt_net : std_logic;
  signal fast_fourier_transform_9_0_event_data_out_channel_halt_net : std_logic;
  signal up_sample1_q_net : std_logic_vector( 1-1 downto 0 );
  signal up_sample_q_net : std_logic_vector( 1-1 downto 0 );
begin
  re_out <= fifo1_dout_net;
  im_out <= fifo_dout_net;
  db_aft_dmt_re <= constant3_op_net;
  db_aft_dmt_im <= constant3_op_net;
  mcode1_out_re_net <= sg_re;
  mcode1_out_im_net <= sg_im;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  dest_clk_net <= clk_2;
  dest_ce_net <= ce_2;
  dest_clk_net_x0 <= clk_4;
  dest_ce_net_x0 <= ce_4;
  clk_net <= clk_5;
  ce_net <= ce_5;
  x1_for_fft_0_for_ifft : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => x1_for_fft_0_for_ifft_op_net
  );
  addsub : entity xil_defaultlib.sysgen_addsub_a4a3676596 
  port map (
    clr => '0',
    a => timing_for_config_op_net,
    b => delay7_q_net,
    clk => clk_net,
    ce => ce_net,
    s => addsub_s_net
  );
  asserted_for_last_sample : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => relational_op_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q => asserted_for_last_sample_q_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_6047eef043 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net
  );
  constant4 : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant4_op_net
  );
  constant5 : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant5_op_net
  );
  convert : entity xil_defaultlib.basic_dmt_xlconvert 
  generic map (
    bool_conversion => 1,
    din_arith => 1,
    din_bin_pt => 0,
    din_width => 1,
    dout_arith => 1,
    dout_bin_pt => 0,
    dout_width => 1,
    latency => 1,
    overflow => xlWrap,
    quantization => xlTruncate
  )
  port map (
    clr => '0',
    en => "1",
    din => addsub_s_net,
    clk => clk_net,
    ce => ce_net,
    dout => convert_dout_net
  );
  counter : entity xil_defaultlib.basic_dmt_xlcounter_limit 
  generic map (
    cnt_15_0 => 15,
    cnt_31_16 => 0,
    cnt_47_32 => 0,
    cnt_63_48 => 0,
    core_name0 => "basic_dmt_c_counter_binary_v12_0_0",
    count_limited => 0,
    op_arith => xlUnsigned,
    op_width => 4
  )
  port map (
    en => "1",
    rst => "0",
    clr => '0',
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    op => counter_op_net
  );
  delay : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 11,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => mcode1_out_im_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q => delay_q_net
  );
  delay3 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 11,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => mcode1_out_re_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q => delay3_q_net
  );
  delay7 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => timing_for_config_op_net,
    clk => clk_net,
    ce => ce_net,
    q => delay7_q_net
  );
  down_sample5 : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlUnsigned,
    d_bin_pt => 0,
    d_width => 1,
    ds_ratio => 2,
    latency => 0,
    phase => 0,
    q_arith => xlUnsigned,
    q_bin_pt => 0,
    q_width => 1
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => fast_fourier_transform_9_0_m_axis_data_tvalid_net,
    src_clk => src_clk_net,
    src_ce => src_ce_net,
    dest_clk => dest_clk_net,
    dest_ce => dest_ce_net,
    q => down_sample5_q_net
  );
  externel_slave_is_able_to_receive_data : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => externel_slave_is_able_to_receive_data_op_net
  );
  fifo : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_5",
    data_count_width => 4,
    data_width => 26,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => shift_op_net,
    we => down_sample5_q_net(0),
    re => re1_q_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    we_ce => dest_ce_net,
    re_ce => dest_ce_net_x0,
    dout => fifo_dout_net,
    empty => fifo_empty_net,
    percent_full => fifo_percent_full_net,
    full => fifo_full_net
  );
  fifo1 : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_5",
    data_count_width => 4,
    data_width => 26,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => shift1_op_net,
    we => down_sample5_q_net(0),
    re => re2_q_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    we_ce => dest_ce_net,
    re_ce => dest_ce_net_x0,
    dout => fifo1_dout_net,
    empty => fifo1_empty_net,
    percent_full => fifo1_percent_full_net,
    full => fifo1_full_net
  );
  fast_fourier_transform_9_0 : entity xil_defaultlib.xlfast_fourier_transform_7bdb82ffedec749ee066981b436841d9 
  port map (
    s_axis_config_tdata_fwd_inv => x1_for_fft_0_for_ifft_op_net,
    s_axis_config_tvalid => convert_dout_net(0),
    s_axis_data_tdata_xn_im_0 => reinterpret_output_port_net,
    s_axis_data_tdata_xn_re_0 => reinterpret1_output_port_net,
    s_axis_data_tvalid => s_axis_data_tvalid1_q_net,
    s_axis_data_tlast => asserted_for_last_sample_q_net(0),
    m_axis_data_tready => externel_slave_is_able_to_receive_data_op_net(0),
    en => aclken_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    s_axis_config_tready => fast_fourier_transform_9_0_s_axis_config_tready_net,
    s_axis_data_tready => fast_fourier_transform_9_0_s_axis_data_tready_net,
    m_axis_data_tdata_xn_im_0 => fast_fourier_transform_9_0_m_axis_data_tdata_xn_im_0_net,
    m_axis_data_tdata_xn_re_0 => fast_fourier_transform_9_0_m_axis_data_tdata_xn_re_0_net,
    m_axis_data_tuser_xk_index => fast_fourier_transform_9_0_m_axis_data_tuser_xk_index_net,
    m_axis_data_tvalid => fast_fourier_transform_9_0_m_axis_data_tvalid_net(0),
    m_axis_data_tlast => fast_fourier_transform_9_0_m_axis_data_tlast_net,
    event_frame_started => fast_fourier_transform_9_0_event_frame_started_net,
    event_tlast_unexpected => fast_fourier_transform_9_0_event_tlast_unexpected_net,
    event_tlast_missing => fast_fourier_transform_9_0_event_tlast_missing_net,
    event_data_in_channel_halt => fast_fourier_transform_9_0_event_data_in_channel_halt_net,
    event_status_channel_halt => fast_fourier_transform_9_0_event_status_channel_halt_net,
    event_data_out_channel_halt => fast_fourier_transform_9_0_event_data_out_channel_halt_net
  );
  reinterpret : entity xil_defaultlib.sysgen_reinterpret_f8109ce444 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    input_port => delay_q_net,
    output_port => reinterpret_output_port_net
  );
  reinterpret1 : entity xil_defaultlib.sysgen_reinterpret_f8109ce444 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    input_port => delay3_q_net,
    output_port => reinterpret1_output_port_net
  );
  relational : entity xil_defaultlib.sysgen_relational_c72c00b807 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    a => counter_op_net,
    b => constant1_op_net,
    op => relational_op_net
  );
  shift : entity xil_defaultlib.sysgen_shift_daec1eca69 
  port map (
    clr => '0',
    ip => fast_fourier_transform_9_0_m_axis_data_tdata_xn_im_0_net,
    clk => src_clk_net,
    ce => src_ce_net,
    op => shift_op_net
  );
  shift1 : entity xil_defaultlib.sysgen_shift_daec1eca69 
  port map (
    clr => '0',
    ip => fast_fourier_transform_9_0_m_axis_data_tdata_xn_re_0_net,
    clk => src_clk_net,
    ce => src_ce_net,
    op => shift1_op_net
  );
  timing_for_config : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => timing_for_config_op_net
  );
  up_sample : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
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
    d => constant4_op_net,
    src_clk => dest_clk_net,
    src_ce => dest_ce_net,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net,
    q => up_sample_q_net
  );
  up_sample1 : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
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
    d => constant5_op_net,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net_x0,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net,
    q => up_sample1_q_net
  );
  aclken : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => up_sample_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q(0) => aclken_q_net
  );
  re1 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => constant3_op_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q(0) => re1_q_net
  );
  re2 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => constant3_op_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q(0) => re2_q_net
  );
  s_axis_data_tvalid1 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => up_sample1_q_net,
    clk => src_clk_net,
    ce => src_ce_net,
    q(0) => s_axis_data_tvalid1_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/FFT
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_fft is
  port (
    sg_re : in std_logic_vector( 21-1 downto 0 );
    sg_im : in std_logic_vector( 21-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_2 : in std_logic;
    ce_2 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    re_out : out std_logic_vector( 26-1 downto 0 );
    im_out : out std_logic_vector( 26-1 downto 0 );
    db_aft_dmt_re : out std_logic_vector( 1-1 downto 0 );
    db_aft_dmt_im : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_fft;
architecture structural of basic_dmt_fft is 
  signal constant3_op_net : std_logic_vector( 1-1 downto 0 );
  signal fifo1_dout_net : std_logic_vector( 26-1 downto 0 );
  signal fifo_dout_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal src_ce_net : std_logic;
  signal mcode1_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal ce_net : std_logic;
  signal dest_clk_net_x0 : std_logic;
  signal dest_ce_net : std_logic;
  signal src_clk_net : std_logic;
  signal dest_ce_net_x0 : std_logic;
  signal clk_net : std_logic;
  signal dest_clk_net : std_logic;
begin
  re_out <= fifo1_dout_net;
  im_out <= fifo_dout_net;
  db_aft_dmt_re <= constant3_op_net;
  db_aft_dmt_im <= constant3_op_net;
  mcode1_out_re_net <= sg_re;
  mcode1_out_im_net <= sg_im;
  src_clk_net <= clk_1;
  src_ce_net <= ce_1;
  dest_clk_net <= clk_2;
  dest_ce_net <= ce_2;
  dest_clk_net_x0 <= clk_4;
  dest_ce_net_x0 <= ce_4;
  clk_net <= clk_5;
  ce_net <= ce_5;
  fft_ofdm_x0 : entity xil_defaultlib.basic_dmt_fft_ofdm 
  port map (
    sg_re => mcode1_out_re_net,
    sg_im => mcode1_out_im_net,
    clk_1 => src_clk_net,
    ce_1 => src_ce_net,
    clk_2 => dest_clk_net,
    ce_2 => dest_ce_net,
    clk_4 => dest_clk_net_x0,
    ce_4 => dest_ce_net_x0,
    clk_5 => clk_net,
    ce_5 => ce_net,
    re_out => fifo1_dout_net,
    im_out => fifo_dout_net,
    db_aft_dmt_re => constant3_op_net,
    db_aft_dmt_im => constant3_op_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/Guard_Interval/Rem_GI
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_rem_gi is
  port (
    re_in : in std_logic_vector( 21-1 downto 0 );
    im_in : in std_logic_vector( 21-1 downto 0 );
    sg_rev_framestart : in std_logic_vector( 1-1 downto 0 );
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    re : out std_logic_vector( 21-1 downto 0 );
    im : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_rem_gi;
architecture structural of basic_dmt_rem_gi is 
  signal assert3_dout_net : std_logic_vector( 2-1 downto 0 );
  signal down_sample3_q_net : std_logic_vector( 21-1 downto 0 );
  signal dest_ce_net : std_logic;
  signal mcode1_starto_net : std_logic_vector( 1-1 downto 0 );
  signal mcode1_stateo_net : std_logic_vector( 2-1 downto 0 );
  signal mcode1_loopcounto_net : std_logic_vector( 8-1 downto 0 );
  signal down_sample2_q_net : std_logic_vector( 1-1 downto 0 );
  signal down_sample1_q_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal assert1_dout_net : std_logic_vector( 1-1 downto 0 );
  signal assert2_dout_net : std_logic_vector( 8-1 downto 0 );
  signal mcode1_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal dest_clk_net : std_logic;
  signal delay1_q_net : std_logic_vector( 8-1 downto 0 );
  signal delay3_q_net : std_logic_vector( 2-1 downto 0 );
  signal mcode1_pop_net : std_logic_vector( 1-1 downto 0 );
  signal delay2_q_net : std_logic_vector( 1-1 downto 0 );
begin
  re <= mcode1_out_re_net;
  im <= mcode1_out_im_net;
  down_sample3_q_net <= re_in;
  down_sample1_q_net <= im_in;
  down_sample2_q_net <= sg_rev_framestart;
  dest_clk_net <= clk_4;
  dest_ce_net <= ce_4;
  assert1 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 1,
    dout_width => 1
  )
  port map (
    din => mcode1_starto_net,
    dout => assert1_dout_net
  );
  assert2 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode1_loopcounto_net,
    dout => assert2_dout_net
  );
  assert3 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 2,
    dout_width => 2
  )
  port map (
    din => mcode1_stateo_net,
    dout => assert3_dout_net
  );
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_34b14fac6d 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    inp_re => down_sample3_q_net,
    inp_im => down_sample1_q_net,
    frameen => down_sample2_q_net,
    statei => delay3_q_net,
    loopcounti => delay1_q_net,
    starti => delay2_q_net,
    out_re => mcode1_out_re_net,
    out_im => mcode1_out_im_net,
    pop => mcode1_pop_net,
    stateo => mcode1_stateo_net,
    loopcounto => mcode1_loopcounto_net,
    starto => mcode1_starto_net
  );
  delay1 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert2_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay1_q_net
  );
  delay2 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => assert1_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay2_q_net
  );
  delay3 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 2
  )
  port map (
    en => '1',
    rst => '1',
    d => assert3_dout_net,
    clk => dest_clk_net,
    ce => dest_ce_net,
    q => delay3_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/Guard_Interval
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_guard_interval_x0 is
  port (
    re_in : in std_logic_vector( 21-1 downto 0 );
    im_in : in std_logic_vector( 21-1 downto 0 );
    sg_rev_framestart : in std_logic_vector( 1-1 downto 0 );
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    re : out std_logic_vector( 21-1 downto 0 );
    im : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_guard_interval_x0;
architecture structural of basic_dmt_guard_interval_x0 is 
  signal down_sample3_q_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal down_sample2_q_net : std_logic_vector( 1-1 downto 0 );
  signal dest_ce_net : std_logic;
  signal down_sample1_q_net : std_logic_vector( 21-1 downto 0 );
  signal dest_clk_net : std_logic;
  signal mcode1_out_im_net : std_logic_vector( 21-1 downto 0 );
begin
  re <= mcode1_out_re_net;
  im <= mcode1_out_im_net;
  down_sample3_q_net <= re_in;
  down_sample1_q_net <= im_in;
  down_sample2_q_net <= sg_rev_framestart;
  dest_clk_net <= clk_4;
  dest_ce_net <= ce_4;
  rem_gi_x1 : entity xil_defaultlib.basic_dmt_rem_gi 
  port map (
    re_in => down_sample3_q_net,
    im_in => down_sample1_q_net,
    sg_rev_framestart => down_sample2_q_net,
    clk_4 => dest_clk_net,
    ce_4 => dest_ce_net,
    re => mcode1_out_re_net,
    im => mcode1_out_im_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/sysgen_equalizer/No_equal
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_no_equal is
  port (
    re : in std_logic_vector( 416-1 downto 0 );
    im : in std_logic_vector( 416-1 downto 0 );
    re_sub1 : out std_logic_vector( 26-1 downto 0 );
    im_sub1 : out std_logic_vector( 26-1 downto 0 );
    re_sub2 : out std_logic_vector( 26-1 downto 0 );
    im_sub2 : out std_logic_vector( 26-1 downto 0 );
    re_sub3 : out std_logic_vector( 26-1 downto 0 );
    im_sub3 : out std_logic_vector( 26-1 downto 0 );
    re_sub4 : out std_logic_vector( 26-1 downto 0 );
    im_sub4 : out std_logic_vector( 26-1 downto 0 );
    re_sub5 : out std_logic_vector( 26-1 downto 0 );
    im_sub5 : out std_logic_vector( 26-1 downto 0 );
    re_sub6 : out std_logic_vector( 26-1 downto 0 );
    im_sub6 : out std_logic_vector( 26-1 downto 0 );
    re_sub7 : out std_logic_vector( 26-1 downto 0 );
    im_sub7 : out std_logic_vector( 26-1 downto 0 );
    re_sub8 : out std_logic_vector( 26-1 downto 0 );
    im_sub8 : out std_logic_vector( 26-1 downto 0 );
    re_sub9 : out std_logic_vector( 26-1 downto 0 );
    im_sub9 : out std_logic_vector( 26-1 downto 0 );
    re_sub10 : out std_logic_vector( 26-1 downto 0 );
    im_sub10 : out std_logic_vector( 26-1 downto 0 );
    re_sub11 : out std_logic_vector( 26-1 downto 0 );
    im_sub11 : out std_logic_vector( 26-1 downto 0 );
    re_sub12 : out std_logic_vector( 26-1 downto 0 );
    im_sub12 : out std_logic_vector( 26-1 downto 0 );
    re_sub13 : out std_logic_vector( 26-1 downto 0 );
    im_sub13 : out std_logic_vector( 26-1 downto 0 );
    re_sub14 : out std_logic_vector( 26-1 downto 0 );
    im_sub14 : out std_logic_vector( 26-1 downto 0 );
    re_sub15 : out std_logic_vector( 26-1 downto 0 );
    im_sub15 : out std_logic_vector( 26-1 downto 0 );
    re_sub16 : out std_logic_vector( 26-1 downto 0 );
    im_sub16 : out std_logic_vector( 26-1 downto 0 )
  );
end basic_dmt_no_equal;
architecture structural of basic_dmt_no_equal is 
  signal mcode1_y1_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y4_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y4_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y5_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y5_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y6_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y1_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y2_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y2_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y9_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y15_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y14_re_net : std_logic_vector( 26-1 downto 0 );
  signal serial_to_parallel_dout_net : std_logic_vector( 416-1 downto 0 );
  signal mcode1_y14_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y15_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y13_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y11_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y16_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y12_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y7_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y6_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y13_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y16_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y12_re_net : std_logic_vector( 26-1 downto 0 );
  signal serial_to_parallel1_dout_net : std_logic_vector( 416-1 downto 0 );
  signal mcode1_y7_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y11_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y9_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_re_net : std_logic_vector( 26-1 downto 0 );
begin
  re_sub1 <= mcode1_y1_re_net;
  im_sub1 <= mcode1_y1_im_net;
  re_sub2 <= mcode1_y2_re_net;
  im_sub2 <= mcode1_y2_im_net;
  re_sub3 <= mcode1_y3_re_net;
  im_sub3 <= mcode1_y3_im_net;
  re_sub4 <= mcode1_y4_re_net;
  im_sub4 <= mcode1_y4_im_net;
  re_sub5 <= mcode1_y5_re_net;
  im_sub5 <= mcode1_y5_im_net;
  re_sub6 <= mcode1_y6_re_net;
  im_sub6 <= mcode1_y6_im_net;
  re_sub7 <= mcode1_y7_re_net;
  im_sub7 <= mcode1_y7_im_net;
  re_sub8 <= mcode1_y8_re_net;
  im_sub8 <= mcode1_y8_im_net;
  re_sub9 <= mcode1_y9_re_net;
  im_sub9 <= mcode1_y9_im_net;
  re_sub10 <= mcode1_y10_re_net;
  im_sub10 <= mcode1_y10_im_net;
  re_sub11 <= mcode1_y11_re_net;
  im_sub11 <= mcode1_y11_im_net;
  re_sub12 <= mcode1_y12_re_net;
  im_sub12 <= mcode1_y12_im_net;
  re_sub13 <= mcode1_y13_re_net;
  im_sub13 <= mcode1_y13_im_net;
  re_sub14 <= mcode1_y14_re_net;
  im_sub14 <= mcode1_y14_im_net;
  re_sub15 <= mcode1_y15_re_net;
  im_sub15 <= mcode1_y15_im_net;
  re_sub16 <= mcode1_y16_re_net;
  im_sub16 <= mcode1_y16_im_net;
  serial_to_parallel_dout_net <= re;
  serial_to_parallel1_dout_net <= im;
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_7190f7090b 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    x_re => serial_to_parallel_dout_net,
    x_im => serial_to_parallel1_dout_net,
    y1_re => mcode1_y1_re_net,
    y1_im => mcode1_y1_im_net,
    y2_re => mcode1_y2_re_net,
    y2_im => mcode1_y2_im_net,
    y3_re => mcode1_y3_re_net,
    y3_im => mcode1_y3_im_net,
    y4_re => mcode1_y4_re_net,
    y4_im => mcode1_y4_im_net,
    y5_re => mcode1_y5_re_net,
    y5_im => mcode1_y5_im_net,
    y6_re => mcode1_y6_re_net,
    y6_im => mcode1_y6_im_net,
    y7_re => mcode1_y7_re_net,
    y7_im => mcode1_y7_im_net,
    y8_re => mcode1_y8_re_net,
    y8_im => mcode1_y8_im_net,
    y9_re => mcode1_y9_re_net,
    y9_im => mcode1_y9_im_net,
    y10_re => mcode1_y10_re_net,
    y10_im => mcode1_y10_im_net,
    y11_re => mcode1_y11_re_net,
    y11_im => mcode1_y11_im_net,
    y12_re => mcode1_y12_re_net,
    y12_im => mcode1_y12_im_net,
    y13_re => mcode1_y13_re_net,
    y13_im => mcode1_y13_im_net,
    y14_re => mcode1_y14_re_net,
    y14_im => mcode1_y14_im_net,
    y15_re => mcode1_y15_re_net,
    y15_im => mcode1_y15_im_net,
    y16_re => mcode1_y16_re_net,
    y16_im => mcode1_y16_im_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT/sysgen_equalizer
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_sysgen_equalizer is
  port (
    re : in std_logic_vector( 416-1 downto 0 );
    im : in std_logic_vector( 416-1 downto 0 );
    re_sub1 : out std_logic_vector( 26-1 downto 0 );
    im_sub1 : out std_logic_vector( 26-1 downto 0 );
    re_sub2 : out std_logic_vector( 26-1 downto 0 );
    im_sub2 : out std_logic_vector( 26-1 downto 0 );
    re_sub3 : out std_logic_vector( 26-1 downto 0 );
    im_sub3 : out std_logic_vector( 26-1 downto 0 );
    re_sub4 : out std_logic_vector( 26-1 downto 0 );
    im_sub4 : out std_logic_vector( 26-1 downto 0 );
    re_sub5 : out std_logic_vector( 26-1 downto 0 );
    im_sub5 : out std_logic_vector( 26-1 downto 0 );
    re_sub6 : out std_logic_vector( 26-1 downto 0 );
    im_sub6 : out std_logic_vector( 26-1 downto 0 );
    re_sub7 : out std_logic_vector( 26-1 downto 0 );
    im_sub7 : out std_logic_vector( 26-1 downto 0 );
    re_sub8 : out std_logic_vector( 26-1 downto 0 );
    im_sub8 : out std_logic_vector( 26-1 downto 0 );
    re_sub9 : out std_logic_vector( 26-1 downto 0 );
    im_sub9 : out std_logic_vector( 26-1 downto 0 );
    re_sub10 : out std_logic_vector( 26-1 downto 0 );
    im_sub10 : out std_logic_vector( 26-1 downto 0 );
    re_sub11 : out std_logic_vector( 26-1 downto 0 );
    im_sub11 : out std_logic_vector( 26-1 downto 0 );
    re_sub12 : out std_logic_vector( 26-1 downto 0 );
    im_sub12 : out std_logic_vector( 26-1 downto 0 );
    re_sub13 : out std_logic_vector( 26-1 downto 0 );
    im_sub13 : out std_logic_vector( 26-1 downto 0 );
    re_sub14 : out std_logic_vector( 26-1 downto 0 );
    im_sub14 : out std_logic_vector( 26-1 downto 0 );
    re_sub15 : out std_logic_vector( 26-1 downto 0 );
    im_sub15 : out std_logic_vector( 26-1 downto 0 );
    re_sub16 : out std_logic_vector( 26-1 downto 0 );
    im_sub16 : out std_logic_vector( 26-1 downto 0 )
  );
end basic_dmt_sysgen_equalizer;
architecture structural of basic_dmt_sysgen_equalizer is 
  signal mcode1_y1_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y5_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y7_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y9_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y7_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y5_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y9_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y6_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y2_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y4_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y6_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y11_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y11_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y4_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y2_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y1_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y14_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y13_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y16_im_net : std_logic_vector( 26-1 downto 0 );
  signal serial_to_parallel_dout_net : std_logic_vector( 416-1 downto 0 );
  signal mcode1_y16_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y14_im_net : std_logic_vector( 26-1 downto 0 );
  signal serial_to_parallel1_dout_net : std_logic_vector( 416-1 downto 0 );
  signal mcode1_y13_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y15_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y15_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y12_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y12_re_net : std_logic_vector( 26-1 downto 0 );
begin
  re_sub1 <= mcode1_y1_re_net;
  im_sub1 <= mcode1_y1_im_net;
  re_sub2 <= mcode1_y2_re_net;
  im_sub2 <= mcode1_y2_im_net;
  re_sub3 <= mcode1_y3_re_net;
  im_sub3 <= mcode1_y3_im_net;
  re_sub4 <= mcode1_y4_re_net;
  im_sub4 <= mcode1_y4_im_net;
  re_sub5 <= mcode1_y5_re_net;
  im_sub5 <= mcode1_y5_im_net;
  re_sub6 <= mcode1_y6_re_net;
  im_sub6 <= mcode1_y6_im_net;
  re_sub7 <= mcode1_y7_re_net;
  im_sub7 <= mcode1_y7_im_net;
  re_sub8 <= mcode1_y8_re_net;
  im_sub8 <= mcode1_y8_im_net;
  re_sub9 <= mcode1_y9_re_net;
  im_sub9 <= mcode1_y9_im_net;
  re_sub10 <= mcode1_y10_re_net;
  im_sub10 <= mcode1_y10_im_net;
  re_sub11 <= mcode1_y11_re_net;
  im_sub11 <= mcode1_y11_im_net;
  re_sub12 <= mcode1_y12_re_net;
  im_sub12 <= mcode1_y12_im_net;
  re_sub13 <= mcode1_y13_re_net;
  im_sub13 <= mcode1_y13_im_net;
  re_sub14 <= mcode1_y14_re_net;
  im_sub14 <= mcode1_y14_im_net;
  re_sub15 <= mcode1_y15_re_net;
  im_sub15 <= mcode1_y15_im_net;
  re_sub16 <= mcode1_y16_re_net;
  im_sub16 <= mcode1_y16_im_net;
  serial_to_parallel_dout_net <= re;
  serial_to_parallel1_dout_net <= im;
  no_equal_x0 : entity xil_defaultlib.basic_dmt_no_equal 
  port map (
    re => serial_to_parallel_dout_net,
    im => serial_to_parallel1_dout_net,
    re_sub1 => mcode1_y1_re_net,
    im_sub1 => mcode1_y1_im_net,
    re_sub2 => mcode1_y2_re_net,
    im_sub2 => mcode1_y2_im_net,
    re_sub3 => mcode1_y3_re_net,
    im_sub3 => mcode1_y3_im_net,
    re_sub4 => mcode1_y4_re_net,
    im_sub4 => mcode1_y4_im_net,
    re_sub5 => mcode1_y5_re_net,
    im_sub5 => mcode1_y5_im_net,
    re_sub6 => mcode1_y6_re_net,
    im_sub6 => mcode1_y6_im_net,
    re_sub7 => mcode1_y7_re_net,
    im_sub7 => mcode1_y7_im_net,
    re_sub8 => mcode1_y8_re_net,
    im_sub8 => mcode1_y8_im_net,
    re_sub9 => mcode1_y9_re_net,
    im_sub9 => mcode1_y9_im_net,
    re_sub10 => mcode1_y10_re_net,
    im_sub10 => mcode1_y10_im_net,
    re_sub11 => mcode1_y11_re_net,
    im_sub11 => mcode1_y11_im_net,
    re_sub12 => mcode1_y12_re_net,
    im_sub12 => mcode1_y12_im_net,
    re_sub13 => mcode1_y13_re_net,
    im_sub13 => mcode1_y13_im_net,
    re_sub14 => mcode1_y14_re_net,
    im_sub14 => mcode1_y14_im_net,
    re_sub15 => mcode1_y15_re_net,
    im_sub15 => mcode1_y15_im_net,
    re_sub16 => mcode1_y16_re_net,
    im_sub16 => mcode1_y16_im_net
  );
end structural;
-- Generated from Simulink block Basic_DMT/Sysgen_SIPaFFT
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_sysgen_sipafft is
  port (
    sg_re : in std_logic_vector( 21-1 downto 0 );
    sg_im : in std_logic_vector( 21-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_2 : in std_logic;
    ce_2 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    db_aft_fft_re : out std_logic_vector( 26-1 downto 0 );
    db_aft_fft_im : out std_logic_vector( 26-1 downto 0 );
    db2_gi_re : out std_logic_vector( 21-1 downto 0 );
    db2_gi_im : out std_logic_vector( 21-1 downto 0 );
    re_sub1 : out std_logic_vector( 26-1 downto 0 );
    im_sub1 : out std_logic_vector( 26-1 downto 0 );
    re_sub2 : out std_logic_vector( 26-1 downto 0 );
    im_sub2 : out std_logic_vector( 26-1 downto 0 );
    re_sub3 : out std_logic_vector( 26-1 downto 0 );
    im_sub3 : out std_logic_vector( 26-1 downto 0 );
    re_sub4 : out std_logic_vector( 26-1 downto 0 );
    im_sub4 : out std_logic_vector( 26-1 downto 0 );
    re_sub5 : out std_logic_vector( 26-1 downto 0 );
    im_sub5 : out std_logic_vector( 26-1 downto 0 );
    re_sub6 : out std_logic_vector( 26-1 downto 0 );
    im_sub6 : out std_logic_vector( 26-1 downto 0 );
    re_sub7 : out std_logic_vector( 26-1 downto 0 );
    im_sub7 : out std_logic_vector( 26-1 downto 0 );
    re_sub8 : out std_logic_vector( 26-1 downto 0 );
    im_sub8 : out std_logic_vector( 26-1 downto 0 );
    re_sub9 : out std_logic_vector( 26-1 downto 0 );
    im_sub9 : out std_logic_vector( 26-1 downto 0 );
    re_sub10 : out std_logic_vector( 26-1 downto 0 );
    im_sub10 : out std_logic_vector( 26-1 downto 0 );
    re_sub11 : out std_logic_vector( 26-1 downto 0 );
    im_sub11 : out std_logic_vector( 26-1 downto 0 );
    re_sub12 : out std_logic_vector( 26-1 downto 0 );
    im_sub12 : out std_logic_vector( 26-1 downto 0 );
    re_sub13 : out std_logic_vector( 26-1 downto 0 );
    im_sub13 : out std_logic_vector( 26-1 downto 0 );
    re_sub14 : out std_logic_vector( 26-1 downto 0 );
    im_sub14 : out std_logic_vector( 26-1 downto 0 );
    re_sub15 : out std_logic_vector( 26-1 downto 0 );
    im_sub15 : out std_logic_vector( 26-1 downto 0 );
    re_sub16 : out std_logic_vector( 26-1 downto 0 );
    im_sub16 : out std_logic_vector( 26-1 downto 0 );
    db_aft_dmt_re : out std_logic_vector( 1-1 downto 0 );
    db_aft_dmt_im : out std_logic_vector( 1-1 downto 0 );
    db_bef_gi_re : out std_logic_vector( 21-1 downto 0 );
    db_bef_gi_im : out std_logic_vector( 21-1 downto 0 );
    sg_rev_framestart2 : out std_logic_vector( 1-1 downto 0 )
  );
end basic_dmt_sysgen_sipafft;
architecture structural of basic_dmt_sysgen_sipafft is 
  signal src_ce_net_x0 : std_logic;
  signal mcode1_loopouto_net : std_logic_vector( 8-1 downto 0 );
  signal fifo_dout_net : std_logic_vector( 26-1 downto 0 );
  signal assert4_dout_net : std_logic_vector( 8-1 downto 0 );
  signal serial_to_parallel1_dout_net : std_logic_vector( 416-1 downto 0 );
  signal assert5_dout_net : std_logic_vector( 2-1 downto 0 );
  signal mcode1_loopcounto_net : std_logic_vector( 8-1 downto 0 );
  signal constant3_op_net_x0 : std_logic_vector( 1-1 downto 0 );
  signal constant1_op_net : std_logic_vector( 1-1 downto 0 );
  signal src_clk_net : std_logic;
  signal assert1_dout_net : std_logic_vector( 8-1 downto 0 );
  signal assert2_dout_net : std_logic_vector( 1-1 downto 0 );
  signal serial_to_parallel_dout_net : std_logic_vector( 416-1 downto 0 );
  signal assert3_dout_net : std_logic_vector( 8-1 downto 0 );
  signal ce_net_x0 : std_logic;
  signal mcode1_stateo_net : std_logic_vector( 2-1 downto 0 );
  signal down_sample2_q_net : std_logic_vector( 1-1 downto 0 );
  signal mcode1_starto_net : std_logic_vector( 1-1 downto 0 );
  signal delay4_q_net_x1 : std_logic_vector( 21-1 downto 0 );
  signal delay4_q_net_x0 : std_logic_vector( 21-1 downto 0 );
  signal mcode1_outputbitcounto_net : std_logic_vector( 8-1 downto 0 );
  signal fifo1_dout_net_x0 : std_logic_vector( 26-1 downto 0 );
  signal fifo1_dout_net : std_logic_vector( 21-1 downto 0 );
  signal fifo1_dcount_net : std_logic_vector( 7-1 downto 0 );
  signal fifo1_empty_net : std_logic;
  signal fifo1_full_net : std_logic;
  signal up_sample2_q_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_push_net : std_logic;
  signal mcode1_pop_net : std_logic;
  signal delay8_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay7_q_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_sel_net : std_logic_vector( 1-1 downto 0 );
  signal delay6_q_net : std_logic_vector( 2-1 downto 0 );
  signal mux_y_net : std_logic_vector( 21-1 downto 0 );
  signal fifo2_empty_net : std_logic;
  signal up_sample_q_net : std_logic_vector( 1-1 downto 0 );
  signal fifo2_full_net : std_logic;
  signal delay2_q_net : std_logic_vector( 8-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 21-1 downto 0 );
  signal fifo2_dout_net : std_logic_vector( 21-1 downto 0 );
  signal delay_q_net : std_logic_vector( 7-1 downto 0 );
  signal delay4_q_net : std_logic_vector( 8-1 downto 0 );
  signal mcode1_framestart_net : std_logic_vector( 1-1 downto 0 );
  signal delay5_q_net : std_logic_vector( 8-1 downto 0 );
  signal up_sample1_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay3_q_net : std_logic_vector( 1-1 downto 0 );
  signal mcode1_y5_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y6_re_net : std_logic_vector( 26-1 downto 0 );
  signal delay4_q_net_x2 : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y6_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y7_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_y4_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y2_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y5_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y7_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_y2_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y1_im_net : std_logic_vector( 26-1 downto 0 );
  signal delay5_q_net_x0 : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y1_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y4_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y9_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y11_re_net : std_logic_vector( 26-1 downto 0 );
  signal delay1_q_net : std_logic_vector( 1-1 downto 0 );
  signal dest_clk_net_x0 : std_logic;
  signal mcode1_y10_im_net : std_logic_vector( 26-1 downto 0 );
  signal inp_recv_im_net : std_logic_vector( 21-1 downto 0 );
  signal src_clk_net_x0 : std_logic;
  signal src_ce_net : std_logic;
  signal dest_ce_net : std_logic;
  signal mcode1_y9_re_net : std_logic_vector( 26-1 downto 0 );
  signal dest_ce_net_x0 : std_logic;
  signal mcode1_y11_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y14_im_net : std_logic_vector( 26-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 1-1 downto 0 );
  signal inp_recv_re_net : std_logic_vector( 21-1 downto 0 );
  signal clk_net : std_logic;
  signal ce_net : std_logic;
  signal clk_net_x0 : std_logic;
  signal dest_clk_net : std_logic;
  signal down_sample1_q_net : std_logic_vector( 21-1 downto 0 );
  signal down_sample3_q_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_y12_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y12_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y16_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y16_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y14_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y15_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y15_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y13_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y13_re_net : std_logic_vector( 26-1 downto 0 );
begin
  db_aft_fft_re <= delay5_q_net_x0;
  db_aft_fft_im <= delay4_q_net_x2;
  db2_gi_re <= mcode1_out_re_net;
  db2_gi_im <= mcode1_out_im_net;
  re_sub1 <= mcode1_y1_re_net;
  im_sub1 <= mcode1_y1_im_net;
  re_sub2 <= mcode1_y2_re_net;
  im_sub2 <= mcode1_y2_im_net;
  re_sub3 <= mcode1_y3_re_net;
  im_sub3 <= mcode1_y3_im_net;
  re_sub4 <= mcode1_y4_re_net;
  im_sub4 <= mcode1_y4_im_net;
  re_sub5 <= mcode1_y5_re_net;
  im_sub5 <= mcode1_y5_im_net;
  re_sub6 <= mcode1_y6_re_net;
  im_sub6 <= mcode1_y6_im_net;
  re_sub7 <= mcode1_y7_re_net;
  im_sub7 <= mcode1_y7_im_net;
  re_sub8 <= mcode1_y8_re_net;
  im_sub8 <= mcode1_y8_im_net;
  re_sub9 <= mcode1_y9_re_net;
  im_sub9 <= mcode1_y9_im_net;
  re_sub10 <= mcode1_y10_re_net;
  im_sub10 <= mcode1_y10_im_net;
  re_sub11 <= mcode1_y11_re_net;
  im_sub11 <= mcode1_y11_im_net;
  re_sub12 <= mcode1_y12_re_net;
  im_sub12 <= mcode1_y12_im_net;
  re_sub13 <= mcode1_y13_re_net;
  im_sub13 <= mcode1_y13_im_net;
  re_sub14 <= mcode1_y14_re_net;
  im_sub14 <= mcode1_y14_im_net;
  re_sub15 <= mcode1_y15_re_net;
  im_sub15 <= mcode1_y15_im_net;
  re_sub16 <= mcode1_y16_re_net;
  im_sub16 <= mcode1_y16_im_net;
  db_aft_dmt_re <= constant3_op_net;
  db_aft_dmt_im <= constant3_op_net;
  db_bef_gi_re <= down_sample3_q_net;
  db_bef_gi_im <= down_sample1_q_net;
  inp_recv_re_net <= sg_re;
  inp_recv_im_net <= sg_im;
  sg_rev_framestart2 <= delay1_q_net;
  src_clk_net_x0 <= clk_1;
  src_ce_net <= ce_1;
  dest_clk_net <= clk_2;
  dest_ce_net <= ce_2;
  dest_clk_net_x0 <= clk_4;
  dest_ce_net_x0 <= ce_4;
  clk_net <= clk_5;
  ce_net <= ce_5;
  clk_net_x0 <= clk_14;
  ce_net_x0 <= ce_14;
  src_clk_net <= clk_64;
  src_ce_net_x0 <= ce_64;
  delayvar_x1 : entity xil_defaultlib.basic_dmt_delayvar_x0 
  port map (
    in1 => inp_recv_im_net,
    clk_14 => clk_net_x0,
    ce_14 => ce_net_x0,
    out1 => delay4_q_net_x1
  );
  delayvar1 : entity xil_defaultlib.basic_dmt_delayvar1 
  port map (
    in1 => inp_recv_re_net,
    clk_14 => clk_net_x0,
    ce_14 => ce_net_x0,
    out1 => delay4_q_net_x0
  );
  fft_x0 : entity xil_defaultlib.basic_dmt_fft 
  port map (
    sg_re => mcode1_out_re_net,
    sg_im => mcode1_out_im_net,
    clk_1 => src_clk_net_x0,
    ce_1 => src_ce_net,
    clk_2 => dest_clk_net,
    ce_2 => dest_ce_net,
    clk_4 => dest_clk_net_x0,
    ce_4 => dest_ce_net_x0,
    clk_5 => clk_net,
    ce_5 => ce_net,
    re_out => fifo1_dout_net_x0,
    im_out => fifo_dout_net,
    db_aft_dmt_re => constant3_op_net,
    db_aft_dmt_im => constant3_op_net
  );
  guard_interval_x0 : entity xil_defaultlib.basic_dmt_guard_interval_x0 
  port map (
    re_in => down_sample3_q_net,
    im_in => down_sample1_q_net,
    sg_rev_framestart => down_sample2_q_net,
    clk_4 => dest_clk_net_x0,
    ce_4 => dest_ce_net_x0,
    re => mcode1_out_re_net,
    im => mcode1_out_im_net
  );
  sysgen_equalizer : entity xil_defaultlib.basic_dmt_sysgen_equalizer 
  port map (
    re => serial_to_parallel_dout_net,
    im => serial_to_parallel1_dout_net,
    re_sub1 => mcode1_y1_re_net,
    im_sub1 => mcode1_y1_im_net,
    re_sub2 => mcode1_y2_re_net,
    im_sub2 => mcode1_y2_im_net,
    re_sub3 => mcode1_y3_re_net,
    im_sub3 => mcode1_y3_im_net,
    re_sub4 => mcode1_y4_re_net,
    im_sub4 => mcode1_y4_im_net,
    re_sub5 => mcode1_y5_re_net,
    im_sub5 => mcode1_y5_im_net,
    re_sub6 => mcode1_y6_re_net,
    im_sub6 => mcode1_y6_im_net,
    re_sub7 => mcode1_y7_re_net,
    im_sub7 => mcode1_y7_im_net,
    re_sub8 => mcode1_y8_re_net,
    im_sub8 => mcode1_y8_im_net,
    re_sub9 => mcode1_y9_re_net,
    im_sub9 => mcode1_y9_im_net,
    re_sub10 => mcode1_y10_re_net,
    im_sub10 => mcode1_y10_im_net,
    re_sub11 => mcode1_y11_re_net,
    im_sub11 => mcode1_y11_im_net,
    re_sub12 => mcode1_y12_re_net,
    im_sub12 => mcode1_y12_im_net,
    re_sub13 => mcode1_y13_re_net,
    im_sub13 => mcode1_y13_im_net,
    re_sub14 => mcode1_y14_re_net,
    im_sub14 => mcode1_y14_im_net,
    re_sub15 => mcode1_y15_re_net,
    im_sub15 => mcode1_y15_im_net,
    re_sub16 => mcode1_y16_re_net,
    im_sub16 => mcode1_y16_im_net
  );
  assert1 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode1_outputbitcounto_net,
    dout => assert1_dout_net
  );
  assert2 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 1,
    dout_width => 1
  )
  port map (
    din => mcode1_starto_net,
    dout => assert2_dout_net
  );
  assert3 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode1_loopouto_net,
    dout => assert3_dout_net
  );
  assert4 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 8,
    dout_width => 8
  )
  port map (
    din => mcode1_loopcounto_net,
    dout => assert4_dout_net
  );
  assert5 : entity xil_defaultlib.xlpassthrough 
  generic map (
    din_width => 2,
    dout_width => 2
  )
  port map (
    din => mcode1_stateo_net,
    dout => assert5_dout_net
  );
  constant1 : entity xil_defaultlib.sysgen_constant_24f5f1f6d4 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant1_op_net
  );
  constant3 : entity xil_defaultlib.sysgen_constant_c4c1fd841d 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    op => constant3_op_net_x0
  );
  delay4_x0 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 5,
    reg_retiming => 0,
    reset => 0,
    width => 26
  )
  port map (
    en => '1',
    rst => '1',
    d => fifo_dout_net,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q => delay4_q_net_x2
  );
  delay5_x0 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 5,
    reg_retiming => 0,
    reset => 0,
    width => 26
  )
  port map (
    en => '1',
    rst => '1',
    d => fifo1_dout_net_x0,
    clk => dest_clk_net_x0,
    ce => dest_ce_net_x0,
    q => delay5_q_net_x0
  );
  down_sample1 : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 21,
    ds_ratio => 4,
    latency => 1,
    phase => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 21
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => delay7_q_net,
    src_clk => src_clk_net_x0,
    src_ce => src_ce_net,
    dest_clk => dest_clk_net_x0,
    dest_ce => dest_ce_net_x0,
    q => down_sample1_q_net
  );
  down_sample2 : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlUnsigned,
    d_bin_pt => 0,
    d_width => 1,
    ds_ratio => 4,
    latency => 0,
    phase => 0,
    q_arith => xlUnsigned,
    q_bin_pt => 0,
    q_width => 1
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => delay1_q_net,
    src_clk => src_clk_net_x0,
    src_ce => src_ce_net,
    dest_clk => dest_clk_net_x0,
    dest_ce => dest_ce_net_x0,
    q => down_sample2_q_net
  );
  down_sample3 : entity xil_defaultlib.basic_dmt_xldsamp 
  generic map (
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 21,
    ds_ratio => 4,
    latency => 1,
    phase => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 21
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    d => delay8_q_net,
    src_clk => src_clk_net_x0,
    src_ce => src_ce_net,
    dest_clk => dest_clk_net_x0,
    dest_ce => dest_ce_net_x0,
    q => down_sample3_q_net
  );
  fifo1 : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_0",
    data_count_width => 7,
    data_width => 21,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => up_sample2_q_net,
    we => mcode1_push_net,
    re => mcode1_pop_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    we_ce => src_ce_net,
    re_ce => src_ce_net,
    dout => fifo1_dout_net,
    empty => fifo1_empty_net,
    full => fifo1_full_net,
    dcount => fifo1_dcount_net
  );
  fifo2 : entity xil_defaultlib.basic_dmt_xlfifogen 
  generic map (
    core_name0 => "basic_dmt_fifo_generator_v12_0_1",
    data_count_width => 7,
    data_width => 21,
    extra_registers => 0,
    has_ae => 0,
    has_af => 0,
    percent_full_width => 4
  )
  port map (
    en => '1',
    rst => '1',
    din => up_sample1_q_net,
    we => mcode1_push_net,
    re => mcode1_pop_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    we_ce => src_ce_net,
    re_ce => src_ce_net,
    dout => fifo2_dout_net,
    empty => fifo2_empty_net,
    full => fifo2_full_net
  );
  mcode1 : entity xil_defaultlib.sysgen_mcode_block_c1f15f41da 
  port map (
    clk => '0',
    ce => '0',
    clr => '0',
    num => delay_q_net,
    frameen => up_sample_q_net,
    statei => delay6_q_net,
    loopcounti => delay5_q_net,
    loopouti => delay4_q_net,
    starti => delay3_q_net,
    outputbitcounti => delay2_q_net,
    sel => mcode1_sel_net,
    push(0) => mcode1_push_net,
    pop(0) => mcode1_pop_net,
    framestart => mcode1_framestart_net,
    stateo => mcode1_stateo_net,
    loopcounto => mcode1_loopcounto_net,
    loopouto => mcode1_loopouto_net,
    starto => mcode1_starto_net,
    outputbitcounto => mcode1_outputbitcounto_net
  );
  mux : entity xil_defaultlib.sysgen_mux_427790cdf8 
  port map (
    clr => '0',
    sel => mcode1_sel_net,
    d0 => constant3_op_net_x0,
    d1 => fifo1_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    y => mux_y_net
  );
  mux1 : entity xil_defaultlib.sysgen_mux_427790cdf8 
  port map (
    clr => '0',
    sel => mcode1_sel_net,
    d0 => constant3_op_net_x0,
    d1 => fifo2_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    y => mux1_y_net
  );
  serial_to_parallel : entity xil_defaultlib.basic_dmt_xls2p 
  generic map (
    din_arith => xlSigned,
    din_bin_pt => 20,
    din_width => 26,
    dout_arith => xlUnsigned,
    dout_bin_pt => 0,
    dout_width => 416,
    latency => 1,
    lsb_first => 0,
    num_inputs => 16
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    din => delay5_q_net_x0,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net_x0,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net_x0,
    dout => serial_to_parallel_dout_net
  );
  serial_to_parallel1 : entity xil_defaultlib.basic_dmt_xls2p 
  generic map (
    din_arith => xlSigned,
    din_bin_pt => 20,
    din_width => 26,
    dout_arith => xlUnsigned,
    dout_bin_pt => 0,
    dout_width => 416,
    latency => 1,
    lsb_first => 0,
    num_inputs => 16
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    rst => "0",
    din => delay4_q_net_x2,
    src_clk => dest_clk_net_x0,
    src_ce => dest_ce_net_x0,
    dest_clk => src_clk_net,
    dest_ce => src_ce_net_x0,
    dout => serial_to_parallel1_dout_net
  );
  up_sample : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 0,
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
    d => constant1_op_net,
    src_clk => src_clk_net,
    src_ce => src_ce_net_x0,
    dest_clk => src_clk_net_x0,
    dest_ce => src_ce_net,
    q => up_sample_q_net
  );
  up_sample1 : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 1,
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 21,
    latency => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 21
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    d => delay4_q_net_x0,
    src_clk => clk_net_x0,
    src_ce => ce_net_x0,
    dest_clk => src_clk_net_x0,
    dest_ce => src_ce_net,
    q => up_sample1_q_net
  );
  up_sample2 : entity xil_defaultlib.basic_dmt_xlusamp 
  generic map (
    copy_samples => 1,
    d_arith => xlSigned,
    d_bin_pt => 13,
    d_width => 21,
    latency => 0,
    q_arith => xlSigned,
    q_bin_pt => 13,
    q_width => 21
  )
  port map (
    src_clr => '0',
    dest_clr => '0',
    en => "1",
    d => delay4_q_net_x1,
    src_clk => clk_net_x0,
    src_ce => ce_net_x0,
    dest_clk => src_clk_net_x0,
    dest_ce => src_ce_net,
    q => up_sample2_q_net
  );
  delay : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 7
  )
  port map (
    en => '1',
    rst => '1',
    d => fifo1_dcount_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay_q_net
  );
  delay1 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 4,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => mcode1_framestart_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay1_q_net
  );
  delay2 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert1_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay2_q_net
  );
  delay3 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 1
  )
  port map (
    en => '1',
    rst => '1',
    d => assert2_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay3_q_net
  );
  delay4 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert3_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay4_q_net
  );
  delay5 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 8
  )
  port map (
    en => '1',
    rst => '1',
    d => assert4_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay5_q_net
  );
  delay6 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 1,
    reg_retiming => 0,
    reset => 0,
    width => 2
  )
  port map (
    en => '1',
    rst => '1',
    d => assert5_dout_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay6_q_net
  );
  delay7 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 2,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => mux_y_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay7_q_net
  );
  delay8 : entity xil_defaultlib.basic_dmt_xldelay 
  generic map (
    latency => 2,
    reg_retiming => 0,
    reset => 0,
    width => 21
  )
  port map (
    en => '1',
    rst => '1',
    d => mux1_y_net,
    clk => src_clk_net_x0,
    ce => src_ce_net,
    q => delay8_q_net
  );
end structural;
-- Generated from Simulink block Basic_DMT_struct
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_struct is
  port (
    inp_recv_im : in std_logic_vector( 21-1 downto 0 );
    inp_recv_re : in std_logic_vector( 21-1 downto 0 );
    inp_trans : in std_logic_vector( 1-1 downto 0 );
    clk_1 : in std_logic;
    ce_1 : in std_logic;
    clk_2 : in std_logic;
    ce_2 : in std_logic;
    clk_4 : in std_logic;
    ce_4 : in std_logic;
    clk_5 : in std_logic;
    ce_5 : in std_logic;
    clk_14 : in std_logic;
    ce_14 : in std_logic;
    clk_16 : in std_logic;
    ce_16 : in std_logic;
    clk_64 : in std_logic;
    ce_64 : in std_logic;
    clk_256 : in std_logic;
    ce_256 : in std_logic;
    out_recv : out std_logic_vector( 1-1 downto 0 );
    out_trans_im : out std_logic_vector( 21-1 downto 0 );
    out_trans_re : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt_struct;
architecture structural of basic_dmt_struct is 
  signal down_sample17_q_net : std_logic_vector( 1-1 downto 0 );
  signal delay2_q_net : std_logic_vector( 21-1 downto 0 );
  signal inp_trans_net : std_logic_vector( 1-1 downto 0 );
  signal inp_recv_im_net : std_logic_vector( 21-1 downto 0 );
  signal src_ce_net_x0 : std_logic;
  signal src_clk_net_x0 : std_logic;
  signal dest_clk_net_x0 : std_logic;
  signal dest_ce_net : std_logic;
  signal delay3_q_net : std_logic_vector( 21-1 downto 0 );
  signal inp_recv_re_net : std_logic_vector( 21-1 downto 0 );
  signal src_clk_net : std_logic;
  signal mcode5_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode10_y1_net : std_logic_vector( 4-1 downto 0 );
  signal ce_net_x0 : std_logic;
  signal mcode14_y1_net : std_logic_vector( 4-1 downto 0 );
  signal clk_net : std_logic;
  signal mcode1_y1_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y2_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y3_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y5_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode8_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y7_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y2_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y7_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode2_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y8_im_net : std_logic_vector( 26-1 downto 0 );
  signal dest_clk_net_x1 : std_logic;
  signal mcode1_y5_re_net : std_logic_vector( 26-1 downto 0 );
  signal src_ce_net : std_logic;
  signal mcode1_y6_re_net : std_logic_vector( 26-1 downto 0 );
  signal ce_net : std_logic;
  signal mcode12_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y6_im_net : std_logic_vector( 26-1 downto 0 );
  signal down_sample1_q_net_x0 : std_logic_vector( 21-1 downto 0 );
  signal mcode3_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y3_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y8_re_net : std_logic_vector( 26-1 downto 0 );
  signal src_clk_net_x1 : std_logic;
  signal src_ce_net_x1 : std_logic;
  signal mcode1_y1_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y4_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y9_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y10_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode16_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y11_re_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y4_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y11_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_y12_re_net : std_logic_vector( 26-1 downto 0 );
  signal dest_ce_net_x0 : std_logic;
  signal mcode11_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode15_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y9_im_net : std_logic_vector( 26-1 downto 0 );
  signal mcode4_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode7_y1_net : std_logic_vector( 4-1 downto 0 );
  signal dest_ce_net_x1 : std_logic;
  signal down_sample_q_net : std_logic_vector( 21-1 downto 0 );
  signal mcode1_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode6_y1_net : std_logic_vector( 4-1 downto 0 );
  signal clk_net_x0 : std_logic;
  signal dest_clk_net : std_logic;
  signal mcode9_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mcode13_y1_net : std_logic_vector( 4-1 downto 0 );
  signal mux1_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x11 : std_logic_vector( 16-1 downto 0 );
  signal slice30_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux1_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal slice5_y_net : std_logic_vector( 4-1 downto 0 );
  signal delay5_q_net_x0 : std_logic_vector( 21-1 downto 0 );
  signal mcode1_y13_im_net : std_logic_vector( 26-1 downto 0 );
  signal mux1_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal mcode1_y16_im_net : std_logic_vector( 26-1 downto 0 );
  signal mux1_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal slice7_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice6_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice2_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux_y_net_x5 : std_logic_vector( 16-1 downto 0 );
  signal mcode1_y16_re_net : std_logic_vector( 26-1 downto 0 );
  signal slice29_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice4_y_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y15_im_net : std_logic_vector( 26-1 downto 0 );
  signal mux_y_net_x15 : std_logic_vector( 16-1 downto 0 );
  signal slice13_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice14_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux_y_net_x8 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x7 : std_logic_vector( 16-1 downto 0 );
  signal mcode1_y12_im_net : std_logic_vector( 26-1 downto 0 );
  signal mux_y_net_x13 : std_logic_vector( 16-1 downto 0 );
  signal slice1_y_net : std_logic_vector( 4-1 downto 0 );
  signal slice3_y_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y15_re_net : std_logic_vector( 26-1 downto 0 );
  signal mux1_y_net_x1 : std_logic_vector( 16-1 downto 0 );
  signal slice12_y_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_y14_im_net : std_logic_vector( 26-1 downto 0 );
  signal mux_y_net_x10 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x2 : std_logic_vector( 16-1 downto 0 );
  signal slice11_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux_y_net_x6 : std_logic_vector( 16-1 downto 0 );
  signal slice10_y_net : std_logic_vector( 4-1 downto 0 );
  signal mcode1_framestart_net : std_logic_vector( 1-1 downto 0 );
  signal slice8_y_net : std_logic_vector( 4-1 downto 0 );
  signal mux1_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x9 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x14 : std_logic_vector( 16-1 downto 0 );
  signal mcode_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal mux_y_net_x12 : std_logic_vector( 16-1 downto 0 );
  signal delay4_q_net_x0 : std_logic_vector( 21-1 downto 0 );
  signal slice9_y_net : std_logic_vector( 4-1 downto 0 );
  signal mcode_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal mux1_y_net : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mcode1_y13_re_net : std_logic_vector( 26-1 downto 0 );
  signal mux1_y_net_x15 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal mux1_y_net_x3 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net : std_logic_vector( 16-1 downto 0 );
  signal mcode1_y14_re_net : std_logic_vector( 26-1 downto 0 );
  signal mux_y_net_x4 : std_logic_vector( 16-1 downto 0 );
  signal mux_y_net_x0 : std_logic_vector( 16-1 downto 0 );
  signal delay5_q_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_out_im_net : std_logic_vector( 21-1 downto 0 );
  signal delay1_q_net : std_logic_vector( 1-1 downto 0 );
  signal constant3_op_net : std_logic_vector( 1-1 downto 0 );
  signal delay7_q_net : std_logic_vector( 1-1 downto 0 );
  signal down_sample3_q_net : std_logic_vector( 21-1 downto 0 );
  signal delay8_q_net : std_logic_vector( 1-1 downto 0 );
  signal delay4_q_net : std_logic_vector( 26-1 downto 0 );
  signal mcode1_out_re_net : std_logic_vector( 21-1 downto 0 );
  signal down_sample1_q_net : std_logic_vector( 21-1 downto 0 );
begin
  inp_recv_im_net <= inp_recv_im;
  inp_recv_re_net <= inp_recv_re;
  out_recv <= down_sample17_q_net;
  out_trans_im <= delay3_q_net;
  out_trans_re <= delay2_q_net;
  inp_trans_net <= inp_trans;
  src_clk_net_x0 <= clk_1;
  src_ce_net_x0 <= ce_1;
  dest_clk_net_x0 <= clk_2;
  dest_ce_net <= ce_2;
  dest_clk_net <= clk_4;
  dest_ce_net_x0 <= ce_4;
  clk_net <= clk_5;
  ce_net <= ce_5;
  clk_net_x0 <= clk_14;
  ce_net_x0 <= ce_14;
  dest_clk_net_x1 <= clk_16;
  dest_ce_net_x1 <= ce_16;
  src_clk_net_x1 <= clk_64;
  src_ce_net_x1 <= ce_64;
  src_clk_net <= clk_256;
  src_ce_net <= ce_256;
  sysgen_channel : entity xil_defaultlib.basic_dmt_sysgen_channel 
  port map (
    re => down_sample_q_net,
    im => down_sample1_q_net_x0,
    clk_14 => clk_net_x0,
    ce_14 => ce_net_x0,
    re_out => delay2_q_net,
    im_out => delay3_q_net
  );
  sysgen_demodulation : entity xil_defaultlib.basic_dmt_sysgen_demodulation 
  port map (
    re_sub1 => mcode1_y1_re_net,
    im_sub1 => mcode1_y1_im_net,
    re_sub2 => mcode1_y2_re_net,
    im_sub2 => mcode1_y2_im_net,
    re_sub3 => mcode1_y3_re_net,
    im_sub3 => mcode1_y3_im_net,
    re_sub4 => mcode1_y4_re_net,
    im_sub4 => mcode1_y4_im_net,
    re_sub5 => mcode1_y5_re_net,
    im_sub5 => mcode1_y5_im_net,
    re_sub6 => mcode1_y6_re_net,
    im_sub6 => mcode1_y6_im_net,
    re_sub7 => mcode1_y7_re_net,
    im_sub7 => mcode1_y7_im_net,
    re_sub8 => mcode1_y8_re_net,
    im_sub8 => mcode1_y8_im_net,
    re_sub9 => mcode1_y9_re_net,
    im_sub9 => mcode1_y9_im_net,
    re_sub10 => mcode1_y10_re_net,
    im_sub10 => mcode1_y10_im_net,
    re_sub11 => mcode1_y11_re_net,
    im_sub11 => mcode1_y11_im_net,
    re_sub12 => mcode1_y12_re_net,
    im_sub12 => mcode1_y12_im_net,
    re_sub13 => mcode1_y13_re_net,
    im_sub13 => mcode1_y13_im_net,
    re_sub14 => mcode1_y14_re_net,
    im_sub14 => mcode1_y14_im_net,
    re_sub15 => mcode1_y15_re_net,
    im_sub15 => mcode1_y15_im_net,
    re_sub16 => mcode1_y16_re_net,
    im_sub16 => mcode1_y16_im_net,
    bit_sub1 => mcode1_y1_net,
    bit_sub2 => mcode2_y1_net,
    bit_sub3 => mcode3_y1_net,
    bit_sub4 => mcode4_y1_net,
    bit_sub5 => mcode5_y1_net,
    bit_sub6 => mcode6_y1_net,
    bit_sub7 => mcode7_y1_net,
    bit_sub8 => mcode8_y1_net,
    bit_sub9 => mcode9_y1_net,
    bit_sub10 => mcode10_y1_net,
    bit_sub11 => mcode11_y1_net,
    bit_sub12 => mcode12_y1_net,
    bit_sub13 => mcode13_y1_net,
    bit_sub14 => mcode14_y1_net,
    bit_sub15 => mcode15_y1_net,
    bit_sub16 => mcode16_y1_net
  );
  sysgen_ifftapis : entity xil_defaultlib.basic_dmt_sysgen_ifftapis 
  port map (
    re_sub1 => mux_y_net_x14,
    im_sub1 => mux1_y_net_x14,
    re_sub2 => mux_y_net_x6,
    im_sub2 => mux1_y_net_x6,
    re_sub3 => mux_y_net_x5,
    im_sub3 => mux1_y_net_x5,
    re_sub4 => mux_y_net_x4,
    im_sub4 => mux1_y_net_x4,
    re_sub5 => mux_y_net_x3,
    im_sub5 => mux1_y_net_x3,
    re_sub6 => mux_y_net_x2,
    im_sub6 => mux1_y_net_x2,
    re_sub7 => mux_y_net_x1,
    im_sub7 => mux1_y_net_x1,
    re_sub8 => mux_y_net_x0,
    im_sub8 => mux1_y_net_x0,
    re_sub9 => mux_y_net,
    im_sub9 => mux1_y_net,
    re_sub10 => mux_y_net_x13,
    im_sub10 => mux1_y_net_x13,
    re_sub11 => mux_y_net_x12,
    im_sub11 => mux1_y_net_x12,
    re_sub12 => mux_y_net_x11,
    im_sub12 => mux1_y_net_x11,
    re_sub13 => mux_y_net_x10,
    im_sub13 => mux1_y_net_x10,
    re_sub14 => mux_y_net_x9,
    im_sub14 => mux1_y_net_x9,
    re_sub15 => mux_y_net_x8,
    im_sub15 => mux1_y_net_x8,
    re_sub16 => mux_y_net_x7,
    im_sub16 => mux1_y_net_x7,
    sgframestart => mcode1_framestart_net,
    clk_1 => src_clk_net_x0,
    ce_1 => src_ce_net_x0,
    clk_2 => dest_clk_net_x0,
    ce_2 => dest_ce_net,
    clk_4 => dest_clk_net,
    ce_4 => dest_ce_net_x0,
    clk_5 => clk_net,
    ce_5 => ce_net,
    clk_14 => clk_net_x0,
    ce_14 => ce_net_x0,
    clk_64 => src_clk_net_x1,
    ce_64 => src_ce_net_x1,
    re => down_sample_q_net,
    im => down_sample1_q_net_x0,
    db_aft_frame_re => mux_y_net_x15,
    db_aft_frame_im => mux1_y_net_x15,
    db_aft_fft_re => delay4_q_net_x0,
    db_aft_fft_im => delay5_q_net_x0,
    db_aft_gi_re => mcode_out_re_net,
    db_aft_gi_im => mcode_out_im_net
  );
  sysgen_modulation : entity xil_defaultlib.basic_dmt_sysgen_modulation 
  port map (
    sub1 => slice30_y_net,
    sub2 => slice29_y_net,
    sub3 => slice7_y_net,
    sub4 => slice6_y_net,
    sub5 => slice5_y_net,
    sub6 => slice4_y_net,
    sub7 => slice3_y_net,
    sub8 => slice2_y_net,
    sub9 => slice1_y_net,
    sub10 => slice13_y_net,
    sub11 => slice14_y_net,
    sub12 => slice12_y_net,
    sub13 => slice11_y_net,
    sub14 => slice10_y_net,
    sub15 => slice8_y_net,
    sub16 => slice9_y_net,
    clk_64 => src_clk_net_x1,
    ce_64 => src_ce_net_x1,
    re_sub1 => mux_y_net_x14,
    im_sub1 => mux1_y_net_x14,
    re_sub2 => mux_y_net_x6,
    im_sub2 => mux1_y_net_x6,
    re_sub3 => mux_y_net_x5,
    im_sub3 => mux1_y_net_x5,
    re_sub4 => mux_y_net_x4,
    im_sub4 => mux1_y_net_x4,
    re_sub5 => mux_y_net_x3,
    im_sub5 => mux1_y_net_x3,
    re_sub6 => mux_y_net_x2,
    im_sub6 => mux1_y_net_x2,
    re_sub7 => mux_y_net_x1,
    im_sub7 => mux1_y_net_x1,
    re_sub8 => mux_y_net_x0,
    im_sub8 => mux1_y_net_x0,
    re_sub9 => mux_y_net,
    im_sub9 => mux1_y_net,
    re_sub10 => mux_y_net_x13,
    im_sub10 => mux1_y_net_x13,
    re_sub11 => mux_y_net_x12,
    im_sub11 => mux1_y_net_x12,
    re_sub12 => mux_y_net_x11,
    im_sub12 => mux1_y_net_x11,
    re_sub13 => mux_y_net_x10,
    im_sub13 => mux1_y_net_x10,
    re_sub14 => mux_y_net_x9,
    im_sub14 => mux1_y_net_x9,
    re_sub15 => mux_y_net_x8,
    im_sub15 => mux1_y_net_x8,
    re_sub16 => mux_y_net_x7,
    im_sub16 => mux1_y_net_x7
  );
  sysgen_pis : entity xil_defaultlib.basic_dmt_sysgen_pis 
  port map (
    bit_sub1 => mcode1_y1_net,
    bit_sub2 => mcode2_y1_net,
    bit_sub3 => mcode3_y1_net,
    bit_sub4 => mcode4_y1_net,
    bit_sub5 => mcode5_y1_net,
    bit_sub6 => mcode6_y1_net,
    bit_sub7 => mcode7_y1_net,
    bit_sub8 => mcode8_y1_net,
    bit_sub9 => mcode9_y1_net,
    bit_sub10 => mcode10_y1_net,
    bit_sub11 => mcode11_y1_net,
    bit_sub12 => mcode12_y1_net,
    bit_sub13 => mcode13_y1_net,
    bit_sub14 => mcode14_y1_net,
    bit_sub15 => mcode15_y1_net,
    bit_sub16 => mcode16_y1_net,
    sg_rev_framestart2 => delay1_q_net,
    clk_1 => src_clk_net_x0,
    ce_1 => src_ce_net_x0,
    clk_5 => clk_net,
    ce_5 => ce_net,
    clk_64 => src_clk_net_x1,
    ce_64 => src_ce_net_x1,
    bit => down_sample17_q_net,
    db_bef_fifo => delay8_q_net
  );
  sysgen_sip : entity xil_defaultlib.basic_dmt_sysgen_sip 
  port map (
    inp_trans => inp_trans_net,
    clk_1 => src_clk_net_x0,
    ce_1 => src_ce_net_x0,
    clk_64 => src_clk_net_x1,
    ce_64 => src_ce_net_x1,
    clk_256 => src_clk_net,
    ce_256 => src_ce_net,
    sub1 => slice30_y_net,
    sub2 => slice29_y_net,
    sub3 => slice7_y_net,
    sub4 => slice6_y_net,
    sub5 => slice5_y_net,
    sub6 => slice4_y_net,
    sub7 => slice3_y_net,
    sub8 => slice2_y_net,
    sub9 => slice1_y_net,
    sub10 => slice13_y_net,
    sub11 => slice14_y_net,
    sub12 => slice12_y_net,
    sub13 => slice11_y_net,
    sub14 => slice10_y_net,
    sub15 => slice8_y_net,
    sub16 => slice9_y_net,
    dbbitstream => delay7_q_net,
    sgframestart => mcode1_framestart_net
  );
  sysgen_sipafft : entity xil_defaultlib.basic_dmt_sysgen_sipafft 
  port map (
    sg_re => inp_recv_re_net,
    sg_im => inp_recv_im_net,
    clk_1 => src_clk_net_x0,
    ce_1 => src_ce_net_x0,
    clk_2 => dest_clk_net_x0,
    ce_2 => dest_ce_net,
    clk_4 => dest_clk_net,
    ce_4 => dest_ce_net_x0,
    clk_5 => clk_net,
    ce_5 => ce_net,
    clk_14 => clk_net_x0,
    ce_14 => ce_net_x0,
    clk_64 => src_clk_net_x1,
    ce_64 => src_ce_net_x1,
    db_aft_fft_re => delay5_q_net,
    db_aft_fft_im => delay4_q_net,
    db2_gi_re => mcode1_out_re_net,
    db2_gi_im => mcode1_out_im_net,
    re_sub1 => mcode1_y1_re_net,
    im_sub1 => mcode1_y1_im_net,
    re_sub2 => mcode1_y2_re_net,
    im_sub2 => mcode1_y2_im_net,
    re_sub3 => mcode1_y3_re_net,
    im_sub3 => mcode1_y3_im_net,
    re_sub4 => mcode1_y4_re_net,
    im_sub4 => mcode1_y4_im_net,
    re_sub5 => mcode1_y5_re_net,
    im_sub5 => mcode1_y5_im_net,
    re_sub6 => mcode1_y6_re_net,
    im_sub6 => mcode1_y6_im_net,
    re_sub7 => mcode1_y7_re_net,
    im_sub7 => mcode1_y7_im_net,
    re_sub8 => mcode1_y8_re_net,
    im_sub8 => mcode1_y8_im_net,
    re_sub9 => mcode1_y9_re_net,
    im_sub9 => mcode1_y9_im_net,
    re_sub10 => mcode1_y10_re_net,
    im_sub10 => mcode1_y10_im_net,
    re_sub11 => mcode1_y11_re_net,
    im_sub11 => mcode1_y11_im_net,
    re_sub12 => mcode1_y12_re_net,
    im_sub12 => mcode1_y12_im_net,
    re_sub13 => mcode1_y13_re_net,
    im_sub13 => mcode1_y13_im_net,
    re_sub14 => mcode1_y14_re_net,
    im_sub14 => mcode1_y14_im_net,
    re_sub15 => mcode1_y15_re_net,
    im_sub15 => mcode1_y15_im_net,
    re_sub16 => mcode1_y16_re_net,
    im_sub16 => mcode1_y16_im_net,
    db_aft_dmt_re => constant3_op_net,
    db_aft_dmt_im => constant3_op_net,
    db_bef_gi_re => down_sample3_q_net,
    db_bef_gi_im => down_sample1_q_net,
    sg_rev_framestart2 => delay1_q_net
  );
end structural;
-- Generated from Simulink block 
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt_default_clock_driver is
  port (
    basic_dmt_sysclk : in std_logic;
    basic_dmt_sysce : in std_logic;
    basic_dmt_sysclr : in std_logic;
    basic_dmt_clk1 : out std_logic;
    basic_dmt_ce1 : out std_logic;
    basic_dmt_clk2 : out std_logic;
    basic_dmt_ce2 : out std_logic;
    basic_dmt_clk4 : out std_logic;
    basic_dmt_ce4 : out std_logic;
    basic_dmt_clk5 : out std_logic;
    basic_dmt_ce5 : out std_logic;
    basic_dmt_clk14 : out std_logic;
    basic_dmt_ce14 : out std_logic;
    basic_dmt_clk16 : out std_logic;
    basic_dmt_ce16 : out std_logic;
    basic_dmt_clk64 : out std_logic;
    basic_dmt_ce64 : out std_logic;
    basic_dmt_clk256 : out std_logic;
    basic_dmt_ce256 : out std_logic
  );
end basic_dmt_default_clock_driver;
architecture structural of basic_dmt_default_clock_driver is 
begin
  clockdriver_x6 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 1,
    log_2_period => 1
  )
  port map (
    sysclk => basic_dmt_sysclk,
    sysce => basic_dmt_sysce,
    sysclr => basic_dmt_sysclr,
    clk => basic_dmt_clk1,
    ce => basic_dmt_ce1
  );
  clockdriver_x5 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 2,
    log_2_period => 2
  )
  port map (
    sysclk => basic_dmt_sysclk,
    sysce => basic_dmt_sysce,
    sysclr => basic_dmt_sysclr,
    clk => basic_dmt_clk2,
    ce => basic_dmt_ce2
  );
  clockdriver_x4 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 4,
    log_2_period => 3
  )
  port map (
    sysclk => basic_dmt_sysclk,
    sysce => basic_dmt_sysce,
    sysclr => basic_dmt_sysclr,
    clk => basic_dmt_clk4,
    ce => basic_dmt_ce4
  );
  clockdriver_x3 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 5,
    log_2_period => 3
  )
  port map (
    sysclk => basic_dmt_sysclk,
    sysce => basic_dmt_sysce,
    sysclr => basic_dmt_sysclr,
    clk => basic_dmt_clk5,
    ce => basic_dmt_ce5
  );
  clockdriver_x2 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 14,
    log_2_period => 4
  )
  port map (
    sysclk => basic_dmt_sysclk,
    sysce => basic_dmt_sysce,
    sysclr => basic_dmt_sysclr,
    clk => basic_dmt_clk14,
    ce => basic_dmt_ce14
  );
  clockdriver_x1 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 16,
    log_2_period => 5
  )
  port map (
    sysclk => basic_dmt_sysclk,
    sysce => basic_dmt_sysce,
    sysclr => basic_dmt_sysclr,
    clk => basic_dmt_clk16,
    ce => basic_dmt_ce16
  );
  clockdriver_x0 : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 64,
    log_2_period => 7
  )
  port map (
    sysclk => basic_dmt_sysclk,
    sysce => basic_dmt_sysce,
    sysclr => basic_dmt_sysclr,
    clk => basic_dmt_clk64,
    ce => basic_dmt_ce64
  );
  clockdriver : entity xil_defaultlib.xlclockdriver 
  generic map (
    period => 256,
    log_2_period => 9
  )
  port map (
    sysclk => basic_dmt_sysclk,
    sysce => basic_dmt_sysce,
    sysclr => basic_dmt_sysclr,
    clk => basic_dmt_clk256,
    ce => basic_dmt_ce256
  );
end structural;
-- Generated from Simulink block 
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;
entity basic_dmt is
  port (
    inp_recv_im : in std_logic_vector( 21-1 downto 0 );
    inp_recv_re : in std_logic_vector( 21-1 downto 0 );
    inp_trans : in std_logic_vector( 1-1 downto 0 );
    clk : in std_logic;
    out_recv : out std_logic_vector( 1-1 downto 0 );
    out_trans_im : out std_logic_vector( 21-1 downto 0 );
    out_trans_re : out std_logic_vector( 21-1 downto 0 )
  );
end basic_dmt;
architecture structural of basic_dmt is 
  attribute core_generation_info : string;
  attribute core_generation_info of structural : architecture is "basic_dmt,sysgen_core_2014_4,{,compilation=IP Catalog,block_icon_display=Default,family=zynq,part=xc7z020,speed=-1,package=clg400,synthesis_language=vhdl,hdl_library=xil_defaultlib,synthesis_strategy=Vivado Synthesis Defaults,implementation_strategy=Vivado Implementation Defaults,clock_loc=,testbench=1,interface_doc=1,ce_clr=0,clock_period=4,system_simulink_period=4e-09,simulation_time=4e-05,addsub=2,assert=50,bitbasher=16,concat=1,constant=148,convert=2,counter=2,delay=88,dsamp=9,fifo=10,mcode=25,mux=37,p2s=5,reinterpret=8,relational=2,s2p=3,shift=2,slice=32,usamp=12,xfft_v9_0=2,}";
  signal ce_4_net : std_logic;
  signal clk_5_net : std_logic;
  signal ce_5_net : std_logic;
  signal clk_14_net : std_logic;
  signal clk_2_net : std_logic;
  signal clk_16_net : std_logic;
  signal clk_64_net : std_logic;
  signal ce_64_net : std_logic;
  signal ce_16_net : std_logic;
  signal clk_256_net : std_logic;
  signal ce_14_net : std_logic;
  signal ce_256_net : std_logic;
  signal ce_2_net : std_logic;
  signal ce_1_net : std_logic;
  signal clk_4_net : std_logic;
  signal clk_1_net : std_logic;
begin
  basic_dmt_default_clock_driver : entity xil_defaultlib.basic_dmt_default_clock_driver 
  port map (
    basic_dmt_sysclk => clk,
    basic_dmt_sysce => '1',
    basic_dmt_sysclr => '0',
    basic_dmt_clk1 => clk_1_net,
    basic_dmt_ce1 => ce_1_net,
    basic_dmt_clk2 => clk_2_net,
    basic_dmt_ce2 => ce_2_net,
    basic_dmt_clk4 => clk_4_net,
    basic_dmt_ce4 => ce_4_net,
    basic_dmt_clk5 => clk_5_net,
    basic_dmt_ce5 => ce_5_net,
    basic_dmt_clk14 => clk_14_net,
    basic_dmt_ce14 => ce_14_net,
    basic_dmt_clk16 => clk_16_net,
    basic_dmt_ce16 => ce_16_net,
    basic_dmt_clk64 => clk_64_net,
    basic_dmt_ce64 => ce_64_net,
    basic_dmt_clk256 => clk_256_net,
    basic_dmt_ce256 => ce_256_net
  );
  basic_dmt_struct : entity xil_defaultlib.basic_dmt_struct 
  port map (
    inp_recv_im => inp_recv_im,
    inp_recv_re => inp_recv_re,
    inp_trans => inp_trans,
    clk_1 => clk_1_net,
    ce_1 => ce_1_net,
    clk_2 => clk_2_net,
    ce_2 => ce_2_net,
    clk_4 => clk_4_net,
    ce_4 => ce_4_net,
    clk_5 => clk_5_net,
    ce_5 => ce_5_net,
    clk_14 => clk_14_net,
    ce_14 => ce_14_net,
    clk_16 => clk_16_net,
    ce_16 => ce_16_net,
    clk_64 => clk_64_net,
    ce_64 => ce_64_net,
    clk_256 => clk_256_net,
    ce_256 => ce_256_net,
    out_recv => out_recv,
    out_trans_im => out_trans_im,
    out_trans_re => out_trans_re
  );
end structural;
