function [push, pop, stateo, loopCounto, popEno]= sg_fsm_bef_chan( pushEn, statei, loopCounti, popEni, chanDownFact)

one=xfix({xlBoolean}, 1);
zero=xfix({xlBoolean}, 0);
%popEni=xfix({xlBoolean}, popEni);
switch statei
    case 0
        pop = zero;
        push= one;  
    case 1
        pop = one;
        push= one;   
    case 2
        pop = one;
        push= zero;  
    case 3
        pop = zero;
        push= zero;
    otherwise
        pop = zero;
        push= zero;   
end

if pushEn == 1
    conPush=1;
    popEni=one;
else
    conPush=0;
end

if loopCounti == 0 && popEni == one
    conPop = 1;
else
    conPop = 0;
end

loopCounti = loopCounti +1;
if loopCounti >= chanDownFact
    loopCounti = 0;
end    

if conPush == 1
    if conPop == 1
        statei = 1;
    else
        statei = 0;
    end

else           
    if conPop == 1
        statei = 2;
    else
       statei = 3;
    end   
end
stateo = statei;
loopCounto = xfix({xlUnsigned, 8,0}, loopCounti);
popEno = popEni;
  end
