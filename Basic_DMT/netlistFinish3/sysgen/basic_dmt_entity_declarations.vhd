-------------------------------------------------------------------
-- System Generator version 2014.4 VHDL source file.
--
-- Copyright(C) 2013 by Xilinx, Inc.  All rights reserved.  This
-- text/file contains proprietary, confidential information of Xilinx,
-- Inc., is distributed under license from Xilinx, Inc., and may be used,
-- copied and/or disclosed only pursuant to the terms of a valid license
-- agreement with Xilinx, Inc.  Xilinx hereby grants you a license to use
-- this text/file solely for design, simulation, implementation and
-- creation of design files limited to Xilinx devices or technologies.
-- Use with non-Xilinx devices or technologies is expressly prohibited
-- and immediately terminates your license unless covered by a separate
-- agreement.
--
-- Xilinx is providing this design, code, or information "as is" solely
-- for use in developing programs and solutions for Xilinx devices.  By
-- providing this design, code, or information as one possible
-- implementation of this feature, application or standard, Xilinx is
-- making no representation that this implementation is free from any
-- claims of infringement.  You are responsible for obtaining any rights
-- you may require for your implementation.  Xilinx expressly disclaims
-- any warranty whatsoever with respect to the adequacy of the
-- implementation, including but not limited to warranties of
-- merchantability or fitness for a particular purpose.
--
-- Xilinx products are not intended for use in life support appliances,
-- devices, or systems.  Use in such applications is expressly prohibited.
--
-- Any modifications that are made to the source code are done at the user's
-- sole risk and will be unsupported.
--
-- This copyright and support notice must be retained as part of this
-- text at all times.  (c) Copyright 1995-2013 Xilinx, Inc.  All rights
-- reserved.
-------------------------------------------------------------------

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


--------------------------------------------------------------------------
--
--  Filename      : xlp2s.vhd
--
--  Description   : Synthesizable vhdl for a parallel to serial
--                  conversion block.
--
--  Mod. History  : Modified VHDL to work with new clock enable scheme.
--                  Made valid bit a pasthru.  Added a register to generate
--                  the select line for the mux that switches between the
--                  input data and shift register outputs.
--                : Added rst/en support
--
-------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


-- synthesis translate_off
library unisim;
use unisim.vcomponents.all;
-- synthesis translate_on

entity basic_dmt_xlp2s is
    generic (dout_width  : integer := 8;          -- output width
             dout_arith  : integer := xlSigned;   -- output arith type
             dout_bin_pt : integer := 0;          -- output binary point location
             din_width   : integer := 1;          -- input width
             din_arith   : integer := xlUnsigned; -- input arith type
             din_bin_pt  : integer := 0;          -- input binary point location
             rst_width   : integer := 1;          -- width of input rst
             rst_bin_pt  : integer := 0;          -- binary point of input rst
             rst_arith   : integer := xlUnsigned; -- type of arith of input rst
             en_width    : integer := 1;          -- width of input en
             en_bin_pt   : integer := 0;          -- binary point of input en
             en_arith    : integer := xlUnsigned; -- type of arith of input en
             lsb_first   : integer := 0;          -- lsb or msb
             latency     : integer := 0;          -- latency from mask
             num_outputs : integer := 0);         -- num of outputs per input

    port (din        : in std_logic_vector (din_width-1 downto 0);
          src_ce     : in std_logic;     -- slower input clock
          src_clr    : in std_logic;
          src_clk    : in std_logic;
          dest_ce    : in std_logic;     -- faster output clock
          dest_clr   : in std_logic;
          dest_clk   : in std_logic;
          rst        : in std_logic_vector(rst_width-1 downto 0);
          en         : in std_logic_vector(en_width-1 downto 0);
          dout       : out std_logic_vector (dout_width-1 downto 0));

end basic_dmt_xlp2s;

architecture synth_behavioral of basic_dmt_xlp2s is

    component FDSE
        port(q  : out STD_ULOGIC;
             d  : in  STD_ULOGIC;
             c  : in  STD_ULOGIC;
             ce : in  STD_ULOGIC;
             s  : in  STD_ULOGIC);
    end component; -- end FDSE

    attribute syn_black_box of FDSE : component is true;
    attribute fpga_dont_touch of FDSE : component is "true";

    component synth_reg
        generic (width   : integer;
                 latency : integer);
        port (i   : in std_logic_vector(width-1 downto 0);
              ce  : in std_logic;
              clr : in std_logic;
              clk : in std_logic;
              o   : out std_logic_vector(width-1 downto 0));
    end component;

    component synth_reg_w_init
        generic (width      : integer;
                 init_index : integer;
                 latency    : integer);
        port (i   : in std_logic_vector(width-1 downto 0);
              ce  : in std_logic;
              clr : in std_logic;
              clk : in std_logic;
              o   : out std_logic_vector(width-1 downto 0));
    end component; -- end synth_reg_w_init

    type temp_array is array (0 to num_outputs-1) of std_logic_vector(dout_width-1 downto 0);

    signal i : temp_array; -- put input into capture register
    signal o : temp_array; -- outputfrom capture
    signal dout_temp        : std_logic_vector(dout_width -1 downto 0);
    signal src_ce_hold      : std_logic;
    signal internal_src_ce  : std_logic;
    signal internal_dest_ce : std_logic;
    signal internal_clr     : std_logic;

begin

    internal_src_ce   <= src_ce_hold and (en(0));
    internal_dest_ce  <= dest_ce and (en(0));
    internal_clr      <= ((dest_clr or src_clr ) and dest_ce) or rst(0);

    -- Register and hold the source enable signal until the next consecutive
    -- destination enable.  This signal is used as the mux select line for
    -- the mux in front of the shift register and the data output mux.

    src_ce_reg : FDSE
    port map (q  => src_ce_hold,
              d  => src_ce,
              c  => src_clk,
              ce => dest_ce,
              s  => src_clr);

    -- input is put into the capture register

    lsb_is_first: if(lsb_first = 1) generate

       fd_array: for index in num_outputs - 1 downto 0 generate
          capture : synth_reg_w_init
             generic map (width      => dout_width,
                          init_index => 0,
                          latency    => 1)
             port map (i   => i(index),
                       ce  => internal_dest_ce,
                       clr => internal_clr,
                       clk => dest_clk,
                       o   => o(index));
       end generate; -- end fd_array

       -- put new input into the capture register or put the same data back
       -- into the capture register
       -- the when statements are inferred into muxes by xst

       signal_select : for idx in num_outputs -1 downto 0 generate
          signal_0: if(idx < num_outputs-1)generate
             i(idx) <=  din((idx+1)*dout_width+dout_width-1 downto (idx+1)*dout_width)
                        when internal_src_ce = '1' else o(idx+1);
          end generate;  -- end signal_0
          signal_1: if(idx = num_outputs-1)generate
             i(idx) <=  din(idx*dout_width+dout_width-1 downto idx*dout_width)
                        when internal_src_ce = '1' else o(idx);
          end generate;  -- end signal_1
      end generate;  -- end signal_select

      -- Output the least sig bits when the delayed src_ce_hold is 1 else output
      -- bits from the capture register.  This line will infer a mux on the
      -- output data.

      dout_temp <= o(0) when internal_src_ce = '0' else din(dout_width-1 downto 0);

    end generate; -- end lsb_is_first

    msb_is_first: if(lsb_first = 0) generate

       fd_array: for index in num_outputs - 1 downto 0 generate
          capture : synth_reg_w_init
             generic map (width      => dout_width,
                          init_index => 0,
                          latency    => 1)
             port map (i   => i(index),
                       ce  => internal_dest_ce,
                       clr => internal_clr,
                       clk => dest_clk,
                       o   => o(index));
       end generate; -- end fd_array

       signal_select : for idx in num_outputs -1 downto 0 generate
          signal_0: if(idx < num_outputs-1)generate
             i(idx) <=  din(din_width-1-(idx+1)*dout_width downto din_width-1 - (idx+1)*dout_width-dout_width+1)
                        when internal_src_ce = '1' else o(idx+1);
          end generate; -- end signal_0
          signal_1: if(idx = num_outputs-1)generate
             i(idx) <=  din(din_width-1-idx*dout_width downto din_width-1-idx*dout_width-dout_width+1)
                        when internal_src_ce = '1' else o(idx);
          end generate; -- end signal_1
       end generate; -- end signal_select

       -- when src_ce is 1 output the most significant bits block has 0 latency

       dout_temp <= o(0) when internal_src_ce = '0'
                         else din(din_width-1 downto din_width-dout_width);

    end generate; -- end msb_is_first

    -- add registers for output data to compensate for
    -- the requested latency

    latency_gt_0 : if (latency > 0) generate
      data_reg : synth_reg
          generic map (width   => dout_width,
                       latency => latency)
          port map (i   => dout_temp,
                    ce  => internal_dest_ce,
                    clr => internal_clr,
                    clk => dest_clk,
                    o   => dout);
    end generate; -- end latency_gt_0

    latency0 : if (latency = 0 ) generate
       dout       <= dout_temp;
    end generate; -- end latency0

