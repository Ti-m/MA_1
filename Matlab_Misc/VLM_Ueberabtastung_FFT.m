
%-- 16.02.2016 11:52 --%
H = [ones(1,16),zweros(33),ones(1,15)]
H = [ones(1,16),zeros(1,33),ones(1,15)]
stem(H)
h=ifft(H)
figure(2)
%plot(h)
%h=ifft(H,1024)
%plot(h)
h=ifft(H)
Hi=ifft(h,1024);
plot(Hi)
plot(abs(Hi))
%-- 16.02.2016 17:00 --%