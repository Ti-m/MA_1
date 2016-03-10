function [push, pop,  stateo, loopCounto, subCaro, subCarCounto, starto, enableo]= ...
    sg_fsm_recv_out(frameEn, statei, loopCounti, subCari, subCarCounti, starti, enablei, ...
    u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, freqDivSubcAlloc, bitPerSymb, fftLen)

zero = xfix({xlBoolean}, 0);
one =  xfix({xlBoolean}, 1);

switch statei
    case 0
        pop = zero;
        push= zero;  
    case 1
        pop = zero;
        push= one;   
    case 2
        pop = one;
        push= zero;  
    case 3
        pop = one;
        push= one;
    otherwise
        pop = zero;
        push= zero;   
end

%unused subcarrier
usub1  = xl_not( xfix({xlUnsigned, 1,0}, u1))*1;
usub2  = xl_not( xfix({xlUnsigned, 1,0}, u2))*2;
usub3  = xl_not( xfix({xlUnsigned, 1,0}, u3))*3;
usub4  = xl_not( xfix({xlUnsigned, 1,0}, u4))*4;
usub5  = xl_not( xfix({xlUnsigned, 1,0}, u5))*5;
usub6  = xl_not( xfix({xlUnsigned, 1,0}, u6))*6;
usub7  = xl_not( xfix({xlUnsigned, 1,0}, u7))*7;
usub8  = xl_not( xfix({xlUnsigned, 1,0}, u8))*8;
usub9  = xl_not( xfix({xlUnsigned, 1,0}, u9))*9;
usub10 = xl_not( xfix({xlUnsigned, 1,0}, u10))*10;
usub11 = xl_not( xfix({xlUnsigned, 1,0}, u11))*11;
usub12 = xl_not( xfix({xlUnsigned, 1,0}, u12))*12;
usub13 = xl_not( xfix({xlUnsigned, 1,0}, u13))*13;
usub14 = xl_not( xfix({xlUnsigned, 1,0}, u14))*14;
usub15 = xl_not( xfix({xlUnsigned, 1,0}, u15))*15;
usub16 = xl_not( xfix({xlUnsigned, 1,0}, u16))*16;


if loopCounti == 0 && enablei == one 
    conPop = 1;
else
    conPop = 0;
end

loopCounti = loopCounti +1;
if loopCounti >= freqDivSubcAlloc
    loopCounti = 0;
end  

subCarCounti = subCarCounti +1;
if subCarCounti >= bitPerSymb %Pop
subCari = subCari + 1;
subCarCounti = 0;
end

if subCari > fftLen
    subCari=0;
    starti=zero;
end

if frameEn == one
   starti=one;
   enablei=one;
   subCari=0;
end

conPush=0;
if subCari ~= usub1  && subCari ~= usub2  && subCari ~= usub3 ...
&& subCari ~= usub4  && subCari ~= usub5  && subCari ~= usub6 ...
&& subCari ~= usub7  && subCari ~= usub8  && subCari ~= usub9 ...
&& subCari ~= usub10 && subCari ~= usub11 && subCari ~= usub12 ...
&& subCari ~= usub13 && subCari ~= usub14 && subCari ~= usub15 ...
&& subCari ~= usub16 && starti == one% Push

conPush=1;
end
  
if conPush == 1
    if conPop == 1
        statei = 3;
    else
        statei = 1;
    end

else           
    if conPop == 1
        statei = 2;
    else
       statei = 0;
    end   
end


stateo = statei;
loopCounto = xfix({xlUnsigned, 8,0}, loopCounti);
subCaro = xfix({xlUnsigned, 8,0}, subCari);
subCarCounto = xfix({xlUnsigned, 8,0}, subCarCounti);
starto = starti;
enableo = enablei;

  end
