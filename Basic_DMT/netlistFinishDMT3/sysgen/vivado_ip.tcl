#-----------------------------------------------------------------
# System Generator version 2014.4 IP Tcl source file.
#
# Copyright(C) 2013 by Xilinx, Inc.  All rights reserved.  This
# text/file contains proprietary, confidential information of Xilinx,
# Inc., is distributed under license from Xilinx, Inc., and may be used,
# copied and/or disclosed only pursuant to the terms of a valid license
# agreement with Xilinx, Inc.  Xilinx hereby grants you a license to use
# this text/file solely for design, simulation, implementation and
# creation of design files limited to Xilinx devices or technologies.
# Use with non-Xilinx devices or technologies is expressly prohibited
# and immediately terminates your license unless covered by a separate
# agreement.
#
# Xilinx is providing this design, code, or information "as is" solely
# for use in developing programs and solutions for Xilinx devices.  By
# providing this design, code, or information as one possible
# implementation of this feature, application or standard, Xilinx is
# making no representation that this implementation is free from any
# claims of infringement.  You are responsible for obtaining any rights
# you may require for your implementation.  Xilinx expressly disclaims
# any warranty whatsoever with respect to the adequacy of the
# implementation, including but not limited to warranties of
# merchantability or fitness for a particular purpose.
#
# Xilinx products are not intended for use in life support appliances,
# devices, or systems.  Use in such applications is expressly prohibited.
#
# Any modifications that are made to the source code are done at the user's
# sole risk and will be unsupported.
#
# This copyright and support notice must be retained as part of this
# text at all times.  (c) Copyright 1995-2013 Xilinx, Inc.  All rights
# reserved.
#-----------------------------------------------------------------

set existingipslist [get_ips]
if {[lsearch $existingipslist basic_dmt_fifo_generator_v12_0_0] < 0} {
create_ip -name fifo_generator -version 12.0 -vendor xilinx.com -library ip -module_name basic_dmt_fifo_generator_v12_0_0
set params_list [list]
lappend params_list CONFIG.Component_Name {basic_dmt_fifo_generator_v12_0_0}
lappend params_list CONFIG.almost_empty_flag {false}
lappend params_list CONFIG.almost_full_flag {false}
lappend params_list CONFIG.data_count {true}
lappend params_list CONFIG.data_count_width {7}
lappend params_list CONFIG.disable_timing_violations {false}
lappend params_list CONFIG.dout_reset_value {0}
lappend params_list CONFIG.enable_ecc {false}
lappend params_list CONFIG.enable_reset_synchronization {true}
lappend params_list CONFIG.fifo_implementation {Common_Clock_Block_RAM}
lappend params_list CONFIG.full_flags_reset_value {0}
lappend params_list CONFIG.inject_dbit_error {false}
lappend params_list CONFIG.inject_sbit_error {false}
lappend params_list CONFIG.input_data_width {9}
lappend params_list CONFIG.input_depth {128}
lappend params_list CONFIG.output_data_width {9}
lappend params_list CONFIG.output_depth {128}
lappend params_list CONFIG.overflow_flag {false}
lappend params_list CONFIG.overflow_sense {Active_High}
lappend params_list CONFIG.performance_options {Standard_FIFO}
lappend params_list CONFIG.programmable_empty_type {No_Programmable_Empty_Threshold}
lappend params_list CONFIG.programmable_full_type {No_Programmable_Full_Threshold}
lappend params_list CONFIG.reset_pin {false}
lappend params_list CONFIG.reset_type {Asynchronous_Reset}
lappend params_list CONFIG.underflow_flag {false}
lappend params_list CONFIG.underflow_sense {Active_High}
lappend params_list CONFIG.use_dout_reset {true}
lappend params_list CONFIG.use_embedded_registers {false}
lappend params_list CONFIG.use_extra_logic {false}
lappend params_list CONFIG.valid_flag {false}
lappend params_list CONFIG.valid_sense {Active_High}
lappend params_list CONFIG.write_acknowledge_flag {false}
lappend params_list CONFIG.write_acknowledge_sense {Active_High}

set_property -dict $params_list [get_ips basic_dmt_fifo_generator_v12_0_0]
}


