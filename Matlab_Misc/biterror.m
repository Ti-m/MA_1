%biterror.m
close all, clear
Fs=16/896e-9;
Rb=62.5e6;
SNRdb = 0:0.1:20-0.1;
SNR=10.^(SNRdb/10);

%pb=3/2*erfc(sqrt(SNR*2*Fs/5/Rb));
%pb2=3/8*erfc(sqrt(SNR*2/5*Fs/Rb));
pb1=3/8*erfc(sqrt(SNR/10));
pb2=3/8*erfc(sqrt((SNR-0.8 ) /10));
pb3=3/8*erfc(sqrt((SNR*0.7)/10));
semilogy(SNRdb,pb1,'b',SNRdb,pb2,'m',SNRdb,pb3,'k'),grid
%semilogy(SNRdb,pb3),grid
xlabel('SNR/dB')
ylabel('P_b')
%OFDM,SNR18,no_chan 
%theo 2e-4

%OFDM,SNR18,chan/equ