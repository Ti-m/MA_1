%initScript.m
format shortEng

assignin('base', 'Ts', SampleTime);
assignin('base', 'Tb', BitTime);
assignin('base', 'modu_mode', modu_mode);
assignin('base', 'radio_precision', radio_precision);
if radio_precision == 1
    precision = 'double';
else
    precision = 'fixdt(1,9,8)';
end
assignin('base', 'rpv', precision);

%set_param('Basic_DMT/Constant','OutDataTypeStr',precision)

if radio_precision == 1
    set_param('Basic_DMT/11111','outDtype',precision)
else
    set_param('Basic_DMT/11111','outDtype','User-defined','outFracLenMode','User-defined','outFracLen','8')
end


%set_param('Basic_DMT/Modulation/Bit-Mapping-P1/256-QAM/Rectangular-QAM-Modulator-Baseband1','OutDataTypeStr',precision)
%set_param(Basic_DMT,'SimulationCommand','Update')