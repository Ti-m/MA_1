%initScript.m
format shortEng

%FixedPoint Arithmetic
fiObject= fimath('RoundingMethod', 'Nearest', ...
                'OverflowAction', 'Saturate', ...
                'ProductMode', 'SpecifyPrecision', ...
                'ProductWordLength', bitCount, ...
                'ProductFractionLength', fracLen, ...
                'SumMode', 'SpecifyPrecision', ...
                'SumWordLength', bitCount, ...
                'SumFractionLength', fracLen, ...
                'CastBeforeSum', true);
assignin('base', 'fiObject', fiObject);

fiObjectAftIFFT= fimath('RoundingMethod', 'Nearest', ...
                'OverflowAction', 'Saturate', ...
                'ProductMode', 'SpecifyPrecision', ...
                'ProductWordLength', bitCount, ...
                'ProductFractionLength', fracLen, ...
                'SumMode', 'SpecifyPrecision', ...
                'SumWordLength', bitCount, ...
                'SumFractionLength', fracLen, ...
                'CastBeforeSum', true);
assignin('base', 'fiObjectAftIFFT', fiObjectAftIFFT);

%bitCount = '8';
%fracLen = '0';
SystemPeriod = 4e-9;
%sysgenSystemPeriod=4e-9;
%sysgenSystemPeriod=.5e-9;
sysgenSystemPeriod=4e-9; %geht auch, aber alle delays verschieben sich
assignin('base', 'sysgenSystemPeriod', sysgenSystemPeriod);
assignin('base', 'SystemPeriod', SystemPeriod);
fftLen = 16;%16
M=log2(fftLen);
assignin('base', 'fftLen', fftLen);
assignin('base', 'M', M);
fftLenDMT = 2*fftLen;
assignin('base', 'fftLenDMT', fftLenDMT);
usedSubCar=14;%14
bitPerSymb=4;
upsampleFactor = 8; 

%Set to zero for not use the carrier
u1=0;
u2=1;
u3=1;
u4=1;
u5=1;
u6=1;
u7=1;
u8=1;
u9=0;%0
u10=1;
u11=1;
u12=1;
u13=1;
u14=1;
u15=1;
u16=1;
assignin('base', 'u1', u1);
assignin('base', 'u2', u2);
assignin('base', 'u3', u3);
assignin('base', 'u4', u4);
assignin('base', 'u5', u5);
assignin('base', 'u6', u6);
assignin('base', 'u7', u7);
assignin('base', 'u8', u8);
assignin('base', 'u9', u9);
assignin('base', 'u10', u10);
assignin('base', 'u11', u11);
assignin('base', 'u12', u12);
assignin('base', 'u13', u13);
assignin('base', 'u14', u14);
assignin('base', 'u15', u15);
assignin('base', 'u16', u16);

assignin('base', 'impulseResponse', impulseResponse);
assignin('base', 'equalizer', equalizer);
% state = 0;
% k=0;
% assignin('base', 'state', state);
% assignin('base', 'k', k);

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
    freqDivDMT = 1;
else
    GI_Active = GI_LenDMT;
    fftLenActive = fftLenDMT;
    freqDivDMT = 2;%To achieve the half processing frequency in DMT mode
end
assignin('base', 'GI_Active', GI_Active);
assignin('base', 'fftLenActive', fftLenActive);
%Used in Mcode blocks to reduce arithmetic
OFDMFrameSmpCntAct = GI_Active + fftLenActive;
assignin('base', 'OFDMFrameSmpCntAct', OFDMFrameSmpCntAct);
assignin('base', 'freqDivDMT', freqDivDMT);
if GI_Active>0
    beta = fftLen/(fftLen+GI_Len); 
else
    beta = 1;
end
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
assignin('base', 'Tb', BitTime);

%Divider for the Input FIFO. Determines how many samples are not sampled 
%until the next valid sample arrives. Calculated here, because it has to
%be calculated only once. 
freqDivSubcAlloc = BitTime/SystemPeriod;
assignin('base', 'freqDivSubcAlloc', freqDivSubcAlloc);

