%Ausprobieren von der Halbierung der FFT Länge bei DMT. Geht nur für reelle
%Eingangswerte, daher nicht für komplexe Modulation geeignet.

%http://www2.units.it/ramponi/teaching/DSP/materiale/Ch3(3).pdf

x=zeros(8,1);
x(1)=1;%0 g
x(2)=2;%1 u
x(3)=2;%2 g
x(4)=2;%3 u
x(5)=0;%3 g
x(6)=1;%3 u
x(7)=1;%3 g
x(8)=1;%3 u
X_normal = fft(x)

xg=[x(1); x(3) ; x(5) ; x(7)];
xu=[x(2); x(4) ; x(6) ; x(8)];

% Xg=fft(xg);
% Xu=fft(xu);
% 
% 
% X_VLM =[Xg(1);
%         Xu(1)*exp(-1i*2*pi*2/4);
%         Xg(2);
%         Xu(2)*exp(-1i*2*pi*4/4)]

y=xg+1i*xu;
Y=fft(y);
C=conj(Y);
B=[C(1); C(3); C(2); C(1)];
for k=1:4
Xg(k)=(Y(k)+B(k))/2;
Xu(k)=(Y(k)+B(k))/(2i);
end

X_VLM =[
        Xg(1)+ Xu(1);         
        Xg(2)+ Xu(2)*exp(-1i*2*pi*1/8);
        Xg(3)+ Xu(3)*exp(-1i*2*pi*2/8);
        Xg(4)+ Xu(4)*exp(-1i*2*pi*3/8);
        Xg(1)+ Xu(1)*exp(-1i*2*pi*4/8);
        Xg(2)+ Xu(2)*exp(-1i*2*pi*5/8);
        Xg(3)+ Xu(3)*exp(-1i*2*pi*3/8);
        Xg(4)+ Xu(4)*exp(-1i*2*pi*1/8);
        ]