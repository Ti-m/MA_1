a1=Test(4294:4294+39);
a2=Test(4294-40:4294+39-40);
a3=Test(4294-40*2:4294+39-40*2);
a4=Test(4294-40*3:4294+39-40*3);
a5=Test(4294-40*4:4294+39-40*4);
a6=Test(4294-40*5:4294+39-40*5);
a7=Test(4294-40*6:4294+39-40*6);
a8=Test(4294-40*7:4294+39-40*7);
a9=Test(4294-40*8:4294+39-40*8);
a10=Test(4294-40*9:4294+39-40*9);


A1=fftshift(fft(a1,1024));
A2=fftshift(fft(a2,1024));
A3=fftshift(fft(a3,1024));
A4=fftshift(fft(a4,1024));
A5=fftshift(fft(a5,1024));
A6=fftshift(fft(a6,1024));
A7=fftshift(fft(a7,1024));
A8=fftshift(fft(a8,1024));
A9=fftshift(fft(a9,1024));
A10=fftshift(fft(a10,1024));

Ages1=(A1+A2+A3+A4+A5)/5;
Ages2=(A1+A2+A3+A4+A5+A6+A7+A8+A9+A10)/10;

stem(20*log10(abs(Ages1)))
hold
stem(20*log10(abs(Ages2))*0.9)