close all
Ts11=28e-9;
Fs11=1/Ts11;
fstep11=Fs11/1024;
f11=-Fs11/2:fstep11:Fs11/2-fstep11;

a11=Test(632:671);
A11=fftshift(fft(a11,1024));
plot(f11,20*log10(abs(A11))),grid
hold
plot(f11,20*log10(fftshift(abs(e))))