set existingipslist [get_ips]
if {[lsearch $existingipslist basic_dmt_fifo_generator_v12_0_1] < 0} {
create_ip -name fifo_generator -version 12.0 -vendor xilinx.com -library ip -module_name basic_dmt_fifo_generator_v12_0_1
set params_list [list]
lappend params_list CONFIG.Component_Name {basic_dmt_fifo_generator_v12_0_1}
lappend params_list CONFIG.almost_empty_flag {false}
lappend params_list CONFIG.almost_full_flag {false}
lappend params_list CONFIG.data_count {false}
lappend params_list CONFIG.data_count_width {7}
lappend params_list CONFIG.disable_timing_violations {false}
lappend params_list CONFIG.dout_reset_value {0}
lappend params_list CONFIG.enable_ecc {false}
lappend params_list CONFIG.enable_reset_synchronization {true}
lappend params_list CONFIG.fifo_implementation {Common_Clock_Block_RAM}
lappend params_list CONFIG.full_flags_reset_value {0}
lappend params_list CONFIG.inject_dbit_error {false}
lappend params_list CONFIG.inject_sbit_error {false}
lappend params_list CONFIG.input_data_width {9}
lappend params_list CONFIG.input_depth {128}
lappend params_list CONFIG.output_data_width {9}
lappend params_list CONFIG.output_depth {128}
lappend params_list CONFIG.overflow_flag {false}
lappend params_list CONFIG.overflow_sense {Active_High}
lappend params_list CONFIG.performance_options {Standard_FIFO}
lappend params_list CONFIG.programmable_empty_type {No_Programmable_Empty_Threshold}
lappend params_list CONFIG.programmable_full_type {No_Programmable_Full_Threshold}
lappend params_list CONFIG.reset_pin {false}
lappend params_list CONFIG.reset_type {Asynchronous_Reset}
lappend params_list CONFIG.underflow_flag {false}
lappend params_list CONFIG.underflow_sense {Active_High}
lappend params_list CONFIG.use_dout_reset {true}
lappend params_list CONFIG.use_embedded_registers {false}
lappend params_list CONFIG.use_extra_logic {false}
lappend params_list CONFIG.valid_flag {false}
lappend params_list CONFIG.valid_sense {Active_High}
lappend params_list CONFIG.write_acknowledge_flag {false}
lappend params_list CONFIG.write_acknowledge_sense {Active_High}

set_property -dict $params_list [get_ips basic_dmt_fifo_generator_v12_0_1]
}


set existingipslist [get_ips]
if {[lsearch $existingipslist basic_dmt_c_counter_binary_v12_0_0] < 0} {
create_ip -name c_counter_binary -version 12.0 -vendor xilinx.com -library ip -module_name basic_dmt_c_counter_binary_v12_0_0
set params_list [list]
lappend params_list CONFIG.Component_Name {basic_dmt_c_counter_binary_v12_0_0}
lappend params_list CONFIG.ainit_value {0}
lappend params_list CONFIG.ce {true}
lappend params_list CONFIG.count_mode {UP}
lappend params_list CONFIG.fb_latency {0}
lappend params_list CONFIG.final_count_value {1}
lappend params_list CONFIG.implementation {Fabric}
lappend params_list CONFIG.increment_value {1}
lappend params_list CONFIG.latency {1}
lappend params_list CONFIG.load {false}
lappend params_list CONFIG.output_width {5}
lappend params_list CONFIG.restrict_count {false}
lappend params_list CONFIG.sclr {false}
lappend params_list CONFIG.sinit {true}
lappend params_list CONFIG.sinit_value {0}
lappend params_list CONFIG.sset {false}
lappend params_list CONFIG.sync_ce_priority {Sync_Overrides_CE}
lappend params_list CONFIG.sync_threshold_output {false}
lappend params_list CONFIG.syncctrlpriority {Reset_Overrides_Set}

set_property -dict $params_list [get_ips basic_dmt_c_counter_binary_v12_0_0]
}


