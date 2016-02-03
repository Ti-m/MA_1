%initScript.m
format shortEng

%bitCount = '8';
%fracLen = '0';

sysgenSystemPeriod=.5e-9;
assignin('base', 'sysgenSystemPeriod', sysgenSystemPeriod);
fftLen = 16;
assignin('base', 'fftLen', fftLen);
fftLenDMT = 2*fftLen;
assignin('base', 'fftLenDMT', fftLenDMT);
usedSubCar=14;
bitPerSymb=4;

upsampleFactor = 8; 

assignin('base', 'impulseResponse', impulseResponse);


if guardInterval == 2
    GI_Len = 4;
    GI_LenDMT=GI_Len*2;
    
else
    GI_Len = 0;
     GI_LenDMT=0;
     GI_Active=0;
end
assignin('base', 'GI_Len', GI_Len);
assignin('base', 'GI_LenDMT', GI_LenDMT);
if dmtOfdm == 1 %% To create blocks which are not dependent on variant subsystems.
    GI_Active = GI_Len;
    fftLenActive = fftLen;
else
    GI_Active = GI_LenDMT;
    fftLenActive = fftLenDMT;
end
assignin('base', 'GI_Active', GI_Active);
assignin('base', 'fftLenActive', fftLenActive);
beta = fftLen/(fftLen+GI_Len); 
assignin('base', 'beta', beta);

assignin('base', 'usedSubCar', usedSubCar);
assignin('base', 'bitPerSymb', bitPerSymb);
assignin('base', 'bitCount',bitCount);
assignin('base', 'fracLen',fracLen);
assignin('base', 'Ts', SampleTime);
if upsample == 2
    upsampleFactor = 8; 
else
    upsampleFactor = 1; %used in AWGN Simulink Channel sample time calculation
end
assignin('base', 'upsample', upsample);
assignin('base', 'upsampleFactor', upsampleFactor);


%sysgenSystemPeriod = SampleTime*usedSubCar/fftLen;
assignin('base', 'sysgenSystemPeriod', sysgenSystemPeriod);
assignin('base', 'Tb', BitTime);
assignin('base', 'modu_mode', modu_mode);
assignin('base', 'radio_precision', str2double(radio_precision));
assignin('base', 'dmtOfdm', dmtOfdm);
assignin('base', 'guardInterval', guardInterval);
assignin('base', 'AWGN', AWGN);
assignin('base', 'channel', channel);
grpDelayChannelFilt = 1;
assignin('base', 'grpDelayChannelFilt', grpDelayChannelFilt);

if radio_precision == 1
    precision_str = 'double';
    precStrAftIFFT = 'double';
else
    precision_str = strcat('fixdt(1,' , num2str(bitCount) , ',' , num2str(fracLen) , ')');
    precStrAftIFFT =strcat('fixdt(1,' , num2str(bitCount+(log2(fftLen)+1)) , ',' , num2str(fracLen) , ')');
    precisionModu = strcat('sfix(',num2str(bitCount),')');
end
assignin('base', 'precision_str', precision_str);
assignin('base', 'precStrAftIFFT', precStrAftIFFT);

if dmtOfdm == 2
%fftLen = 32;
end
%set_param('Basic_DMT/Constant','OutDataTypeStr',precision)

%Rectangular QAM Modulator Data Type
%'outDtype' = 'double' or 'User-defined'
%'outFracLenMode'='User-defined'
%'outFracLen'=fracLen
%'outUDDataType'=precisionModu

%%%%SIMULINK-BLOCKS%%%%%

%Not possible to replace these with variables in the simulink-constant
%blocks.
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/Constant','OutDataTypeStr',precision_str)
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_DMT/Constant','OutDataTypeStr',precision_str)
set_param('Basic_DMT/AWGN/Yes_AWGN/Data_Type_Conversion','OutDataTypeStr',precStrAftIFFT)  

