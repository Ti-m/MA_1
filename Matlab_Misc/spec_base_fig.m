clear,close all
%plot_subcar
f=-4e6:1e3:4e6;
fs=16e6;
n=8000;
%impulseresponse
  a0=0.21194908595403703;
 a1=0.576101828091926;
 a2=a0;
h=[a0 , a1, a2];
 
 H = freqz(h,1,f,fs);
%subplot(2,1,1) 
%plot(f,20*log10(abs(H)),'o')
hold
a=1e6;
%pi, raster der nullsten sind in 1er
%2*16 mit fs=32e6, die breite der keulen wird 1000
b=2*8*pi;
%scale for plot
c=16;
%absolute for plot
d=16;
s1= sin(b*(f)    /fs)./(b*(f)    /fs);
s2= sin(b*(f-a)  /fs)./(b*(f-a)  /fs);
s3= sin(b*(f-a*2)/fs)./(b*(f-a*2)/fs);
s4= sin(b*(f-a*3)/fs)./(b*(f-a*3)/fs);
s5= sin(b*(f-a*4)/fs)./(b*(f-a*4)/fs);
s6= sin(b*(f+a)  /fs)./(b*(f+a)  /fs);
s7= sin(b*(f+a*2)/fs)./(b*(f+a*2)/fs);
s8= sin(b*(f+a*3)/fs)./(b*(f+a*3)/fs);
s9= sin(b*(f+a*4)/fs)./(b*(f+a*4)/fs);

%s9=  sin(b*(f+a*8) /fs)./(b*(f+a*8) /fs);
% s10= sin(b*(f-a*9) /fs)./(b*(f-a*9) /fs);
% s11= sin(b*(f-a*10)/fs)./(b*(f-a*10)/fs);
% s12= sin(b*(f-a*11)/fs)./(b*(f-a*11)/fs);
% s13= sin(b*(f-a*12)/fs)./(b*(f-a*12)/fs);
% s14= sin(b*(f-a*13)/fs)./(b*(f-a*13)/fs);
% s15= sin(b*(f-a*14)/fs)./(b*(f-a*14)/fs);
% s16= sin(b*(f-a*15)/fs)./(b*(f-a*15)/fs);
%subplot(2,1,2)
plot(f,abs(s1),f,abs(s2),f,abs(s3),f,abs(s4),f,abs(s5),f,abs(s6),f,abs(s7),f,abs(s8),f,abs(s9))

xlabel('f/Hz'),ylabel('|S_{OFDM}(f)|'),grid
%plot(f,s1.*c-d,f,s2.*c-d,f,s3.*c-d,f,s4.*c-d,f,s5.*c-d,f,s6.*c-d,...
%     f,s7.*c-d,f,s8.*c-d,f,s9.*c-d,f,s10.*c-d,f,s11.*c-d,f,s12.*c-d,...
%     f,s13.*c-d,f,s14.*c-d,f,s15.*c-d,f,s16.*c-d)
 
 %Gesamtspektrum
%  sges=    s1+s2+s3+s4+s5+s6+s7+s8+s9   +s10+s11+s12+s13+s14+s15+s16;
 
 %figure,plot(f,sges)
