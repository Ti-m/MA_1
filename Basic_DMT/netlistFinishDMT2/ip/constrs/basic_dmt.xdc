set rateCebasic_dmt2 basic_dmt_default_clock_driver/clockdriver_x6/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellsbasic_dmt2 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCebasic_dmt2/Q]] IS_ENABLE]]
set rateCebasic_dmt4 basic_dmt_default_clock_driver/clockdriver_x5/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellsbasic_dmt4 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCebasic_dmt4/Q]] IS_ENABLE]]
set rateCebasic_dmt5 basic_dmt_default_clock_driver/clockdriver_x4/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellsbasic_dmt5 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCebasic_dmt5/Q]] IS_ENABLE]]
set rateCebasic_dmt7 basic_dmt_default_clock_driver/clockdriver_x3/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellsbasic_dmt7 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCebasic_dmt7/Q]] IS_ENABLE]]
set rateCebasic_dmt16 basic_dmt_default_clock_driver/clockdriver_x2/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellsbasic_dmt16 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCebasic_dmt16/Q]] IS_ENABLE]]
set rateCebasic_dmt64 basic_dmt_default_clock_driver/clockdriver_x1/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellsbasic_dmt64 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCebasic_dmt64/Q]] IS_ENABLE]]
set rateCebasic_dmt128 basic_dmt_default_clock_driver/clockdriver_x0/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellsbasic_dmt128 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCebasic_dmt128/Q]] IS_ENABLE]]
set rateCebasic_dmt256 basic_dmt_default_clock_driver/clockdriver/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellsbasic_dmt256 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCebasic_dmt256/Q]] IS_ENABLE]]
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt2 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt2 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt4 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt4 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt5 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt5 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt7 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt7 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt16 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt16 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt64 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt64 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt128 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt128 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt256 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt2 -to $rateCellsbasic_dmt256 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt2 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt2 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt4 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt4 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt5 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt5 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt7 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt7 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt16 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt16 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt64 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt64 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt128 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt128 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt256 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt4 -to $rateCellsbasic_dmt256 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt2 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt2 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt4 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt4 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt5 -setup 5
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt5 -hold 4
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt7 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt7 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt16 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt16 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt64 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt64 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt128 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt128 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt256 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt5 -to $rateCellsbasic_dmt256 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt2 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt2 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt4 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt4 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt5 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt5 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt7 -setup 7
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt7 -hold 6
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt16 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt16 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt64 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt64 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt128 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt128 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt256 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt7 -to $rateCellsbasic_dmt256 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt2 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt2 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt4 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt4 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt5 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt5 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt7 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt7 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt16 -setup 16
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt16 -hold 15
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt64 -setup 16
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt64 -hold 15
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt128 -setup 16
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt128 -hold 15
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt256 -setup 16
set_multicycle_path -from $rateCellsbasic_dmt16 -to $rateCellsbasic_dmt256 -hold 15
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt2 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt2 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt4 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt4 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt5 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt5 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt7 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt7 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt16 -setup 16
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt16 -hold 15
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt64 -setup 64
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt64 -hold 63
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt128 -setup 64
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt128 -hold 63
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt256 -setup 64
set_multicycle_path -from $rateCellsbasic_dmt64 -to $rateCellsbasic_dmt256 -hold 63
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt2 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt2 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt4 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt4 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt5 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt5 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt7 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt7 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt16 -setup 16
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt16 -hold 15
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt64 -setup 64
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt64 -hold 63
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt128 -setup 128
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt128 -hold 127
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt256 -setup 128
set_multicycle_path -from $rateCellsbasic_dmt128 -to $rateCellsbasic_dmt256 -hold 127
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt2 -setup 2
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt2 -hold 1
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt4 -setup 4
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt4 -hold 3
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt5 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt5 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt7 -setup 1
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt7 -hold 0
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt16 -setup 16
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt16 -hold 15
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt64 -setup 64
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt64 -hold 63
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt128 -setup 128
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt128 -hold 127
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt256 -setup 256
set_multicycle_path -from $rateCellsbasic_dmt256 -to $rateCellsbasic_dmt256 -hold 255
