function [ out_re, out_im, pop ]= sg_fsm_GI_OFDM( inp_re,inp_im,...
    frameEn, bitCountAftIFFT, fracLen)
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
    case 13%Output prefix and Input
        i13_re=inp_re;
        i13_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=14;
    case 14
        i14_re=inp_re;
        i14_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=15;
    case 15
        i15_re=inp_re;
        i15_im=inp_im;
        out_re=inp_re;
        out_im=inp_im;
        pop=1;
        statei=16;
    case 16
        i16_re=inp_re;
        i16_im=inp_im;
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



  end