end architecture synth_behavioral;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_reinterpret_83a14f5b85 is
  port (
    input_port : in std_logic_vector((26 - 1) downto 0);
    output_port : out std_logic_vector((26 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_reinterpret_83a14f5b85;
architecture behavior of sysgen_reinterpret_83a14f5b85
is
  signal input_port_1_40: signed((26 - 1) downto 0);
begin
  input_port_1_40 <= std_logic_vector_to_signed(input_port);
  output_port <= signed_to_std_logic_vector(input_port_1_40);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_24f5f1f6d4 is
  port (
    op : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_24f5f1f6d4;
architecture behavior of sysgen_constant_24f5f1f6d4
is
begin
  op <= "1";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_cc555e006e is
  port (
    op : out std_logic_vector((21 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_cc555e006e;
architecture behavior of sysgen_constant_cc555e006e
is
begin
  op <= "000000010000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


entity basic_dmt_xldelay is
   generic(width        : integer := -1;
           latency      : integer := -1;
           reg_retiming : integer :=  0;
           reset        : integer :=  0);
   port(d       : in std_logic_vector (width-1 downto 0);
        ce      : in std_logic;
        clk     : in std_logic;
        en      : in std_logic;
        rst     : in std_logic;
        q       : out std_logic_vector (width-1 downto 0));

end basic_dmt_xldelay;

architecture behavior of basic_dmt_xldelay is
   component synth_reg
      generic (width       : integer;
               latency     : integer);
      port (i       : in std_logic_vector(width-1 downto 0);
            ce      : in std_logic;
            clr     : in std_logic;
            clk     : in std_logic;
            o       : out std_logic_vector(width-1 downto 0));
   end component; -- end component synth_reg

   component synth_reg_reg
      generic (width       : integer;
               latency     : integer);
      port (i       : in std_logic_vector(width-1 downto 0);
            ce      : in std_logic;
            clr     : in std_logic;
            clk     : in std_logic;
            o       : out std_logic_vector(width-1 downto 0));
   end component;

   signal internal_ce  : std_logic;

begin
   internal_ce  <= ce and en;

   srl_delay: if ((reg_retiming = 0) and (reset = 0)) or (latency < 1) generate
     synth_reg_srl_inst : synth_reg
       generic map (
         width   => width,
         latency => latency)
       port map (
         i   => d,
         ce  => internal_ce,
         clr => '0',
         clk => clk,
         o   => q);
   end generate srl_delay;

   reg_delay: if ((reg_retiming = 1) or (reset = 1)) and (latency >= 1) generate
     synth_reg_reg_inst : synth_reg_reg
       generic map (
         width   => width,
         latency => latency)
       port map (
         i   => d,
         ce  => internal_ce,
         clr => rst,
         clk => clk,
         o   => q);
   end generate reg_delay;
end architecture behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_5010573108 is
  port (
    i : in std_logic_vector((26 - 1) downto 0);
    q : in std_logic_vector((26 - 1) downto 0);
    y1 : out std_logic_vector((4 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_5010573108;
architecture behavior of sysgen_mcode_block_5010573108
is
  signal i_1_28: signed((26 - 1) downto 0);
  signal q_1_30: signed((26 - 1) downto 0);
  signal rel_8_13: boolean;
  signal b1_join_8_9: unsigned((1 - 1) downto 0);
  signal rel_15_13: boolean;
  signal b1_join_15_9: unsigned((1 - 1) downto 0);
  signal rel_6_6: boolean;
  signal b0_join_6_2: unsigned((1 - 1) downto 0);
  signal b1_join_6_2: unsigned((1 - 1) downto 0);
  signal rel_23_13: boolean;
  signal b3_join_23_9: unsigned((1 - 1) downto 0);
  signal rel_30_13: boolean;
  signal b3_join_30_9: unsigned((1 - 1) downto 0);
  signal rel_21_9: boolean;
  signal b3_join_21_5: unsigned((1 - 1) downto 0);
  signal b2_join_21_5: unsigned((1 - 1) downto 0);
  signal y1_38_5_concat: unsigned((4 - 1) downto 0);
begin
  i_1_28 <= std_logic_vector_to_signed(i);
  q_1_30 <= std_logic_vector_to_signed(q);
  rel_8_13 <= i_1_28 > std_logic_vector_to_signed("00000000000100000000000000");
  proc_if_8_9: process (rel_8_13)
  is
  begin
    if rel_8_13 then
      b1_join_8_9 <= std_logic_vector_to_unsigned("0");
    else 
      b1_join_8_9 <= std_logic_vector_to_unsigned("1");
    end if;
  end process proc_if_8_9;
  rel_15_13 <= i_1_28 > std_logic_vector_to_signed("11111111111100000000000000");
  proc_if_15_9: process (rel_15_13)
  is
  begin
    if rel_15_13 then
      b1_join_15_9 <= std_logic_vector_to_unsigned("1");
    else 
      b1_join_15_9 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_15_9;
  rel_6_6 <= i_1_28 > std_logic_vector_to_signed("00000000000000000000000000");
  proc_if_6_2: process (b1_join_15_9, b1_join_8_9, rel_6_6)
  is
  begin
    if rel_6_6 then
      b0_join_6_2 <= std_logic_vector_to_unsigned("1");
      b1_join_6_2 <= b1_join_8_9;
    else 
      b0_join_6_2 <= std_logic_vector_to_unsigned("0");
      b1_join_6_2 <= b1_join_15_9;
    end if;
  end process proc_if_6_2;
  rel_23_13 <= q_1_30 > std_logic_vector_to_signed("00000000000100000000000000");
  proc_if_23_9: process (rel_23_13)
  is
  begin
    if rel_23_13 then
      b3_join_23_9 <= std_logic_vector_to_unsigned("0");
    else 
      b3_join_23_9 <= std_logic_vector_to_unsigned("1");
    end if;
  end process proc_if_23_9;
  rel_30_13 <= q_1_30 > std_logic_vector_to_signed("11111111111100000000000000");
  proc_if_30_9: process (rel_30_13)
  is
  begin
    if rel_30_13 then
      b3_join_30_9 <= std_logic_vector_to_unsigned("1");
    else 
      b3_join_30_9 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_30_9;
  rel_21_9 <= q_1_30 > std_logic_vector_to_signed("00000000000000000000000000");
  proc_if_21_5: process (b3_join_23_9, b3_join_30_9, rel_21_9)
  is
  begin
    if rel_21_9 then
      b3_join_21_5 <= b3_join_23_9;
      b2_join_21_5 <= std_logic_vector_to_unsigned("0");
    else 
      b3_join_21_5 <= b3_join_30_9;
      b2_join_21_5 <= std_logic_vector_to_unsigned("1");
    end if;
  end process proc_if_21_5;
  y1_38_5_concat <= std_logic_vector_to_unsigned(unsigned_to_std_logic_vector(b0_join_6_2) & unsigned_to_std_logic_vector(b1_join_6_2) & unsigned_to_std_logic_vector(b2_join_21_5) & unsigned_to_std_logic_vector(b3_join_21_5));
  y1 <= unsigned_to_std_logic_vector(y1_38_5_concat);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

--$Header: /devl/xcs/repo/env/Jobs/sysgen/src/xbs/hdl_pkg/xlpassthrough.vhd,v 1.1 2005/07/11 00:50:55 alexc Exp $
---------------------------------------------------------------------
--
--  Filename      : xlpassthrough.vhd
--
--  Created       : 07/09/05
--
--  Description   : VHDL description of a passthrough block
--
---------------------------------------------------------------------


---------------------------------------------------------------------
--
--  Entity        : xlpassthrough
--
--  Architecture  : passthrough_arch
--
--  Description   : Top level VHDL description of passthrough block. 
--
---------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;
use work.conv_pkg.all;

entity xlpassthrough is
    generic (
        din_width    : integer := 16;            -- Width of input
        dout_width   : integer := 16             -- Width of output
        );
    port (
        din : in std_logic_vector (din_width-1 downto 0);
        dout : out std_logic_vector (dout_width-1 downto 0));
end xlpassthrough;

architecture passthrough_arch of xlpassthrough is
begin
  dout <= din;
end passthrough_arch;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

---------------------------------------------------------------------
--
--  Filename      : xldsamp.vhd
--
--  Description   : VHDL description of a block that is inserted into the
--                  data path to down sample the data betwen two blocks
--                  where the period is different between two blocks.
--
--  Mod. History  : Changed clock timing on the down sampler.  The
--                  destination enable is delayed by one system clock
--                  cycle and held until the next consecutive source
--                  enable pulse.  This change allows downsampler data
--                  transitions to occur on the rising clock edge when
--                  the destination ce is asserted.
--                : Added optional latency is the downsampler.  Note, if
--                  the latency is greater than 0, no shutter is used.
--                : Removed valid bit logic from wrapper
--
--
---------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


-- synthesis translate_off
library unisim;
use unisim.vcomponents.all;
-- synthesis translate_on

entity basic_dmt_xldsamp is
  generic (
    d_width: integer := 12;
    d_bin_pt: integer := 0;
    d_arith: integer := xlUnsigned;
    q_width: integer := 12;
    q_bin_pt: integer := 0;
    q_arith: integer := xlUnsigned;
    en_width: integer := 1;
    en_bin_pt: integer := 0;
    en_arith: integer := xlUnsigned;
    rst_width: integer := 1;
    rst_bin_pt: integer := 0;
    rst_arith: integer := xlUnsigned;
    ds_ratio: integer := 2;
    phase: integer := 0;
    latency: integer := 1
  );
  port (
    d: in std_logic_vector(d_width - 1 downto 0);
    src_clk: in std_logic;
    src_ce: in std_logic;
    src_clr: in std_logic;
    dest_clk: in std_logic;
    dest_ce: in std_logic;
    dest_clr: in std_logic;
    en: in std_logic_vector(en_width - 1 downto 0);
    rst: in std_logic_vector(rst_width - 1 downto 0);
    q: out std_logic_vector(q_width - 1 downto 0)
  );
end basic_dmt_xldsamp;

architecture struct of basic_dmt_xldsamp is
  component synth_reg
    generic (
      width: integer := 16;
      latency: integer := 5
    );
    port (
      i: in std_logic_vector(width - 1 downto 0);
      ce: in std_logic;
      clr: in std_logic;
      clk: in std_logic;
      o: out std_logic_vector(width - 1 downto 0)
    );
  end component; -- end synth_reg

  component synth_reg_reg
     generic (width       : integer;
              latency     : integer);
     port (i       : in std_logic_vector(width-1 downto 0);
           ce      : in std_logic;
           clr     : in std_logic;
           clk     : in std_logic;
           o       : out std_logic_vector(width-1 downto 0));
  end component;

  component fdse
    port (
      q: out   std_ulogic;
      d: in    std_ulogic;
      c: in    std_ulogic;
      s: in    std_ulogic;
      ce: in    std_ulogic
    );
  end component; -- end fdse
  attribute syn_black_box of fdse: component is true;
  attribute fpga_dont_touch of fdse: component is "true";

  signal adjusted_dest_ce: std_logic;
  signal adjusted_dest_ce_w_en: std_logic;
  signal dest_ce_w_en: std_logic;
  signal smpld_d: std_logic_vector(d_width-1 downto 0);
  signal sclr:std_logic;
begin
  -- An 'adjusted' destination clock enable signal must be generated for
  -- the zero latency and double registered down-sampler implementations.
  -- For both cases, it is necassary to adjust the timing of the clock
  -- enable so that it is asserted at the start of the sample period,
  -- instead of the end.  This is realized using an fdse prim. to register
  -- the destination clock enable.  The fdse itself is enabled with the
  -- source clock enable.  Enabling the fdse holds the adjusted CE high
  -- for the duration of the fast sample period and is needed to satisfy
  -- the multicycle constraint if the input data is running at a non-system
  -- rate.
  adjusted_ce_needed: if ((latency = 0) or (phase /= (ds_ratio - 1))) generate
    dest_ce_reg: fdse
      port map (
        q => adjusted_dest_ce,
        d => dest_ce,
        c => src_clk,
        s => sclr,
        ce => src_ce
      );
  end generate; -- adjusted_ce_needed

  -- A shutter (mux/reg pair) is used to implement a 0 latency downsampler.
  -- The shutter uses the adjusted destination clock enable to select between
  -- the current input and the sampled input.
  latency_eq_0: if (latency = 0) generate
    shutter_d_reg: synth_reg
      generic map (
        width => d_width,
        latency => 1
      )
      port map (
        i => d,
        ce => adjusted_dest_ce,
        clr => sclr,
        clk => src_clk,
        o => smpld_d
      );

    -- Mux selects current input value or register value.
    shutter_mux: process (adjusted_dest_ce, d, smpld_d)
    begin
	  if adjusted_dest_ce = '0' then
        q <= smpld_d;
      else
        q <= d;
      end if;
    end process; -- end select_mux
  end generate; -- end latency_eq_0

  -- A more efficient downsampler can be implemented if a latency > 0 is
  -- allowed.  There are two possible implementations, depending on the
  -- requested sampling phase.  A double register downsampler is needed
  -- for all cases except when the sample phase is the last input frame
  -- of the sample period.  In this case, only one register is needed.

  latency_gt_0: if (latency > 0) generate
    -- The first register in the double reg implementation is used to
    -- sample the correct frame (phase) of the input data.  Both the
    -- data and valid bit must be sampled.
    dbl_reg_test: if (phase /= (ds_ratio-1)) generate
        smpl_d_reg: synth_reg_reg
          generic map (
            width => d_width,
            latency => 1
          )
          port map (
            i => d,
            ce => adjusted_dest_ce_w_en,
            clr => sclr,
            clk => src_clk,
            o => smpld_d
          );
    end generate; -- end dbl_reg_test

    sngl_reg_test: if (phase = (ds_ratio -1)) generate
      smpld_d <= d;
    end generate; -- sngl_reg_test

    -- The latency pipe captures the sampled data and the END of the sample
    -- period.  Note that if the requested sample phase is the last input
    -- frame in the period, the first register (smpl_reg) is not needed.
    latency_pipe: synth_reg_reg
      generic map (
        width => d_width,
        latency => latency
      )
      port map (
        i => smpld_d,
        ce => dest_ce_w_en,
        clr => sclr,
        clk => dest_clk,
        o => q
      );
  end generate; -- end latency_gt_0

  -- Signal assignments
  dest_ce_w_en <= dest_ce and en(0);
  adjusted_dest_ce_w_en <= adjusted_dest_ce and en(0);
  sclr <= (src_clr or rst(0)) and dest_ce;
end architecture struct;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_08b11b7c87 is
  port (
    pushen : in std_logic_vector((1 - 1) downto 0);
    statei : in std_logic_vector((2 - 1) downto 0);
    loopcounti : in std_logic_vector((8 - 1) downto 0);
    popeni : in std_logic_vector((1 - 1) downto 0);
    push : out std_logic_vector((1 - 1) downto 0);
    pop : out std_logic_vector((1 - 1) downto 0);
    stateo : out std_logic_vector((2 - 1) downto 0);
    loopcounto : out std_logic_vector((8 - 1) downto 0);
    popeno : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_08b11b7c87;
architecture behavior of sysgen_mcode_block_08b11b7c87
is
  signal pushen_1_68: unsigned((1 - 1) downto 0);
  signal statei_1_76: unsigned((2 - 1) downto 0);
  signal loopcounti_1_84: unsigned((8 - 1) downto 0);
  signal popeni_1_96: boolean;
  signal push_join_6_1: boolean;
  signal pop_join_6_1: boolean;
  signal rel_24_4: boolean;
  signal conpush_join_24_1: unsigned((1 - 1) downto 0);
  signal popeni_join_24_1: boolean;
  signal rel_31_4: boolean;
  signal rel_31_23: boolean;
  signal bool_31_4: boolean;
  signal conpop_join_31_1: unsigned((1 - 1) downto 0);
  signal cast_37_14: unsigned((9 - 1) downto 0);
  signal loopcounti_37_1_addsub: unsigned((9 - 1) downto 0);
  signal rel_38_4: boolean;
  signal loopcounti_join_38_1: unsigned((9 - 1) downto 0);
  signal rel_43_8: boolean;
  signal statei_join_43_5: unsigned((1 - 1) downto 0);
  signal rel_50_8: boolean;
  signal statei_join_50_5: unsigned((2 - 1) downto 0);
  signal rel_42_4: boolean;
  signal statei_join_42_1: unsigned((2 - 1) downto 0);
  signal cast_loopcounto_57_1_convert: unsigned((8 - 1) downto 0);
begin
  pushen_1_68 <= std_logic_vector_to_unsigned(pushen);
  statei_1_76 <= std_logic_vector_to_unsigned(statei);
  loopcounti_1_84 <= std_logic_vector_to_unsigned(loopcounti);
  popeni_1_96 <= ((popeni) = "1");
  proc_switch_6_1: process (statei_1_76)
  is
  begin
    case statei_1_76 is 
      when "00" =>
        push_join_6_1 <= true;
        pop_join_6_1 <= false;
      when "01" =>
        push_join_6_1 <= true;
        pop_join_6_1 <= true;
      when "10" =>
        push_join_6_1 <= false;
        pop_join_6_1 <= true;
      when "11" =>
        push_join_6_1 <= false;
        pop_join_6_1 <= false;
      when others =>
        push_join_6_1 <= false;
        pop_join_6_1 <= false;
    end case;
  end process proc_switch_6_1;
  rel_24_4 <= pushen_1_68 = std_logic_vector_to_unsigned("1");
  proc_if_24_1: process (popeni_1_96, rel_24_4)
  is
  begin
    if rel_24_4 then
      conpush_join_24_1 <= std_logic_vector_to_unsigned("1");
      popeni_join_24_1 <= true;
    else 
      conpush_join_24_1 <= std_logic_vector_to_unsigned("0");
      popeni_join_24_1 <= popeni_1_96;
    end if;
  end process proc_if_24_1;
  rel_31_4 <= loopcounti_1_84 = std_logic_vector_to_unsigned("00000000");
  rel_31_23 <= popeni_join_24_1 = true;
  bool_31_4 <= rel_31_4 and rel_31_23;
  proc_if_31_1: process (bool_31_4)
  is
  begin
    if bool_31_4 then
      conpop_join_31_1 <= std_logic_vector_to_unsigned("1");
    else 
      conpop_join_31_1 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_31_1;
  cast_37_14 <= u2u_cast(loopcounti_1_84, 0, 9, 0);
  loopcounti_37_1_addsub <= cast_37_14 + std_logic_vector_to_unsigned("000000001");
  rel_38_4 <= loopcounti_37_1_addsub >= std_logic_vector_to_unsigned("000001110");
  proc_if_38_1: process (loopcounti_37_1_addsub, rel_38_4)
  is
  begin
    if rel_38_4 then
      loopcounti_join_38_1 <= std_logic_vector_to_unsigned("000000000");
    else 
      loopcounti_join_38_1 <= loopcounti_37_1_addsub;
    end if;
  end process proc_if_38_1;
  rel_43_8 <= conpop_join_31_1 = std_logic_vector_to_unsigned("1");
  proc_if_43_5: process (rel_43_8)
  is
  begin
    if rel_43_8 then
      statei_join_43_5 <= std_logic_vector_to_unsigned("1");
    else 
      statei_join_43_5 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_43_5;
  rel_50_8 <= conpop_join_31_1 = std_logic_vector_to_unsigned("1");
  proc_if_50_5: process (rel_50_8)
  is
  begin
    if rel_50_8 then
      statei_join_50_5 <= std_logic_vector_to_unsigned("10");
    else 
      statei_join_50_5 <= std_logic_vector_to_unsigned("11");
    end if;
  end process proc_if_50_5;
  rel_42_4 <= conpush_join_24_1 = std_logic_vector_to_unsigned("1");
  proc_if_42_1: process (rel_42_4, statei_join_43_5, statei_join_50_5)
  is
  begin
    if rel_42_4 then
      statei_join_42_1 <= u2u_cast(statei_join_43_5, 0, 2, 0);
    else 
      statei_join_42_1 <= statei_join_50_5;
    end if;
  end process proc_if_42_1;
  cast_loopcounto_57_1_convert <= u2u_cast(loopcounti_join_38_1, 0, 8, 0);
  push <= boolean_to_vector(push_join_6_1);
  pop <= boolean_to_vector(pop_join_6_1);
  stateo <= unsigned_to_std_logic_vector(statei_join_42_1);
  loopcounto <= unsigned_to_std_logic_vector(cast_loopcounto_57_1_convert);
  popeno <= boolean_to_vector(popeni_join_24_1);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

----------------------------------------------------------------------------
--
--  Filename      : xlusamp.vhd
--
--  Description   : VHDL description of an up sampler.  The input signal
--                  has a larger period than the output signal's period
--                  and the blocks's period is set on the Simulink mask
--                  GUI.
--
--  Assumptions   : Input size, bin_pt, etc. are the same as the output
--
--  Mod. History  : Removed the shutter from the upsampler.  A mux is used
--                  to zero pad the data samples.  The mux select line is
--                  generated by registering the source enable signal
--                  when the destination ce is asserted.
--                : Removed valid bits from wrapper.
--
----------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


-- synthesis translate_off
library unisim;
use unisim.vcomponents.all;
-- synthesis translate_on

entity basic_dmt_xlusamp is

    generic (
             d_width      : integer := 5;          -- Width of d input
             d_bin_pt     : integer := 2;          -- Binary point of input d
             d_arith      : integer := xlUnsigned; -- Type of arith of d input
             q_width      : integer := 5;          -- Width of q output
             q_bin_pt     : integer := 2;          -- Binary point of output q
             q_arith      : integer := xlUnsigned; -- Type of arith of output
             en_width     : integer := 1;
             en_bin_pt    : integer := 0;
             en_arith     : integer := xlUnsigned;
             sampling_ratio     : integer := 2;
             latency      : integer := 1;
             copy_samples : integer := 0);         -- if 0, output q = 0
                                                   -- when ce = 0, else sample
                                                   -- is held until next clk

    port (
          d        : in std_logic_vector (d_width-1 downto 0);
          src_clk  : in std_logic;
          src_ce   : in std_logic;
          src_clr  : in std_logic;
          dest_clk : in std_logic;
          dest_ce  : in std_logic;
          dest_clr : in std_logic;
          en       : in std_logic_vector(en_width-1 downto 0);
          q        : out std_logic_vector (q_width-1 downto 0)
         );
end basic_dmt_xlusamp;

architecture struct of basic_dmt_xlusamp is
    component synth_reg
      generic (
        width: integer := 16;
        latency: integer := 5
      );
      port (
        i: in std_logic_vector(width - 1 downto 0);
        ce: in std_logic;
        clr: in std_logic;
        clk: in std_logic;
        o: out std_logic_vector(width - 1 downto 0)
      );
    end component; -- end synth_reg

    component FDSE
        port (q  : out   std_ulogic;
              d  : in    std_ulogic;
              c  : in    std_ulogic;
              s  : in    std_ulogic;
              ce : in    std_ulogic);
    end component; -- end FDSE

    attribute syn_black_box of FDSE : component is true;
    attribute fpga_dont_touch of FDSE : component is "true";

    signal zero    : std_logic_vector (d_width-1 downto 0);
    signal mux_sel : std_logic;
    signal sampled_d  : std_logic_vector (d_width-1 downto 0);
    signal internal_ce : std_logic;

begin


   -- If zero padding is required, a mux is used to switch between data input
   -- and zeros.  The mux select is generated by registering the source enable
   -- signal.  This register is enabled by the destination enable signal. This
   -- has the effect of holding the select line high until the next consecutive
   -- destination enable pulse, and thereby satisfying the timing constraints.
   -- Signal assignments

   -- register the source enable signal with the register enabled
   -- by the destination enable
   sel_gen : FDSE
       port map (q  => mux_sel,
           d  => src_ce,
            c  => src_clk,
            s  => src_clr,
            ce => dest_ce);
  -- Generate the user enable
  internal_ce <= src_ce and en(0);

  copy_samples_false : if (copy_samples = 0) generate

      -- signal assignments
      zero <= (others => '0');

      -- purpose: latency is 0 and copy_samples is 0
      -- type   : combinational
      -- inputs : mux_sel, d, zero
      -- outputs: q
      gen_q_cp_smpls_0_and_lat_0: if (latency = 0) generate
        cp_smpls_0_and_lat_0: process (mux_sel, d, zero)
        begin  -- process cp_smpls_0_and_lat_0
          if (mux_sel = '1') then
            q <= d;
          else
            q <= zero;
          end if;
        end process cp_smpls_0_and_lat_0;
      end generate; -- end gen_q_cp_smpls_0_and_lat_0

      gen_q_cp_smpls_0_and_lat_gt_0: if (latency > 0) generate
        sampled_d_reg: synth_reg
          generic map (
            width => d_width,
            latency => latency
          )

          port map (
            i => d,
            ce => internal_ce,
            clr => src_clr,
            clk => src_clk,
            o => sampled_d
          );

        gen_q_check_mux_sel: process (mux_sel, sampled_d, zero)
        begin
          if (mux_sel = '1') then
            q <= sampled_d;
          else
            q <= zero;
          end if;
        end process gen_q_check_mux_sel;
      end generate; -- end gen_q_cp_smpls_0_and_lat_gt_0
   end generate; -- end copy_samples_false

   -- If zero padding is not required, we can short the upsampler data inputs
   -- to the upsampler data outputs when latency is 0.
   -- This option uses no hardware resources.

   copy_samples_true : if (copy_samples = 1) generate

     gen_q_cp_smpls_1_and_lat_0: if (latency = 0) generate
       q <= d;
     end generate; -- end gen_q_cp_smpls_1_and_lat_0

     gen_q_cp_smpls_1_and_lat_gt_0: if (latency > 0) generate
       q <= sampled_d;
       sampled_d_reg2: synth_reg
         generic map (
           width => d_width,
           latency => latency
         )

         port map (
           i => d,
           ce => internal_ce,
           clr => src_clr,
           clk => src_clk,
           o => sampled_d
         );
     end generate; -- end gen_q_cp_smpls_1_and_lat_gt_0
   end generate; -- end copy_samples_true
end architecture struct;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_2371105fd2 is
  port (
    inp_re : in std_logic_vector((21 - 1) downto 0);
    inp_im : in std_logic_vector((21 - 1) downto 0);
    frameen : in std_logic_vector((1 - 1) downto 0);
    i1_re : in std_logic_vector((21 - 1) downto 0);
    i2_re : in std_logic_vector((21 - 1) downto 0);
    i3_re : in std_logic_vector((21 - 1) downto 0);
    i4_re : in std_logic_vector((21 - 1) downto 0);
    i5_re : in std_logic_vector((21 - 1) downto 0);
    i6_re : in std_logic_vector((21 - 1) downto 0);
    i7_re : in std_logic_vector((21 - 1) downto 0);
    i8_re : in std_logic_vector((21 - 1) downto 0);
    i9_re : in std_logic_vector((21 - 1) downto 0);
    i10_re : in std_logic_vector((21 - 1) downto 0);
    i11_re : in std_logic_vector((21 - 1) downto 0);
    i12_re : in std_logic_vector((21 - 1) downto 0);
    i13_re : in std_logic_vector((21 - 1) downto 0);
    i14_re : in std_logic_vector((21 - 1) downto 0);
    i15_re : in std_logic_vector((21 - 1) downto 0);
    i16_re : in std_logic_vector((21 - 1) downto 0);
    i1_im : in std_logic_vector((21 - 1) downto 0);
    i2_im : in std_logic_vector((21 - 1) downto 0);
    i3_im : in std_logic_vector((21 - 1) downto 0);
    i4_im : in std_logic_vector((21 - 1) downto 0);
    i5_im : in std_logic_vector((21 - 1) downto 0);
    i6_im : in std_logic_vector((21 - 1) downto 0);
    i7_im : in std_logic_vector((21 - 1) downto 0);
    i8_im : in std_logic_vector((21 - 1) downto 0);
    i9_im : in std_logic_vector((21 - 1) downto 0);
    i10_im : in std_logic_vector((21 - 1) downto 0);
    i11_im : in std_logic_vector((21 - 1) downto 0);
    i12_im : in std_logic_vector((21 - 1) downto 0);
    i13_im : in std_logic_vector((21 - 1) downto 0);
    i14_im : in std_logic_vector((21 - 1) downto 0);
    i15_im : in std_logic_vector((21 - 1) downto 0);
    i16_im : in std_logic_vector((21 - 1) downto 0);
    statei : in std_logic_vector((8 - 1) downto 0);
    out_re : out std_logic_vector((21 - 1) downto 0);
    out_im : out std_logic_vector((21 - 1) downto 0);
    pop : out std_logic_vector((1 - 1) downto 0);
    o1_re : out std_logic_vector((21 - 1) downto 0);
    o2_re : out std_logic_vector((21 - 1) downto 0);
    o3_re : out std_logic_vector((21 - 1) downto 0);
    o4_re : out std_logic_vector((21 - 1) downto 0);
    o5_re : out std_logic_vector((21 - 1) downto 0);
    o6_re : out std_logic_vector((21 - 1) downto 0);
    o7_re : out std_logic_vector((21 - 1) downto 0);
    o8_re : out std_logic_vector((21 - 1) downto 0);
    o9_re : out std_logic_vector((21 - 1) downto 0);
    o10_re : out std_logic_vector((21 - 1) downto 0);
    o11_re : out std_logic_vector((21 - 1) downto 0);
    o12_re : out std_logic_vector((21 - 1) downto 0);
    o13_re : out std_logic_vector((21 - 1) downto 0);
    o14_re : out std_logic_vector((21 - 1) downto 0);
    o15_re : out std_logic_vector((21 - 1) downto 0);
    o16_re : out std_logic_vector((21 - 1) downto 0);
    o1_im : out std_logic_vector((21 - 1) downto 0);
    o2_im : out std_logic_vector((21 - 1) downto 0);
    o3_im : out std_logic_vector((21 - 1) downto 0);
    o4_im : out std_logic_vector((21 - 1) downto 0);
    o5_im : out std_logic_vector((21 - 1) downto 0);
    o6_im : out std_logic_vector((21 - 1) downto 0);
    o7_im : out std_logic_vector((21 - 1) downto 0);
    o8_im : out std_logic_vector((21 - 1) downto 0);
    o9_im : out std_logic_vector((21 - 1) downto 0);
    o10_im : out std_logic_vector((21 - 1) downto 0);
    o11_im : out std_logic_vector((21 - 1) downto 0);
    o12_im : out std_logic_vector((21 - 1) downto 0);
    o13_im : out std_logic_vector((21 - 1) downto 0);
    o14_im : out std_logic_vector((21 - 1) downto 0);
    o15_im : out std_logic_vector((21 - 1) downto 0);
    o16_im : out std_logic_vector((21 - 1) downto 0);
    stateo : out std_logic_vector((8 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_2371105fd2;
architecture behavior of sysgen_mcode_block_2371105fd2
is
  signal inp_re_5_56: signed((21 - 1) downto 0);
  signal inp_im_5_63: signed((21 - 1) downto 0);
  signal frameen_6_5: boolean;
  signal i1_re_6_14: signed((21 - 1) downto 0);
  signal i2_re_6_22: signed((21 - 1) downto 0);
  signal i3_re_6_30: signed((21 - 1) downto 0);
  signal i4_re_6_37: signed((21 - 1) downto 0);
  signal i5_re_6_45: signed((21 - 1) downto 0);
  signal i6_re_6_53: signed((21 - 1) downto 0);
  signal i7_re_6_61: signed((21 - 1) downto 0);
  signal i8_re_7_5: signed((21 - 1) downto 0);
  signal i9_re_7_13: signed((21 - 1) downto 0);
  signal i10_re_7_21: signed((21 - 1) downto 0);
  signal i11_re_7_29: signed((21 - 1) downto 0);
  signal i12_re_7_37: signed((21 - 1) downto 0);
  signal i13_re_7_45: signed((21 - 1) downto 0);
  signal i14_re_7_53: signed((21 - 1) downto 0);
  signal i15_re_7_61: signed((21 - 1) downto 0);
  signal i16_re_8_5: signed((21 - 1) downto 0);
  signal i1_im_8_13: signed((21 - 1) downto 0);
  signal i2_im_8_21: signed((21 - 1) downto 0);
  signal i3_im_8_29: signed((21 - 1) downto 0);
  signal i4_im_8_36: signed((21 - 1) downto 0);
  signal i5_im_8_44: signed((21 - 1) downto 0);
  signal i6_im_8_52: signed((21 - 1) downto 0);
  signal i7_im_8_60: signed((21 - 1) downto 0);
  signal i8_im_9_5: signed((21 - 1) downto 0);
  signal i9_im_9_13: signed((21 - 1) downto 0);
  signal i10_im_9_21: signed((21 - 1) downto 0);
  signal i11_im_9_29: signed((21 - 1) downto 0);
  signal i12_im_9_37: signed((21 - 1) downto 0);
  signal i13_im_9_45: signed((21 - 1) downto 0);
  signal i14_im_9_53: signed((21 - 1) downto 0);
  signal i15_im_9_61: signed((21 - 1) downto 0);
  signal i16_im_10_5: signed((21 - 1) downto 0);
  signal statei_10_14: unsigned((8 - 1) downto 0);
  signal statei_join_51_9: unsigned((1 - 1) downto 0);
  signal statei_join_49_1: unsigned((8 - 1) downto 0);
  signal o1_im_join_49_1: signed((21 - 1) downto 0);
  signal o1_re_join_49_1: signed((21 - 1) downto 0);
  signal o2_re_join_49_1: signed((21 - 1) downto 0);
  signal o2_im_join_49_1: signed((21 - 1) downto 0);
  signal o3_im_join_49_1: signed((21 - 1) downto 0);
  signal o3_re_join_49_1: signed((21 - 1) downto 0);
  signal o4_im_join_49_1: signed((21 - 1) downto 0);
  signal o4_re_join_49_1: signed((21 - 1) downto 0);
  signal o5_im_join_49_1: signed((21 - 1) downto 0);
  signal o5_re_join_49_1: signed((21 - 1) downto 0);
  signal o6_re_join_49_1: signed((21 - 1) downto 0);
  signal o6_im_join_49_1: signed((21 - 1) downto 0);
  signal o7_im_join_49_1: signed((21 - 1) downto 0);
  signal o7_re_join_49_1: signed((21 - 1) downto 0);
  signal o8_re_join_49_1: signed((21 - 1) downto 0);
  signal o8_im_join_49_1: signed((21 - 1) downto 0);
  signal o9_im_join_49_1: signed((21 - 1) downto 0);
  signal o9_re_join_49_1: signed((21 - 1) downto 0);
  signal o10_re_join_49_1: signed((21 - 1) downto 0);
  signal o10_im_join_49_1: signed((21 - 1) downto 0);
  signal o11_re_join_49_1: signed((21 - 1) downto 0);
  signal o11_im_join_49_1: signed((21 - 1) downto 0);
  signal o12_im_join_49_1: signed((21 - 1) downto 0);
  signal o12_re_join_49_1: signed((21 - 1) downto 0);
  signal out_re_join_49_1: signed((21 - 1) downto 0);
  signal pop_join_49_1: unsigned((1 - 1) downto 0);
  signal o13_re_join_49_1: signed((21 - 1) downto 0);
  signal o13_im_join_49_1: signed((21 - 1) downto 0);
  signal out_im_join_49_1: signed((21 - 1) downto 0);
  signal o14_re_join_49_1: signed((21 - 1) downto 0);
  signal o14_im_join_49_1: signed((21 - 1) downto 0);
  signal o15_im_join_49_1: signed((21 - 1) downto 0);
  signal o15_re_join_49_1: signed((21 - 1) downto 0);
  signal o16_im_join_49_1: signed((21 - 1) downto 0);
  signal o16_re_join_49_1: signed((21 - 1) downto 0);
begin
  inp_re_5_56 <= std_logic_vector_to_signed(inp_re);
  inp_im_5_63 <= std_logic_vector_to_signed(inp_im);
  frameen_6_5 <= ((frameen) = "1");
  i1_re_6_14 <= std_logic_vector_to_signed(i1_re);
  i2_re_6_22 <= std_logic_vector_to_signed(i2_re);
  i3_re_6_30 <= std_logic_vector_to_signed(i3_re);
  i4_re_6_37 <= std_logic_vector_to_signed(i4_re);
  i5_re_6_45 <= std_logic_vector_to_signed(i5_re);
  i6_re_6_53 <= std_logic_vector_to_signed(i6_re);
  i7_re_6_61 <= std_logic_vector_to_signed(i7_re);
  i8_re_7_5 <= std_logic_vector_to_signed(i8_re);
  i9_re_7_13 <= std_logic_vector_to_signed(i9_re);
  i10_re_7_21 <= std_logic_vector_to_signed(i10_re);
  i11_re_7_29 <= std_logic_vector_to_signed(i11_re);
  i12_re_7_37 <= std_logic_vector_to_signed(i12_re);
  i13_re_7_45 <= std_logic_vector_to_signed(i13_re);
  i14_re_7_53 <= std_logic_vector_to_signed(i14_re);
  i15_re_7_61 <= std_logic_vector_to_signed(i15_re);
  i16_re_8_5 <= std_logic_vector_to_signed(i16_re);
  i1_im_8_13 <= std_logic_vector_to_signed(i1_im);
  i2_im_8_21 <= std_logic_vector_to_signed(i2_im);
  i3_im_8_29 <= std_logic_vector_to_signed(i3_im);
  i4_im_8_36 <= std_logic_vector_to_signed(i4_im);
  i5_im_8_44 <= std_logic_vector_to_signed(i5_im);
  i6_im_8_52 <= std_logic_vector_to_signed(i6_im);
  i7_im_8_60 <= std_logic_vector_to_signed(i7_im);
  i8_im_9_5 <= std_logic_vector_to_signed(i8_im);
  i9_im_9_13 <= std_logic_vector_to_signed(i9_im);
  i10_im_9_21 <= std_logic_vector_to_signed(i10_im);
  i11_im_9_29 <= std_logic_vector_to_signed(i11_im);
  i12_im_9_37 <= std_logic_vector_to_signed(i12_im);
  i13_im_9_45 <= std_logic_vector_to_signed(i13_im);
  i14_im_9_53 <= std_logic_vector_to_signed(i14_im);
  i15_im_9_61 <= std_logic_vector_to_signed(i15_im);
  i16_im_10_5 <= std_logic_vector_to_signed(i16_im);
  statei_10_14 <= std_logic_vector_to_unsigned(statei);
  proc_if_51_9: process (frameen_6_5)
  is
  begin
    if frameen_6_5 then
      statei_join_51_9 <= std_logic_vector_to_unsigned("1");
    else 
      statei_join_51_9 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_51_9;
  proc_switch_49_1: process (i10_im_9_21, i10_re_7_21, i11_im_9_29, i11_re_7_29, i12_im_9_37, i12_re_7_37, i13_im_9_45, i13_re_7_45, i14_im_9_53, i14_re_7_53, i15_im_9_61, i15_re_7_61, i16_im_10_5, i16_re_8_5, i1_im_8_13, i1_re_6_14, i2_im_8_21, i2_re_6_22, i3_im_8_29, i3_re_6_30, i4_im_8_36, i4_re_6_37, i5_im_8_44, i5_re_6_45, i6_im_8_52, i6_re_6_53, i7_im_8_60, i7_re_6_61, i8_im_9_5, i8_re_7_5, i9_im_9_13, i9_re_7_13, inp_im_5_63, inp_re_5_56, statei_10_14, statei_join_51_9)
  is
  begin
    case statei_10_14 is 
      when "00000000" =>
        statei_join_49_1 <= u2u_cast(statei_join_51_9, 0, 8, 0);
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00000001" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00000010");
        o1_im_join_49_1 <= inp_im_5_63;
        o1_re_join_49_1 <= inp_re_5_56;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00000010" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00000011");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= inp_re_5_56;
        o2_im_join_49_1 <= inp_im_5_63;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00000011" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00000100");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= inp_im_5_63;
        o3_re_join_49_1 <= inp_re_5_56;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00000100" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00000101");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= inp_im_5_63;
        o4_re_join_49_1 <= inp_re_5_56;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00000101" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00000110");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= inp_im_5_63;
        o5_re_join_49_1 <= inp_re_5_56;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00000110" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00000111");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= inp_re_5_56;
        o6_im_join_49_1 <= inp_im_5_63;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00000111" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00001000");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= inp_im_5_63;
        o7_re_join_49_1 <= inp_re_5_56;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00001000" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00001001");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= inp_re_5_56;
        o8_im_join_49_1 <= inp_im_5_63;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00001001" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00001010");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= inp_im_5_63;
        o9_re_join_49_1 <= inp_re_5_56;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00001010" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00001011");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= inp_re_5_56;
        o10_im_join_49_1 <= inp_im_5_63;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00001011" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00001100");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= inp_re_5_56;
        o11_im_join_49_1 <= inp_im_5_63;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00001100" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00001101");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= inp_im_5_63;
        o12_re_join_49_1 <= inp_re_5_56;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00001101" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00001110");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= inp_re_5_56;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= inp_re_5_56;
        o13_im_join_49_1 <= inp_im_5_63;
        out_im_join_49_1 <= inp_im_5_63;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00001110" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00001111");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= inp_re_5_56;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= inp_im_5_63;
        o14_re_join_49_1 <= inp_re_5_56;
        o14_im_join_49_1 <= inp_im_5_63;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00001111" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00010000");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= inp_re_5_56;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= inp_im_5_63;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= inp_im_5_63;
        o15_re_join_49_1 <= inp_re_5_56;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00010000" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00010001");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= inp_re_5_56;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= inp_im_5_63;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= inp_im_5_63;
        o16_re_join_49_1 <= inp_re_5_56;
      when "00010001" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00010010");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i1_re_6_14;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i1_im_8_13;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00010010" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00010011");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i2_re_6_22;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i2_im_8_21;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00010011" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00010100");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i3_re_6_30;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i3_im_8_29;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00010100" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00010101");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i4_re_6_37;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i4_im_8_36;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00010101" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00010110");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i5_re_6_45;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i5_im_8_44;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00010110" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00010111");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i6_re_6_53;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i6_im_8_52;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00010111" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00011000");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i7_re_6_61;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i7_im_8_60;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00011000" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00011001");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i8_re_7_5;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i8_im_9_5;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00011001" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00011010");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i9_re_7_13;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i9_im_9_13;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00011010" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00011011");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i10_re_7_21;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i10_im_9_21;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00011011" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00011100");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i11_re_7_29;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i11_im_9_29;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00011100" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00011101");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i12_re_7_37;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i12_im_9_37;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00011101" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00011110");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i13_re_7_45;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i13_im_9_45;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00011110" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00011111");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i14_re_7_53;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i14_im_9_53;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00011111" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00100000");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i15_re_7_61;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i15_im_9_61;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when "00100000" =>
        statei_join_49_1 <= std_logic_vector_to_unsigned("00000000");
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= i16_re_8_5;
        pop_join_49_1 <= std_logic_vector_to_unsigned("1");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= i16_im_10_5;
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
      when others =>
        statei_join_49_1 <= statei_10_14;
        o1_im_join_49_1 <= i1_im_8_13;
        o1_re_join_49_1 <= i1_re_6_14;
        o2_re_join_49_1 <= i2_re_6_22;
        o2_im_join_49_1 <= i2_im_8_21;
        o3_im_join_49_1 <= i3_im_8_29;
        o3_re_join_49_1 <= i3_re_6_30;
        o4_im_join_49_1 <= i4_im_8_36;
        o4_re_join_49_1 <= i4_re_6_37;
        o5_im_join_49_1 <= i5_im_8_44;
        o5_re_join_49_1 <= i5_re_6_45;
        o6_re_join_49_1 <= i6_re_6_53;
        o6_im_join_49_1 <= i6_im_8_52;
        o7_im_join_49_1 <= i7_im_8_60;
        o7_re_join_49_1 <= i7_re_6_61;
        o8_re_join_49_1 <= i8_re_7_5;
        o8_im_join_49_1 <= i8_im_9_5;
        o9_im_join_49_1 <= i9_im_9_13;
        o9_re_join_49_1 <= i9_re_7_13;
        o10_re_join_49_1 <= i10_re_7_21;
        o10_im_join_49_1 <= i10_im_9_21;
        o11_re_join_49_1 <= i11_re_7_29;
        o11_im_join_49_1 <= i11_im_9_29;
        o12_im_join_49_1 <= i12_im_9_37;
        o12_re_join_49_1 <= i12_re_7_37;
        out_re_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_49_1 <= std_logic_vector_to_unsigned("0");
        o13_re_join_49_1 <= i13_re_7_45;
        o13_im_join_49_1 <= i13_im_9_45;
        out_im_join_49_1 <= std_logic_vector_to_signed("000000000000000000000");
        o14_re_join_49_1 <= i14_re_7_53;
        o14_im_join_49_1 <= i14_im_9_53;
        o15_im_join_49_1 <= i15_im_9_61;
        o15_re_join_49_1 <= i15_re_7_61;
        o16_im_join_49_1 <= i16_im_10_5;
        o16_re_join_49_1 <= i16_re_8_5;
    end case;
  end process proc_switch_49_1;
  out_re <= signed_to_std_logic_vector(out_re_join_49_1);
  out_im <= signed_to_std_logic_vector(out_im_join_49_1);
  pop <= unsigned_to_std_logic_vector(pop_join_49_1);
  o1_re <= signed_to_std_logic_vector(o1_re_join_49_1);
  o2_re <= signed_to_std_logic_vector(o2_re_join_49_1);
  o3_re <= signed_to_std_logic_vector(o3_re_join_49_1);
  o4_re <= signed_to_std_logic_vector(o4_re_join_49_1);
  o5_re <= signed_to_std_logic_vector(o5_re_join_49_1);
  o6_re <= signed_to_std_logic_vector(o6_re_join_49_1);
  o7_re <= signed_to_std_logic_vector(o7_re_join_49_1);
  o8_re <= signed_to_std_logic_vector(o8_re_join_49_1);
  o9_re <= signed_to_std_logic_vector(o9_re_join_49_1);
  o10_re <= signed_to_std_logic_vector(o10_re_join_49_1);
  o11_re <= signed_to_std_logic_vector(o11_re_join_49_1);
  o12_re <= signed_to_std_logic_vector(o12_re_join_49_1);
  o13_re <= signed_to_std_logic_vector(o13_re_join_49_1);
  o14_re <= signed_to_std_logic_vector(o14_re_join_49_1);
  o15_re <= signed_to_std_logic_vector(o15_re_join_49_1);
  o16_re <= signed_to_std_logic_vector(o16_re_join_49_1);
  o1_im <= signed_to_std_logic_vector(o1_im_join_49_1);
  o2_im <= signed_to_std_logic_vector(o2_im_join_49_1);
  o3_im <= signed_to_std_logic_vector(o3_im_join_49_1);
  o4_im <= signed_to_std_logic_vector(o4_im_join_49_1);
  o5_im <= signed_to_std_logic_vector(o5_im_join_49_1);
  o6_im <= signed_to_std_logic_vector(o6_im_join_49_1);
  o7_im <= signed_to_std_logic_vector(o7_im_join_49_1);
  o8_im <= signed_to_std_logic_vector(o8_im_join_49_1);
  o9_im <= signed_to_std_logic_vector(o9_im_join_49_1);
  o10_im <= signed_to_std_logic_vector(o10_im_join_49_1);
  o11_im <= signed_to_std_logic_vector(o11_im_join_49_1);
  o12_im <= signed_to_std_logic_vector(o12_im_join_49_1);
  o13_im <= signed_to_std_logic_vector(o13_im_join_49_1);
  o14_im <= signed_to_std_logic_vector(o14_im_join_49_1);
  o15_im <= signed_to_std_logic_vector(o15_im_join_49_1);
  o16_im <= signed_to_std_logic_vector(o16_im_join_49_1);
  stateo <= unsigned_to_std_logic_vector(statei_join_49_1);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_c4c1fd841d is
  port (
    op : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_c4c1fd841d;
architecture behavior of sysgen_constant_c4c1fd841d
is
begin
  op <= "0";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_addsub_a4a3676596 is
  port (
    a : in std_logic_vector((1 - 1) downto 0);
    b : in std_logic_vector((1 - 1) downto 0);
    s : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_addsub_a4a3676596;
architecture behavior of sysgen_addsub_a4a3676596
is
  signal a_17_32: unsigned((1 - 1) downto 0);
  signal b_17_35: unsigned((1 - 1) downto 0);
  type array_type_op_mem_91_20 is array (0 to (1 - 1)) of unsigned((1 - 1) downto 0);
  signal op_mem_91_20: array_type_op_mem_91_20 := (
    0 => "0");
  signal op_mem_91_20_front_din: unsigned((1 - 1) downto 0);
  signal op_mem_91_20_back: unsigned((1 - 1) downto 0);
  signal op_mem_91_20_push_front_pop_back_en: std_logic;
  type array_type_cout_mem_92_22 is array (0 to (1 - 1)) of unsigned((1 - 1) downto 0);
  signal cout_mem_92_22: array_type_cout_mem_92_22 := (
    0 => "0");
  signal cout_mem_92_22_front_din: unsigned((1 - 1) downto 0);
  signal cout_mem_92_22_back: unsigned((1 - 1) downto 0);
  signal cout_mem_92_22_push_front_pop_back_en: std_logic;
  signal prev_mode_93_22_next: unsigned((3 - 1) downto 0);
  signal prev_mode_93_22: unsigned((3 - 1) downto 0);
  signal prev_mode_93_22_reg_i: std_logic_vector((3 - 1) downto 0);
  signal prev_mode_93_22_reg_o: std_logic_vector((3 - 1) downto 0);
  signal cast_71_18: signed((3 - 1) downto 0);
  signal cast_71_22: signed((3 - 1) downto 0);
  signal internal_s_71_5_addsub: signed((3 - 1) downto 0);
  signal cast_internal_s_83_3_convert: unsigned((1 - 1) downto 0);
begin
  a_17_32 <= std_logic_vector_to_unsigned(a);
  b_17_35 <= std_logic_vector_to_unsigned(b);
  op_mem_91_20_back <= op_mem_91_20(0);
  proc_op_mem_91_20: process (clk)
  is
    variable i: integer;
  begin
    if (clk'event and (clk = '1')) then
      if ((ce = '1') and (op_mem_91_20_push_front_pop_back_en = '1')) then
        op_mem_91_20(0) <= op_mem_91_20_front_din;
      end if;
    end if;
  end process proc_op_mem_91_20;
  cout_mem_92_22_back <= cout_mem_92_22(0);
  proc_cout_mem_92_22: process (clk)
  is
    variable i_x_000000: integer;
  begin
    if (clk'event and (clk = '1')) then
      if ((ce = '1') and (cout_mem_92_22_push_front_pop_back_en = '1')) then
        cout_mem_92_22(0) <= cout_mem_92_22_front_din;
      end if;
    end if;
  end process proc_cout_mem_92_22;
  prev_mode_93_22_reg_i <= unsigned_to_std_logic_vector(prev_mode_93_22_next);
  prev_mode_93_22 <= std_logic_vector_to_unsigned(prev_mode_93_22_reg_o);
  prev_mode_93_22_reg_inst: entity work.synth_reg_w_init
    generic map (
      init_index => 2, 
      init_value => b"010", 
      latency => 1, 
      width => 3)
    port map (
      ce => ce, 
      clk => clk, 
      clr => clr, 
      i => prev_mode_93_22_reg_i, 
      o => prev_mode_93_22_reg_o);
  cast_71_18 <= u2s_cast(a_17_32, 0, 3, 0);
  cast_71_22 <= u2s_cast(b_17_35, 0, 3, 0);
  internal_s_71_5_addsub <= cast_71_18 - cast_71_22;
  cast_internal_s_83_3_convert <= s2u_cast(internal_s_71_5_addsub, 0, 1, 0);
  op_mem_91_20_push_front_pop_back_en <= '0';
  cout_mem_92_22_push_front_pop_back_en <= '0';
  prev_mode_93_22_next <= std_logic_vector_to_unsigned("000");
  s <= unsigned_to_std_logic_vector(cast_internal_s_83_3_convert);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_6047eef043 is
  port (
    op : out std_logic_vector((4 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_6047eef043;
architecture behavior of sysgen_constant_6047eef043
is
begin
  op <= "1111";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

--$Header: /devl/xcs/repo/env/Jobs/sysgen/src/xbs/blocks/xlconvert/hdl/xlconvert.vhd,v 1.1 2004/11/22 00:17:30 rosty Exp $
---------------------------------------------------------------------
--
--  Filename      : xlconvert.vhd
--
--  Description   : VHDL description of a fixed point converter block that
--                  converts the input to a new output type.

--
---------------------------------------------------------------------


---------------------------------------------------------------------
--
--  Entity        : xlconvert
--
--  Architecture  : behavior
--
--  Description   : Top level VHDL description of fixed point conver block.
--
---------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


entity convert_func_call_basic_dmt_xlconvert is
    generic (
        din_width    : integer := 16;            -- Width of input
        din_bin_pt   : integer := 4;             -- Binary point of input
        din_arith    : integer := xlUnsigned;    -- Type of arith of input
        dout_width   : integer := 8;             -- Width of output
        dout_bin_pt  : integer := 2;             -- Binary point of output
        dout_arith   : integer := xlUnsigned;    -- Type of arith of output
        quantization : integer := xlTruncate;    -- xlRound or xlTruncate
        overflow     : integer := xlWrap);       -- xlSaturate or xlWrap
    port (
        din : in std_logic_vector (din_width-1 downto 0);
        result : out std_logic_vector (dout_width-1 downto 0));
end convert_func_call_basic_dmt_xlconvert ;

architecture behavior of convert_func_call_basic_dmt_xlconvert is
begin
    -- Convert to output type and do saturation arith.
    result <= convert_type(din, din_width, din_bin_pt, din_arith,
                           dout_width, dout_bin_pt, dout_arith,
                           quantization, overflow);
end behavior;


library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


entity basic_dmt_xlconvert  is
    generic (
        din_width    : integer := 16;            -- Width of input
        din_bin_pt   : integer := 4;             -- Binary point of input
        din_arith    : integer := xlUnsigned;    -- Type of arith of input
        dout_width   : integer := 8;             -- Width of output
        dout_bin_pt  : integer := 2;             -- Binary point of output
        dout_arith   : integer := xlUnsigned;    -- Type of arith of output
        en_width     : integer := 1;
        en_bin_pt    : integer := 0;
        en_arith     : integer := xlUnsigned;
        bool_conversion : integer :=0;           -- if one, convert ufix_1_0 to
                                                 -- bool
        latency      : integer := 0;             -- Ouput delay clk cycles
        quantization : integer := xlTruncate;    -- xlRound or xlTruncate
        overflow     : integer := xlWrap);       -- xlSaturate or xlWrap
    port (
        din : in std_logic_vector (din_width-1 downto 0);
        en  : in std_logic_vector (en_width-1 downto 0);
        ce  : in std_logic;
        clr : in std_logic;
        clk : in std_logic;
        dout : out std_logic_vector (dout_width-1 downto 0));

end basic_dmt_xlconvert ;

architecture behavior of basic_dmt_xlconvert  is

    component synth_reg
        generic (width       : integer;
                 latency     : integer);
        port (i       : in std_logic_vector(width-1 downto 0);
              ce      : in std_logic;
              clr     : in std_logic;
              clk     : in std_logic;
              o       : out std_logic_vector(width-1 downto 0));
    end component;

    component convert_func_call_basic_dmt_xlconvert 
        generic (
            din_width    : integer := 16;            -- Width of input
            din_bin_pt   : integer := 4;             -- Binary point of input
            din_arith    : integer := xlUnsigned;    -- Type of arith of input
            dout_width   : integer := 8;             -- Width of output
            dout_bin_pt  : integer := 2;             -- Binary point of output
            dout_arith   : integer := xlUnsigned;    -- Type of arith of output
            quantization : integer := xlTruncate;    -- xlRound or xlTruncate
            overflow     : integer := xlWrap);       -- xlSaturate or xlWrap
        port (
            din : in std_logic_vector (din_width-1 downto 0);
            result : out std_logic_vector (dout_width-1 downto 0));
    end component;


    -- synthesis translate_off
--    signal real_din, real_dout : real;    -- For debugging info ports
    -- synthesis translate_on
    signal result : std_logic_vector(dout_width-1 downto 0);
    signal internal_ce : std_logic;

begin

    -- Debugging info for internal full precision variables
    -- synthesis translate_off
--     real_din <= to_real(din, din_bin_pt, din_arith);
--     real_dout <= to_real(dout, dout_bin_pt, dout_arith);
    -- synthesis translate_on

    internal_ce <= ce and en(0);

    bool_conversion_generate : if (bool_conversion = 1)
    generate
      result <= din;
    end generate; --bool_conversion_generate

    std_conversion_generate : if (bool_conversion = 0)
    generate
      -- Workaround for XST bug
      convert : convert_func_call_basic_dmt_xlconvert 
        generic map (
          din_width   => din_width,
          din_bin_pt  => din_bin_pt,
          din_arith   => din_arith,
          dout_width  => dout_width,
          dout_bin_pt => dout_bin_pt,
          dout_arith  => dout_arith,
          quantization => quantization,
          overflow     => overflow)
        port map (
          din => din,
          result => result);
    end generate; --std_conversion_generate

    latency_test : if (latency > 0) generate
        reg : synth_reg
            generic map (
              width => dout_width,
              latency => latency
            )
            port map (
              i => result,
              ce => internal_ce,
              clr => clr,
              clk => clk,
              o => dout
            );
    end generate;

    latency0 : if (latency = 0)
    generate
        dout <= result;
    end generate latency0;

end  behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_5f9845ca1e is
  port (
    i1 : in std_logic_vector((16 - 1) downto 0);
    i2 : in std_logic_vector((16 - 1) downto 0);
    i3 : in std_logic_vector((16 - 1) downto 0);
    i4 : in std_logic_vector((16 - 1) downto 0);
    i5 : in std_logic_vector((16 - 1) downto 0);
    i6 : in std_logic_vector((16 - 1) downto 0);
    i7 : in std_logic_vector((16 - 1) downto 0);
    i8 : in std_logic_vector((16 - 1) downto 0);
    i9 : in std_logic_vector((16 - 1) downto 0);
    i10 : in std_logic_vector((16 - 1) downto 0);
    i11 : in std_logic_vector((16 - 1) downto 0);
    i12 : in std_logic_vector((16 - 1) downto 0);
    i13 : in std_logic_vector((16 - 1) downto 0);
    i14 : in std_logic_vector((16 - 1) downto 0);
    i15 : in std_logic_vector((16 - 1) downto 0);
    i16 : in std_logic_vector((16 - 1) downto 0);
    o1 : out std_logic_vector((16 - 1) downto 0);
    o2 : out std_logic_vector((16 - 1) downto 0);
    o3 : out std_logic_vector((16 - 1) downto 0);
    o4 : out std_logic_vector((16 - 1) downto 0);
    o5 : out std_logic_vector((16 - 1) downto 0);
    o6 : out std_logic_vector((16 - 1) downto 0);
    o7 : out std_logic_vector((16 - 1) downto 0);
    o8 : out std_logic_vector((16 - 1) downto 0);
    o9 : out std_logic_vector((16 - 1) downto 0);
    o10 : out std_logic_vector((16 - 1) downto 0);
    o11 : out std_logic_vector((16 - 1) downto 0);
    o12 : out std_logic_vector((16 - 1) downto 0);
    o13 : out std_logic_vector((16 - 1) downto 0);
    o14 : out std_logic_vector((16 - 1) downto 0);
    o15 : out std_logic_vector((16 - 1) downto 0);
    o16 : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_5f9845ca1e;
architecture behavior of sysgen_mcode_block_5f9845ca1e
is
  signal i1_3_12: signed((16 - 1) downto 0);
  signal i2_3_17: signed((16 - 1) downto 0);
  signal i3_3_22: signed((16 - 1) downto 0);
  signal i4_3_27: signed((16 - 1) downto 0);
  signal i5_3_32: signed((16 - 1) downto 0);
  signal i6_3_37: signed((16 - 1) downto 0);
  signal i7_3_42: signed((16 - 1) downto 0);
  signal i8_3_47: signed((16 - 1) downto 0);
  signal i9_3_52: signed((16 - 1) downto 0);
  signal i10_3_57: signed((16 - 1) downto 0);
  signal i11_3_62: signed((16 - 1) downto 0);
  signal i12_3_67: signed((16 - 1) downto 0);
  signal i13_4_17: signed((16 - 1) downto 0);
  signal i14_4_22: signed((16 - 1) downto 0);
  signal i15_4_27: signed((16 - 1) downto 0);
  signal i16_4_32: signed((16 - 1) downto 0);
  signal mult_7_39: signed((18 - 1) downto 0);
  signal cast_o1_7_1_convert: signed((16 - 1) downto 0);
  signal mult_15_39: signed((18 - 1) downto 0);
  signal cast_o9_15_1_convert: signed((16 - 1) downto 0);
begin
  i1_3_12 <= std_logic_vector_to_signed(i1);
  i2_3_17 <= std_logic_vector_to_signed(i2);
  i3_3_22 <= std_logic_vector_to_signed(i3);
  i4_3_27 <= std_logic_vector_to_signed(i4);
  i5_3_32 <= std_logic_vector_to_signed(i5);
  i6_3_37 <= std_logic_vector_to_signed(i6);
  i7_3_42 <= std_logic_vector_to_signed(i7);
  i8_3_47 <= std_logic_vector_to_signed(i8);
  i9_3_52 <= std_logic_vector_to_signed(i9);
  i10_3_57 <= std_logic_vector_to_signed(i10);
  i11_3_62 <= std_logic_vector_to_signed(i11);
  i12_3_67 <= std_logic_vector_to_signed(i12);
  i13_4_17 <= std_logic_vector_to_signed(i13);
  i14_4_22 <= std_logic_vector_to_signed(i14);
  i15_4_27 <= std_logic_vector_to_signed(i15);
  i16_4_32 <= std_logic_vector_to_signed(i16);
  mult_7_39 <= (i1_3_12 * std_logic_vector_to_signed("00"));
  cast_o1_7_1_convert <= s2s_cast(mult_7_39, 13, 16, 13);
  mult_15_39 <= (i9_3_52 * std_logic_vector_to_signed("00"));
  cast_o9_15_1_convert <= s2s_cast(mult_15_39, 13, 16, 13);
  o1 <= signed_to_std_logic_vector(cast_o1_7_1_convert);
  o2 <= signed_to_std_logic_vector(i2_3_17);
  o3 <= signed_to_std_logic_vector(i3_3_22);
  o4 <= signed_to_std_logic_vector(i4_3_27);
  o5 <= signed_to_std_logic_vector(i5_3_32);
  o6 <= signed_to_std_logic_vector(i6_3_37);
  o7 <= signed_to_std_logic_vector(i7_3_42);
  o8 <= signed_to_std_logic_vector(i8_3_47);
  o9 <= signed_to_std_logic_vector(cast_o9_15_1_convert);
  o10 <= signed_to_std_logic_vector(i10_3_57);
  o11 <= signed_to_std_logic_vector(i11_3_62);
  o12 <= signed_to_std_logic_vector(i12_3_67);
  o13 <= signed_to_std_logic_vector(i13_4_17);
  o14 <= signed_to_std_logic_vector(i14_4_22);
  o15 <= signed_to_std_logic_vector(i15_4_27);
  o16 <= signed_to_std_logic_vector(i16_4_32);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mux_e10439f9cf is
  port (
    sel : in std_logic_vector((4 - 1) downto 0);
    d0 : in std_logic_vector((16 - 1) downto 0);
    d1 : in std_logic_vector((16 - 1) downto 0);
    d2 : in std_logic_vector((16 - 1) downto 0);
    d3 : in std_logic_vector((16 - 1) downto 0);
    d4 : in std_logic_vector((16 - 1) downto 0);
    d5 : in std_logic_vector((16 - 1) downto 0);
    d6 : in std_logic_vector((16 - 1) downto 0);
    d7 : in std_logic_vector((16 - 1) downto 0);
    d8 : in std_logic_vector((16 - 1) downto 0);
    d9 : in std_logic_vector((16 - 1) downto 0);
    d10 : in std_logic_vector((16 - 1) downto 0);
    d11 : in std_logic_vector((16 - 1) downto 0);
    d12 : in std_logic_vector((16 - 1) downto 0);
    d13 : in std_logic_vector((16 - 1) downto 0);
    d14 : in std_logic_vector((16 - 1) downto 0);
    d15 : in std_logic_vector((16 - 1) downto 0);
    y : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mux_e10439f9cf;
architecture behavior of sysgen_mux_e10439f9cf
is
  signal sel_1_20: std_logic_vector((4 - 1) downto 0);
  signal d0_1_24: std_logic_vector((16 - 1) downto 0);
  signal d1_1_27: std_logic_vector((16 - 1) downto 0);
  signal d2_1_30: std_logic_vector((16 - 1) downto 0);
  signal d3_1_33: std_logic_vector((16 - 1) downto 0);
  signal d4_1_36: std_logic_vector((16 - 1) downto 0);
  signal d5_1_39: std_logic_vector((16 - 1) downto 0);
  signal d6_1_42: std_logic_vector((16 - 1) downto 0);
  signal d7_1_45: std_logic_vector((16 - 1) downto 0);
  signal d8_1_48: std_logic_vector((16 - 1) downto 0);
  signal d9_1_51: std_logic_vector((16 - 1) downto 0);
  signal d10_1_54: std_logic_vector((16 - 1) downto 0);
  signal d11_1_58: std_logic_vector((16 - 1) downto 0);
  signal d12_1_62: std_logic_vector((16 - 1) downto 0);
  signal d13_1_66: std_logic_vector((16 - 1) downto 0);
  signal d14_1_70: std_logic_vector((16 - 1) downto 0);
  signal d15_1_74: std_logic_vector((16 - 1) downto 0);
  type array_type_pipe_44_22 is array (0 to (1 - 1)) of std_logic_vector((16 - 1) downto 0);
  signal pipe_44_22: array_type_pipe_44_22 := (
    0 => "0000000000000000");
  signal pipe_44_22_front_din: std_logic_vector((16 - 1) downto 0);
  signal pipe_44_22_back: std_logic_vector((16 - 1) downto 0);
  signal pipe_44_22_push_front_pop_back_en: std_logic;
  signal unregy_join_6_1: std_logic_vector((16 - 1) downto 0);
begin
  sel_1_20 <= sel;
  d0_1_24 <= d0;
  d1_1_27 <= d1;
  d2_1_30 <= d2;
  d3_1_33 <= d3;
  d4_1_36 <= d4;
  d5_1_39 <= d5;
  d6_1_42 <= d6;
  d7_1_45 <= d7;
  d8_1_48 <= d8;
  d9_1_51 <= d9;
  d10_1_54 <= d10;
  d11_1_58 <= d11;
  d12_1_62 <= d12;
  d13_1_66 <= d13;
  d14_1_70 <= d14;
  d15_1_74 <= d15;
  pipe_44_22_back <= pipe_44_22(0);
  proc_pipe_44_22: process (clk)
  is
    variable i: integer;
  begin
    if (clk'event and (clk = '1')) then
      if ((ce = '1') and (pipe_44_22_push_front_pop_back_en = '1')) then
        pipe_44_22(0) <= pipe_44_22_front_din;
      end if;
    end if;
  end process proc_pipe_44_22;
  proc_switch_6_1: process (d0_1_24, d10_1_54, d11_1_58, d12_1_62, d13_1_66, d14_1_70, d15_1_74, d1_1_27, d2_1_30, d3_1_33, d4_1_36, d5_1_39, d6_1_42, d7_1_45, d8_1_48, d9_1_51, sel_1_20)
  is
  begin
    case sel_1_20 is 
      when "0000" =>
        unregy_join_6_1 <= d0_1_24;
      when "0001" =>
        unregy_join_6_1 <= d1_1_27;
      when "0010" =>
        unregy_join_6_1 <= d2_1_30;
      when "0011" =>
        unregy_join_6_1 <= d3_1_33;
      when "0100" =>
        unregy_join_6_1 <= d4_1_36;
      when "0101" =>
        unregy_join_6_1 <= d5_1_39;
      when "0110" =>
        unregy_join_6_1 <= d6_1_42;
      when "0111" =>
        unregy_join_6_1 <= d7_1_45;
      when "1000" =>
        unregy_join_6_1 <= d8_1_48;
      when "1001" =>
        unregy_join_6_1 <= d9_1_51;
      when "1010" =>
        unregy_join_6_1 <= d10_1_54;
      when "1011" =>
        unregy_join_6_1 <= d11_1_58;
      when "1100" =>
        unregy_join_6_1 <= d12_1_62;
      when "1101" =>
        unregy_join_6_1 <= d13_1_66;
      when "1110" =>
        unregy_join_6_1 <= d14_1_70;
      when others =>
        unregy_join_6_1 <= d15_1_74;
    end case;
  end process proc_switch_6_1;
  pipe_44_22_front_din <= unregy_join_6_1;
  pipe_44_22_push_front_pop_back_en <= '1';
  y <= pipe_44_22_back;
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_reinterpret_f8109ce444 is
  port (
    input_port : in std_logic_vector((21 - 1) downto 0);
    output_port : out std_logic_vector((21 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_reinterpret_f8109ce444;
architecture behavior of sysgen_reinterpret_f8109ce444
is
  signal input_port_1_40: signed((21 - 1) downto 0);
begin
  input_port_1_40 <= std_logic_vector_to_signed(input_port);
  output_port <= signed_to_std_logic_vector(input_port_1_40);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_relational_c72c00b807 is
  port (
    a : in std_logic_vector((4 - 1) downto 0);
    b : in std_logic_vector((4 - 1) downto 0);
    op : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_relational_c72c00b807;
architecture behavior of sysgen_relational_c72c00b807
is
  signal a_1_31: unsigned((4 - 1) downto 0);
  signal b_1_34: unsigned((4 - 1) downto 0);
  signal result_12_3_rel: boolean;
begin
  a_1_31 <= std_logic_vector_to_unsigned(a);
  b_1_34 <= std_logic_vector_to_unsigned(b);
  result_12_3_rel <= a_1_31 = b_1_34;
  op <= boolean_to_vector(result_12_3_rel);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_reinterpret_81a8d7a2c8 is
  port (
    input_port : in std_logic_vector((16 - 1) downto 0);
    output_port : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_reinterpret_81a8d7a2c8;
architecture behavior of sysgen_reinterpret_81a8d7a2c8
is
  signal input_port_1_40: signed((16 - 1) downto 0);
begin
  input_port_1_40 <= std_logic_vector_to_signed(input_port);
  output_port <= signed_to_std_logic_vector(input_port_1_40);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_bitbasher_b99de7e501 is
  port (
    a : in std_logic_vector((4 - 1) downto 0);
    b : out std_logic_vector((2 - 1) downto 0);
    c : out std_logic_vector((2 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_bitbasher_b99de7e501;
architecture behavior of sysgen_bitbasher_b99de7e501
is
  signal a_1_28: unsigned((4 - 1) downto 0);
  signal slice_5_28: unsigned((2 - 1) downto 0);
  signal fullb_5_1_concat: unsigned((2 - 1) downto 0);
  signal slice_6_28: unsigned((2 - 1) downto 0);
  signal fullc_6_1_concat: unsigned((2 - 1) downto 0);
begin
  a_1_28 <= std_logic_vector_to_unsigned(a);
  slice_5_28 <= u2u_slice(a_1_28, 3, 2);
  fullb_5_1_concat <= std_logic_vector_to_unsigned(unsigned_to_std_logic_vector(slice_5_28));
  slice_6_28 <= u2u_slice(a_1_28, 1, 0);
  fullc_6_1_concat <= std_logic_vector_to_unsigned(unsigned_to_std_logic_vector(slice_6_28));
  b <= unsigned_to_std_logic_vector(fullb_5_1_concat);
  c <= unsigned_to_std_logic_vector(fullc_6_1_concat);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_e75a4c2335 is
  port (
    op : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_e75a4c2335;
architecture behavior of sysgen_constant_e75a4c2335
is
begin
  op <= "1010000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_1a3f20e021 is
  port (
    op : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_1a3f20e021;
architecture behavior of sysgen_constant_1a3f20e021
is
begin
  op <= "1110000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_9986852557 is
  port (
    op : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_9986852557;
architecture behavior of sysgen_constant_9986852557
is
begin
  op <= "0110000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_7b97c80a71 is
  port (
    op : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_7b97c80a71;
architecture behavior of sysgen_constant_7b97c80a71
is
begin
  op <= "0010000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mux_1870d2b50d is
  port (
    sel : in std_logic_vector((2 - 1) downto 0);
    d0 : in std_logic_vector((16 - 1) downto 0);
    d1 : in std_logic_vector((16 - 1) downto 0);
    d2 : in std_logic_vector((16 - 1) downto 0);
    d3 : in std_logic_vector((16 - 1) downto 0);
    y : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mux_1870d2b50d;
architecture behavior of sysgen_mux_1870d2b50d
is
  signal sel_1_20: std_logic_vector((2 - 1) downto 0);
  signal d0_1_24: std_logic_vector((16 - 1) downto 0);
  signal d1_1_27: std_logic_vector((16 - 1) downto 0);
  signal d2_1_30: std_logic_vector((16 - 1) downto 0);
  signal d3_1_33: std_logic_vector((16 - 1) downto 0);
  type array_type_pipe_20_22 is array (0 to (1 - 1)) of std_logic_vector((16 - 1) downto 0);
  signal pipe_20_22: array_type_pipe_20_22 := (
    0 => "0000000000000000");
  signal pipe_20_22_front_din: std_logic_vector((16 - 1) downto 0);
  signal pipe_20_22_back: std_logic_vector((16 - 1) downto 0);
  signal pipe_20_22_push_front_pop_back_en: std_logic;
  signal unregy_join_6_1: std_logic_vector((16 - 1) downto 0);
begin
  sel_1_20 <= sel;
  d0_1_24 <= d0;
  d1_1_27 <= d1;
  d2_1_30 <= d2;
  d3_1_33 <= d3;
  pipe_20_22_back <= pipe_20_22(0);
  proc_pipe_20_22: process (clk)
  is
    variable i: integer;
  begin
    if (clk'event and (clk = '1')) then
      if ((ce = '1') and (pipe_20_22_push_front_pop_back_en = '1')) then
        pipe_20_22(0) <= pipe_20_22_front_din;
      end if;
    end if;
  end process proc_pipe_20_22;
  proc_switch_6_1: process (d0_1_24, d1_1_27, d2_1_30, d3_1_33, sel_1_20)
  is
  begin
    case sel_1_20 is 
      when "00" =>
        unregy_join_6_1 <= d0_1_24;
      when "01" =>
        unregy_join_6_1 <= d1_1_27;
      when "10" =>
        unregy_join_6_1 <= d2_1_30;
      when others =>
        unregy_join_6_1 <= d3_1_33;
    end case;
  end process proc_switch_6_1;
  pipe_20_22_front_din <= unregy_join_6_1;
  pipe_20_22_push_front_pop_back_en <= '1';
  y <= pipe_20_22_back;
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_concat_9b747ee43b is
  port (
    in0 : in std_logic_vector((4 - 1) downto 0);
    in1 : in std_logic_vector((4 - 1) downto 0);
    in2 : in std_logic_vector((4 - 1) downto 0);
    in3 : in std_logic_vector((4 - 1) downto 0);
    in4 : in std_logic_vector((4 - 1) downto 0);
    in5 : in std_logic_vector((4 - 1) downto 0);
    in6 : in std_logic_vector((4 - 1) downto 0);
    in7 : in std_logic_vector((4 - 1) downto 0);
    in8 : in std_logic_vector((4 - 1) downto 0);
    in9 : in std_logic_vector((4 - 1) downto 0);
    in10 : in std_logic_vector((4 - 1) downto 0);
    in11 : in std_logic_vector((4 - 1) downto 0);
    in12 : in std_logic_vector((4 - 1) downto 0);
    in13 : in std_logic_vector((4 - 1) downto 0);
    in14 : in std_logic_vector((4 - 1) downto 0);
    in15 : in std_logic_vector((4 - 1) downto 0);
    y : out std_logic_vector((64 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_concat_9b747ee43b;
architecture behavior of sysgen_concat_9b747ee43b
is
  signal in0_1_23: unsigned((4 - 1) downto 0);
  signal in1_1_27: unsigned((4 - 1) downto 0);
  signal in2_1_31: unsigned((4 - 1) downto 0);
  signal in3_1_35: unsigned((4 - 1) downto 0);
  signal in4_1_39: unsigned((4 - 1) downto 0);
  signal in5_1_43: unsigned((4 - 1) downto 0);
  signal in6_1_47: unsigned((4 - 1) downto 0);
  signal in7_1_51: unsigned((4 - 1) downto 0);
  signal in8_1_55: unsigned((4 - 1) downto 0);
  signal in9_1_59: unsigned((4 - 1) downto 0);
  signal in10_1_63: unsigned((4 - 1) downto 0);
  signal in11_1_68: unsigned((4 - 1) downto 0);
  signal in12_1_73: unsigned((4 - 1) downto 0);
  signal in13_1_78: unsigned((4 - 1) downto 0);
  signal in14_1_83: unsigned((4 - 1) downto 0);
  signal in15_1_88: unsigned((4 - 1) downto 0);
  signal y_2_1_concat: unsigned((64 - 1) downto 0);
begin
  in0_1_23 <= std_logic_vector_to_unsigned(in0);
  in1_1_27 <= std_logic_vector_to_unsigned(in1);
  in2_1_31 <= std_logic_vector_to_unsigned(in2);
  in3_1_35 <= std_logic_vector_to_unsigned(in3);
  in4_1_39 <= std_logic_vector_to_unsigned(in4);
  in5_1_43 <= std_logic_vector_to_unsigned(in5);
  in6_1_47 <= std_logic_vector_to_unsigned(in6);
  in7_1_51 <= std_logic_vector_to_unsigned(in7);
  in8_1_55 <= std_logic_vector_to_unsigned(in8);
  in9_1_59 <= std_logic_vector_to_unsigned(in9);
  in10_1_63 <= std_logic_vector_to_unsigned(in10);
  in11_1_68 <= std_logic_vector_to_unsigned(in11);
  in12_1_73 <= std_logic_vector_to_unsigned(in12);
  in13_1_78 <= std_logic_vector_to_unsigned(in13);
  in14_1_83 <= std_logic_vector_to_unsigned(in14);
  in15_1_88 <= std_logic_vector_to_unsigned(in15);
  y_2_1_concat <= std_logic_vector_to_unsigned(unsigned_to_std_logic_vector(in0_1_23) & unsigned_to_std_logic_vector(in1_1_27) & unsigned_to_std_logic_vector(in2_1_31) & unsigned_to_std_logic_vector(in3_1_35) & unsigned_to_std_logic_vector(in4_1_39) & unsigned_to_std_logic_vector(in5_1_43) & unsigned_to_std_logic_vector(in6_1_47) & unsigned_to_std_logic_vector(in7_1_51) & unsigned_to_std_logic_vector(in8_1_55) & unsigned_to_std_logic_vector(in9_1_59) & unsigned_to_std_logic_vector(in10_1_63) & unsigned_to_std_logic_vector(in11_1_68) & unsigned_to_std_logic_vector(in12_1_73) & unsigned_to_std_logic_vector(in13_1_78) & unsigned_to_std_logic_vector(in14_1_83) & unsigned_to_std_logic_vector(in15_1_88));
  y <= unsigned_to_std_logic_vector(y_2_1_concat);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_7852e0a78d is
  port (
    frameen : in std_logic_vector((1 - 1) downto 0);
    statei : in std_logic_vector((2 - 1) downto 0);
    loopcounti : in std_logic_vector((8 - 1) downto 0);
    subcari : in std_logic_vector((8 - 1) downto 0);
    subcarcounti : in std_logic_vector((8 - 1) downto 0);
    starti : in std_logic_vector((1 - 1) downto 0);
    enablei : in std_logic_vector((1 - 1) downto 0);
    push : out std_logic_vector((1 - 1) downto 0);
    pop : out std_logic_vector((1 - 1) downto 0);
    stateo : out std_logic_vector((2 - 1) downto 0);
    loopcounto : out std_logic_vector((8 - 1) downto 0);
    subcaro : out std_logic_vector((8 - 1) downto 0);
    subcarcounto : out std_logic_vector((8 - 1) downto 0);
    starto : out std_logic_vector((1 - 1) downto 0);
    enableo : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_7852e0a78d;
architecture behavior of sysgen_mcode_block_7852e0a78d
is
  signal frameen_2_21: boolean;
  signal statei_2_30: unsigned((2 - 1) downto 0);
  signal loopcounti_2_38: unsigned((8 - 1) downto 0);
  signal subcari_2_50: unsigned((8 - 1) downto 0);
  signal subcarcounti_2_59: unsigned((8 - 1) downto 0);
  signal starti_2_73: boolean;
  signal enablei_2_81: boolean;
  signal pop_join_8_1: boolean;
  signal push_join_8_1: boolean;
  signal rel_45_4: boolean;
  signal rel_45_23: boolean;
  signal bool_45_4: boolean;
  signal conpop_join_45_1: unsigned((1 - 1) downto 0);
  signal cast_51_14: unsigned((9 - 1) downto 0);
  signal loopcounti_51_1_addsub: unsigned((9 - 1) downto 0);
  signal rel_52_4: boolean;
  signal loopcounti_join_52_1: unsigned((9 - 1) downto 0);
  signal cast_56_16: unsigned((9 - 1) downto 0);
  signal subcarcounti_56_1_addsub: unsigned((9 - 1) downto 0);
  signal cast_58_11: unsigned((9 - 1) downto 0);
  signal subcari_58_1_addsub: unsigned((9 - 1) downto 0);
  signal rel_57_4: boolean;
  signal subcarcounti_join_57_1: unsigned((9 - 1) downto 0);
  signal subcari_join_57_1: unsigned((9 - 1) downto 0);
  signal rel_62_4: boolean;
  signal starti_join_62_1: boolean;
  signal subcari_join_62_1: unsigned((9 - 1) downto 0);
  signal rel_67_4: boolean;
  signal starti_join_67_1: boolean;
  signal subcari_join_67_1: unsigned((9 - 1) downto 0);
  signal enablei_join_67_1: boolean;
  signal rel_74_4: boolean;
  signal rel_74_25: boolean;
  signal rel_74_46: boolean;
  signal rel_75_4: boolean;
  signal rel_75_25: boolean;
  signal rel_75_46: boolean;
  signal rel_76_4: boolean;
  signal rel_76_25: boolean;
  signal rel_76_46: boolean;
  signal rel_77_4: boolean;
  signal rel_77_25: boolean;
  signal rel_77_46: boolean;
  signal rel_78_4: boolean;
  signal rel_78_25: boolean;
  signal rel_78_46: boolean;
  signal rel_79_4: boolean;
  signal rel_79_25: boolean;
  signal bool_74_4: boolean;
  signal conpush_join_74_1: unsigned((1 - 1) downto 0);
  signal rel_85_8: boolean;
  signal statei_join_85_5: unsigned((2 - 1) downto 0);
  signal rel_92_8: boolean;
  signal statei_join_92_5: unsigned((2 - 1) downto 0);
  signal rel_84_4: boolean;
  signal statei_join_84_1: unsigned((2 - 1) downto 0);
  signal cast_loopcounto_101_1_convert: unsigned((8 - 1) downto 0);
  signal cast_subcaro_102_1_convert: unsigned((8 - 1) downto 0);
  signal cast_subcarcounto_103_1_convert: unsigned((8 - 1) downto 0);
begin
  frameen_2_21 <= ((frameen) = "1");
  statei_2_30 <= std_logic_vector_to_unsigned(statei);
  loopcounti_2_38 <= std_logic_vector_to_unsigned(loopcounti);
  subcari_2_50 <= std_logic_vector_to_unsigned(subcari);
  subcarcounti_2_59 <= std_logic_vector_to_unsigned(subcarcounti);
  starti_2_73 <= ((starti) = "1");
  enablei_2_81 <= ((enablei) = "1");
  proc_switch_8_1: process (statei_2_30)
  is
  begin
    case statei_2_30 is 
      when "00" =>
        pop_join_8_1 <= false;
        push_join_8_1 <= false;
      when "01" =>
        pop_join_8_1 <= false;
        push_join_8_1 <= true;
      when "10" =>
        pop_join_8_1 <= true;
        push_join_8_1 <= false;
      when "11" =>
        pop_join_8_1 <= true;
        push_join_8_1 <= true;
      when others =>
        pop_join_8_1 <= false;
        push_join_8_1 <= false;
    end case;
  end process proc_switch_8_1;
  rel_45_4 <= loopcounti_2_38 = std_logic_vector_to_unsigned("00000000");
  rel_45_23 <= enablei_2_81 = true;
  bool_45_4 <= rel_45_4 and rel_45_23;
  proc_if_45_1: process (bool_45_4)
  is
  begin
    if bool_45_4 then
      conpop_join_45_1 <= std_logic_vector_to_unsigned("1");
    else 
      conpop_join_45_1 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_45_1;
  cast_51_14 <= u2u_cast(loopcounti_2_38, 0, 9, 0);
  loopcounti_51_1_addsub <= cast_51_14 + std_logic_vector_to_unsigned("000000001");
  rel_52_4 <= loopcounti_51_1_addsub >= std_logic_vector_to_unsigned("000000101");
  proc_if_52_1: process (loopcounti_51_1_addsub, rel_52_4)
  is
  begin
    if rel_52_4 then
      loopcounti_join_52_1 <= std_logic_vector_to_unsigned("000000000");
    else 
      loopcounti_join_52_1 <= loopcounti_51_1_addsub;
    end if;
  end process proc_if_52_1;
  cast_56_16 <= u2u_cast(subcarcounti_2_59, 0, 9, 0);
  subcarcounti_56_1_addsub <= cast_56_16 + std_logic_vector_to_unsigned("000000001");
  cast_58_11 <= u2u_cast(subcari_2_50, 0, 9, 0);
  subcari_58_1_addsub <= cast_58_11 + std_logic_vector_to_unsigned("000000001");
  rel_57_4 <= subcarcounti_56_1_addsub >= std_logic_vector_to_unsigned("000000100");
  proc_if_57_1: process (rel_57_4, subcarcounti_56_1_addsub, subcari_2_50, subcari_58_1_addsub)
  is
  begin
    if rel_57_4 then
      subcarcounti_join_57_1 <= std_logic_vector_to_unsigned("000000000");
      subcari_join_57_1 <= subcari_58_1_addsub;
    else 
      subcarcounti_join_57_1 <= subcarcounti_56_1_addsub;
      subcari_join_57_1 <= u2u_cast(subcari_2_50, 0, 9, 0);
    end if;
  end process proc_if_57_1;
  rel_62_4 <= subcari_join_57_1 > std_logic_vector_to_unsigned("000010000");
  proc_if_62_1: process (rel_62_4, starti_2_73, subcari_join_57_1)
  is
  begin
    if rel_62_4 then
      starti_join_62_1 <= false;
      subcari_join_62_1 <= std_logic_vector_to_unsigned("000000000");
    else 
      starti_join_62_1 <= starti_2_73;
      subcari_join_62_1 <= subcari_join_57_1;
    end if;
  end process proc_if_62_1;
  rel_67_4 <= frameen_2_21 = true;
  proc_if_67_1: process (enablei_2_81, rel_67_4, starti_join_62_1, subcari_join_62_1)
  is
  begin
    if rel_67_4 then
      starti_join_67_1 <= true;
      subcari_join_67_1 <= std_logic_vector_to_unsigned("000000000");
      enablei_join_67_1 <= true;
    else 
      starti_join_67_1 <= starti_join_62_1;
      subcari_join_67_1 <= subcari_join_62_1;
      enablei_join_67_1 <= enablei_2_81;
    end if;
  end process proc_if_67_1;
  rel_74_4 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000001");
  rel_74_25 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_74_46 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_75_4 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_75_25 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_75_46 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_76_4 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_76_25 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_76_46 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000001001");
  rel_77_4 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_77_25 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_77_46 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_78_4 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_78_25 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_78_46 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_79_4 <= subcari_join_67_1 /= std_logic_vector_to_unsigned("000000000");
  rel_79_25 <= starti_join_67_1 = true;
  bool_74_4 <= rel_74_4 and rel_74_25 and rel_74_46 and rel_75_4 and rel_75_25 and rel_75_46 and rel_76_4 and rel_76_25 and rel_76_46 and rel_77_4 and rel_77_25 and rel_77_46 and rel_78_4 and rel_78_25 and rel_78_46 and rel_79_4 and rel_79_25;
  proc_if_74_1: process (bool_74_4)
  is
  begin
    if bool_74_4 then
      conpush_join_74_1 <= std_logic_vector_to_unsigned("1");
    else 
      conpush_join_74_1 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_74_1;
  rel_85_8 <= conpop_join_45_1 = std_logic_vector_to_unsigned("1");
  proc_if_85_5: process (rel_85_8)
  is
  begin
    if rel_85_8 then
      statei_join_85_5 <= std_logic_vector_to_unsigned("11");
    else 
      statei_join_85_5 <= std_logic_vector_to_unsigned("01");
    end if;
  end process proc_if_85_5;
  rel_92_8 <= conpop_join_45_1 = std_logic_vector_to_unsigned("1");
  proc_if_92_5: process (rel_92_8)
  is
  begin
    if rel_92_8 then
      statei_join_92_5 <= std_logic_vector_to_unsigned("10");
    else 
      statei_join_92_5 <= std_logic_vector_to_unsigned("00");
    end if;
  end process proc_if_92_5;
  rel_84_4 <= conpush_join_74_1 = std_logic_vector_to_unsigned("1");
  proc_if_84_1: process (rel_84_4, statei_join_85_5, statei_join_92_5)
  is
  begin
    if rel_84_4 then
      statei_join_84_1 <= statei_join_85_5;
    else 
      statei_join_84_1 <= statei_join_92_5;
    end if;
  end process proc_if_84_1;
  cast_loopcounto_101_1_convert <= u2u_cast(loopcounti_join_52_1, 0, 8, 0);
  cast_subcaro_102_1_convert <= u2u_cast(subcari_join_67_1, 0, 8, 0);
  cast_subcarcounto_103_1_convert <= u2u_cast(subcarcounti_join_57_1, 0, 8, 0);
  push <= boolean_to_vector(push_join_8_1);
  pop <= boolean_to_vector(pop_join_8_1);
  stateo <= unsigned_to_std_logic_vector(statei_join_84_1);
  loopcounto <= unsigned_to_std_logic_vector(cast_loopcounto_101_1_convert);
  subcaro <= unsigned_to_std_logic_vector(cast_subcaro_102_1_convert);
  subcarcounto <= unsigned_to_std_logic_vector(cast_subcarcounto_103_1_convert);
  starto <= boolean_to_vector(starti_join_67_1);
  enableo <= boolean_to_vector(enablei_join_67_1);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

---------------------------------------------------------------------
--
--  Filename      : xlslice.vhd
--
--  Description   : VHDL description of a block that sets the output to a
--                  specified range of the input bits. The output is always
--                  set to an unsigned type with it's binary point at zero.
--
---------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


entity basic_dmt_xlslice is
    generic (
        new_msb      : integer := 9;           -- position of new msb
        new_lsb      : integer := 1;           -- position of new lsb
        x_width      : integer := 16;          -- Width of x input
        y_width      : integer := 8);          -- Width of y output
    port (
        x : in std_logic_vector (x_width-1 downto 0);
        y : out std_logic_vector (y_width-1 downto 0));
end basic_dmt_xlslice;

architecture behavior of basic_dmt_xlslice is
begin
    y <= x(new_msb downto new_lsb);
end  behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_96bf53b8c9 is
  port (
    num : in std_logic_vector((7 - 1) downto 0);
    frameen : in std_logic_vector((1 - 1) downto 0);
    sel : out std_logic_vector((1 - 1) downto 0);
    push : out std_logic_vector((1 - 1) downto 0);
    pop : out std_logic_vector((1 - 1) downto 0);
    framestart : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_96bf53b8c9;
architecture behavior of sysgen_mcode_block_96bf53b8c9
is
  signal num_2_23: unsigned((7 - 1) downto 0);
  signal frameen_2_28: boolean;
  signal statei_5_20_next: unsigned((2 - 1) downto 0);
  signal statei_5_20: unsigned((2 - 1) downto 0) := "00";
  signal bitcounti_6_23_next: unsigned((8 - 1) downto 0);
  signal bitcounti_6_23: unsigned((8 - 1) downto 0) := "00000000";
  signal starti_7_20_next: boolean;
  signal starti_7_20: boolean := false;
  signal starti_7_20_rst: std_logic;
  signal subcarcounti_8_26_next: unsigned((8 - 1) downto 0);
  signal subcarcounti_8_26: unsigned((8 - 1) downto 0) := "00000000";
  signal subcari_9_21_next: unsigned((8 - 1) downto 0);
  signal subcari_9_21: unsigned((8 - 1) downto 0) := "00000000";
  signal loopcounti_10_24_next: unsigned((8 - 1) downto 0);
  signal loopcounti_10_24: unsigned((8 - 1) downto 0) := "00000000";
  signal framestart_join_12_1: boolean;
  signal pop_join_12_1: boolean;
  signal sel_join_12_1: unsigned((1 - 1) downto 0);
  signal push_join_12_1: boolean;
  signal rel_64_4: boolean;
  signal conpush_join_64_1: unsigned((1 - 1) downto 0);
  signal cast_69_14: unsigned((9 - 1) downto 0);
  signal loopcounti_69_1_addsub: unsigned((9 - 1) downto 0);
  signal rel_70_4: boolean;
  signal loopcounti_join_70_1: unsigned((9 - 1) downto 0);
  signal framestart_join_77_5: boolean;
  signal cast_81_20: unsigned((9 - 1) downto 0);
  signal subcarcounti_81_5_addsub: unsigned((9 - 1) downto 0);
  signal cast_83_15: unsigned((9 - 1) downto 0);
  signal subcari_83_5_addsub: unsigned((9 - 1) downto 0);
  signal rel_82_8: boolean;
  signal subcari_join_82_5: unsigned((9 - 1) downto 0);
  signal subcarcounti_join_82_5: unsigned((9 - 1) downto 0);
  signal rel_86_8: boolean;
  signal subcari_join_86_5: unsigned((9 - 1) downto 0);
  signal cast_97_15: unsigned((9 - 1) downto 0);
  signal bitcounti_97_5_addsub: unsigned((9 - 1) downto 0);
  signal rel_90_8: boolean;
  signal rel_90_29: boolean;
  signal rel_90_50: boolean;
  signal rel_91_8: boolean;
  signal rel_91_29: boolean;
  signal rel_91_50: boolean;
  signal rel_92_8: boolean;
  signal rel_92_29: boolean;
  signal rel_92_50: boolean;
  signal rel_93_8: boolean;
  signal rel_93_29: boolean;
  signal rel_93_50: boolean;
  signal rel_94_8: boolean;
  signal rel_94_29: boolean;
  signal rel_94_50: boolean;
  signal rel_95_8: boolean;
  signal bool_90_8: boolean;
  signal conpop_join_90_5: unsigned((1 - 1) downto 0);
  signal bitcounti_join_90_5: unsigned((9 - 1) downto 0);
  signal rel_75_6: boolean;
  signal rel_75_31: boolean;
  signal bool_75_48: boolean;
  signal bool_75_6: boolean;
  signal rel_75_72: boolean;
  signal rel_75_87: boolean;
  signal bool_75_72: boolean;
  signal bool_75_6_x_000000: boolean;
  signal conpop_join_75_1: unsigned((1 - 1) downto 0);
  signal framestart_join_75_1: boolean;
  signal subcari_join_75_1: unsigned((9 - 1) downto 0);
  signal starti_join_75_1: boolean;
  signal subcarcounti_join_75_1: unsigned((9 - 1) downto 0);
  signal bitcounti_join_75_1: unsigned((9 - 1) downto 0);
  signal rel_102_4: boolean;
  signal starti_join_102_1: boolean;
  signal starti_join_102_1_rst: std_logic;
  signal bitcounti_join_102_1: unsigned((9 - 1) downto 0);
  signal rel_108_8: boolean;
  signal statei_join_108_5: unsigned((2 - 1) downto 0);
  signal rel_114_8: boolean;
  signal statei_join_114_5: unsigned((2 - 1) downto 0);
  signal rel_107_4: boolean;
  signal statei_join_107_1: unsigned((2 - 1) downto 0);
  signal cast_loopcounto_122_1_convert: unsigned((8 - 1) downto 0);
  signal cast_subcaro_123_1_convert: unsigned((8 - 1) downto 0);
  signal cast_subcarcounto_124_1_convert: unsigned((8 - 1) downto 0);
  signal cast_bitcounto_126_1_convert: unsigned((8 - 1) downto 0);
  signal cast_bitcounti_6_23_next: unsigned((8 - 1) downto 0);
  signal cast_subcarcounti_8_26_next: unsigned((8 - 1) downto 0);
  signal cast_subcari_9_21_next: unsigned((8 - 1) downto 0);
  signal cast_loopcounti_10_24_next: unsigned((8 - 1) downto 0);
begin
  num_2_23 <= std_logic_vector_to_unsigned(num);
  frameen_2_28 <= ((frameen) = "1");
  proc_statei_5_20: process (clk)
  is
  begin
    if (clk'event and (clk = '1')) then
      if (ce = '1') then
        statei_5_20 <= statei_5_20_next;
      end if;
    end if;
  end process proc_statei_5_20;
  proc_bitcounti_6_23: process (clk)
  is
  begin
    if (clk'event and (clk = '1')) then
      if (ce = '1') then
        bitcounti_6_23 <= bitcounti_6_23_next;
      end if;
    end if;
  end process proc_bitcounti_6_23;
  proc_starti_7_20: process (clk)
  is
  begin
    if (clk'event and (clk = '1')) then
      if ((ce = '1') and (starti_7_20_rst = '1')) then
        starti_7_20 <= false;
      elsif (ce = '1') then 
        starti_7_20 <= starti_7_20_next;
      end if;
    end if;
  end process proc_starti_7_20;
  proc_subcarcounti_8_26: process (clk)
  is
  begin
    if (clk'event and (clk = '1')) then
      if (ce = '1') then
        subcarcounti_8_26 <= subcarcounti_8_26_next;
      end if;
    end if;
  end process proc_subcarcounti_8_26;
  proc_subcari_9_21: process (clk)
  is
  begin
    if (clk'event and (clk = '1')) then
      if (ce = '1') then
        subcari_9_21 <= subcari_9_21_next;
      end if;
    end if;
  end process proc_subcari_9_21;
  proc_loopcounti_10_24: process (clk)
  is
  begin
    if (clk'event and (clk = '1')) then
      if (ce = '1') then
        loopcounti_10_24 <= loopcounti_10_24_next;
      end if;
    end if;
  end process proc_loopcounti_10_24;
  proc_switch_12_1: process (statei_5_20)
  is
  begin
    case statei_5_20 is 
      when "00" =>
        framestart_join_12_1 <= false;
        pop_join_12_1 <= false;
        sel_join_12_1 <= std_logic_vector_to_unsigned("0");
        push_join_12_1 <= false;
      when "01" =>
        framestart_join_12_1 <= false;
        pop_join_12_1 <= true;
        sel_join_12_1 <= std_logic_vector_to_unsigned("1");
        push_join_12_1 <= false;
      when "10" =>
        framestart_join_12_1 <= false;
        pop_join_12_1 <= false;
        sel_join_12_1 <= std_logic_vector_to_unsigned("0");
        push_join_12_1 <= true;
      when "11" =>
        framestart_join_12_1 <= false;
        pop_join_12_1 <= true;
        sel_join_12_1 <= std_logic_vector_to_unsigned("1");
        push_join_12_1 <= true;
      when others =>
        framestart_join_12_1 <= false;
        pop_join_12_1 <= false;
        sel_join_12_1 <= std_logic_vector_to_unsigned("0");
        push_join_12_1 <= false;
    end case;
  end process proc_switch_12_1;
  rel_64_4 <= loopcounti_10_24 = std_logic_vector_to_unsigned("00000001");
  proc_if_64_1: process (rel_64_4)
  is
  begin
    if rel_64_4 then
      conpush_join_64_1 <= std_logic_vector_to_unsigned("1");
    else 
      conpush_join_64_1 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_64_1;
  cast_69_14 <= u2u_cast(loopcounti_10_24, 0, 9, 0);
  loopcounti_69_1_addsub <= cast_69_14 + std_logic_vector_to_unsigned("000000001");
  rel_70_4 <= loopcounti_69_1_addsub >= std_logic_vector_to_unsigned("000000101");
  proc_if_70_1: process (loopcounti_69_1_addsub, rel_70_4)
  is
  begin
    if rel_70_4 then
      loopcounti_join_70_1 <= std_logic_vector_to_unsigned("000000000");
    else 
      loopcounti_join_70_1 <= loopcounti_69_1_addsub;
    end if;
  end process proc_if_70_1;
  proc_if_77_5: process (frameen_2_28, framestart_join_12_1)
  is
  begin
    if frameen_2_28 then
      framestart_join_77_5 <= true;
    else 
      framestart_join_77_5 <= framestart_join_12_1;
    end if;
  end process proc_if_77_5;
  cast_81_20 <= u2u_cast(subcarcounti_8_26, 0, 9, 0);
  subcarcounti_81_5_addsub <= cast_81_20 + std_logic_vector_to_unsigned("000000001");
  cast_83_15 <= u2u_cast(subcari_9_21, 0, 9, 0);
  subcari_83_5_addsub <= cast_83_15 + std_logic_vector_to_unsigned("000000001");
  rel_82_8 <= subcarcounti_81_5_addsub >= std_logic_vector_to_unsigned("000000100");
  proc_if_82_5: process (rel_82_8, subcarcounti_81_5_addsub, subcari_83_5_addsub, subcari_9_21)
  is
  begin
    if rel_82_8 then
      subcari_join_82_5 <= subcari_83_5_addsub;
      subcarcounti_join_82_5 <= std_logic_vector_to_unsigned("000000000");
    else 
      subcari_join_82_5 <= u2u_cast(subcari_9_21, 0, 9, 0);
      subcarcounti_join_82_5 <= subcarcounti_81_5_addsub;
    end if;
  end process proc_if_82_5;
  rel_86_8 <= subcari_join_82_5 > std_logic_vector_to_unsigned("000010000");
  proc_if_86_5: process (rel_86_8, subcari_join_82_5)
  is
  begin
    if rel_86_8 then
      subcari_join_86_5 <= std_logic_vector_to_unsigned("000000000");
    else 
      subcari_join_86_5 <= subcari_join_82_5;
    end if;
  end process proc_if_86_5;
  cast_97_15 <= u2u_cast(bitcounti_6_23, 0, 9, 0);
  bitcounti_97_5_addsub <= cast_97_15 + std_logic_vector_to_unsigned("000000001");
  rel_90_8 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000001");
  rel_90_29 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_90_50 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_91_8 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_91_29 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_91_50 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_92_8 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_92_29 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_92_50 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000001001");
  rel_93_8 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_93_29 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_93_50 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_94_8 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_94_29 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_94_50 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  rel_95_8 <= subcari_join_86_5 /= std_logic_vector_to_unsigned("000000000");
  bool_90_8 <= rel_90_8 and rel_90_29 and rel_90_50 and rel_91_8 and rel_91_29 and rel_91_50 and rel_92_8 and rel_92_29 and rel_92_50 and rel_93_8 and rel_93_29 and rel_93_50 and rel_94_8 and rel_94_29 and rel_94_50 and rel_95_8;
  proc_if_90_5: process (bitcounti_6_23, bitcounti_97_5_addsub, bool_90_8)
  is
  begin
    if bool_90_8 then
      conpop_join_90_5 <= std_logic_vector_to_unsigned("1");
      bitcounti_join_90_5 <= bitcounti_97_5_addsub;
    else 
      conpop_join_90_5 <= std_logic_vector_to_unsigned("0");
      bitcounti_join_90_5 <= u2u_cast(bitcounti_6_23, 0, 9, 0);
    end if;
  end process proc_if_90_5;
  rel_75_6 <= num_2_23 >= std_logic_vector_to_unsigned("0111000");
  rel_75_31 <= bitcounti_6_23 = std_logic_vector_to_unsigned("00000000");
  bool_75_48 <= frameen_2_28 or starti_7_20;
  bool_75_6 <= rel_75_6 and rel_75_31 and bool_75_48;
  rel_75_72 <= bitcounti_6_23 > std_logic_vector_to_unsigned("00000000");
  rel_75_87 <= bitcounti_6_23 <= std_logic_vector_to_unsigned("00111000");
  bool_75_72 <= rel_75_72 and rel_75_87;
  bool_75_6_x_000000 <= bool_75_6 or bool_75_72;
  proc_if_75_1: process (bitcounti_6_23, bitcounti_join_90_5, bool_75_6_x_000000, conpop_join_90_5, framestart_join_12_1, framestart_join_77_5, starti_7_20, subcarcounti_8_26, subcarcounti_join_82_5, subcari_9_21, subcari_join_86_5)
  is
  begin
    if bool_75_6_x_000000 then
      conpop_join_75_1 <= conpop_join_90_5;
      framestart_join_75_1 <= framestart_join_77_5;
      subcari_join_75_1 <= subcari_join_86_5;
      starti_join_75_1 <= true;
      subcarcounti_join_75_1 <= subcarcounti_join_82_5;
      bitcounti_join_75_1 <= bitcounti_join_90_5;
    else 
      conpop_join_75_1 <= std_logic_vector_to_unsigned("0");
      framestart_join_75_1 <= framestart_join_12_1;
      subcari_join_75_1 <= u2u_cast(subcari_9_21, 0, 9, 0);
      starti_join_75_1 <= starti_7_20;
      subcarcounti_join_75_1 <= u2u_cast(subcarcounti_8_26, 0, 9, 0);
      bitcounti_join_75_1 <= u2u_cast(bitcounti_6_23, 0, 9, 0);
    end if;
  end process proc_if_75_1;
  rel_102_4 <= bitcounti_join_75_1 >= std_logic_vector_to_unsigned("000111000");
  proc_if_102_1: process (bitcounti_join_75_1, rel_102_4, starti_join_75_1)
  is
  begin
    if rel_102_4 then
      starti_join_102_1_rst <= '1';
    else 
      starti_join_102_1_rst <= '0';
    end if;
    starti_join_102_1 <= starti_join_75_1;
    if rel_102_4 then
      bitcounti_join_102_1 <= std_logic_vector_to_unsigned("000000000");
    else 
      bitcounti_join_102_1 <= bitcounti_join_75_1;
    end if;
  end process proc_if_102_1;
  rel_108_8 <= conpush_join_64_1 = std_logic_vector_to_unsigned("1");
  proc_if_108_5: process (rel_108_8)
  is
  begin
    if rel_108_8 then
      statei_join_108_5 <= std_logic_vector_to_unsigned("11");
    else 
      statei_join_108_5 <= std_logic_vector_to_unsigned("01");
    end if;
  end process proc_if_108_5;
  rel_114_8 <= conpush_join_64_1 = std_logic_vector_to_unsigned("1");
  proc_if_114_5: process (rel_114_8)
  is
  begin
    if rel_114_8 then
      statei_join_114_5 <= std_logic_vector_to_unsigned("10");
    else 
      statei_join_114_5 <= std_logic_vector_to_unsigned("00");
    end if;
  end process proc_if_114_5;
  rel_107_4 <= conpop_join_75_1 = std_logic_vector_to_unsigned("1");
  proc_if_107_1: process (rel_107_4, statei_join_108_5, statei_join_114_5)
  is
  begin
    if rel_107_4 then
      statei_join_107_1 <= statei_join_108_5;
    else 
      statei_join_107_1 <= statei_join_114_5;
    end if;
  end process proc_if_107_1;
  cast_loopcounto_122_1_convert <= u2u_cast(loopcounti_join_70_1, 0, 8, 0);
  cast_subcaro_123_1_convert <= u2u_cast(subcari_join_75_1, 0, 8, 0);
  cast_subcarcounto_124_1_convert <= u2u_cast(subcarcounti_join_75_1, 0, 8, 0);
  cast_bitcounto_126_1_convert <= u2u_cast(bitcounti_join_102_1, 0, 8, 0);
  statei_5_20_next <= statei_join_107_1;
  cast_bitcounti_6_23_next <= u2u_cast(bitcounti_join_102_1, 0, 8, 0);
  bitcounti_6_23_next <= cast_bitcounti_6_23_next;
  starti_7_20_next <= starti_join_75_1;
  starti_7_20_rst <= starti_join_102_1_rst;
  cast_subcarcounti_8_26_next <= u2u_cast(subcarcounti_join_75_1, 0, 8, 0);
  subcarcounti_8_26_next <= cast_subcarcounti_8_26_next;
  cast_subcari_9_21_next <= u2u_cast(subcari_join_75_1, 0, 8, 0);
  subcari_9_21_next <= cast_subcari_9_21_next;
  cast_loopcounti_10_24_next <= u2u_cast(loopcounti_join_70_1, 0, 8, 0);
  loopcounti_10_24_next <= cast_loopcounti_10_24_next;
  sel <= unsigned_to_std_logic_vector(sel_join_12_1);
  push <= boolean_to_vector(push_join_12_1);
  pop <= boolean_to_vector(pop_join_12_1);
  framestart <= boolean_to_vector(framestart_join_75_1);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mux_31e440a591 is
  port (
    sel : in std_logic_vector((1 - 1) downto 0);
    d0 : in std_logic_vector((1 - 1) downto 0);
    d1 : in std_logic_vector((1 - 1) downto 0);
    y : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mux_31e440a591;
architecture behavior of sysgen_mux_31e440a591
is
  signal sel_1_20: std_logic_vector((1 - 1) downto 0);
  signal d0_1_24: std_logic_vector((1 - 1) downto 0);
  signal d1_1_27: std_logic_vector((1 - 1) downto 0);
  type array_type_pipe_16_22 is array (0 to (1 - 1)) of std_logic_vector((1 - 1) downto 0);
  signal pipe_16_22: array_type_pipe_16_22 := (
    0 => "0");
  signal pipe_16_22_front_din: std_logic_vector((1 - 1) downto 0);
  signal pipe_16_22_back: std_logic_vector((1 - 1) downto 0);
  signal pipe_16_22_push_front_pop_back_en: std_logic;
  signal unregy_join_6_1: std_logic_vector((1 - 1) downto 0);
begin
  sel_1_20 <= sel;
  d0_1_24 <= d0;
  d1_1_27 <= d1;
  pipe_16_22_back <= pipe_16_22(0);
  proc_pipe_16_22: process (clk)
  is
    variable i: integer;
  begin
    if (clk'event and (clk = '1')) then
      if ((ce = '1') and (pipe_16_22_push_front_pop_back_en = '1')) then
        pipe_16_22(0) <= pipe_16_22_front_din;
      end if;
    end if;
  end process proc_pipe_16_22;
  proc_switch_6_1: process (d0_1_24, d1_1_27, sel_1_20)
  is
  begin
    case sel_1_20 is 
      when "0" =>
        unregy_join_6_1 <= d0_1_24;
      when others =>
        unregy_join_6_1 <= d1_1_27;
    end case;
  end process proc_switch_6_1;
  pipe_16_22_front_din <= unregy_join_6_1;
  pipe_16_22_push_front_pop_back_en <= '1';
  y <= pipe_16_22_back;
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


----------------------------------------------------------------------------
--
--  Filename      : xls2p.vhd
--
--  Created       : 5/22/2001
--
--  Description   : Synthesizable vhdl for a serial to parallel conversion
--                  block.
--
--  Mod. History  : Modified VHDL to work with the new clock enable scheme.
--                  Removed the shutter to properly align output data.
--                  Changed the capture register input arrangment, and set the
--                  capture register latency to 1.  Registered the clock enable
--                  signal to produce a "reset" signal for the valid bit.
--                : Added rst/en support
--
--
----------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


-- synthesis translate_off
library unisim;
use unisim.vcomponents.all;
-- synthesis translate_on

entity basic_dmt_xls2p is

    generic (dout_width  : integer := 8;          -- output width
             dout_arith  : integer := xlSigned;   -- output arithmetic type
             dout_bin_pt : integer := 0;          -- output binary point
             din_width   : integer := 1;          -- input width
             din_arith   : integer := xlUnsigned; -- input arith type
             din_bin_pt  : integer := 0;          -- input binary point
             rst_width   : integer := 1;          -- width of input rst
             rst_bin_pt  : integer := 0;          -- binary point of input rst
             rst_arith   : integer := xlUnsigned; -- type of arith of input rst
             en_width    : integer := 1;          -- width of input en
             en_bin_pt   : integer := 0;          -- binary poitn of input en
             en_arith    : integer := xlUnsigned; -- type of arith of input en
             lsb_first   : integer := 0;          -- is least sig bit first
             latency     : integer := 0;          -- latency of the block from mask
             num_inputs  : integer := 0);         -- number of inputs needed for output

    port (din        : in std_logic_vector (din_width-1 downto 0);
          src_ce     : in std_logic;     -- source clock (fast)
          src_clr    : in std_logic;
          src_clk    : in std_logic;
          dest_ce    : in std_logic;     -- output clock (slow)
          dest_clr   : in std_logic;
          dest_clk   : in std_logic;
          rst        : in std_logic_vector (rst_width-1 downto 0);
          en         : in std_logic_vector (en_width-1 downto 0);
          dout       : out std_logic_vector (dout_width-1 downto 0));

end basic_dmt_xls2p;

architecture synth_behavioral of basic_dmt_xls2p is

    component synth_reg_w_init
        generic (width      : integer;
                 init_index : integer;
                 latency    : integer);
        port (i   : in std_logic_vector(width-1 downto 0);
              ce  : in std_logic;
              clr : in std_logic;
              clk : in std_logic;
              o   : out std_logic_vector(width-1 downto 0));
    end component; -- end synth_reg_w_init

    component synth_reg
        generic (width   : integer;
                 latency : integer);
        port (i   : in std_logic_vector(width-1 downto 0);
              ce  : in std_logic;
              clr : in std_logic;
              clk : in std_logic;
              o   : out std_logic_vector(width-1 downto 0));
    end component;

    component FDSE
        port(q  : out STD_ULOGIC;
             d  : in  STD_ULOGIC;
             c  : in  STD_ULOGIC;
             ce : in  STD_ULOGIC;
             s  : in  STD_ULOGIC);
    end component; -- end FDSE

    attribute syn_black_box of FDSE : component is true;
    attribute fpga_dont_touch of FDSE : component is "true";

    type temp_array is array (0 to num_inputs-1) of std_logic_vector(din_width-1 downto 0);

    signal i : temp_array;          -- input to comp registers
    signal o : temp_array;          -- output from comp register
    signal capture_in : temp_array; -- input to capture register

    signal del_dest_ce : std_logic;

    -- output from capture register
    signal dout_temp : std_logic_vector(dout_width-1 downto 0);

    signal internal_src_ce  : std_logic;
    signal internal_dest_ce : std_logic;
    signal internal_clr     : std_logic;
    signal internal_select : std_logic;


begin

    internal_src_ce   <= src_ce and (en(0));
    internal_dest_ce  <= dest_ce and (en(0));
    internal_clr      <= ((dest_clr or src_clr ) and dest_ce)  or rst(0);
	--internal_clr      <= (dest_clr or src_clr or rst(0)) and dest_ce;

    -- Implement the clock enable circuit

    -- The comp register acts a shift register and positions the input bits
    -- into a parallel word.  The capture register freezes the parallel
    -- sample for the 1 cycle that all the needed bits are in place.

    lsb_is_first: if(lsb_first = 1) generate
       fd_array: for index in num_inputs - 1 downto 0 generate

          comp : synth_reg
             generic map (width      => din_width,
                          latency    => 1)
             port map (i   => i(index),
                       ce  => internal_src_ce,
                       clr => internal_clr,
                       clk => src_clk,
                       o   => o(index));

          capture : synth_reg_w_init
             generic map (width      => din_width,
                          init_index => 0,
                          latency    => 1)
             port map (i   => capture_in(index),
                       ce  => internal_dest_ce,
                       clr => internal_clr,
                       clk => dest_clk,
                       o   => dout_temp(dout_width-1-index*din_width downto dout_width-index*din_width-din_width));

          -- generate the comp register and capture register inputs
          signal_0: if (index = 0) generate
                       i(index) <= din;
                       capture_in(index) <= din;
          end generate; -- end signal_0

          signal_gt_0: if (index > 0) generate
                        i(index) <= o(index - 1);
                        capture_in(index) <= o(index - 1);
          end generate; -- end signal_gt_0

       end generate; -- end fd_array
    end generate; -- end lst_is_first

    msb_is_first: if(lsb_first = 0) generate
       fd_array1: for index in num_inputs-1 downto 0 generate

          comp : synth_reg
             generic map (width      => din_width,
                          latency    => 1)
             port map (i   => i(index),
                       ce  => internal_src_ce,
                       clr => internal_clr,
                       clk => src_clk,
                       o   => o(index));

          capture : synth_reg_w_init
             generic map (width      => din_width,
                          init_index => 0,
                          latency    => 1)
             port map (i   => capture_in(index),
                       ce  => internal_dest_ce,
                       clr => internal_clr,
                       clk => dest_clk,
                       o   => dout_temp(index*din_width + din_width-1 downto index*din_width));

           signal_01: if (index = 0) generate
                         i(index) <= din;
                         capture_in(index) <= din;
           end generate; -- end signal_01

           signal_gt_01: if (index > 0) generate
                         i(index) <= o(index - 1);
                         capture_in(index) <= o(index - 1);
           end generate;  -- end signal_gt_01

       end generate; -- end fd_array1
    end generate; -- end msb is first

    -- register the destination clock enable
    -- this signal will be used to "reset" the valid signal for every
    -- new word

    -- dest_ce_reg : FDSE port map (c  => src_clk,
    --                             d  => dest_ce,
    --                             q  => del_dest_ce,
    --                             ce => internal_src_ce,
    --                             s  => internal_clr);

    -- add additional latency where necessary

    latency_gt_0 : if (latency > 1)
    generate
       data_reg : synth_reg
          generic map (width   => dout_width,
                       latency => latency-1)
          port map (i   => dout_temp,
                    ce  => internal_dest_ce,
                    clr => internal_clr,
                    clk => dest_clk,
                    o   => dout);
    end generate; -- end latency_gt_0

    latency0 : if (latency <= 1 )
    generate
        dout <= dout_temp;
    end generate; -- end latency0

end architecture synth_behavioral;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_c1f15f41da is
  port (
    num : in std_logic_vector((7 - 1) downto 0);
    frameen : in std_logic_vector((1 - 1) downto 0);
    statei : in std_logic_vector((2 - 1) downto 0);
    loopcounti : in std_logic_vector((8 - 1) downto 0);
    loopouti : in std_logic_vector((8 - 1) downto 0);
    starti : in std_logic_vector((1 - 1) downto 0);
    outputbitcounti : in std_logic_vector((8 - 1) downto 0);
    sel : out std_logic_vector((1 - 1) downto 0);
    push : out std_logic_vector((1 - 1) downto 0);
    pop : out std_logic_vector((1 - 1) downto 0);
    framestart : out std_logic_vector((1 - 1) downto 0);
    stateo : out std_logic_vector((2 - 1) downto 0);
    loopcounto : out std_logic_vector((8 - 1) downto 0);
    loopouto : out std_logic_vector((8 - 1) downto 0);
    starto : out std_logic_vector((1 - 1) downto 0);
    outputbitcounto : out std_logic_vector((8 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_c1f15f41da;
architecture behavior of sysgen_mcode_block_c1f15f41da
is
  signal num_2_21: unsigned((7 - 1) downto 0);
  signal frameen_2_26: boolean;
  signal statei_2_35: unsigned((2 - 1) downto 0);
  signal loopcounti_2_43: unsigned((8 - 1) downto 0);
  signal loopouti_2_55: unsigned((8 - 1) downto 0);
  signal starti_2_65: boolean;
  signal outputbitcounti_2_73: unsigned((8 - 1) downto 0);
  signal pop_join_7_1: boolean;
  signal push_join_7_1: boolean;
  signal sel_join_7_1: unsigned((1 - 1) downto 0);
  signal framestart_join_7_1: boolean;
  signal rel_40_4: boolean;
  signal conpush_join_40_1: unsigned((1 - 1) downto 0);
  signal cast_45_14: unsigned((9 - 1) downto 0);
  signal loopcounti_45_1_addsub: unsigned((9 - 1) downto 0);
  signal rel_46_4: boolean;
  signal loopcounti_join_46_1: unsigned((9 - 1) downto 0);
  signal rel_53_19: boolean;
  signal bool_53_8: boolean;
  signal loopouti_join_53_5: unsigned((8 - 1) downto 0);
  signal framestart_join_53_5: boolean;
  signal cast_59_21: unsigned((9 - 1) downto 0);
  signal outputbitcounti_59_5_addsub: unsigned((9 - 1) downto 0);
  signal rel_51_6: boolean;
  signal rel_51_41: boolean;
  signal rel_51_64: boolean;
  signal rel_51_82: boolean;
  signal bool_51_64: boolean;
  signal bool_51_6: boolean;
  signal rel_51_102: boolean;
  signal rel_51_123: boolean;
  signal rel_51_169: boolean;
  signal bool_51_102: boolean;
  signal bool_51_6_x_000000: boolean;
  signal conpop_join_51_1: unsigned((1 - 1) downto 0);
  signal loopouti_join_51_1: unsigned((8 - 1) downto 0);
  signal starti_join_51_1: boolean;
  signal framestart_join_51_1: boolean;
  signal outputbitcounti_join_51_1: unsigned((9 - 1) downto 0);
  signal cast_64_12: unsigned((9 - 1) downto 0);
  signal loopouti_64_1_addsub: unsigned((9 - 1) downto 0);
  signal rel_65_4: boolean;
  signal loopouti_join_65_1: unsigned((9 - 1) downto 0);
  signal rel_69_4: boolean;
  signal starti_join_69_1: boolean;
  signal outputbitcounti_join_69_1: unsigned((9 - 1) downto 0);
  signal rel_75_8: boolean;
  signal statei_join_75_5: unsigned((2 - 1) downto 0);
  signal rel_81_8: boolean;
  signal statei_join_81_5: unsigned((2 - 1) downto 0);
  signal rel_74_4: boolean;
  signal statei_join_74_1: unsigned((2 - 1) downto 0);
  signal cast_loopcounto_89_1_convert: unsigned((8 - 1) downto 0);
  signal cast_loopouto_91_1_convert: unsigned((8 - 1) downto 0);
  signal cast_outputbitcounto_92_1_convert: unsigned((8 - 1) downto 0);
begin
  num_2_21 <= std_logic_vector_to_unsigned(num);
  frameen_2_26 <= ((frameen) = "1");
  statei_2_35 <= std_logic_vector_to_unsigned(statei);
  loopcounti_2_43 <= std_logic_vector_to_unsigned(loopcounti);
  loopouti_2_55 <= std_logic_vector_to_unsigned(loopouti);
  starti_2_65 <= ((starti) = "1");
  outputbitcounti_2_73 <= std_logic_vector_to_unsigned(outputbitcounti);
  proc_switch_7_1: process (statei_2_35)
  is
  begin
    case statei_2_35 is 
      when "00" =>
        pop_join_7_1 <= false;
        push_join_7_1 <= false;
        sel_join_7_1 <= std_logic_vector_to_unsigned("0");
        framestart_join_7_1 <= false;
      when "01" =>
        pop_join_7_1 <= true;
        push_join_7_1 <= false;
        sel_join_7_1 <= std_logic_vector_to_unsigned("1");
        framestart_join_7_1 <= false;
      when "10" =>
        pop_join_7_1 <= false;
        push_join_7_1 <= true;
        sel_join_7_1 <= std_logic_vector_to_unsigned("0");
        framestart_join_7_1 <= false;
      when "11" =>
        pop_join_7_1 <= true;
        push_join_7_1 <= true;
        sel_join_7_1 <= std_logic_vector_to_unsigned("1");
        framestart_join_7_1 <= false;
      when others =>
        pop_join_7_1 <= false;
        push_join_7_1 <= false;
        sel_join_7_1 <= std_logic_vector_to_unsigned("0");
        framestart_join_7_1 <= false;
    end case;
  end process proc_switch_7_1;
  rel_40_4 <= loopcounti_2_43 = std_logic_vector_to_unsigned("00000001");
  proc_if_40_1: process (rel_40_4)
  is
  begin
    if rel_40_4 then
      conpush_join_40_1 <= std_logic_vector_to_unsigned("1");
    else 
      conpush_join_40_1 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_40_1;
  cast_45_14 <= u2u_cast(loopcounti_2_43, 0, 9, 0);
  loopcounti_45_1_addsub <= cast_45_14 + std_logic_vector_to_unsigned("000000001");
  rel_46_4 <= loopcounti_45_1_addsub >= std_logic_vector_to_unsigned("000001110");
  proc_if_46_1: process (loopcounti_45_1_addsub, rel_46_4)
  is
  begin
    if rel_46_4 then
      loopcounti_join_46_1 <= std_logic_vector_to_unsigned("000000000");
    else 
      loopcounti_join_46_1 <= loopcounti_45_1_addsub;
    end if;
  end process proc_if_46_1;
  rel_53_19 <= outputbitcounti_2_73 = std_logic_vector_to_unsigned("00000000");
  bool_53_8 <= frameen_2_26 and rel_53_19;
  proc_if_53_5: process (bool_53_8, framestart_join_7_1, loopouti_2_55)
  is
  begin
    if bool_53_8 then
      loopouti_join_53_5 <= std_logic_vector_to_unsigned("00000000");
      framestart_join_53_5 <= true;
    else 
      loopouti_join_53_5 <= loopouti_2_55;
      framestart_join_53_5 <= framestart_join_7_1;
    end if;
  end process proc_if_53_5;
  cast_59_21 <= u2u_cast(outputbitcounti_2_73, 0, 9, 0);
  outputbitcounti_59_5_addsub <= cast_59_21 + std_logic_vector_to_unsigned("000000001");
  rel_51_6 <= num_2_21 >= std_logic_vector_to_unsigned("0010100");
  rel_51_41 <= outputbitcounti_2_73 = std_logic_vector_to_unsigned("00000000");
  rel_51_64 <= frameen_2_26 = true;
  rel_51_82 <= starti_2_65 = true;
  bool_51_64 <= rel_51_64 or rel_51_82;
  bool_51_6 <= rel_51_6 and rel_51_41 and bool_51_64;
  rel_51_102 <= outputbitcounti_2_73 > std_logic_vector_to_unsigned("00000000");
  rel_51_123 <= outputbitcounti_2_73 <= std_logic_vector_to_unsigned("00010100");
  rel_51_169 <= loopouti_2_55 = std_logic_vector_to_unsigned("00000000");
  bool_51_102 <= rel_51_102 and rel_51_123 and rel_51_169;
  bool_51_6_x_000000 <= bool_51_6 or bool_51_102;
  proc_if_51_1: process (bool_51_6_x_000000, framestart_join_53_5, framestart_join_7_1, loopouti_2_55, loopouti_join_53_5, outputbitcounti_2_73, outputbitcounti_59_5_addsub, starti_2_65)
  is
  begin
    if bool_51_6_x_000000 then
      conpop_join_51_1 <= std_logic_vector_to_unsigned("1");
      loopouti_join_51_1 <= loopouti_join_53_5;
      starti_join_51_1 <= true;
      framestart_join_51_1 <= framestart_join_53_5;
      outputbitcounti_join_51_1 <= outputbitcounti_59_5_addsub;
    else 
      conpop_join_51_1 <= std_logic_vector_to_unsigned("0");
      loopouti_join_51_1 <= loopouti_2_55;
      starti_join_51_1 <= starti_2_65;
      framestart_join_51_1 <= framestart_join_7_1;
      outputbitcounti_join_51_1 <= u2u_cast(outputbitcounti_2_73, 0, 9, 0);
    end if;
  end process proc_if_51_1;
  cast_64_12 <= u2u_cast(loopouti_join_51_1, 0, 9, 0);
  loopouti_64_1_addsub <= cast_64_12 + std_logic_vector_to_unsigned("000000001");
  rel_65_4 <= loopouti_64_1_addsub >= std_logic_vector_to_unsigned("000000100");
  proc_if_65_1: process (loopouti_64_1_addsub, rel_65_4)
  is
  begin
    if rel_65_4 then
      loopouti_join_65_1 <= std_logic_vector_to_unsigned("000000000");
    else 
      loopouti_join_65_1 <= loopouti_64_1_addsub;
    end if;
  end process proc_if_65_1;
  rel_69_4 <= outputbitcounti_join_51_1 >= std_logic_vector_to_unsigned("000010100");
  proc_if_69_1: process (outputbitcounti_join_51_1, rel_69_4, starti_join_51_1)
  is
  begin
    if rel_69_4 then
      starti_join_69_1 <= false;
      outputbitcounti_join_69_1 <= std_logic_vector_to_unsigned("000000000");
    else 
      starti_join_69_1 <= starti_join_51_1;
      outputbitcounti_join_69_1 <= outputbitcounti_join_51_1;
    end if;
  end process proc_if_69_1;
  rel_75_8 <= conpush_join_40_1 = std_logic_vector_to_unsigned("1");
  proc_if_75_5: process (rel_75_8)
  is
  begin
    if rel_75_8 then
      statei_join_75_5 <= std_logic_vector_to_unsigned("11");
    else 
      statei_join_75_5 <= std_logic_vector_to_unsigned("01");
    end if;
  end process proc_if_75_5;
  rel_81_8 <= conpush_join_40_1 = std_logic_vector_to_unsigned("1");
  proc_if_81_5: process (rel_81_8)
  is
  begin
    if rel_81_8 then
      statei_join_81_5 <= std_logic_vector_to_unsigned("10");
    else 
      statei_join_81_5 <= std_logic_vector_to_unsigned("00");
    end if;
  end process proc_if_81_5;
  rel_74_4 <= conpop_join_51_1 = std_logic_vector_to_unsigned("1");
  proc_if_74_1: process (rel_74_4, statei_join_75_5, statei_join_81_5)
  is
  begin
    if rel_74_4 then
      statei_join_74_1 <= statei_join_75_5;
    else 
      statei_join_74_1 <= statei_join_81_5;
    end if;
  end process proc_if_74_1;
  cast_loopcounto_89_1_convert <= u2u_cast(loopcounti_join_46_1, 0, 8, 0);
  cast_loopouto_91_1_convert <= u2u_cast(loopouti_join_65_1, 0, 8, 0);
  cast_outputbitcounto_92_1_convert <= u2u_cast(outputbitcounti_join_69_1, 0, 8, 0);
  sel <= unsigned_to_std_logic_vector(sel_join_7_1);
  push <= boolean_to_vector(push_join_7_1);
  pop <= boolean_to_vector(pop_join_7_1);
  framestart <= boolean_to_vector(framestart_join_51_1);
  stateo <= unsigned_to_std_logic_vector(statei_join_74_1);
  loopcounto <= unsigned_to_std_logic_vector(cast_loopcounto_89_1_convert);
  loopouto <= unsigned_to_std_logic_vector(cast_loopouto_91_1_convert);
  starto <= boolean_to_vector(starti_join_69_1);
  outputbitcounto <= unsigned_to_std_logic_vector(cast_outputbitcounto_92_1_convert);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mux_427790cdf8 is
  port (
    sel : in std_logic_vector((1 - 1) downto 0);
    d0 : in std_logic_vector((1 - 1) downto 0);
    d1 : in std_logic_vector((21 - 1) downto 0);
    y : out std_logic_vector((21 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mux_427790cdf8;
architecture behavior of sysgen_mux_427790cdf8
is
  signal sel_1_20: std_logic_vector((1 - 1) downto 0);
  signal d0_1_24: std_logic_vector((1 - 1) downto 0);
  signal d1_1_27: std_logic_vector((21 - 1) downto 0);
  type array_type_pipe_16_22 is array (0 to (1 - 1)) of std_logic_vector((21 - 1) downto 0);
  signal pipe_16_22: array_type_pipe_16_22 := (
    0 => "000000000000000000000");
  signal pipe_16_22_front_din: std_logic_vector((21 - 1) downto 0);
  signal pipe_16_22_back: std_logic_vector((21 - 1) downto 0);
  signal pipe_16_22_push_front_pop_back_en: std_logic;
  signal unregy_join_6_1: std_logic_vector((21 - 1) downto 0);
begin
  sel_1_20 <= sel;
  d0_1_24 <= d0;
  d1_1_27 <= d1;
  pipe_16_22_back <= pipe_16_22(0);
  proc_pipe_16_22: process (clk)
  is
    variable i: integer;
  begin
    if (clk'event and (clk = '1')) then
      if ((ce = '1') and (pipe_16_22_push_front_pop_back_en = '1')) then
        pipe_16_22(0) <= pipe_16_22_front_din;
      end if;
    end if;
  end process proc_pipe_16_22;
  proc_switch_6_1: process (d0_1_24, d1_1_27, sel_1_20)
  is
  begin
    case sel_1_20 is 
      when "0" =>
        unregy_join_6_1 <= cast(d0_1_24, 0, 21, 13, xlUnsigned);
      when others =>
        unregy_join_6_1 <= d1_1_27;
    end case;
  end process proc_switch_6_1;
  pipe_16_22_front_din <= unregy_join_6_1;
  pipe_16_22_push_front_pop_back_en <= '1';
  y <= pipe_16_22_back;
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_shift_daec1eca69 is
  port (
    ip : in std_logic_vector((26 - 1) downto 0);
    op : out std_logic_vector((26 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_shift_daec1eca69;
architecture behavior of sysgen_shift_daec1eca69
is
  signal ip_1_23: signed((26 - 1) downto 0);
  type array_type_op_mem_46_20 is array (0 to (1 - 1)) of signed((26 - 1) downto 0);
  signal op_mem_46_20: array_type_op_mem_46_20 := (
    0 => "00000000000000000000000000");
  signal op_mem_46_20_front_din: signed((26 - 1) downto 0);
  signal op_mem_46_20_back: signed((26 - 1) downto 0);
  signal op_mem_46_20_push_front_pop_back_en: std_logic;
  signal cast_internal_ip_36_3_convert: signed((26 - 1) downto 0);
begin
  ip_1_23 <= std_logic_vector_to_signed(ip);
  op_mem_46_20_back <= op_mem_46_20(0);
  proc_op_mem_46_20: process (clk)
  is
    variable i: integer;
  begin
    if (clk'event and (clk = '1')) then
      if ((ce = '1') and (op_mem_46_20_push_front_pop_back_en = '1')) then
        op_mem_46_20(0) <= op_mem_46_20_front_din;
      end if;
    end if;
  end process proc_op_mem_46_20;
  cast_internal_ip_36_3_convert <= s2s_cast(ip_1_23, 24, 26, 20);
  op_mem_46_20_push_front_pop_back_en <= '0';
  op <= signed_to_std_logic_vector(cast_internal_ip_36_3_convert);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_34b14fac6d is
  port (
    inp_re : in std_logic_vector((21 - 1) downto 0);
    inp_im : in std_logic_vector((21 - 1) downto 0);
    frameen : in std_logic_vector((1 - 1) downto 0);
    statei : in std_logic_vector((2 - 1) downto 0);
    loopcounti : in std_logic_vector((8 - 1) downto 0);
    starti : in std_logic_vector((1 - 1) downto 0);
    out_re : out std_logic_vector((21 - 1) downto 0);
    out_im : out std_logic_vector((21 - 1) downto 0);
    pop : out std_logic_vector((1 - 1) downto 0);
    stateo : out std_logic_vector((2 - 1) downto 0);
    loopcounto : out std_logic_vector((8 - 1) downto 0);
    starto : out std_logic_vector((1 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_34b14fac6d;
architecture behavior of sysgen_mcode_block_34b14fac6d
is
  signal inp_re_2_24: signed((21 - 1) downto 0);
  signal inp_im_2_32: signed((21 - 1) downto 0);
  signal frameen_2_40: boolean;
  signal statei_2_49: unsigned((2 - 1) downto 0);
  signal loopcounti_2_57: unsigned((8 - 1) downto 0);
  signal starti_2_69: boolean;
  signal rel_11_4: boolean;
  signal loopcounti_join_11_1: unsigned((8 - 1) downto 0);
  signal starti_join_11_1: boolean;
  signal cast_16_14: unsigned((9 - 1) downto 0);
  signal loopcounti_16_1_addsub: unsigned((9 - 1) downto 0);
  signal rel_18_4: boolean;
  signal starti_join_18_1: boolean;
  signal rel_24_12: boolean;
  signal rel_24_38: boolean;
  signal bool_24_12: boolean;
  signal statei_join_24_9: unsigned((1 - 1) downto 0);
  signal rel_34_12: boolean;
  signal rel_34_38: boolean;
  signal bool_34_12: boolean;
  signal statei_join_34_9: unsigned((1 - 1) downto 0);
  signal statei_join_22_1: unsigned((2 - 1) downto 0);
  signal out_re_join_22_1: signed((21 - 1) downto 0);
  signal out_im_join_22_1: signed((21 - 1) downto 0);
  signal pop_join_22_1: boolean;
  signal cast_loopcounto_43_1_convert: unsigned((8 - 1) downto 0);
begin
  inp_re_2_24 <= std_logic_vector_to_signed(inp_re);
  inp_im_2_32 <= std_logic_vector_to_signed(inp_im);
  frameen_2_40 <= ((frameen) = "1");
  statei_2_49 <= std_logic_vector_to_unsigned(statei);
  loopcounti_2_57 <= std_logic_vector_to_unsigned(loopcounti);
  starti_2_69 <= ((starti) = "1");
  rel_11_4 <= frameen_2_40 = true;
  proc_if_11_1: process (loopcounti_2_57, rel_11_4, starti_2_69)
  is
  begin
    if rel_11_4 then
      loopcounti_join_11_1 <= std_logic_vector_to_unsigned("00000000");
      starti_join_11_1 <= true;
    else 
      loopcounti_join_11_1 <= loopcounti_2_57;
      starti_join_11_1 <= starti_2_69;
    end if;
  end process proc_if_11_1;
  cast_16_14 <= u2u_cast(loopcounti_join_11_1, 0, 9, 0);
  loopcounti_16_1_addsub <= cast_16_14 + std_logic_vector_to_unsigned("000000001");
  rel_18_4 <= loopcounti_16_1_addsub > std_logic_vector_to_unsigned("000010100");
  proc_if_18_1: process (rel_18_4, starti_join_11_1)
  is
  begin
    if rel_18_4 then
      starti_join_18_1 <= false;
    else 
      starti_join_18_1 <= starti_join_11_1;
    end if;
  end process proc_if_18_1;
  rel_24_12 <= loopcounti_16_1_addsub > std_logic_vector_to_unsigned("000000100");
  rel_24_38 <= starti_join_18_1 = true;
  bool_24_12 <= rel_24_12 and rel_24_38;
  proc_if_24_9: process (bool_24_12)
  is
  begin
    if bool_24_12 then
      statei_join_24_9 <= std_logic_vector_to_unsigned("1");
    else 
      statei_join_24_9 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_24_9;
  rel_34_12 <= loopcounti_16_1_addsub > std_logic_vector_to_unsigned("000000100");
  rel_34_38 <= starti_join_18_1 = true;
  bool_34_12 <= rel_34_12 and rel_34_38;
  proc_if_34_9: process (bool_34_12)
  is
  begin
    if bool_34_12 then
      statei_join_34_9 <= std_logic_vector_to_unsigned("1");
    else 
      statei_join_34_9 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_34_9;
  proc_switch_22_1: process (inp_im_2_32, inp_re_2_24, statei_2_49, statei_join_24_9, statei_join_34_9)
  is
  begin
    case statei_2_49 is 
      when "00" =>
        statei_join_22_1 <= u2u_cast(statei_join_24_9, 0, 2, 0);
        out_re_join_22_1 <= std_logic_vector_to_signed("000000000000000000000");
        out_im_join_22_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_22_1 <= false;
      when "01" =>
        statei_join_22_1 <= u2u_cast(statei_join_34_9, 0, 2, 0);
        out_re_join_22_1 <= inp_re_2_24;
        out_im_join_22_1 <= inp_im_2_32;
        pop_join_22_1 <= true;
      when others =>
        statei_join_22_1 <= statei_2_49;
        out_re_join_22_1 <= std_logic_vector_to_signed("000000000000000000000");
        out_im_join_22_1 <= std_logic_vector_to_signed("000000000000000000000");
        pop_join_22_1 <= false;
    end case;
  end process proc_switch_22_1;
  cast_loopcounto_43_1_convert <= u2u_cast(loopcounti_16_1_addsub, 0, 8, 0);
  out_re <= signed_to_std_logic_vector(out_re_join_22_1);
  out_im <= signed_to_std_logic_vector(out_im_join_22_1);
  pop <= boolean_to_vector(pop_join_22_1);
  stateo <= unsigned_to_std_logic_vector(statei_join_22_1);
  loopcounto <= unsigned_to_std_logic_vector(cast_loopcounto_43_1_convert);
  starto <= boolean_to_vector(starti_join_18_1);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mcode_block_7190f7090b is
  port (
    x_re : in std_logic_vector((416 - 1) downto 0);
    x_im : in std_logic_vector((416 - 1) downto 0);
    y1_re : out std_logic_vector((26 - 1) downto 0);
    y1_im : out std_logic_vector((26 - 1) downto 0);
    y2_re : out std_logic_vector((26 - 1) downto 0);
    y2_im : out std_logic_vector((26 - 1) downto 0);
    y3_re : out std_logic_vector((26 - 1) downto 0);
    y3_im : out std_logic_vector((26 - 1) downto 0);
    y4_re : out std_logic_vector((26 - 1) downto 0);
    y4_im : out std_logic_vector((26 - 1) downto 0);
    y5_re : out std_logic_vector((26 - 1) downto 0);
    y5_im : out std_logic_vector((26 - 1) downto 0);
    y6_re : out std_logic_vector((26 - 1) downto 0);
    y6_im : out std_logic_vector((26 - 1) downto 0);
    y7_re : out std_logic_vector((26 - 1) downto 0);
    y7_im : out std_logic_vector((26 - 1) downto 0);
    y8_re : out std_logic_vector((26 - 1) downto 0);
    y8_im : out std_logic_vector((26 - 1) downto 0);
    y9_re : out std_logic_vector((26 - 1) downto 0);
    y9_im : out std_logic_vector((26 - 1) downto 0);
    y10_re : out std_logic_vector((26 - 1) downto 0);
    y10_im : out std_logic_vector((26 - 1) downto 0);
    y11_re : out std_logic_vector((26 - 1) downto 0);
    y11_im : out std_logic_vector((26 - 1) downto 0);
    y12_re : out std_logic_vector((26 - 1) downto 0);
    y12_im : out std_logic_vector((26 - 1) downto 0);
    y13_re : out std_logic_vector((26 - 1) downto 0);
    y13_im : out std_logic_vector((26 - 1) downto 0);
    y14_re : out std_logic_vector((26 - 1) downto 0);
    y14_im : out std_logic_vector((26 - 1) downto 0);
    y15_re : out std_logic_vector((26 - 1) downto 0);
    y15_im : out std_logic_vector((26 - 1) downto 0);
    y16_re : out std_logic_vector((26 - 1) downto 0);
    y16_im : out std_logic_vector((26 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_7190f7090b;
architecture behavior of sysgen_mcode_block_7190f7090b
is
  signal x_re_5_32: unsigned((416 - 1) downto 0);
  signal x_im_5_37: unsigned((416 - 1) downto 0);
  signal x1_re_10_1_slice: unsigned((26 - 1) downto 0);
  signal x2_re_11_1_slice: unsigned((26 - 1) downto 0);
  signal x3_re_12_1_slice: unsigned((26 - 1) downto 0);
  signal x4_re_13_1_slice: unsigned((26 - 1) downto 0);
  signal x5_re_14_1_slice: unsigned((26 - 1) downto 0);
  signal x6_re_15_1_slice: unsigned((26 - 1) downto 0);
  signal x7_re_16_1_slice: unsigned((26 - 1) downto 0);
  signal x8_re_17_1_slice: unsigned((26 - 1) downto 0);
  signal x9_re_18_1_slice: unsigned((26 - 1) downto 0);
  signal x10_re_19_1_slice: unsigned((26 - 1) downto 0);
  signal x11_re_20_1_slice: unsigned((26 - 1) downto 0);
  signal x12_re_21_1_slice: unsigned((26 - 1) downto 0);
  signal x13_re_22_1_slice: unsigned((26 - 1) downto 0);
  signal x14_re_23_1_slice: unsigned((26 - 1) downto 0);
  signal x15_re_24_1_slice: unsigned((26 - 1) downto 0);
  signal x16_re_25_1_slice: unsigned((26 - 1) downto 0);
  signal x1_im_27_1_slice: unsigned((26 - 1) downto 0);
  signal x2_im_28_1_slice: unsigned((26 - 1) downto 0);
  signal x3_im_29_1_slice: unsigned((26 - 1) downto 0);
  signal x4_im_30_1_slice: unsigned((26 - 1) downto 0);
  signal x5_im_31_1_slice: unsigned((26 - 1) downto 0);
  signal x6_im_32_1_slice: unsigned((26 - 1) downto 0);
  signal x7_im_33_1_slice: unsigned((26 - 1) downto 0);
  signal x8_im_34_1_slice: unsigned((26 - 1) downto 0);
  signal x9_im_35_1_slice: unsigned((26 - 1) downto 0);
  signal x10_im_36_1_slice: unsigned((26 - 1) downto 0);
  signal x11_im_37_1_slice: unsigned((26 - 1) downto 0);
  signal x12_im_38_1_slice: unsigned((26 - 1) downto 0);
  signal x13_im_39_1_slice: unsigned((26 - 1) downto 0);
  signal x14_im_40_1_slice: unsigned((26 - 1) downto 0);
  signal x15_im_41_1_slice: unsigned((26 - 1) downto 0);
  signal x16_im_42_1_slice: unsigned((26 - 1) downto 0);
  signal y1_re_44_1_force: signed((26 - 1) downto 0);
  signal y2_re_45_1_force: signed((26 - 1) downto 0);
  signal y3_re_46_1_force: signed((26 - 1) downto 0);
  signal y4_re_47_1_force: signed((26 - 1) downto 0);
  signal y5_re_48_1_force: signed((26 - 1) downto 0);
  signal y6_re_49_1_force: signed((26 - 1) downto 0);
  signal y7_re_50_1_force: signed((26 - 1) downto 0);
  signal y8_re_51_1_force: signed((26 - 1) downto 0);
  signal y9_re_52_1_force: signed((26 - 1) downto 0);
  signal y10_re_53_1_force: signed((26 - 1) downto 0);
  signal y11_re_54_1_force: signed((26 - 1) downto 0);
  signal y12_re_55_1_force: signed((26 - 1) downto 0);
  signal y13_re_56_1_force: signed((26 - 1) downto 0);
  signal y14_re_57_1_force: signed((26 - 1) downto 0);
  signal y15_re_58_1_force: signed((26 - 1) downto 0);
  signal y16_re_59_1_force: signed((26 - 1) downto 0);
  signal y1_im_61_1_force: signed((26 - 1) downto 0);
  signal y2_im_62_1_force: signed((26 - 1) downto 0);
  signal y3_im_63_1_force: signed((26 - 1) downto 0);
  signal y4_im_64_1_force: signed((26 - 1) downto 0);
  signal y5_im_65_1_force: signed((26 - 1) downto 0);
  signal y6_im_66_1_force: signed((26 - 1) downto 0);
  signal y7_im_67_1_force: signed((26 - 1) downto 0);
  signal y8_im_68_1_force: signed((26 - 1) downto 0);
  signal y9_im_69_1_force: signed((26 - 1) downto 0);
  signal y10_im_70_1_force: signed((26 - 1) downto 0);
  signal y11_im_71_1_force: signed((26 - 1) downto 0);
  signal y12_im_72_1_force: signed((26 - 1) downto 0);
  signal y13_im_73_1_force: signed((26 - 1) downto 0);
  signal y14_im_74_1_force: signed((26 - 1) downto 0);
  signal y15_im_75_1_force: signed((26 - 1) downto 0);
  signal y16_im_76_1_force: signed((26 - 1) downto 0);
begin
  x_re_5_32 <= std_logic_vector_to_unsigned(x_re);
  x_im_5_37 <= std_logic_vector_to_unsigned(x_im);
  x1_re_10_1_slice <= u2u_slice(x_re_5_32, 415, 390);
  x2_re_11_1_slice <= u2u_slice(x_re_5_32, 389, 364);
  x3_re_12_1_slice <= u2u_slice(x_re_5_32, 363, 338);
  x4_re_13_1_slice <= u2u_slice(x_re_5_32, 337, 312);
  x5_re_14_1_slice <= u2u_slice(x_re_5_32, 311, 286);
  x6_re_15_1_slice <= u2u_slice(x_re_5_32, 285, 260);
  x7_re_16_1_slice <= u2u_slice(x_re_5_32, 259, 234);
  x8_re_17_1_slice <= u2u_slice(x_re_5_32, 233, 208);
  x9_re_18_1_slice <= u2u_slice(x_re_5_32, 207, 182);
  x10_re_19_1_slice <= u2u_slice(x_re_5_32, 181, 156);
  x11_re_20_1_slice <= u2u_slice(x_re_5_32, 155, 130);
  x12_re_21_1_slice <= u2u_slice(x_re_5_32, 129, 104);
  x13_re_22_1_slice <= u2u_slice(x_re_5_32, 103, 78);
  x14_re_23_1_slice <= u2u_slice(x_re_5_32, 77, 52);
  x15_re_24_1_slice <= u2u_slice(x_re_5_32, 51, 26);
  x16_re_25_1_slice <= u2u_slice(x_re_5_32, 25, 0);
  x1_im_27_1_slice <= u2u_slice(x_im_5_37, 415, 390);
  x2_im_28_1_slice <= u2u_slice(x_im_5_37, 389, 364);
  x3_im_29_1_slice <= u2u_slice(x_im_5_37, 363, 338);
  x4_im_30_1_slice <= u2u_slice(x_im_5_37, 337, 312);
  x5_im_31_1_slice <= u2u_slice(x_im_5_37, 311, 286);
  x6_im_32_1_slice <= u2u_slice(x_im_5_37, 285, 260);
  x7_im_33_1_slice <= u2u_slice(x_im_5_37, 259, 234);
  x8_im_34_1_slice <= u2u_slice(x_im_5_37, 233, 208);
  x9_im_35_1_slice <= u2u_slice(x_im_5_37, 207, 182);
  x10_im_36_1_slice <= u2u_slice(x_im_5_37, 181, 156);
  x11_im_37_1_slice <= u2u_slice(x_im_5_37, 155, 130);
  x12_im_38_1_slice <= u2u_slice(x_im_5_37, 129, 104);
  x13_im_39_1_slice <= u2u_slice(x_im_5_37, 103, 78);
  x14_im_40_1_slice <= u2u_slice(x_im_5_37, 77, 52);
  x15_im_41_1_slice <= u2u_slice(x_im_5_37, 51, 26);
  x16_im_42_1_slice <= u2u_slice(x_im_5_37, 25, 0);
  y1_re_44_1_force <= unsigned_to_signed(x1_re_10_1_slice);
  y2_re_45_1_force <= unsigned_to_signed(x2_re_11_1_slice);
  y3_re_46_1_force <= unsigned_to_signed(x3_re_12_1_slice);
  y4_re_47_1_force <= unsigned_to_signed(x4_re_13_1_slice);
  y5_re_48_1_force <= unsigned_to_signed(x5_re_14_1_slice);
  y6_re_49_1_force <= unsigned_to_signed(x6_re_15_1_slice);
  y7_re_50_1_force <= unsigned_to_signed(x7_re_16_1_slice);
  y8_re_51_1_force <= unsigned_to_signed(x8_re_17_1_slice);
  y9_re_52_1_force <= unsigned_to_signed(x9_re_18_1_slice);
  y10_re_53_1_force <= unsigned_to_signed(x10_re_19_1_slice);
  y11_re_54_1_force <= unsigned_to_signed(x11_re_20_1_slice);
  y12_re_55_1_force <= unsigned_to_signed(x12_re_21_1_slice);
  y13_re_56_1_force <= unsigned_to_signed(x13_re_22_1_slice);
  y14_re_57_1_force <= unsigned_to_signed(x14_re_23_1_slice);
  y15_re_58_1_force <= unsigned_to_signed(x15_re_24_1_slice);
  y16_re_59_1_force <= unsigned_to_signed(x16_re_25_1_slice);
  y1_im_61_1_force <= unsigned_to_signed(x1_im_27_1_slice);
  y2_im_62_1_force <= unsigned_to_signed(x2_im_28_1_slice);
  y3_im_63_1_force <= unsigned_to_signed(x3_im_29_1_slice);
  y4_im_64_1_force <= unsigned_to_signed(x4_im_30_1_slice);
  y5_im_65_1_force <= unsigned_to_signed(x5_im_31_1_slice);
  y6_im_66_1_force <= unsigned_to_signed(x6_im_32_1_slice);
  y7_im_67_1_force <= unsigned_to_signed(x7_im_33_1_slice);
  y8_im_68_1_force <= unsigned_to_signed(x8_im_34_1_slice);
  y9_im_69_1_force <= unsigned_to_signed(x9_im_35_1_slice);
  y10_im_70_1_force <= unsigned_to_signed(x10_im_36_1_slice);
  y11_im_71_1_force <= unsigned_to_signed(x11_im_37_1_slice);
  y12_im_72_1_force <= unsigned_to_signed(x12_im_38_1_slice);
  y13_im_73_1_force <= unsigned_to_signed(x13_im_39_1_slice);
  y14_im_74_1_force <= unsigned_to_signed(x14_im_40_1_slice);
  y15_im_75_1_force <= unsigned_to_signed(x15_im_41_1_slice);
  y16_im_76_1_force <= unsigned_to_signed(x16_im_42_1_slice);
  y1_re <= signed_to_std_logic_vector(y1_re_44_1_force);
  y1_im <= signed_to_std_logic_vector(y1_im_61_1_force);
  y2_re <= signed_to_std_logic_vector(y2_re_45_1_force);
  y2_im <= signed_to_std_logic_vector(y2_im_62_1_force);
  y3_re <= signed_to_std_logic_vector(y3_re_46_1_force);
  y3_im <= signed_to_std_logic_vector(y3_im_63_1_force);
  y4_re <= signed_to_std_logic_vector(y4_re_47_1_force);
  y4_im <= signed_to_std_logic_vector(y4_im_64_1_force);
  y5_re <= signed_to_std_logic_vector(y5_re_48_1_force);
  y5_im <= signed_to_std_logic_vector(y5_im_65_1_force);
  y6_re <= signed_to_std_logic_vector(y6_re_49_1_force);
  y6_im <= signed_to_std_logic_vector(y6_im_66_1_force);
  y7_re <= signed_to_std_logic_vector(y7_re_50_1_force);
  y7_im <= signed_to_std_logic_vector(y7_im_67_1_force);
  y8_re <= signed_to_std_logic_vector(y8_re_51_1_force);
  y8_im <= signed_to_std_logic_vector(y8_im_68_1_force);
  y9_re <= signed_to_std_logic_vector(y9_re_52_1_force);
  y9_im <= signed_to_std_logic_vector(y9_im_69_1_force);
  y10_re <= signed_to_std_logic_vector(y10_re_53_1_force);
  y10_im <= signed_to_std_logic_vector(y10_im_70_1_force);
  y11_re <= signed_to_std_logic_vector(y11_re_54_1_force);
  y11_im <= signed_to_std_logic_vector(y11_im_71_1_force);
  y12_re <= signed_to_std_logic_vector(y12_re_55_1_force);
  y12_im <= signed_to_std_logic_vector(y12_im_72_1_force);
  y13_re <= signed_to_std_logic_vector(y13_re_56_1_force);
  y13_im <= signed_to_std_logic_vector(y13_im_73_1_force);
  y14_re <= signed_to_std_logic_vector(y14_re_57_1_force);
  y14_im <= signed_to_std_logic_vector(y14_im_74_1_force);
  y15_re <= signed_to_std_logic_vector(y15_re_58_1_force);
  y15_im <= signed_to_std_logic_vector(y15_im_75_1_force);
  y16_re <= signed_to_std_logic_vector(y16_re_59_1_force);
  y16_im <= signed_to_std_logic_vector(y16_im_76_1_force);
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

---------------------------------------------------------------------
 --
 --  Filename      : xlcounter.vhd
 --
 --  Created       : 5/31/00
 --  Modified      : 6/7/00
 --
 --  Description   : VHDL wrapper for a counter. This wrapper
 --                  uses the Binary Counter CoreGenerator core.
 --
 ---------------------------------------------------------------------
 
 
 ---------------------------------------------------------------------
 --
 --  Entity        : xlcounter
 --
 --  Architecture  : behavior
 --
 --  Description   : Top level VHDL description of a counter.
 --
 ---------------------------------------------------------------------
 
 library IEEE;
 use IEEE.std_logic_1164.all;
 use IEEE.numeric_std.all;

entity basic_dmt_xlcounter_limit is 
   generic (
     core_name0: string := "";
     op_width: integer := 5;
     op_arith: integer := xlSigned;
     cnt_63_48: integer:= 0;
     cnt_47_32: integer:= 0;
     cnt_31_16: integer:= 0;
     cnt_15_0: integer:= 0;
     count_limited: integer := 0		-- 0 if cnt_to = (2^n)-1 else 1
   );
   port (
     ce: in std_logic;
     clr: in std_logic;
     clk: in std_logic;
     op: out std_logic_vector(op_width - 1 downto 0);
     up: in std_logic_vector(0 downto 0) := (others => '0');
     en: in std_logic_vector(0 downto 0);
     rst: in std_logic_vector(0 downto 0)
   );
 end basic_dmt_xlcounter_limit;
 
 architecture behavior of basic_dmt_xlcounter_limit is
 signal high_cnt_to: std_logic_vector(31 downto 0);
 signal low_cnt_to: std_logic_vector(31 downto 0);
 signal cnt_to: std_logic_vector(63 downto 0);
 signal core_sinit, op_thresh0, core_ce: std_logic;
 signal rst_overrides_en: std_logic;
 signal op_net: std_logic_vector(op_width - 1 downto 0);
 
 -- synthesis translate_off
 signal real_op : real; -- For debugging info ports
 -- synthesis translate_on
 
 function equals(op, cnt_to : std_logic_vector; width, arith : integer)
 return std_logic
 is
 variable signed_op, signed_cnt_to : signed (width - 1 downto 0);
 variable unsigned_op, unsigned_cnt_to : unsigned (width - 1 downto 0);
 variable result : std_logic;
 begin
 -- synthesis translate_off
 if ((is_XorU(op)) or (is_XorU(cnt_to)) ) then
 result := '0';
 return result;
 end if;
 -- synthesis translate_on
 
 if (op = cnt_to) then
 result := '1';
 else
 result := '0';
 end if;
 return result;
 end;


 component basic_dmt_c_counter_binary_v12_0_0
    port ( 
      clk: in std_logic;
      ce: in std_logic;
      SINIT: in std_logic;
      q: out std_logic_vector(op_width - 1 downto 0) 
 		  ); 
 end component;

-- synthesis translate_off
   constant zeroVec : std_logic_vector(op_width - 1 downto 0) := (others => '0');
   constant oneVec : std_logic_vector(op_width - 1 downto 0) := (others => '1');
   constant zeroStr : string(1 to op_width) :=
     std_logic_vector_to_bin_string(zeroVec);
   constant oneStr : string(1 to op_width) :=
     std_logic_vector_to_bin_string(oneVec);
 -- synthesis translate_on
 
 begin
   -- Debugging info for internal full precision variables
   -- synthesis translate_off
 --     real_op <= to_real(op, op_bin_pt, op_arith);
   -- synthesis translate_on
 
   cnt_to(63 downto 48) <= integer_to_std_logic_vector(cnt_63_48, 16, op_arith);
   cnt_to(47 downto 32) <= integer_to_std_logic_vector(cnt_47_32, 16, op_arith);
   cnt_to(31 downto 16) <= integer_to_std_logic_vector(cnt_31_16, 16, op_arith);
   cnt_to(15 downto 0) <= integer_to_std_logic_vector(cnt_15_0, 16, op_arith);
 
   -- Output of counter always valid
   op <= op_net;
   core_ce <= ce and en(0);
   rst_overrides_en <= rst(0) or en(0);
 
   limit : if (count_limited = 1) generate
     eq_cnt_to : process (op_net, cnt_to)
     begin
       -- Had to pass cnt_to(op_width - 1 downto 0) instead of cnt_to so
       -- that XST would infer a macro
       op_thresh0 <= equals(op_net, cnt_to(op_width - 1 downto 0),
                      op_width, op_arith);
     end process;
 
     core_sinit <= (op_thresh0 or clr or rst(0)) and ce and rst_overrides_en;
   end generate;
 
   no_limit : if (count_limited = 0) generate
     core_sinit <= (clr or rst(0)) and ce and rst_overrides_en;
   end generate;


 comp0: if ((core_name0 = "basic_dmt_c_counter_binary_v12_0_0")) generate 
  core_instance0:basic_dmt_c_counter_binary_v12_0_0
   port map ( 
        clk => clk,
        ce => core_ce,
        SINIT => core_sinit,
        q => op_net
  ); 
   end generate;

end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

---------------------------------------------------------------------
 --
 --  Entity        : xlfifogen
 --
 --  Architecture  : behavior
 --
 --  Description   : Top level VHDL description of a fifo block
 --
 ---------------------------------------------------------------------
 
 library IEEE;
 use IEEE.std_logic_1164.all;
 use IEEE.std_logic_arith.all;
 use ieee.std_logic_unsigned.all;

entity basic_dmt_xlfifogen is 
   generic (
     core_name0: string := "";
     data_width: integer := -1;
     data_count_width: integer := -1;
     percent_full_width: integer := -1;
     has_ae : integer := 0;
     has_af : integer := 0;
     extra_registers: integer := 2
   );
   port (
     din: in std_logic_vector(data_width - 1 downto 0);
     we: in std_logic;
     we_ce: in std_logic;
     re: in std_logic;
     re_ce: in std_logic;
     rst: in std_logic;
     en: in std_logic;
     ce: in std_logic;
     clk: in std_logic;
     empty: out std_logic;
     full: out std_logic;
     percent_full: out std_logic_vector(percent_full_width - 1 downto 0);
     dcount: out std_logic_vector(data_count_width - 1 downto 0);
     ae: out std_logic;
     af: out std_logic;
     dout: out std_logic_vector(data_width - 1 downto 0)
   );
 end basic_dmt_xlfifogen;
 
 architecture behavior of basic_dmt_xlfifogen is
 component synth_reg
 generic (
 width: integer := 16;
 latency: integer := 5
 );
 port (
 i: in std_logic_vector(width - 1 downto 0);
 ce: in std_logic;
 clr: in std_logic;
 clk: in std_logic;
 o: out std_logic_vector(width - 1 downto 0)
 );
 end component;
 


 component basic_dmt_fifo_generator_v12_0_0
    port ( 
      clk: in std_logic;
      din: in std_logic_vector(data_width - 1 downto 0);
      wr_en: in std_logic;
      rd_en: in std_logic;
      dout: out std_logic_vector(data_width - 1 downto 0);
      full: out std_logic;
      empty: out std_logic;
      data_count: out std_logic_vector(data_count_width - 1 downto 0) 
 		  ); 
 end component;

 component basic_dmt_fifo_generator_v12_0_1
    port ( 
      clk: in std_logic;
      din: in std_logic_vector(data_width - 1 downto 0);
      wr_en: in std_logic;
      rd_en: in std_logic;
      dout: out std_logic_vector(data_width - 1 downto 0);
      full: out std_logic;
      empty: out std_logic 
 		  ); 
 end component;

 component basic_dmt_fifo_generator_v12_0_2
    port ( 
      clk: in std_logic;
      din: in std_logic_vector(data_width - 1 downto 0);
      wr_en: in std_logic;
      rd_en: in std_logic;
      dout: out std_logic_vector(data_width - 1 downto 0);
      full: out std_logic;
      empty: out std_logic 
 		  ); 
 end component;

 component basic_dmt_fifo_generator_v12_0_3
    port ( 
      clk: in std_logic;
      din: in std_logic_vector(data_width - 1 downto 0);
      wr_en: in std_logic;
      rd_en: in std_logic;
      dout: out std_logic_vector(data_width - 1 downto 0);
      full: out std_logic;
      empty: out std_logic;
      data_count: out std_logic_vector(data_count_width - 1 downto 0) 
 		  ); 
 end component;

 component basic_dmt_fifo_generator_v12_0_4
    port ( 
      clk: in std_logic;
      din: in std_logic_vector(data_width - 1 downto 0);
      wr_en: in std_logic;
      rd_en: in std_logic;
      dout: out std_logic_vector(data_width - 1 downto 0);
      full: out std_logic;
      empty: out std_logic;
      data_count: out std_logic_vector(data_count_width - 1 downto 0) 
 		  ); 
 end component;

 component basic_dmt_fifo_generator_v12_0_5
    port ( 
      clk: in std_logic;
      din: in std_logic_vector(data_width - 1 downto 0);
      wr_en: in std_logic;
      rd_en: in std_logic;
      dout: out std_logic_vector(data_width - 1 downto 0);
      full: out std_logic;
      empty: out std_logic;
      data_count: out std_logic_vector(data_count_width - 1 downto 0) 
 		  ); 
 end component;

  signal rd_en: std_logic;
   signal wr_en: std_logic;
   signal srst: std_logic;
   signal core_full: std_logic;
   signal core_dcount: std_logic_vector(data_count_width - 1 downto 0);
   signal srst_vec: std_logic_vector(0 downto 0);
 
 begin
 

 comp0: if ((core_name0 = "basic_dmt_fifo_generator_v12_0_0")) generate 
  core_instance0:basic_dmt_fifo_generator_v12_0_0
   port map ( 
        clk => clk,
        din => din,
        wr_en => wr_en,
        rd_en => rd_en,
        full => core_full,
        dout => dout,
        empty => empty
,
        data_count => core_dcount
  ); 
   end generate;

 comp1: if ((core_name0 = "basic_dmt_fifo_generator_v12_0_1")) generate 
  core_instance1:basic_dmt_fifo_generator_v12_0_1
   port map ( 
        clk => clk,
        din => din,
        wr_en => wr_en,
        rd_en => rd_en,
        full => core_full,
        dout => dout,
        empty => empty

  ); 
   end generate;

 comp2: if ((core_name0 = "basic_dmt_fifo_generator_v12_0_2")) generate 
  core_instance2:basic_dmt_fifo_generator_v12_0_2
   port map ( 
        clk => clk,
        din => din,
        wr_en => wr_en,
        rd_en => rd_en,
        full => core_full,
        dout => dout,
        empty => empty

  ); 
   end generate;

 comp3: if ((core_name0 = "basic_dmt_fifo_generator_v12_0_3")) generate 
  core_instance3:basic_dmt_fifo_generator_v12_0_3
   port map ( 
        clk => clk,
        din => din,
        wr_en => wr_en,
        rd_en => rd_en,
        full => core_full,
        dout => dout,
        empty => empty
,
        data_count => core_dcount
  ); 
   end generate;

 comp4: if ((core_name0 = "basic_dmt_fifo_generator_v12_0_4")) generate 
  core_instance4:basic_dmt_fifo_generator_v12_0_4
   port map ( 
        clk => clk,
        din => din,
        wr_en => wr_en,
        rd_en => rd_en,
        full => core_full,
        dout => dout,
        empty => empty
,
        data_count => core_dcount
  ); 
   end generate;

 comp5: if ((core_name0 = "basic_dmt_fifo_generator_v12_0_5")) generate 
  core_instance5:basic_dmt_fifo_generator_v12_0_5
   port map ( 
        clk => clk,
        din => din,
        wr_en => wr_en,
        rd_en => rd_en,
        full => core_full,
        dout => dout,
        empty => empty
,
        data_count => core_dcount
  ); 
   end generate;

-- Process to remap data count from 0000->1111 when fifo is full.
   modify_count: process(core_full, core_dcount) is
   begin
     if core_full = '1' then
       percent_full <= (others => '1');
     else
       percent_full <= core_dcount(data_count_width-1 downto data_count_width-percent_full_width);
     end if;
   end process modify_count;
   
   rd_en <= re and en and re_ce;
   wr_en <= we and en and we_ce;
   full <= core_full;
   dcount <= core_dcount;
   
   --Zero ae/af if these signals are not specified on the core
   terminate_core_ae: if has_ae /= 1 generate
   begin
     ae <= '0';
   end generate terminate_core_ae;
   terminate_core_af: if has_af /= 1 generate
   begin
     af <= '0';
   end generate terminate_core_af;
latency_gt_0: if (extra_registers > 0) generate
   reg: synth_reg
     generic map (
       width => 1,
       latency => extra_registers
     )
     port map (
       i => std_logic_to_vector(rst),
       ce => ce,
       clr => '0',
       clk => clk,
       o => srst_vec
     );
     srst <= srst_vec(0);
 end generate;
 
 latency_eq_0: if (extra_registers = 0) generate
   srst <= rst and ce;
 end generate;
 
 end  behavior;
 
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

entity xlfast_fourier_transform_56afb6d1c1e51bed448a5501b8c5efcd is 
  port(
    ce:in std_logic;
    clk:in std_logic;
    en:in std_logic;
    event_data_in_channel_halt:out std_logic;
    event_data_out_channel_halt:out std_logic;
    event_frame_started:out std_logic;
    event_status_channel_halt:out std_logic;
    event_tlast_missing:out std_logic;
    event_tlast_unexpected:out std_logic;
    m_axis_data_tdata_xn_im_0:out std_logic_vector(20 downto 0);
    m_axis_data_tdata_xn_re_0:out std_logic_vector(20 downto 0);
    m_axis_data_tlast:out std_logic;
    m_axis_data_tready:in std_logic;
    m_axis_data_tuser_xk_index:out std_logic_vector(3 downto 0);
    m_axis_data_tvalid:out std_logic;
    s_axis_config_tdata_fwd_inv:in std_logic_vector(0 downto 0);
    s_axis_config_tready:out std_logic;
    s_axis_config_tvalid:in std_logic;
    s_axis_data_tdata_xn_im_0:in std_logic_vector(15 downto 0);
    s_axis_data_tdata_xn_re_0:in std_logic_vector(15 downto 0);
    s_axis_data_tlast:in std_logic;
    s_axis_data_tready:out std_logic;
    s_axis_data_tvalid:in std_logic
  );
end xlfast_fourier_transform_56afb6d1c1e51bed448a5501b8c5efcd; 

architecture behavior of xlfast_fourier_transform_56afb6d1c1e51bed448a5501b8c5efcd  is
  component basic_dmt_xfft_v9_0_0
    port(
      aclk:in std_logic;
      aclken:in std_logic;
      event_data_in_channel_halt:out std_logic;
      event_data_out_channel_halt:out std_logic;
      event_frame_started:out std_logic;
      event_status_channel_halt:out std_logic;
      event_tlast_missing:out std_logic;
      event_tlast_unexpected:out std_logic;
      m_axis_data_tdata:out std_logic_vector(47 downto 0);
      m_axis_data_tlast:out std_logic;
      m_axis_data_tready:in std_logic;
      m_axis_data_tuser:out std_logic_vector(7 downto 0);
      m_axis_data_tvalid:out std_logic;
      s_axis_config_tdata:in std_logic_vector(7 downto 0);
      s_axis_config_tready:out std_logic;
      s_axis_config_tvalid:in std_logic;
      s_axis_data_tdata:in std_logic_vector(31 downto 0);
      s_axis_data_tlast:in std_logic;
      s_axis_data_tready:out std_logic;
      s_axis_data_tvalid:in std_logic
    );
end component;
signal aclken_net: std_logic := '0';
signal m_axis_data_tdata_net: std_logic_vector(47 downto 0) := (others=>'0');
signal m_axis_data_tuser_net: std_logic_vector(7 downto 0) := (others=>'0');
signal s_axis_config_tdata_net: std_logic_vector(7 downto 0) := (others=>'0');
signal s_axis_data_tdata_net: std_logic_vector(31 downto 0) := (others=>'0');
begin
  aclken_net <= en and ce;
  m_axis_data_tdata_xn_im_0 <= m_axis_data_tdata_net(44 downto 24);
  m_axis_data_tdata_xn_re_0 <= m_axis_data_tdata_net(20 downto 0);
  m_axis_data_tuser_xk_index <= m_axis_data_tuser_net(3 downto 0);
  s_axis_config_tdata_net(0 downto 0) <= s_axis_config_tdata_fwd_inv;
  s_axis_data_tdata_net(31 downto 16) <= s_axis_data_tdata_xn_im_0;
  s_axis_data_tdata_net(15 downto 0) <= s_axis_data_tdata_xn_re_0;
  basic_dmt_xfft_v9_0_0_instance : basic_dmt_xfft_v9_0_0
    port map(
      aclk=>clk,
      aclken=>aclken_net,
      event_data_in_channel_halt=>event_data_in_channel_halt,
      event_data_out_channel_halt=>event_data_out_channel_halt,
      event_frame_started=>event_frame_started,
      event_status_channel_halt=>event_status_channel_halt,
      event_tlast_missing=>event_tlast_missing,
      event_tlast_unexpected=>event_tlast_unexpected,
      m_axis_data_tdata=>m_axis_data_tdata_net,
      m_axis_data_tlast=>m_axis_data_tlast,
      m_axis_data_tready=>m_axis_data_tready,
      m_axis_data_tuser=>m_axis_data_tuser_net,
      m_axis_data_tvalid=>m_axis_data_tvalid,
      s_axis_config_tdata=>s_axis_config_tdata_net,
      s_axis_config_tready=>s_axis_config_tready,
      s_axis_config_tvalid=>s_axis_config_tvalid,
      s_axis_data_tdata=>s_axis_data_tdata_net,
      s_axis_data_tlast=>s_axis_data_tlast,
      s_axis_data_tready=>s_axis_data_tready,
      s_axis_data_tvalid=>s_axis_data_tvalid
    );
end behavior;


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

entity xlfast_fourier_transform_7bdb82ffedec749ee066981b436841d9 is 
  port(
    ce:in std_logic;
    clk:in std_logic;
    en:in std_logic;
    event_data_in_channel_halt:out std_logic;
    event_data_out_channel_halt:out std_logic;
    event_frame_started:out std_logic;
    event_status_channel_halt:out std_logic;
    event_tlast_missing:out std_logic;
    event_tlast_unexpected:out std_logic;
    m_axis_data_tdata_xn_im_0:out std_logic_vector(25 downto 0);
    m_axis_data_tdata_xn_re_0:out std_logic_vector(25 downto 0);
    m_axis_data_tlast:out std_logic;
    m_axis_data_tready:in std_logic;
    m_axis_data_tuser_xk_index:out std_logic_vector(3 downto 0);
    m_axis_data_tvalid:out std_logic;
    s_axis_config_tdata_fwd_inv:in std_logic_vector(0 downto 0);
    s_axis_config_tready:out std_logic;
    s_axis_config_tvalid:in std_logic;
    s_axis_data_tdata_xn_im_0:in std_logic_vector(20 downto 0);
    s_axis_data_tdata_xn_re_0:in std_logic_vector(20 downto 0);
    s_axis_data_tlast:in std_logic;
    s_axis_data_tready:out std_logic;
    s_axis_data_tvalid:in std_logic
  );
end xlfast_fourier_transform_7bdb82ffedec749ee066981b436841d9; 

architecture behavior of xlfast_fourier_transform_7bdb82ffedec749ee066981b436841d9  is
  component basic_dmt_xfft_v9_0_1
    port(
      aclk:in std_logic;
      aclken:in std_logic;
      event_data_in_channel_halt:out std_logic;
      event_data_out_channel_halt:out std_logic;
      event_frame_started:out std_logic;
      event_status_channel_halt:out std_logic;
      event_tlast_missing:out std_logic;
      event_tlast_unexpected:out std_logic;
      m_axis_data_tdata:out std_logic_vector(63 downto 0);
      m_axis_data_tlast:out std_logic;
      m_axis_data_tready:in std_logic;
      m_axis_data_tuser:out std_logic_vector(7 downto 0);
      m_axis_data_tvalid:out std_logic;
      s_axis_config_tdata:in std_logic_vector(7 downto 0);
      s_axis_config_tready:out std_logic;
      s_axis_config_tvalid:in std_logic;
      s_axis_data_tdata:in std_logic_vector(47 downto 0);
      s_axis_data_tlast:in std_logic;
      s_axis_data_tready:out std_logic;
      s_axis_data_tvalid:in std_logic
    );
end component;
signal aclken_net: std_logic := '0';
signal m_axis_data_tdata_net: std_logic_vector(63 downto 0) := (others=>'0');
signal m_axis_data_tuser_net: std_logic_vector(7 downto 0) := (others=>'0');
signal s_axis_config_tdata_net: std_logic_vector(7 downto 0) := (others=>'0');
signal s_axis_data_tdata_net: std_logic_vector(47 downto 0) := (others=>'0');
begin
  aclken_net <= en and ce;
  m_axis_data_tdata_xn_im_0 <= m_axis_data_tdata_net(57 downto 32);
  m_axis_data_tdata_xn_re_0 <= m_axis_data_tdata_net(25 downto 0);
  m_axis_data_tuser_xk_index <= m_axis_data_tuser_net(3 downto 0);
  s_axis_config_tdata_net(0 downto 0) <= s_axis_config_tdata_fwd_inv;
  s_axis_data_tdata_net(44 downto 24) <= s_axis_data_tdata_xn_im_0;
  s_axis_data_tdata_net(20 downto 0) <= s_axis_data_tdata_xn_re_0;
  basic_dmt_xfft_v9_0_1_instance : basic_dmt_xfft_v9_0_1
    port map(
      aclk=>clk,
      aclken=>aclken_net,
      event_data_in_channel_halt=>event_data_in_channel_halt,
      event_data_out_channel_halt=>event_data_out_channel_halt,
      event_frame_started=>event_frame_started,
      event_status_channel_halt=>event_status_channel_halt,
      event_tlast_missing=>event_tlast_missing,
      event_tlast_unexpected=>event_tlast_unexpected,
      m_axis_data_tdata=>m_axis_data_tdata_net,
      m_axis_data_tlast=>m_axis_data_tlast,
      m_axis_data_tready=>m_axis_data_tready,
      m_axis_data_tuser=>m_axis_data_tuser_net,
      m_axis_data_tvalid=>m_axis_data_tvalid,
      s_axis_config_tdata=>s_axis_config_tdata_net,
      s_axis_config_tready=>s_axis_config_tready,
      s_axis_config_tvalid=>s_axis_config_tvalid,
      s_axis_data_tdata=>s_axis_data_tdata_net,
      s_axis_data_tlast=>s_axis_data_tlast,
      s_axis_data_tready=>s_axis_data_tready,
      s_axis_data_tvalid=>s_axis_data_tvalid
    );
end behavior;



