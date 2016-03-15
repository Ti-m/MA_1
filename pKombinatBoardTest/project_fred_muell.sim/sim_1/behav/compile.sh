#!/bin/sh
# Vivado(TM)
# compile.sh: Vivado-generated Script for launching XSim application
# Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
# 
if [ -z "$PATH" ]; then
  PATH=%XILINX%\lib\%PLATFORM%;%XILINX%\bin\%PLATFORM%:C:/Xilinx/SDK/2014.2/bin;C:/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/nt;C:/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/nt
else
  PATH=%XILINX%\lib\%PLATFORM%;%XILINX%\bin\%PLATFORM%:C:/Xilinx/SDK/2014.2/bin;C:/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/nt;C:/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/nt:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=:
else
  LD_LIBRARY_PATH=::$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

#
# Setup env for Xilinx simulation libraries
#
XILINX_PLANAHEAD=C:/Xilinx/Vivado/2014.2
export XILINX_PLANAHEAD
ExecStep()
{
   "$@"
   RETVAL=$?
   if [ $RETVAL -ne 0 ]
   then
       exit $RETVAL
   fi
}

ExecStep xelab -m32 --debug typical --relax -L xil_defaultlib -L secureip --snapshot toggle_behav --prj D:/vivado_projects/project_fred_muell/project_fred_muell.sim/sim_1/behav/toggle.prj   xil_defaultlib.toggle
