# Note: This file is produced automatically, and will be overwritten the next
# time you press "Generate" in System Generator. 
#


namespace eval ::xilinx::dsp::planaheaddriver {
	set Compilation {IP Catalog}
	set CompilationFlow {IP}
	set CreateInterfaceDocument {on}
	set DSPDevice {xc7z020}
	set DSPFamily {zynq}
	set DSPPackage {clg400}
	set DSPSpeed {-1}
	set FPGAClockPeriod 4
	set GenerateTestBench 1
	set HDLLanguage {vhdl}
	set IP_Auto_Infer {1}
	set IP_Categories_Text {System Generator for DSP}
	set IP_Common_Repos {0}
	set IP_Description {}
	set IP_Dir {}
	set IP_Library_Text {SysGen}
	set IP_LifeCycle_Menu {1}
	set IP_Logo {sysgen_icon_100.png}
	set IP_Name {Basic_DMT_cw}
	set IP_Revision {89053641}
	set IP_Vendor_Text {User Company}
	set IP_Version_Text {1.1}
	set ImplStrategyName {Vivado Implementation Defaults}
	set PostProjectCreationProc {dsp_package_for_vivado_ip_integrator}
	set Project {small_test}
	set ProjectFiles {
		{{conv_pkg.vhd} -lib {xil_defaultlib}}
		{{synth_reg.vhd} -lib {xil_defaultlib}}
		{{synth_reg_w_init.vhd} -lib {xil_defaultlib}}
		{{srl17e.vhd} -lib {xil_defaultlib}}
		{{synth_reg_reg.vhd} -lib {xil_defaultlib}}
		{{single_reg_w_init.vhd} -lib {xil_defaultlib}}
		{{xlclockdriver_rd.vhd} -lib {xil_defaultlib}}
		{{small_test_entity_declarations.vhd} -lib {xil_defaultlib}}
		{{small_test.vhd} -lib {xil_defaultlib}}
		{{small_test_tb.vhd}}
		{{small_test_clock.xdc}}
		{{small_test.xdc}}
		{{small_test.htm}}
	}
	set SimPeriod 4e-09
	set SimTime 4e-05
	set SimulationTime {40204.00000000 ns}
	set SynthStrategyName {Vivado Synthesis Defaults}
	set SynthesisTool {Vivado}
	set TargetDir {C:/Users/Tim-UML/Documents/GitHub/MA_1/Sysgen_small_test/netlistFin1}
	set TestBenchModule {small_test_tb}
	set TopLevelModule {small_test}
	set TopLevelSimulinkHandle 3.00012
	set VHDLLib {xil_defaultlib}
	set TopLevelPortInterface {}
	dict set TopLevelPortInterface inp_trans Name {inp_trans}
	dict set TopLevelPortInterface inp_trans Type UFix_1_0
	dict set TopLevelPortInterface inp_trans ArithmeticType xlUnsigned
	dict set TopLevelPortInterface inp_trans BinaryPoint 0
	dict set TopLevelPortInterface inp_trans Width 1
	dict set TopLevelPortInterface inp_trans DatFile {small_test_inp_trans.dat}
	dict set TopLevelPortInterface inp_trans IconText {inp_trans}
	dict set TopLevelPortInterface inp_trans Direction in
	dict set TopLevelPortInterface inp_trans Period 5
	dict set TopLevelPortInterface inp_trans Interface 0
	dict set TopLevelPortInterface inp_trans InterfaceString {DATA}
	dict set TopLevelPortInterface inp_trans ClockDomain {small_test}
	dict set TopLevelPortInterface inp_trans Locs {}
	dict set TopLevelPortInterface inp_trans IOStandard {}
	dict set TopLevelPortInterface inp_recv_re1 Name {inp_recv_re1}
	dict set TopLevelPortInterface inp_recv_re1 Type Fix_16_13
	dict set TopLevelPortInterface inp_recv_re1 ArithmeticType xlSigned
	dict set TopLevelPortInterface inp_recv_re1 BinaryPoint 13
	dict set TopLevelPortInterface inp_recv_re1 Width 16
	dict set TopLevelPortInterface inp_recv_re1 DatFile {small_test_inp_recv_re1.dat}
	dict set TopLevelPortInterface inp_recv_re1 IconText {inp_recv_re1}
	dict set TopLevelPortInterface inp_recv_re1 Direction in
	dict set TopLevelPortInterface inp_recv_re1 Period 8
	dict set TopLevelPortInterface inp_recv_re1 Interface 0
	dict set TopLevelPortInterface inp_recv_re1 InterfaceString {DATA}
	dict set TopLevelPortInterface inp_recv_re1 ClockDomain {small_test}
	dict set TopLevelPortInterface inp_recv_re1 Locs {}
	dict set TopLevelPortInterface inp_recv_re1 IOStandard {}
	dict set TopLevelPortInterface inp_recv_im1 Name {inp_recv_im1}
	dict set TopLevelPortInterface inp_recv_im1 Type Fix_16_13
	dict set TopLevelPortInterface inp_recv_im1 ArithmeticType xlSigned
	dict set TopLevelPortInterface inp_recv_im1 BinaryPoint 13
	dict set TopLevelPortInterface inp_recv_im1 Width 16
	dict set TopLevelPortInterface inp_recv_im1 DatFile {small_test_inp_recv_im1.dat}
	dict set TopLevelPortInterface inp_recv_im1 IconText {inp_recv_im1}
	dict set TopLevelPortInterface inp_recv_im1 Direction in
	dict set TopLevelPortInterface inp_recv_im1 Period 8
	dict set TopLevelPortInterface inp_recv_im1 Interface 0
	dict set TopLevelPortInterface inp_recv_im1 InterfaceString {DATA}
	dict set TopLevelPortInterface inp_recv_im1 ClockDomain {small_test}
	dict set TopLevelPortInterface inp_recv_im1 Locs {}
	dict set TopLevelPortInterface inp_recv_im1 IOStandard {}
	dict set TopLevelPortInterface out_recv Name {out_recv}
	dict set TopLevelPortInterface out_recv Type UFix_1_0
	dict set TopLevelPortInterface out_recv ArithmeticType xlUnsigned
	dict set TopLevelPortInterface out_recv BinaryPoint 0
	dict set TopLevelPortInterface out_recv Width 1
	dict set TopLevelPortInterface out_recv DatFile {small_test_out_recv.dat}
	dict set TopLevelPortInterface out_recv IconText {out_recv}
	dict set TopLevelPortInterface out_recv Direction out
	dict set TopLevelPortInterface out_recv Period 5
	dict set TopLevelPortInterface out_recv Interface 0
	dict set TopLevelPortInterface out_recv InterfaceString {DATA}
	dict set TopLevelPortInterface out_recv ClockDomain {small_test}
	dict set TopLevelPortInterface out_recv Locs {}
	dict set TopLevelPortInterface out_recv IOStandard {}
	dict set TopLevelPortInterface out_trans_im Name {out_trans_im}
	dict set TopLevelPortInterface out_trans_im Type Fix_16_13
	dict set TopLevelPortInterface out_trans_im ArithmeticType xlSigned
	dict set TopLevelPortInterface out_trans_im BinaryPoint 13
	dict set TopLevelPortInterface out_trans_im Width 16
	dict set TopLevelPortInterface out_trans_im DatFile {small_test_out_trans_im.dat}
	dict set TopLevelPortInterface out_trans_im IconText {out_trans_im}
	dict set TopLevelPortInterface out_trans_im Direction out
	dict set TopLevelPortInterface out_trans_im Period 8
	dict set TopLevelPortInterface out_trans_im Interface 0
	dict set TopLevelPortInterface out_trans_im InterfaceString {DATA}
	dict set TopLevelPortInterface out_trans_im ClockDomain {small_test}
	dict set TopLevelPortInterface out_trans_im Locs {}
	dict set TopLevelPortInterface out_trans_im IOStandard {}
	dict set TopLevelPortInterface out_trans_re Name {out_trans_re}
	dict set TopLevelPortInterface out_trans_re Type Fix_16_13
	dict set TopLevelPortInterface out_trans_re ArithmeticType xlSigned
	dict set TopLevelPortInterface out_trans_re BinaryPoint 13
	dict set TopLevelPortInterface out_trans_re Width 16
	dict set TopLevelPortInterface out_trans_re DatFile {small_test_out_trans_re.dat}
	dict set TopLevelPortInterface out_trans_re IconText {out_trans_re}
	dict set TopLevelPortInterface out_trans_re Direction out
	dict set TopLevelPortInterface out_trans_re Period 8
	dict set TopLevelPortInterface out_trans_re Interface 0
	dict set TopLevelPortInterface out_trans_re InterfaceString {DATA}
	dict set TopLevelPortInterface out_trans_re ClockDomain {small_test}
	dict set TopLevelPortInterface out_trans_re Locs {}
	dict set TopLevelPortInterface out_trans_re IOStandard {}
	dict set TopLevelPortInterface test_pin Name {test_pin}
	dict set TopLevelPortInterface test_pin Type UFix_1_0
	dict set TopLevelPortInterface test_pin ArithmeticType xlUnsigned
	dict set TopLevelPortInterface test_pin BinaryPoint 0
	dict set TopLevelPortInterface test_pin Width 1
	dict set TopLevelPortInterface test_pin DatFile {small_test_test_pin.dat}
	dict set TopLevelPortInterface test_pin IconText {test_pin}
	dict set TopLevelPortInterface test_pin Direction out
	dict set TopLevelPortInterface test_pin Period 5
	dict set TopLevelPortInterface test_pin Interface 0
	dict set TopLevelPortInterface test_pin InterfaceString {DATA}
	dict set TopLevelPortInterface test_pin ClockDomain {small_test}
	dict set TopLevelPortInterface test_pin Locs {}
	dict set TopLevelPortInterface test_pin IOStandard {}
	dict set TopLevelPortInterface clk Name {clk}
	dict set TopLevelPortInterface clk Type -
	dict set TopLevelPortInterface clk ArithmeticType xlUnsigned
	dict set TopLevelPortInterface clk BinaryPoint 0
	dict set TopLevelPortInterface clk Width 1
	dict set TopLevelPortInterface clk DatFile {}
	dict set TopLevelPortInterface clk Direction in
	dict set TopLevelPortInterface clk Period 1
	dict set TopLevelPortInterface clk Interface 6
	dict set TopLevelPortInterface clk InterfaceString {CLOCK}
	dict set TopLevelPortInterface clk ClockDomain {small_test}
	dict set TopLevelPortInterface clk Locs {}
	dict set TopLevelPortInterface clk IOStandard {}
	dict set TopLevelPortInterface clk AssociatedInterfaces {}
	dict set TopLevelPortInterface clk AssociatedResets {}
	set MemoryMappedPort {}
}

source SgPaProject.tcl
::xilinx::dsp::planaheadworker::dsp_create_project