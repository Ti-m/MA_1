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
if radio_precision == 1
   
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/256_QAM/Rect_QAM_Mod','outDtype',precision)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/64_QAM/Rect QAM','outDtype',precision)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/256_QAM/Rectangular_QAM_Modu','outDtype',precision)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/64_QAM/Rectangular_QAM_Modu','outDtype',precision)
else
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',fracLen,'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/64_QAM/Rect QAM','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',fracLen,'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/256_QAM/Rectangular_QAM_Modu','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',fracLen,'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/64_QAM/Rectangular_QAM_Modu','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',fracLen,'outUDDataType',precisionModu)

end


%set_param('Basic_DMT/Modulation/Bit-Mapping-P1/256-QAM/Rectangular-QAM-Modulator-Baseband1','OutDataTypeStr',precision)
%set_param(Basic_DMT,'SimulationCommand','Update')