set existingipslist [get_ips]
if {[lsearch $existingipslist basic_dmt_fifo_generator_v12_0_2] < 0} {
create_ip -name fifo_generator -version 12.0 -vendor xilinx.com -library ip -module_name basic_dmt_fifo_generator_v12_0_2
set params_list [list]
lappend params_list CONFIG.Component_Name {basic_dmt_fifo_generator_v12_0_2}
lappend params_list CONFIG.almost_empty_flag {false}
lappend params_list CONFIG.almost_full_flag {false}
lappend params_list CONFIG.data_count {false}
lappend params_list CONFIG.data_count_width {5}
lappend params_list CONFIG.disable_timing_violations {false}
lappend params_list CONFIG.dout_reset_value {0}
lappend params_list CONFIG.enable_ecc {false}
lappend params_list CONFIG.enable_reset_synchronization {true}
lappend params_list CONFIG.fifo_implementation {Common_Clock_Block_RAM}
lappend params_list CONFIG.full_flags_reset_value {0}
lappend params_list CONFIG.inject_dbit_error {false}
lappend params_list CONFIG.inject_sbit_error {false}
lappend params_list CONFIG.input_data_width {9}
lappend params_list CONFIG.input_depth {32}
lappend params_list CONFIG.output_data_width {9}
lappend params_list CONFIG.output_depth {32}
lappend params_list CONFIG.overflow_flag {false}
lappend params_list CONFIG.overflow_sense {Active_High}
lappend params_list CONFIG.performance_options {Standard_FIFO}
lappend params_list CONFIG.programmable_empty_type {No_Programmable_Empty_Threshold}
lappend params_list CONFIG.programmable_full_type {No_Programmable_Full_Threshold}
lappend params_list CONFIG.reset_pin {false}
lappend params_list CONFIG.reset_type {Asynchronous_Reset}
lappend params_list CONFIG.underflow_flag {false}
lappend params_list CONFIG.underflow_sense {Active_High}
lappend params_list CONFIG.use_dout_reset {true}
lappend params_list CONFIG.use_embedded_registers {false}
lappend params_list CONFIG.use_extra_logic {false}
lappend params_list CONFIG.valid_flag {false}
lappend params_list CONFIG.valid_sense {Active_High}
lappend params_list CONFIG.write_acknowledge_flag {false}
lappend params_list CONFIG.write_acknowledge_sense {Active_High}

set_property -dict $params_list [get_ips basic_dmt_fifo_generator_v12_0_2]
}


set existingipslist [get_ips]
if {[lsearch $existingipslist basic_dmt_fifo_generator_v12_0_3] < 0} {
create_ip -name fifo_generator -version 12.0 -vendor xilinx.com -library ip -module_name basic_dmt_fifo_generator_v12_0_3
set params_list [list]
lappend params_list CONFIG.Component_Name {basic_dmt_fifo_generator_v12_0_3}
lappend params_list CONFIG.almost_empty_flag {false}
lappend params_list CONFIG.almost_full_flag {false}
lappend params_list CONFIG.data_count {true}
lappend params_list CONFIG.data_count_width {5}
lappend params_list CONFIG.disable_timing_violations {false}
lappend params_list CONFIG.dout_reset_value {0}
lappend params_list CONFIG.enable_ecc {false}
lappend params_list CONFIG.enable_reset_synchronization {true}
lappend params_list CONFIG.fifo_implementation {Common_Clock_Block_RAM}
lappend params_list CONFIG.full_flags_reset_value {0}
lappend params_list CONFIG.inject_dbit_error {false}
lappend params_list CONFIG.inject_sbit_error {false}
lappend params_list CONFIG.input_data_width {9}
lappend params_list CONFIG.input_depth {32}
lappend params_list CONFIG.output_data_width {9}
lappend params_list CONFIG.output_depth {32}
lappend params_list CONFIG.overflow_flag {false}
lappend params_list CONFIG.overflow_sense {Active_High}
lappend params_list CONFIG.performance_options {Standard_FIFO}
lappend params_list CONFIG.programmable_empty_type {No_Programmable_Empty_Threshold}
lappend params_list CONFIG.programmable_full_type {No_Programmable_Full_Threshold}
lappend params_list CONFIG.reset_pin {false}
lappend params_list CONFIG.reset_type {Asynchronous_Reset}
lappend params_list CONFIG.underflow_flag {false}
lappend params_list CONFIG.underflow_sense {Active_High}
lappend params_list CONFIG.use_dout_reset {true}
lappend params_list CONFIG.use_embedded_registers {false}
lappend params_list CONFIG.use_extra_logic {false}
lappend params_list CONFIG.valid_flag {false}
lappend params_list CONFIG.valid_sense {Active_High}
lappend params_list CONFIG.write_acknowledge_flag {false}
lappend params_list CONFIG.write_acknowledge_sense {Active_High}

set_property -dict $params_list [get_ips basic_dmt_fifo_generator_v12_0_3]
}


