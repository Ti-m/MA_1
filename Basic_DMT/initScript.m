%initScript.m
format shortEng

%bitCount = '8';
%fracLen = '0';
assignin('base', 'bitCount', bitCount);
assignin('base', 'fracLen', fracLen);
assignin('base', 'Ts', SampleTime);
assignin('base', 'Tb', BitTime);
assignin('base', 'modu_mode', modu_mode);
assignin('base', 'radio_precision', radio_precision);
assignin('base', 'dmtOfdm', dmtOfdm);
if radio_precision == 1
    precision = 'double';
else
    precision = strcat('fixdt(1,' , bitCount , ',' , fracLen , ')');
    precisionModu = strcat('sfix(',bitCount,')');
end
assignin('base', 'rpv', precision);

%set_param('Basic_DMT/Constant','OutDataTypeStr',precision)

%Rectangular QAM Modulator Data Type
%'outDtype' = 'double' or 'User-defined'
%'outFracLenMode'='User-defined'
%'outFracLen'=fracLen
%'outUDDataType'=precisionModu

%%%%SIMULINK-BLOCKS%%%%%

set_param('Basic_DMT/IFFT & P//S/Create Frame for IFFT/DMT/Constant','OutDataTypeStr',precision)
set_param('Basic_DMT/IFFT & P//S/Create Frame for IFFT/OFDM/Constant1','OutDataTypeStr',precision)
if radio_precision == 1
    
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/256_QAM/Rect_QAM_Mod','outDtype',precision)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/16_QAM/Rect QAM','outDtype',precision)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/256_QAM/Rectangular_QAM_Modu','outDtype',precision)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/16_QAM/Rectangular_QAM_Modu','outDtype',precision)     
else
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',fracLen,'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/16_QAM/Rect QAM','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',fracLen,'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/256_QAM/Rectangular_QAM_Modu','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',fracLen,'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/16_QAM/Rectangular_QAM_Modu','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',fracLen,'outUDDataType',precisionModu)

end

%%%%SYSGEN-BLOCKS%%%%%

set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant1','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant2','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant3','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant4','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant5','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant6','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant7','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant8','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)

set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant1','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant2','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant3','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant4','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant5','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant6','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant7','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant8','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%get_param(gcb,'arith_type')
%get_param(gcb,'bin_pt')
%get_param(gcb,'n_bits')
%Outputs all block paths
%BlockPaths = find_system('Basic_DMT','Type','Block')

%set_param('Basic_DMT/Modulation/Bit-Mapping-P1/256-QAM/Rectangular-QAM-Modulator-Baseband1','OutDataTypeStr',precision)
%set_param(Basic_DMT,'SimulationCommand','Update')