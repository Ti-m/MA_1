function [ out_re, out_im, pop, o1_re , o2_re , o3_re, o4_re , o5_re,...
    o6_re , o7_re , o8_re , o9_re , o10_re, o11_re, o12_re, o13_re,...
    o14_re, o15_re, o16_re, o1_im , o2_im , o3_im, o4_im , o5_im ,...
    o6_im , o7_im , o8_im , o9_im , o10_im, o11_im, o12_im, o13_im,...
    o14_im, o15_im, o16_im,  stateo ]= sg_fsm_GI_OFDM( inp_re,inp_im,...
    frameEn, i1_re , i2_re , i3_re, i4_re , i5_re , i6_re , i7_re , ...
    i8_re , i9_re , i10_re, i11_re, i12_re, i13_re, i14_re, i15_re, ...
    i16_re, i1_im , i2_im , i3_im, i4_im , i5_im , i6_im , i7_im ,...
    i8_im , i9_im , i10_im, i11_im, i12_im, i13_im, i14_im, i15_im,...
    i16_im,  statei )
%
%
o1_re=i1_re;
o2_re=i2_re;
o3_re=i3_re;
o4_re=i4_re;
o5_re=i5_re;
o6_re=i6_re;
o7_re=i7_re;
o8_re=i8_re;
o9_re=i9_re;
o10_re=i10_re;
o11_re=i11_re;
o12_re=i12_re;
o13_re=i13_re;
o14_re=i14_re;
o15_re=i15_re;
o16_re=i16_re;
o1_im=i1_im;
o2_im=i2_im;
o3_im=i3_im;
o4_im=i4_im;
o5_im=i5_im;
o6_im=i6_im;
o7_im=i7_im;
o8_im=i8_im;
o9_im=i9_im;
o10_im=i10_im;
o11_im=i11_im;
o12_im=i12_im;
o13_im=i13_im;
o14_im=i14_im;
o15_im=i15_im;
o16_im=i16_im;
pop = 0;
out_re = 0;
out_im = 0;

switch statei
    case 0       
        if frameEn %loopCount == 1            
            statei=1;           
        else
            statei=0;            
        end
        
    case 1%Input
        o1_re=inp_re;
        o1_im=inp_im;
        statei=2;       
    case 2
        o2_re=inp_re;
        o2_im=inp_im;
        statei=3;
    case 3
        o3_re=inp_re;
        o3_im=inp_im;
        statei=4;
    case 4
        o4_re=inp_re;
        o4_im=inp_im;
        statei=5;
    case 5
        o5_re=inp_re;
        o5_im=inp_im;
        statei=6;
    case 6
        o6_re=inp_re;
        o6_im=inp_im;
        statei=7;
    case 7
        o7_re=inp_re;
        o7_im=inp_im;
        statei=8;
    case 8
        o8_re=inp_re;
        o8_im=inp_im;
        statei=9;
    case 9
        o9_re=inp_re;
        o9_im=inp_im;
        statei=10;
    case 10
        o10_re=inp_re;
        o10_im=inp_im;
        statei=11;
    case 11
        o11_re=inp_re;
        o11_im=inp_im;
        statei=12;
    case 12
        o12_re=inp_re;
        o12_im=inp_im;
        statei=13;
    case 13%Output prefix and Input
        o13_re=inp_re;
        o13_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=14;
    case 14
        o14_re=inp_re;
        o14_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=15;
    case 15
        o15_re=inp_re;
        o15_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=16;
    case 16
        o16_re=inp_re;
        o16_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=17;
    case 17%Only Output
        out_re=i1_re;
        out_im=i1_im;
        pop=1;
        statei=18;
    case 18
        out_re=i2_re;
        out_im=i2_im;
        pop=1;
        statei=19;
    case 19
        out_re=i3_re;
        out_im=i3_im;
        pop=1;
        statei=20;
    case 20
        out_re=i4_re;
        out_im=i4_im;
        pop=1;
        statei=21;
    case 21
        out_re=i5_re;
        out_im=i5_im;
        pop=1;
        statei=22;
    case 22
        out_re=i6_re;
        out_im=i6_im;
        pop=1;
        statei=23;
    case 23
        out_re=i7_re;
        out_im=i7_im;
        pop=1;
        statei=24;
    case 24
        out_re=i8_re;
        out_im=i8_im;
        pop=1;
        statei=25;
    case 25
        out_re=i9_re;
        out_im=i9_im;
        pop=1;
        statei=26;
    case 26
        out_re=i10_re;
        out_im=i10_im;
        pop=1;
        statei=27;
    case 27
        out_re=i11_re;
        out_im=i11_im;
        pop=1;
        statei=28;
    case 28
        out_re=i12_re;
        out_im=i12_im;
        pop=1;
        statei=29;
    case 29
        out_re=i13_re;
        out_im=i13_im;
        pop=1;
        statei=30;
    case 30
        out_re=i14_re;
        out_im=i14_im;
        pop=1;
        statei=31;
    case 31
        out_re=i15_re;
        out_im=i15_im;
        pop=1;
        statei=32;
    case 32
        out_re=i16_re;
        out_im=i16_im;
        pop=1;
        statei=0;
end

stateo =statei;


  end
