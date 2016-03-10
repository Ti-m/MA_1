function [out_re, out_im, pop,  stateo, loopCounto,  starto]= ...
    sg_fsm_rem_GI_OFDM(inp_re, inp_im, frameEn, statei, loopCounti, starti, fftLenActive, GI_Active)

zero = xfix({xlBoolean}, 0);
one =  xfix({xlBoolean}, 1);

pop = zero;
out_re = 0;
out_im = 0;

if frameEn == one
    loopCounti = 0;
    starti=one;
end

loopCounti = loopCounti+1;

if loopCounti > GI_Active+fftLenActive
   starti=zero; 
end

switch statei
    case 0 
        if loopCounti > GI_Active && starti == one             
            statei=1;           
        else
            statei=0;            
        end
        
    case 1
         pop = one;
         out_re = inp_re;
         out_im = inp_im;
        if loopCounti > GI_Active && starti == one           
            statei=1;           
        else
            statei=0;            
        end

end

stateo = statei;
loopCounto = xfix({xlUnsigned, 8,0}, loopCounti);
starto = starti;
  end