set existingipslist [get_ips]
if {[lsearch $existingipslist basic_dmt_xfft_v9_0_0] < 0} {
create_ip -name xfft -version 9.0 -vendor xilinx.com -library ip -module_name basic_dmt_xfft_v9_0_0
set params_list [list]
lappend params_list CONFIG.Component_Name {basic_dmt_xfft_v9_0_0}
lappend params_list CONFIG.aclken {true}
lappend params_list CONFIG.aresetn {false}
lappend params_list CONFIG.butterfly_type {use_xtremedsp_slices}
lappend params_list CONFIG.channels {1}
lappend params_list CONFIG.complex_mult_type {use_mults_resources}
lappend params_list CONFIG.cyclic_prefix_insertion {false}
lappend params_list CONFIG.data_format {fixed_point}
lappend params_list CONFIG.implementation_options {pipelined_streaming_io}
lappend params_list CONFIG.input_width {9}
lappend params_list CONFIG.memory_options_data {block_ram}
lappend params_list CONFIG.memory_options_hybrid {false}
lappend params_list CONFIG.memory_options_phase_factors {block_ram}
lappend params_list CONFIG.memory_options_reorder {block_ram}
lappend params_list CONFIG.number_of_stages_using_block_ram_for_data_and_phase_factors {0}
lappend params_list CONFIG.output_ordering {natural_order}
lappend params_list CONFIG.ovflo {false}
lappend params_list CONFIG.phase_factor_width {12}
lappend params_list CONFIG.rounding_modes {convergent_rounding}
lappend params_list CONFIG.run_time_configurable_transform_length {false}
lappend params_list CONFIG.scaling_options {unscaled}
lappend params_list CONFIG.target_clock_frequency {250}
lappend params_list CONFIG.target_data_throughput {50}
lappend params_list CONFIG.throttle_scheme {nonrealtime}
lappend params_list CONFIG.transform_length {32}
lappend params_list CONFIG.xk_index {true}

set_property -dict $params_list [get_ips basic_dmt_xfft_v9_0_0]
}


