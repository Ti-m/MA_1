@echo off
set xv_path=C:\\Xilinx\\Vivado\\2014.4\\bin
call %xv_path%/xelab  -wto 576aecf68fd942139765ebfa6631fd86 -m64 --debug typical --relax -L xil_defaultlib -L secureip --snapshot basic_dmt_tb_func_impl xil_defaultlib.basic_dmt_tb -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