%How many bits are in one OFDM frame. Used in subc_alloc FSM
bitsPerFrame=usedSubCar*bitPerSymb;
assignin('base', 'bitsPerFrame', bitsPerFrame);
%Samplerate on Channel
Tchan=bitPerSymb*usedSubCar/fftLenActive*(BitTime*beta);
%Calc factor for downsampling before channel
%chanDownFact=Tchan/(SystemPeriod*bitPerSymb*usedSubCar/(fftLenActive));
chanDownFact=Tchan/SystemPeriod;
assignin('base', 'Tchan', Tchan);
assignin('base', 'chanDownFact', chanDownFact);

%sysgenSystemPeriod = SampleTime*usedSubCar/fftLen;
assignin('base', 'sysgenSystemPeriod', sysgenSystemPeriod);

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
    precStrAftIFFT =strcat('fixdt(1,' , num2str(bitCount) , ',' , num2str(fracLen) , ')');
    %precStrAftIFFT =strcat('fixdt(1,' , num2str(bitCount+(log2(fftLen)+1)) , ',' , num2str(fracLen) , ')');
    precisionModu = strcat('sfix(',num2str(bitCount),')');
end
assignin('base', 'precision_str', precision_str);
assignin('base', 'precStrAftIFFT', precStrAftIFFT);

bitCountAftIFFT = bitCount;
%bitCountAftIFFT = bitCount+(log2(fftLen)+1);
assignin('base', 'bitCountAftIFFT', bitCountAftIFFT);


%bitCountAftFFTRec = bitCount+(log2(fftLen)+1)*2;
bitCountAftFFTRec = bitCount;
assignin('base', 'bitCountAftFFTRec', bitCountAftFFTRec);
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
%set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/Constant','OutDataTypeStr',precision_str)
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_DMT/Constant','OutDataTypeStr',precision_str)
set_param('Basic_DMT/AWGN/Yes_AWGN/Data_Type_Conversion','OutDataTypeStr',precStrAftIFFT)  
set_param('Basic_DMT/IFFTaPIS/Data Type Conversion','OutDataTypeStr',precision_str)
%set_param('Basic_DMT/SIPaFFT/Assert_aft_FFT/Data Type Conversion3','OutDataTypeStr',precStrAftIFFT) 
%set_param('Basic_DMT/IFFTaPIS/Data Type Conversion1','OutDataTypeStr',precision_str)
%set_param('Basic_DMT/IFFTaPIS/Data Type Conversion2','OutDataTypeStr',precision_str) 

% set_param('Basic_DMT/SIP/Data Type Conversion','OutDataTypeStr',precision_str) 
% set_param('Basic_DMT/SIP/Data Type Conversion1','OutDataTypeStr',precision_str) 
%set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/out','DataType',precision_str) 
% set_param('Basic_DMT/SIP/MATLAB Function/sel','CompiledType','uint32') 
% set_param('Basic_DMT/SIP/MATLAB Function/sel','DataType',precision_str) 
% set_param('Basic_DMT/SIP/MATLAB Function/push','DataType',precision_str) 
% set_param('Basic_DMT/SIP/MATLAB Function/pop','DataType',precision_str) 
% set_param('Basic_DMT/SIP/MATLAB Function/frameStart','DataType',precision_str) 
% set_param('Basic_DMT/SIP/MATLAB Function/num','DataType',precision_str) 
% set_param('Basic_DMT/SIP/MATLAB Function/frameEn','DataType',precision_str) 

%%% CREATE FRAME OFDM

set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o1','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o2','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o3','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o4','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o5','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o6','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o7','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o8','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o9','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o10','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o11','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o12','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o13','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o14','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o15','OutDataTypeStr',precision_str) 
set_param('Basic_DMT/IFFTaPIS/Create_Frame_for_IFFT/OFDMorDMT/Frame_OFDM/MATLAB Function/o16','OutDataTypeStr',precision_str) 

%%% CREATE FRAME DMT
%Kommt scheinbar ohne aus

%%% SET GI OFDM
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/Data Store Memory1','OutDataTypeStr',precStrAftIFFT) 

set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/out','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/inp','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i1','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i2','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i3','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i4','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i5','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i6','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i7','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i8','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i9','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i10','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i11','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i12','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i13','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i14','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i15','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/i16','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o1','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o2','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o3','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o4','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o5','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o6','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o7','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o8','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o9','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o10','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o11','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o12','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o13','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o14','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o15','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_OFDM/MATLAB Function/o16','OutDataTypeStr',precStrAftIFFT)