set existingipslist [get_ips]
if {[lsearch $existingipslist basic_dmt_fifo_generator_v12_0_4] < 0} {
create_ip -name fifo_generator -version 12.0 -vendor xilinx.com -library ip -module_name basic_dmt_fifo_generator_v12_0_4
set params_list [list]
lappend params_list CONFIG.Component_Name {basic_dmt_fifo_generator_v12_0_4}
lappend params_list CONFIG.almost_empty_flag {false}
lappend params_list CONFIG.almost_full_flag {false}
lappend params_list CONFIG.data_count {true}
lappend params_list CONFIG.data_count_width {7}
lappend params_list CONFIG.disable_timing_violations {false}
lappend params_list CONFIG.dout_reset_value {0}
lappend params_list CONFIG.enable_ecc {false}
lappend params_list CONFIG.enable_reset_synchronization {true}
lappend params_list CONFIG.fifo_implementation {Common_Clock_Block_RAM}
lappend params_list CONFIG.full_flags_reset_value {0}
lappend params_list CONFIG.inject_dbit_error {false}
lappend params_list CONFIG.inject_sbit_error {false}
lappend params_list CONFIG.input_data_width {1}
lappend params_list CONFIG.input_depth {128}
lappend params_list CONFIG.output_data_width {1}
lappend params_list CONFIG.output_depth {128}
lappend params_list CONFIG.overflow_flag {false}
lappend params_list CONFIG.overflow_sense {Active_High}
lappend params_list CONFIG.performance_options {Standard_FIFO}
lappend params_list CONFIG.programmable_empty_type {No_Programmable_Empty_Threshold}
lappend params_list CONFIG.programmable_full_type {No_Programmable_Full_Threshold}
lappend params_list CONFIG.reset_pin {false}
lappend params_list CONFIG.reset_type {Asynchronous_Reset}
lappend params_list CONFIG.underflow_flag {false}
lappend params_list CONFIG.underflow_sense {Active_High}
lappend params_list CONFIG.use_dout_reset {true}
lappend params_list CONFIG.use_embedded_registers {false}
lappend params_list CONFIG.use_extra_logic {false}
lappend params_list CONFIG.valid_flag {false}
lappend params_list CONFIG.valid_sense {Active_High}
lappend params_list CONFIG.write_acknowledge_flag {false}
lappend params_list CONFIG.write_acknowledge_sense {Active_High}

set_property -dict $params_list [get_ips basic_dmt_fifo_generator_v12_0_4]
}


set existingipslist [get_ips]
if {[lsearch $existingipslist basic_dmt_fifo_generator_v12_0_5] < 0} {
create_ip -name fifo_generator -version 12.0 -vendor xilinx.com -library ip -module_name basic_dmt_fifo_generator_v12_0_5
set params_list [list]
lappend params_list CONFIG.Component_Name {basic_dmt_fifo_generator_v12_0_5}
lappend params_list CONFIG.almost_empty_flag {false}
lappend params_list CONFIG.almost_full_flag {false}
lappend params_list CONFIG.data_count {true}
lappend params_list CONFIG.data_count_width {4}
lappend params_list CONFIG.disable_timing_violations {false}
lappend params_list CONFIG.dout_reset_value {0}
lappend params_list CONFIG.enable_ecc {false}
lappend params_list CONFIG.enable_reset_synchronization {true}
lappend params_list CONFIG.fifo_implementation {Common_Clock_Block_RAM}
lappend params_list CONFIG.full_flags_reset_value {0}
lappend params_list CONFIG.inject_dbit_error {false}
lappend params_list CONFIG.inject_sbit_error {false}
lappend params_list CONFIG.input_data_width {9}
lappend params_list CONFIG.input_depth {16}
lappend params_list CONFIG.output_data_width {9}
lappend params_list CONFIG.output_depth {16}
lappend params_list CONFIG.overflow_flag {false}
lappend params_list CONFIG.overflow_sense {Active_High}
lappend params_list CONFIG.performance_options {Standard_FIFO}
lappend params_list CONFIG.programmable_empty_type {No_Programmable_Empty_Threshold}
lappend params_list CONFIG.programmable_full_type {No_Programmable_Full_Threshold}
lappend params_list CONFIG.reset_pin {false}
lappend params_list CONFIG.reset_type {Asynchronous_Reset}
lappend params_list CONFIG.underflow_flag {false}
lappend params_list CONFIG.underflow_sense {Active_High}
lappend params_list CONFIG.use_dout_reset {true}
lappend params_list CONFIG.use_embedded_registers {false}
lappend params_list CONFIG.use_extra_logic {false}
lappend params_list CONFIG.valid_flag {false}
lappend params_list CONFIG.valid_sense {Active_High}
lappend params_list CONFIG.write_acknowledge_flag {false}
lappend params_list CONFIG.write_acknowledge_sense {Active_High}

set_property -dict $params_list [get_ips basic_dmt_fifo_generator_v12_0_5]
}


validate_ip [get_ips]
