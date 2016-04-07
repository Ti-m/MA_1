


sig = [0 1-1i 1-1i 1-1i 1-1i 1-1i 1-1i 1-1i  0 1-1i 1-1i 1-1i 1-1i 1-1i 1-1i 1-1i ];
SIG = ifft(sig)*16;
%insert GI
% some extra value to handle transient effects
SIG_GI = [-2+2i 0 -2+2i 0 -2+2i 0 -2+2i 0 SIG];

%Channel influence
a0=0.061461097527179653;
 a1=0.8770778049456408;
 a2=a0;
h=[a0 a1 a2];

SIG_CHN = filter(h,1,SIG_GI);
%SIG_CHN = SIG_GI;
 
SIG_RMV_GI = SIG_CHN(end-15:end);
sig_rcv = fft(SIG_RMV_GI)/16;
%equalizer
H=fft(h,16);
sig_eql= sig_rcv./H;


% 
% for i=1:length(equal1)
% erg1(:,i)=equal1(i)*e;
% erg2(:,i)=equal2(i)*e;
% end