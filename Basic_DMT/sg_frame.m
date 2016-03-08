function [ o1 , o2 , o3 , o4 , o5 , o6 , o7 , o8 , o9 , o10, o11, o12, ...
                o13, o14, o15, o16] = sg_frame(...
           i1 , i2 , i3 , i4 , i5 , i6 , i7 , i8 , i9 , i10, i11, i12, ...
                i13, i14, i15, i16, u1 , u2 , u3 , u4 , u5 , u6 , u7 , ...
                u8 , u9 , u10, u11, u12, u13, u14, u15, u16, bitCount, fracLen)
%Sets subcarriers to Zero
o1=xfix({xlSigned, bitCount,fracLen}, i1*xfix({xlUnsigned, 1,0}, u1));
o2=xfix({xlSigned, bitCount,fracLen}, i2*xfix({xlUnsigned, 1,0}, u2));
o3=xfix({xlSigned, bitCount,fracLen}, i3*xfix({xlUnsigned, 1,0}, u3));
o4=xfix({xlSigned, bitCount,fracLen}, i4*xfix({xlUnsigned, 1,0}, u4));
o5=xfix({xlSigned, bitCount,fracLen}, i5*xfix({xlUnsigned, 1,0}, u5));
o6=xfix({xlSigned, bitCount,fracLen}, i6*xfix({xlUnsigned, 1,0}, u6));
o7=xfix({xlSigned, bitCount,fracLen}, i7*xfix({xlUnsigned, 1,0}, u7));
o8=xfix({xlSigned, bitCount,fracLen}, i8*xfix({xlUnsigned, 1,0}, u8));
o9=xfix({xlSigned, bitCount,fracLen}, i9*xfix({xlUnsigned, 1,0}, u9));
o10=xfix({xlSigned, bitCount,fracLen}, i10*xfix({xlUnsigned, 1,0}, u10));
o11=xfix({xlSigned, bitCount,fracLen}, i11*xfix({xlUnsigned, 1,0}, u11));
o12=xfix({xlSigned, bitCount,fracLen}, i12*xfix({xlUnsigned, 1,0}, u12));
o13=xfix({xlSigned, bitCount,fracLen}, i13*xfix({xlUnsigned, 1,0}, u13));
o14=xfix({xlSigned, bitCount,fracLen}, i14*xfix({xlUnsigned, 1,0}, u14));
o15=xfix({xlSigned, bitCount,fracLen}, i15*xfix({xlUnsigned, 1,0}, u15));
o16=xfix({xlSigned, bitCount,fracLen}, i16*xfix({xlUnsigned, 1,0}, u16));

            
end