%%% SET GI DMT
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/Data Store Memory1','OutDataTypeStr',precStrAftIFFT) 

set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/out','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/inp','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i1','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i2','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i3','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i4','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i5','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i6','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i7','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i8','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i9','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i10','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i11','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i12','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i13','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i14','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i15','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i16','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i17','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i18','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i19','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i20','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i21','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i22','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i23','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i24','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i25','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i26','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i27','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i28','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i29','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i30','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i31','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/i32','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o1','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o2','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o3','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o4','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o5','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o6','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o7','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o8','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o9','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o10','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o11','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o12','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o13','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o14','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o15','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o16','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o17','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o18','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o19','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o20','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o21','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o22','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o23','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o24','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o25','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o26','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o27','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o28','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o29','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o30','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o31','OutDataTypeStr',precStrAftIFFT) 
set_param('Basic_DMT/IFFTaPIS/Guard_Interval/Set_GI_DMT/MATLAB Function/o32','OutDataTypeStr',precStrAftIFFT)


%%%%%%%%%%%%%%%%%%%RECEIVER
%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%SIP
set_param('Basic_DMT/SIPaFFT/Constant2','OutDataTypeStr',precStrAftIFFT)
%%% REM_GI OFDM
set_param('Basic_DMT/SIPaFFT/Remove_Guard_Interval/Rem_GI/Data Store Memory3','OutDataTypeStr',precStrAftIFFT) 

set_param('Basic_DMT/SIPaFFT/Remove_Guard_Interval/Rem_GI/MATLAB Function/out','OutDataTypeStr',precStrAftIFFT)
set_param('Basic_DMT/SIPaFFT/Remove_Guard_Interval/Rem_GI/MATLAB Function/inp','OutDataTypeStr',precStrAftIFFT) 

%%% REM_GI OFDM
% set_param('Basic_DMT/SIPaFFT/Remove_Guard_Interval/Rem_GI_DMT/Data Store Memory3','OutDataTypeStr',precStrAftIFFT) 
% 
% set_param('Basic_DMT/SIPaFFT/Remove_Guard_Interval/Rem_GI_DMT/MATLAB Function/out','OutDataTypeStr',precStrAftIFFT)
% set_param('Basic_DMT/SIPaFFT/Remove_Guard_Interval/Rem_GI_DMT/MATLAB Function/inp','OutDataTypeStr',precStrAftIFFT) 

%%%TEST
 testGHJ = strcat('fixdt(1,' , num2str(bitCount) , ',' , num2str(fracLen) , ')');
