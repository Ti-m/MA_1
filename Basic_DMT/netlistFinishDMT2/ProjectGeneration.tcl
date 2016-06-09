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
	set IP_Revision {95514859}
	set IP_Vendor_Text {User Company}
	set IP_Version_Text {8.41210}
	set ImplStrategyName {Vivado Implementation Defaults}
	set PostProjectCreationProc {dsp_package_for_vivado_ip_integrator}
	set Project {basic_dmt}
	set ProjectFiles {
		{{conv_pkg.vhd} -lib {xil_defaultlib}}
		{{synth_reg.vhd} -lib {xil_defaultlib}}
		{{synth_reg_w_init.vhd} -lib {xil_defaultlib}}
		{{srl17e.vhd} -lib {xil_defaultlib}}
		{{synth_reg_reg.vhd} -lib {xil_defaultlib}}
		{{single_reg_w_init.vhd} -lib {xil_defaultlib}}
		{{xlclockdriver_rd.vhd} -lib {xil_defaultlib}}
		{{vivado_ip.tcl}}
		{{basic_dmt_entity_declarations.vhd} -lib {xil_defaultlib}}
		{{basic_dmt.vhd} -lib {xil_defaultlib}}
		{{basic_dmt_tb.vhd}}
		{{basic_dmt_clock.xdc}}
		{{basic_dmt.xdc}}
		{{basic_dmt.htm}}
	}
	set SimPeriod 4e-09
	set SimTime 4.66667e-05
	set SimulationTime {46870.66666667 ns}
	set SynthStrategyName {Vivado Synthesis Defaults}
	set SynthesisTool {Vivado}
	set TargetDir {D:/MA_1/Basic_DMT/netlistFinishDMT2}
	set TestBenchModule {basic_dmt_tb}
	set TopLevelModule {basic_dmt}
	set TopLevelSimulinkHandle 3.00012
	set VHDLLib {xil_defaultlib}
	set TopLevelPortInterface {}
	dict set TopLevelPortInterface inp_trans Name {inp_trans}
	dict set TopLevelPortInterface inp_trans Type UFix_1_0
	dict set TopLevelPortInterface inp_trans ArithmeticType xlUnsigned
	dict set TopLevelPortInterface inp_trans BinaryPoint 0
	dict set TopLevelPortInterface inp_trans Width 1
	dict set TopLevelPortInterface inp_trans DatFile {basic_dmt_sysgen_sip_inp_trans.dat}
	dict set TopLevelPortInterface inp_trans IconText {inp_trans}
	dict set TopLevelPortInterface inp_trans Direction in
	dict set TopLevelPortInterface inp_trans Period 1
	dict set TopLevelPortInterface inp_trans Interface 0
	dict set TopLevelPortInterface inp_trans InterfaceString {DATA}
	dict set TopLevelPortInterface inp_trans ClockDomain {basic_dmt}
	dict set TopLevelPortInterface inp_trans Locs {}
	dict set TopLevelPortInterface inp_trans IOStandard {}
	dict set TopLevelPortInterface inp_recv_re Name {inp_recv_re}
	dict set TopLevelPortInterface inp_recv_re Type Fix_9_3
	dict set TopLevelPortInterface inp_recv_re ArithmeticType xlSigned
	dict set TopLevelPortInterface inp_recv_re BinaryPoint 3
	dict set TopLevelPortInterface inp_recv_re Width 9
	dict set TopLevelPortInterface inp_recv_re DatFile {basic_dmt_inp_recv_re.dat}
	dict set TopLevelPortInterface inp_recv_re IconText {inp_recv_re}
	dict set TopLevelPortInterface inp_recv_re Direction in
	dict set TopLevelPortInterface inp_recv_re Period 14
	dict set TopLevelPortInterface inp_recv_re Interface 0
	dict set TopLevelPortInterface inp_recv_re InterfaceString {DATA}
	dict set TopLevelPortInterface inp_recv_re ClockDomain {basic_dmt}
	dict set TopLevelPortInterface inp_recv_re Locs {}
	dict set TopLevelPortInterface inp_recv_re IOStandard {}
	dict set TopLevelPortInterface inp_recv_im Name {inp_recv_im}
	dict set TopLevelPortInterface inp_recv_im Type Fix_9_3
	dict set TopLevelPortInterface inp_recv_im ArithmeticType xlSigned
	dict set TopLevelPortInterface inp_recv_im BinaryPoint 3
	dict set TopLevelPortInterface inp_recv_im Width 9
	dict set TopLevelPortInterface inp_recv_im DatFile {basic_dmt_inp_recv_im.dat}
	dict set TopLevelPortInterface inp_recv_im IconText {inp_recv_im}
	dict set TopLevelPortInterface inp_recv_im Direction in
	dict set TopLevelPortInterface inp_recv_im Period 14
	dict set TopLevelPortInterface inp_recv_im Interface 0
	dict set TopLevelPortInterface inp_recv_im InterfaceString {DATA}
	dict set TopLevelPortInterface inp_recv_im ClockDomain {basic_dmt}
	dict set TopLevelPortInterface inp_recv_im Locs {}
	dict set TopLevelPortInterface inp_recv_im IOStandard {}
	dict set TopLevelPortInterface diffsig Name {diffsig}
	dict set TopLevelPortInterface diffsig Type UFix_1_0
	dict set TopLevelPortInterface diffsig ArithmeticType xlUnsigned
	dict set TopLevelPortInterface diffsig BinaryPoint 0
	dict set TopLevelPortInterface diffsig Width 1
	dict set TopLevelPortInterface diffsig DatFile {basic_dmt_diffsig.dat}
	dict set TopLevelPortInterface diffsig IconText {diffSig}
	dict set TopLevelPortInterface diffsig Direction out
	dict set TopLevelPortInterface diffsig Period 5
	dict set TopLevelPortInterface diffsig Interface 0
	dict set TopLevelPortInterface diffsig InterfaceString {DATA}
	dict set TopLevelPortInterface diffsig ClockDomain {basic_dmt}
	dict set TopLevelPortInterface diffsig Locs {}
	dict set TopLevelPortInterface diffsig IOStandard {}
	dict set TopLevelPortInterface out_recv Name {out_recv}
	dict set TopLevelPortInterface out_recv Type UFix_1_0
	dict set TopLevelPortInterface out_recv ArithmeticType xlUnsigned
	dict set TopLevelPortInterface out_recv BinaryPoint 0
	dict set TopLevelPortInterface out_recv Width 1
	dict set TopLevelPortInterface out_recv DatFile {basic_dmt_out_recv.dat}
	dict set TopLevelPortInterface out_recv IconText {out_recv}
	dict set TopLevelPortInterface out_recv Direction out
	dict set TopLevelPortInterface out_recv Period 5
	dict set TopLevelPortInterface out_recv Interface 0
	dict set TopLevelPortInterface out_recv InterfaceString {DATA}
	dict set TopLevelPortInterface out_recv ClockDomain {basic_dmt}
	dict set TopLevelPortInterface out_recv Locs {}
	dict set TopLevelPortInterface out_recv IOStandard {}
	dict set TopLevelPortInterface out_trans_im Name {out_trans_im}
	dict set TopLevelPortInterface out_trans_im Type Fix_9_3
	dict set TopLevelPortInterface out_trans_im ArithmeticType xlSigned
	dict set TopLevelPortInterface out_trans_im BinaryPoint 3
	dict set TopLevelPortInterface out_trans_im Width 9
	dict set TopLevelPortInterface out_trans_im DatFile {basic_dmt_out_trans_im.dat}
	dict set TopLevelPortInterface out_trans_im IconText {out_trans_im}
	dict set TopLevelPortInterface out_trans_im Direction out
	dict set TopLevelPortInterface out_trans_im Period 14
	dict set TopLevelPortInterface out_trans_im Interface 0
	dict set TopLevelPortInterface out_trans_im InterfaceString {DATA}
	dict set TopLevelPortInterface out_trans_im ClockDomain {basic_dmt}
	dict set TopLevelPortInterface out_trans_im Locs {}
	dict set TopLevelPortInterface out_trans_im IOStandard {}
	dict set TopLevelPortInterface out_trans_re Name {out_trans_re}
	dict set TopLevelPortInterface out_trans_re Type Fix_9_3
	dict set TopLevelPortInterface out_trans_re ArithmeticType xlSigned
	dict set TopLevelPortInterface out_trans_re BinaryPoint 3
	dict set TopLevelPortInterface out_trans_re Width 9
	dict set TopLevelPortInterface out_trans_re DatFile {basic_dmt_out_trans_re.dat}
	dict set TopLevelPortInterface out_trans_re IconText {out_trans_re}
	dict set TopLevelPortInterface out_trans_re Direction out
	dict set TopLevelPortInterface out_trans_re Period 14
	dict set TopLevelPortInterface out_trans_re Interface 0
	dict set TopLevelPortInterface out_trans_re InterfaceString {DATA}
	dict set TopLevelPortInterface out_trans_re ClockDomain {basic_dmt}
	dict set TopLevelPortInterface out_trans_re Locs {}
	dict set TopLevelPortInterface out_trans_re IOStandard {}
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
	dict set TopLevelPortInterface clk ClockDomain {basic_dmt}
	dict set TopLevelPortInterface clk Locs {}
	dict set TopLevelPortInterface clk IOStandard {}
	dict set TopLevelPortInterface clk AssociatedInterfaces {}
	dict set TopLevelPortInterface clk AssociatedResets {}
	set MemoryMappedPort {}
}

source SgPaProject.tcl
::xilinx::dsp::planaheadworker::dsp_create_project