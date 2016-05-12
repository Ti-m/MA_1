%biterror.m
close all, clear
Fs=16/896e-9;
Rb=62.5e6;
SNRdb = 0:0.1:20-0.1;
SNR=10.^(SNRdb/10);

%pb=3/2*erfc(sqrt(SNR*2*Fs/5/Rb));
%pb2=3/8*erfc(sqrt(SNR*2/5*Fs/Rb));
pb3=3/8*erfc(sqrt((SNR-0.8)/10));
%semilogy(SNRdb,pb,'b',SNRdb,pb2,'r',SNRdb,pb3,'m'),grid
semilogy(SNRdb,pb3),grid
xlabel('SNR/dB')
ylabel('P_b')
%OFDM,SNR18,no_chan 
%theo 2e-4

%OFDM,SNR18,chan/equ