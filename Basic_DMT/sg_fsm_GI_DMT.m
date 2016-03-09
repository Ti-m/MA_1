function [ out_re, out_im, pop, o1_re , o2_re , o3_re, o4_re , o5_re ,...
    o6_re , o7_re , o8_re , o9_re , o10_re, o11_re, o12_re, o13_re, ...
    o14_re, o15_re, o16_re,  o17_re , o18_re , o19_re, o20_re , ...
    o21_re , o22_re , o23_re , o24_re , o25_re , o26_re, o27_re, ...
    o28_re, o29_re, o30_re, o31_re, o32_re, o1_im , o2_im , o3_im, ...
    o4_im , o5_im , o6_im , o7_im , o8_im , o9_im , o10_im, o11_im,...
    o12_im, o13_im, o14_im, o15_im, o16_im, o17_im , o18_im , o19_im, ...
    o20_im , o21_im , o22_im , o23_im , o24_im , o25_im , o26_im, ...
    o27_im, o28_im, o29_im, o30_im, o31_im, o32_im,  stateo ]= ...
    sg_fsm_GI_DMT( inp_re,inp_im, frameEn, i1_re , i2_re , i3_re,...
    i4_re , i5_re , i6_re , i7_re , i8_re , i9_re , i10_re, i11_re,...
    i12_re, i13_re, i14_re, i15_re, i16_re, i17_re , i18_re , i19_re,...
    i20_re , i21_re , i22_re , i23_re , i24_re , i25_re , i26_re, ...
    i27_re, i28_re, i29_re, i30_re, i31_re, i32_re, i1_im , i2_im , ...
    i3_im, i4_im , i5_im , i6_im , i7_im , i8_im , i9_im , i10_im, ...
    i11_im, i12_im, i13_im, i14_im, i15_im, i16_im, i17_im , i18_im ...
    , i19_im, i20_im , i21_im , i22_im , i23_im , i24_im , i25_im , ...
    i26_im, i27_im, i28_im, i29_im, i30_im, i31_im, i32_im,  statei )
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
o17_re=i17_re;
o18_re=i18_re;
o19_re=i19_re;
o20_re=i20_re;
o21_re=i21_re;
o22_re=i22_re;
o23_re=i23_re;
o24_re=i24_re;
o25_re=i25_re;
o26_re=i26_re;
o27_re=i27_re;
o28_re=i28_re;
o29_re=i29_re;
o30_re=i30_re;
o31_re=i31_re;
o32_re=i32_re;
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
o17_im=i17_im;
o18_im=i18_im;
o19_im=i19_im;
o20_im=i20_im;
o21_im=i21_im;
o22_im=i22_im;
o23_im=i23_im;
o24_im=i24_im;
o25_im=i25_im;
o26_im=i26_im;
o27_im=i27_im;
o28_im=i28_im;
o29_im=i29_im;
o30_im=i30_im;
o31_im=i31_im;
o32_im=i32_im;
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
    case 13
        o13_re=inp_re;
        o13_im=inp_im;
        statei=14;
    case 14
        o14_re=inp_re;
        o14_im=inp_im;
        statei=15;
    case 15
        o15_re=inp_re;
        o15_im=inp_im;
        statei=16;
    case 16
        o16_re=inp_re;
        o16_im=inp_im;
        statei=17;
    case 17
        o17_re=inp_re;
        o17_im=inp_im;
        statei=18;       
    case 18
        o18_re=inp_re;
        o18_im=inp_im;
        statei=19;
    case 19
        o19_re=inp_re;
        o19_im=inp_im;
        statei=20;
    case 20
        o20_re=inp_re;
        o20_im=inp_im;
        statei=21;
    case 21
        o21_re=inp_re;
        o21_im=inp_im;
        statei=22;
    case 22
        o22_re=inp_re;
        o22_im=inp_im;
        statei=23;
    case 23
        o23_re=inp_re;
        o23_im=inp_im;
        statei=24;
    case 24
        o24_re=inp_re;
        o24_im=inp_im;
        statei=25;
    case 25 %Continue Input and start Output GI
        o25_re=inp_re;
        o25_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=26;
    case 26
        o26_re=inp_re;
        o26_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=27;
    case 27
        o27_re=inp_re;
        o27_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=28;
    case 28
        o28_re=inp_re;
        o28_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=29;
    case 29
        o29_re=inp_re;
        o29_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=30;
    case 30
        o30_re=inp_re;
        o30_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=31;
    case 31
        o31_re=inp_re;
        o31_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=32;
    case 32
        o32_re=inp_re;
        o32_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=33;   
    case 33%Output Data
        out_re=i1_re;
        out_im=i1_im;
        pop=1;
        statei=34;
    case 34
        out_re=i2_re;
        out_im=i2_im;
        pop=1;
        statei=35;
    case 35
        out_re=i3_re;
        out_im=i3_im;
        pop=1;
        statei=36;
    case 36
        out_re=i4_re;
        out_im=i4_im;
        pop=1;
        statei=37;
    case 37%Output Data
        out_re=i5_re;
        out_im=i5_im;
        pop=1;
        statei=38;
    case 38
        out_re=i6_re;
        out_im=i6_im;
        pop=1;
        statei=39;
    case 39
        out_re=i7_re;
        out_im=i7_im;
        pop=1;
        statei=40;
    case 40
        out_re=i8_re;
        out_im=i8_im;
        pop=1;
        statei=41;
    case 41
        out_re=i9_re;
        out_im=i9_im;
        pop=1;
        statei=42;
    case 42
        out_re=i10_re;
        out_im=i10_im;
        pop=1;
        statei=43;
    case 43
        out_re=i11_re;
        out_im=i11_im;
        pop=1;
        statei=44;
    case 44
        out_re=i12_re;
        out_im=i12_im;
        pop=1;
        statei=45;
    case 45
        out_re=i13_re;
        out_im=i13_im;
        pop=1;
        statei=46;
    case 46
        out_re=i14_re;
        out_im=i14_im;
        pop=1;
        statei=47;
    case 47
        out_re=i15_re;
        out_im=i15_im;
        pop=1;
        statei=48;
    case 48
        out_re=i16_re;
        out_im=i16_im;
        pop=1;
        statei=49;
    case 49
        out_re=i17_re;
        out_im=i17_im;
        pop=1;
        statei=50;
    case 50
        out_re=i18_re;
        out_im=i18_im;
        pop=1;
        statei=51;
    case 51
        out_re=i19_re;
        out_im=i19_im;
        pop=1;
        statei=52;
    case 52
        out_re=i20_re;
        out_im=i20_im;
        pop=1;
        statei=53;
    case 53
        out_re=i21_re;
        out_im=i21_im;
        pop=1;
        statei=54;
    case 54
        out_re=i22_re;
        out_im=i22_im;
        pop=1;
        statei=55;
    case 55
        out_re=i23_re;
        out_im=i23_im;
        pop=1;
        statei=56;
    case 56
        out_re=i24_re;
        out_im=i24_im;
        pop=1;
        statei=57;
    case 57
        out_re=i25_re;
        out_im=i25_im;
        pop=1;
        statei=58;
    case 58
        out_re=i26_re;
        out_im=i26_im;
        pop=1;
        statei=59;
    case 59
        out_re=i27_re;
        out_im=i27_im;
        pop=1;
        statei=60;
    case 60
        out_re=i28_re;
        out_im=i28_im;
        pop=1;
        statei=61;
    case 61
        out_re=i29_re;
        out_im=i29_im;
        pop=1;
        statei=62;
    case 62
        out_re=i30_re;
        out_im=i30_im;
        pop=1;
        statei=63;
    case 63
        out_re=i31_re;
        out_im=i31_im;
        pop=1;
        statei=64;
    case 64
        out_re=i32_re;
        out_im=i32_im;
        pop=1;
        statei=0;
end

stateo =statei;


  end