if radio_precision == 1 
    
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/16_QAM/Rect_QAM_Mod','outDtype',precision_str)    
    set_param('Basic_DMT/Modulation/Bit_Mapping_P3/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P3/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P4/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P4/16_QAM/Rect_QAM_Mod','outDtype',precision_str) 
    set_param('Basic_DMT/Modulation/Bit_Mapping_P5/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P5/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P6/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P6/16_QAM/Rect_QAM_Mod','outDtype',precision_str)    
    set_param('Basic_DMT/Modulation/Bit_Mapping_P7/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P7/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P8/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P8/16_QAM/Rect_QAM_Mod','outDtype',precision_str)    
    set_param('Basic_DMT/Modulation/Bit_Mapping_P9/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P9/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P10/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P10/16_QAM/Rect_QAM_Mod','outDtype',precision_str)    
    set_param('Basic_DMT/Modulation/Bit_Mapping_P11/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P11/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P12/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P12/16_QAM/Rect_QAM_Mod','outDtype',precision_str)    
    set_param('Basic_DMT/Modulation/Bit_Mapping_P13/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P13/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P14/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P14/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    
    set_param('Basic_DMT/IFFTaPIS/IFFT','outputDataTypeStr','Inherit: Inherit via internal rule')
    
    set_param('Basic_DMT/SIPaFFT/FFT/FFT_OFDM/FFT','outputDataTypeStr','Inherit: Inherit via internal rule')
    set_param('Basic_DMT/SIPaFFT/FFT/FFT_DMT/FFT','outputDataTypeStr','Inherit: Inherit via internal rule')
else
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P1/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P2/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P3/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P3/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P4/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P4/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P5/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P5/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P6/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P6/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P7/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P7/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P8/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P8/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P9/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P9/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P10/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P10/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P11/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P11/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P12/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P12/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P13/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P13/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P14/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P14/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
  
    set_param('Basic_DMT/IFFTaPIS/IFFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount+log2(fftLen)+1) , ',' , num2str(fracLen) , ')'))
    set_param('Basic_DMT/SIPaFFT/FFT/FFT_OFDM/FFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount+(log2(fftLen)+1)*2) , ',' , num2str(fracLen) , ')'))
    set_param('Basic_DMT/SIPaFFT/FFT/FFT_DMT/FFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount+(log2(fftLen)+1)*2) , ',' , num2str(fracLen) , ')'))
end

%channel filter coefficients
%TP zweiter ordnung, Fenstermethode, rect-windows, fc=5MHz, Fs=17.8MHz
%a0=0.26324574007976659;
%a1=0.47350851984046677;
%a2=a0;

%channel filter coefficients
%lahmer TP mit nur 3dB D�mpfung, geht auch ohne equalizer
a0=0.04100388;
a1=0.9179922382;
a2=a0;
assignin('base', 'a0', a0);
assignin('base', 'a1', a1);
assignin('base', 'a2', a2);

%equalizer coefficients
h=[a0; a1; a2; zeros(17857,1) ];
%h=[a0; a1; a2; zeros(32-3,1) ];
g=fft(h);
e(1:8)=g(1:893:8*893);
e(9:16)=g(13*893:893:20*893);

%e=e1(1:893:17857*2);
%e=e1(1:16);
%e=ones(16,1);
e0=e(1);
e1=e(2);
%e1=0.8314+i*0.0042;
e2=e(3);
%e2=0.8583+i*0.01;
e3=e(4);
e4=e(5);
e5=e(6);
e6=e(7);
e7=e(8);
e8=e(9);
e9=e(10);
e10=e(11);
e11=e(12);
e12=e(13);
e13=e(14);
e14=e(15);
e15=e(16);
assignin('base', 'e', e);
assignin('base', 'e0', e0);
assignin('base', 'e1', e1);
assignin('base', 'e2', e2);
assignin('base', 'e3', e3);
assignin('base', 'e4', e4);
assignin('base', 'e5', e5);
assignin('base', 'e6', e6);
assignin('base', 'e7', e7);
assignin('base', 'e8', e8);
assignin('base', 'e9', e9);
assignin('base', 'e10', e10);
assignin('base', 'e11', e11);
assignin('base', 'e12', e12);
assignin('base', 'e13', e13);
assignin('base', 'e14', e14);
assignin('base', 'e15', e15);
%%%%SYSGEN-BLOCKS%%%%%

%set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant1','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant2','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant3','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant4','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant5','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant6','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant7','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM/Constant8','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)

%set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant1','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant2','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant3','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant4','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant5','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant6','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant7','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_Modulation/16-QAM1/Constant8','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)

%set_param('Basic_DMT/Sysgen_IFFTaPIS/Constant','arith_type','Signed (2''s comp)','bin_pt',fracLen,'n_bits',bitCount)
%set_param('Basic_DMT/Sysgen_IFFTaPIS/Reinterpret','bin_pt',num2str(str2double(bitCount)-1))
%set_param('Basic_DMT/Sysgen_IFFTaPIS/Reinterpret1','bin_pt',num2str(str2double(bitCount)-1))
%set_param('Basic_DMT/Sysgen_IFFTaPIS/Reinterpret2','bin_pt',fracLen)
%set_param('Basic_DMT/Sysgen_IFFTaPIS/Reinterpret3','bin_pt',fracLen)

%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret','bin_pt',num2str(str2double(bitCount)-1+log2(fftLen)+1))
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret1','bin_pt',num2str(str2double(bitCount)-1+log2(fftLen)+1))
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret2','bin_pt',fracLen)
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret3','bin_pt',fracLen)
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret4','bin_pt',fracLen)
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret5','bin_pt',fracLen)
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret6','bin_pt',fracLen)
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret7','bin_pt',fracLen)
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret8','bin_pt',fracLen)
%set_param('Basic_DMT/Sysgen_SIPaFFT/Reinterpret9','bin_pt',fracLen)


%get_param(gcb,'arith_type')
%get_param(gcb,'bin_pt')
%get_param(gcb,'n_bits')
%Outputs all block paths
%BlockPaths = find_system('Basic_DMT','Type','Block')

%set_param('Basic_DMT/Modulation/Bit-Mapping-P1/256-QAM/Rectangular-QAM-Modulator-Baseband1','OutDataTypeStr',precision)
%set_param(Basic_DMT,'SimulationCommand','Update')