%OFDM
beta = 0.8


Tb=20e-9 * beta
M=4;%Modulationskonstante
N=16;%FFTLEN

G= N/beta-N

U=14;%Used carrier

Ts=M*U/N*Tb
Bsub=1/(M*U*Tb)
B=N*Bsub
T1=Ts/2
T2=T1*U
%TR=TD/2
%ggt=gcd(sym([Tb, Ts, T1, T2]))

%Optimierungsproblem? http://de.mathworks.com/products/optimization/features.html#definieren-und-l%C3%B6sen-von-optimierungsproblemen

%DMT
N_DMT= 2*N;
B_DMT=N_DMT*Bsub
G_DMT= N_DMT/beta-N_DMT
Ts_DMT=M*U/N_DMT*Tb
T1_DMT = Ts_DMT/2
T2_DMT=T1_DMT*U

ggt=gcd(sym([Tb, Ts_DMT, T1_DMT, T2_DMT, T1, T2]))
ggt=gcd(sym([Tb, Ts_DMT]))

% %OFDM
% Ts=20e-9;
% B=4;%Modulationskonstante
% N=16;%FFTLEN
% G=N/4;%GI_LEN
% U=N-2;%Used carrier
% 
% TD=B*U/N*Ts
% TF=TD/((N+G)/N)
% %TR=TD/2
% ggt=gcd(sym([Ts, TD]))
% 
% %Optimierungsproblem? http://de.mathworks.com/products/optimization/features.html#definieren-und-l%C3%B6sen-von-optimierungsproblemen
% 
% %DMT
% N_DMT= 2*N;
% G_DMT=N_DMT/4;
% 
% TD_DMT=B*U/N_DMT*Ts
% TF_DMT=TD_DMT/((N_DMT+G_DMT)/N_DMT)
% %TR_DMT=TD_DMT/2
% 
% ggt=gcd(sym([Ts, TD_DMT]))