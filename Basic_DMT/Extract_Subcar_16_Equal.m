function [y1_re,  y1_im,  y2_re,  y2_im,  y3_re,  y3_im,  y4_re, y4_im,...
          y5_re,  y5_im,  y6_re,  y6_im,  y7_re,  y7_im,  y8_re, y8_im,...
          y9_re,  y9_im,  y10_re, y10_im, y11_re, y11_im, y12_re, y12_im,...
          y13_re, y13_im, y14_re, y14_im, y15_re, y15_im, y16_re, y16_im...
          ]= Extract_Subcar_16_Equal(...
          x_re,x_im,M,fracLen,bitCount,...
          e1_re, e1_im, e2_re, e2_im, e3_re, e3_im, e4_re, e4_im,...
          e5_re, e5_im, e6_re, e6_im, e7_re, e7_im, e8_re, e8_im,...
          e9_re, e9_im, e10_re,e10_im,e11_re,e11_im,e12_re,e12_im,...
          e13_re,e13_im,e14_re,e14_im,e15_re,e15_im,e16_re,e16_im)
%  M=4;
%  fracLen=13;
%  bitCount=16;
%Some ideas from UG958 
x1_re  = xl_slice(x_re, (bitCount+(M+1)*2)*16-1, (bitCount+(M+1)*2)*15); 
x2_re  = xl_slice(x_re, (bitCount+(M+1)*2)*15-1, (bitCount+(M+1)*2)*14); 
x3_re  = xl_slice(x_re, (bitCount+(M+1)*2)*14-1, (bitCount+(M+1)*2)*13);  
x4_re  = xl_slice(x_re, (bitCount+(M+1)*2)*13-1, (bitCount+(M+1)*2)*12); 
x5_re  = xl_slice(x_re, (bitCount+(M+1)*2)*12-1, (bitCount+(M+1)*2)*11);  
x6_re  = xl_slice(x_re, (bitCount+(M+1)*2)*11-1, (bitCount+(M+1)*2)*10); 
x7_re  = xl_slice(x_re, (bitCount+(M+1)*2)*10-1, (bitCount+(M+1)*2)*9);  
x8_re  = xl_slice(x_re, (bitCount+(M+1)*2)*9-1 , (bitCount+(M+1)*2)*8); 
x9_re  = xl_slice(x_re, (bitCount+(M+1)*2)*8-1 , (bitCount+(M+1)*2)*7);  
x10_re = xl_slice(x_re, (bitCount+(M+1)*2)*7-1 , (bitCount+(M+1)*2)*6); 
x11_re = xl_slice(x_re, (bitCount+(M+1)*2)*6-1 , (bitCount+(M+1)*2)*5);  
x12_re = xl_slice(x_re, (bitCount+(M+1)*2)*5-1 , (bitCount+(M+1)*2)*4); 
x13_re = xl_slice(x_re, (bitCount+(M+1)*2)*4-1 , (bitCount+(M+1)*2)*3);  
x14_re = xl_slice(x_re, (bitCount+(M+1)*2)*3-1 , (bitCount+(M+1)*2)*2);
x15_re = xl_slice(x_re, (bitCount+(M+1)*2)*2-1 , (bitCount+(M+1)*2)*1);  
x16_re = xl_slice(x_re, (bitCount+(M+1)*2)-1   , 0  );

x1_im  = xl_slice(x_im, (bitCount+(M+1)*2)*16-1, (bitCount+(M+1)*2)*15); 
x2_im  = xl_slice(x_im, (bitCount+(M+1)*2)*15-1, (bitCount+(M+1)*2)*14); 
x3_im  = xl_slice(x_im, (bitCount+(M+1)*2)*14-1, (bitCount+(M+1)*2)*13);  
x4_im  = xl_slice(x_im, (bitCount+(M+1)*2)*13-1, (bitCount+(M+1)*2)*12); 
x5_im  = xl_slice(x_im, (bitCount+(M+1)*2)*12-1, (bitCount+(M+1)*2)*11);  
x6_im  = xl_slice(x_im, (bitCount+(M+1)*2)*11-1, (bitCount+(M+1)*2)*10); 
x7_im  = xl_slice(x_im, (bitCount+(M+1)*2)*10-1, (bitCount+(M+1)*2)*9);  
x8_im  = xl_slice(x_im, (bitCount+(M+1)*2)*9-1 , (bitCount+(M+1)*2)*8); 
x9_im  = xl_slice(x_im, (bitCount+(M+1)*2)*8-1 , (bitCount+(M+1)*2)*7);  
x10_im = xl_slice(x_im, (bitCount+(M+1)*2)*7-1 , (bitCount+(M+1)*2)*6); 
x11_im = xl_slice(x_im, (bitCount+(M+1)*2)*6-1 , (bitCount+(M+1)*2)*5);  
x12_im = xl_slice(x_im, (bitCount+(M+1)*2)*5-1 , (bitCount+(M+1)*2)*4); 
x13_im = xl_slice(x_im, (bitCount+(M+1)*2)*4-1 , (bitCount+(M+1)*2)*3);  
x14_im = xl_slice(x_im, (bitCount+(M+1)*2)*3-1 , (bitCount+(M+1)*2)*2);
x15_im = xl_slice(x_im, (bitCount+(M+1)*2)*2-1 , (bitCount+(M+1)*2)*1);  
x16_im = xl_slice(x_im, (bitCount+(M+1)*2-1)   , 0  );

