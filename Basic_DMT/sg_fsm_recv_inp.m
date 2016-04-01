function [sel, push, pop, frameStart]= ...
    sg_fsm_recv_inp(num, frameEn, OFDMFrameSmpCntAct, chanDownFact, bitPerSymb)

zero = xfix({xlBoolean}, 0);
one =  xfix({xlBoolean}, 1);

%Optimzed Bitwidths as necessary.
persistent statei, statei = xl_state(0, {xlUnsigned, 2, 0});
persistent outputBitCounti, outputBitCounti = xl_state(0, {xlUnsigned, 6, 0});
persistent starti, starti = xl_state(0, {xlBoolean});
persistent loopOuti, loopOuti = xl_state(0, {xlUnsigned, 3, 0});
persistent loopCounti, loopCounti = xl_state(0, {xlUnsigned, 4, 0});

switch statei
    case 0 %Müll
    sel = 0;
    pop = zero;
    push= zero;
    frameStart = zero;
    
  case 1 % Push ohne Pop
        
    sel = 1;
    pop = one;
    push= zero;
    frameStart = zero;
    
  case 2 %Pop ohne Push
    sel = 0;
    pop = zero;
    push = one;
    frameStart = zero;
    
  case 3 %push mit Pop
    sel = 1;
    pop = one;
    push= one;
    frameStart = zero;
    
    otherwise  
    sel = 0;
    pop = zero;
    push = zero;
    frameStart = zero;
end

if loopCounti == 1%Push
    conPush=1;
else
    conPush=0;
end
loopCounti = loopCounti +1;
if loopCounti >= chanDownFact %Push
    loopCounti = 0;
end  

conPop=0;
if ((num >= OFDMFrameSmpCntAct && outputBitCounti==0 && (frameEn == one || starti == one)) || (outputBitCounti>0 && outputBitCounti<= OFDMFrameSmpCntAct && loopOuti == 0))
    starti=one;
    if frameEn && outputBitCounti==0
        frameStart=one;
        loopOuti = 0;
    end      
    
    conPop=1;
    outputBitCounti=outputBitCounti+1;
    

end

loopOuti = loopOuti +1;
if loopOuti >= bitPerSymb %Slow Pop
    loopOuti = 0;
end  

if outputBitCounti >= OFDMFrameSmpCntAct
    outputBitCounti=0;
    starti=zero;
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

  end
