%plot_spec_without_GI.m
close all
%OFDM=1, DMT =2
select=1;
if select==1
    %OFDM
Ts11=56e-9;
else
    %DMT
Ts11=28e-9;
end

Fs11=1/Ts11;
fstep11=Fs11/(4096);
f11=-Fs11/2:fstep11:Fs11/2-fstep11;
bin= zeros(4096,1);
if select ==1  
%OFDM
bin(1:256:end)=30;
bin(end)=30;
a11=Test1(1745:1745+15);
else
%DMT
bin(1:128:end)=40;
bin(end)=40;
a11=Test1(2336+1:2336+1+31);
end

A11=fftshift(fft(a11,4096));
plot(f11,20*log10(abs(A11))),grid
hold
stem(f11,bin)
axis([-9e6 9e6 20 30])
xlabel('f/Hz'),ylabel('20*log(|S_{OFDM}|)'),grid
%%%plot(f11,20*log10(fftshift(abs(e))))

%stem(a11)