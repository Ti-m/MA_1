function [y1_re,  y1_im,  y2_re,  y2_im,  y3_re,  y3_im,  y4_re, y4_im,...
          y5_re,  y5_im,  y6_re,  y6_im,  y7_re,  y7_im,  y8_re, y8_im,...
          y9_re,  y9_im,  y10_re, y10_im, y11_re, y11_im, y12_re, y12_im,...
          y13_re, y13_im, y14_re, y14_im, y15_re, y15_im, y16_re, y16_im...
          ]= Extract_Subcar_16_Equal(x_re,x_im,M,fracLen,bitCount)
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

y1_re = xl_force(x1_re,xlSigned,fracLen);
y2_re = xl_force(x2_re,xlSigned,fracLen);
y3_re = xl_force(x3_re,xlSigned,fracLen);
y4_re = xl_force(x4_re,xlSigned,fracLen);
y5_re = xl_force(x5_re,xlSigned,fracLen);
y6_re = xl_force(x6_re,xlSigned,fracLen);
y7_re = xl_force(x7_re,xlSigned,fracLen);
y8_re = xl_force(x8_re,xlSigned,fracLen);
y9_re = xl_force(x9_re,xlSigned,fracLen);
y10_re = xl_force(x10_re,xlSigned,fracLen);
y11_re = xl_force(x11_re,xlSigned,fracLen);
y12_re = xl_force(x12_re,xlSigned,fracLen);
y13_re = xl_force(x13_re,xlSigned,fracLen);
y14_re = xl_force(x14_re,xlSigned,fracLen);
y15_re = xl_force(x15_re,xlSigned,fracLen);
y16_re = xl_force(x16_re,xlSigned,fracLen);

y1_im = xl_force(x1_im,xlSigned,fracLen);
y2_im = xl_force(x2_im,xlSigned,fracLen);
y3_im = xl_force(x3_im,xlSigned,fracLen);
y4_im = xl_force(x4_im,xlSigned,fracLen);
y5_im = xl_force(x5_im,xlSigned,fracLen);
y6_im = xl_force(x6_im,xlSigned,fracLen);
y7_im = xl_force(x7_im,xlSigned,fracLen);
y8_im = xl_force(x8_im,xlSigned,fracLen);
y9_im = xl_force(x9_im,xlSigned,fracLen);
y10_im = xl_force(x10_im,xlSigned,fracLen);
y11_im = xl_force(x11_im,xlSigned,fracLen);
y12_im = xl_force(x12_im,xlSigned,fracLen);
y13_im = xl_force(x13_im,xlSigned,fracLen);
y14_im = xl_force(x14_im,xlSigned,fracLen);
y15_im = xl_force(x15_im,xlSigned,fracLen);
y16_im = xl_force(x16_im,xlSigned,fracLen);

  end
