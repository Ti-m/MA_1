%SystemSpec.m
%SystemSpecification
clear,clc

%%%%%%%%%%%%%%%Genrell%%%%%%%%%%%%%%%%%%%%%%
%Channel coding code rate
R_c = 0.5

%Data Bitrate bit/sec
R_b = 50e6

%Raw Transmission rate
R_r = R_b / R_c

%Duration bit
T_bit = 1/R_r

%%%%%%%%%%%%%%%OFDM Parameter%%%%%%%%%%%%%%%
%Guard interval duration
% The Guard interval has to be greater than the impulse response of the
% channel. In the thesis of Manuel Gertje a duration of 20us is chosen for
% a typical radio channel in hilly terrain 10 . In the wired situation,
% a duration no longer then 1us can be assumed.
T_G = 1e-6

%Bandwidth efiency. Typical value from Kammayer S.590
beta = 0.8

%OFDM Symbolduration (T_FFT)
T_Sym = T_G*beta/(1-beta)

%Bit per Symbol with 128-QAM
N_bit = log2(128)

%FFT Len OFDM
N_FFT = 2^nextpow2(ceil(T_Sym/(T_bit*N_bit)))

%Unuesed Carriers, constant 5 from IEE802.11a
%Is there a better value?
N_unused_carr = floor(N_FFT/5)

%Used Carriers
N_FFT_used = N_FFT - N_unused_carr


%Bit per OFDM Symbol
N_bit_OFDM_symb = N_FFT_used * N_bit

%OFDM Symbols per second
R_OFDM_Symb = R_r/ N_bit_OFDM_symb

%OFDM Symbolduration (T_FFT)
%T_Sym = 1/R_OFDM_Symb

%Required Bandwidth
B= R_OFDM_Symb * N_FFT
B2=1/(T_Sym)*N_FFT


%Required Sampling Frequency for sampling theorem
Fs_min=2*B2

%%%%%%%%%%%%%%%%%%%%%%%%%%%%ADC/DAC%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% SignaleRange/FullscaleRange 
%http://www.dataq.com/data-acquisition/general-education-tutorials/fact-folly-mathematics-analog-digital-converter-resolution.html
RangeSignal = 10
RangeFullScale = 12

RangeDiv=RangeSignal/RangeFullScale

%Temp 20 Degree Celsius in K
Temp = 293
Boltzmann = 1.3806488e-23
%N0 for Real valued channel in W/Hz
N0=Boltzmann * Temp * 2

%Thermical noise at receiver
P_n = N0 * B2

% Bit from Symbols
N_bit

% Additional Bit from Noise

% Additional Bit from PAPR