% testGHJ = 'double';
 set_param('Basic_DMT/Subsystem1/Constant8','OutDataTypeStr',testGHJ)
 set_param('Basic_DMT/Subsystem1/Data Store Memory','OutDataTypeStr',testGHJ)
 %%%%
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
    set_param('Basic_DMT/Modulation/Bit_Mapping_P15/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P15/16_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P16/256_QAM/Rect_QAM_Mod','outDtype',precision_str)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P16/16_QAM/Rect_QAM_Mod','outDtype',precision_str) 
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
    set_param('Basic_DMT/Modulation/Bit_Mapping_P15/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P15/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P16/256_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    set_param('Basic_DMT/Modulation/Bit_Mapping_P16/16_QAM/Rect_QAM_Mod','outDtype','User-defined','outFracLenMode','User-defined','outFracLen',num2str(fracLen),'outUDDataType',precisionModu)
    %set_param('Basic_DMT/IFFTaPIS/IFFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount+log2(fftLen)+1) , ',' , num2str(fracLen) , ')'))
    %set_param('Basic_DMT/SIPaFFT/FFT/FFT_OFDM/FFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount+(log2(fftLen)+1)*2) , ',' , num2str(fracLen) , ')'))
    %set_param('Basic_DMT/SIPaFFT/FFT/FFT_DMT/FFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount+(log2(fftLen)+1)*2) , ',' , num2str(fracLen) , ')'))
    set_param('Basic_DMT/IFFTaPIS/IFFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount) , ',' , num2str(fracLen) , ')'))
    set_param('Basic_DMT/SIPaFFT/FFT/FFT_OFDM/FFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount) , ',' , num2str(fracLen) , ')'))
    set_param('Basic_DMT/SIPaFFT/FFT/FFT_DMT/FFT','outputDataTypeStr',strcat('fixdt(1,' , num2str(bitCount) , ',' , num2str(fracLen) , ')'))
end

%channel filter coefficients

%TP zweiter ordnung, Fenstermethode, Hamming-window, fc=5MHz, Fs=35.71MHz,
%2.5dB
 %a0=0.061461097527179653;
% a1=0.8770778049456408;
 %a2=a0;


%TP zweiter ordnung, Fenstermethode, rect-windows, fc=5MHz, Fs=14.286MHz
  a0=0.21194908595403703;
 a1=0.576101828091926;
 a2=a0;

%channel filter coefficients
%TP zweiter ordnung, Fenstermethode, rect-windows, fc=5MHz, Fs=17.8MHz
%   a0=0.26324574007976659;
%   a1=0.47350851984046677;
%   a2=a0;


%channel filter coefficients
% %TP (triangular) mit nur 7dB Dämpfung, geht auch ohne equalizer
% a0=0.14442723509625877;
% a1=0.71114552980748247;
% a2=a0;

%channel filter coefficients
%lahmer TP mit nur 3dB Dämpfung, geht auch ohne equalizer
%  a0=0.04100388;
%   a1=0.9179922382;
%  a2=a0;
assignin('base', 'a0', a0);
assignin('base', 'a1', a1);
assignin('base', 'a2', a2);

%equalizer coefficients
h=[a0; a1; a2;];
%h=[a0; a1; a2; zeros(13,1) ];
%h=[a0; a1; a2; zeros(1024-3,1) ];
%h=[a0; a1; a2; zeros(17857,1) ];
%%%%%%%%h=[a0; a1; a2; zeros(35714-3,1) ];
%h=[a0; a1; a2; zeros(32-3,1) ];

H=fft(h,fftLenActive);%ofdm16 dmt32
if dmtOfdm == 2 %DMT active
    H = H(1:16);
end
% e=p./(abs(p).^2);
% for d=1:16
%     alt(d)=p(d)'/(abs(p(d))^2);
% end
e=H;
%assignin('base', 'alt', alt);
%p=real(g)+1+1i*imag(g);
%%%%%%%%e=p(1:893:16*893);
%e(1:8)=p(1:893:8*893);
%e(9:16)=p(13*893:893:20*893);
%e=1./alt;
eCalc=e;
assignin('base', 'H', H);
assignin('base', 'eCalc', eCalc);
%e=e1(1:893:17857*2);
%%e=e(1:16);
%e=ones(16,1);


e1=e(1);
e2=e(2);
e3=e(3);
e4=e(4);
e5=e(5);

e6=e(6);
e7=e(7);
e8=e(8);
e9=e(9);
e10=e(10);
e11=e(11);
e12=e(12);
e13=e(13);
e14=e(14);
e15=e(15);
e16=e(16);


%lahmer TP mit nur 3dB Dämpfung, geht auch ohne equalizer
% e9=0.8719;
% e10=0.8801+i*0.01569;
% e11=0.889+i*0.02899;
% e12=0.9023+i*0.03788;
% e13=0.918+i*0.041;
% e14=0.9337+i*0.03788;
% e15=0.947+i*0.02899;
% e16=0.9559+i*0.01569;
% e1=0.9641;
% e2=0.9559-i*0.01569;
% e3=0.947-i*0.02899;
% e4=0.9337-i*0.03788;
% e5=0.918-i*0.041;
% e6=0.9023-i*0.03788;
% e7=0.889-i*0.02899;
% e8=0.8801-i*0.01569;


%TP zweiter Ordnung
% e9=0.1774;
% e10=0.2303+i*0.1007;
% e11=0.2874+i*0.1861;
% e12=0.3728+i*0.2432;
% e13=0.4735+i*0.2632;
% e14=0.5742+i*0.2432;
% e15=0.6597+i*0.1861;
% e16=0.7167+i*0.1007;
% e1=0.7697;
% e2=0.7167-i*0.1007;
% e3=0.6597-i*0.1861;
% e4=0.5742-i*0.2432;
% e5=0.4735-i*0.2632;
% e6=0.3728-i*0.2432;
% e7=0.2874-i*0.1861;
% e8=0.2303-i*0.1007;

%TP triangular 7dB
% e9=0.1444;
% e10=0.5777+i*0.05527;
% e11=0.609+i*0.1021;
% e12=0.6559+i*0.1334;
% e13=0.7111+i*0.1444;
% e14=0.7664+i*0.1334;
% e15=0.8133+i*0.1021;
% e16=0.8446+i*0.05527;
% e1=-0.1444;
% e2=0.8446-i*0.05527;
% e3=0.8133-i*0.1021;
% e4=0.7664-i*0.1334;
% e5=0.7111-i*0.1444;
% e6=0.6559-i*0.1334;
% e7=0.609-i*0.1021;
% e8=0.5777-i*0.05527;

%%TP zweiter ordnung, Fenstermethode, Hamming-window, fc=5MHz, Fs=35.71MHz,
%2.5dB
% e9= 0.03073- i*0.03073;
% e10=0.8892-i*0.02414;
% e11=0.8702-i*0.01663;
% e12=0.8514-i*0.008479;
% e13=0.8336;
% e14=0.8175+i*0.008479;
% e15=0.8037+i*0.01663;
% e16=0.7927+i*0.02414;
% e1=-0.06146;
% e2=0.9735-i*0.03614;
% e3=0.974-i*0.04015;
% e4=0.9708-i*0.04262;
% e5=0.964-i*0.04346;
% e6=0.9538-i*0.04262;
% e7=0.9407-i*0.04015;
% e8=0.9252-i*0.03614;

elook=[e1 e2 e3 e4 e5 e6 e7 e8 e9 e10 e11 e12 e13 e14 e15 e16];
assignin('base', 'elook', elook);
assignin('base', 'e', e);
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
assignin('base', 'e16', e16);
%%%%SYSGEN-BLOCKS%%%%%

%Prepare coefficients for sysgen
e1s=1/e1;
e2s=1/e2;
e3s=1/e3;
e4s=1/e4;
e5s=1/e5;
e6s=1/e6;
e7s=1/e7;
e8s=1/e8;
e9s=1/e9;
e10s=1/e10;
e11s=1/e11;
e12s=1/e12;
e13s=1/e13;
e14s=1/e14;
e15s=1/e15;
e16s=1/e16;

assignin('base', 'e1_re', real(e1s));
assignin('base', 'e1_im', imag(e1s));
assignin('base', 'e2_re', real(e2s));
assignin('base', 'e2_im', imag(e2s));
assignin('base', 'e3_re', real(e3s));
assignin('base', 'e3_im', imag(e3s));
assignin('base', 'e4_re', real(e4s));
assignin('base', 'e4_im', imag(e4s));
assignin('base', 'e5_re', real(e5s));
assignin('base', 'e5_im', imag(e5s));
assignin('base', 'e6_re', real(e6s));
assignin('base', 'e6_im', imag(e6s));
assignin('base', 'e7_re', real(e7s));
assignin('base', 'e7_im', imag(e7s));
assignin('base', 'e8_re', real(e8s));
assignin('base', 'e8_im', imag(e8s));
assignin('base', 'e9_re', real(e9s));
assignin('base', 'e9_im', imag(e9s));
assignin('base', 'e10_re', real(e10s));
assignin('base', 'e10_im', imag(e10s));
assignin('base', 'e11_re', real(e11s));
assignin('base', 'e11_im', imag(e11s));
assignin('base', 'e12_re', real(e12s));
assignin('base', 'e12_im', imag(e12s));
assignin('base', 'e13_re', real(e13s));
assignin('base', 'e13_im', imag(e13s));
assignin('base', 'e14_re', real(e14s));
assignin('base', 'e14_im', imag(e14s));
assignin('base', 'e15_re', real(e15s));
assignin('base', 'e15_im', imag(e15s));
assignin('base', 'e16_re', real(e16s));
assignin('base', 'e16_im', imag(e16s));


%Outputs all block paths
%BlockPaths = find_system('Basic_DMT','Type','Block')