tmp_y1_re = xl_force(x1_re,xlSigned,fracLen);
tmp_y2_re = xl_force(x2_re,xlSigned,fracLen);
tmp_y3_re = xl_force(x3_re,xlSigned,fracLen);
tmp_y4_re = xl_force(x4_re,xlSigned,fracLen);
tmp_y5_re = xl_force(x5_re,xlSigned,fracLen);
tmp_y6_re = xl_force(x6_re,xlSigned,fracLen);
tmp_y7_re = xl_force(x7_re,xlSigned,fracLen);
tmp_y8_re = xl_force(x8_re,xlSigned,fracLen);
tmp_y9_re = xl_force(x9_re,xlSigned,fracLen);
tmp_y10_re = xl_force(x10_re,xlSigned,fracLen);
tmp_y11_re = xl_force(x11_re,xlSigned,fracLen);
tmp_y12_re = xl_force(x12_re,xlSigned,fracLen);
tmp_y13_re = xl_force(x13_re,xlSigned,fracLen);
tmp_y14_re = xl_force(x14_re,xlSigned,fracLen);
tmp_y15_re = xl_force(x15_re,xlSigned,fracLen);
tmp_y16_re = xl_force(x16_re,xlSigned,fracLen);

tmp_y1_im = xl_force(x1_im,xlSigned,fracLen);
tmp_y2_im = xl_force(x2_im,xlSigned,fracLen);
tmp_y3_im = xl_force(x3_im,xlSigned,fracLen);
tmp_y4_im = xl_force(x4_im,xlSigned,fracLen);
tmp_y5_im = xl_force(x5_im,xlSigned,fracLen);
tmp_y6_im = xl_force(x6_im,xlSigned,fracLen);
tmp_y7_im = xl_force(x7_im,xlSigned,fracLen);
tmp_y8_im = xl_force(x8_im,xlSigned,fracLen);
tmp_y9_im = xl_force(x9_im,xlSigned,fracLen);
tmp_y10_im = xl_force(x10_im,xlSigned,fracLen);
tmp_y11_im = xl_force(x11_im,xlSigned,fracLen);
tmp_y12_im = xl_force(x12_im,xlSigned,fracLen);
tmp_y13_im = xl_force(x13_im,xlSigned,fracLen);
tmp_y14_im = xl_force(x14_im,xlSigned,fracLen);
tmp_y15_im = xl_force(x15_im,xlSigned,fracLen);
tmp_y16_im = xl_force(x16_im,xlSigned,fracLen);

%Equalizer (normally a complex divsion has to be performed, but the mcode
%block only supports division by power of 2. So the coefficients are
%prepared in matlab(1/e))

%convert coefficients from double to fixpoint
e1_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e1_re);
e2_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e2_re);
e3_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e3_re);
e4_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e4_re);
e5_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e5_re);
e6_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e6_re);
e7_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e7_re);
e8_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e8_re);
e9_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e9_re);
e10_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e10_re);
e11_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e11_re);
e12_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e12_re);
e13_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e13_re);
e14_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e14_re);
e15_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e15_re);
e16_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e16_re);

e1_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e1_im);
e2_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e2_im);
e3_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e3_im);
e4_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e4_im);
e5_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e5_im);
e6_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e6_im);
e7_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e7_im);
e8_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e8_im);
e9_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e9_im);
e10_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e10_im);
e11_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e11_im);
e12_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e12_im);
e13_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e13_im);
e14_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e14_im);
e15_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e15_im);
e16_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, e16_im);

%apply coefficients (complex multiplication)
y1_re = tmp_y1_re*e9_re- tmp_y1_im*e9_im;
y2_re = tmp_y2_re*e10_re- tmp_y2_im*e10_im;
y3_re = tmp_y3_re*e11_re- tmp_y3_im*e11_im;
y4_re = tmp_y4_re*e12_re- tmp_y4_im*e12_im;
y5_re = tmp_y5_re*e13_re- tmp_y5_im*e13_im;
y6_re = tmp_y6_re*e14_re- tmp_y6_im*e14_im;
y7_re = tmp_y7_re*e15_re- tmp_y7_im*e15_im;
y8_re = tmp_y8_re*e16_re- tmp_y8_im*e16_im;
y9_re = tmp_y9_re*e1_re- tmp_y9_im*e1_im;
y10_re = tmp_y10_re*e2_re- tmp_y10_im*e2_im;
y11_re = tmp_y11_re*e3_re- tmp_y11_im*e3_im;
y12_re = tmp_y12_re*e4_re- tmp_y12_im*e4_im;
y13_re = tmp_y13_re*e5_re- tmp_y13_im*e5_im;
y14_re = tmp_y14_re*e6_re- tmp_y14_im*e6_im;
y15_re = tmp_y15_re*e7_re- tmp_y15_im*e7_im;
y16_re = tmp_y16_re*e8_re- tmp_y16_im*e8_im;

