function [sel, push, pop, frameStart, stateo, loopCounto, loopOuto,  starto, outputBitCounto]= ...
    sg_fsm_recv_inp(num, frameEn, statei, loopCounti, loopOuti, starti, outputBitCounti, fftLenActive, GI_Active, chanDownFact, bitPerSymb)

zero = xfix({xlBoolean}, 0);
one =  xfix({xlBoolean}, 1);

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
if ((num >= (fftLenActive+GI_Active) && outputBitCounti==0 && (frameEn == one || starti == one)) || (outputBitCounti>0 && outputBitCounti<= (fftLenActive+GI_Active) && loopOuti == 0))
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

if outputBitCounti >= fftLenActive+GI_Active
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

stateo = statei;
loopCounto = xfix({xlUnsigned, 8,0}, loopCounti);
starto = starti;
loopOuto = xfix({xlUnsigned, 8,0}, loopOuti);
outputBitCounto = xfix({xlUnsigned, 8,0}, outputBitCounti);
  end
