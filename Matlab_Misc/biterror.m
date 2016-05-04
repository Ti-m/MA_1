%biterror.m
close all, clear
Fs=16/896e-9;
Rb=62.5e6;
SNRdb = 0:0.1:20-0.1;
SNR=10.^(SNRdb/10);

pb=3/2*erfc(sqrt(SNR*2*Fs/5/Rb));
semilogy(SNRdb,pb)