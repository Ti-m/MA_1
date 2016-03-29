function [ out_re, out_im, pop]= ...
    sg_fsm_GI_DMT( inp_re,inp_im, frameEn, bitCountAftIFFT, fracLen)
%
%
persistent statei, statei = xl_state(0, {xlUnsigned, 8, 0});
persistent i1_re, i1_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i1_im, i1_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i2_re, i2_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i2_im, i2_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i3_re, i3_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i3_im, i3_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i4_re, i4_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i4_im, i4_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i5_re, i5_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i5_im, i5_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i6_re, i6_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i6_im, i6_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i7_re, i7_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i7_im, i7_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i8_re, i8_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i8_im, i8_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i9_re, i9_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i9_im, i9_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i10_re, i10_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i10_im, i10_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i11_re, i11_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i11_im, i11_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i12_re, i12_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i12_im, i12_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i13_re, i13_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i13_im, i13_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i14_re, i14_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i14_im, i14_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i15_re, i15_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i15_im, i15_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i16_re, i16_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i16_im, i16_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i17_re, i17_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i17_im, i17_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i18_re, i18_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i18_im, i18_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i19_re, i19_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i19_im, i19_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i20_re, i20_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i20_im, i20_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i21_re, i21_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i21_im, i21_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i22_re, i22_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i22_im, i22_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i23_re, i23_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i23_im, i23_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i24_re, i24_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i24_im, i24_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i25_re, i25_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i25_im, i25_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i26_re, i26_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i26_im, i26_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i27_re, i27_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i27_im, i27_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i28_re, i28_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i28_im, i28_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i29_re, i29_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i29_im, i29_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i30_re, i30_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i30_im, i30_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i31_re, i31_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i31_im, i31_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i32_re, i32_re = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});
persistent i32_im, i32_im = xl_state(0, {xlSigned, bitCountAftIFFT, fracLen});

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
        i1_re=inp_re;
        i1_im=inp_im;
        statei=2;       
    case 2
        i2_re=inp_re;
        i2_im=inp_im;
        statei=3;
    case 3
        i3_re=inp_re;
        i3_im=inp_im;
        statei=4;
    case 4
        i4_re=inp_re;
        i4_im=inp_im;
        statei=5;
    case 5
        i5_re=inp_re;
        i5_im=inp_im;
        statei=6;
    case 6
        i6_re=inp_re;
        i6_im=inp_im;
        statei=7;
    case 7
        i7_re=inp_re;
        i7_im=inp_im;
        statei=8;
    case 8
        i8_re=inp_re;
        i8_im=inp_im;
        statei=9;
    case 9
        i9_re=inp_re;
        i9_im=inp_im;
        statei=10;
    case 10
        i10_re=inp_re;
        i10_im=inp_im;
        statei=11;
    case 11
        i11_re=inp_re;
        i11_im=inp_im;
        statei=12;
    case 12
        i12_re=inp_re;
        i12_im=inp_im;
        statei=13;
    case 13
        i13_re=inp_re;
        i13_im=inp_im;
        statei=14;
    case 14
        i14_re=inp_re;
        i14_im=inp_im;
        statei=15;
    case 15
        i15_re=inp_re;
        i15_im=inp_im;
        statei=16;
    case 16
        i16_re=inp_re;
        i16_im=inp_im;
        statei=17;
    case 17
        i17_re=inp_re;
        i17_im=inp_im;
        statei=18;       
    case 18
        i18_re=inp_re;
        i18_im=inp_im;
        statei=19;
    case 19
        i19_re=inp_re;
        i19_im=inp_im;
        statei=20;
    case 20
        i20_re=inp_re;
        i20_im=inp_im;
        statei=21;
    case 21
        i21_re=inp_re;
        i21_im=inp_im;
        statei=22;
    case 22
        i22_re=inp_re;
        i22_im=inp_im;
        statei=23;
    case 23
        i23_re=inp_re;
        i23_im=inp_im;
        statei=24;
    case 24
        i24_re=inp_re;
        i24_im=inp_im;
        statei=25;
    case 25 %Continue Input and start Output GI
        i25_re=inp_re;
        i25_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=26;
    case 26
        i26_re=inp_re;
        i26_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=27;
    case 27
        i27_re=inp_re;
        i27_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=28;
    case 28
        i28_re=inp_re;
        i28_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=29;
    case 29
        i29_re=inp_re;
        i29_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=30;
    case 30
        i30_re=inp_re;
        i30_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=31;
    case 31
        i31_re=inp_re;
        i31_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=32;
    case 32
        i32_re=inp_re;
        i32_im=inp_im;
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

  end
