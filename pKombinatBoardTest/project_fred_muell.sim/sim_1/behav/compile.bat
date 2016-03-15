@echo off
rem  Vivado(TM)
rem  compile.bat: a Vivado-generated XSim simulation Script
rem  Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.

set PATH=%XILINX%\lib\%PLATFORM%;%XILINX%\bin\%PLATFORM%;C:/Xilinx/SDK/2014.2/bin;C:/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/nt;C:/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/nt;C:/Xilinx/Vivado/2014.2/bin;%PATH%
set XILINX_PLANAHEAD=C:/Xilinx/Vivado/2014.2

xelab -m32 --debug typical --relax -L xil_defaultlib -L secureip --snapshot toggle_behav --prj D:/vivado_projects/project_fred_muell/project_fred_muell.sim/sim_1/behav/toggle.prj   xil_defaultlib.toggle
if errorlevel 1 (
   cmd /c exit /b %errorlevel%
)
