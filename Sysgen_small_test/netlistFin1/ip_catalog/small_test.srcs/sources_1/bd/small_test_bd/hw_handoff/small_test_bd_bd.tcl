
################################################################
# This is a generated script based on design: small_test_bd
#
# Though there are limitations about the generated script,
# the main purpose of this utility is to make learning
# IP Integrator Tcl commands easier.
################################################################

################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2014.4
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   puts "ERROR: This script was generated using Vivado <$scripts_vivado_version> and is being run in <$current_vivado_version> of Vivado. Please run the script in Vivado <$scripts_vivado_version> then open the design in Vivado <$current_vivado_version>. Upgrade the design by running \"Tools => Report => Report IP Status...\", then run write_bd_tcl to create an updated script."

   return 1
}

################################################################
# START
################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source small_test_bd_script.tcl

# If you do not already have a project created,
# you can create a project using the following command:
#    create_project project_1 myproj -part xc7z020clg400-1
#    set_property BOARD_PART em.avnet.com:microzed_7020:part0:1.0 [current_project]


# CHANGE DESIGN NAME HERE
set design_name small_test_bd

# If you do not already have an existing IP Integrator design open,
# you can create a design using the following command:
#    create_bd_design $design_name

# CHECKING IF PROJECT EXISTS
if { [get_projects -quiet] eq "" } {
   puts "ERROR: Please open or create a project!"
   return 1
}


# Creating design if needed
set errMsg ""
set nRet 0

set cur_design [current_bd_design -quiet]
set list_cells [get_bd_cells -quiet]

if { ${design_name} eq "" } {
   # USE CASES:
   #    1) Design_name not set

   set errMsg "ERROR: Please set the variable <design_name> to a non-empty value."
   set nRet 1

} elseif { ${cur_design} ne "" && ${list_cells} eq "" } {
   # USE CASES:
   #    2): Current design opened AND is empty AND names same.
   #    3): Current design opened AND is empty AND names diff; design_name NOT in project.
   #    4): Current design opened AND is empty AND names diff; design_name exists in project.

   if { $cur_design ne $design_name } {
      puts "INFO: Changing value of <design_name> from <$design_name> to <$cur_design> since current design is empty."
      set design_name [get_property NAME $cur_design]
   }
   puts "INFO: Constructing design in IPI design <$cur_design>..."

} elseif { ${cur_design} ne "" && $list_cells ne "" && $cur_design eq $design_name } {
   # USE CASES:
   #    5) Current design opened AND has components AND same names.

   set errMsg "ERROR: Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 1
} elseif { [get_files -quiet ${design_name}.bd] ne "" } {
   # USE CASES: 
   #    6) Current opened design, has components, but diff names, design_name exists in project.
   #    7) No opened design, design_name exists in project.

   set errMsg "ERROR: Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 2

} else {
   # USE CASES:
   #    8) No opened design, design_name not in project.
   #    9) Current opened design, has components, but diff names, design_name not in project.

   puts "INFO: Currently there is no design <$design_name> in project, so creating one..."

   create_bd_design $design_name

   puts "INFO: Making design <$design_name> as current_bd_design."
   current_bd_design $design_name

}

puts "INFO: Currently the variable <design_name> is equal to \"$design_name\"."

if { $nRet != 0 } {
   puts $errMsg
   return $nRet
}

##################################################################
# DESIGN PROCs
##################################################################



# Procedure to create entire design; Provide argument to make
# procedure reusable. If parentCell is "", will use root.
proc create_root_design { parentCell } {

  if { $parentCell eq "" } {
     set parentCell [get_bd_cells /]
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     puts "ERROR: Unable to find parent cell <$parentCell>!"
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     puts "ERROR: Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj


  # Create interface ports

  # Create ports
  set clk [ create_bd_port -dir I -type clk clk ]
  set inp_recv_im1 [ create_bd_port -dir I -from 15 -to 0 -type data inp_recv_im1 ]
  set inp_recv_re1 [ create_bd_port -dir I -from 15 -to 0 -type data inp_recv_re1 ]
  set inp_trans [ create_bd_port -dir I -from 0 -to 0 -type data inp_trans ]
  set out_recv [ create_bd_port -dir O -from 0 -to 0 -type data out_recv ]
  set out_trans_im [ create_bd_port -dir O -from 15 -to 0 -type data out_trans_im ]
  set out_trans_re [ create_bd_port -dir O -from 15 -to 0 -type data out_trans_re ]
  set test_pin [ create_bd_port -dir O -from 0 -to 0 -type data test_pin ]

  # Create instance: small_test_1, and set properties
  set small_test_1 [ create_bd_cell -type ip -vlnv User_Company:SysGen:small_test:1.1 small_test_1 ]

  # Create port connections
  connect_bd_net -net clk_1 [get_bd_ports clk] [get_bd_pins small_test_1/clk]
  connect_bd_net -net inp_recv_im1_1 [get_bd_ports inp_recv_im1] [get_bd_pins small_test_1/inp_recv_im1]
  connect_bd_net -net inp_recv_re1_1 [get_bd_ports inp_recv_re1] [get_bd_pins small_test_1/inp_recv_re1]
  connect_bd_net -net inp_trans_1 [get_bd_ports inp_trans] [get_bd_pins small_test_1/inp_trans]
  connect_bd_net -net small_test_1_out_recv [get_bd_ports out_recv] [get_bd_pins small_test_1/out_recv]
  connect_bd_net -net small_test_1_out_trans_im [get_bd_ports out_trans_im] [get_bd_pins small_test_1/out_trans_im]
  connect_bd_net -net small_test_1_out_trans_re [get_bd_ports out_trans_re] [get_bd_pins small_test_1/out_trans_re]
  connect_bd_net -net small_test_1_test_pin [get_bd_ports test_pin] [get_bd_pins small_test_1/test_pin]

  # Create address segments
  

  # Restore current instance
  current_bd_instance $oldCurInst

  save_bd_design
}
# End of create_root_design()


##################################################################
# MAIN FLOW
##################################################################

create_root_design ""


