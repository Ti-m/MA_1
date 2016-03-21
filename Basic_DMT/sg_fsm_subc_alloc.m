function [sel, push, pop, frameStart]= ...
    sg_fsm_subc_alloc(num, frameEn,  ...
    u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15, u16, freqDivSubcAlloc, bitsPerFrame, bitPerSymb, fftLen)

persistent statei, statei = xl_state(0, {xlUnsigned, 2, 0});
persistent bitCounti, bitCounti = xl_state(0, {xlUnsigned, 8, 0});
persistent starti, starti = xl_state(0, {xlBoolean, 8, 0});
persistent subCarCounti, subCarCounti = xl_state(0, {xlUnsigned, 8, 0});
persistent subCari, subCari = xl_state(0, {xlUnsigned, 8, 0});
persistent loopCounti, loopCounti = xl_state(0, {xlUnsigned, 8, 0});

switch statei
    case 0 %Müll
    sel = 0;
    pop = xfix({xlBoolean}, 0);
    push= xfix({xlBoolean}, 0);
    frameStart = xfix({xlBoolean}, 0);
    
  case 1 % Push ohne Pop
        
    sel = 1;
    pop = xfix({xlBoolean}, 1);
    push= xfix({xlBoolean}, 0);
    frameStart = xfix({xlBoolean}, 0);
    
  case 2 %Pop ohne Push
    sel = 0;
    pop = xfix({xlBoolean}, 0);
    push = xfix({xlBoolean}, 1);
    frameStart = xfix({xlBoolean}, 0);
    
  case 3 %push mit Pop
    sel = 1;
    pop = xfix({xlBoolean}, 1);
    push= xfix({xlBoolean}, 1);
    frameStart = xfix({xlBoolean}, 0);
    
    otherwise  
    sel = 0;
    pop = xfix({xlBoolean}, 0);
    push = xfix({xlBoolean}, 0);
    frameStart = xfix({xlBoolean}, 0);
end


%Eventuell alles vorberechnen?
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

if loopCounti == 1%Push
    conPush=1;
else
    conPush=0;
end
loopCounti = loopCounti +1;
if loopCounti >= xfix({xlUnsigned, 8,0}, freqDivSubcAlloc) %Push
    loopCounti = 0;
end  

conPop=0;
if ((num >= (bitsPerFrame) && bitCounti==0 && (frameEn || starti)) || (bitCounti>0 && bitCounti<= (bitsPerFrame)))
    starti=xfix({xlBoolean}, 1);
    if frameEn
        frameStart = xfix({xlBoolean}, 1);
    end
    
    subCarCounti = subCarCounti +1;
    if subCarCounti >= bitPerSymb %Pop
    subCari = subCari + 1;
    subCarCounti = 0;
    end
    if subCari > fftLen
        subCari=0;
    end
    
    if subCari ~= usub1  && subCari ~= usub2  && subCari ~= usub3 ...
    && subCari ~= usub4  && subCari ~= usub5  && subCari ~= usub6 ...
    && subCari ~= usub7  && subCari ~= usub8  && subCari ~= usub9 ...
    && subCari ~= usub10 && subCari ~= usub11 && subCari ~= usub12 ...
    && subCari ~= usub13 && subCari ~= usub14 && subCari ~= usub15 ...
    && subCari ~= usub16% Pop
    conPop=1;
    bitCounti=bitCounti+1;
    end

end

if bitCounti >= bitsPerFrame
    bitCounti=0;
    starti=xfix({xlBoolean}, 0);
end

if conPop == 1
    if conPush == 1
        statei = 3;
    else
        statei = 1;
    end
else
    if conPush == 1
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
bitCounto = xfix({xlUnsigned, 8,0}, bitCounti);
  end
