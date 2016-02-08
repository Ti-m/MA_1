%%SystemSpec.m
%SystemSpecification
clear,clc
format shortEng

%% Bit rate
%Channel coding code rate
R_c = 1

% Data Bitrate bit/sec
R_b = 50e6

% Raw Transmission rate
R_r = R_b / R_c

% Duration bit
T_bit = 1/R_r

%%%%%%%%%%%%%%%OFDM Parameter%%%%%%%%%%%%%%%
%Guard interval duration
% The Guard interval has to be greater than the impulse response of the
% channel. In the thesis of Manuel Gertje a duration of 20us is chosen for
% a typical radio channel in hilly terrain 10 . In the wired situation,
% a duration no longer then 1us can be assumed.
%T_G = 1.428e-6

%% Bandwidth effiency. Ratio  N_FFT/(N_FFT+N_GI)
%Typical value from Kammayer S.590
beta = 0.8

% Bit per Symbol with 16-QAM
M = log2(16)


%% FFT Len OFDM
N_FFT = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096]

%% Unuesed Carriers, constant 5 from IEE802.11a
%Is there a better value?
%N_unused_carr = ceil(N_FFT/5)
N_unused_carr = 2

%% Used Carriers
N_FFT_used = N_FFT - N_unused_carr

%% Number of GI samples
N_GI = N_FFT/beta - N_FFT


%% Sample time for each individual subcarrier during modulation. (Parallel)
%Is the duration to collect enough samples for a new OFDM symbol.
T_subcarrier = N_FFT_used * T_bit * M ;

%% Sample time after the aggregation through the FFT. (Serial)
T_FFT =T_subcarrier ./ N_FFT;

%% Sample time on the channel with GI. (Serial)
T_Chan = T_FFT * beta;

%% Duration OFDM full transmission

T_OFDM = T_Chan .* (N_FFT+N_GI)

%% Duration Payload 
T_Sym = T_Chan .* N_FFT

%% Duration of GI
T_GI =T_Chan .* N_GI

%Subcarriercount needed to reach Datarate in T_Sym
% *2 for use of DMT
%%%%T_OFDM anstelle von T_Sym??????%%%%%%%
%N_FFT_needed = ceil(T_OFDM/(T_bit*M))
%N_FFT_needed = (T_OFDM/(T_bit*M))

%N_FFT_used = 0; k=1;
%while N_FFT_needed >= N_FFT_used

%FFT Len OFDM
%N_FFT = 2^nextpow2(N_FFT_needed*k);

%Unuesed Carriers, constant 5 from IEE802.11a
%Is there a better value?
%N_unused_carr = floor(N_FFT/5);

%Used Carriers
%N_FFT_used = N_FFT - N_unused_carr;

%k=k+1;
%end
%N_FFT


%% Bit per OFDM Symbol
N_bit_OFDM_symb = N_FFT_used * M 

%% OFDM Symbols needed per second to reach transmission speed
R_OFDM_Symb = R_r./ N_bit_OFDM_symb

%Bits_per_second = R_OFDM_Symb .* N_bit_OFDM_symb %redundant


%FS_OFDM = (4 * N_FFT)./(N_FFT_used.*T_bit.*M.*beta)
FS_OFDM = N_FFT./(N_FFT_used.*T_bit.*M.*beta)
%% N_FFT mit DMT
% N_FFT = N_FFT *2
% N_unused_carr = N_unused_carr *2
% N_FFT_used = N_FFT_used * 2
%% Required Bandwidth for OFDM
%The Bandwidth for a single subcarrier is the same for DMT and OFDM. Its
%calculated not with the full OFDM symbol time but the payload time. After
%insertion of the GI just the carriers are getting smaller and the
%orthogonality is broken.
B_SC=1./T_subcarrier
%B_OFDM=B_SC.*N_FFT
B_OFDM=1./T_Chan
%% Required Bandwidth for DMT
%B_DMT=B_SC.*N_FFT*2
B_DMT=2./T_Chan

%% Required Sampling Frequency for sampling theorem
Fs_min_OFDM=2*B_OFDM
Fs_min_DMT=2*B_DMT
%%%%%%%%%%%%%%%%%%%%%%%%%%%%ADC/DAC%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% SignaleRange/FullscaleRange 
%http://www.dataq.com/data-acquisition/general-education-tutorials/fact-folly-mathematics-analog-digital-converter-resolution.html
RangeSignal = 10
RangeFullScale = 12

RangeDiv=RangeSignal/RangeFullScale

%% Temp 20 Degree Celsius in K
Temp = 293
Boltzmann = 1.3806488e-23
%N0 for Real valued channel in W/Hz
N0=Boltzmann * Temp * 2

%Thermical noise at receiver
P_n = N0 * B_DMT

%% Bit from Symbols
N_bit_sign =3 %16-QAM

% Additional Bit from Noise

% Additional Bit from PAPR
% PAR *4 corresponds to 12dB
N_bit_PAPR = 2

Bit_FracLen = 13

%ADC Resolution
Converter_Resolution = N_bit_sign + N_bit_PAPR + Bit_FracLen

%%%%%%%%%%%%%%%%%%%%%%%%%%%%FPGA%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Max CLK for FPGA PL with internal oszilator through PS block, higher with
%external source
Max_CLK = 250e6

%Number of multiplications for FFT (80%-90% of effort)
FFT_multiplication_complex = N_FFT/2.*log2(N_FFT)
FFT_multiplication_real = FFT_multiplication_complex *4

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%FS2 = (4 * N_FFT)./(N_FFT_used.*T_bit.*M.*beta)
