-- (c) Copyright 1995-2016 Xilinx, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
-- DO NOT MODIFY THIS FILE.

-- IP VLNV: User_Company:SysGen:basic_dmt:8.41210
-- IP Revision: 95514859

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

LIBRARY xil_defaultlib;
USE xil_defaultlib.basic_dmt;

ENTITY basic_dmt_0 IS
  PORT (
    inp_recv_im : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
    inp_recv_re : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
    inp_trans : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
    clk : IN STD_LOGIC;
    diffsig : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
    out_recv : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
    out_trans_im : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
    out_trans_re : OUT STD_LOGIC_VECTOR(8 DOWNTO 0)
  );
END basic_dmt_0;

ARCHITECTURE basic_dmt_0_arch OF basic_dmt_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : string;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF basic_dmt_0_arch: ARCHITECTURE IS "yes";

  COMPONENT basic_dmt IS
    PORT (
      inp_recv_im : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
      inp_recv_re : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
      inp_trans : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
      clk : IN STD_LOGIC;
      diffsig : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
      out_recv : OUT STD_LOGIC_VECTOR(0 DOWNTO 0);
      out_trans_im : OUT STD_LOGIC_VECTOR(8 DOWNTO 0);
      out_trans_re : OUT STD_LOGIC_VECTOR(8 DOWNTO 0)
    );
  END COMPONENT basic_dmt;
  ATTRIBUTE X_CORE_INFO : STRING;
  ATTRIBUTE X_CORE_INFO OF basic_dmt_0_arch: ARCHITECTURE IS "basic_dmt,Vivado 2014.4";
  ATTRIBUTE CHECK_LICENSE_TYPE : STRING;
  ATTRIBUTE CHECK_LICENSE_TYPE OF basic_dmt_0_arch : ARCHITECTURE IS "basic_dmt_0,basic_dmt,{}";
  ATTRIBUTE X_INTERFACE_INFO : STRING;
  ATTRIBUTE X_INTERFACE_INFO OF inp_recv_im: SIGNAL IS "xilinx.com:signal:data:1.0 inp_recv_im DATA";
  ATTRIBUTE X_INTERFACE_INFO OF inp_recv_re: SIGNAL IS "xilinx.com:signal:data:1.0 inp_recv_re DATA";
  ATTRIBUTE X_INTERFACE_INFO OF inp_trans: SIGNAL IS "xilinx.com:signal:data:1.0 inp_trans DATA";
  ATTRIBUTE X_INTERFACE_INFO OF clk: SIGNAL IS "xilinx.com:signal:clock:1.0 clk CLK";
  ATTRIBUTE X_INTERFACE_INFO OF diffsig: SIGNAL IS "xilinx.com:signal:data:1.0 diffsig DATA";
  ATTRIBUTE X_INTERFACE_INFO OF out_recv: SIGNAL IS "xilinx.com:signal:data:1.0 out_recv DATA";
  ATTRIBUTE X_INTERFACE_INFO OF out_trans_im: SIGNAL IS "xilinx.com:signal:data:1.0 out_trans_im DATA";
  ATTRIBUTE X_INTERFACE_INFO OF out_trans_re: SIGNAL IS "xilinx.com:signal:data:1.0 out_trans_re DATA";
BEGIN
  U0 : basic_dmt
    PORT MAP (
      inp_recv_im => inp_recv_im,
      inp_recv_re => inp_recv_re,
      inp_trans => inp_trans,
      clk => clk,
      diffsig => diffsig,
      out_recv => out_recv,
      out_trans_im => out_trans_im,
      out_trans_re => out_trans_re
    );
END basic_dmt_0_arch;