y1_im = tmp_y1_re*e9_im+ tmp_y1_im*e9_re;
y2_im = tmp_y2_re*e10_im+ tmp_y2_im*e10_re;
y3_im = tmp_y3_re*e11_im+ tmp_y3_im*e11_re;
y4_im = tmp_y4_re*e12_im+ tmp_y4_im*e12_re;
y5_im = tmp_y5_re*e13_im+ tmp_y5_im*e13_re;
y6_im = tmp_y6_re*e14_im+ tmp_y6_im*e14_re;
y7_im = tmp_y7_re*e15_im+ tmp_y7_im*e15_re;
y8_im = tmp_y8_re*e16_im+ tmp_y8_im*e16_re;
y9_im = tmp_y9_re*e1_im+ tmp_y9_im*e1_re;
y10_im = tmp_y10_re*e2_im+ tmp_y10_im*e2_re;
y11_im = tmp_y11_re*e3_im+ tmp_y11_im*e3_re;
y12_im = tmp_y12_re*e4_im+ tmp_y12_im*e4_re;
y13_im = tmp_y13_re*e5_im+ tmp_y13_im*e5_re;
y14_im = tmp_y14_re*e6_im+ tmp_y14_im*e6_re;
y15_im = tmp_y15_re*e7_im+ tmp_y15_im*e7_re;
y16_im = tmp_y16_re*e8_im+ tmp_y16_im*e8_re;

% y1_re = xl_force(y1_re,xlSigned,fracLen);
% y2_re = xl_force(y2_re,xlSigned,fracLen);
% y3_re = xl_force(y3_re,xlSigned,fracLen);
% y4_re = xl_force(y4_re,xlSigned,fracLen);
% y5_re = xl_force(y5_re,xlSigned,fracLen);
% y6_re = xl_force(y6_re,xlSigned,fracLen);
% y7_re = xl_force(y7_re,xlSigned,fracLen);
% y8_re = xl_force(y8_re,xlSigned,fracLen);
% y9_re = xl_force(y9_re,xlSigned,fracLen);
% y10_re = xl_force(y10_re,xlSigned,fracLen);
% y11_re = xl_force(y11_re,xlSigned,fracLen);
% y12_re = xl_force(y12_re,xlSigned,fracLen);
% y13_re = xl_force(y13_re,xlSigned,fracLen);
% y14_re = xl_force(y14_re,xlSigned,fracLen);
% y15_re = xl_force(y15_re,xlSigned,fracLen);
% y16_re = xl_force(y16_re,xlSigned,fracLen);
% 
% y1_im = xl_force(y1_im,xlSigned,fracLen);
% y2_im = xl_force(y2_im,xlSigned,fracLen);
% y3_im = xl_force(y3_im,xlSigned,fracLen);
% y4_im = xl_force(y4_im,xlSigned,fracLen);
% y5_im = xl_force(y5_im,xlSigned,fracLen);
% y6_im = xl_force(y6_im,xlSigned,fracLen);
% y7_im = xl_force(y7_im,xlSigned,fracLen);
% y8_im = xl_force(y8_im,xlSigned,fracLen);
% y9_im = xl_force(y9_im,xlSigned,fracLen);
% y10_im = xl_force(y10_im,xlSigned,fracLen);
% y11_im = xl_force(y11_im,xlSigned,fracLen);
% y12_im = xl_force(y12_im,xlSigned,fracLen);
% y13_im = xl_force(y13_im,xlSigned,fracLen);
% y14_im = xl_force(y14_im,xlSigned,fracLen);
% y15_im = xl_force(y15_im,xlSigned,fracLen);
% y16_im = xl_force(y16_im,xlSigned,fracLen);

y1_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y1_re);
y2_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y2_re);
y3_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y3_re);
y4_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y4_re);
y5_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y5_re);
y6_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y6_re);
y7_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y7_re);
y8_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y8_re);
y9_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y9_re);
y10_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y10_re);
y11_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y11_re);
y12_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y12_re);
y13_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y13_re);
y14_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y14_re);
y15_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y15_re);
y16_re = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y16_re);

y1_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y1_im);
y2_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y2_im);
y3_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y3_im);
y4_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y4_im);
y5_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y5_im);
y6_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y6_im);
y7_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y7_im);
y8_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y8_im);
y9_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y9_im);
y10_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y10_im);
y11_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y11_im);
y12_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y12_im);
y13_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y13_im);
y14_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y14_im);
y15_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y15_im);
y16_im = xfix({xlSigned, bitCount+(M+1)*2,fracLen}, y16_im);

  end
