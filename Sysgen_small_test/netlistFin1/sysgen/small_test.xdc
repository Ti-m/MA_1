set rateCesmall_test4 small_test_default_clock_driver/clockdriver_x1/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellssmall_test4 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCesmall_test4/Q]] IS_ENABLE]]
set rateCesmall_test5 small_test_default_clock_driver/clockdriver_x0/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellssmall_test5 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCesmall_test5/Q]] IS_ENABLE]]
set rateCesmall_test8 small_test_default_clock_driver/clockdriver/pipelined_ce.ce_pipeline[1].ce_reg/latency_gt_0.fd_array[1].reg_comp/fd_prim_array[0].bit_is_0.fdre_comp
set rateCellssmall_test8 [get_cells -of [filter [all_fanout -flat -endpoints [get_pins $rateCesmall_test8/Q]] IS_ENABLE]]
set_multicycle_path -from $rateCellssmall_test4 -to $rateCellssmall_test4 -setup 4
set_multicycle_path -from $rateCellssmall_test4 -to $rateCellssmall_test4 -hold 3
set_multicycle_path -from $rateCellssmall_test4 -to $rateCellssmall_test5 -setup 1
set_multicycle_path -from $rateCellssmall_test4 -to $rateCellssmall_test5 -hold 0
set_multicycle_path -from $rateCellssmall_test4 -to $rateCellssmall_test8 -setup 4
set_multicycle_path -from $rateCellssmall_test4 -to $rateCellssmall_test8 -hold 3
set_multicycle_path -from $rateCellssmall_test5 -to $rateCellssmall_test4 -setup 1
set_multicycle_path -from $rateCellssmall_test5 -to $rateCellssmall_test4 -hold 0
set_multicycle_path -from $rateCellssmall_test5 -to $rateCellssmall_test5 -setup 5
set_multicycle_path -from $rateCellssmall_test5 -to $rateCellssmall_test5 -hold 4
set_multicycle_path -from $rateCellssmall_test5 -to $rateCellssmall_test8 -setup 1
set_multicycle_path -from $rateCellssmall_test5 -to $rateCellssmall_test8 -hold 0
set_multicycle_path -from $rateCellssmall_test8 -to $rateCellssmall_test4 -setup 4
set_multicycle_path -from $rateCellssmall_test8 -to $rateCellssmall_test4 -hold 3
set_multicycle_path -from $rateCellssmall_test8 -to $rateCellssmall_test5 -setup 1
set_multicycle_path -from $rateCellssmall_test8 -to $rateCellssmall_test5 -hold 0
set_multicycle_path -from $rateCellssmall_test8 -to $rateCellssmall_test8 -setup 8
set_multicycle_path -from $rateCellssmall_test8 -to $rateCellssmall_test8 -hold 7
