


sig = [0 1-1i 1-1i 1-1i 1-1i 1-1i 1-1i 1-1i  0 1-1i 1-1i 1-1i 1-1i 1-1i 1-1i 1-1i 0 1+1i 1+1i 1+1i 1+1i 1+1i 1+1i 1+1i 0 1+1i 1+1i 1+1i 1+1i 1+1i 1+1i 1+1i];
SIG = ifft(sig)*32;
%insert GI
% some extra value to handle transient effects
SIG_GI = [SIG SIG(end-7:end) SIG];

%Channel influence
a0=0.061461097527179653;
 a1=0.8770778049456408;
 a2=a0;
h=[a0 a1 a2];

SIG_CHN = filter(h,1,SIG_GI);
%SIG_CHN = SIG_GI;
 
SIG_RMV_GI = SIG_CHN(end-31:end);
sig_rcv = fft(SIG_RMV_GI)/32;
%extract subcar
sig_rcv_extr= [real(sig_rcv(1))+real(sig_rcv(17))*1i sig_rcv(2:16)];


%equalizer
H=fft(h,16);
% H2=[H(9:16) H(1:8)];
sig_eql= sig_rcv_extr./H;
% Hges = [H ; H2]

% 
% for i=1:length(equal1)
% erg1(:,i)=equal1(i)*e;
% erg2(:,i)=equal2(i)*e;
% end