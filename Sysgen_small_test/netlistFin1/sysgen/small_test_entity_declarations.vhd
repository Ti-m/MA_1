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

entity small_test_xldsamp is
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
end small_test_xldsamp;

architecture struct of small_test_xldsamp is
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
entity sysgen_mcode_block_108a9ea098 is
  port (
    i : in std_logic_vector((16 - 1) downto 0);
    q : in std_logic_vector((16 - 1) downto 0);
    y1 : out std_logic_vector((4 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_mcode_block_108a9ea098;
architecture behavior of sysgen_mcode_block_108a9ea098
is
  signal i_1_28: signed((16 - 1) downto 0);
  signal q_1_30: signed((16 - 1) downto 0);
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
  rel_8_13 <= i_1_28 > std_logic_vector_to_signed("0100000000000000");
  proc_if_8_9: process (rel_8_13)
  is
  begin
    if rel_8_13 then
      b1_join_8_9 <= std_logic_vector_to_unsigned("0");
    else 
      b1_join_8_9 <= std_logic_vector_to_unsigned("1");
    end if;
  end process proc_if_8_9;
  rel_15_13 <= i_1_28 > std_logic_vector_to_signed("1100000000000000");
  proc_if_15_9: process (rel_15_13)
  is
  begin
    if rel_15_13 then
      b1_join_15_9 <= std_logic_vector_to_unsigned("1");
    else 
      b1_join_15_9 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_15_9;
  rel_6_6 <= i_1_28 > std_logic_vector_to_signed("0000000000000000");
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
  rel_23_13 <= q_1_30 > std_logic_vector_to_signed("0100000000000000");
  proc_if_23_9: process (rel_23_13)
  is
  begin
    if rel_23_13 then
      b3_join_23_9 <= std_logic_vector_to_unsigned("0");
    else 
      b3_join_23_9 <= std_logic_vector_to_unsigned("1");
    end if;
  end process proc_if_23_9;
  rel_30_13 <= q_1_30 > std_logic_vector_to_signed("1100000000000000");
  proc_if_30_9: process (rel_30_13)
  is
  begin
    if rel_30_13 then
      b3_join_30_9 <= std_logic_vector_to_unsigned("1");
    else 
      b3_join_30_9 <= std_logic_vector_to_unsigned("0");
    end if;
  end process proc_if_30_9;
  rel_21_9 <= q_1_30 > std_logic_vector_to_signed("0000000000000000");
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

entity small_test_xlp2s is
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

end small_test_xlp2s;

architecture synth_behavioral of small_test_xlp2s is

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

---------------------------------------------------------------------
--
--  Filename      : xlregister.vhd
--
--  Description   : VHDL description of an arbitrary wide register.
--                  Unlike the delay block, an initial value is
--                  specified and is considered valid at the start
--                  of simulation.  The register is only one word
--                  deep.
--
--  Mod. History  : Removed valid bit logic from wrapper.
--                : Changed VHDL to use a bit_vector generic for its
--
---------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;


entity small_test_xlregister is

   generic (d_width          : integer := 5;          -- Width of d input
            init_value       : bit_vector := b"00");  -- Binary init value string

   port (d   : in std_logic_vector (d_width-1 downto 0);
         rst : in std_logic_vector(0 downto 0) := "0";
         en  : in std_logic_vector(0 downto 0) := "1";
         ce  : in std_logic;
         clk : in std_logic;
         q   : out std_logic_vector (d_width-1 downto 0));

end small_test_xlregister;

architecture behavior of small_test_xlregister is

   component synth_reg_w_init
      generic (width      : integer;
               init_index : integer;
               init_value : bit_vector;
               latency    : integer);
      port (i   : in std_logic_vector(width-1 downto 0);
            ce  : in std_logic;
            clr : in std_logic;
            clk : in std_logic;
            o   : out std_logic_vector(width-1 downto 0));
   end component; -- end synth_reg_w_init

   -- synthesis translate_off
   signal real_d, real_q           : real;    -- For debugging info ports
   -- synthesis translate_on
   signal internal_clr             : std_logic;
   signal internal_ce              : std_logic;

begin

   internal_clr <= rst(0) and ce;
   internal_ce  <= en(0) and ce;

   -- Synthesizable behavioral model
   synth_reg_inst : synth_reg_w_init
      generic map (width      => d_width,
                   init_index => 2,
                   init_value => init_value,
                   latency    => 1)
      port map (i   => d,
                ce  => internal_ce,
                clr => internal_clr,
                clk => clk,
                o   => q);

end architecture behavior;


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

entity small_test_xls2p is

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

end small_test_xls2p;

architecture synth_behavioral of small_test_xls2p is

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

entity small_test_xlusamp is

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
end small_test_xlusamp;

architecture struct of small_test_xlusamp is
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
entity sysgen_bitbasher_6f934eab2e is
  port (
    a : in std_logic_vector((4 - 1) downto 0);
    b : out std_logic_vector((2 - 1) downto 0);
    c : out std_logic_vector((2 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_bitbasher_6f934eab2e;
architecture behavior of sysgen_bitbasher_6f934eab2e
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
entity sysgen_constant_8298a0350f is
  port (
    op : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_8298a0350f;
architecture behavior of sysgen_constant_8298a0350f
is
begin
  op <= "1010000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_12484bd0f1 is
  port (
    op : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_12484bd0f1;
architecture behavior of sysgen_constant_12484bd0f1
is
begin
  op <= "1110000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_dd6c28fc92 is
  port (
    op : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_dd6c28fc92;
architecture behavior of sysgen_constant_dd6c28fc92
is
begin
  op <= "0110000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_constant_bfc89839f9 is
  port (
    op : out std_logic_vector((16 - 1) downto 0);
    clk : in std_logic;
    ce : in std_logic;
    clr : in std_logic);
end sysgen_constant_bfc89839f9;
architecture behavior of sysgen_constant_bfc89839f9
is
begin
  op <= "0010000000000000";
end behavior;

library xil_defaultlib;
use xil_defaultlib.conv_pkg.all;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
entity sysgen_mux_017810f7a9 is
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
end sysgen_mux_017810f7a9;
architecture behavior of sysgen_mux_017810f7a9
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

