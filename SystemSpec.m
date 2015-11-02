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

%% Bandwidth effiency. 
%Typical value from Kammayer S.590
beta = 0.9

% Bit per Symbol with 256-QAM
M = log2(256)


%% FFT Len OFDM
N_FFT = [32, 64, 128, 256, 512, 1024, 2048, 4096]

%% Unuesed Carriers, constant 5 from IEE802.11a
%Is there a better value?
N_unused_carr = ceil(N_FFT/5)

%% Used Carriers
N_FFT_used = N_FFT - N_unused_carr

%% OFDM full duration
T_OFDM = N_FFT_used * T_bit * M

%% OFDM Symbolduration (T_FFT)
T_G = T_OFDM/(beta/(1-beta)+1)

%% OFDM full duration
T_Sym = T_OFDM - T_G

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

%% OFDM Symbols per second
R_OFDM_Symb = R_r./ N_bit_OFDM_symb

Bits_per_second = R_OFDM_Symb .* N_bit_OFDM_symb


FS2 = (4 * N_FFT)./(N_FFT_used.*T_bit.*M.*beta)
%% N_FFT mit DMT
N_FFT = N_FFT *2
N_unused_carr = N_unused_carr *2
N_FFT_used = N_FFT_used * 2
%% Required Bandwidth
B_SC=1./(T_Sym)
B=1./(T_Sym).*N_FFT

%% Required Sampling Frequency for sampling theorem
Fs_min=2*B

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
P_n = N0 * B

%% Bit from Symbols
M

% Additional Bit from Noise

% Additional Bit from PAPR
% PAR *4 corresponds to 12dB
N_bit_PAPR = 2

%ADC Resolution
Converter_Resolution = M + N_bit_PAPR

%%%%%%%%%%%%%%%%%%%%%%%%%%%%FPGA%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Max CLK for FPGA PL with internal oszilator through PS block, higher with
%external source
Max_CLK = 250e6

%Number of multiplications for FFT (80%-90% of effort)
FFT_multiplication_complex = N_FFT/2.*log2(N_FFT)
FFT_multiplication_real = FFT_multiplication_complex *4

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%FS2 = (4 * N_FFT)./(T_bit.*M.*beta)./floor(N_FFT/10)
FS2 = (4 * N_FFT)./(N_FFT_used.*T_bit.*M.*beta)
