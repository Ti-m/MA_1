proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
set_msg_config -id {Synth 8-256} -limit 10000
set_msg_config -id {Synth 8-638} -limit 10000
set_msg_config  -id {BD 41-759}  -new_severity {INFO} 
set_msg_config  -id {BD 41-759}  -new_severity {CRITICAL WARNING} 

start_step init_design
set rc [catch {
  create_msg_db init_design.pb
  set_param gui.test TreeTableDev
  debug::add_scope template.lib 1
  create_project -in_memory -part xc7z020clg400-1
  set_property board_part em.avnet.com:microzed_7020:part0:1.0 [current_project]
  set_property design_mode GateLvl [current_fileset]
  set_property webtalk.parent_dir D:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.cache/wt [current_project]
  set_property parent.project_path D:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.xpr [current_project]
  set_property ip_repo_paths {
  d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.cache/ip
  D:/MA_1/Basic_DMT/netlistFinishDMT2/ip
} [current_project]
  set_property ip_output_repo d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.cache/ip [current_project]
  add_files -quiet D:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.runs/synth_1/basic_dmt_bd_wrapper.dcp
  add_files -quiet D:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.runs/basic_dmt_0_synth_1/basic_dmt_0.dcp
  set_property netlist_only true [get_files D:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.runs/basic_dmt_0_synth_1/basic_dmt_0.dcp]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_0 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_0/basic_dmt_fifo_generator_v12_0_0/basic_dmt_fifo_generator_v12_0_0.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_0/basic_dmt_fifo_generator_v12_0_0/basic_dmt_fifo_generator_v12_0_0.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_1 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_1/basic_dmt_fifo_generator_v12_0_1/basic_dmt_fifo_generator_v12_0_1.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_1/basic_dmt_fifo_generator_v12_0_1/basic_dmt_fifo_generator_v12_0_1.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_2 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_2/basic_dmt_fifo_generator_v12_0_2/basic_dmt_fifo_generator_v12_0_2.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_2/basic_dmt_fifo_generator_v12_0_2/basic_dmt_fifo_generator_v12_0_2.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_3 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_3/basic_dmt_fifo_generator_v12_0_3/basic_dmt_fifo_generator_v12_0_3.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_3/basic_dmt_fifo_generator_v12_0_3/basic_dmt_fifo_generator_v12_0_3.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_4 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_4/basic_dmt_fifo_generator_v12_0_4/basic_dmt_fifo_generator_v12_0_4.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/bd/basic_dmt_bd/ip/basic_dmt_bd_basic_dmt_1_0/basic_dmt_fifo_generator_v12_0_4/basic_dmt_fifo_generator_v12_0_4/basic_dmt_fifo_generator_v12_0_4.xdc]
  read_xdc -ref basic_dmt_bd_basic_dmt_1_0 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ipshared/User_Company/basic_dmt_v8_41210/e13c4507/constrs/basic_dmt_clock.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ipshared/User_Company/basic_dmt_v8_41210/e13c4507/constrs/basic_dmt_clock.xdc]
  read_xdc -ref basic_dmt_bd_basic_dmt_1_0 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ipshared/User_Company/basic_dmt_v8_41210/e13c4507/constrs/basic_dmt.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ipshared/User_Company/basic_dmt_v8_41210/e13c4507/constrs/basic_dmt.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_0 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_0/basic_dmt_fifo_generator_v12_0_0/basic_dmt_fifo_generator_v12_0_0.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_0/basic_dmt_fifo_generator_v12_0_0/basic_dmt_fifo_generator_v12_0_0.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_1 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_1/basic_dmt_fifo_generator_v12_0_1/basic_dmt_fifo_generator_v12_0_1.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_1/basic_dmt_fifo_generator_v12_0_1/basic_dmt_fifo_generator_v12_0_1.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_2 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_2/basic_dmt_fifo_generator_v12_0_2/basic_dmt_fifo_generator_v12_0_2.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_2/basic_dmt_fifo_generator_v12_0_2/basic_dmt_fifo_generator_v12_0_2.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_3 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_3/basic_dmt_fifo_generator_v12_0_3/basic_dmt_fifo_generator_v12_0_3.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_3/basic_dmt_fifo_generator_v12_0_3/basic_dmt_fifo_generator_v12_0_3.xdc]
  read_xdc -ref basic_dmt_fifo_generator_v12_0_4 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_4/basic_dmt_fifo_generator_v12_0_4/basic_dmt_fifo_generator_v12_0_4.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/basic_dmt_fifo_generator_v12_0_4/basic_dmt_fifo_generator_v12_0_4/basic_dmt_fifo_generator_v12_0_4.xdc]
  read_xdc -ref basic_dmt_0 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/constrs/basic_dmt_clock.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/constrs/basic_dmt_clock.xdc]
  read_xdc -ref basic_dmt_0 -cells U0 d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/constrs/basic_dmt.xdc
  set_property processing_order EARLY [get_files d:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/sources_1/ip/basic_dmt_0/constrs/basic_dmt.xdc]
  read_xdc D:/MA_1/Basic_DMT/netlistFinishDMT2/ip_catalog/basic_dmt.srcs/constrs_1/new/own.xdc
  link_design -top basic_dmt_bd_wrapper -part xc7z020clg400-1
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
}

start_step opt_design
set rc [catch {
  create_msg_db opt_design.pb
  catch {write_debug_probes -quiet -force debug_nets}
  opt_design 
  write_checkpoint -force basic_dmt_bd_wrapper_opt.dcp
  catch {report_drc -file basic_dmt_bd_wrapper_drc_opted.rpt}
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
}

start_step place_design
set rc [catch {
  create_msg_db place_design.pb
  place_design 
  write_checkpoint -force basic_dmt_bd_wrapper_placed.dcp
  catch { report_io -file basic_dmt_bd_wrapper_io_placed.rpt }
  catch { report_clock_utilization -file basic_dmt_bd_wrapper_clock_utilization_placed.rpt }
  catch { report_utilization -file basic_dmt_bd_wrapper_utilization_placed.rpt -pb basic_dmt_bd_wrapper_utilization_placed.pb }
  catch { report_control_sets -verbose -file basic_dmt_bd_wrapper_control_sets_placed.rpt }
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
}

start_step route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force basic_dmt_bd_wrapper_routed.dcp
  catch { report_drc -file basic_dmt_bd_wrapper_drc_routed.rpt -pb basic_dmt_bd_wrapper_drc_routed.pb }
  catch { report_timing_summary -warn_on_violation -max_paths 10 -file basic_dmt_bd_wrapper_timing_summary_routed.rpt -rpx basic_dmt_bd_wrapper_timing_summary_routed.rpx }
  catch { report_power -file basic_dmt_bd_wrapper_power_routed.rpt -pb basic_dmt_bd_wrapper_power_summary_routed.pb }
  catch { report_route_status -file basic_dmt_bd_wrapper_route_status.rpt -pb basic_dmt_bd_wrapper_route_status.pb }
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
}

