@echo off
set xv_path=C:\\Xilinx\\Vivado\\2014.4\\bin
call %xv_path%/xelab  -wto c4c5566747704013a98c52ec0fd0354c -m64 --debug typical --relax --include "../../../CLK_WIZ_SIMU.srcs/sources_1/ipshared/xilinx.com/processing_system7_bfm_v2_0/e69044ca/hdl" -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot design_1_wrapper_behav xil_defaultlib.design_1_wrapper xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
