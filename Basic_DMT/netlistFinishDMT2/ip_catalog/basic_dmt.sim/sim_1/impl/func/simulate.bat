@echo off
set xv_path=C:\\Xilinx\\Vivado\\2014.4\\bin
call %xv_path%/xsim basic_dmt_tb_func_impl -key {Post-Implementation:sim_1:Functional:basic_dmt_tb} -tclbatch basic_dmt_tb.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
